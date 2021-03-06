#include <o7.h>

#include "StringStore.h"

#define StringStore_RBlock_tag V_Base_tag
extern void StringStore_RBlock_undef(struct StringStore_RBlock *r) {
	V_Base_undef(&r->_);
	memset(&r->s, 0, sizeof(r->s));
	r->next = NULL;
	r->num = O7_INT_UNDEF;
}
#define StringStore_String_tag V_Base_tag
extern void StringStore_String_undef(struct StringStore_String *r) {
	V_Base_undef(&r->_);
	r->block = NULL;
	r->ofs = O7_INT_UNDEF;
}
#define StringStore_Iterator_tag V_Base_tag
extern void StringStore_Iterator_undef(struct StringStore_Iterator *r) {
	V_Base_undef(&r->_);
	r->char_ = '\0';
	r->b = NULL;
	r->i = O7_INT_UNDEF;
}
#define StringStore_Store_tag V_Base_tag
extern void StringStore_Store_undef(struct StringStore_Store *r) {
	V_Base_undef(&r->_);
	r->first = NULL;
	r->last = NULL;
	r->ofs = O7_INT_UNDEF;
}

extern void StringStore_Undef(struct StringStore_String *s) {
	V_Init(&(*s)._);
	(*s).block = NULL;
	(*s).ofs =  - 1;
}

extern o7_bool StringStore_IsDefined(struct StringStore_String *s) {
	return (*s).block != NULL;
}

static void Put_AddBlock(struct StringStore_RBlock **b, o7_int_t *i) {
	O7_ASSERT(O7_REF((*b))->next == NULL);
	(*i) = 0;
	O7_NEW(&O7_REF((*b))->next, StringStore_RBlock);
	V_Init(&(*O7_REF(O7_REF((*b))->next))._);
	O7_REF(O7_REF((*b))->next)->num = o7_add(O7_REF((*b))->num, 1);
	(*b) = O7_REF((*b))->next;
	O7_REF((*b))->next = NULL;
}

extern void StringStore_Put(struct StringStore_Store *store, struct StringStore_String *w, o7_int_t s_len0, o7_char s[/*len0*/], o7_int_t j, o7_int_t end) {
	struct StringStore_RBlock *b;
	o7_int_t i;

	O7_ASSERT((s_len0 % 2 == 1) || (j <= end));
	O7_ASSERT((0 <= j) && (j < o7_sub(s_len0, 1)));
	O7_ASSERT((0 <= end) && (end < s_len0));
	b = (*store).last;
	i = o7_int((*store).ofs);
	V_Init(&(*w)._);
	(*w).block = b;
	(*w).ofs = i;
	while (j != end) {
		if (i == O7_LEN(O7_REF(b)->s) - 1) {
			O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] = 0x0Cu;
			Put_AddBlock(&b, &i);
		}
		O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] = s[o7_ind(s_len0, j)];
		O7_ASSERT(s[o7_ind(s_len0, j)] != 0x0Cu);
		i = o7_add(i, 1);

		j = o7_add(j, 1);
		if ((j == o7_sub(s_len0, 1)) && (end < o7_sub(s_len0, 1))) {
			j = 0;
		}
	}
	O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] = 0x00u;
	if (i < O7_LEN(O7_REF(b)->s) - 2) {
		i = o7_add(i, 1);
	} else {
		Put_AddBlock(&b, &i);
	}
	(*store).last = b;
	(*store).ofs = i;
}

extern o7_bool StringStore_GetIter(struct StringStore_Iterator *iter, struct StringStore_String *s, o7_int_t ofs) {
	O7_ASSERT(0 <= ofs);
	if ((*s).block != NULL) {
		V_Init(&(*iter)._);
		(*iter).b = (*s).block;
		(*iter).i = o7_int((*s).ofs);
		while (1) if (O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)] == 0x0Cu) {
			(*iter).b = O7_REF((*iter).b)->next;
			(*iter).i = 0;
		} else if ((0 < ofs) && (O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)] != 0x00u)) {
			ofs = o7_sub(ofs, 1);
			(*iter).i = o7_add((*iter).i, 1);
		} else break;
		(*iter).char_ = O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)];
	}
	return ((*s).block != NULL) && (O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)] != 0x00u);
}

extern o7_bool StringStore_IterNext(struct StringStore_Iterator *iter) {
	if ((*iter).char_ != 0x00u) {
		(*iter).i = o7_add((*iter).i, 1);
		if (O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)] == 0x0Cu) {
			(*iter).b = O7_REF((*iter).b)->next;
			(*iter).i = 0;
		}
		(*iter).char_ = O7_REF((*iter).b)->s[o7_ind(StringStore_BlockSize_cnst + 1, (*iter).i)];
	}
	return (*iter).char_ != 0x00u;
}

extern o7_char StringStore_GetChar(struct StringStore_String *s, o7_int_t i) {
	o7_int_t ofs;
	struct StringStore_RBlock *b;

	O7_ASSERT((0 <= i) && (i < StringStore_BlockSize_cnst * StringStore_BlockSize_cnst));
	ofs = o7_add((*s).ofs, i);
	b = (*s).block;
	while (StringStore_BlockSize_cnst <= ofs) {
		b = O7_REF(b)->next;
		ofs = o7_sub(ofs, StringStore_BlockSize_cnst);
	}
	return O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, ofs)];
}

extern o7_bool StringStore_IsEqualToChars(struct StringStore_String *w, o7_int_t s_len0, o7_char s[/*len0*/], o7_int_t j, o7_int_t end) {
	o7_int_t i;
	struct StringStore_RBlock *b;

	O7_ASSERT((j >= 0) && (j < o7_sub(s_len0, 1)));
	O7_ASSERT((0 <= end) && (end < o7_sub(s_len0, 1)));
	i = o7_int((*w).ofs);
	b = (*w).block;
	while (1) if ((O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == s[o7_ind(s_len0, j)]) && (j != end)) {
		i = o7_add(i, 1);
		j = o7_mod((o7_add(j, 1)), (o7_sub(s_len0, 1)));
	} else if (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu) {
		b = O7_REF(b)->next;
		i = 0;
	} else break;
	return (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x00u) && (j == end);
}

extern o7_bool StringStore_IsEqualToString(struct StringStore_String *w, o7_int_t s_len0, o7_char s[/*len0*/]) {
	o7_int_t i, j;
	struct StringStore_RBlock *b;

	j = 0;
	i = o7_int((*w).ofs);
	b = (*w).block;
	while (1) if ((j < s_len0) && (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == s[o7_ind(s_len0, j)]) && (s[o7_ind(s_len0, j)] != 0x00u)) {
		i = o7_add(i, 1);
		j = o7_add(j, 1);
	} else if (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu) {
		b = O7_REF(b)->next;
		i = 0;
	} else break;
	return (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x00u) && ((j == s_len0) || (s[o7_ind(s_len0, j)] == 0x00u));
}

extern o7_int_t StringStore_Compare(struct StringStore_String *w1, struct StringStore_String *w2) {
	o7_int_t i1, i2, res;
	struct StringStore_RBlock *b1, *b2;

	i1 = o7_int((*w1).ofs);
	i2 = o7_int((*w2).ofs);
	b1 = (*w1).block;
	b2 = (*w2).block;
	while (1) if (O7_REF(b1)->s[o7_ind(StringStore_BlockSize_cnst + 1, i1)] == 0x0Cu) {
		b1 = O7_REF(b1)->next;
		i1 = 0;
	} else if (O7_REF(b2)->s[o7_ind(StringStore_BlockSize_cnst + 1, i2)] == 0x0Cu) {
		b2 = O7_REF(b2)->next;
		i2 = 0;
	} else if ((O7_REF(b1)->s[o7_ind(StringStore_BlockSize_cnst + 1, i1)] == O7_REF(b2)->s[o7_ind(StringStore_BlockSize_cnst + 1, i2)]) && (O7_REF(b1)->s[o7_ind(StringStore_BlockSize_cnst + 1, i1)] != 0x00u)) {
		i1 = o7_add(i1, 1);
		i2 = o7_add(i2, 1);
	} else break;
	if (O7_REF(b1)->s[o7_ind(StringStore_BlockSize_cnst + 1, i1)] == O7_REF(b2)->s[o7_ind(StringStore_BlockSize_cnst + 1, i2)]) {
		res = 0;
	} else if (O7_REF(b1)->s[o7_ind(StringStore_BlockSize_cnst + 1, i1)] < O7_REF(b2)->s[o7_ind(StringStore_BlockSize_cnst + 1, i2)]) {
		res =  - 1;
	} else {
		res = 1;
	}
	return res;
}

extern o7_bool StringStore_SearchSubString(struct StringStore_String *w, o7_int_t s_len0, o7_char s[/*len0*/]) {
	o7_int_t i, j;
	struct StringStore_RBlock *b;

	i = o7_int((*w).ofs);
	b = (*w).block;
	do {
		while (1) if (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu) {
			b = O7_REF(b)->next;
			i = 0;
		} else if ((O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] != s[0]) && (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] != 0x00u)) {
			i = o7_add(i, 1);
		} else break;
		j = 0;
		while (1) if ((j < s_len0) && (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == s[o7_ind(s_len0, j)]) && (s[o7_ind(s_len0, j)] != 0x00u)) {
			i = o7_add(i, 1);
			j = o7_add(j, 1);
		} else if (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu) {
			b = O7_REF(b)->next;
			i = 0;
		} else break;
	} while (!((j == s_len0) || (s[o7_ind(s_len0, j)] == 0x00u) || (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x00u)));
	return (j == s_len0) || (s[o7_ind(s_len0, j)] == 0x00u);
}

extern o7_bool StringStore_CopyToChars(o7_int_t d_len0, o7_char d[/*len0*/], o7_int_t *dofs, struct StringStore_String *w) {
	struct StringStore_RBlock *b;
	o7_int_t i;

	b = (*w).block;
	i = o7_int((*w).ofs);
	while (1) if (((*dofs) < o7_sub(d_len0, 1)) && (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] > 0x0Cu)) {
		d[o7_ind(d_len0, (*dofs))] = O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)];
		(*dofs) = o7_add((*dofs), 1);
		i = o7_add(i, 1);
	} else if (O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] != 0x00u) {
		O7_ASSERT(O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu);
		b = O7_REF(b)->next;
		i = 0;
	} else break;
	d[o7_ind(d_len0, (*dofs))] = 0x00u;
	return O7_REF(b)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x00u;
}

extern void StringStore_StoreInit(struct StringStore_Store *s) {
	V_Init(&(*s)._);
	O7_NEW(&(*s).first, StringStore_RBlock);
	V_Init(&(*O7_REF((*s).first))._);
	O7_REF((*s).first)->num = 0;
	(*s).last = (*s).first;
	O7_REF((*s).last)->next = NULL;
	(*s).ofs = 0;
}

extern void StringStore_StoreDone(struct StringStore_Store *s) {
	while ((*s).first != NULL) {
		(*s).first = O7_REF((*s).first)->next;
	}
	(*s).last = NULL;
}

extern o7_int_t StringStore_Write(struct VDataStream_Out *out, o7_tag_t *out_tag, struct StringStore_String *str) {
	o7_int_t i, len, ofs;
	struct StringStore_RBlock *block;

	block = (*str).block;
	i = o7_int((*str).ofs);
	ofs = i;
	len = 0;
	while (1) if (O7_REF(block)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x0Cu) {
		len = o7_add(len, VDataStream_WriteChars(&(*out), out_tag, StringStore_BlockSize_cnst + 1, O7_REF(block)->s, ofs, o7_sub(i, ofs)));
		block = O7_REF(block)->next;
		ofs = 0;
		i = 0;
	} else if (O7_REF(block)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] != 0x00u) {
		i = o7_add(i, 1);
	} else break;
	O7_ASSERT(O7_REF(block)->s[o7_ind(StringStore_BlockSize_cnst + 1, i)] == 0x00u);
	len = VDataStream_WriteChars(&(*out), out_tag, StringStore_BlockSize_cnst + 1, O7_REF(block)->s, ofs, o7_sub(i, ofs));
	return len;
}

extern void StringStore_init(void) {
	static unsigned initialized = 0;
	if (0 == initialized) {
		Log_init();
		VDataStream_init();
	}
	++initialized;
}

