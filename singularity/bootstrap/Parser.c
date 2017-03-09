#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#define O7C_BOOL_UNDEFINED
#include <o7c.h>

#include "Parser.h"

#define ErrNo_cnst 0
#define ErrMin_cnst Parser_ErrAstEnd_cnst

o7c_tag_t Parser_Options_tag;
typedef struct Parser {
	V_Base _;
	struct Parser_Options opt;
	o7c_bool err;
	struct Scanner_Scanner s;
	int l;
	struct Parser_anon_0000 {
		int ofs;
		int end;
	} comment;
	struct Ast_RModule *module;
	struct Ast_RProvider *provider;
} Parser;
static o7c_tag_t Parser_tag;


static void (*declarations)(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) = NULL;
static struct Ast_RType *(*type)(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) = NULL;
static struct Ast_RStatement *(*statements)(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) = NULL;
static struct Ast_RExpression *(*expression)(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) = NULL;

static void AddError(struct Parser *p, o7c_tag_t p_tag, int err) {
	Log_Str("AddError ", 10);
	Log_Int(err);
	Log_Str(" at ", 5);
	Log_Int((*p).s.line);
	Log_Str(":", 2);
	Log_Int(o7c_add((*p).s.column, o7c_mul((*p).s.tabs, 3)));
	Log_Ln();
	(*p).err = o7c_cmp(err, Parser_ErrAstBegin_cnst) >  0;
	if ((*p).module != NULL) {
		Ast_AddError((*p).module, err, (*p).s.line, (*p).s.column, (*p).s.tabs);
	}
	(*p).opt.printError(err);
	Out_String(". ", 3);
	Out_Int(o7c_add((*p).s.line, 1), 2);
	Out_String(":", 2);
	Out_Int(o7c_add((*p).s.column, o7c_mul((*p).s.tabs, 3)), 2);
	Out_Ln();
}

static void CheckAst(struct Parser *p, o7c_tag_t p_tag, int err) {
	if (o7c_cmp(err, Ast_ErrNo_cnst) !=  0) {
		assert((o7c_cmp(err, ErrNo_cnst) <  0) && (o7c_cmp(err, Ast_ErrMin_cnst) >=  0));
		AddError(&(*p), p_tag, o7c_add(Parser_ErrAstBegin_cnst, err));
	}
}

static void Scan(struct Parser *p, o7c_tag_t p_tag) {
	(*p).l = Scanner_Next(&(*p).s, Scanner_Scanner_tag);
	if (o7c_cmp((*p).l, ErrNo_cnst) <  0) {
		AddError(&(*p), p_tag, (*p).l);
		if (o7c_cmp((*p).l, Scanner_ErrNumberTooBig_cnst) ==  0) {
			(*p).l = Scanner_Number_cnst;
		}
	} else if (o7c_cmp((*p).l, Scanner_Semicolon_cnst) ==  0) {
		Scanner_ResetComment(&(*p).s, Scanner_Scanner_tag);
	}
}

static void Expect(struct Parser *p, o7c_tag_t p_tag, int expect, int error) {
	if (o7c_cmp((*p).l, expect) ==  0) {
		Scan(&(*p), p_tag);
	} else {
		AddError(&(*p), p_tag, error);
	}
}

static o7c_bool ScanIfEqual(struct Parser *p, o7c_tag_t p_tag, int lex) {
	if (o7c_cmp((*p).l, lex) ==  0) {
		Scan(&(*p), p_tag);
		lex = (*p).l;
	}
	return o7c_cmp((*p).l, lex) ==  0;
}

static void ExpectIdent(struct Parser *p, o7c_tag_t p_tag, int *begin, int *end, int error) {
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		(*begin) = (*p).s.lexStart;
		(*end) = (*p).s.lexEnd;
		Scan(&(*p), p_tag);
	} else {
		AddError(&(*p), p_tag, error);
		(*begin) =  - 1;
		(*end) =  - 1;
	}
}

static Ast_ExprSet Set(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static int Set_Element(Ast_ExprSet *e, struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RExpression *left = NULL;
	int err = O7C_INT_UNDEF;

	left = expression(&(*p), p_tag, ds);
	if (o7c_cmp((*p).l, Scanner_Range_cnst) ==  0) {
		Scan(&(*p), p_tag);
		err = Ast_ExprSetNew(&(*e), left, expression(&(*p), p_tag, ds));
	} else {
		err = Ast_ExprSetNew(&(*e), left, NULL);
	}
	return err;
}

static Ast_ExprSet Set(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_ExprSet e = NULL, next = NULL;
	int err = O7C_INT_UNDEF;

	assert(o7c_cmp((*p).l, Scanner_Brace3Open_cnst) ==  0);
	Scan(&(*p), p_tag);
	if (o7c_cmp((*p).l, Scanner_Brace3Close_cnst) !=  0) {
		err = Set_Element(&e, &(*p), p_tag, ds);
		CheckAst(&(*p), p_tag, err);
		next = e;
		while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
			err = Set_Element(&next->next, &(*p), p_tag, ds);
			CheckAst(&(*p), p_tag, err);
			next = next->next;
		}
		Expect(&(*p), p_tag, Scanner_Brace3Close_cnst, Parser_ErrExpectBrace3Close_cnst);
	} else {
		CheckAst(&(*p), p_tag, Ast_ExprSetNew(&e, NULL, NULL));
		Scan(&(*p), p_tag);
	}
	return e;
}

static struct Ast_RDeclaration *DeclarationGet(struct Ast_RDeclarations *ds, struct Parser *p, o7c_tag_t p_tag) {
	struct Ast_RDeclaration *d = NULL;

	Log_StrLn("DeclarationGet", 15);
	CheckAst(&(*p), p_tag, Ast_DeclarationGet(&d, ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd));
	return d;
}

static struct Ast_RDeclaration *ExpectDecl(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RDeclaration *d = NULL;

	if (o7c_cmp((*p).l, Scanner_Ident_cnst) !=  0) {
		d = NULL;
		AddError(&(*p), p_tag, Parser_ErrExpectIdent_cnst);
	} else {
		d = DeclarationGet(ds, &(*p), p_tag);
		Scan(&(*p), p_tag);
	}
	return d;
}

static struct Ast_RDeclaration *Qualident(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RDeclaration *d = NULL;

	Log_StrLn("Qualident", 10);
	d = ExpectDecl(&(*p), p_tag, ds);
	if ((d != NULL) && (o7c_is(d, Ast_Import_s_tag))) {
		Expect(&(*p), p_tag, Scanner_Dot_cnst, Parser_ErrExpectDot_cnst);
		d = ExpectDecl(&(*p), p_tag, &O7C_GUARD(Ast_Import_s, &d)->_.module->_);
	}
	return d;
}

static struct Ast_RDeclaration *ExpectRecordExtend(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_RConstruct *base) {
	struct Ast_RDeclaration *d = NULL;

	d = Qualident(&(*p), p_tag, ds);
	return d;
}

static Ast_Designator Designator(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static void Designator_SetSel(struct Ast_RSelector **prev, struct Ast_RSelector *sel, Ast_Designator des) {
	if ((*prev) == NULL) {
		des->sel = sel;
	} else {
		(*prev)->next = sel;
	}
	(*prev) = sel;
}

static Ast_Designator Designator(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_Designator des = NULL;
	struct Ast_RDeclaration *decl = NULL, *var_ = NULL;
	struct Ast_RSelector *prev = NULL, *sel = NULL;
	struct Ast_RType *type = NULL;
	int nameBegin = O7C_INT_UNDEF, nameEnd = O7C_INT_UNDEF;

	Log_StrLn("Designator", 11);
	assert(o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0);
	decl = Qualident(&(*p), p_tag, ds);
	des = NULL;
	if (decl != NULL) {
		if (o7c_is(decl, Ast_RVar_tag)) {
			type = decl->type;
			prev = NULL;
			des = Ast_DesignatorNew(decl);
			do {
				sel = NULL;
				if (o7c_cmp((*p).l, Scanner_Dot_cnst) ==  0) {
					Scan(&(*p), p_tag);
					ExpectIdent(&(*p), p_tag, &nameBegin, &nameEnd, Parser_ErrExpectIdent_cnst);
					if (o7c_cmp(nameBegin, 0) >=  0) {
						CheckAst(&(*p), p_tag, Ast_SelRecordNew(&sel, &type, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameBegin, nameEnd));
					}
				} else if (o7c_cmp((*p).l, Scanner_Brace1Open_cnst) ==  0) {
					if (o7c_in(type->_._.id, ((1 << Ast_IdRecord_cnst) | (1 << Ast_IdPointer_cnst)))) {
						Scan(&(*p), p_tag);
						var_ = ExpectRecordExtend(&(*p), p_tag, ds, O7C_GUARD(Ast_RConstruct, &type));
						CheckAst(&(*p), p_tag, Ast_SelGuardNew(&sel, &type, var_));
						Expect(&(*p), p_tag, Scanner_Brace1Close_cnst, Parser_ErrExpectBrace1Close_cnst);
					} else if (!(o7c_is(type, Ast_ProcType_s_tag))) {
						AddError(&(*p), p_tag, Parser_ErrExpectVarRecordOrPointer_cnst);
					}
				} else if (o7c_cmp((*p).l, Scanner_Brace2Open_cnst) ==  0) {
					Scan(&(*p), p_tag);
					CheckAst(&(*p), p_tag, Ast_SelArrayNew(&sel, &type, expression(&(*p), p_tag, ds)));
					while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
						Designator_SetSel(&prev, sel, des);
						CheckAst(&(*p), p_tag, Ast_SelArrayNew(&sel, &type, expression(&(*p), p_tag, ds)));
					}
					Expect(&(*p), p_tag, Scanner_Brace2Close_cnst, Parser_ErrExpectBrace2Close_cnst);
				} else if (o7c_cmp((*p).l, Scanner_Dereference_cnst) ==  0) {
					CheckAst(&(*p), p_tag, Ast_SelPointerNew(&sel, &type));
					Scan(&(*p), p_tag);
				}
				Designator_SetSel(&prev, sel, des);
			} while (!(sel == NULL));
			des->_._.type = type;
		} else if ((o7c_is(decl, Ast_Const_s_tag)) || (o7c_is(decl, Ast_RGeneralProcedure_tag)) || (o7c_cmp(decl->_.id, Ast_IdError_cnst) ==  0)) {
			des = Ast_DesignatorNew(decl);
		} else {
			AddError(&(*p), p_tag, Parser_ErrExpectDesignator_cnst);
		}
	}
	return des;
}

static void CallParams(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_ExprCall e) {
	Ast_Parameter par = NULL;
	Ast_FormalParam fp = NULL;

	assert(o7c_cmp((*p).l, Scanner_Brace1Open_cnst) ==  0);
	Scan(&(*p), p_tag);
	if (!ScanIfEqual(&(*p), p_tag, Scanner_Brace1Close_cnst)) {
		par = NULL;
		if (o7c_is(e->designator->_._.type, Ast_ProcType_s_tag)) {
			fp = O7C_GUARD(Ast_ProcType_s, &e->designator->_._.type)->params;
		} else {
			fp = NULL;
		}
		CheckAst(&(*p), p_tag, Ast_CallParamNew(e, &par, expression(&(*p), p_tag, ds), &fp));
		e->params = par;
		while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
			CheckAst(&(*p), p_tag, Ast_CallParamNew(e, &par, expression(&(*p), p_tag, ds), &fp));
		}
		CheckAst(&(*p), p_tag, Ast_CallParamsEnd(e, fp));
		Expect(&(*p), p_tag, Scanner_Brace1Close_cnst, Parser_ErrExpectBrace1Close_cnst);
	}
}

static Ast_ExprCall ExprCall(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_Designator des) {
	Ast_ExprCall e = NULL;

	CheckAst(&(*p), p_tag, Ast_ExprCallNew(&e, des));
	CallParams(&(*p), p_tag, ds, e);
	return e;
}

static struct Ast_RExpression *Factor(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static void Factor_Ident(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_RExpression **e) {
	Ast_Designator des = NULL;

	des = Designator(&(*p), p_tag, ds);
	if (o7c_cmp((*p).l, Scanner_Brace1Open_cnst) !=  0) {
		(*e) = (&(des)->_._);
	} else {
		(*e) = (&(ExprCall(&(*p), p_tag, ds, des))->_._);
	}
}

static Ast_ExprNegate Factor_Negate(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_ExprNegate neg = NULL;

	assert(o7c_cmp((*p).l, Scanner_Negate_cnst) ==  0);
	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_ExprNegateNew(&neg, Factor(&(*p), p_tag, ds)));
	return neg;
}

static struct Ast_RExpression *Factor(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RExpression *e = NULL;

	Log_StrLn("Factor", 7);
	if (o7c_cmp((*p).l, Scanner_Number_cnst) ==  0) {
		if ((*p).s.isReal) {
			e = (&(Ast_ExprRealNew((*p).s.real, (*p).module, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd))->_._._);
		} else {
			e = (&(Ast_ExprIntegerNew((*p).s.integer))->_._._);
		}
		Scan(&(*p), p_tag);
	} else if ((o7c_cmp((*p).l, Scanner_True_cnst) ==  0) || (o7c_cmp((*p).l, Scanner_False_cnst) ==  0)) {
		e = (&(Ast_ExprBooleanNew(o7c_cmp((*p).l, Scanner_True_cnst) ==  0))->_._);
		Scan(&(*p), p_tag);
	} else if (o7c_cmp((*p).l, Scanner_Nil_cnst) ==  0) {
		e = (&(Ast_ExprNilNew())->_._);
		Scan(&(*p), p_tag);
	} else if (o7c_cmp((*p).l, Scanner_String_cnst) ==  0) {
		e = (&(Ast_ExprStringNew((*p).module, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd))->_._._._);
		if ((e != NULL) && o7c_bl((*p).s.isChar)) {
			O7C_GUARD(Ast_ExprString_s, &e)->_.int_ = (*p).s.integer;
		}
		Scan(&(*p), p_tag);
	} else if (o7c_cmp((*p).l, Scanner_Brace1Open_cnst) ==  0) {
		Scan(&(*p), p_tag);
		e = (&(Ast_ExprBracesNew(expression(&(*p), p_tag, ds)))->_._);
		Expect(&(*p), p_tag, Scanner_Brace1Close_cnst, Parser_ErrExpectBrace1Close_cnst);
	} else if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		Factor_Ident(&(*p), p_tag, ds, &e);
	} else if (o7c_cmp((*p).l, Scanner_Brace3Open_cnst) ==  0) {
		e = (&(Set(&(*p), p_tag, ds))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Negate_cnst) ==  0) {
		e = (&(Factor_Negate(&(*p), p_tag, ds))->_._);
	} else {
		AddError(&(*p), p_tag, Parser_ErrExpectExpression_cnst);
		e = NULL;
	}
	return e;
}

static struct Ast_RExpression *Term(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RExpression *e = NULL;
	Ast_ExprTerm term = NULL;
	int l = O7C_INT_UNDEF;

	Log_StrLn("Term", 5);
	e = Factor(&(*p), p_tag, ds);
	if ((o7c_cmp((*p).l, Scanner_MultFirst_cnst) >=  0) && (o7c_cmp((*p).l, Scanner_MultLast_cnst) <=  0)) {
		l = (*p).l;
		Scan(&(*p), p_tag);
		term = NULL;
		CheckAst(&(*p), p_tag, Ast_ExprTermNew(&term, O7C_GUARD(Ast_RFactor, &e), l, Factor(&(*p), p_tag, ds)));
		assert((term->expr != NULL) && (term->factor != NULL));
		e = (&(term)->_);
		while ((o7c_cmp((*p).l, Scanner_MultFirst_cnst) >=  0) && (o7c_cmp((*p).l, Scanner_MultLast_cnst) <=  0)) {
			l = (*p).l;
			Scan(&(*p), p_tag);
			CheckAst(&(*p), p_tag, Ast_ExprTermAdd(e, &term, l, Factor(&(*p), p_tag, ds)));
		}
	}
	return e;
}

static struct Ast_RExpression *Sum(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RExpression *e = NULL;
	Ast_ExprSum sum = NULL;
	int l = O7C_INT_UNDEF;

	Log_StrLn("Sum", 4);
	l = (*p).l;
	if (o7c_in(l, ((1 << Scanner_Plus_cnst) | (1 << Scanner_Minus_cnst)))) {
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_ExprSumNew(&sum, l, Term(&(*p), p_tag, ds)));
		e = (&(sum)->_);
	} else {
		e = Term(&(*p), p_tag, ds);
		if (o7c_in((*p).l, ((1 << Scanner_Plus_cnst) | (1 << Scanner_Minus_cnst) | (1 << Scanner_Or_cnst)))) {
			CheckAst(&(*p), p_tag, Ast_ExprSumNew(&sum,  - 1, e));
			e = (&(sum)->_);
		}
	}
	while (o7c_in((*p).l, ((1 << Scanner_Plus_cnst) | (1 << Scanner_Minus_cnst) | (1 << Scanner_Or_cnst)))) {
		l = (*p).l;
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_ExprSumAdd(e, &sum, l, Term(&(*p), p_tag, ds)));
	}
	return e;
}

static struct Ast_RExpression *Expression(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RExpression *expr = NULL;
	Ast_ExprRelation e = NULL;
	Ast_ExprIsExtension isExt = NULL;
	int rel = O7C_INT_UNDEF;

	expr = Sum(&(*p), p_tag, ds);
	if ((o7c_cmp((*p).l, Scanner_RelationFirst_cnst) >=  0) && (o7c_cmp((*p).l, Scanner_RelationLast_cnst) <  0)) {
		rel = (*p).l;
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_ExprRelationNew(&e, expr, rel, Sum(&(*p), p_tag, ds)));
		expr = (&(e)->_);
	} else if (ScanIfEqual(&(*p), p_tag, Scanner_Is_cnst)) {
		CheckAst(&(*p), p_tag, Ast_ExprIsExtensionNew(&isExt, &expr, type(&(*p), p_tag, ds,  - 1,  - 1)));
		expr = (&(isExt)->_);
	}
	return expr;
}

static void DeclComment(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclaration *d) {
	int comOfs = O7C_INT_UNDEF, comEnd = O7C_INT_UNDEF;

	if (o7c_bl((*p).opt.saveComments) && Scanner_TakeCommentPos(&(*p).s, Scanner_Scanner_tag, &comOfs, &comEnd)) {
		Ast_DeclSetComment(d, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, comOfs, comEnd);
	}
}

static void Mark(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclaration *d) {
	DeclComment(&(*p), p_tag, d);
	d->mark = ScanIfEqual(&(*p), p_tag, Scanner_Asterisk_cnst);
}

static void Consts(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	int begin = O7C_INT_UNDEF, end = O7C_INT_UNDEF;
	struct Ast_Const_s *const_ = NULL;

	Scan(&(*p), p_tag);
	while (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		if (!(*p).err) {
			ExpectIdent(&(*p), p_tag, &begin, &end, Parser_ErrExpectConstName_cnst);
			CheckAst(&(*p), p_tag, Ast_ConstAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, begin, end));
			const_ = O7C_GUARD(Ast_Const_s, &ds->end);
			Mark(&(*p), p_tag, &const_->_);
			Expect(&(*p), p_tag, Scanner_Equal_cnst, Parser_ErrExpectEqual_cnst);
			CheckAst(&(*p), p_tag, Ast_ConstSetExpression(const_, Expression(&(*p), p_tag, ds)));
			Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
		}
		if ((*p).err) {
			while ((o7c_cmp((*p).l, Scanner_Import_cnst) <  0) && (o7c_cmp((*p).l, Scanner_Semicolon_cnst) !=  0)) {
				Scan(&(*p), p_tag);
			}
			(*p).err = false;
		}
	}
}

static int ExprToArrayLen(struct Parser *p, o7c_tag_t p_tag, struct Ast_RExpression *e) {
	int i = O7C_INT_UNDEF;

	if ((e != NULL) && (e->value_ != NULL) && (o7c_is(e->value_, Ast_RExprInteger_tag))) {
		i = O7C_GUARD(Ast_RExprInteger, &e->value_)->int_;
		if (o7c_cmp(i, 0) <=  0) {
			AddError(&(*p), p_tag, Parser_ErrArrayLenLess1_cnst);
		} else {
			Log_Str("Array Len ", 11);
			Log_Int(i);
			Log_Ln();
		}
	} else {
		i =  - 1;
		if (e != NULL) {
			AddError(&(*p), p_tag, Ast_ErrExpectConstIntExpr_cnst);
		}
	}
	return i;
}

static struct Ast_RArray *Array(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) {
	struct Ast_RArray *a = NULL;
	struct Ast_RType *t = NULL;
	struct Ast_RExpression *exprLen = NULL;
	struct Ast_RExpression *lens[16] ;
	int i = O7C_INT_UNDEF, size = O7C_INT_UNDEF;
	memset(&lens, 0, sizeof(lens));

	Log_StrLn("Array", 6);
	assert(o7c_cmp((*p).l, Scanner_Array_cnst) ==  0);
	Scan(&(*p), p_tag);
	a = Ast_ArrayGet(NULL, Expression(&(*p), p_tag, ds));
	if (o7c_cmp(nameBegin, 0) >=  0) {
		t = (&(a)->_._);
		CheckAst(&(*p), p_tag, Ast_TypeAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameBegin, nameEnd, &t));
	}
	size = ExprToArrayLen(&(*p), p_tag, a->count);
	i = 0;
	while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
		exprLen = Expression(&(*p), p_tag, ds);
		size = o7c_mul(size, ExprToArrayLen(&(*p), p_tag, exprLen));
		if (o7c_cmp(i, sizeof(lens) / sizeof (lens[0])) <  0) {
			lens[o7c_ind(16, i)] = exprLen;
		}
		i = o7c_add(i, 1);
	}
	if (o7c_cmp(i, sizeof(lens) / sizeof (lens[0])) >  0) {
		AddError(&(*p), p_tag, Parser_ErrArrayDimensionsTooMany_cnst);
	}
	Expect(&(*p), p_tag, Scanner_Of_cnst, Parser_ErrExpectOf_cnst);
	a->_._._.type = type(&(*p), p_tag, ds,  - 1,  - 1);
	while (o7c_cmp(i, 0) >  0) {
		i = o7c_sub(i, 1);
		a->_._._.type = (&(Ast_ArrayGet(a->_._._.type, lens[o7c_ind(16, i)]))->_._);
	}
	return a;
}

static struct Ast_RType *TypeNamed(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RDeclaration *d = NULL;
	struct Ast_RType *t = NULL;

	t = NULL;
	d = Qualident(&(*p), p_tag, ds);
	if (d != NULL) {
		if (o7c_is(d, Ast_RType_tag)) {
			t = O7C_GUARD(Ast_RType, &d);
		} else if (o7c_cmp(d->_.id, Ast_IdError_cnst) !=  0) {
			AddError(&(*p), p_tag, Parser_ErrExpectType_cnst);
		}
	}
	if (t == NULL) {
		t = Ast_TypeGet(Ast_IdInteger_cnst);
	}
	return t;
}

static void VarDeclaration(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *dsAdd, struct Ast_RDeclarations *dsTypes);
static void VarDeclaration_Name(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	int begin = O7C_INT_UNDEF, end = O7C_INT_UNDEF;

	ExpectIdent(&(*p), p_tag, &begin, &end, Parser_ErrExpectIdent_cnst);
	CheckAst(&(*p), p_tag, Ast_VarAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, begin, end));
	DeclComment(&(*p), p_tag, ds->end);
	Mark(&(*p), p_tag, ds->end);
}

static void VarDeclaration(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *dsAdd, struct Ast_RDeclarations *dsTypes) {
	struct Ast_RDeclaration *var_ = NULL;
	struct Ast_RType *typ = NULL;

	VarDeclaration_Name(&(*p), p_tag, dsAdd);
	var_ = (&(O7C_GUARD(Ast_RVar, &dsAdd->end))->_);
	while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
		VarDeclaration_Name(&(*p), p_tag, dsAdd);
	}
	Expect(&(*p), p_tag, Scanner_Colon_cnst, Parser_ErrExpectColon_cnst);
	typ = type(&(*p), p_tag, dsTypes,  - 1,  - 1);
	while (var_ != NULL) {
		var_->type = typ;
		var_ = var_->next;
	}
}

static void Vars(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	while (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		VarDeclaration(&(*p), p_tag, ds, ds);
		Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
	}
}

static Ast_Record Record(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd);
static void Record_Vars(struct Parser *p, o7c_tag_t p_tag, Ast_Record dsAdd, struct Ast_RDeclarations *dsTypes);
static void Vars_Record_Declaration(struct Parser *p, o7c_tag_t p_tag, Ast_Record dsAdd, struct Ast_RDeclarations *dsTypes);
static void Declaration_Vars_Record_Name(struct Ast_RVar **v, struct Parser *p, o7c_tag_t p_tag, Ast_Record ds) {
	int begin = O7C_INT_UNDEF, end = O7C_INT_UNDEF;

	ExpectIdent(&(*p), p_tag, &begin, &end, Parser_ErrExpectIdent_cnst);
	CheckAst(&(*p), p_tag, Ast_RecordVarAdd(&(*v), ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, begin, end));
	Mark(&(*p), p_tag, &(*v)->_);
}

static void Vars_Record_Declaration(struct Parser *p, o7c_tag_t p_tag, Ast_Record dsAdd, struct Ast_RDeclarations *dsTypes) {
	struct Ast_RVar *var_ = NULL;
	struct Ast_RDeclaration *d = NULL;
	struct Ast_RType *typ = NULL;

	Declaration_Vars_Record_Name(&var_, &(*p), p_tag, dsAdd);
	d = (&(var_)->_);
	while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
		Declaration_Vars_Record_Name(&var_, &(*p), p_tag, dsAdd);
	}
	Expect(&(*p), p_tag, Scanner_Colon_cnst, Parser_ErrExpectColon_cnst);
	typ = type(&(*p), p_tag, dsTypes,  - 1,  - 1);
	while (d != NULL) {
		d->type = typ;
		d = d->next;
	}
}

static void Record_Vars(struct Parser *p, o7c_tag_t p_tag, Ast_Record dsAdd, struct Ast_RDeclarations *dsTypes) {
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		Vars_Record_Declaration(&(*p), p_tag, dsAdd, dsTypes);
		while (ScanIfEqual(&(*p), p_tag, Scanner_Semicolon_cnst)) {
			if (o7c_cmp((*p).l, Scanner_End_cnst) !=  0) {
				Vars_Record_Declaration(&(*p), p_tag, dsAdd, dsTypes);
			} else if ((*p).opt.strictSemicolon) {
				AddError(&(*p), p_tag, Parser_ErrExcessSemicolon_cnst);
				(*p).err = false;
			}
		}
	}
}

static Ast_Record Record(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) {
	Ast_Record rec = NULL, base = NULL;
	struct Ast_RType *t = NULL;
	struct Ast_RDeclaration *decl = NULL;

	assert(o7c_cmp((*p).l, Scanner_Record_cnst) ==  0);
	Scan(&(*p), p_tag);
	base = NULL;
	if (ScanIfEqual(&(*p), p_tag, Scanner_Brace1Open_cnst)) {
		decl = Qualident(&(*p), p_tag, ds);
		if ((decl != NULL) && (o7c_cmp(decl->_.id, Ast_IdRecord_cnst) ==  0)) {
			base = O7C_GUARD(Ast_Record_s, &decl);
		} else {
			AddError(&(*p), p_tag, Parser_ErrExpectRecord_cnst);
		}
		Expect(&(*p), p_tag, Scanner_Brace1Close_cnst, Parser_ErrExpectBrace1Close_cnst);
	}
	rec = Ast_RecordNew(ds, base);
	if (o7c_cmp(nameBegin, 0) >=  0) {
		t = (&(rec)->_._);
		CheckAst(&(*p), p_tag, Ast_TypeAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameBegin, nameEnd, &t));
		if (&rec->_._ != t) {
			rec = O7C_GUARD(Ast_Record_s, &t);
			Ast_RecordSetBase(rec, base);
		}
	} else {
		rec->_._._.name.block = NULL;
		rec->_._._.module = (*p).module;
	}
	Record_Vars(&(*p), p_tag, rec, ds);
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	return rec;
}

static struct Ast_RPointer *Pointer(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) {
	struct Ast_RPointer *tp = NULL;
	struct Ast_RType *t = NULL;
	struct Ast_RDeclaration *decl = NULL;
	struct Ast_RType *typeDecl = NULL;

	assert(o7c_cmp((*p).l, Scanner_Pointer_cnst) ==  0);
	Scan(&(*p), p_tag);
	tp = Ast_PointerGet(NULL);
	if (o7c_cmp(nameBegin, 0) >=  0) {
		t = (&(tp)->_._);
		assert(t != NULL);
		CheckAst(&(*p), p_tag, Ast_TypeAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameBegin, nameEnd, &t));
	}
	Expect(&(*p), p_tag, Scanner_To_cnst, Parser_ErrExpectTo_cnst);
	if (o7c_cmp((*p).l, Scanner_Record_cnst) ==  0) {
		tp->_._._.type = (&(Record(&(*p), p_tag, ds,  - 1,  - 1))->_._);
		if (tp->_._._.type != NULL) {
			O7C_GUARD(Ast_Record_s, &tp->_._._.type)->pointer = tp;
		}
	} else if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		decl = Ast_DeclarationSearch(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd);
		if (decl == NULL) {
			typeDecl = (&(Ast_RecordNew(ds, NULL))->_._);
			CheckAst(&(*p), p_tag, Ast_TypeAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd, &typeDecl));
			assert(tp->_._._.next == &typeDecl->_);
			typeDecl->_._.id = Ast_IdRecordForward_cnst;
			tp->_._._.type = typeDecl;
			O7C_GUARD(Ast_Record_s, &typeDecl)->pointer = tp;
		} else if (o7c_is(decl, Ast_Record_s_tag)) {
			tp->_._._.type = (&(O7C_GUARD(Ast_Record_s, &decl))->_._);
			O7C_GUARD(Ast_Record_s, &decl)->pointer = tp;
		} else {
			tp->_._._.type = TypeNamed(&(*p), p_tag, ds);
			if (tp->_._._.type != NULL) {
				if (o7c_is(tp->_._._.type, Ast_Record_s_tag)) {
					O7C_GUARD(Ast_Record_s, &tp->_._._.type)->pointer = tp;
				} else {
					AddError(&(*p), p_tag, Parser_ErrExpectRecord_cnst);
				}
			}
		}
		Scan(&(*p), p_tag);
	} else {
		AddError(&(*p), p_tag, Parser_ErrExpectRecord_cnst);
	}
	return tp;
}

static void FormalParameters(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_ProcType_s *proc);
static void FormalParameters_Section(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_ProcType_s *proc);
static void Section_FormalParameters_Name(struct Parser *p, o7c_tag_t p_tag, struct Ast_ProcType_s *proc) {
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) !=  0) {
		AddError(&(*p), p_tag, Parser_ErrExpectIdent_cnst);
	} else {
		CheckAst(&(*p), p_tag, Ast_ParamAdd((*p).module, proc, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd));
		Scan(&(*p), p_tag);
	}
}

static struct Ast_RType *Section_FormalParameters_Type(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RType *t = NULL;
	int arrs = O7C_INT_UNDEF;

	arrs = 0;
	while (ScanIfEqual(&(*p), p_tag, Scanner_Array_cnst)) {
		Expect(&(*p), p_tag, Scanner_Of_cnst, Parser_ErrExpectOf_cnst);
		arrs = o7c_add(arrs, 1);
	}
	t = TypeNamed(&(*p), p_tag, ds);
	while ((t != NULL) && (o7c_cmp(arrs, 0) >  0)) {
		t = (&(Ast_ArrayGet(t, NULL))->_._);
		arrs = o7c_sub(arrs, 1);
	}
	return t;
}

static void FormalParameters_Section(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_ProcType_s *proc) {
	o7c_bool isVar = O7C_BOOL_UNDEF;
	struct Ast_RDeclaration *param = NULL;
	struct Ast_RType *type = NULL;

	isVar = ScanIfEqual(&(*p), p_tag, Scanner_Var_cnst);
	Section_FormalParameters_Name(&(*p), p_tag, proc);
	param = (&(proc->end)->_._);
	while (ScanIfEqual(&(*p), p_tag, Scanner_Comma_cnst)) {
		Section_FormalParameters_Name(&(*p), p_tag, proc);
	}
	Expect(&(*p), p_tag, Scanner_Colon_cnst, Parser_ErrExpectColon_cnst);
	type = Section_FormalParameters_Type(&(*p), p_tag, ds);
	while (param != NULL) {
		O7C_GUARD(Ast_FormalParam_s, &param)->isVar = isVar;
		param->type = type;
		param = param->next;
	}
}

static void FormalParameters(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, struct Ast_ProcType_s *proc) {
	o7c_bool braces = O7C_BOOL_UNDEF;

	braces = ScanIfEqual(&(*p), p_tag, Scanner_Brace1Open_cnst);
	if (braces) {
		if (!ScanIfEqual(&(*p), p_tag, Scanner_Brace1Close_cnst)) {
			FormalParameters_Section(&(*p), p_tag, ds, proc);
			while (ScanIfEqual(&(*p), p_tag, Scanner_Semicolon_cnst)) {
				FormalParameters_Section(&(*p), p_tag, ds, proc);
			}
			Expect(&(*p), p_tag, Scanner_Brace1Close_cnst, Parser_ErrExpectBrace1Close_cnst);
		}
	}
	if (ScanIfEqual(&(*p), p_tag, Scanner_Colon_cnst)) {
		if (!braces) {
			AddError(&(*p), p_tag, Parser_ErrFunctionWithoutBraces_cnst);
			(*p).err = false;
		}
		proc->_._._.type = TypeNamed(&(*p), p_tag, ds);
	}
}

static struct Ast_ProcType_s *TypeProcedure(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) {
	struct Ast_ProcType_s *proc = NULL;
	struct Ast_RType *t = NULL;

	assert(o7c_cmp((*p).l, Scanner_Procedure_cnst) ==  0);
	Scan(&(*p), p_tag);
	proc = Ast_ProcTypeNew();
	if (o7c_cmp(nameBegin, 0) >=  0) {
		t = (&(proc)->_._);
		CheckAst(&(*p), p_tag, Ast_TypeAdd(ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameBegin, nameEnd, &t));
	}
	FormalParameters(&(*p), p_tag, ds, proc);
	return proc;
}

static struct Ast_RType *Type(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, int nameBegin, int nameEnd) {
	struct Ast_RType *t = NULL;

	if (o7c_cmp((*p).l, Scanner_Array_cnst) ==  0) {
		t = (&(Array(&(*p), p_tag, ds, nameBegin, nameEnd))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Pointer_cnst) ==  0) {
		t = (&(Pointer(&(*p), p_tag, ds, nameBegin, nameEnd))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Procedure_cnst) ==  0) {
		t = (&(TypeProcedure(&(*p), p_tag, ds, nameBegin, nameEnd))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Record_cnst) ==  0) {
		t = (&(Record(&(*p), p_tag, ds, nameBegin, nameEnd))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		t = TypeNamed(&(*p), p_tag, ds);
	} else {
		t = Ast_TypeGet(Ast_IdInteger_cnst);
		AddError(&(*p), p_tag, Parser_ErrExpectType_cnst);
	}
	return t;
}

static void Types(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RType *type = NULL;
	int begin = O7C_INT_UNDEF, end = O7C_INT_UNDEF;
	o7c_bool mark = O7C_BOOL_UNDEF;

	Scan(&(*p), p_tag);
	while (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		begin = (*p).s.lexStart;
		end = (*p).s.lexEnd;
		Scan(&(*p), p_tag);
		mark = ScanIfEqual(&(*p), p_tag, Scanner_Asterisk_cnst);
		Expect(&(*p), p_tag, Scanner_Equal_cnst, Parser_ErrExpectEqual_cnst);
		type = Type(&(*p), p_tag, ds, begin, end);
		if (type != NULL) {
			type->_.mark = mark;
			if (!(o7c_is(type, Ast_RConstruct_tag))) {
				AddError(&(*p), p_tag, Parser_ErrExpectStructuredType_cnst);
			}
		}
		Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
	}
}

static Ast_If If(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static Ast_If If_Branch(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_If if_ = NULL;

	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_IfNew(&if_, Expression(&(*p), p_tag, ds), NULL));
	Expect(&(*p), p_tag, Scanner_Then_cnst, Parser_ErrExpectThen_cnst);
	if_->_.stats = statements(&(*p), p_tag, ds);
	return if_;
}

static Ast_If If(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_If if_ = NULL, else_ = NULL;
	struct Ast_RWhileIf *elsif = NULL;

	assert(o7c_cmp((*p).l, Scanner_If_cnst) ==  0);
	if_ = If_Branch(&(*p), p_tag, ds);
	elsif = (&(if_)->_);
	while (o7c_cmp((*p).l, Scanner_Elsif_cnst) ==  0) {
		elsif->elsif = (&(If_Branch(&(*p), p_tag, ds))->_);
		elsif = elsif->elsif;
	}
	if (ScanIfEqual(&(*p), p_tag, Scanner_Else_cnst)) {
		CheckAst(&(*p), p_tag, Ast_IfNew(&else_, NULL, statements(&(*p), p_tag, ds)));
		elsif->elsif = (&(else_)->_);
	}
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	return if_;
}

static Ast_Case Case(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static void Case_Element(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_Case case_);
static Ast_CaseLabel Element_Case_LabelList(struct Parser *p, o7c_tag_t p_tag, Ast_Case case_, struct Ast_RDeclarations *ds);
static Ast_CaseLabel LabelList_Element_Case_LabelRange(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static Ast_CaseLabel LabelRange_LabelList_Element_Case_Label(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_CaseLabel l = NULL;

	if ((o7c_cmp((*p).l, Scanner_Number_cnst) ==  0) && !(*p).s.isReal) {
		CheckAst(&(*p), p_tag, Ast_CaseLabelNew(&l, Ast_IdInteger_cnst, (*p).s.integer));
		Scan(&(*p), p_tag);
	} else if (o7c_cmp((*p).l, Scanner_String_cnst) ==  0) {
		assert(o7c_bl((*p).s.isChar));
		CheckAst(&(*p), p_tag, Ast_CaseLabelNew(&l, Ast_IdChar_cnst, (*p).s.integer));
		Scan(&(*p), p_tag);
	} else if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		CheckAst(&(*p), p_tag, Ast_CaseLabelQualNew(&l, Qualident(&(*p), p_tag, ds)));
	} else {
		CheckAst(&(*p), p_tag, Ast_CaseLabelNew(&l, Ast_IdInteger_cnst, 0));
		AddError(&(*p), p_tag, Parser_ErrExpectIntOrStrOrQualident_cnst);
	}
	return l;
}

static Ast_CaseLabel LabelList_Element_Case_LabelRange(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_CaseLabel r = NULL;

	r = LabelRange_LabelList_Element_Case_Label(&(*p), p_tag, ds);
	if (o7c_cmp((*p).l, Scanner_Range_cnst) ==  0) {
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_CaseRangeNew(r, LabelRange_LabelList_Element_Case_Label(&(*p), p_tag, ds)));
	}
	return r;
}

static Ast_CaseLabel Element_Case_LabelList(struct Parser *p, o7c_tag_t p_tag, Ast_Case case_, struct Ast_RDeclarations *ds) {
	Ast_CaseLabel first = NULL, last = NULL;

	first = LabelList_Element_Case_LabelRange(&(*p), p_tag, ds);
	CheckAst(&(*p), p_tag, Ast_CaseRangeListAdd(case_, NULL, first));
	while (o7c_cmp((*p).l, Scanner_Comma_cnst) ==  0) {
		Scan(&(*p), p_tag);
		last = LabelList_Element_Case_LabelRange(&(*p), p_tag, ds);
		CheckAst(&(*p), p_tag, Ast_CaseRangeListAdd(case_, first, last));
	}
	return first;
}

static void Case_Element(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_Case case_) {
	Ast_CaseElement elem = NULL;

	elem = Ast_CaseElementNew(Element_Case_LabelList(&(*p), p_tag, case_, ds));
	Expect(&(*p), p_tag, Scanner_Colon_cnst, Parser_ErrExpectColon_cnst);
	elem->stats = statements(&(*p), p_tag, ds);
	CheckAst(&(*p), p_tag, Ast_CaseElementAdd(case_, elem));
}

static Ast_Case Case(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_Case case_ = NULL;

	assert(o7c_cmp((*p).l, Scanner_Case_cnst) ==  0);
	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_CaseNew(&case_, Expression(&(*p), p_tag, ds)));
	Expect(&(*p), p_tag, Scanner_Of_cnst, Parser_ErrExpectOf_cnst);
	Case_Element(&(*p), p_tag, ds, case_);
	while (ScanIfEqual(&(*p), p_tag, Scanner_Alternative_cnst)) {
		Case_Element(&(*p), p_tag, ds, case_);
	}
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	return case_;
}

static Ast_Repeat Repeat(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_Repeat r = NULL;

	assert(o7c_cmp((*p).l, Scanner_Repeat_cnst) ==  0);
	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_RepeatNew(&r, statements(&(*p), p_tag, ds)));
	Expect(&(*p), p_tag, Scanner_Until_cnst, Parser_ErrExpectUntil_cnst);
	CheckAst(&(*p), p_tag, Ast_RepeatSetUntil(r, Expression(&(*p), p_tag, ds)));
	return r;
}

static Ast_For For(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_For f = NULL;
	struct Ast_RVar *v = NULL;

	assert(o7c_cmp((*p).l, Scanner_For_cnst) ==  0);
	Scan(&(*p), p_tag);
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) !=  0) {
		AddError(&(*p), p_tag, o7c_add(Parser_ErrExpectIdent_cnst, o7c_mul(Ast_ForIteratorGet(&v, ds, "FORITERATOR", 12, 0, 10), 0)));
	} else {
		CheckAst(&(*p), p_tag, Ast_ForIteratorGet(&v, ds, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd));
	}
	Scan(&(*p), p_tag);
	Expect(&(*p), p_tag, Scanner_Assign_cnst, Parser_ErrExpectAssign_cnst);
	CheckAst(&(*p), p_tag, Ast_ForNew(&f, v, Expression(&(*p), p_tag, ds), NULL, 1, NULL));
	Expect(&(*p), p_tag, Scanner_To_cnst, Parser_ErrExpectTo_cnst);
	CheckAst(&(*p), p_tag, Ast_ForSetTo(f, Expression(&(*p), p_tag, ds)));
	if (o7c_cmp((*p).l, Scanner_By_cnst) !=  0) {
		CheckAst(&(*p), p_tag, Ast_ForSetBy(f, NULL));
	} else {
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_ForSetBy(f, Expression(&(*p), p_tag, ds)));
	}
	Expect(&(*p), p_tag, Scanner_Do_cnst, Parser_ErrExpectDo_cnst);
	f->stats = statements(&(*p), p_tag, ds);
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	return f;
}

static Ast_While While(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_While w = NULL, br = NULL;
	struct Ast_RWhileIf *elsif = NULL;

	assert(o7c_cmp((*p).l, Scanner_While_cnst) ==  0);
	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_WhileNew(&w, Expression(&(*p), p_tag, ds), NULL));
	elsif = (&(w)->_);
	Expect(&(*p), p_tag, Scanner_Do_cnst, Parser_ErrExpectDo_cnst);
	w->_.stats = statements(&(*p), p_tag, ds);
	while (ScanIfEqual(&(*p), p_tag, Scanner_Elsif_cnst)) {
		CheckAst(&(*p), p_tag, Ast_WhileNew(&br, Expression(&(*p), p_tag, ds), NULL));
		elsif->elsif = (&(br)->_);
		elsif = (&(br)->_);
		Expect(&(*p), p_tag, Scanner_Do_cnst, Parser_ErrExpectDo_cnst);
		elsif->stats = statements(&(*p), p_tag, ds);
	}
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	return w;
}

static Ast_Assign Assign(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_Designator des) {
	Ast_Assign st = NULL;

	assert(o7c_cmp((*p).l, Scanner_Assign_cnst) ==  0);
	Scan(&(*p), p_tag);
	CheckAst(&(*p), p_tag, Ast_AssignNew(&st, des, Expression(&(*p), p_tag, ds)));
	return st;
}

static Ast_Call Call(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds, Ast_Designator des) {
	Ast_Call st = NULL;

	CheckAst(&(*p), p_tag, Ast_CallNew(&st, des));
	if (o7c_cmp((*p).l, Scanner_Brace1Open_cnst) ==  0) {
		CallParams(&(*p), p_tag, ds, O7C_GUARD(Ast_ExprCall_s, &st->_.expr));
	} else if ((des != NULL) && (des->_._.type != NULL) && (o7c_is(des->_._.type, Ast_ProcType_s_tag))) {
		CheckAst(&(*p), p_tag, Ast_CallParamsEnd(O7C_GUARD(Ast_ExprCall_s, &st->_.expr), O7C_GUARD(Ast_ProcType_s, &des->_._.type)->params));
	}
	return st;
}

static o7c_bool NotEnd(int l) {
	return (o7c_cmp(l, Scanner_End_cnst) !=  0) && (o7c_cmp(l, Scanner_Return_cnst) !=  0) && (o7c_cmp(l, Scanner_Else_cnst) !=  0) && (o7c_cmp(l, Scanner_Elsif_cnst) !=  0) && (o7c_cmp(l, Scanner_Until_cnst) !=  0) && (o7c_cmp(l, Scanner_Alternative_cnst) !=  0);
}

static struct Ast_RStatement *Statements(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds);
static struct Ast_RStatement *Statements_Statement(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	Ast_Designator des = NULL;
	struct Ast_RStatement *st = NULL;
	int commentOfs = O7C_INT_UNDEF, commentEnd = O7C_INT_UNDEF;

	if (!(*p).opt.saveComments || !Scanner_TakeCommentPos(&(*p).s, Scanner_Scanner_tag, &commentOfs, &commentEnd)) {
		commentOfs =  - 1;
	}
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		des = Designator(&(*p), p_tag, ds);
		if (o7c_cmp((*p).l, Scanner_Assign_cnst) ==  0) {
			st = (&(Assign(&(*p), p_tag, ds, des))->_);
		} else {
			st = (&(Call(&(*p), p_tag, ds, des))->_);
		}
	} else if (o7c_cmp((*p).l, Scanner_If_cnst) ==  0) {
		st = (&(If(&(*p), p_tag, ds))->_._);
	} else if (o7c_cmp((*p).l, Scanner_Case_cnst) ==  0) {
		st = (&(Case(&(*p), p_tag, ds))->_);
	} else if (o7c_cmp((*p).l, Scanner_Repeat_cnst) ==  0) {
		st = (&(Repeat(&(*p), p_tag, ds))->_);
	} else if (o7c_cmp((*p).l, Scanner_For_cnst) ==  0) {
		st = (&(For(&(*p), p_tag, ds))->_);
	} else if (o7c_cmp((*p).l, Scanner_While_cnst) ==  0) {
		st = (&(While(&(*p), p_tag, ds))->_._);
	} else {
		st = NULL;
		AddError(&(*p), p_tag, Parser_ErrExpectStatement_cnst);
	}
	if (st == NULL) {
		st = (&(Ast_StatementErrorNew())->_);
	}
	if (o7c_cmp(commentOfs, 0) >=  0) {
		Ast_NodeSetComment(&(*st)._, Ast_RStatement_tag, (*p).module, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, commentOfs, commentEnd);
	}
	if ((*p).err) {
		Log_StrLn("Error", 6);
		while ((o7c_cmp((*p).l, Scanner_Semicolon_cnst) !=  0) && NotEnd((*p).l)) {
			Scan(&(*p), p_tag);
		}
		(*p).err = false;
	}
	return st;
}

static struct Ast_RStatement *Statements(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RStatement *stats = NULL, *last = NULL;

	stats = Statements_Statement(&(*p), p_tag, ds);
	last = stats;
	while (1) if (ScanIfEqual(&(*p), p_tag, Scanner_Semicolon_cnst)) {
		if (NotEnd((*p).l)) {
			last->next = Statements_Statement(&(*p), p_tag, ds);
			last = last->next;
		} else if ((*p).opt.strictSemicolon) {
			AddError(&(*p), p_tag, Parser_ErrExcessSemicolon_cnst);
			(*p).err = false;
		}
	} else if (NotEnd((*p).l)) {
		AddError(&(*p), p_tag, Parser_ErrExpectSemicolon_cnst);
		(*p).err = false;
		last->next = Statements_Statement(&(*p), p_tag, ds);
		last = last->next;
	} else break;
	return stats;
}

static void Return(struct Parser *p, o7c_tag_t p_tag, struct Ast_RProcedure *proc) {
	if (o7c_cmp((*p).l, Scanner_Return_cnst) ==  0) {
		Log_StrLn("Return", 7);
		Scan(&(*p), p_tag);
		CheckAst(&(*p), p_tag, Ast_ProcedureSetReturn(proc, Expression(&(*p), p_tag, &proc->_._)));
		if (o7c_cmp((*p).l, Scanner_Semicolon_cnst) ==  0) {
			if ((*p).opt.strictSemicolon) {
				AddError(&(*p), p_tag, Parser_ErrExcessSemicolon_cnst);
				(*p).err = false;
			}
			Scan(&(*p), p_tag);
		}
	} else {
		CheckAst(&(*p), p_tag, Ast_ProcedureEnd(proc));
	}
}

static void ProcBody(struct Parser *p, o7c_tag_t p_tag, struct Ast_RProcedure *proc) {
	declarations(&(*p), p_tag, &proc->_._);
	if (ScanIfEqual(&(*p), p_tag, Scanner_Begin_cnst)) {
		proc->_._.stats = Statements(&(*p), p_tag, &proc->_._);
	}
	Return(&(*p), p_tag, proc);
	Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
	if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
		if (!StringStore_IsEqualToChars(&proc->_._._.name, StringStore_String_tag, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd)) {
			AddError(&(*p), p_tag, Parser_ErrEndProcedureNameNotMatch_cnst);
		}
		Scan(&(*p), p_tag);
	} else {
		AddError(&(*p), p_tag, Parser_ErrExpectProcedureName_cnst);
	}
}

static o7c_bool TakeComment(struct Parser *p, o7c_tag_t p_tag) {
	return o7c_bl((*p).opt.saveComments) && Scanner_TakeCommentPos(&(*p).s, Scanner_Scanner_tag, &(*p).comment.ofs, &(*p).comment.end);
}

static void Procedure(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	struct Ast_RProcedure *proc = NULL;
	int nameStart = O7C_INT_UNDEF, nameEnd = O7C_INT_UNDEF;

	assert(o7c_cmp((*p).l, Scanner_Procedure_cnst) ==  0);
	Scan(&(*p), p_tag);
	ExpectIdent(&(*p), p_tag, &nameStart, &nameEnd, Parser_ErrExpectIdent_cnst);
	CheckAst(&(*p), p_tag, Ast_ProcedureAdd(ds, &proc, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameStart, nameEnd));
	Mark(&(*p), p_tag, &proc->_._._);
	FormalParameters(&(*p), p_tag, ds, proc->_.header);
	Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
	ProcBody(&(*p), p_tag, proc);
}

static void Declarations(struct Parser *p, o7c_tag_t p_tag, struct Ast_RDeclarations *ds) {
	if (o7c_cmp((*p).l, Scanner_Const_cnst) ==  0) {
		Consts(&(*p), p_tag, ds);
	}
	if (o7c_cmp((*p).l, Scanner_Type_cnst) ==  0) {
		Types(&(*p), p_tag, ds);
	}
	if (o7c_cmp((*p).l, Scanner_Var_cnst) ==  0) {
		Scan(&(*p), p_tag);
		Vars(&(*p), p_tag, ds);
	}
	while (o7c_cmp((*p).l, Scanner_Procedure_cnst) ==  0) {
		Procedure(&(*p), p_tag, ds);
		Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
	}
}

static void Imports(struct Parser *p, o7c_tag_t p_tag) {
	int nameOfs = O7C_INT_UNDEF, nameEnd = O7C_INT_UNDEF, realOfs = O7C_INT_UNDEF, realEnd = O7C_INT_UNDEF;

	do {
		Scan(&(*p), p_tag);
		ExpectIdent(&(*p), p_tag, &nameOfs, &nameEnd, Parser_ErrExpectModuleName_cnst);
		if (ScanIfEqual(&(*p), p_tag, Scanner_Assign_cnst)) {
			ExpectIdent(&(*p), p_tag, &realOfs, &realEnd, Parser_ErrExpectModuleName_cnst);
		} else {
			realOfs = nameOfs;
			realEnd = nameEnd;
		}
		if (!(*p).err) {
			CheckAst(&(*p), p_tag, Ast_ImportAdd((*p).module, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, nameOfs, nameEnd, realOfs, realEnd, (*p).provider));
		} else {
			(*p).err = false;
			while ((o7c_cmp((*p).l, Scanner_Import_cnst) <  0) && (o7c_cmp((*p).l, Scanner_Comma_cnst) !=  0) && (o7c_cmp((*p).l, Scanner_Semicolon_cnst) !=  0)) {
				Scan(&(*p), p_tag);
			}
		}
	} while (!(o7c_cmp((*p).l, Scanner_Comma_cnst) !=  0));
	Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
}

static void Module(struct Parser *p, o7c_tag_t p_tag) {
	Log_StrLn("Module", 7);
	Scan(&(*p), p_tag);
	if (o7c_cmp((*p).l, Scanner_Module_cnst) !=  0) {
		(*p).l = Parser_ErrExpectModule_cnst;
	} else {
		Scan(&(*p), p_tag);
		if (o7c_cmp((*p).l, Scanner_Ident_cnst) !=  0) {
			(*p).module = Ast_ModuleNew(" ", 2, 0, 0);
			AddError(&(*p), p_tag, Parser_ErrExpectIdent_cnst);
		} else {
			(*p).module = Ast_ModuleNew((*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd);
			if (TakeComment(&(*p), p_tag)) {
				Ast_ModuleSetComment((*p).module, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).comment.ofs, (*p).comment.end);
			}
			Scan(&(*p), p_tag);
		}
		Expect(&(*p), p_tag, Scanner_Semicolon_cnst, Parser_ErrExpectSemicolon_cnst);
		if (o7c_cmp((*p).l, Scanner_Import_cnst) ==  0) {
			Imports(&(*p), p_tag);
		}
		Declarations(&(*p), p_tag, &(*p).module->_);
		if (ScanIfEqual(&(*p), p_tag, Scanner_Begin_cnst)) {
			(*p).module->_.stats = Statements(&(*p), p_tag, &(*p).module->_);
		}
		Expect(&(*p), p_tag, Scanner_End_cnst, Parser_ErrExpectEnd_cnst);
		if (o7c_cmp((*p).l, Scanner_Ident_cnst) ==  0) {
			if (!StringStore_IsEqualToChars(&(*p).module->_._.name, StringStore_String_tag, (*p).s.buf, Scanner_BlockSize_cnst * 2 + 1, (*p).s.lexStart, (*p).s.lexEnd)) {
				AddError(&(*p), p_tag, Parser_ErrEndModuleNameNotMatch_cnst);
			}
			Scan(&(*p), p_tag);
		} else {
			AddError(&(*p), p_tag, Parser_ErrExpectModuleName_cnst);
		}
		if (o7c_cmp((*p).l, Scanner_Dot_cnst) !=  0) {
			AddError(&(*p), p_tag, Parser_ErrExpectDot_cnst);
		}
		CheckAst(&(*p), p_tag, Ast_ModuleEnd((*p).module));
	}
}

static void Blank(int code) {
}

extern void Parser_DefaultOptions(struct Parser_Options *opt, o7c_tag_t opt_tag) {
	V_Init(&(*opt)._, opt_tag);
	(*opt).strictSemicolon = true;
	(*opt).strictReturn = true;
	(*opt).saveComments = true;
	(*opt).printError = Blank;
}

extern struct Ast_RModule *Parser_Parse(struct VDataStream_In *in_, struct Ast_RProvider *prov, struct Parser_Options *opt, o7c_tag_t opt_tag) {
	struct Parser p ;
	memset(&p, 0, sizeof(p));

	assert(in_ != NULL);
	assert(prov != NULL);
	V_Init(&p._, Parser_tag);
	p.opt = (*opt);
	p.err = false;
	p.module = NULL;
	p.provider = prov;
	Scanner_Init(&p.s, Scanner_Scanner_tag, in_);
	Module(&p, Parser_tag);
	return p.module;
}

extern void Parser_init(void) {
	static int initialized = 0;
	if (0 == initialized) {
		V_init();
		Log_init();
		Out_init();
		Utf8_init();
		Scanner_init();
		StringStore_init();
		Ast_init();
		VDataStream_init();

		o7c_tag_init(Parser_Options_tag, V_Base_tag);
		o7c_tag_init(Parser_tag, V_Base_tag);

		declarations = Declarations;
		type = Type;
		statements = Statements;
		expression = Expression;
	}
	++initialized;
}

