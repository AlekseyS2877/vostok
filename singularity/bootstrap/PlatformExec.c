#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>

#define O7C_BOOL_UNDEFINED
#include <o7c.h>

#include "PlatformExec.h"

o7c_tag_t PlatformExec_Code_tag;

static o7c_bool Copy(o7c_char d[/*len0*/], int d_len0, int *i, o7c_char s[/*len0*/], int s_len0, int *j) {
	while (1) if ((o7c_cmp((*i), o7c_sub(d_len0, 4)) <  0) && (s[o7c_ind(s_len0, (*j))] == (char unsigned)'\'')) {
		d[o7c_ind(d_len0, (*i))] = (char unsigned)'\'';
		d[o7c_ind(d_len0, o7c_add((*i), 1))] = (char unsigned)'\\';
		d[o7c_ind(d_len0, o7c_add((*i), 2))] = (char unsigned)'\'';
		d[o7c_ind(d_len0, o7c_add((*i), 3))] = (char unsigned)'\'';
		(*i) = o7c_add((*i), 4);
		(*j) = o7c_add((*j), 1);
	} else if ((o7c_cmp((*i), o7c_sub(d_len0, 1)) <  0) && (s[o7c_ind(s_len0, (*j))] != 0x00u)) {
		d[o7c_ind(d_len0, (*i))] = s[o7c_ind(s_len0, (*j))];
		(*i) = o7c_add((*i), 1);
		(*j) = o7c_add((*j), 1);
	} else break;
	d[o7c_ind(d_len0, (*i))] = 0x00u;
	return s[o7c_ind(s_len0, (*j))] == 0x00u;
}

static o7c_bool FullCopy(o7c_char d[/*len0*/], int d_len0, int *i, o7c_char s[/*len0*/], int s_len0, int j) {
	o7c_bool ret = O7C_BOOL_UNDEF;

	d[o7c_ind(d_len0, (*i))] = (char unsigned)'\'';
	(*i) = o7c_add((*i), 1);
	ret = Copy(d, d_len0, &(*i), s, s_len0, &j) && (o7c_cmp((*i), o7c_sub(d_len0, 1)) <  0);
	if (ret) {
		d[o7c_ind(d_len0, (*i))] = (char unsigned)'\'';
		(*i) = o7c_add((*i), 1);
		d[o7c_ind(d_len0, (*i))] = 0x00u;
	}
	return s[o7c_ind(s_len0, j)] == 0x00u;
}

extern o7c_bool PlatformExec_Init(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char name[/*len0*/], int name_len0) {
	V_Init(&(*c)._, c_tag);
	(*c).len = 0;
	return (name[0] == 0x00u) || FullCopy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, name, name_len0, 0);
}

extern o7c_bool PlatformExec_Add(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char arg[/*len0*/], int arg_len0, int ofs) {
	o7c_bool ret = O7C_BOOL_UNDEF;

	ret = o7c_cmp((*c).len, sizeof((*c).buf) / sizeof ((*c).buf[0]) - 1) <  0;
	if (ret) {
		(*c).buf[o7c_ind(PlatformExec_CodeSize_cnst, (*c).len)] = (char unsigned)' ';
		(*c).len = o7c_add((*c).len, 1);
		ret = FullCopy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, arg, arg_len0, ofs);
	}
	return ret;
}

extern o7c_bool PlatformExec_AddClean(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char arg[/*len0*/], int arg_len0) {
	int ofs = O7C_INT_UNDEF;

	ofs = 0;
	return Copy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, arg, arg_len0, &ofs);
}

extern o7c_bool PlatformExec_FirstPart(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char arg[/*len0*/], int arg_len0) {
	o7c_bool ret = O7C_BOOL_UNDEF;
	int ofs = O7C_INT_UNDEF;

	ret = o7c_cmp((*c).len, sizeof((*c).buf) / sizeof ((*c).buf[0]) - 2) <  0;
	if (ret) {
		(*c).buf[o7c_ind(PlatformExec_CodeSize_cnst, (*c).len)] = (char unsigned)' ';
		(*c).buf[o7c_ind(PlatformExec_CodeSize_cnst, o7c_add((*c).len, 1))] = (char unsigned)'\'';
		(*c).len = o7c_add((*c).len, 2);
		ofs = 0;
		ret = Copy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, arg, arg_len0, &ofs);
	}
	return ret;
}

extern o7c_bool PlatformExec_AddPart(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char arg[/*len0*/], int arg_len0) {
	int ofs = O7C_INT_UNDEF;

	ofs = 0;
	return Copy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, arg, arg_len0, &ofs);
}

extern o7c_bool PlatformExec_LastPart(struct PlatformExec_Code *c, o7c_tag_t c_tag, o7c_char arg[/*len0*/], int arg_len0) {
	o7c_bool ret = O7C_BOOL_UNDEF;
	int ofs = O7C_INT_UNDEF;

	ofs = 0;
	ret = Copy((*c).buf, PlatformExec_CodeSize_cnst, &(*c).len, arg, arg_len0, &ofs) && (o7c_cmp((*c).len, sizeof((*c).buf) / sizeof ((*c).buf[0]) - 1) <  0);
	if (ret) {
		(*c).buf[o7c_ind(PlatformExec_CodeSize_cnst, (*c).len)] = (char unsigned)'\'';
		(*c).buf[o7c_ind(PlatformExec_CodeSize_cnst, o7c_add((*c).len, 1))] = 0x00u;
		(*c).len = o7c_add((*c).len, 2);
	}
	return ret;
}

extern int PlatformExec_Do(struct PlatformExec_Code *c, o7c_tag_t c_tag) {
	assert(o7c_cmp((*c).len, 0) >  0);
	return OsExec_Do((*c).buf, PlatformExec_CodeSize_cnst);
}

extern void PlatformExec_Log(struct PlatformExec_Code *c, o7c_tag_t c_tag) {
	Log_StrLn((*c).buf, PlatformExec_CodeSize_cnst);
}

extern void PlatformExec_init(void) {
	static int initialized = 0;
	if (0 == initialized) {
		V_init();
		Utf8_init();
		OsExec_init();
		Log_init();

		o7c_tag_init(PlatformExec_Code_tag, V_Base_tag);

	}
	++initialized;
}

