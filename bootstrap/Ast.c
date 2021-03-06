#include <o7.h>

#include "Ast.h"

#define LastId_cnst 35

#define Ast_ModuleBag__s_tag o7_base_tag
extern void Ast_ModuleBag__s_undef(struct Ast_ModuleBag__s *r) {
	r->m = NULL;
}
#define Ast_RProvider_tag V_Base_tag
extern void Ast_RProvider_undef(struct Ast_RProvider *r) {
	V_Base_undef(&r->_);
	r->get = NULL;
	r->reg = NULL;
}
#define Ast_Node_tag V_Base_tag
extern void Ast_Node_undef(struct Ast_Node *r) {
	V_Base_undef(&r->_);
	r->id = O7_INT_UNDEF;
	StringStore_String_undef(&r->comment);
	r->emptyLines = O7_INT_UNDEF;
	r->ext = NULL;
}
#define Ast_RError_tag Ast_Node_tag
extern void Ast_RError_undef(struct Ast_RError *r) {
	Ast_Node_undef(&r->_);
	r->code = O7_INT_UNDEF;
	r->line = O7_INT_UNDEF;
	r->column = O7_INT_UNDEF;
	r->bytes = O7_INT_UNDEF;
	StringStore_String_undef(&r->str);
	r->next = NULL;
}
#define Ast_DeclarationsBag__s_tag o7_base_tag
extern void Ast_DeclarationsBag__s_undef(struct Ast_DeclarationsBag__s *r) {
	r->d = NULL;
}
#define Ast_RDeclaration_tag Ast_Node_tag
extern void Ast_RDeclaration_undef(struct Ast_RDeclaration *r) {
	Ast_Node_undef(&r->_);
	r->module_ = NULL;
	r->up = NULL;
	StringStore_String_undef(&r->name);
	r->mark = O7_BOOL_UNDEF;
	r->used = O7_BOOL_UNDEF;
	r->type = NULL;
	r->next = NULL;
}
o7_tag_t Ast_RType_tag;
extern void Ast_RType_undef(struct Ast_RType *r) {
	Ast_RDeclaration_undef(&r->_);
	r->array_ = NULL;
	r->properties = 0u;
}
#define Ast_Byte__s_tag Ast_RType_tag
extern void Ast_Byte__s_undef(struct Ast_Byte__s *r) {
	Ast_RType_undef(&r->_);
}
o7_tag_t Ast_Const__s_tag;
extern void Ast_Const__s_undef(struct Ast_Const__s *r) {
	Ast_RDeclaration_undef(&r->_);
	r->expr = NULL;
	r->finished = O7_BOOL_UNDEF;
}
o7_tag_t Ast_RConstruct_tag;
extern void Ast_RConstruct_undef(struct Ast_RConstruct *r) {
	Ast_RType_undef(&r->_);
}
o7_tag_t Ast_RArray_tag;
extern void Ast_RArray_undef(struct Ast_RArray *r) {
	Ast_RConstruct_undef(&r->_);
	r->count = NULL;
}
#define Ast_RVarState_tag o7_base_tag
extern void Ast_RVarState_undef(struct Ast_RVarState *r) {
	r->inited = 0u;
	r->inCondition = O7_BOOL_UNDEF;
	r->root = NULL;
	r->if_ = NULL;
	r->else_ = NULL;
}
o7_tag_t Ast_RVar_tag;
extern void Ast_RVar_undef(struct Ast_RVar *r) {
	Ast_RDeclaration_undef(&r->_);
	r->state = NULL;
	r->checkInit = O7_BOOL_UNDEF;
	r->inVarParam = O7_BOOL_UNDEF;
}
o7_tag_t Ast_RRecord_tag;
extern void Ast_RRecord_undef(struct Ast_RRecord *r) {
	Ast_RConstruct_undef(&r->_);
	r->base = NULL;
	r->vars = NULL;
	r->pointer = NULL;
	r->needTag = O7_BOOL_UNDEF;
	r->inAssign = O7_BOOL_UNDEF;
	r->complete = O7_BOOL_UNDEF;
}
o7_tag_t Ast_RPointer_tag;
extern void Ast_RPointer_undef(struct Ast_RPointer *r) {
	Ast_RConstruct_undef(&r->_);
}
o7_tag_t Ast_RFormalParam_tag;
extern void Ast_RFormalParam_undef(struct Ast_RFormalParam *r) {
	Ast_RVar_undef(&r->_);
	r->access = 0u;
	r->needTag = NULL;
	r->link = NULL;
}
#define Ast_RNeedTagList_tag V_Base_tag
extern void Ast_RNeedTagList_undef(struct Ast_RNeedTagList *r) {
	V_Base_undef(&r->_);
	r->next = NULL;
	r->value_ = O7_BOOL_UNDEF;
	r->count = O7_INT_UNDEF;
	r->first = NULL;
	r->last = NULL;
}
o7_tag_t Ast_RProcType_tag;
extern void Ast_RProcType_undef(struct Ast_RProcType *r) {
	Ast_RConstruct_undef(&r->_);
	r->params = NULL;
	r->end = NULL;
}

typedef struct FormalProcType__s {
	Ast_RProcType _;
} *FormalProcType;
static o7_tag_t FormalProcType__s_tag;

#define Ast_RDeclarations_tag Ast_RDeclaration_tag
extern void Ast_RDeclarations_undef(struct Ast_RDeclarations *r) {
	Ast_RDeclaration_undef(&r->_);
	r->dag = NULL;
	r->start = NULL;
	r->end = NULL;
	r->consts = NULL;
	r->types = NULL;
	r->vars = NULL;
	r->varsEnd = NULL;
	r->procedures = NULL;
	r->recordForwardCount = O7_INT_UNDEF;
	r->stats = NULL;
}
o7_tag_t Ast_Import__s_tag;
extern void Ast_Import__s_undef(struct Ast_Import__s *r) {
	Ast_RDeclaration_undef(&r->_);
}
o7_tag_t Ast_RModule_tag;
extern void Ast_RModule_undef(struct Ast_RModule *r) {
	Ast_RDeclarations_undef(&r->_);
	r->bag = NULL;
	StringStore_Store_undef(&r->store);
	r->script = O7_BOOL_UNDEF;
	r->errorHide = O7_BOOL_UNDEF;
	r->handleImport = O7_BOOL_UNDEF;
	r->import_ = NULL;
	r->fixed = O7_BOOL_UNDEF;
	r->spec = O7_BOOL_UNDEF;
	r->unusedDecl = NULL;
	r->errors = NULL;
	r->errLast = NULL;
}
o7_tag_t Ast_RGeneralProcedure_tag;
extern void Ast_RGeneralProcedure_undef(struct Ast_RGeneralProcedure *r) {
	Ast_RDeclarations_undef(&r->_);
	r->header = NULL;
	r->return_ = NULL;
}
o7_tag_t Ast_RProcedure_tag;
extern void Ast_RProcedure_undef(struct Ast_RProcedure *r) {
	Ast_RGeneralProcedure_undef(&r->_);
	r->deep = O7_INT_UNDEF;
	r->usedAsValue = O7_BOOL_UNDEF;
}
o7_tag_t Ast_PredefinedProcedure__s_tag;
extern void Ast_PredefinedProcedure__s_undef(struct Ast_PredefinedProcedure__s *r) {
	Ast_RGeneralProcedure_undef(&r->_);
}
#define Ast_RExpression_tag Ast_Node_tag
extern void Ast_RExpression_undef(struct Ast_RExpression *r) {
	Ast_Node_undef(&r->_);
	r->type = NULL;
	r->properties = 0u;
	r->value_ = NULL;
}
#define Ast_RSelector_tag Ast_Node_tag
extern void Ast_RSelector_undef(struct Ast_RSelector *r) {
	Ast_Node_undef(&r->_);
	r->type = NULL;
	r->next = NULL;
}
o7_tag_t Ast_SelPointer__s_tag;
extern void Ast_SelPointer__s_undef(struct Ast_SelPointer__s *r) {
	Ast_RSelector_undef(&r->_);
}
o7_tag_t Ast_SelGuard__s_tag;
extern void Ast_SelGuard__s_undef(struct Ast_SelGuard__s *r) {
	Ast_RSelector_undef(&r->_);
}
o7_tag_t Ast_SelArray__s_tag;
extern void Ast_SelArray__s_undef(struct Ast_SelArray__s *r) {
	Ast_RSelector_undef(&r->_);
	r->index = NULL;
}
o7_tag_t Ast_SelRecord__s_tag;
extern void Ast_SelRecord__s_undef(struct Ast_SelRecord__s *r) {
	Ast_RSelector_undef(&r->_);
	r->var_ = NULL;
}
o7_tag_t Ast_RFactor_tag;
extern void Ast_RFactor_undef(struct Ast_RFactor *r) {
	Ast_RExpression_undef(&r->_);
	r->nextValue = NULL;
}
o7_tag_t Ast_Designator__s_tag;
extern void Ast_Designator__s_undef(struct Ast_Designator__s *r) {
	Ast_RFactor_undef(&r->_);
	r->decl = NULL;
	r->inited = 0u;
	r->sel = NULL;
}
#define Ast_ExprNumber_tag Ast_RFactor_tag
extern void Ast_ExprNumber_undef(struct Ast_ExprNumber *r) {
	Ast_RFactor_undef(&r->_);
}
o7_tag_t Ast_RExprInteger_tag;
extern void Ast_RExprInteger_undef(struct Ast_RExprInteger *r) {
	Ast_ExprNumber_undef(&r->_);
	r->int_ = O7_INT_UNDEF;
}
o7_tag_t Ast_ExprReal__s_tag;
extern void Ast_ExprReal__s_undef(struct Ast_ExprReal__s *r) {
	Ast_ExprNumber_undef(&r->_);
	r->real = O7_DBL_UNDEF;
	StringStore_String_undef(&r->str);
}
o7_tag_t Ast_ExprBoolean__s_tag;
extern void Ast_ExprBoolean__s_undef(struct Ast_ExprBoolean__s *r) {
	Ast_RFactor_undef(&r->_);
	r->bool_ = O7_BOOL_UNDEF;
}
o7_tag_t Ast_ExprString__s_tag;
extern void Ast_ExprString__s_undef(struct Ast_ExprString__s *r) {
	Ast_RExprInteger_undef(&r->_);
	StringStore_String_undef(&r->string);
	r->asChar = O7_BOOL_UNDEF;
}
#define Ast_ExprNil__s_tag Ast_RFactor_tag
extern void Ast_ExprNil__s_undef(struct Ast_ExprNil__s *r) {
	Ast_RFactor_undef(&r->_);
}
o7_tag_t Ast_RExprSet_tag;
extern void Ast_RExprSet_undef(struct Ast_RExprSet *r) {
	Ast_RFactor_undef(&r->_);
	memset(&r->exprs, 0, sizeof(r->exprs));
	r->next = NULL;
}
o7_tag_t Ast_ExprSetValue__s_tag;
extern void Ast_ExprSetValue__s_undef(struct Ast_ExprSetValue__s *r) {
	Ast_RFactor_undef(&r->_);
	memset(&r->set, 0, sizeof(r->set));
	r->long_ = O7_BOOL_UNDEF;
}
o7_tag_t Ast_ExprNegate__s_tag;
extern void Ast_ExprNegate__s_undef(struct Ast_ExprNegate__s *r) {
	Ast_RFactor_undef(&r->_);
	r->expr = NULL;
}
o7_tag_t Ast_ExprBraces__s_tag;
extern void Ast_ExprBraces__s_undef(struct Ast_ExprBraces__s *r) {
	Ast_RFactor_undef(&r->_);
	r->expr = NULL;
}
o7_tag_t Ast_ExprRelation__s_tag;
extern void Ast_ExprRelation__s_undef(struct Ast_ExprRelation__s *r) {
	Ast_RExpression_undef(&r->_);
	r->relation = O7_INT_UNDEF;
	r->distance = O7_INT_UNDEF;
	memset(&r->exprs, 0, sizeof(r->exprs));
}
o7_tag_t Ast_ExprIsExtension__s_tag;
extern void Ast_ExprIsExtension__s_undef(struct Ast_ExprIsExtension__s *r) {
	Ast_RExpression_undef(&r->_);
	r->designator = NULL;
	r->extType = NULL;
}
o7_tag_t Ast_RExprSum_tag;
extern void Ast_RExprSum_undef(struct Ast_RExprSum *r) {
	Ast_RExpression_undef(&r->_);
	r->add = O7_INT_UNDEF;
	r->term = NULL;
	r->next = NULL;
}
o7_tag_t Ast_ExprTerm__s_tag;
extern void Ast_ExprTerm__s_undef(struct Ast_ExprTerm__s *r) {
	Ast_RExpression_undef(&r->_);
	r->factor = NULL;
	r->mult = O7_INT_UNDEF;
	r->expr = NULL;
}
#define Ast_RParameter_tag Ast_Node_tag
extern void Ast_RParameter_undef(struct Ast_RParameter *r) {
	Ast_Node_undef(&r->_);
	r->expr = NULL;
	r->next = NULL;
	r->distance = O7_INT_UNDEF;
}
o7_tag_t Ast_ExprCall__s_tag;
extern void Ast_ExprCall__s_undef(struct Ast_ExprCall__s *r) {
	Ast_RFactor_undef(&r->_);
	r->designator = NULL;
	r->params = NULL;
}
#define Ast_RStatement_tag Ast_Node_tag
extern void Ast_RStatement_undef(struct Ast_RStatement *r) {
	Ast_Node_undef(&r->_);
	r->expr = NULL;
	r->next = NULL;
}
o7_tag_t Ast_RWhileIf_tag;
extern void Ast_RWhileIf_undef(struct Ast_RWhileIf *r) {
	Ast_RStatement_undef(&r->_);
	r->stats = NULL;
	r->elsif = NULL;
}
o7_tag_t Ast_If__s_tag;
extern void Ast_If__s_undef(struct Ast_If__s *r) {
	Ast_RWhileIf_undef(&r->_);
}
#define Ast_RCaseLabel_tag Ast_Node_tag
extern void Ast_RCaseLabel_undef(struct Ast_RCaseLabel *r) {
	Ast_Node_undef(&r->_);
	r->value_ = O7_INT_UNDEF;
	r->qual = NULL;
	r->right = NULL;
	r->next = NULL;
}
#define Ast_RCaseElement_tag Ast_Node_tag
extern void Ast_RCaseElement_undef(struct Ast_RCaseElement *r) {
	Ast_Node_undef(&r->_);
	r->labels = NULL;
	r->stats = NULL;
	r->next = NULL;
}
o7_tag_t Ast_Case__s_tag;
extern void Ast_Case__s_undef(struct Ast_Case__s *r) {
	Ast_RStatement_undef(&r->_);
	r->elements = NULL;
	r->else_ = NULL;
}
o7_tag_t Ast_Repeat__s_tag;
extern void Ast_Repeat__s_undef(struct Ast_Repeat__s *r) {
	Ast_RStatement_undef(&r->_);
	r->stats = NULL;
}
o7_tag_t Ast_For__s_tag;
extern void Ast_For__s_undef(struct Ast_For__s *r) {
	Ast_RStatement_undef(&r->_);
	r->to = NULL;
	r->var_ = NULL;
	r->by = O7_INT_UNDEF;
	r->stats = NULL;
}
#define Ast_While__s_tag Ast_RWhileIf_tag
extern void Ast_While__s_undef(struct Ast_While__s *r) {
	Ast_RWhileIf_undef(&r->_);
}
o7_tag_t Ast_Assign__s_tag;
extern void Ast_Assign__s_undef(struct Ast_Assign__s *r) {
	Ast_RStatement_undef(&r->_);
	r->designator = NULL;
	r->distance = O7_INT_UNDEF;
}
o7_tag_t Ast_Call__s_tag;
extern void Ast_Call__s_undef(struct Ast_Call__s *r) {
	Ast_RStatement_undef(&r->_);
}
#define Ast_StatementError__s_tag Ast_RStatement_tag
extern void Ast_StatementError__s_undef(struct Ast_StatementError__s *r) {
	Ast_RStatement_undef(&r->_);
}

static struct Ast_RType *types[Ast_PredefinedTypesCount_cnst];
static struct Ast_RDeclaration *predefined[OberonSpecIdent_PredefinedLast_cnst - OberonSpecIdent_PredefinedFirst_cnst + 1];
static struct Ast_ExprBoolean__s *booleans[2];
static struct Ast_ExprNil__s *nil = NULL;

static struct Ast_RFactor *values = NULL;
static struct Ast_RNeedTagList *needTags = NULL;

extern void Ast_PutChars(struct Ast_RModule *m, struct StringStore_String *w, o7_int_t s_len0, o7_char s[/*len0*/], o7_int_t begin, o7_int_t end) {
	if (0 <= begin) {
		StringStore_Put(&O7_REF(m)->store, &(*w), s_len0, s, begin, end);
	} else {
		StringStore_Put(&O7_REF(m)->store, &(*w), 7, (o7_char *)"#error", 0, 5);
	}
}

static void NodeInit(struct Ast_Node *n, o7_int_t id) {
	O7_ASSERT((Ast_NoId_cnst <= id) && (id <= LastId_cnst) || (OberonSpecIdent_PredefinedFirst_cnst <= id) && (id <= OberonSpecIdent_PredefinedLast_cnst));
	V_Init(&(*n)._);
	(*n).id = id;
	(*n).emptyLines = 0;
	StringStore_Undef(&(*n).comment);
	(*n).ext = NULL;
}

extern void Ast_NodeSetComment(struct Ast_Node *n, struct Ast_RModule *m, o7_int_t com_len0, o7_char com[/*len0*/], o7_int_t ofs, o7_int_t end) {
	O7_ASSERT(!StringStore_IsDefined(&(*n).comment));
	Ast_PutChars(m, &(*n).comment, com_len0, com, ofs, end);
}

extern void Ast_DeclSetComment(struct Ast_RDeclaration *d, o7_int_t com_len0, o7_char com[/*len0*/], o7_int_t ofs, o7_int_t end) {
	Ast_NodeSetComment(&(*O7_REF(d))._, O7_REF(O7_REF(d)->module_)->m, com_len0, com, ofs, end);
}

extern void Ast_ModuleSetComment(struct Ast_RModule *m, o7_int_t com_len0, o7_char com[/*len0*/], o7_int_t ofs, o7_int_t end) {
	Ast_NodeSetComment(&(*O7_REF(m))._._._, m, com_len0, com, ofs, end);
}

static void DeclInit(struct Ast_RDeclaration *d, struct Ast_RDeclarations *ds) {
	if (ds == NULL) {
		O7_REF(d)->module_ = NULL;
		O7_REF(d)->up = NULL;
	} else {
		if ((O7_REF(ds)->_.module_ == NULL) && (o7_is(ds, &Ast_RModule_tag))) {
			O7_REF(d)->module_ = O7_GUARD(Ast_RModule, &ds)->bag;
		} else {
			O7_REF(d)->module_ = O7_REF(ds)->_.module_;
		}
		O7_REF(d)->up = O7_REF(ds)->dag;
	}
	O7_REF(d)->mark = (0 > 1);
	O7_REF(d)->used = (0 > 1);
	StringStore_Undef(&O7_REF(d)->name);
	O7_REF(d)->type = NULL;
	O7_REF(d)->next = NULL;
}

static void DeclConnect(struct Ast_RDeclaration *d, struct Ast_RDeclarations *ds, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t start, o7_int_t end) {
	struct Ast_RDeclaration *p;

	O7_ASSERT(d != NULL);
	O7_ASSERT(name[0] != 0x00u);
	O7_ASSERT(!(o7_is(d, &Ast_RModule_tag)));
	O7_ASSERT((O7_REF(ds)->start == NULL) || !(o7_is(O7_REF(ds)->start, &Ast_RModule_tag)));

	DeclInit(d, ds);
	if ((O7_REF(ds)->end != NULL) && (O7_REF(ds)->procedures != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		if (O7_REF(ds)->vars == NULL) {
			if (O7_REF(ds)->start == &O7_REF(ds)->procedures->_._._) {
				O7_REF(ds)->start = d;
			} else {
				p = O7_REF(ds)->start;
				while (!(o7_is(O7_REF(p)->next, &Ast_RProcedure_tag))) {
					p = O7_REF(p)->next;
				}
				O7_REF(p)->next = d;
			}
			O7_REF(d)->next = (&(O7_REF(ds)->procedures)->_._._);
		} else {
			O7_REF(d)->next = O7_REF(O7_REF(ds)->varsEnd)->_.next;
			O7_REF(O7_REF(ds)->varsEnd)->_.next = d;
			O7_REF(ds)->varsEnd = O7_GUARD(Ast_RVar, &d);
		}
	} else {
		if (O7_REF(ds)->end != NULL) {
			O7_ASSERT(O7_REF(O7_REF(ds)->end)->next == NULL);
			O7_REF(O7_REF(ds)->end)->next = d;
		} else {
			O7_ASSERT(O7_REF(ds)->start == NULL);
			O7_REF(ds)->start = d;
		}
		O7_ASSERT(!(o7_is(O7_REF(ds)->start, &Ast_RModule_tag)));
		O7_REF(ds)->end = d;
	}
	if (start >= 0) {
		Ast_PutChars(O7_REF(O7_REF(d)->module_)->m, &O7_REF(d)->name, name_len0, name, start, end);
	} else {
		Ast_PutChars(O7_REF(O7_REF(d)->module_)->m, &O7_REF(d)->name, 8, (o7_char *)"#ERROR ", 0, 5);
	}
}

static void DeclarationsInit(struct Ast_RDeclarations *d, struct Ast_RDeclarations *up) {
	DeclInit(&d->_, NULL);
	O7_NEW(&O7_REF(d)->dag, Ast_DeclarationsBag__s);
	O7_REF(O7_REF(d)->dag)->d = d;
	O7_REF(d)->start = NULL;
	O7_REF(d)->end = NULL;

	O7_REF(d)->consts = NULL;
	O7_REF(d)->types = NULL;
	O7_REF(d)->vars = NULL;
	O7_REF(d)->varsEnd = NULL;
	O7_REF(d)->procedures = NULL;
	if (up == NULL) {
		O7_REF(d)->_.up = NULL;
	} else {
		O7_REF(d)->_.up = O7_REF(up)->dag;
	}
	O7_REF(d)->stats = NULL;

	O7_REF(d)->recordForwardCount = 0;
}

static void DeclarationsConnect(struct Ast_RDeclarations *d, struct Ast_RDeclarations *up, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t start, o7_int_t end) {
	DeclarationsInit(d, up);
	if (name[0] != 0x00u) {
		DeclConnect(&d->_, up, name_len0, name, start, end);
	} else {
		/* Record */
		DeclInit(&d->_, up);
	}
	O7_REF(d)->_.up = O7_REF(up)->dag;
}

extern struct Ast_RModule *Ast_ModuleNew(o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RModule *m = NULL;

	O7_NEW(&m, Ast_RModule);
	NodeInit(&(*O7_REF(m))._._._, Ast_NoId_cnst);
	DeclarationsInit(&m->_, NULL);
	O7_NEW(&O7_REF(m)->bag, Ast_ModuleBag__s);
	O7_REF(O7_REF(m)->bag)->m = m;
	O7_REF(m)->fixed = (0 > 1);
	O7_REF(m)->spec = (0 > 1);
	O7_REF(m)->import_ = NULL;
	O7_REF(m)->errors = NULL;
	O7_REF(m)->errLast = NULL;
	StringStore_StoreInit(&O7_REF(m)->store);

	Ast_PutChars(m, &O7_REF(m)->_._.name, name_len0, name, begin, end);
	O7_REF(m)->_._.module_ = O7_REF(m)->bag;
	O7_REF(m)->errorHide = (0 < 1);
	O7_REF(m)->handleImport = (0 > 1);
	O7_REF(m)->script = (0 > 1);
	return m;
}

extern struct Ast_RModule *Ast_ScriptNew(void) {
	struct Ast_RModule *m;

	m = Ast_ModuleNew(9, (o7_char *)"script  ", 0, 6);
	O7_REF(m)->script = (0 < 1);
	return m;
}

extern struct Ast_RModule *Ast_ProvideModule(struct Ast_RProvider *prov, struct Ast_RModule *host, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t ofs, o7_int_t end) {
	O7_ASSERT(prov != NULL);
	O7_ASSERT((0 <= ofs) && (ofs <= end) && (end < name_len0));
	return O7_REF(prov)->get(prov, host, name_len0, name, ofs, end);
}

extern struct Ast_ModuleBag__s *Ast_GetModuleByName(struct Ast_RProvider *prov, struct Ast_RModule *host, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t ofs, o7_int_t end) {
	struct Ast_RModule *m;
	struct Ast_ModuleBag__s *b;

	m = Ast_ProvideModule(prov, host, name_len0, name, ofs, end);
	if (m != NULL) {
		b = O7_REF(m)->bag;
	} else {
		b = NULL;
	}
	return b;
}

extern o7_bool Ast_RegModule(struct Ast_RProvider *provider, struct Ast_RModule *m) {
	return O7_REF(provider)->reg(provider, m);
}

static o7_int_t CheckUnusedDeclarations(struct Ast_RDeclarations *ds) {
	struct Ast_RDeclaration *d;
	o7_int_t err;

	d = O7_REF(ds)->start;
	while ((d != NULL) && (o7_is(d, &Ast_Import__s_tag))) {
		d = O7_REF(d)->next;
	}
	while ((d != NULL) && (o7_bl(O7_REF(d)->mark) || o7_bl(O7_REF(d)->used) || (o7_is(d, &Ast_RVar_tag)) && (0 != (((1u << Ast_InitedValue_cnst) | (1u << Ast_InitedNil_cnst)) & O7_REF(O7_GUARD(Ast_RVar, &d)->state)->inited)))) {
		d = O7_REF(d)->next;
	}
	if (d == NULL) {
		err = Ast_ErrNo_cnst;
	} else {
		O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->unusedDecl = d;
		err = Ast_ErrDeclarationUnused_cnst;
	}
	return err;
}

extern o7_int_t Ast_ModuleEnd(struct Ast_RModule *m) {
	o7_int_t err;

	O7_ASSERT(!o7_bl(O7_REF(m)->fixed));
	O7_REF(m)->fixed = (0 < 1);
	if (o7_bl(O7_REF(m)->script)) {
		err = Ast_ErrNo_cnst;
	} else {
		err = CheckUnusedDeclarations(&m->_);
	}
	return err;
}

extern void Ast_ModuleReopen(struct Ast_RModule *m) {
	O7_ASSERT(o7_bl(O7_REF(m)->fixed));
	O7_REF(m)->fixed = (0 > 1);
}

extern void Ast_ImportHandle(struct Ast_RModule *m) {
	O7_ASSERT(!o7_bl(O7_REF(m)->handleImport));
	O7_REF(m)->handleImport = (0 < 1);
}

extern void Ast_ImportEnd(struct Ast_RModule *m) {
	O7_ASSERT(o7_bl(O7_REF(m)->handleImport));
	O7_REF(m)->handleImport = (0 > 1);
}

static o7_int_t ImportAdd_Load(struct Ast_ModuleBag__s **res, struct Ast_RProvider *prov, struct Ast_RModule *host, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t realOfs, o7_int_t realEnd) {
	o7_int_t err;
	struct Ast_RModule *m;

	(*res) = Ast_GetModuleByName(prov, host, buf_len0, buf, realOfs, realEnd);
	if ((*res) == NULL) {
		m = Ast_ModuleNew(buf_len0, buf, realOfs, realEnd);
		(*res) = O7_REF(m)->bag;
		err = Ast_ErrImportModuleNotFound_cnst;
	} else if (O7_REF(O7_REF((*res))->m)->errors != NULL) {
		err = Ast_ErrImportModuleWithError_cnst;
	} else if (o7_bl(O7_REF(O7_REF((*res))->m)->handleImport)) {
		err = Ast_ErrImportLoop_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	Log_Str(30, (o7_char *)"Модуль получен: ");
	Log_Int((o7_int_t)((*res) != NULL));
	Log_Ln();
	return err;
}

static o7_bool ImportAdd_IsDup(struct Ast_Import__s *i, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t nameOfs, o7_int_t nameEnd, o7_int_t realOfs, o7_int_t realEnd) {
	return StringStore_IsEqualToChars(&O7_REF(i)->_.name, buf_len0, buf, nameOfs, nameEnd) || (realOfs != nameOfs) && ((o7_cmp(O7_REF(i)->_.name.ofs, O7_REF(O7_REF(O7_REF(i)->_.module_)->m)->_._.name.ofs) != 0) || (O7_REF(i)->_.name.block != O7_REF(O7_REF(O7_REF(i)->_.module_)->m)->_._.name.block)) && StringStore_IsEqualToChars(&O7_REF(O7_REF(O7_REF(i)->_.module_)->m)->_._.name, buf_len0, buf, realOfs, realEnd);
}

extern o7_int_t Ast_ImportAdd(struct Ast_RProvider *prov, struct Ast_RModule *m, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t nameOfs, o7_int_t nameEnd, o7_int_t realOfs, o7_int_t realEnd) {
	struct Ast_Import__s *imp = NULL;
	struct Ast_RDeclaration *i;
	o7_int_t err;

	O7_ASSERT(!o7_bl(O7_REF(m)->fixed));

	i = (&(O7_REF(m)->import_)->_);
	O7_ASSERT((i == NULL) || (o7_is(O7_REF(m)->_.end, &Ast_Import__s_tag)));
	if (StringStore_IsEqualToChars(&O7_REF(m)->_._.name, buf_len0, buf, realOfs, realEnd)) {
		err = Ast_ErrImportSelf_cnst;
	} else {
		while ((i != NULL) && !ImportAdd_IsDup(O7_GUARD(Ast_Import__s, &i), buf_len0, buf, nameOfs, nameEnd, realOfs, realEnd)) {
			i = O7_REF(i)->next;
		}
		if (i != NULL) {
			err = Ast_ErrImportNameDuplicate_cnst;
		} else {
			O7_NEW(&imp, Ast_Import__s);
			NodeInit(&(*O7_REF(imp))._._, Ast_IdImport_cnst);
			DeclConnect(&imp->_, &m->_, buf_len0, buf, nameOfs, nameEnd);
			O7_REF(imp)->_.mark = (0 < 1);
			if (O7_REF(m)->import_ == NULL) {
				O7_REF(m)->import_ = imp;
			}
			err = ImportAdd_Load(&O7_REF(imp)->_.module_, prov, m, buf_len0, buf, realOfs, realEnd);
		}
	}
	return err;
}

static struct Ast_RDeclaration *SearchName(struct Ast_RDeclaration *d, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	if (begin < 0) {
		d = NULL;
	} else {
		while ((d != NULL) && !StringStore_IsEqualToChars(&O7_REF(d)->name, buf_len0, buf, begin, end)) {
			O7_ASSERT(!(o7_is(d, &Ast_RModule_tag)));
			d = O7_REF(d)->next;
		}
	}
	return d;
}

static struct Ast_RDeclaration *DeclarationLineSearch(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d;

	d = SearchName(O7_REF(ds)->start, buf_len0, buf, begin, end);
	if ((d == NULL) && (o7_is(ds, &Ast_RProcedure_tag))) {
		d = SearchName(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._, buf_len0, buf, begin, end);
	}
	return d;
}

static o7_int_t CheckNameDuplicate(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err = O7_INT_UNDEF;

	if (begin < 0) {
		err = Ast_ErrNo_cnst;
	} else if (DeclarationLineSearch(ds, buf_len0, buf, begin, end) != NULL) {
		err = Ast_ErrDeclarationNameDuplicate_cnst;
	} else if (o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->errorHide) && (O7_REF(ds)->_.up != NULL) && (DeclarationLineSearch(&O7_REF(O7_REF(ds)->_.module_)->m->_, buf_len0, buf, begin, end) != NULL)) {
		err = Ast_ErrDeclarationNameHide_cnst;
	} else if (o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->errorHide) && OberonSpecIdent_IsPredefined(&err, buf_len0, buf, begin, end)) {
		err = Ast_ErrPredefinedNameHide_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_ConstAdd(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_Const__s *c = NULL;
	o7_int_t err;

	O7_ASSERT(!o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->fixed));

	O7_NEW(&c, Ast_Const__s);
	NodeInit(&(*O7_REF(c))._._, Ast_IdConst_cnst);
	err = CheckNameDuplicate(ds, buf_len0, buf, begin, end);
	DeclConnect(&c->_, ds, buf_len0, buf, begin, end);
	O7_REF(c)->expr = NULL;
	O7_REF(c)->finished = (0 > 1);
	if (O7_REF(ds)->consts == NULL) {
		O7_REF(ds)->consts = c;
	}
	return err;
}

extern o7_int_t Ast_ConstSetExpression(struct Ast_Const__s *const_, struct Ast_RExpression *expr) {
	o7_int_t err;

	O7_REF(const_)->finished = (0 < 1);
	err = Ast_ErrNo_cnst;
	if (expr != NULL) {
		O7_REF(const_)->expr = expr;
		O7_REF(const_)->_.type = O7_REF(expr)->type;
		if ((O7_REF(expr)->type != NULL) && (O7_REF(expr)->value_ == NULL)) {
			err = Ast_ErrConstDeclExprNotConst_cnst;
		}
	}
	return err;
}

static void TypeAdd_MoveForwardDeclToLast(struct Ast_RDeclarations *ds, struct Ast_RRecord *rec) {
	struct Ast_RDeclaration *t;

	if (O7_REF(rec)->_._._.next != NULL) {
		if (O7_REF(O7_REF(rec)->pointer)->_._._.next == &rec->_._._) {
			t = (&(O7_REF(rec)->pointer)->_._._);
		} else {
			t = (&(O7_REF(ds)->types)->_);
			while (O7_REF(t)->next != &rec->_._._) {
				t = O7_REF(t)->next;
			}
		}
		O7_REF(t)->next = O7_REF(rec)->_._._.next;
		O7_REF(rec)->_._._.next = NULL;

		O7_REF(O7_REF(ds)->end)->next = (&(rec)->_._._);
		O7_REF(ds)->end = (&(rec)->_._._);
	}
	O7_REF(ds)->recordForwardCount = o7_sub(O7_REF(ds)->recordForwardCount, 1);
	O7_ASSERT(o7_cmp(0, O7_REF(ds)->recordForwardCount) <= 0);
}

extern o7_int_t Ast_TypeAdd(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end, struct Ast_RType **td) {
	struct Ast_RDeclaration *d;
	o7_int_t err = O7_INT_UNDEF;

	O7_ASSERT(!o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->fixed));

	d = DeclarationLineSearch(ds, buf_len0, buf, begin, end);
	if (((d == NULL) || (o7_cmp(O7_REF(d)->_.id, Ast_IdRecordForward_cnst) == 0)) || (d == NULL) && ((O7_REF(ds)->_.up == NULL) || (DeclarationLineSearch(&O7_REF(O7_REF(ds)->_.module_)->m->_, buf_len0, buf, begin, end) == NULL))) {
		if (OberonSpecIdent_IsPredefined(&err, buf_len0, buf, begin, end)) {
			err = Ast_ErrPredefinedNameHide_cnst;
		} else {
			err = Ast_ErrNo_cnst;
		}
	} else if (d == NULL) {
		err = Ast_ErrDeclarationNameHide_cnst;
	} else {
		err = Ast_ErrDeclarationNameDuplicate_cnst;
	}
	if ((d == NULL) || (err == Ast_ErrDeclarationNameDuplicate_cnst)) {
		O7_ASSERT((*td) != NULL);
		DeclConnect(&(*td)->_, ds, buf_len0, buf, begin, end);
		if (O7_REF(ds)->types == NULL) {
			O7_REF(ds)->types = (*td);
		}
	} else {
		(*td) = O7_GUARD(Ast_RType, &d);
		TypeAdd_MoveForwardDeclToLast(ds, O7_GUARD(Ast_RRecord, &d));
	}
	return err;
}

extern o7_int_t Ast_CheckUndefRecordForward(struct Ast_RDeclarations *ds) {
	o7_int_t err;

	if (o7_cmp(O7_REF(ds)->recordForwardCount, 0) == 0) {
		err = Ast_ErrNo_cnst;
	} else {
		err = Ast_ErrRecordForwardUndefined_cnst;
		O7_REF(ds)->recordForwardCount = 0;
	}
	return err;
}

static void VarStateInit(struct Ast_RVarState *vs, struct Ast_RVarState *root) {
	O7_ASSERT(O7_REF(root)->else_ == NULL);

	O7_REF(vs)->inited = O7_REF(root)->inited & ~((1u << Ast_Used_cnst) | (1u << Ast_Dereferenced_cnst));
	O7_REF(vs)->inCondition = O7_REF(root)->inited != (1u << Ast_InitedValue_cnst);
	O7_REF(vs)->root = root;
	if (O7_REF(root)->if_ == NULL) {
		O7_REF(root)->if_ = vs;
	} else {
		O7_REF(root)->else_ = vs;
	}
}

static void VarStateRootInit(struct Ast_RVarState *vs) {
	O7_REF(vs)->inited = (1u << Ast_InitedNo_cnst);
	O7_REF(vs)->inCondition = (0 > 1);
	O7_REF(vs)->if_ = NULL;
	O7_REF(vs)->else_ = NULL;
	O7_REF(vs)->root = NULL;
}

static struct Ast_RVarState *VarStateNew(struct Ast_RVarState *root) {
	struct Ast_RVarState *vs = NULL;

	O7_NEW(&vs, Ast_RVarState);
	VarStateInit(vs, root);
	return vs;
}

static void VarStateUp(struct Ast_RVarState **vs) {
	O7_ASSERT((O7_REF(O7_REF((*vs))->root)->if_ == (*vs)) || (O7_REF(O7_REF((*vs))->root)->else_ == (*vs)));

	(*vs) = O7_REF((*vs))->root;
	if (O7_REF((*vs))->else_ != NULL) {
		if (!!( (1u << Ast_InitedFail_cnst) & O7_REF(O7_REF((*vs))->else_)->inited)) {
			O7_REF((*vs))->inited = O7_REF(O7_REF((*vs))->if_)->inited;
		} else {
			O7_REF((*vs))->inited = O7_REF(O7_REF((*vs))->if_)->inited | O7_REF(O7_REF((*vs))->else_)->inited;
		}
		O7_REF((*vs))->else_ = NULL;
	} else {
		O7_REF((*vs))->inited = O7_REF((*vs))->inited | O7_REF(O7_REF((*vs))->if_)->inited;
	}
	O7_REF((*vs))->if_ = NULL;
}

static void TurnIf_Handle(struct Ast_RDeclaration *d) {
	struct Ast_RVar *v;
	struct Ast_RVarState *vs;

	while ((d != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		v = O7_GUARD(Ast_RVar, &d);
		O7_ASSERT(O7_REF(O7_REF(v)->state)->if_ == NULL);
		vs = VarStateNew(O7_REF(v)->state);
		O7_ASSERT(O7_REF(O7_REF(v)->state)->if_ == vs);
		O7_REF(v)->state = vs;
		d = O7_REF(d)->next;
	}
}

extern void Ast_TurnIf(struct Ast_RDeclarations *ds) {
	if (o7_is(ds, &Ast_RProcedure_tag)) {
		TurnIf_Handle(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._);
		TurnIf_Handle(&O7_REF(ds)->vars->_);
	}
}

static void TurnElse_Handle(struct Ast_RDeclaration *d) {
	struct Ast_RVar *v;
	struct Ast_RVarState *vs;

	while ((d != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		v = O7_GUARD(Ast_RVar, &d);
		O7_ASSERT(O7_REF(O7_REF(O7_REF(v)->state)->root)->if_ == O7_REF(v)->state);
		vs = VarStateNew(O7_REF(O7_REF(v)->state)->root);
		O7_ASSERT(O7_REF(O7_REF(O7_REF(v)->state)->root)->else_ == vs);
		O7_ASSERT(O7_REF(O7_REF(O7_REF(v)->state)->root)->if_ == O7_REF(v)->state);
		O7_REF(v)->state = vs;
		d = O7_REF(d)->next;
	}
}

extern void Ast_TurnElse(struct Ast_RDeclarations *ds) {
	if (o7_is(ds, &Ast_RProcedure_tag)) {
		TurnElse_Handle(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._);
		TurnElse_Handle(&O7_REF(ds)->vars->_);
	}
}

static void TurnFail_Handle(struct Ast_RDeclaration *d) {
	while ((d != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		O7_REF(O7_GUARD(Ast_RVar, &d)->state)->inited |= 1u << Ast_InitedFail_cnst;
		d = O7_REF(d)->next;
	}
}

extern void Ast_TurnFail(struct Ast_RDeclarations *ds) {
	if (o7_is(ds, &Ast_RProcedure_tag)) {
		TurnFail_Handle(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._);
		TurnFail_Handle(&O7_REF(ds)->vars->_);
	}
}

static void BackFromBranch_Handle(struct Ast_RDeclaration *d) {
	while ((d != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		VarStateUp(&O7_GUARD(Ast_RVar, &d)->state);
		d = O7_REF(d)->next;
	}
}

extern void Ast_BackFromBranch(struct Ast_RDeclarations *ds) {
	if (o7_is(ds, &Ast_RProcedure_tag)) {
		BackFromBranch_Handle(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._);
		BackFromBranch_Handle(&O7_REF(ds)->vars->_);
	}
}

static void ChecklessVarAdd(struct Ast_RVar **v, struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	O7_NEW(&(*v), Ast_RVar);
	NodeInit(&(*O7_REF((*v)))._._, Ast_IdVar_cnst);
	DeclConnect(&(*v)->_, ds, buf_len0, buf, begin, end);
	O7_REF((*v))->_.type = NULL;

	O7_NEW(&O7_REF((*v))->state, Ast_RVarState);
	VarStateRootInit(O7_REF((*v))->state);
	O7_REF((*v))->checkInit = (0 > 1);
	O7_REF((*v))->inVarParam = (0 > 1);

	if (O7_REF(ds)->vars == NULL) {
		O7_REF(ds)->vars = (*v);
	}
	O7_REF(ds)->varsEnd = (*v);
}

extern o7_int_t Ast_VarAdd(struct Ast_RVar **v, struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	O7_ASSERT((O7_REF(ds)->_.module_ == NULL) || !o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->fixed));
	err = CheckNameDuplicate(ds, buf_len0, buf, begin, end);
	ChecklessVarAdd(&(*v), ds, buf_len0, buf, begin, end);
	return err;
}

static void TypeInit(struct Ast_RType *t, o7_int_t id) {
	NodeInit(&(*O7_REF(t))._._, id);
	DeclInit(&t->_, NULL);
	O7_REF(t)->properties = 0;
	O7_REF(t)->array_ = NULL;
}

extern struct Ast_RProcType *Ast_ProcTypeNew(o7_bool forType) {
	struct Ast_RProcType *p = NULL;
	struct FormalProcType__s *fp = NULL;

	if (forType) {
		O7_NEW(&fp, FormalProcType__s);
		p = (&(fp)->_);
	} else {
		O7_NEW(&p, Ast_RProcType);
	}
	TypeInit(&p->_._, Ast_IdProcType_cnst);
	O7_REF(p)->params = NULL;
	O7_REF(p)->end = NULL;
	return p;
}

static void ParamAddPredefined(struct Ast_RProcType *proc, struct Ast_RType *type, o7_set_t access) {
	struct Ast_RFormalParam *v = NULL;

	O7_ASSERT(0 == (access & ~((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst))));

	O7_NEW(&v, Ast_RFormalParam);
	NodeInit(&(*O7_REF(v))._._._, Ast_IdVar_cnst);
	if (O7_REF(proc)->end == NULL) {
		O7_REF(proc)->params = v;
	} else {
		O7_REF(O7_REF(proc)->end)->_._.next = (&(v)->_._);
	}
	O7_REF(proc)->end = v;

	O7_REF(v)->_._.module_ = NULL;
	O7_REF(v)->_._.up = NULL;

	O7_REF(v)->_._.mark = (0 > 1);
	O7_REF(v)->_._.next = NULL;
	O7_REF(v)->link = NULL;

	O7_REF(v)->_._.type = type;
	if (access == 0) {
		O7_REF(v)->access = (1u << Ast_ParamIn_cnst);
	} else {
		O7_REF(v)->access = access;
	}
	O7_REF(v)->needTag = NULL;

	O7_NEW(&O7_REF(v)->_.state, Ast_RVarState);
	VarStateRootInit(O7_REF(v)->_.state);
	O7_REF(v)->_.checkInit = (0 > 1);
	O7_REF(v)->_.inVarParam = (0 > 1);
	if (!!( (1u << Ast_ParamIn_cnst) & O7_REF(v)->access)) {
		O7_REF(O7_REF(v)->_.state)->inited = (1u << Ast_InitedValue_cnst);
	} else {
		O7_REF(O7_REF(v)->_.state)->inited = (1u << Ast_InitedNo_cnst);
	}
}

extern o7_int_t Ast_ParamAdd(struct Ast_RModule *module_, struct Ast_RProcType *proc, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end, o7_set_t access) {
	o7_int_t err = O7_INT_UNDEF;

	if (SearchName(&O7_REF(proc)->params->_._, buf_len0, buf, begin, end) != NULL) {
		err = Ast_ErrDeclarationNameDuplicate_cnst;
	} else if (!(o7_is(proc, &FormalProcType__s_tag)) && (DeclarationLineSearch(&module_->_, buf_len0, buf, begin, end) != NULL)) {
		err = Ast_ErrDeclarationNameHide_cnst;
	} else if (o7_bl(O7_REF(module_)->errorHide) && OberonSpecIdent_IsPredefined(&err, buf_len0, buf, begin, end)) {
		err = Ast_ErrPredefinedNameHide_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	ParamAddPredefined(proc, NULL, access);
	Ast_PutChars(module_, &O7_REF(O7_REF(proc)->end)->_._.name, buf_len0, buf, begin, end);
	return err;
}

extern o7_int_t Ast_ParamInsert(struct Ast_RFormalParam **new_, struct Ast_RFormalParam *prev, struct Ast_RModule *module_, struct Ast_RProcType *proc, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end, struct Ast_RType *type, o7_set_t access) {
	o7_int_t err;
	struct Ast_RFormalParam *fpEnd;

	O7_ASSERT(O7_REF(proc)->end != NULL);
	fpEnd = O7_REF(proc)->end;
	err = Ast_ParamAdd(module_, proc, buf_len0, buf, begin, end, access);
	(*new_) = O7_REF(proc)->end;
	O7_REF((*new_))->_._.type = type;
	if (O7_REF(prev)->_._.next != &(*new_)->_._) {
		O7_REF((*new_))->_._.next = O7_REF(prev)->_._.next;
		O7_REF(prev)->_._.next = (&((*new_))->_._);
		O7_REF(proc)->end = fpEnd;
		O7_REF(fpEnd)->_._.next = NULL;
	}
	return err;
}

extern o7_bool Ast_IsNeedTag(struct Ast_RFormalParam *p) {
	return (O7_REF(p)->needTag != NULL) && (O7_REF(O7_REF(p)->needTag)->value_);
}

static void NewNeedTag(struct Ast_RFormalParam *p, o7_bool need) {
	O7_ASSERT(O7_REF(p)->needTag == NULL);
	O7_ASSERT(O7_REF(p)->link == NULL);

	O7_NEW(&O7_REF(p)->needTag, Ast_RNeedTagList);
	O7_REF(O7_REF(p)->needTag)->count = 1;
	O7_REF(O7_REF(p)->needTag)->first = p;
	O7_REF(O7_REF(p)->needTag)->last = p;

	O7_REF(O7_REF(p)->needTag)->value_ = need;

	O7_REF(O7_REF(p)->needTag)->next = needTags;
	needTags = O7_REF(p)->needTag;
}

static void SetNeedTag(struct Ast_RFormalParam *p) {
	if (O7_REF(p)->needTag == NULL) {
		NewNeedTag(p, (0 < 1));
	} else {
		O7_REF(O7_REF(p)->needTag)->value_ = (0 < 1);
	}
}

static void ExchangeParamsNeedTag(struct Ast_RFormalParam *p1, struct Ast_RFormalParam *p2);
static void ExchangeParamsNeedTag_Merge(struct Ast_RNeedTagList *list, struct Ast_RNeedTagList *del) {
	O7_ASSERT(list != del);
	O7_ASSERT(O7_REF(O7_REF(list)->last)->link == NULL);
	O7_ASSERT(O7_REF(del)->last != NULL);

	if (o7_bl(O7_REF(del)->value_)) {
		O7_REF(list)->value_ = (0 < 1);
	}
	O7_REF(list)->count = o7_add(O7_REF(list)->count, O7_REF(del)->count);
	O7_REF(O7_REF(list)->last)->link = O7_REF(del)->first;
	O7_REF(list)->last = O7_REF(del)->last;
	O7_ASSERT(O7_REF(O7_REF(list)->last)->link == NULL);
	O7_REF(del)->last = NULL;
	while (O7_REF(del)->first != NULL) {
		O7_REF(O7_REF(del)->first)->needTag = list;
		O7_REF(del)->last = O7_REF(O7_REF(del)->first)->link;
		O7_REF(del)->first = O7_REF(del)->last;
	}
	O7_ASSERT(O7_REF(list)->last != NULL);
}

static void ExchangeParamsNeedTag_Add(struct Ast_RNeedTagList *list, struct Ast_RFormalParam *p) {
	O7_ASSERT(O7_REF(p)->link == NULL);
	O7_ASSERT(O7_REF(p)->needTag == NULL);

	O7_REF(O7_REF(list)->last)->link = p;
	O7_REF(list)->last = p;
	O7_ASSERT(O7_REF(list)->last != NULL);
	O7_REF(p)->needTag = list;
}

static void ExchangeParamsNeedTag(struct Ast_RFormalParam *p1, struct Ast_RFormalParam *p2) {
	if (p1 == p2) {
	} else if (O7_REF(p1)->needTag == NULL) {
		if (O7_REF(p2)->needTag == NULL) {
			NewNeedTag(p2, (0 > 1));
		}
		ExchangeParamsNeedTag_Add(O7_REF(p2)->needTag, p1);
	} else {
		if (O7_REF(p2)->needTag == NULL) {
			ExchangeParamsNeedTag_Add(O7_REF(p1)->needTag, p2);
		} else if (o7_cmp(O7_REF(O7_REF(p2)->needTag)->count, O7_REF(O7_REF(p1)->needTag)->count) > 0) {
			ExchangeParamsNeedTag_Merge(O7_REF(p2)->needTag, O7_REF(p1)->needTag);
		} else if (O7_REF(p1)->needTag != O7_REF(p2)->needTag) {
			ExchangeParamsNeedTag_Merge(O7_REF(p1)->needTag, O7_REF(p2)->needTag);
		}
	}
}

extern o7_int_t Ast_ProcTypeSetReturn(struct Ast_RProcType *proc, struct Ast_RType *type) {
	o7_int_t err;

	O7_REF(proc)->_._._.type = type;
	if (!(o7_in(O7_REF(type)->_._.id, ((1u << Ast_IdArray_cnst) | (1u << Ast_IdRecord_cnst))))) {
		err = Ast_ErrNo_cnst;
	} else {
		err = Ast_ErrReturnTypeArrayOrRecord_cnst;
	}
	return err;
}

extern void Ast_AddError(struct Ast_RModule *m, o7_int_t error, o7_int_t line, o7_int_t column) {
	struct Ast_RError *e = NULL;

	O7_NEW(&e, Ast_RError);
	NodeInit(&(*O7_REF(e))._, Ast_NoId_cnst);
	O7_REF(e)->next = NULL;
	O7_REF(e)->code = error;
	O7_REF(e)->line = line;
	O7_REF(e)->column = column;
	if (O7_REF(m)->unusedDecl == NULL) {
		StringStore_Undef(&O7_REF(e)->str);
	} else {
		O7_REF(e)->str = O7_REF(O7_REF(m)->unusedDecl)->name;
		O7_REF(m)->unusedDecl = NULL;
	}
	if (O7_REF(m)->errLast == NULL) {
		O7_REF(m)->errors = e;
	} else {
		O7_REF(O7_REF(m)->errLast)->next = e;
	}
	O7_REF(m)->errLast = e;
}

extern struct Ast_RType *Ast_TypeGet(o7_int_t id) {
	O7_ASSERT(types[o7_ind(Ast_PredefinedTypesCount_cnst, id)] != NULL);
	return types[o7_ind(Ast_PredefinedTypesCount_cnst, id)];
}

extern struct Ast_RArray *Ast_ArrayGet(struct Ast_RType *t, struct Ast_RExpression *count) {
	struct Ast_RArray *a = NULL;

	if ((count != NULL) || (t == NULL) || (O7_REF(t)->array_ == NULL)) {
		O7_NEW(&a, Ast_RArray);
		TypeInit(&a->_._, Ast_IdArray_cnst);
		O7_REF(a)->count = count;
		if ((t != NULL) && (count == NULL)) {
			O7_REF(t)->array_ = a;
		}
		O7_REF(a)->_._._.type = t;
	} else {
		a = O7_REF(t)->array_;
	}
	return a;
}

extern o7_int_t Ast_MultArrayLenByExpr(o7_int_t *size, struct Ast_RExpression *e) {
	o7_int_t i, err;

	err = Ast_ErrNo_cnst;
	if (e == NULL) {
	} else if ((O7_REF(e)->value_ != NULL) && (o7_is(O7_REF(e)->value_, &Ast_RExprInteger_tag))) {
		i = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(e)->value_)->int_);
		if (i <= 0) {
			err = Ast_ErrArrayLenLess1_cnst;
		} else if (!CheckIntArithmetic_Mul(&(*size), (*size), i)) {
			(*size) = 0;
			err = Ast_ErrArrayLenTooBig_cnst;
		}
	} else if (o7_cmp(O7_REF(e)->_.id, Ast_IdError_cnst) != 0) {
		err = Ast_ErrExpectConstIntExpr_cnst;
	}
	return err;
}

extern struct Ast_RPointer *Ast_PointerGet(struct Ast_RRecord *t) {
	struct Ast_RPointer *p = NULL;

	if ((t == NULL) || (O7_REF(t)->pointer == NULL)) {
		O7_NEW(&p, Ast_RPointer);
		TypeInit(&p->_._, Ast_IdPointer_cnst);
		O7_REF(p)->_._._.type = (&(t)->_._);
		if (t != NULL) {
			O7_REF(t)->pointer = p;
		}
	} else {
		p = O7_REF(t)->pointer;
	}
	return p;
}

extern void Ast_PointerSetRecord(struct Ast_RPointer *tp, struct Ast_RRecord *subtype) {
	O7_REF(tp)->_._._.type = (&(subtype)->_._);
	O7_REF(subtype)->pointer = tp;
}

extern o7_int_t Ast_PointerSetType(struct Ast_RPointer *tp, struct Ast_RType *subtype) {
	o7_int_t err;

	if (o7_in(O7_REF(subtype)->_._.id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdRecordForward_cnst)))) {
		Ast_PointerSetRecord(tp, O7_GUARD(Ast_RRecord, &subtype));
		err = Ast_ErrNo_cnst;
	} else {
		O7_REF(tp)->_._._.type = subtype;
		err = Ast_ErrPointerToNotRecord_cnst;
	}
	return err;
}

extern void Ast_RecordSetBase(struct Ast_RRecord *r, struct Ast_RRecord *base) {
	O7_ASSERT(O7_REF(r)->base == NULL);
	O7_ASSERT(O7_REF(r)->vars == NULL);
	O7_REF(r)->base = base;
}

static void RecNew(struct Ast_RRecord **r, o7_int_t id) {
	O7_ASSERT(o7_in(id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdRecordForward_cnst))));

	O7_NEW(&(*r), Ast_RRecord);
	TypeInit(&(*r)->_._, id);
	O7_REF((*r))->pointer = NULL;
	O7_REF((*r))->vars = NULL;
	O7_REF((*r))->base = NULL;
	O7_REF((*r))->needTag = (0 > 1);
	O7_REF((*r))->inAssign = (0 < 1);
	O7_REF((*r))->complete = (0 > 1);
}

extern struct Ast_RRecord *Ast_RecordNew(struct Ast_RDeclarations *ds, struct Ast_RRecord *base) {
	struct Ast_RRecord *r = NULL;

	RecNew(&r, Ast_IdRecord_cnst);
	Ast_RecordSetBase(r, base);
	return r;
}

extern struct Ast_RRecord *Ast_RecordForwardNew(struct Ast_RDeclarations *ds, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RRecord *r = NULL;

	RecNew(&r, Ast_IdRecordForward_cnst);
	DeclConnect(&r->_._._, ds, name_len0, name, begin, end);
	O7_REF(ds)->recordForwardCount = o7_add(O7_REF(ds)->recordForwardCount, 1);
	return r;
}

extern o7_int_t Ast_RecordEnd(struct Ast_RRecord *r) {
	O7_ASSERT(o7_in(O7_REF(r)->_._._._.id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdRecordForward_cnst))));
	O7_REF(r)->_._._._.id = Ast_IdRecord_cnst;
	O7_REF(r)->_._._.used = (0 < 1);
	O7_REF(r)->complete = (0 < 1);
	return Ast_ErrNo_cnst;
}

extern struct Ast_RDeclaration *Ast_PredefinedGet(o7_int_t id) {
	return predefined[o7_ind(OberonSpecIdent_PredefinedLast_cnst - OberonSpecIdent_PredefinedFirst_cnst + 1, o7_sub(id, OberonSpecIdent_PredefinedFirst_cnst))];
}

static struct Ast_RDeclaration *SearchPredefined(o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d;
	o7_int_t l = O7_INT_UNDEF;

	if (OberonSpecIdent_IsPredefined(&l, buf_len0, buf, begin, end)) {
		d = Ast_PredefinedGet(o7_int(l));
		O7_ASSERT(d != NULL);
	} else {
		d = NULL;
	}
	return d;
}

extern struct Ast_RDeclaration *Ast_DeclarationSearch(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d;

	if (o7_is(ds, &Ast_RProcedure_tag)) {
		d = SearchName(&O7_REF(O7_GUARD(Ast_RProcedure, &ds)->_.header)->params->_._, buf_len0, buf, begin, end);
	} else {
		d = NULL;
	}
	if (d == NULL) {
		d = SearchName(O7_REF(ds)->start, buf_len0, buf, begin, end);
		if (o7_is(ds, &Ast_RProcedure_tag)) {
			if (d == NULL) {
				do {
					ds = O7_REF(O7_REF(ds)->_.up)->d;
				} while (!((ds == NULL) || (o7_is(ds, &Ast_RModule_tag))));
				if (ds != NULL) {
					d = SearchName(O7_REF(ds)->start, buf_len0, buf, begin, end);
				}
			}
		} else {
			while ((d == NULL) && (O7_REF(ds)->_.up != NULL)) {
				ds = O7_REF(O7_REF(ds)->_.up)->d;
				d = SearchName(O7_REF(ds)->start, buf_len0, buf, begin, end);
			}
		}
		if ((d == NULL) && (o7_is(ds, &Ast_RModule_tag)) && !o7_bl(O7_GUARD(Ast_RModule, &ds)->fixed)) {
			d = SearchPredefined(buf_len0, buf, begin, end);
		}
	}
	if ((d != NULL) && (o7_is(d, &Ast_RType_tag))) {
		O7_REF(d)->used = (0 < 1);
		if (o7_is(d, &Ast_RVar_tag)) {
			O7_REF(O7_GUARD(Ast_RVar, &d)->state)->inited |= 1u << Ast_Used_cnst;
		}
	}
	return d;
}

extern struct Ast_RType *Ast_TypeErrorNew(void) {
	struct Ast_RType *type = NULL;

	O7_NEW(&type, Ast_RType);
	NodeInit(&(*O7_REF(type))._._, Ast_IdError_cnst);
	DeclInit(&type->_, NULL);
	return type;
}

extern struct Ast_RDeclaration *Ast_DeclErrorNew(struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d = NULL;

	O7_NEW(&d, Ast_RDeclaration);
	NodeInit(&(*O7_REF(d))._, Ast_IdError_cnst);
	DeclConnect(d, ds, buf_len0, buf, begin, end);
	O7_REF(d)->type = Ast_TypeErrorNew();
	O7_REF(d)->used = (0 < 1);
	O7_REF(d)->mark = (0 < 1);
	return d;
}

extern o7_int_t Ast_DeclarationGet(struct Ast_RDeclaration **d, struct Ast_RProvider *prov, struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	(*d) = Ast_DeclarationSearch(ds, buf_len0, buf, begin, end);
	if ((*d) == NULL) {
		if ((O7_REF(ds)->_.module_ != NULL) && o7_bl(O7_REF(O7_REF(O7_REF(ds)->_.module_)->m)->script)) {
			err = Ast_ImportAdd(prov, O7_REF(O7_REF(ds)->_.module_)->m, buf_len0, buf, begin, end, begin, end);
			(*d) = O7_REF(ds)->end;
		} else {
			err = Ast_ErrNo_cnst;
		}
		if (((*d) == NULL) && (err == Ast_ErrNo_cnst)) {
			err = Ast_ErrDeclarationNotFound_cnst;
			(*d) = Ast_DeclErrorNew(ds, buf_len0, buf, begin, end);
			O7_ASSERT(O7_REF((*d))->type != NULL);
		}
	} else if (!o7_bl(O7_REF((*d))->mark) && (O7_REF((*d))->module_ != NULL) && o7_bl(O7_REF(O7_REF(O7_REF((*d))->module_)->m)->fixed)) {
		err = Ast_ErrDeclarationIsPrivate_cnst;
	} else if ((o7_is((*d), &Ast_Const__s_tag)) && !o7_bl(O7_GUARD(Ast_Const__s, &(*d))->finished)) {
		err = Ast_ErrConstRecursive_cnst;
		O7_GUARD(Ast_Const__s, &(*d))->finished = (0 < 1);
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_VarGet(struct Ast_RVar **v, struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;
	struct Ast_RDeclaration *d;

	d = Ast_DeclarationSearch(ds, buf_len0, buf, begin, end);
	if (d == NULL) {
		err = Ast_ErrDeclarationNotFound_cnst;
	} else if (o7_cmp(O7_REF(d)->_.id, Ast_IdVar_cnst) != 0) {
		err = Ast_ErrDeclarationNotVar_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	if (err == Ast_ErrNo_cnst) {
		(*v) = O7_GUARD(Ast_RVar, &d);
		if (!o7_bl(O7_REF(d)->mark) && o7_bl(O7_REF(O7_REF(O7_REF(d)->module_)->m)->fixed)) {
			err = Ast_ErrDeclarationIsPrivate_cnst;
		}
	} else {
		ChecklessVarAdd(&(*v), ds, buf_len0, buf, begin, end);
	}
	return err;
}

extern o7_int_t Ast_ForIteratorGet(struct Ast_RVar **v, struct Ast_RDeclarations *ds, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	err = Ast_VarGet(&(*v), ds, buf_len0, buf, begin, end);
	if ((*v) != NULL) {
		if (O7_REF((*v))->_.type == NULL) {
			O7_REF((*v))->_.type = Ast_TypeGet(Ast_IdInteger_cnst);
		} else if (o7_cmp(O7_REF(O7_REF((*v))->_.type)->_._.id, Ast_IdInteger_cnst) != 0) {
			err = Ast_ErrForIteratorNotInteger_cnst;
		}
	}
	return err;
}

static void ExprInit(struct Ast_RExpression *e, o7_int_t id, struct Ast_RType *t) {
	NodeInit(&(*O7_REF(e))._, id);
	if (t != NULL) {
		O7_REF(t)->_.used = (0 < 1);
	}
	O7_REF(e)->type = t;
	O7_REF(e)->properties = 0;
	O7_REF(e)->value_ = NULL;
}

static void ValueInit(struct Ast_RFactor *f, o7_int_t id, struct Ast_RType *t) {
	ExprInit(&f->_, id, t);
	O7_REF(f)->_.value_ = f;
	O7_REF(f)->nextValue = values;
	values = f;
}

extern struct Ast_RExprInteger *Ast_ExprIntegerNew(o7_int_t int_) {
	struct Ast_RExprInteger *e = NULL;

	O7_NEW(&e, Ast_RExprInteger);
	ValueInit(&e->_._, Ast_IdInteger_cnst, Ast_TypeGet(Ast_IdInteger_cnst));
	O7_REF(e)->int_ = int_;
	return e;
}

extern struct Ast_ExprReal__s *Ast_ExprRealNew(double real, struct Ast_RModule *m, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_ExprReal__s *e = NULL;

	O7_ASSERT(m != NULL);
	O7_NEW(&e, Ast_ExprReal__s);
	ValueInit(&e->_._, Ast_IdReal_cnst, Ast_TypeGet(Ast_IdReal_cnst));
	O7_REF(e)->real = real;
	Ast_PutChars(m, &O7_REF(e)->str, buf_len0, buf, begin, end);
	return e;
}

extern struct Ast_ExprReal__s *Ast_ExprRealNewByValue(double real) {
	struct Ast_ExprReal__s *e = NULL;

	O7_NEW(&e, Ast_ExprReal__s);
	ValueInit(&e->_._, Ast_IdReal_cnst, Ast_TypeGet(Ast_IdReal_cnst));
	O7_REF(e)->real = real;
	StringStore_Undef(&O7_REF(e)->str);
	return e;
}

extern struct Ast_ExprBoolean__s *Ast_ExprBooleanGet(o7_bool bool_) {
	struct Ast_ExprBoolean__s *e;

	e = booleans[o7_ind(2, (o7_int_t)o7_bl(bool_))];
	if (e == NULL) {
		O7_NEW(&e, Ast_ExprBoolean__s);
		ValueInit(&e->_, Ast_IdBoolean_cnst, Ast_TypeGet(Ast_IdBoolean_cnst));
		O7_REF(e)->bool_ = bool_;
		booleans[o7_ind(2, (o7_int_t)o7_bl(bool_))] = e;
	}
	return e;
}

extern struct Ast_ExprString__s *Ast_ExprStringNew(struct Ast_RModule *m, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_ExprString__s *e = NULL;
	o7_int_t len;

	len = o7_sub(end, begin);
	if (len < 0) {
		len = o7_sub(o7_add(len, buf_len0), 1);
	}
	len = o7_sub(len, 1);
	O7_NEW(&e, Ast_ExprString__s);
	ValueInit(&e->_._._, Ast_IdString_cnst, &Ast_ArrayGet(Ast_TypeGet(Ast_IdChar_cnst), &Ast_ExprIntegerNew(len)->_._._)->_._);
	O7_REF(e)->_.int_ =  - 1;
	O7_REF(e)->asChar = (0 > 1);
	Ast_PutChars(m, &O7_REF(e)->string, buf_len0, buf, begin, end);
	return e;
}

extern struct Ast_ExprString__s *Ast_ExprCharNew(o7_int_t int_) {
	struct Ast_ExprString__s *e = NULL;

	O7_NEW(&e, Ast_ExprString__s);
	ValueInit(&e->_._._, Ast_IdString_cnst, &Ast_ArrayGet(Ast_TypeGet(Ast_IdChar_cnst), &Ast_ExprIntegerNew(2)->_._._)->_._);
	StringStore_Undef(&O7_REF(e)->string);
	O7_REF(e)->_.int_ = int_;
	O7_REF(e)->asChar = (0 < 1);
	return e;
}

extern struct Ast_ExprNil__s *Ast_ExprNilGet(void) {
	if (nil == NULL) {
		O7_NEW(&nil, Ast_ExprNil__s);
		ValueInit(&nil->_, Ast_IdPointer_cnst, Ast_TypeGet(Ast_IdPointer_cnst));
		O7_REF(nil)->_._.properties = (1u << Ast_ExprPointerTouch_cnst);
		O7_ASSERT(O7_REF(O7_REF(nil)->_._.type)->_.type == NULL);
	}
	return nil;
}

extern struct Ast_RExpression *Ast_ExprErrNew(void) {
	struct Ast_RFactor *e = NULL;

	O7_NEW(&e, Ast_RFactor);
	ExprInit(&e->_, Ast_IdError_cnst, Ast_TypeErrorNew());
	return (&(e)->_);
}

static o7_set_t Prop(struct Ast_RExpression *e) {
	o7_set_t p;

	if (e == NULL) {
		p = 0;
	} else {
		p = O7_REF(e)->properties;
	}
	return p;
}

static void PropTouch(struct Ast_RExpression *e, o7_set_t prop) {
	O7_REF(e)->properties = O7_REF(e)->properties | prop & ((1u << Ast_ExprPointerTouch_cnst) | (1u << Ast_ExprIntNegativeDividentTouch_cnst));
}

extern struct Ast_ExprBraces__s *Ast_ExprBracesNew(struct Ast_RExpression *expr) {
	struct Ast_ExprBraces__s *e = NULL;

	O7_NEW(&e, Ast_ExprBraces__s);
	ExprInit(&e->_._, Ast_IdBraces_cnst, O7_REF(expr)->type);
	O7_REF(e)->expr = expr;
	O7_REF(e)->_._.value_ = O7_REF(expr)->value_;
	PropTouch(&e->_._, Prop(expr));
	return e;
}

extern struct Ast_ExprSetValue__s *Ast_ExprSetByValue(LongSet_Type set) {
	struct Ast_ExprSetValue__s *e = NULL;

	O7_NEW(&e, Ast_ExprSetValue__s);
	ValueInit(&e->_, Ast_IdSet_cnst, Ast_TypeGet(Ast_IdSet_cnst));
	memcpy(O7_REF(e)->set, set, (2) * sizeof(set[0]));
	return e;
}

extern o7_int_t Ast_ExprSetNew(struct Ast_RExprSet **base, struct Ast_RExprSet **e, struct Ast_RExpression *expr1, struct Ast_RExpression *expr2) {
	o7_int_t err, left, right = O7_INT_UNDEF;
	LongSet_Type set;

	O7_NEW(&(*e), Ast_RExprSet);
	ExprInit(&(*e)->_._, Ast_IdSet_cnst, Ast_TypeGet(Ast_IdSet_cnst));
	O7_REF((*e))->exprs[0] = expr1;
	O7_REF((*e))->exprs[1] = expr2;
	O7_REF((*e))->next = NULL;
	err = Ast_ErrNo_cnst;
	if ((expr1 == NULL) && (expr2 == NULL)) {
	} else if ((expr1 != NULL) && (O7_REF(expr1)->type != NULL) && ((expr2 == NULL) || (O7_REF(expr2)->type != NULL))) {
		if ((o7_cmp(O7_REF(O7_REF(expr1)->type)->_._.id, Ast_IdInteger_cnst) != 0) || (expr2 != NULL) && (o7_cmp(O7_REF(O7_REF(expr2)->type)->_._.id, Ast_IdInteger_cnst) != 0)) {
			err = Ast_ErrNotIntSetElem_cnst;
		} else if ((O7_REF(expr1)->value_ != NULL) && ((expr2 == NULL) || (O7_REF(expr2)->value_ != NULL))) {
			LongSet_Empty(set);
			left = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(expr1)->value_)->int_);
			if (expr2 != NULL) {
				right = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(expr2)->value_)->int_);
			}
			if (!LongSet_InRange(left) || (expr2 != NULL) && !LongSet_InRange(o7_int(right))) {
				err = Ast_ErrSetElemOutOfRange_cnst;
			} else if (expr2 == NULL) {
				if (left <= TypesLimits_SetMax_cnst) {
					set[0] = (1u << left);
				} else {
					set[1] = (1u << (o7_mod(left, (TypesLimits_SetMax_cnst + 1))));
				}
			} else if (o7_cmp(left, right) > 0) {
				err = Ast_ErrSetLeftElemBiggerRightElem_cnst;
			} else if (o7_cmp(right, TypesLimits_SetMax_cnst) <= 0) {
				set[0] = o7_set(left, right);
			} else if (left > TypesLimits_SetMax_cnst) {
				set[1] = o7_set(o7_mod(left, (TypesLimits_SetMax_cnst + 1)), o7_mod(right, (TypesLimits_SetMax_cnst + 1)));
			} else {
				set[0] = o7_set(left, TypesLimits_SetMax_cnst);
				set[1] = ((1u << 0) | (1u << (o7_mod(right, (TypesLimits_SetMax_cnst + 1)))));
			}
			if (err == Ast_ErrNo_cnst) {
				O7_REF((*e))->_._.value_ = (&(Ast_ExprSetByValue(set))->_);

				O7_REF((*e))->_.nextValue = values;
				values = (&((*e))->_);
			}
		}
	}
	if ((*base) == NULL) {
		(*base) = (*e);
	} else if ((O7_REF((*base))->_._.value_ != NULL) && (O7_REF((*e))->_._.value_ != NULL)) {
		LongSet_Union(O7_GUARD(Ast_ExprSetValue__s, &O7_REF((*base))->_._.value_)->set, set);
	}
	PropTouch(&(*base)->_._, Prop(expr1) | Prop(expr2));
	return err;
}

extern o7_int_t Ast_ExprNegateNew(struct Ast_ExprNegate__s **neg, struct Ast_RExpression *expr) {
	o7_int_t err;

	O7_NEW(&(*neg), Ast_ExprNegate__s);
	ExprInit(&(*neg)->_._, Ast_IdNegate_cnst, Ast_TypeGet(Ast_IdBoolean_cnst));
	O7_REF((*neg))->expr = expr;
	PropTouch(&(*neg)->_._, Prop(expr));
	if ((O7_REF(expr)->type != NULL) && (o7_cmp(O7_REF(O7_REF(expr)->type)->_._.id, Ast_IdBoolean_cnst) != 0)) {
		err = Ast_ErrNegateNotBool_cnst;
	} else {
		err = Ast_ErrNo_cnst;
		if (O7_REF(expr)->value_ != NULL) {
			O7_REF((*neg))->_._.value_ = (&(Ast_ExprBooleanGet(!o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(expr)->value_)->bool_)))->_);
		}
	}
	return err;
}

extern o7_int_t Ast_DesignatorNew(struct Ast_Designator__s **d, struct Ast_RDeclaration *decl) {
	O7_NEW(&(*d), Ast_Designator__s);
	ExprInit(&(*d)->_._, Ast_IdDesignator_cnst, NULL);
	O7_REF((*d))->decl = decl;
	O7_REF((*d))->sel = NULL;
	O7_REF((*d))->_._.type = O7_REF(decl)->type;
	if (o7_is(decl, &Ast_RVar_tag)) {
		O7_REF((*d))->inited = O7_REF(O7_GUARD(Ast_RVar, &decl)->state)->inited;
	} else {
		O7_REF((*d))->inited = (1u << Ast_InitedValue_cnst);
		if (o7_is(decl, &Ast_Const__s_tag)) {
			O7_REF((*d))->_._.value_ = O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->value_;
		} else if (o7_is(decl, &Ast_RGeneralProcedure_tag)) {
			O7_REF((*d))->_._.type = (&(O7_GUARD(Ast_RGeneralProcedure, &decl)->header)->_._);
		}
	}
	return Ast_ErrNo_cnst;
}

extern o7_bool Ast_IsGlobal(struct Ast_RDeclaration *d) {
	return (O7_REF(d)->up != NULL) && (O7_REF(O7_REF(O7_REF(d)->up)->d)->_.up == NULL);
}

static void DesignatorUsed_InVarParam(struct Ast_RVar *v, struct Ast_RSelector *sel) {
	if (sel == NULL) {
		O7_REF(v)->inVarParam = (0 < 1);
	} else {
		while (O7_REF(sel)->next != NULL) {
			sel = O7_REF(sel)->next;
		}
		if (o7_is(sel, &Ast_SelRecord__s_tag)) {
			O7_REF(O7_GUARD(Ast_SelRecord__s, &sel)->var_)->inVarParam = (0 < 1);
		}
	}
}

extern o7_int_t Ast_DesignatorUsed(struct Ast_Designator__s *d, o7_bool varParam, o7_bool inLoop) {
	o7_int_t err;
	struct Ast_RVar *v;

	err = Ast_ErrNo_cnst;
	if (o7_is(O7_REF(d)->decl, &Ast_RVar_tag)) {
		v = O7_GUARD(Ast_RVar, &O7_REF(d)->decl);

		if (varParam) {
			DesignatorUsed_InVarParam(v, O7_REF(d)->sel);
		}

		if ((o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdPointer_cnst) == 0) && (O7_REF(d)->sel != NULL) && !Ast_IsGlobal(&v->_) && (!(!!( (1u << Ast_InitedValue_cnst) & O7_REF(O7_REF(v)->state)->inited)) && !(o7_bl(O7_REF(O7_REF(v)->state)->inCondition) && inLoop) || !o7_bl(O7_REF(O7_REF(v)->state)->inCondition) && (0 != (O7_REF(O7_REF(v)->state)->inited & ((1u << Ast_InitedNo_cnst) | (1u << Ast_InitedNil_cnst)))))) {
			err = Ast_ErrVarUninitialized_cnst;
		} else if (varParam) {
			if (!(!!( (1u << Ast_InitedValue_cnst) & O7_REF(O7_REF(v)->state)->inited))) {
				O7_REF(v)->checkInit = (0 < 1);
				O7_REF(O7_REF(v)->state)->inited |= 1u << Ast_InitedCheck_cnst;
			}
			O7_REF(O7_REF(v)->state)->inited = (O7_REF(O7_REF(v)->state)->inited & ~(1u << Ast_InitedNo_cnst)) | (1u << Ast_InitedValue_cnst);
		} else if (!(!(!!( (1u << Ast_InitedNo_cnst) & O7_REF(O7_REF(v)->state)->inited)) || o7_bl(O7_REF(O7_REF(v)->state)->inCondition) && (0 != (O7_REF(O7_REF(v)->state)->inited & ~(1u << Ast_InitedNo_cnst)))) && !inLoop && ((O7_REF(v)->_.up != NULL) && (O7_REF(O7_REF(O7_REF(v)->_.up)->d)->_.up != NULL) || (o7_is(v, &Ast_RFormalParam_tag)))) {
			err = o7_sub(Ast_ErrVarUninitialized_cnst, (o7_int_t)(!!( (1u << Ast_InitedValue_cnst) & O7_REF(O7_REF(v)->state)->inited)));
			O7_REF(O7_REF(v)->state)->inited = (1u << Ast_InitedValue_cnst);
		} else if (!!( (1u << Ast_InitedNo_cnst) & O7_REF(O7_REF(v)->state)->inited)) {
			O7_REF(O7_REF(v)->state)->inited |= 1u << Ast_InitedCheck_cnst;
			O7_REF(v)->checkInit = (0 < 1);
		}
		O7_REF(O7_REF(v)->state)->inited |= 1u << Ast_Used_cnst;
	} else if (varParam && (o7_cmp(O7_REF(O7_REF(d)->decl)->_.id, Ast_IdProc_cnst) == 0)) {
		O7_GUARD(Ast_RProcedure, &O7_REF(d)->decl)->usedAsValue = (0 < 1);
	}
	O7_REF(O7_REF(d)->decl)->used = (0 < 1);
	return err;
}

extern o7_int_t Ast_CheckInited(struct Ast_RDeclarations *ds) {
	o7_int_t err;
	struct Ast_RDeclaration *d;
	o7_char name[128];
	o7_int_t len;
	memset(&name, 0, sizeof(name));

	d = (&(O7_REF(ds)->vars)->_);
	while ((d != NULL) && (o7_is(d, &Ast_RVar_tag)) && (!(!!( (1u << Ast_Used_cnst) & O7_REF(O7_GUARD(Ast_RVar, &d)->state)->inited)) || (!!( (1u << Ast_InitedValue_cnst) & O7_REF(O7_GUARD(Ast_RVar, &d)->state)->inited)))) {
		d = O7_REF(d)->next;
	}
	if ((d != NULL) && (o7_is(d, &Ast_RVar_tag))) {
		len = 0;
		if (StringStore_CopyToChars(128, name, &len, &O7_REF(d)->name)) {
			Log_StrLn(128, name);
		}
		err = Ast_ErrVarMayUninitialized_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_bool Ast_IsRecordExtension(o7_int_t *distance, struct Ast_RRecord *t0, struct Ast_RRecord *t1) {
	o7_int_t dist;

	if ((t0 != NULL) && (t1 != NULL)) {
		dist = 0;
		do {
			t1 = O7_REF(t1)->base;
			dist = o7_add(dist, 1);
		} while (!((t0 == t1) || (t1 == NULL)));
		if (t0 == t1) {
			(*distance) = dist;
		}
	} else {
		t0 = NULL;
		t1 = NULL;
	}
	return t0 == t1;
}

static void SelInit(struct Ast_RSelector *s) {
	NodeInit(&(*O7_REF(s))._, Ast_NoId_cnst);
	O7_REF(s)->type = NULL;
	O7_REF(s)->next = NULL;
}

extern o7_int_t Ast_SelPointerNew(struct Ast_RSelector **sel, struct Ast_RType **type) {
	struct Ast_SelPointer__s *sp = NULL;
	o7_int_t err;

	O7_NEW(&sp, Ast_SelPointer__s);
	SelInit(&sp->_);
	(*sel) = (&(sp)->_);
	O7_REF((*type))->_.used = (0 < 1);
	if (o7_is((*type), &Ast_RPointer_tag)) {
		err = Ast_ErrNo_cnst;
		(*type) = O7_REF((*type))->_.type;
		O7_REF((*sel))->type = (*type);
	} else {
		err = Ast_ErrDerefToNotPointer_cnst;
	}
	return err;
}

extern o7_int_t Ast_SelArrayNew(struct Ast_RSelector **sel, struct Ast_RType **type, struct Ast_RExpression *index) {
	struct Ast_SelArray__s *sa = NULL;
	o7_int_t err;

	O7_NEW(&sa, Ast_SelArray__s);
	SelInit(&sa->_);
	O7_REF(sa)->index = index;
	(*sel) = (&(sa)->_);
	if (!(o7_is((*type), &Ast_RArray_tag))) {
		err = Ast_ErrArrayItemToNotArray_cnst;
	} else if (o7_cmp(O7_REF(O7_REF(index)->type)->_._.id, Ast_IdInteger_cnst) != 0) {
		err = Ast_ErrArrayIndexNotInt_cnst;
	} else if ((O7_REF(index)->value_ != NULL) && (o7_cmp(O7_GUARD(Ast_RExprInteger, &O7_REF(index)->value_)->int_, 0) < 0)) {
		err = Ast_ErrArrayIndexNegative_cnst;
	} else if ((O7_REF(index)->value_ != NULL) && (O7_GUARD(Ast_RArray, &(*type))->count != NULL) && (O7_REF(O7_GUARD(Ast_RArray, &(*type))->count)->value_ != NULL) && (o7_cmp(O7_GUARD(Ast_RExprInteger, &O7_REF(index)->value_)->int_, O7_GUARD(Ast_RExprInteger, &O7_REF(O7_GUARD(Ast_RArray, &(*type))->count)->value_)->int_) >= 0)) {
		err = Ast_ErrArrayIndexOutOfRange_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	(*type) = O7_REF((*type))->_.type;
	O7_REF((*sel))->type = (*type);
	return err;
}

static struct Ast_RVar *RecordVarSearch(struct Ast_RRecord *r, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d;
	struct Ast_RVar *v;

	d = SearchName(&O7_REF(r)->vars->_, name_len0, name, begin, end);
	while ((d == NULL) && (O7_REF(r)->base != NULL)) {
		r = O7_REF(r)->base;
		d = SearchName(&O7_REF(r)->vars->_, name_len0, name, begin, end);
	}
	if (d != NULL) {
		v = O7_GUARD(Ast_RVar, &d);
	} else {
		v = NULL;
	}
	return v;
}

static struct Ast_RVar *RecordChecklessVarAdd(struct Ast_RRecord *r, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RVar *v = NULL;
	struct Ast_RDeclaration *last;

	O7_NEW(&v, Ast_RVar);
	NodeInit(&(*O7_REF(v))._._, Ast_IdVar_cnst);
	DeclInit(&v->_, NULL);
	O7_REF(v)->_.module_ = O7_REF(r)->_._._.module_;
	O7_REF(v)->inVarParam = (0 > 1);
	O7_REF(v)->checkInit = (0 > 1);
	Ast_PutChars(O7_REF(O7_REF(v)->_.module_)->m, &O7_REF(v)->_.name, name_len0, name, begin, end);
	if (O7_REF(r)->vars == NULL) {
		O7_REF(r)->vars = v;
	} else {
		last = (&(O7_REF(r)->vars)->_);
		while (O7_REF(last)->next != NULL) {
			last = O7_REF(last)->next;
		}
		O7_REF(last)->next = (&(v)->_);
	}
	return v;
}

extern o7_int_t Ast_RecordVarAdd(struct Ast_RVar **v, struct Ast_RRecord *r, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	(*v) = RecordVarSearch(r, name_len0, name, begin, end);
	if ((*v) == NULL) {
		err = Ast_ErrNo_cnst;
	} else {
		err = Ast_ErrDeclarationNameDuplicate_cnst;
	}
	(*v) = RecordChecklessVarAdd(r, name_len0, name, begin, end);
	return err;
}

extern o7_int_t Ast_RecordVarGet(struct Ast_RVar **v, struct Ast_RRecord *r, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	(*v) = RecordVarSearch(r, name_len0, name, begin, end);
	if ((*v) == NULL) {
		err = Ast_ErrDeclarationNotFound_cnst;
		(*v) = RecordChecklessVarAdd(r, name_len0, name, begin, end);
		O7_REF((*v))->_.type = Ast_TypeGet(Ast_IdInteger_cnst);
	} else if (!o7_bl(O7_REF((*v))->_.mark) && o7_bl(O7_REF(O7_REF(O7_REF((*v))->_.module_)->m)->fixed)) {
		err = Ast_ErrDeclarationIsPrivate_cnst;
		O7_REF((*v))->_.mark = (0 < 1);
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_VarListSetType(struct Ast_RDeclaration *first, struct Ast_RType *t) {
	struct Ast_RDeclaration *d;
	o7_int_t err;

	d = first;
	O7_REF(t)->_.used = (0 < 1);
	while (d != NULL) {
		O7_REF(d)->type = t;
		d = O7_REF(d)->next;
	}

	err = Ast_ErrNo_cnst;
	if (o7_cmp(O7_REF(t)->_._.id, Ast_IdPointer_cnst) == 0) {
		if ((o7_cmp(O7_REF(O7_REF(t)->_.type)->_._.id, Ast_IdRecord_cnst) == 0) && !o7_bl(O7_GUARD(Ast_RRecord, &O7_REF(t)->_.type)->complete)) {
			err = Ast_ErrVarOfPointerToRecordForward_cnst;
		}
	} else if ((o7_cmp(O7_REF(t)->_._.id, Ast_IdRecordForward_cnst) == 0) || (o7_cmp(O7_REF(t)->_._.id, Ast_IdRecord_cnst) == 0) && !o7_bl(O7_GUARD(Ast_RRecord, &t)->complete)) {
		err = Ast_ErrVarOfRecordForward_cnst;
	}
	return err;
}

extern o7_int_t Ast_ArraySetType(struct Ast_RArray *a, struct Ast_RType *t) {
	o7_int_t err;

	O7_ASSERT(O7_REF(a)->_._._.type == NULL);
	O7_REF(a)->_._._.type = t;

	err = Ast_ErrNo_cnst;
	if (o7_cmp(O7_REF(t)->_._.id, Ast_IdPointer_cnst) == 0) {
		if ((o7_cmp(O7_REF(O7_REF(t)->_.type)->_._.id, Ast_IdRecord_cnst) == 0) && !o7_bl(O7_GUARD(Ast_RRecord, &O7_REF(t)->_.type)->complete)) {
			err = Ast_ErrArrayTypeOfPointerToRecordForward_cnst;
		}
	} else if ((o7_cmp(O7_REF(t)->_._.id, Ast_IdRecordForward_cnst) == 0) || (o7_cmp(O7_REF(t)->_._.id, Ast_IdRecord_cnst) == 0) && !o7_bl(O7_GUARD(Ast_RRecord, &t)->complete)) {
		err = Ast_ErrArrayTypeOfRecordForward_cnst;
	}
	return err;
}

extern o7_int_t Ast_ArrayGetSubtype(struct Ast_RArray *a, struct Ast_RType **subtype) {
	struct Ast_RType *t;
	o7_int_t i;

	t = O7_REF(a)->_._._.type;
	i = 1;
	while (o7_cmp(O7_REF(t)->_._.id, Ast_IdArray_cnst) == 0) {
		i = o7_add(i, 1);
		t = O7_REF(t)->_.type;
	}
	(*subtype) = t;
	return i;
}

extern o7_int_t Ast_SelRecordNew(struct Ast_RSelector **sel, struct Ast_RType **type, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_SelRecord__s *sr = NULL;
	o7_int_t err;
	struct Ast_RRecord *record;
	struct Ast_RVar *var_ = NULL;

	O7_NEW(&sr, Ast_SelRecord__s);
	SelInit(&sr->_);
	var_ = NULL;
	err = Ast_ErrNo_cnst;
	if ((*type) != NULL) {
		if (!(o7_in(O7_REF((*type))->_._.id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdPointer_cnst))))) {
			err = Ast_ErrDotSelectorToNotRecord_cnst;
		} else {
			if (o7_cmp(O7_REF((*type))->_._.id, Ast_IdRecord_cnst) == 0) {
				record = O7_GUARD(Ast_RRecord, &(*type));
			} else if (O7_REF((*type))->_.type == NULL) {
				record = NULL;
			} else {
				record = O7_GUARD(Ast_RRecord, &O7_REF((*type))->_.type);
			}
			if (record != NULL) {
				err = Ast_RecordVarGet(&var_, record, name_len0, name, begin, end);
				if (var_ != NULL) {
					(*type) = O7_REF(var_)->_.type;
				} else {
					(*type) = NULL;
				}
			}
		}
	}
	O7_REF(sr)->var_ = var_;
	(*sel) = (&(sr)->_);
	O7_REF((*sel))->type = (*type);
	return err;
}

extern o7_int_t Ast_SelGuardNew(struct Ast_RSelector **sel, struct Ast_Designator__s *des, struct Ast_RDeclaration *guard) {
	struct Ast_SelGuard__s *sg = NULL;
	o7_int_t err, dist = O7_INT_UNDEF;

	O7_NEW(&sg, Ast_SelGuard__s);
	SelInit(&sg->_);
	err = Ast_ErrNo_cnst;
	if (!(o7_in(O7_REF(O7_REF(des)->_._.type)->_._.id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdPointer_cnst))))) {
		err = Ast_ErrGuardedTypeNotExtensible_cnst;
	} else if (o7_cmp(O7_REF(O7_REF(des)->_._.type)->_._.id, Ast_IdRecord_cnst) == 0) {
		if ((guard == NULL) || !(o7_is(guard, &Ast_RRecord_tag)) || !Ast_IsRecordExtension(&dist, O7_GUARD(Ast_RRecord, &O7_REF(des)->_._.type), O7_GUARD(Ast_RRecord, &guard))) {
			err = Ast_ErrGuardExpectRecordExt_cnst;
		} else {
			O7_REF(des)->_._.type = (&(O7_GUARD(Ast_RRecord, &guard))->_._);
			O7_GUARD(Ast_RRecord, &guard)->needTag = (0 < 1);
			if ((O7_REF(des)->sel == NULL) && (o7_is(O7_REF(des)->decl, &Ast_RFormalParam_tag))) {
				SetNeedTag(O7_GUARD(Ast_RFormalParam, &O7_REF(des)->decl));
			}
		}
	} else {
		if ((guard == NULL) || !(o7_is(guard, &Ast_RPointer_tag)) || !Ast_IsRecordExtension(&dist, O7_GUARD(Ast_RRecord, &O7_GUARD(Ast_RPointer, &O7_REF(des)->_._.type)->_._._.type), O7_GUARD(Ast_RRecord, &O7_GUARD(Ast_RPointer, &guard)->_._._.type))) {
			err = Ast_ErrGuardExpectPointerExt_cnst;
		} else {
			O7_REF(des)->_._.type = (&(O7_GUARD(Ast_RPointer, &guard))->_._);
			O7_GUARD(Ast_RRecord, &O7_REF(guard)->type)->needTag = (0 < 1);
		}
	}
	O7_REF(sg)->_.type = O7_REF(des)->_._.type;
	(*sel) = (&(sg)->_);
	return err;
}

extern o7_bool Ast_EqualProcTypes(struct Ast_RProcType *t1, struct Ast_RProcType *t2) {
	o7_bool comp;
	struct Ast_RDeclaration *fp1, *fp2;

	comp = O7_REF(t1)->_._._.type == O7_REF(t2)->_._._.type;
	if (comp) {
		fp1 = (&(O7_REF(t1)->params)->_._);
		fp2 = (&(O7_REF(t2)->params)->_._);
		while ((fp1 != NULL) && (fp2 != NULL) && (o7_is(fp1, &Ast_RFormalParam_tag)) && (o7_is(fp2, &Ast_RFormalParam_tag)) && (O7_REF(fp1)->type == O7_REF(fp2)->type) && (O7_GUARD(Ast_RFormalParam, &fp1)->access == O7_GUARD(Ast_RFormalParam, &fp2)->access)) {
			ExchangeParamsNeedTag(O7_GUARD(Ast_RFormalParam, &fp1), O7_GUARD(Ast_RFormalParam, &fp2));
			fp1 = O7_REF(fp1)->next;
			fp2 = O7_REF(fp2)->next;
		}
		comp = ((fp1 == NULL) || !(o7_is(fp1, &Ast_RFormalParam_tag))) && ((fp2 == NULL) || !(o7_is(fp2, &Ast_RFormalParam_tag)));
	}
	return comp;
}

extern o7_bool Ast_CompatibleTypes(o7_int_t *distance, struct Ast_RType *t1, struct Ast_RType *t2, o7_bool param) {
	o7_bool comp;

	(*distance) = 0;
	/* совместимы, если ошибка в разборе */
	comp = (t1 == NULL) || (t2 == NULL);
	if (!comp) {
		comp = t1 == t2;
		if (comp) {
		} else if ((o7_cmp(O7_REF(t1)->_._.id, O7_REF(t2)->_._.id) == 0) && (o7_in(O7_REF(t1)->_._.id, ((1u << Ast_IdArray_cnst) | (1u << Ast_IdPointer_cnst) | (1u << Ast_IdRecord_cnst) | (1u << Ast_IdProcType_cnst))))) {
			switch (O7_REF(t1)->_._.id) {
			case 10:
				comp = ((param && (O7_GUARD(Ast_RArray, &t1)->count == NULL)) || (!param && (O7_GUARD(Ast_RArray, &t2)->count == NULL))) && Ast_CompatibleTypes(&(*distance), O7_REF(t1)->_.type, O7_REF(t2)->_.type, param);
				break;
			case 9:
				comp = (O7_REF(t1)->_.type == O7_REF(t2)->_.type) || (O7_REF(t1)->_.type == NULL) || (O7_REF(t2)->_.type == NULL) || Ast_IsRecordExtension(&(*distance), O7_GUARD(Ast_RRecord, &O7_REF(t1)->_.type), O7_GUARD(Ast_RRecord, &O7_REF(t2)->_.type));
				break;
			case 11:
				comp = Ast_IsRecordExtension(&(*distance), O7_GUARD(Ast_RRecord, &t1), O7_GUARD(Ast_RRecord, &t2));
				break;
			case 13:
				comp = Ast_EqualProcTypes(O7_GUARD(Ast_RProcType, &t1), O7_GUARD(Ast_RProcType, &t2));
				break;
			default:
				o7_case_fail(O7_REF(t1)->_._.id);
				break;
			}
		} else if (o7_cmp(O7_REF(t1)->_._.id, Ast_IdProcType_cnst) == 0) {
			comp = (o7_cmp(O7_REF(t2)->_._.id, Ast_IdPointer_cnst) == 0) && (O7_REF(t2)->_.type == NULL);
		} else if (o7_cmp(O7_REF(t2)->_._.id, Ast_IdProcType_cnst) == 0) {
			comp = (o7_cmp(O7_REF(t1)->_._.id, Ast_IdPointer_cnst) == 0) && (O7_REF(t1)->_.type == NULL);
		}
	}
	return comp;
}

extern o7_int_t Ast_ExprIsExtensionNew(struct Ast_ExprIsExtension__s **e, struct Ast_RExpression *des, struct Ast_RType *type) {
	o7_int_t err, dist = O7_INT_UNDEF;
	struct Ast_RType *desType;

	O7_NEW(&(*e), Ast_ExprIsExtension__s);
	ExprInit(&(*e)->_, Ast_IdIsExtension_cnst, Ast_TypeGet(Ast_IdBoolean_cnst));
	O7_REF((*e))->designator = NULL;
	O7_REF((*e))->extType = type;
	err = Ast_ErrNo_cnst;
	if ((type != NULL) && !(o7_in(O7_REF(type)->_._.id, ((1u << Ast_IdPointer_cnst) | (1u << Ast_IdRecord_cnst))))) {
		err = Ast_ErrIsExtTypeNotRecord_cnst;
	} else if (des == NULL) {
	} else if (o7_is(des, &Ast_Designator__s_tag)) {
		O7_REF((*e))->designator = O7_GUARD(Ast_Designator__s, &des);
		desType = O7_REF(des)->type;
		if (desType == NULL) {
		} else if (!(o7_in(O7_REF(O7_REF(des)->type)->_._.id, ((1u << Ast_IdPointer_cnst) | (1u << Ast_IdRecord_cnst))))) {
			err = Ast_ErrIsExtVarNotRecord_cnst;
		} else if (o7_cmp(O7_REF(type)->_._.id, O7_REF(O7_REF(des)->type)->_._.id) != 0) {
			err = Ast_ErrIsExtMeshupPtrAndRecord_cnst;
		} else {
			if (o7_cmp(O7_REF(type)->_._.id, Ast_IdPointer_cnst) == 0) {
				type = O7_REF(type)->_.type;
				desType = O7_REF(desType)->_.type;
			} else if ((O7_REF(O7_REF((*e))->designator)->sel == NULL) && (o7_is(O7_REF(O7_REF((*e))->designator)->decl, &Ast_RFormalParam_tag))) {
				SetNeedTag(O7_GUARD(Ast_RFormalParam, &O7_REF(O7_REF((*e))->designator)->decl));
			}
			if (Ast_IsRecordExtension(&dist, O7_GUARD(Ast_RRecord, &desType), O7_GUARD(Ast_RRecord, &type))) {
				O7_GUARD(Ast_RRecord, &type)->needTag = (0 < 1);
			} else {
				err = Ast_ErrIsExtExpectRecordExt_cnst;
			}
		}
	} else {
		err = Ast_ErrIsExtVarNotRecord_cnst;
	}
	return err;
}

static o7_bool CompatibleAsCharAndString(struct Ast_RType *t1, struct Ast_RExpression **e2) {
	o7_bool ret;

	ret = (o7_cmp(O7_REF(t1)->_._.id, Ast_IdChar_cnst) == 0) && (O7_REF((*e2))->value_ != NULL) && (o7_is(O7_REF((*e2))->value_, &Ast_ExprString__s_tag)) && (o7_cmp(O7_GUARD(Ast_ExprString__s, &O7_REF((*e2))->value_)->_.int_, 0) >= 0);
	if (ret && !o7_bl(O7_GUARD(Ast_ExprString__s, &O7_REF((*e2))->value_)->asChar)) {
		if (o7_is((*e2), &Ast_ExprString__s_tag)) {
			(*e2) = (&(Ast_ExprCharNew(o7_int(O7_GUARD(Ast_ExprString__s, &O7_REF((*e2))->value_)->_.int_)))->_._._._);
		} else {
			O7_REF((*e2))->value_ = (&(Ast_ExprCharNew(o7_int(O7_GUARD(Ast_ExprString__s, &O7_REF((*e2))->value_)->_.int_)))->_._._);
		}
		O7_ASSERT(o7_bl(O7_GUARD(Ast_ExprString__s, &O7_REF((*e2))->value_)->asChar));
	}
	return ret;
}

static o7_bool CompatibleAsIntAndByte(struct Ast_RType *t1, struct Ast_RType *t2) {
	return (o7_in(O7_REF(t1)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst)))) && (o7_in(O7_REF(t2)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst))));
}

static o7_bool CompatibleAsStrings(struct Ast_RType *t, struct Ast_RExpression *e) {
	return (o7_cmp(O7_REF(t)->_._.id, Ast_IdArray_cnst) == 0) && (o7_cmp(O7_REF(O7_REF(t)->_.type)->_._.id, Ast_IdChar_cnst) == 0) && (o7_is(e, &Ast_ExprString__s_tag));
}

static o7_bool IsChars(struct Ast_RType *t) {
	return (o7_cmp(O7_REF(t)->_._.id, Ast_IdArray_cnst) == 0) && (o7_cmp(O7_REF(O7_REF(t)->_.type)->_._.id, Ast_IdChar_cnst) == 0);
}

static o7_bool ExprRelationNew_CheckType(struct Ast_RType *t1, struct Ast_RType *t2, struct Ast_RExpression **e1, struct Ast_RExpression **e2, o7_int_t relation, o7_int_t *distance, o7_int_t *err) {
	o7_bool continue_;
	o7_int_t dist1, dist2;

	dist1 = 0;
	dist2 = 0;
	if ((t1 == NULL) || (t2 == NULL)) {
		continue_ = (0 > 1);
	} else if (relation == Scanner_In_cnst) {
		continue_ = (o7_cmp(O7_REF(t1)->_._.id, Ast_IdInteger_cnst) == 0) && (o7_in(O7_REF(t2)->_._.id, Ast_Sets_cnst));
		if (!continue_) {
			(*err) = o7_add(o7_add(o7_sub(Ast_ErrExprInWrongTypes_cnst, 3), (o7_int_t)(o7_cmp(O7_REF(t1)->_._.id, Ast_IdInteger_cnst) != 0)), o7_mul((o7_int_t)!(o7_in(O7_REF(t2)->_._.id, Ast_Sets_cnst)), 2));
		}
	} else if (!Ast_CompatibleTypes(&dist1, t1, t2, (0 > 1)) && !Ast_CompatibleTypes(&dist2, t2, t1, (0 > 1)) && !(IsChars(t1) && IsChars(t2)) && !CompatibleAsStrings(t1, (*e2)) && !CompatibleAsStrings(t2, (*e1)) && !CompatibleAsCharAndString(t1, &(*e2)) && !CompatibleAsCharAndString(t2, &(*e1)) && !CompatibleAsIntAndByte(t1, t2)) {
		(*err) = Ast_ErrRelationExprDifferenTypes_cnst;
		continue_ = (0 > 1);
	} else if ((o7_in(O7_REF(t1)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst) | (1u << Ast_IdReal_cnst) | (1u << Ast_IdChar_cnst)))) || (o7_cmp(O7_REF(t1)->_._.id, Ast_IdArray_cnst) == 0) && (o7_cmp(O7_REF(O7_REF(t1)->_.type)->_._.id, Ast_IdChar_cnst) == 0)) {
		continue_ = (0 < 1);
	} else if (o7_in(O7_REF(t1)->_._.id, ((1u << Ast_IdRecord_cnst) | (1u << Ast_IdArray_cnst)))) {
		continue_ = (0 > 1);
		(*err) = Ast_ErrRelIncompatibleType_cnst;
	} else {
		continue_ = (relation == Scanner_Equal_cnst) || (relation == Scanner_Inequal_cnst);
		if (!continue_) {
			(*err) = Ast_ErrRelIncompatibleType_cnst;
		}
	}
	(*distance) = o7_sub(dist1, dist2);
	return continue_;
}

static o7_bool ExprRelationNew_IsEqualChars(struct Ast_RExprInteger *v1, struct Ast_RExprInteger *v2) {
	O7_ASSERT(TypesLimits_InCharRange(o7_int(O7_REF(v1)->int_)));
	O7_ASSERT(TypesLimits_InCharRange(o7_int(O7_REF(v2)->int_)));
	return o7_cmp(O7_REF(v1)->int_, O7_REF(v2)->int_) == 0;
}

static o7_bool ExprRelationNew_IsEqualStrings(struct Ast_RExprInteger *v1, struct Ast_RExprInteger *v2) {
	o7_bool ret;

	ret = (o7_cmp(O7_REF(v1)->int_, O7_REF(v2)->int_) == 0);
	if (ret && (o7_cmp(O7_REF(v1)->int_,  - 1) == 0)) {
		ret = StringStore_Compare(&O7_GUARD(Ast_ExprString__s, &v1)->string, &O7_GUARD(Ast_ExprString__s, &v2)->string) == 0;
	}
	return ret;
}

extern o7_int_t Ast_ExprRelationNew(struct Ast_ExprRelation__s **e, struct Ast_RExpression *expr1, o7_int_t relation, struct Ast_RExpression *expr2) {
#	define AcceptableRelationLexems_cnst (O7_SET(Scanner_RelationFirst_cnst, Scanner_RelationLast_cnst) & ~(1u << Scanner_Is_cnst))

	o7_int_t err;
	o7_bool res;
	struct Ast_RExpression *v1, *v2;

	O7_ASSERT(o7_in(relation, AcceptableRelationLexems_cnst));

	O7_NEW(&(*e), Ast_ExprRelation__s);
	ExprInit(&(*e)->_, Ast_IdRelation_cnst, Ast_TypeGet(Ast_IdBoolean_cnst));
	O7_REF((*e))->exprs[0] = expr1;
	O7_REF((*e))->exprs[1] = expr2;
	O7_REF((*e))->relation = relation;
	PropTouch(&(*e)->_, Prop(expr1) | Prop(expr2));
	err = Ast_ErrNo_cnst;
	if ((expr1 != NULL) && (expr2 != NULL) && ExprRelationNew_CheckType(O7_REF(expr1)->type, O7_REF(expr2)->type, &O7_REF((*e))->exprs[0], &O7_REF((*e))->exprs[1], relation, &O7_REF((*e))->distance, &err) && (O7_REF(expr1)->value_ != NULL) && (O7_REF(expr2)->value_ != NULL) && (relation != Scanner_Is_cnst)) {
		v1 = (&(O7_REF(O7_REF((*e))->exprs[0])->value_)->_);
		v2 = (&(O7_REF(O7_REF((*e))->exprs[1])->value_)->_);
		switch (relation) {
		case 11:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) == 0;
				break;
			case 4:
				res = ExprRelationNew_IsEqualStrings(O7_GUARD(Ast_RExprInteger, &v1), O7_GUARD(Ast_RExprInteger, &v2));
				break;
			case 2:
				res = O7_GUARD(Ast_ExprBoolean__s, &v1)->bool_ == O7_GUARD(Ast_ExprBoolean__s, &v2)->bool_;
				break;
			case 5:
				res = (O7_GUARD(Ast_ExprReal__s, &v1)->real == O7_GUARD(Ast_ExprReal__s, &v2)->real) || (0 < 1);
				break;
			case 7:
			case 8:
				res = LongSet_Equal(O7_GUARD(Ast_ExprSetValue__s, &v1)->set, O7_GUARD(Ast_ExprSetValue__s, &v2)->set);
				break;
			case 9:
				O7_ASSERT(v1 == v2);
				res = (0 < 1);
				break;
			case 10:
				res = ExprRelationNew_IsEqualStrings(O7_GUARD(Ast_RExprInteger, &v1), O7_GUARD(Ast_RExprInteger, &v2));
				break;
			case 13:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 12:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) != 0;
				break;
			case 4:
				res = !ExprRelationNew_IsEqualChars(O7_GUARD(Ast_RExprInteger, &v1), O7_GUARD(Ast_RExprInteger, &v2));
				break;
			case 2:
				res = O7_GUARD(Ast_ExprBoolean__s, &v1)->bool_ != O7_GUARD(Ast_ExprBoolean__s, &v2)->bool_;
				break;
			case 5:
				res = O7_GUARD(Ast_ExprReal__s, &v1)->real != O7_GUARD(Ast_ExprReal__s, &v2)->real;
				break;
			case 7:
			case 8:
				res = !LongSet_Equal(O7_GUARD(Ast_ExprSetValue__s, &v1)->set, O7_GUARD(Ast_ExprSetValue__s, &v2)->set);
				break;
			case 9:
				O7_ASSERT(v1 == v2);
				res = (0 > 1);
				break;
			case 10:
				res = !ExprRelationNew_IsEqualStrings(O7_GUARD(Ast_RExprInteger, &v1), O7_GUARD(Ast_RExprInteger, &v2));
				break;
			case 13:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 13:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
			case 4:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) < 0;
				break;
			case 5:
				res = O7_GUARD(Ast_ExprReal__s, &v1)->real < O7_GUARD(Ast_ExprReal__s, &v2)->real;
				break;
			case 10:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 14:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
			case 4:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) <= 0;
				break;
			case 5:
				res = O7_GUARD(Ast_ExprReal__s, &v1)->real <= O7_GUARD(Ast_ExprReal__s, &v2)->real;
				break;
			case 10:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 15:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
			case 4:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) > 0;
				break;
			case 5:
				res = O7_GUARD(Ast_ExprReal__s, &v1)->real > O7_GUARD(Ast_ExprReal__s, &v2)->real;
				break;
			case 10:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 16:
			switch (O7_REF(O7_REF(expr1)->type)->_._.id) {
			case 0:
			case 4:
				res = o7_cmp(O7_GUARD(Ast_RExprInteger, &v1)->int_, O7_GUARD(Ast_RExprInteger, &v2)->int_) >= 0;
				break;
			case 5:
				res = O7_GUARD(Ast_ExprReal__s, &v1)->real >= O7_GUARD(Ast_ExprReal__s, &v2)->real;
				break;
			case 10:
				res = (0 > 1);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(expr1)->type)->_._.id);
				break;
			}
			break;
		case 17:
			res = LongSet_In(o7_int(O7_GUARD(Ast_RExprInteger, &v1)->int_), O7_GUARD(Ast_ExprSetValue__s, &v2)->set);
			break;
		default:
			o7_case_fail(relation);
			break;
		}
		if (o7_cmp(O7_REF(O7_REF(expr1)->type)->_._.id, Ast_IdReal_cnst) != 0) {
			O7_REF((*e))->_.value_ = (&(Ast_ExprBooleanGet(res))->_);
		}
	}
	return err;
#	undef AcceptableRelationLexems_cnst
}

static o7_int_t LexToSign(o7_int_t sign) {
	o7_int_t s;

	if (o7_in(sign, ((1u << Ast_NoSign_cnst) | (1u << Ast_Plus_cnst)))) {
		s =  + 1;
	} else {
		O7_ASSERT(sign == Ast_Minus_cnst);
		s =  - 1;
	}
	return s;
}

static void ExprSumCreate(struct Ast_RExprSum **e, o7_int_t add, struct Ast_RExpression *sum, struct Ast_RExpression *term) {
	struct Ast_RType *t;

	O7_NEW(&(*e), Ast_RExprSum);
	if ((sum != NULL) && (O7_REF(sum)->type != NULL) && (o7_in(O7_REF(O7_REF(sum)->type)->_._.id, ((1u << Ast_IdReal_cnst) | (1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst))))) {
		t = O7_REF(sum)->type;
	} else if (term != NULL) {
		t = O7_REF(term)->type;
	} else {
		t = NULL;
	}
	if ((t != NULL) && (o7_cmp(O7_REF(t)->_._.id, Ast_IdByte_cnst) == 0)) {
		t = Ast_TypeGet(Ast_IdInteger_cnst);
	}
	ExprInit(&(*e)->_, Ast_IdSum_cnst, t);
	O7_REF((*e))->next = NULL;
	O7_REF((*e))->add = add;
	O7_REF((*e))->term = term;
	PropTouch(&(*e)->_, Prop(sum) | Prop(term));
}

extern o7_int_t Ast_ExprSumNew(struct Ast_RExprSum **e, o7_int_t add, struct Ast_RExpression *term) {
	o7_int_t err;

	O7_ASSERT(o7_in(add, ((1u << Ast_NoSign_cnst) | (1u << Ast_Plus_cnst) | (1u << Ast_Minus_cnst))));

	ExprSumCreate(&(*e), add, NULL, term);
	err = Ast_ErrNo_cnst;
	if (O7_REF((*e))->_.type != NULL) {
		if (!(o7_in(O7_REF(O7_REF((*e))->_.type)->_._.id, (Ast_Numbers_cnst | Ast_Sets_cnst))) && (add != Ast_NoSign_cnst)) {
			if (o7_cmp(O7_REF(O7_REF((*e))->_.type)->_._.id, Ast_IdBoolean_cnst) != 0) {
				err = Ast_ErrNotNumberAndNotSetInAdd_cnst;
			} else {
				err = Ast_ErrSignForBool_cnst;
			}
		} else if (O7_REF(term)->value_ != NULL) {
			switch (O7_REF(O7_REF((*e))->_.type)->_._.id) {
			case 0:
				O7_REF((*e))->_.value_ = (&(Ast_ExprIntegerNew(o7_mul(O7_GUARD(Ast_RExprInteger, &O7_REF(term)->value_)->int_, LexToSign(add))))->_._);
				break;
			case 5:
				O7_REF((*e))->_.value_ = NULL;
				break;
			case 7:
			case 8:
				O7_REF((*e))->_.value_ = (&(Ast_ExprSetByValue(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(term)->value_)->set))->_);
				if (add == Ast_Minus_cnst) {
					LongSet_Not(O7_GUARD(Ast_ExprSetValue__s, &O7_REF((*e))->_.value_)->set);
				}
				break;
			case 2:
				O7_REF((*e))->_.value_ = (&(Ast_ExprBooleanGet(o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(term)->value_)->bool_)))->_);
				break;
			default:
				o7_case_fail(O7_REF(O7_REF((*e))->_.type)->_._.id);
				break;
			}
		}
	}
	return err;
}

static o7_bool ExprSumAdd_CheckType(struct Ast_RExpression *e1, struct Ast_RExpression *e2, o7_int_t add, o7_int_t *err) {
	o7_bool continue_;

	if ((O7_REF(e1)->type == NULL) || (O7_REF(e2)->type == NULL)) {
		continue_ = (0 > 1);
	} else if ((o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, O7_REF(O7_REF(e2)->type)->_._.id) != 0) && !CompatibleAsIntAndByte(O7_REF(e1)->type, O7_REF(e2)->type)) {
		(*err) = Ast_ErrAddExprDifferenTypes_cnst;
		continue_ = (0 > 1);
	} else if (add == Scanner_Or_cnst) {
		continue_ = o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, Ast_IdBoolean_cnst) == 0;
		if (!continue_) {
			(*err) = Ast_ErrNotBoolInLogicExpr_cnst;
		}
	} else {
		continue_ = o7_in(O7_REF(O7_REF(e1)->type)->_._.id, (Ast_Numbers_cnst | Ast_Sets_cnst));
		if (!continue_) {
			(*err) = Ast_ErrNotNumberAndNotSetInAdd_cnst;
		}
	}
	return continue_;
}

extern o7_int_t Ast_ExprSumAdd(struct Ast_RExpression *fullSum, struct Ast_RExprSum **lastAdder, o7_int_t add, struct Ast_RExpression *term) {
	struct Ast_RExprSum *e = NULL;
	o7_int_t err;

	O7_ASSERT(o7_in(add, ((1u << Ast_Plus_cnst) | (1u << Ast_Minus_cnst) | (1u << Ast_Or_cnst))));

	ExprSumCreate(&e, add, fullSum, term);
	err = Ast_ErrNo_cnst;
	if ((fullSum != NULL) && (term != NULL) && ExprSumAdd_CheckType(fullSum, term, add, &err) && (O7_REF(fullSum)->value_ != NULL) && (O7_REF(term)->value_ != NULL)) {
		if (add == Scanner_Or_cnst) {
			if (o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(term)->value_)->bool_)) {
				O7_REF(fullSum)->value_ = O7_REF(term)->value_;
			}
		} else {
			switch (O7_REF(O7_REF(term)->type)->_._.id) {
			case 0:
				if (CheckIntArithmetic_Add(&O7_GUARD(Ast_RExprInteger, &O7_REF(fullSum)->value_)->int_, o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(fullSum)->value_)->int_), o7_mul(O7_GUARD(Ast_RExprInteger, &O7_REF(term)->value_)->int_, LexToSign(add)))) {
				} else if (add == Ast_Minus_cnst) {
					err = Ast_ErrConstSubOverflow_cnst;
				} else {
					err = Ast_ErrConstAddOverflow_cnst;
				}
				break;
			case 5:
				break;
			case 7:
				if (add == Ast_Plus_cnst) {
					LongSet_Union(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(fullSum)->value_)->set, O7_GUARD(Ast_ExprSetValue__s, &O7_REF(term)->value_)->set);
				} else {
					O7_ASSERT(add == Ast_Minus_cnst);
					LongSet_Diff(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(fullSum)->value_)->set, O7_GUARD(Ast_ExprSetValue__s, &O7_REF(term)->value_)->set);
				}
				break;
			default:
				o7_case_fail(O7_REF(O7_REF(term)->type)->_._.id);
				break;
			}
		}
	} else if (fullSum != NULL) {
		O7_REF(fullSum)->value_ = NULL;
	}

	if ((*lastAdder) != NULL) {
		O7_REF((*lastAdder))->next = e;
	}
	(*lastAdder) = e;
	return err;
}

static o7_int_t MultCalc(struct Ast_RExpression *res, o7_int_t mult, struct Ast_RExpression *b);
static o7_bool MultCalc_CheckType(struct Ast_RExpression *e1, struct Ast_RExpression *e2, o7_int_t mult, o7_int_t *err) {
	o7_bool continue_;

	if ((O7_REF(e1)->type == NULL) || (O7_REF(e2)->type == NULL)) {
		continue_ = (0 > 1);
	} else if ((o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, O7_REF(O7_REF(e2)->type)->_._.id) != 0) && !CompatibleAsIntAndByte(O7_REF(e1)->type, O7_REF(e2)->type)) {
		continue_ = (0 > 1);
		if (mult == Scanner_And_cnst) {
			(*err) = Ast_ErrNotBoolInLogicExpr_cnst;
		} else if (mult == Scanner_Asterisk_cnst) {
			(*err) = Ast_ErrMultExprDifferentTypes_cnst;
		} else {
			(*err) = Ast_ErrDivExprDifferentTypes_cnst;
		}
	} else if (mult == Scanner_And_cnst) {
		continue_ = o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, Ast_IdBoolean_cnst) == 0;
		if (!continue_) {
			(*err) = Ast_ErrNotBoolInLogicExpr_cnst;
		}
	} else if (!(o7_in(O7_REF(O7_REF(e1)->type)->_._.id, (Ast_Numbers_cnst | Ast_Sets_cnst)))) {
		continue_ = (0 > 1);
		(*err) = Ast_ErrNotNumberAndNotSetInMult_cnst;
	} else if ((mult == Scanner_Div_cnst) || (mult == Scanner_Mod_cnst)) {
		continue_ = o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, Ast_IdInteger_cnst) == 0;
		if (!continue_) {
			(*err) = Ast_ErrNotIntInDivOrMod_cnst;
		}
	} else if ((mult == Scanner_Slash_cnst) && (o7_cmp(O7_REF(O7_REF(e1)->type)->_._.id, Ast_IdInteger_cnst) == 0)) {
		continue_ = (0 > 1);
		(*err) = Ast_ErrNotRealTypeForRealDiv_cnst;
	} else {
		continue_ = (0 < 1);
	}
	return continue_;
}

static void MultCalc_Int(struct Ast_RExpression *res, o7_int_t mult, struct Ast_RExpression *b, o7_int_t *err) {
	o7_int_t i = O7_INT_UNDEF, i1, i2;
	struct Ast_RExprInteger *val;

	i1 = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(res)->value_)->int_);
	i2 = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(b)->value_)->int_);
	if (mult == Scanner_Asterisk_cnst) {
		if (!CheckIntArithmetic_Mul(&i, i1, i2)) {
			(*err) = Ast_ErrConstMultOverflow_cnst;
		}
	} else if (i2 == 0) {
		(*err) = Ast_ErrComDivByZero_cnst;
	} else if (i2 < 0) {
		(*err) = Ast_ErrNegativeDivisor_cnst;
	} else if (mult == Scanner_Div_cnst) {
		i = o7_div(i1, i2);
	} else {
		O7_ASSERT(mult == Scanner_Mod_cnst);
		i = o7_mod(i1, i2);
	}
	if ((*err) == Ast_ErrNo_cnst) {
		val = Ast_ExprIntegerNew(o7_int(i));
		if ((o7_in(mult, ((1u << Scanner_Div_cnst) | (1u << Scanner_Mod_cnst)))) && (i1 < 0)) {
			O7_REF(val)->_._._.properties = (1u << Ast_ExprIntNegativeDividentTouch_cnst);
		} else {
			O7_REF(val)->_._._.properties = (1u << Ast_ExprIntNegativeDividentTouch_cnst) & (O7_REF(O7_REF(res)->value_)->_.properties | O7_REF(O7_REF(b)->value_)->_.properties);
		}
		O7_REF(res)->value_ = (&(val)->_._);
		O7_REF(res)->properties = O7_REF(res)->properties | O7_REF(val)->_._._.properties;
	} else {
		O7_REF(res)->value_ = NULL;
	}
}

static void MultCalc_Rl(struct Ast_RExpression *res, o7_int_t mult, struct Ast_RExpression *b) {
	double r, r1, r2;

	r1 = o7_dbl(O7_GUARD(Ast_ExprReal__s, &O7_REF(res)->value_)->real);
	r2 = o7_dbl(O7_GUARD(Ast_ExprReal__s, &O7_REF(b)->value_)->real);
	if (mult == Scanner_Asterisk_cnst) {
		r = o7_fmul(r1, r2);
	} else {
		r = o7_fdiv(r1, r2);
	}
	if (O7_REF(res)->value_ == NULL) {
		O7_REF(res)->value_ = (&(Ast_ExprRealNewByValue(r))->_._);
	} else {
		O7_GUARD(Ast_ExprReal__s, &O7_REF(res)->value_)->real = r;
	}
}

static void MultCalc_St(struct Ast_RExpression *res, o7_int_t mult, struct Ast_RExpression *b) {
	LongSet_Type s, s1, s2;
	memset(&s, 0, sizeof(s));
	memset(&s1, 0, sizeof(s1));
	memset(&s2, 0, sizeof(s2));

	memcpy(s1, O7_GUARD(Ast_ExprSetValue__s, &O7_REF(res)->value_)->set, sizeof(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(res)->value_)->set));
	memcpy(s2, O7_GUARD(Ast_ExprSetValue__s, &O7_REF(b)->value_)->set, sizeof(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(b)->value_)->set));
	if (mult == Scanner_Asterisk_cnst) {
		s[0] = s1[0] & s2[0];
		s[1] = s1[1] & s2[1];
	} else {
		s[0] = s1[0] ^ s2[0];
		s[1] = s1[1] ^ s2[1];
	}
	if (O7_REF(res)->value_ == NULL) {
		O7_REF(res)->value_ = (&(Ast_ExprSetByValue(s))->_);
	} else {
		memcpy(O7_GUARD(Ast_ExprSetValue__s, &O7_REF(res)->value_)->set, s, sizeof(s));
	}
}

static void MultCalc_CheckDivisor(o7_int_t *err, o7_int_t d) {
	if (d == 0) {
		(*err) = Ast_ErrComDivByZero_cnst;
	} else if (d < 0) {
		(*err) = Ast_ErrNegativeDivisor_cnst;
	}
}

static o7_int_t MultCalc(struct Ast_RExpression *res, o7_int_t mult, struct Ast_RExpression *b) {
	o7_int_t err;

	err = Ast_ErrNo_cnst;
	if (MultCalc_CheckType(res, b, mult, &err) && (O7_REF(res)->value_ != NULL) && (O7_REF(b)->value_ != NULL)) {
		switch (O7_REF(O7_REF(res)->type)->_._.id) {
		case 0:
			MultCalc_Int(res, mult, b, &err);
			break;
		case 5:
			if ((0 > 1)) {
				MultCalc_Rl(res, mult, b);
			}
			O7_REF(res)->value_ = NULL;
			break;
		case 2:
			if (o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(res)->value_)->bool_) && !o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(b)->value_)->bool_)) {
				O7_REF(res)->value_ = O7_REF(b)->value_;
			}
			break;
		case 7:
			MultCalc_St(res, mult, b);
			break;
		default:
			o7_case_fail(O7_REF(O7_REF(res)->type)->_._.id);
			break;
		}
	} else {
		O7_REF(res)->value_ = NULL;
		if ((o7_in((o7_sub(mult, Scanner_Div_cnst)), ((1u << 0) | (1u << 1)))) && (O7_REF(b)->value_ != NULL) && (o7_cmp(O7_REF(O7_REF(O7_REF(b)->value_)->_.type)->_._.id, Ast_IdInteger_cnst) == 0)) {
			MultCalc_CheckDivisor(&err, o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(b)->value_)->int_));
		}
	}
	return err;
}

static o7_int_t ExprTermGeneral(struct Ast_ExprTerm__s **e, struct Ast_RExpression *result, struct Ast_RFactor *factor, o7_int_t mult, struct Ast_RExpression *factorOrTerm) {
	struct Ast_RType *t;
	struct Ast_RFactor *val;
	o7_int_t err;

	O7_ASSERT((Scanner_MultFirst_cnst <= mult) && (mult <= Scanner_MultLast_cnst));

	O7_ASSERT((o7_cmp(O7_REF(factorOrTerm)->_.id, Ast_IdError_cnst) == 0) || (o7_is(factorOrTerm, &Ast_RFactor_tag)) || (o7_is(factorOrTerm, &Ast_ExprTerm__s_tag)));

	if (factor != NULL) {
		t = O7_REF(factor)->_.type;
		val = O7_REF(factor)->_.value_;
		if ((t != NULL) && (o7_cmp(O7_REF(t)->_._.id, Ast_IdByte_cnst) == 0)) {
			t = Ast_TypeGet(Ast_IdInteger_cnst);
		}
	} else {
		t = NULL;
		val = NULL;
	}

	O7_NEW(&(*e), Ast_ExprTerm__s);
	ExprInit(&(*e)->_, Ast_IdTerm_cnst, t);
	if (result == NULL) {
		result = (&((*e))->_);
		if (o7_cmp(O7_REF(O7_REF((*e))->_.type)->_._.id, Ast_IdReal_cnst) != 0) {
			O7_REF((*e))->_.value_ = val;
		}
	}
	PropTouch(&(*e)->_, Prop(&factor->_) | Prop(factorOrTerm));
	O7_REF((*e))->factor = factor;
	O7_REF((*e))->mult = mult;
	O7_REF((*e))->expr = factorOrTerm;
	O7_REF((*e))->factor = factor;

	if (o7_cmp(O7_REF(factorOrTerm)->_.id, Ast_IdError_cnst) != 0) {
		err = MultCalc(result, mult, factorOrTerm);
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_ExprTermNew(struct Ast_ExprTerm__s **e, struct Ast_RFactor *factor, o7_int_t mult, struct Ast_RExpression *factorOrTerm) {
	return ExprTermGeneral(&(*e), NULL, factor, mult, factorOrTerm);
}

extern o7_int_t Ast_ExprTermAdd(struct Ast_RExpression *fullTerm, struct Ast_ExprTerm__s **lastTerm, o7_int_t mult, struct Ast_RExpression *factorOrTerm) {
	struct Ast_ExprTerm__s *e = NULL;
	o7_int_t err;

	if ((*lastTerm) != NULL) {
		O7_ASSERT(O7_REF((*lastTerm))->expr != NULL);
		err = ExprTermGeneral(&e, fullTerm, O7_GUARD(Ast_RFactor, &O7_REF((*lastTerm))->expr), mult, factorOrTerm);
		O7_REF((*lastTerm))->expr = (&(e)->_);
		(*lastTerm) = e;
	} else {
		err = ExprTermGeneral(&(*lastTerm), fullTerm, NULL, mult, factorOrTerm);
	}
	return err;
}

static o7_int_t ExprCallCreate(struct Ast_ExprCall__s **e, struct Ast_Designator__s *des, o7_bool func) {
	o7_int_t err;
	struct Ast_RType *t;
	struct Ast_RProcType *pt;

	t = NULL;
	err = Ast_ErrNo_cnst;
	if (des != NULL) {
		if (o7_cmp(O7_REF(O7_REF(des)->decl)->_.id, Ast_IdError_cnst) == 0) {
			pt = Ast_ProcTypeNew((0 > 1));
			O7_REF(O7_REF(des)->decl)->type = (&(pt)->_._);
			O7_REF(des)->_._.type = (&(pt)->_._);
		} else if (O7_REF(des)->_._.type != NULL) {
			if (o7_is(O7_REF(des)->_._.type, &Ast_RProcType_tag)) {
				t = O7_REF(O7_REF(des)->_._.type)->_.type;
				if ((t != NULL) != func) {
					err = o7_add(Ast_ErrCallIgnoredReturn_cnst, (o7_int_t)o7_bl(func));
				}
			} else {
				err = Ast_ErrCallNotProc_cnst;
			}
		}
	}
	if ((t == NULL) && func) {
		t = Ast_TypeErrorNew();
	}
	O7_NEW(&(*e), Ast_ExprCall__s);
	ExprInit(&(*e)->_._, Ast_IdCall_cnst, t);
	O7_REF((*e))->designator = des;
	O7_REF((*e))->params = NULL;
	return err;
}

extern o7_int_t Ast_ExprCallNew(struct Ast_ExprCall__s **e, struct Ast_Designator__s *des) {
	return ExprCallCreate(&(*e), des, (0 < 1));
}

extern o7_bool Ast_IsChangeable(struct Ast_Designator__s *des) {
	struct Ast_RVar *v;
	struct Ast_RSelector *sel;
	o7_int_t tid;
	o7_bool able;

	v = O7_GUARD(Ast_RVar, &O7_REF(des)->decl);
	if (Ast_IsGlobal(&v->_)) {
		able = !o7_bl(O7_REF(O7_REF(O7_REF(v)->_.module_)->m)->fixed);
	} else {
		able = !(o7_is(v, &Ast_RFormalParam_tag)) || (!!( (1u << Ast_ParamOut_cnst) & O7_GUARD(Ast_RFormalParam, &v)->access)) || !(o7_in(O7_REF(O7_REF(v)->_.type)->_._.id, ((1u << Ast_IdArray_cnst) | (1u << Ast_IdRecord_cnst))));
	}
	if (!able) {
		tid = o7_int(O7_REF(O7_REF(O7_REF(des)->decl)->type)->_._.id);
		sel = O7_REF(des)->sel;
		while ((sel != NULL) && (tid != Ast_IdPointer_cnst)) {
			tid = o7_int(O7_REF(O7_REF(sel)->type)->_._.id);
			sel = O7_REF(sel)->next;
		}
		able = sel != NULL;
	}
	return able;
}

extern o7_bool Ast_IsVar(struct Ast_RExpression *e) {
	return (o7_is(e, &Ast_Designator__s_tag)) && (o7_is(O7_GUARD(Ast_Designator__s, &e)->decl, &Ast_RVar_tag));
}

extern o7_bool Ast_IsFormalParam(struct Ast_RExpression *e) {
	return (o7_is(e, &Ast_Designator__s_tag)) && (O7_GUARD(Ast_Designator__s, &e)->sel == NULL) && (o7_is(O7_GUARD(Ast_Designator__s, &e)->decl, &Ast_RFormalParam_tag));
}

extern o7_int_t Ast_ProcedureAdd(struct Ast_RDeclarations *ds, struct Ast_RProcedure **p, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t begin, o7_int_t end) {
	o7_int_t err;

	err = CheckNameDuplicate(ds, buf_len0, buf, begin, end);
	O7_NEW(&(*p), Ast_RProcedure);
	NodeInit(&(*O7_REF((*p)))._._._._, Ast_IdProc_cnst);
	DeclarationsConnect(&(*p)->_._, ds, buf_len0, buf, begin, end);
	O7_REF((*p))->_.header = Ast_ProcTypeNew((0 > 1));
	O7_REF((*p))->_.return_ = NULL;
	O7_REF((*p))->usedAsValue = (0 > 1);
	if (O7_REF(ds)->_.up == NULL) {
		O7_REF((*p))->deep = 0;
	} else {
		O7_REF((*p))->deep = o7_add(O7_GUARD(Ast_RProcedure, &ds)->deep, 1);
		if ((err == Ast_ErrNo_cnst) && (o7_cmp(TranslatorLimits_DeepProcedures_cnst, O7_REF((*p))->deep) <= 0)) {
			err = Ast_ErrProcNestedTooDeep_cnst;
		}
	}
	if (O7_REF(ds)->procedures == NULL) {
		O7_REF(ds)->procedures = (*p);
	}
	return err;
}

extern o7_int_t Ast_ProcedureSetReturn(struct Ast_RProcedure *p, struct Ast_RExpression *e) {
	o7_int_t err, distance = O7_INT_UNDEF;

	O7_ASSERT(O7_REF(p)->_.return_ == NULL);
	err = Ast_ErrNo_cnst;
	if (O7_REF(O7_REF(p)->_.header)->_._._.type == NULL) {
		err = Ast_ErrProcHasNoReturn_cnst;
	} else if (e != NULL) {
		O7_REF(p)->_.return_ = e;
		if (!Ast_CompatibleTypes(&distance, O7_REF(O7_REF(p)->_.header)->_._._.type, O7_REF(e)->type, (0 > 1)) && !CompatibleAsCharAndString(O7_REF(O7_REF(p)->_.header)->_._._.type, &O7_REF(p)->_.return_)) {
			if (!CompatibleAsIntAndByte(O7_REF(O7_REF(p)->_.header)->_._._.type, O7_REF(O7_REF(p)->_.return_)->type)) {
				err = Ast_ErrReturnIncompatibleType_cnst;
			} else if ((o7_cmp(O7_REF(O7_REF(O7_REF(p)->_.return_)->type)->_._.id, Ast_IdByte_cnst) == 0) && (O7_REF(e)->value_ != NULL) && !TypesLimits_InByteRange(o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(e)->value_)->int_))) {
				err = Ast_ErrValueOutOfRangeOfByte_cnst;
			}
		}
		if (err == Ast_ErrNo_cnst) {
			err = CheckUnusedDeclarations(&p->_._);
		}
	}
	return err;
}

extern o7_int_t Ast_ProcedureEnd(struct Ast_RProcedure *p) {
	o7_int_t err;

	if ((O7_REF(O7_REF(p)->_.header)->_._._.type != NULL) && (O7_REF(p)->_.return_ == NULL)) {
		err = Ast_ErrExpectReturn_cnst;
	} else {
		err = CheckUnusedDeclarations(&p->_._);
	}
	return err;
}

static o7_bool CallParamNew_TypeVariation(struct Ast_ExprCall__s *call, struct Ast_RType *tp, struct Ast_RFormalParam *fp) {
	o7_bool comp;
	o7_int_t id;

	comp = o7_is(O7_REF(O7_REF(call)->designator)->decl, &Ast_PredefinedProcedure__s_tag);
	if (comp) {
		id = o7_int(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id);
		if (id == OberonSpecIdent_New_cnst) {
			comp = o7_cmp(O7_REF(tp)->_._.id, Ast_IdPointer_cnst) == 0;
		} else if (id == OberonSpecIdent_Abs_cnst) {
			comp = o7_in(O7_REF(tp)->_._.id, Ast_Numbers_cnst);
			O7_REF(call)->_._.type = tp;
		} else if (id == OberonSpecIdent_Len_cnst) {
			comp = o7_cmp(O7_REF(tp)->_._.id, Ast_IdArray_cnst) == 0;
		} else {
			comp = (id == OberonSpecIdent_Ord_cnst) && (o7_in(O7_REF(tp)->_._.id, (Ast_Sets_cnst | ((1u << Ast_IdChar_cnst) | (1u << Ast_IdBoolean_cnst)))));
		}
	}
	return comp;
}

static void CallParamNew_ParamsVariation(struct Ast_ExprCall__s *call, struct Ast_RExpression *e, o7_int_t *err) {
	o7_int_t id;

	id = o7_int(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id);
	if (id != Ast_IdError_cnst) {
		if ((id != OberonSpecIdent_Inc_cnst) && (id != OberonSpecIdent_Dec_cnst) || (O7_REF(O7_REF(call)->params)->next != NULL)) {
			(*err) = Ast_ErrCallExcessParam_cnst;
		} else if (o7_cmp(O7_REF(O7_REF(e)->type)->_._.id, Ast_IdInteger_cnst) != 0) {
			(*err) = Ast_ErrCallIncompatibleParamType_cnst;
		}
	}
}

static void CallParamNew_CheckNeedTag(struct Ast_RFormalParam *fp, struct Ast_RExpression *e) {
	if ((o7_cmp(O7_REF(O7_REF(fp)->_._.type)->_._.id, Ast_IdRecord_cnst) == 0) && Ast_IsFormalParam(e)) {
		ExchangeParamsNeedTag(fp, O7_GUARD(Ast_RFormalParam, &O7_GUARD(Ast_Designator__s, &e)->decl));
	}
}

extern o7_int_t Ast_CallParamNew(struct Ast_ExprCall__s *call, struct Ast_RParameter **lastParam, struct Ast_RExpression *e, struct Ast_RFormalParam **currentFormalParam) {
	o7_int_t err, distance = O7_INT_UNDEF;
	struct Ast_RFormalParam *fp;

	err = Ast_ErrNo_cnst;
	fp = (*currentFormalParam);
	if (fp != NULL) {
		if (!Ast_CompatibleTypes(&distance, O7_REF(fp)->_._.type, O7_REF(e)->type, (0 < 1)) && !CompatibleAsCharAndString(O7_REF((*currentFormalParam))->_._.type, &e) && ((!!( (1u << Ast_ParamOut_cnst) & O7_REF(fp)->access)) || !CompatibleAsIntAndByte(O7_REF(fp)->_._.type, O7_REF(e)->type)) && !CallParamNew_TypeVariation(call, O7_REF(e)->type, fp)) {
			err = Ast_ErrCallIncompatibleParamType_cnst;
		} else if (!!( (1u << Ast_ParamOut_cnst) & O7_REF(fp)->access)) {
			if (!(Ast_IsVar(e) && Ast_IsChangeable(O7_GUARD(Ast_Designator__s, &e)))) {
				err = Ast_ErrCallExpectVarParam_cnst;
			} else if ((O7_REF(e)->type != NULL) && (o7_cmp(O7_REF(O7_REF(e)->type)->_._.id, Ast_IdPointer_cnst) == 0) && (O7_REF(e)->type != O7_REF(fp)->_._.type) && (O7_REF(fp)->_._.type != NULL) && (O7_REF(O7_REF(fp)->_._.type)->_.type != NULL) && (O7_REF(O7_REF(e)->type)->_.type != NULL)) {
				err = Ast_ErrCallVarPointerTypeNotSame_cnst;
			}
		} else if ((o7_cmp(O7_REF(O7_REF(fp)->_._.type)->_._.id, Ast_IdByte_cnst) == 0) && (o7_cmp(O7_REF(O7_REF(e)->type)->_._.id, Ast_IdInteger_cnst) == 0) && (O7_REF(e)->value_ != NULL) && !TypesLimits_InByteRange(o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(e)->value_)->int_))) {
			err = Ast_ErrValueOutOfRangeOfByte_cnst;
		}
		if ((O7_REF(fp)->_._.next != NULL) && (o7_is(O7_REF(fp)->_._.next, &Ast_RFormalParam_tag))) {
			(*currentFormalParam) = O7_GUARD(Ast_RFormalParam, &O7_REF(fp)->_._.next);
		} else {
			(*currentFormalParam) = NULL;
		}
		if ((err == Ast_ErrNo_cnst) && (o7_cmp(O7_REF(O7_REF(fp)->_._.type)->_._.id, Ast_IdProcType_cnst) == 0) && (e != NULL) && (o7_is(e, &Ast_Designator__s_tag)) && (o7_cmp(O7_REF(O7_GUARD(Ast_Designator__s, &e)->decl)->_.id, Ast_IdProc_cnst) == 0)) {
			O7_GUARD(Ast_RProcedure, &O7_GUARD(Ast_Designator__s, &e)->decl)->usedAsValue = (0 < 1);
		}
	} else {
		distance = 0;
		CallParamNew_ParamsVariation(call, e, &err);
	}

	if ((*lastParam) == NULL) {
		O7_NEW(&(*lastParam), Ast_RParameter);
	} else {
		O7_ASSERT(O7_REF((*lastParam))->next == NULL);
		O7_NEW(&O7_REF((*lastParam))->next, Ast_RParameter);
		(*lastParam) = O7_REF((*lastParam))->next;
	}
	if ((err == Ast_ErrNo_cnst) && (fp != NULL)) {
		CallParamNew_CheckNeedTag(fp, e);
	}
	NodeInit(&(*O7_REF((*lastParam)))._, Ast_NoId_cnst);
	O7_REF((*lastParam))->expr = e;
	O7_REF((*lastParam))->distance = o7_int(distance);
	O7_REF((*lastParam))->next = NULL;
	return err;
}

extern void Ast_CallParamInsert(struct Ast_RParameter *par, struct Ast_RFormalParam **fp, struct Ast_RExpression *expr, struct Ast_RParameter **np) {
	O7_NEW(&(*np), Ast_RParameter);
	NodeInit(&(*O7_REF((*np)))._, Ast_NoId_cnst);
	O7_REF((*np))->distance = 0;
	O7_REF((*np))->expr = expr;
	O7_REF((*np))->next = O7_REF(par)->next;
	O7_REF(par)->next = (*np);
}

static void CallParamsEnd_CalcPredefined(struct Ast_ExprCall__s *call, struct Ast_RFactor *v, o7_int_t *err) {
	switch (O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id) {
	case 200:
		if (o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdReal_cnst) == 0) {
			O7_REF(call)->_._.value_ = NULL;
		} else {
			O7_ASSERT(o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdInteger_cnst) == 0);
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(abs(O7_GUARD(Ast_RExprInteger, &v)->int_)))->_._);
		}
		break;
	case 219:
		O7_REF(call)->_._.value_ = (&(Ast_ExprBooleanGet((O7_GUARD(Ast_RExprInteger, &v)->int_ % 2 == 1)))->_);
		break;
	case 217:
		if (O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_ != NULL) {
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew((o7_int_t)((o7_uint_t)O7_GUARD(Ast_RExprInteger, &v)->int_ << O7_GUARD(Ast_RExprInteger, &O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_)->int_)))->_._);
		}
		break;
	case 201:
		if (O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_ != NULL) {
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(o7_asr(O7_GUARD(Ast_RExprInteger, &v)->int_, O7_GUARD(Ast_RExprInteger, &O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_)->int_)))->_._);
		}
		break;
	case 224:
		if (O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_ != NULL) {
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(o7_ror(O7_GUARD(Ast_RExprInteger, &v)->int_, O7_GUARD(Ast_RExprInteger, &O7_REF(O7_REF(O7_REF(O7_REF(call)->params)->next)->expr)->value_)->int_)))->_._);
		}
		break;
	case 209:
		if ((0 > 1)) {
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(o7_floor(O7_GUARD(Ast_ExprReal__s, &v)->real)))->_._);
		}
		break;
	case 210:
		O7_REF(call)->_._.value_ = (&(Ast_ExprRealNewByValue(o7_flt(O7_GUARD(Ast_RExprInteger, &v)->int_)))->_._);
		break;
	case 220:
		if (o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdChar_cnst) == 0) {
			O7_REF(call)->_._.value_ = v;
		} else if (o7_is(v, &Ast_ExprString__s_tag)) {
			if (o7_cmp(O7_GUARD(Ast_ExprString__s, &v)->_.int_,  - 1) > 0) {
				O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(o7_int(O7_GUARD(Ast_ExprString__s, &v)->_.int_)))->_._);
			}
		} else if (o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdBoolean_cnst) == 0) {
			O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew((o7_int_t)o7_bl(O7_GUARD(Ast_ExprBoolean__s, &v)->bool_)))->_._);
		} else if (o7_in(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_Sets_cnst)) {
			if (LongSet_ConvertableToInt(O7_GUARD(Ast_ExprSetValue__s, &v)->set)) {
				O7_REF(call)->_._.value_ = (&(Ast_ExprIntegerNew(LongSet_Ord(O7_GUARD(Ast_ExprSetValue__s, &v)->set)))->_._);
			} else {
				(*err) = Ast_ErrSetElemMaxNotConvertToInt_cnst;
			}
		} else if (o7_cmp(O7_REF(O7_REF(v)->_.type)->_._.id, Ast_IdError_cnst) != 0) {
			Log_Str(40, (o7_char *)"Неправильный id типа = ");
			Log_Int(o7_int(O7_REF(O7_REF(v)->_.type)->_._.id));
			Log_Ln();
			Log_Int(o7_int(O7_REF(v)->_._.id));
			Log_Ln();
		}
		break;
	case 206:
		if (!TypesLimits_InCharRange(o7_int(O7_GUARD(Ast_RExprInteger, &v)->int_))) {
			(*err) = Ast_ErrValueOutOfRangeOfChar_cnst;
		}
		O7_REF(call)->_._.value_ = v;
		break;
	default:
		o7_case_fail(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id);
		break;
	}
}

extern o7_int_t Ast_CallParamsEnd(struct Ast_ExprCall__s *call, struct Ast_RFormalParam *currentFormalParam, struct Ast_RDeclarations *ds) {
	o7_int_t err;

	err = Ast_ErrNo_cnst;
	if (currentFormalParam != NULL) {
		err = Ast_ErrCallParamsNotEnough_cnst;
	} else if (o7_cmp(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id, OberonSpecIdent_Len_cnst) == 0) {
		if ((o7_is(O7_REF(O7_REF(O7_REF(call)->params)->expr)->type, &Ast_RArray_tag)) && (O7_GUARD(Ast_RArray, &O7_REF(O7_REF(O7_REF(call)->params)->expr)->type)->count != NULL)) {
			O7_REF(call)->_._.value_ = O7_REF(O7_GUARD(Ast_RArray, &O7_REF(O7_REF(O7_REF(call)->params)->expr)->type)->count)->value_;
		}
	} else if (o7_cmp(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->_.id, OberonSpecIdent_Assert_cnst) == 0) {
		if ((O7_REF(O7_REF(O7_REF(call)->params)->expr)->value_ != NULL) && (o7_is(O7_REF(O7_REF(O7_REF(call)->params)->expr)->value_, &Ast_ExprBoolean__s_tag)) && !o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(O7_REF(O7_REF(call)->params)->expr)->value_)->bool_)) {
			if (O7_REF(O7_REF(call)->params)->expr == &Ast_ExprBooleanGet((0 > 1))->_._) {
				Ast_TurnFail(ds);
			} else {
				err = Ast_ErrAssertConstFalse_cnst;
			}
		}
	} else if ((o7_is(O7_REF(O7_REF(call)->designator)->decl, &Ast_PredefinedProcedure__s_tag)) && (O7_REF(O7_REF(O7_REF(O7_REF(call)->designator)->decl)->type)->_.type != NULL) && (O7_REF(O7_REF(O7_REF(call)->params)->expr)->value_ != NULL)) {
		CallParamsEnd_CalcPredefined(call, O7_REF(O7_REF(O7_REF(call)->params)->expr)->value_, &err);
	}
	return err;
}

static void StatInit(struct Ast_RStatement *s, struct Ast_RExpression *e) {
	NodeInit(&(*O7_REF(s))._, Ast_NoId_cnst);
	O7_REF(s)->expr = e;
	O7_REF(s)->next = NULL;
}

extern o7_int_t Ast_CallNew(struct Ast_Call__s **c, struct Ast_Designator__s *des) {
	o7_int_t err;
	struct Ast_ExprCall__s *e = NULL;

	err = ExprCallCreate(&e, des, (0 > 1));
	if (err == Ast_ErrNo_cnst) {
		err = Ast_DesignatorUsed(des, (0 > 1), (0 > 1));
	}
	O7_NEW(&(*c), Ast_Call__s);
	StatInit(&(*c)->_, &e->_._);
	return err;
}

extern o7_int_t Ast_CallBeginGet(struct Ast_Call__s **call, struct Ast_RModule *m, o7_bool acceptParams, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	struct Ast_RDeclaration *d;
	struct Ast_Designator__s *des = NULL;
	o7_int_t err;

	d = SearchName(O7_REF(m)->_.start, name_len0, name, begin, end);
	if (begin == end) {
		O7_ASSERT(d == NULL);
		err = Ast_ErrExpectProcNameWithoutParams_cnst;
	} else if (d == NULL) {
		err = Ast_ErrDeclarationNotFound_cnst;
	} else if (!o7_bl(O7_REF(d)->mark)) {
		err = Ast_ErrDeclarationIsPrivate_cnst;
	} else if (!(o7_is(d, &Ast_RProcedure_tag))) {
		err = Ast_ErrDeclarationNotProc_cnst;
	} else if (O7_REF(O7_GUARD(Ast_RProcedure, &d)->_.header)->_._._.type != NULL) {
		err = Ast_ErrProcNotCommandHaveReturn_cnst;
	} else if (O7_REF(O7_GUARD(Ast_RProcedure, &d)->_.header)->params != NULL) {
		err = Ast_ErrProcNotCommandHaveParams_cnst;
	} else {
		err = Ast_DesignatorNew(&des, d);
		if (err == Ast_ErrNo_cnst) {
			err = Ast_CallNew(&(*call), des);
		}
	}
	return err;
}

extern o7_int_t Ast_CommandGet(struct Ast_Call__s **call, struct Ast_RModule *m, o7_int_t name_len0, o7_char name[/*len0*/], o7_int_t begin, o7_int_t end) {
	return Ast_CallBeginGet(&(*call), m, (0 > 1), name_len0, name, begin, end);
}

extern o7_int_t Ast_IfNew(struct Ast_If__s **if_, struct Ast_RExpression *expr, struct Ast_RStatement *stats) {
	o7_int_t err;

	O7_NEW(&(*if_), Ast_If__s);
	StatInit(&(*if_)->_._, expr);
	O7_REF((*if_))->_.stats = stats;
	O7_REF((*if_))->_.elsif = NULL;
	if ((expr != NULL) && (o7_cmp(O7_REF(O7_REF(expr)->type)->_._.id, Ast_IdBoolean_cnst) != 0)) {
		err = Ast_ErrNotBoolInIfCondition_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

static void CheckCondition(o7_int_t *err, struct Ast_RExpression *expr, o7_int_t adder) {
	(*err) = Ast_ErrNo_cnst;
	if (expr != NULL) {
		if (o7_cmp(O7_REF(O7_REF(expr)->type)->_._.id, Ast_IdBoolean_cnst) != 0) {
			(*err) = o7_add(Ast_ErrNotBoolInWhileCondition_cnst, adder);
		} else if (O7_REF(expr)->value_ != NULL) {
			(*err) = o7_sub(o7_add(Ast_ErrWhileConditionAlwaysFalse_cnst, adder), (o7_int_t)o7_bl(O7_GUARD(Ast_ExprBoolean__s, &O7_REF(expr)->value_)->bool_));
		}
	}
}

extern o7_int_t Ast_WhileNew(struct Ast_While__s **w, struct Ast_RExpression *expr, struct Ast_RStatement *stats) {
	o7_int_t err = O7_INT_UNDEF;

	O7_NEW(&(*w), Ast_While__s);
	StatInit(&(*w)->_._, expr);
	O7_REF((*w))->_.stats = stats;
	O7_REF((*w))->_.elsif = NULL;
	CheckCondition(&err, expr, 0);
	return o7_int(err);
}

extern o7_int_t Ast_RepeatNew(struct Ast_Repeat__s **r, struct Ast_RStatement *stats) {
	O7_NEW(&(*r), Ast_Repeat__s);
	StatInit(&(*r)->_, NULL);
	O7_REF((*r))->stats = stats;
	return Ast_ErrNo_cnst;
}

extern o7_int_t Ast_RepeatSetUntil(struct Ast_Repeat__s *r, struct Ast_RExpression *e) {
	o7_int_t err = O7_INT_UNDEF;

	O7_ASSERT(O7_REF(r)->_.expr == NULL);
	O7_REF(r)->_.expr = e;
	CheckCondition(&err, e, Ast_ErrNotBoolInUntil_cnst - Ast_ErrNotBoolInWhileCondition_cnst);
	return o7_int(err);
}

extern o7_int_t Ast_ForSetBy(struct Ast_For__s *for_, struct Ast_RExpression *by) {
	o7_int_t err, init, to;

	err = Ast_ErrNo_cnst;
	if ((by != NULL) && (O7_REF(by)->value_ != NULL) && (o7_cmp(O7_REF(O7_REF(by)->type)->_._.id, Ast_IdInteger_cnst) == 0)) {
		O7_REF(for_)->by = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(by)->value_)->int_);
		if (o7_cmp(O7_REF(for_)->by, 0) == 0) {
			err = Ast_ErrForByZero_cnst;
		}
	} else {
		O7_REF(for_)->by = 1;
		if (by != NULL) {
			err = Ast_ErrExpectConstIntExpr_cnst;
		}
	}
	if ((err == Ast_ErrNo_cnst) && (O7_REF(for_)->_.expr != NULL) && (O7_REF(O7_REF(for_)->_.expr)->value_ != NULL) && (o7_is(O7_REF(O7_REF(for_)->_.expr)->value_, &Ast_RExprInteger_tag)) && (O7_REF(for_)->to != NULL) && (O7_REF(O7_REF(for_)->to)->value_ != NULL) && (o7_is(O7_REF(O7_REF(for_)->to)->value_, &Ast_RExprInteger_tag))) {
		init = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(O7_REF(for_)->_.expr)->value_)->int_);
		to = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(O7_REF(for_)->to)->value_)->int_);
		if ((init < to) && (o7_cmp(O7_REF(for_)->by, 0) < 0)) {
			err = Ast_ErrByShouldBePositive_cnst;
		} else if ((init > to) && (o7_cmp(O7_REF(for_)->by, 0) > 0)) {
			err = Ast_ErrByShouldBeNegative_cnst;
		} else if ((o7_cmp(O7_REF(for_)->by, 0) > 0) && (o7_sub(TypesLimits_IntegerMax_cnst, O7_REF(for_)->by) < to) || (o7_cmp(O7_REF(for_)->by, 0) < 0) && (o7_sub(TypesLimits_IntegerMin_cnst, O7_REF(for_)->by) > to)) {
			err = Ast_ErrForPossibleOverflow_cnst;
		}
	}
	return err;
}

extern o7_int_t Ast_ForSetTo(struct Ast_For__s *for_, struct Ast_RExpression *to) {
	o7_int_t err;

	if ((to != NULL) && (o7_cmp(O7_REF(O7_REF(to)->type)->_._.id, Ast_IdInteger_cnst) != 0)) {
		err = Ast_ErrExpectIntExpr_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	O7_REF(for_)->to = to;
	return err;
}

extern o7_int_t Ast_ForNew(struct Ast_For__s **f, struct Ast_RVar *var_, struct Ast_RExpression *init, struct Ast_RExpression *to, o7_int_t by, struct Ast_RStatement *stats) {
	o7_int_t err;

	O7_NEW(&(*f), Ast_For__s);
	StatInit(&(*f)->_, init);
	O7_REF((*f))->var_ = var_;

	O7_REF(O7_REF(var_)->state)->inited = ((1u << Ast_InitedValue_cnst) | (1u << Ast_Used_cnst));

	O7_REF(var_)->_.used = (0 < 1);
	err = Ast_ForSetTo((*f), to);
	O7_REF((*f))->by = by;
	O7_REF((*f))->stats = stats;
	return err;
}

extern o7_int_t Ast_CaseNew(struct Ast_Case__s **case_, struct Ast_RExpression *expr) {
	o7_int_t err;

	O7_NEW(&(*case_), Ast_Case__s);
	StatInit(&(*case_)->_, expr);
	O7_REF((*case_))->elements = NULL;
	O7_REF((*case_))->else_ = NULL;
	if ((O7_REF(expr)->type != NULL) && !(o7_in(O7_REF(O7_REF(expr)->type)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdChar_cnst))))) {
		err = Ast_ErrCaseExprNotIntOrChar_cnst;
	} else {
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_CaseElseSet(struct Ast_Case__s *case_, struct Ast_RStatement *else_) {
	o7_int_t err;

	if (O7_REF(case_)->else_ != NULL) {
		err = Ast_ErrCaseElseAlreadyExist_cnst;
	} else {
		O7_REF(case_)->else_ = else_;
		err = Ast_ErrNo_cnst;
	}
	return err;
}

extern o7_int_t Ast_CaseRangeSearch(struct Ast_Case__s *case_, o7_int_t int_) {
	struct Ast_RCaseElement *e;

	O7_ASSERT((0 > 1));
	e = O7_REF(case_)->elements;
	if (e != NULL) {
		while (O7_REF(e)->next != NULL) {
			e = O7_REF(e)->next;
		}
		if (O7_REF(e)->stats != NULL) {
			e = NULL;
		}
	}
	return 0;
}

extern o7_int_t Ast_CaseLabelNew(struct Ast_RCaseLabel **label, o7_int_t id, o7_int_t value_) {
	O7_ASSERT(o7_in(id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdChar_cnst))));

	O7_NEW(&(*label), Ast_RCaseLabel);
	NodeInit(&(*O7_REF((*label)))._, id);
	O7_REF((*label))->qual = NULL;
	O7_REF((*label))->value_ = value_;
	O7_REF((*label))->right = NULL;
	O7_REF((*label))->next = NULL;
	return Ast_ErrNo_cnst;
}

extern o7_int_t Ast_CaseLabelQualNew(struct Ast_RCaseLabel **label, struct Ast_RDeclaration *decl) {
	o7_int_t err, i;

	(*label) = NULL;
	O7_REF(decl)->used = (0 < 1);
	if (o7_cmp(O7_REF(decl)->_.id, Ast_IdError_cnst) == 0) {
		err = Ast_ErrNo_cnst;
	} else if (!(o7_is(decl, &Ast_Const__s_tag))) {
		err = Ast_ErrCaseLabelNotConst_cnst;
	} else if (!(o7_in(O7_REF(O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->type)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdChar_cnst)))) && !((o7_is(O7_GUARD(Ast_Const__s, &decl)->expr, &Ast_ExprString__s_tag)) && (o7_cmp(O7_GUARD(Ast_ExprString__s, &O7_GUARD(Ast_Const__s, &decl)->expr)->_.int_,  - 1) > 0))) {
		err = Ast_ErrCaseLabelNotIntOrChar_cnst;
	} else if (o7_cmp(O7_REF(O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->type)->_._.id, Ast_IdInteger_cnst) == 0) {
		err = Ast_CaseLabelNew(&(*label), Ast_IdInteger_cnst, o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->value_)->int_));
	} else {
		i = o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->value_)->int_);
		if (i < 0) {
			O7_ASSERT((0 > 1));
			i = (o7_int_t)O7_REF(O7_GUARD(Ast_ExprString__s, &O7_REF(O7_GUARD(Ast_Const__s, &decl)->expr)->value_)->string.block)->s[0];
		}
		err = Ast_CaseLabelNew(&(*label), Ast_IdChar_cnst, i);
	}
	if ((*label) == NULL) {
		err = o7_add(err, o7_mul(Ast_CaseLabelNew(&(*label), Ast_IdInteger_cnst, 0), 0));
	}
	return err;
}

extern o7_int_t Ast_CaseRangeNew(struct Ast_RCaseLabel *left, struct Ast_RCaseLabel *right) {
	o7_int_t err;

	O7_ASSERT((O7_REF(left)->right == NULL) && (O7_REF(left)->next == NULL));
	O7_ASSERT((right == NULL) || (O7_REF(right)->right == NULL) && (O7_REF(right)->next == NULL));

	O7_REF(left)->right = right;

	err = Ast_ErrNo_cnst;
	if (right == NULL) {
	} else if (o7_cmp(O7_REF(left)->_.id, O7_REF(right)->_.id) != 0) {
		err = Ast_ErrCaseRangeLabelsTypeMismatch_cnst;
	} else if (o7_cmp(O7_REF(left)->value_, O7_REF(right)->value_) >= 0) {
		err = Ast_ErrCaseLabelLeftNotLessRight_cnst;
	}
	return err;
}

static o7_bool IsRangesCross(struct Ast_RCaseLabel *l1, struct Ast_RCaseLabel *l2) {
	o7_bool cross;

	if (o7_cmp(O7_REF(l1)->value_, O7_REF(l2)->value_) < 0) {
		cross = (O7_REF(l1)->right != NULL) && (o7_cmp(O7_REF(O7_REF(l1)->right)->value_, O7_REF(l2)->value_) >= 0);
	} else {
		cross = (o7_cmp(O7_REF(l1)->value_, O7_REF(l2)->value_) == 0) || (O7_REF(l2)->right != NULL) && (o7_cmp(O7_REF(O7_REF(l2)->right)->value_, O7_REF(l1)->value_) >= 0);
	}
	return cross;
}

static o7_bool IsListCrossRange(struct Ast_RCaseLabel *list, struct Ast_RCaseLabel *range) {
	while ((list != NULL) && !IsRangesCross(list, range)) {
		list = O7_REF(list)->next;
	}
	return list != NULL;
}

static o7_bool IsElementsCrossRange(struct Ast_RCaseElement *elem, struct Ast_RCaseLabel *range) {
	while ((elem != NULL) && !IsListCrossRange(O7_REF(elem)->labels, range)) {
		elem = O7_REF(elem)->next;
	}
	return elem != NULL;
}

extern o7_int_t Ast_CaseRangeListAdd(struct Ast_Case__s *case_, struct Ast_RCaseLabel *first, struct Ast_RCaseLabel *new_) {
	o7_int_t err;

	O7_ASSERT(O7_REF(new_)->next == NULL);
	O7_ASSERT(O7_REF(case_)->else_ == NULL);
	if ((o7_cmp(O7_REF(O7_REF(O7_REF(case_)->_.expr)->type)->_._.id, O7_REF(new_)->_.id) != 0) && !((o7_in(O7_REF(O7_REF(O7_REF(case_)->_.expr)->type)->_._.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst)))) && (o7_in(O7_REF(new_)->_.id, ((1u << Ast_IdInteger_cnst) | (1u << Ast_IdByte_cnst)))))) {
		err = Ast_ErrCaseRangeLabelsTypeMismatch_cnst;
	} else {
		if (IsElementsCrossRange(O7_REF(case_)->elements, new_)) {
			err = Ast_ErrCaseElemDuplicate_cnst;
		} else {
			err = Ast_ErrNo_cnst;
		}

		if (first != NULL) {
			while (O7_REF(first)->next != NULL) {
				if (IsListCrossRange(first, new_)) {
					err = Ast_ErrCaseElemDuplicate_cnst;
				}
				first = O7_REF(first)->next;
			}
			if (IsListCrossRange(first, new_)) {
				err = Ast_ErrCaseElemDuplicate_cnst;
			}
			O7_REF(first)->next = new_;
		}
	}
	return err;
}

extern struct Ast_RCaseElement *Ast_CaseElementNew(struct Ast_RCaseLabel *labels) {
	struct Ast_RCaseElement *elem = NULL;

	O7_NEW(&elem, Ast_RCaseElement);
	NodeInit(&(*O7_REF(elem))._, Ast_NoId_cnst);
	O7_REF(elem)->next = NULL;
	O7_REF(elem)->labels = labels;
	O7_REF(elem)->stats = NULL;
	return elem;
}

extern o7_int_t Ast_CaseElementAdd(struct Ast_Case__s *case_, struct Ast_RCaseElement *elem) {
	o7_int_t err;
	struct Ast_RCaseElement *last;

	O7_ASSERT(O7_REF(case_)->else_ == NULL);
	if (O7_REF(case_)->elements == NULL) {
		O7_REF(case_)->elements = elem;
	} else {
		last = O7_REF(case_)->elements;
		while (O7_REF(last)->next != NULL) {
			last = O7_REF(last)->next;
		}
		O7_REF(last)->next = elem;
	}
	err = Ast_ErrNo_cnst;
	return err;
}

static void TypeInclAssigned(struct Ast_RType *t) {
	struct Ast_RDeclaration *v;
	struct Ast_RRecord *rec;

	O7_REF(t)->properties |= 1u << Ast_TypeAssigned_cnst;
	if (o7_cmp(O7_REF(t)->_._.id, Ast_IdRecord_cnst) == 0) {
		rec = O7_GUARD(Ast_RRecord, &t);
		if (O7_REF(rec)->base != NULL) {
			TypeInclAssigned(&O7_REF(rec)->base->_._);
		}
		v = (&(O7_REF(rec)->vars)->_);
		while (v != NULL) {
			if (o7_cmp(O7_REF(O7_REF(v)->type)->_._.id, Ast_IdRecord_cnst) == 0) {
				TypeInclAssigned(O7_REF(v)->type);
			}
			v = O7_REF(v)->next;
		}
	}
}

extern o7_int_t Ast_AssignNew(struct Ast_Assign__s **a, o7_bool inLoops, struct Ast_Designator__s *des, struct Ast_RExpression *expr) {
	o7_int_t err;
	struct Ast_RVar *var_;

	O7_NEW(&(*a), Ast_Assign__s);
	StatInit(&(*a)->_, expr);
	O7_REF((*a))->designator = des;
	err = Ast_ErrNo_cnst;
	if (des != NULL) {
		if ((o7_is(O7_REF(des)->decl, &Ast_RVar_tag)) && Ast_IsChangeable(des)) {
			var_ = O7_GUARD(Ast_RVar, &O7_REF(des)->decl);
			TypeInclAssigned(O7_REF(des)->_._.type);
			if (o7_cmp(O7_REF(O7_REF(var_)->_.type)->_._.id, Ast_IdPointer_cnst) == 0) {
				if ((O7_REF(des)->sel != NULL) && (!(!!( (1u << Ast_InitedValue_cnst) & O7_REF(O7_REF(var_)->state)->inited)) || !o7_bl(O7_REF(O7_REF(var_)->state)->inCondition) && (0 != (O7_REF(O7_REF(var_)->state)->inited & ((1u << Ast_InitedNo_cnst) | (1u << Ast_InitedNil_cnst))))) && !inLoops) {
					err = Ast_ErrVarUninitialized_cnst;
				}
				O7_REF(var_)->_.used = (0 < 1);
			}

			O7_REF(O7_REF(var_)->state)->inited = O7_REF(O7_REF(var_)->state)->inited & ~((1u << Ast_InitedNo_cnst) | (1u << Ast_InitedValue_cnst) | (1u << Ast_InitedCheck_cnst) | (1u << Ast_InitedNil_cnst));
			if ((O7_REF(des)->sel == NULL) && (!Ast_IsGlobal(&var_->_) || (o7_is(var_, &Ast_RFormalParam_tag))) && (expr != NULL) && (O7_REF(expr)->value_ != NULL) && (O7_REF(expr)->value_ == &Ast_ExprNilGet()->_)) {
				O7_REF(O7_REF(var_)->state)->inited |= 1u << Ast_InitedNil_cnst;
			} else {
				O7_REF(O7_REF(var_)->state)->inited |= 1u << Ast_InitedValue_cnst;
			}
			O7_REF(des)->inited = O7_REF(O7_REF(var_)->state)->inited;
		} else {
			err = Ast_ErrAssignExpectVarParam_cnst;
		}

		if ((err == Ast_ErrNo_cnst) && (expr != NULL) && !Ast_CompatibleTypes(&O7_REF((*a))->distance, O7_REF(des)->_._.type, O7_REF(expr)->type, (0 > 1)) && !CompatibleAsCharAndString(O7_REF(des)->_._.type, &expr) && !CompatibleAsStrings(O7_REF(des)->_._.type, expr)) {
			if (!CompatibleAsIntAndByte(O7_REF(des)->_._.type, O7_REF(expr)->type)) {
				Log_Str(38, (o7_char *)"ErrAssignIncompatibleType because of ");
				Log_Int(o7_int(O7_REF(O7_REF(des)->_._.type)->_._.id));
				Log_Str(2, (o7_char *)"\x20");
				Log_Int(o7_int(O7_REF(O7_REF(expr)->type)->_._.id));
				Log_Ln();
				err = Ast_ErrAssignIncompatibleType_cnst;
			} else if ((o7_cmp(O7_REF(O7_REF(des)->_._.type)->_._.id, Ast_IdByte_cnst) == 0) && (O7_REF(expr)->value_ != NULL) && !TypesLimits_InByteRange(o7_int(O7_GUARD(Ast_RExprInteger, &O7_REF(expr)->value_)->int_))) {
				err = Ast_ErrValueOutOfRangeOfByte_cnst;
			}
		}

		if ((err == Ast_ErrNo_cnst) && (O7_REF(expr)->value_ != NULL) && (o7_is(O7_REF(expr)->value_, &Ast_ExprString__s_tag)) && (o7_cmp(O7_REF(O7_REF(des)->_._.type)->_._.id, Ast_IdArray_cnst) == 0) && (O7_GUARD(Ast_RArray, &O7_REF(des)->_._.type)->count != NULL) && (o7_cmp(O7_GUARD(Ast_RExprInteger, &O7_GUARD(Ast_RArray, &O7_REF(des)->_._.type)->count)->int_, O7_GUARD(Ast_RExprInteger, &O7_GUARD(Ast_RArray, &O7_REF(O7_REF(expr)->value_)->_.type)->count)->int_) < 0)) {
			err = Ast_ErrAssignStringToNotEnoughArray_cnst;
		}

		if ((o7_cmp(O7_REF(O7_REF(des)->_._.type)->_._.id, Ast_IdProcType_cnst) == 0) && (err == Ast_ErrNo_cnst) && (expr != &nil->_._) && (o7_cmp(O7_REF(O7_GUARD(Ast_Designator__s, &expr)->decl)->_.id, Ast_IdProc_cnst) == 0)) {
			O7_GUARD(Ast_RProcedure, &O7_GUARD(Ast_Designator__s, &expr)->decl)->usedAsValue = (0 < 1);
		}
	}
	return err;
}

extern struct Ast_StatementError__s *Ast_StatementErrorNew(void) {
	struct Ast_StatementError__s *s = NULL;

	O7_NEW(&s, Ast_StatementError__s);
	StatInit(&s->_, NULL);
	return s;
}

static void PredefinedDeclarationsInit(void);
static void PredefinedDeclarationsInit_TypeNew(o7_int_t s, o7_int_t t) {
	struct Ast_RType *td = NULL;

	O7_NEW(&td, Ast_RType);
	TypeInit(td, t);

	predefined[o7_ind(OberonSpecIdent_PredefinedLast_cnst - OberonSpecIdent_PredefinedFirst_cnst + 1, o7_sub(s, OberonSpecIdent_PredefinedFirst_cnst))] = (&(td)->_);
	types[o7_ind(Ast_PredefinedTypesCount_cnst, t)] = td;
}

static struct Ast_RProcType *PredefinedDeclarationsInit_ProcNew(o7_int_t s, o7_int_t t) {
	struct Ast_PredefinedProcedure__s *td = NULL;

	O7_NEW(&td, Ast_PredefinedProcedure__s);
	NodeInit(&(*O7_REF(td))._._._._, s);
	DeclInit(&td->_._._, NULL);
	predefined[o7_ind(OberonSpecIdent_PredefinedLast_cnst - OberonSpecIdent_PredefinedFirst_cnst + 1, o7_sub(s, OberonSpecIdent_PredefinedFirst_cnst))] = (&(td)->_._._);
	O7_REF(td)->_.header = Ast_ProcTypeNew((0 > 1));
	O7_REF(td)->_._._.type = (&(O7_REF(td)->_.header)->_._);
	if (Ast_NoId_cnst < t) {
		O7_REF(O7_REF(td)->_.header)->_._._.type = Ast_TypeGet(t);
	}
	return O7_REF(td)->_.header;
}

static void PredefinedDeclarationsInit(void) {
	struct Ast_RProcType *tp;
	struct Ast_RType *typeInt, *typeReal;

	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Byte_cnst, Ast_IdByte_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Integer_cnst, Ast_IdInteger_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_LongInt_cnst, Ast_IdLongInt_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Char_cnst, Ast_IdChar_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Set_cnst, Ast_IdSet_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_LongSet_cnst, Ast_IdLongSet_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Boolean_cnst, Ast_IdBoolean_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Real_cnst, Ast_IdReal_cnst);
	PredefinedDeclarationsInit_TypeNew(OberonSpecIdent_Real32_cnst, Ast_IdReal32_cnst);
	O7_NEW(&types[Ast_IdPointer_cnst], Ast_RType);
	NodeInit(&(*O7_REF(types[Ast_IdPointer_cnst]))._._, Ast_IdPointer_cnst);
	DeclInit(&types[Ast_IdPointer_cnst]->_, NULL);

	typeInt = Ast_TypeGet(Ast_IdInteger_cnst);
	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Abs_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Asr_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Assert_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, Ast_TypeGet(Ast_IdBoolean_cnst), (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Chr_cnst, Ast_IdChar_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Dec_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, typeInt, ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Excl_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, Ast_TypeGet(Ast_IdSet_cnst), ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	typeReal = Ast_TypeGet(Ast_IdReal_cnst);
	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Floor_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, typeReal, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Flt_cnst, Ast_IdReal_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Inc_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, typeInt, ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Incl_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, Ast_TypeGet(Ast_IdSet_cnst), ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Len_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, &Ast_ArrayGet(typeInt, NULL)->_._, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Lsl_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_New_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, Ast_TypeGet(Ast_IdPointer_cnst), ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Odd_cnst, Ast_IdBoolean_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Ord_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, Ast_TypeGet(Ast_IdChar_cnst), (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Pack_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, typeReal, ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Ror_cnst, Ast_IdInteger_cnst);
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));
	ParamAddPredefined(tp, typeInt, (1u << Ast_ParamIn_cnst));

	tp = PredefinedDeclarationsInit_ProcNew(OberonSpecIdent_Unpk_cnst, Ast_NoId_cnst);
	ParamAddPredefined(tp, typeReal, ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));
	ParamAddPredefined(tp, typeInt, ((1u << Ast_ParamIn_cnst) | (1u << Ast_ParamOut_cnst)));
}

extern o7_bool Ast_HasError(struct Ast_RModule *m) {
	return O7_REF(m)->errLast != NULL;
}

extern void Ast_ProviderInit(struct Ast_RProvider *p, Ast_Provide get, Ast_Register reg) {
	O7_ASSERT(get != NULL);
	O7_ASSERT(reg != NULL);

	V_Init(&(*O7_REF(p))._);
	O7_REF(p)->get = get;
	O7_REF(p)->reg = reg;
}

static void UnlinkVar(struct Ast_RVar *v) {
	O7_REF(v)->_.type = NULL;
	if (O7_REF(v)->state != NULL) {
		O7_REF(O7_REF(v)->state)->if_ = NULL;
		O7_REF(O7_REF(v)->state)->else_ = NULL;
		O7_REF(O7_REF(v)->state)->root = NULL;
		O7_REF(v)->state = NULL;
	}
}

static void DeclarationsUnlink(struct Ast_RDeclarations *ds);
static void DeclarationsUnlink_UnlinkRecord(struct Ast_RRecord *r) {
	struct Ast_RDeclaration *d;
	struct Ast_RVar *v;

	d = (&(O7_REF(r)->vars)->_);
	O7_REF(r)->pointer = NULL;
	O7_REF(r)->base = NULL;
	O7_REF(r)->vars = NULL;
	while (d != NULL) {
		v = O7_GUARD(Ast_RVar, &d);
		d = O7_REF(d)->next;
		O7_REF(v)->_.next = NULL;
		UnlinkVar(v);
	}
}

static void DeclarationsUnlink(struct Ast_RDeclarations *ds) {
	struct Ast_RDeclaration *p, *d;
	struct Ast_RStatement *st, *tst;

	O7_REF(O7_REF(ds)->dag)->d = NULL;
	O7_REF(ds)->dag = NULL;
	O7_REF(ds)->_.module_ = NULL;
	O7_REF(ds)->consts = NULL;
	O7_REF(ds)->types = NULL;
	O7_REF(ds)->vars = NULL;
	O7_REF(ds)->_._.ext = NULL;
	p = (&(O7_REF(ds)->procedures)->_._._);
	O7_REF(ds)->procedures = NULL;
	st = O7_REF(ds)->stats;
	O7_REF(ds)->stats = NULL;

	d = O7_REF(ds)->start;
	O7_REF(ds)->start = NULL;
	O7_REF(ds)->end = NULL;

	while (d != NULL) {
		p = d;
		d = O7_REF(d)->next;
		switch (O7_REF(p)->_.id) {
		case 9:
			if (O7_REF(p)->type != NULL) {
				DeclarationsUnlink_UnlinkRecord(O7_GUARD(Ast_RRecord, &O7_REF(p)->type));
			}
			break;
		case 11:
			break;
		case 12:
			DeclarationsUnlink_UnlinkRecord(O7_GUARD(Ast_RRecord, &p));
			break;
		case 10:
			O7_GUARD(Ast_RArray, &p)->count = NULL;
			break;
		case 13:
		case 32:
		case 31:
			break;
		case 33:
			O7_GUARD(Ast_Const__s, &p)->expr = NULL;
			break;
		case 35:
			O7_GUARD(Ast_RProcedure, &p)->_.header = NULL;
			O7_GUARD(Ast_RProcedure, &p)->_.return_ = NULL;
			DeclarationsUnlink(&O7_GUARD(Ast_RProcedure, &p)->_._);
			break;
		case 34:
			UnlinkVar(O7_GUARD(Ast_RVar, &p));
			break;
		default:
			o7_case_fail(O7_REF(p)->_.id);
			break;
		}
		O7_REF(p)->type = NULL;
		O7_REF(p)->next = NULL;
		O7_REF(p)->_.ext = NULL;
	}

	while (st != NULL) {
		tst = st;
		st = O7_REF(st)->next;
		O7_REF(tst)->expr = NULL;
		O7_REF(tst)->next = NULL;
		O7_REF(tst)->_.ext = NULL;
	}
}

extern void Ast_Unlinks(struct Ast_RModule *m) {
	struct Ast_RFormalParam *fp;

	O7_REF(O7_REF(m)->bag)->m = NULL;
	O7_REF(m)->bag = NULL;

	O7_REF(m)->_._.up = NULL;
	DeclarationsUnlink(&m->_);

	while (values != NULL) {
		O7_REF(values)->_.value_ = NULL;
		values = O7_REF(values)->nextValue;
	}

	while (needTags != NULL) {
		while (O7_REF(needTags)->first != NULL) {
			fp = O7_REF(O7_REF(needTags)->first)->link;
			O7_REF(O7_REF(needTags)->first)->link = NULL;
			O7_REF(needTags)->first = fp;
		}

		O7_REF(needTags)->last = NULL;

		needTags = O7_REF(needTags)->next;
	}
}

extern void Ast_init(void) {
	static unsigned initialized = 0;
	if (0 == initialized) {
		Log_init();
		Out_init();
		Scanner_init();
		StringStore_init();

		O7_TAG_INIT(Ast_RType, Ast_RDeclaration);
		O7_TAG_INIT(Ast_Const__s, Ast_RDeclaration);
		O7_TAG_INIT(Ast_RConstruct, Ast_RType);
		O7_TAG_INIT(Ast_RArray, Ast_RConstruct);
		O7_TAG_INIT(Ast_RVar, Ast_RDeclaration);
		O7_TAG_INIT(Ast_RRecord, Ast_RConstruct);
		O7_TAG_INIT(Ast_RPointer, Ast_RConstruct);
		O7_TAG_INIT(Ast_RFormalParam, Ast_RVar);
		O7_TAG_INIT(Ast_RProcType, Ast_RConstruct);
		O7_TAG_INIT(FormalProcType__s, Ast_RProcType);
		O7_TAG_INIT(Ast_Import__s, Ast_RDeclaration);
		O7_TAG_INIT(Ast_RModule, Ast_RDeclarations);
		O7_TAG_INIT(Ast_RGeneralProcedure, Ast_RDeclarations);
		O7_TAG_INIT(Ast_RProcedure, Ast_RGeneralProcedure);
		O7_TAG_INIT(Ast_PredefinedProcedure__s, Ast_RGeneralProcedure);
		O7_TAG_INIT(Ast_SelPointer__s, Ast_RSelector);
		O7_TAG_INIT(Ast_SelGuard__s, Ast_RSelector);
		O7_TAG_INIT(Ast_SelArray__s, Ast_RSelector);
		O7_TAG_INIT(Ast_SelRecord__s, Ast_RSelector);
		O7_TAG_INIT(Ast_RFactor, Ast_RExpression);
		O7_TAG_INIT(Ast_Designator__s, Ast_RFactor);
		O7_TAG_INIT(Ast_RExprInteger, Ast_ExprNumber);
		O7_TAG_INIT(Ast_ExprReal__s, Ast_ExprNumber);
		O7_TAG_INIT(Ast_ExprBoolean__s, Ast_RFactor);
		O7_TAG_INIT(Ast_ExprString__s, Ast_RExprInteger);
		O7_TAG_INIT(Ast_RExprSet, Ast_RFactor);
		O7_TAG_INIT(Ast_ExprSetValue__s, Ast_RFactor);
		O7_TAG_INIT(Ast_ExprNegate__s, Ast_RFactor);
		O7_TAG_INIT(Ast_ExprBraces__s, Ast_RFactor);
		O7_TAG_INIT(Ast_ExprRelation__s, Ast_RExpression);
		O7_TAG_INIT(Ast_ExprIsExtension__s, Ast_RExpression);
		O7_TAG_INIT(Ast_RExprSum, Ast_RExpression);
		O7_TAG_INIT(Ast_ExprTerm__s, Ast_RExpression);
		O7_TAG_INIT(Ast_ExprCall__s, Ast_RFactor);
		O7_TAG_INIT(Ast_RWhileIf, Ast_RStatement);
		O7_TAG_INIT(Ast_If__s, Ast_RWhileIf);
		O7_TAG_INIT(Ast_Case__s, Ast_RStatement);
		O7_TAG_INIT(Ast_Repeat__s, Ast_RStatement);
		O7_TAG_INIT(Ast_For__s, Ast_RStatement);
		O7_TAG_INIT(Ast_Assign__s, Ast_RStatement);
		O7_TAG_INIT(Ast_Call__s, Ast_RStatement);

		O7_STATIC_ASSERT(!(O7_IN(Ast_NoSign_cnst, ((1u << Ast_Plus_cnst) | (1u << Ast_Minus_cnst) | (1u << Ast_Or_cnst)))));

		PredefinedDeclarationsInit();
		booleans[0] = NULL;
		booleans[1] = NULL;
		nil = NULL;
		values = NULL;
		needTags = NULL;
	}
	++initialized;
}

