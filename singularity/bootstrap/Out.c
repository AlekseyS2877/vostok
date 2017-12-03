/* Generated by Vostok - Oberon-07 translator */

#include <stdbool.h>

#define O7_BOOL_UNDEFINED
#include <o7.h>

#include "Out.h"

static o7_bool success = O7_BOOL_UNDEF;

extern void Out_String(int s_len0, o7_char s[/*len0*/]) {
	int i = O7_INT_UNDEF;

	i = 0;
	while ((o7_cmp(i, s_len0) <  0) && (s[o7_ind(s_len0, i)] != 0x00u)) {
		i = o7_add(i, 1);
	}
	success = o7_cmp(i, CFiles_WriteChars(CFiles_out, s_len0, s, 0, i)) ==  0;
}

extern void Out_Char(o7_char ch) {
	o7_char s[1];
	memset(&s, 0, sizeof(s));

	s[0] = ch;
	success = o7_cmp(1, CFiles_WriteChars(CFiles_out, 1, s, 0, 1)) ==  0;
}

extern void Out_Int(int x, int n) {
	o7_char s[32];
	int i = O7_INT_UNDEF;
	o7_bool neg = O7_BOOL_UNDEF;
	memset(&s, 0, sizeof(s));

	i = O7_LEN(s);
	neg = false;
	if (o7_cmp(x, 0) ==  0) {
		i = o7_sub(i, 1);
		s[o7_ind(32, i)] = (o7_char)'0';
	} else {
		if (o7_cmp(x, 0) <  0) {
			neg = true;
			x = o7_sub(0, x);
		}
		while (o7_cmp(x, 0) !=  0) {
			i = o7_sub(i, 1);
			s[o7_ind(32, i)] = o7_chr(o7_add((int)(o7_char)'0', o7_mod(x, 10)));
			x = o7_div(x, 10);
		}
		if (o7_bl(neg)) {
			i = o7_sub(i, 1);
			s[o7_ind(32, i)] = (o7_char)'-';
		}
	}
	if (o7_cmp(n, 0) <  0) {
		n = O7_LEN(s);
	} else if (o7_cmp(n, O7_LEN(s)) >  0) {
		n = 0;
	} else {
		n = o7_sub(O7_LEN(s), n);
	}
	while (o7_cmp(i, n) >  0) {
		i = o7_sub(i, 1);
		s[o7_ind(32, i)] = (o7_char)' ';
	}
	success = o7_cmp(o7_sub(O7_LEN(s), i), CFiles_WriteChars(CFiles_out, 32, s, i, o7_sub(O7_LEN(s), i))) ==  0;
}

extern void Out_Ln(void) {
	o7_char s[2];
	memset(&s, 0, sizeof(s));

	s[0] = 0x0Du;
	s[1] = 0x0Au;
	success = (o7_cmp(O7_LEN(s), CFiles_WriteChars(CFiles_out, 2, s, 0, O7_LEN(s))) ==  0) && CFiles_Flush(CFiles_out);
}

/* TODO */
extern void Out_Real(double x, int n) {
	o7_char s[64];
	int i = O7_INT_UNDEF, l = O7_INT_UNDEF, e = O7_INT_UNDEF, d = O7_INT_UNDEF;
	o7_bool sign = O7_BOOL_UNDEF;
	double tens = O7_DBL_UNDEF;
	memset(&s, 0, sizeof(s));

	i = O7_LEN(s) / 2;
	if (x != x) {
		l = o7_add(i, 2);
		s[o7_ind(64, i)] = (o7_char)'N';
		s[o7_ind(64, o7_add(i, 1))] = (o7_char)'a';
		s[o7_ind(64, o7_add(i, 2))] = (o7_char)'N';
	} else if ((x == 0.0) || (x == o7_fsub(0, 0.0))) {
		l = o7_add(i, 2);
		s[o7_ind(64, i)] = (o7_char)'0';
		s[o7_ind(64, o7_add(i, 1))] = (o7_char)'.';
		s[o7_ind(64, o7_add(i, 2))] = (o7_char)'0';
		if (x < 0.0) {
			i = o7_sub(i, 1);
			s[o7_ind(64, i)] = (o7_char)'-';
		}
	} else {
		sign = x < 0.0;
		l = o7_int(i);
		if (o7_bl(sign)) {
			s[o7_ind(64, l)] = (o7_char)'-';
			l = o7_add(l, 1);
			x = o7_fsub(0, x);
		}
		if (x < 1.0) {
			e =  - 1;
			tens = 10.0;
			while (o7_fmul(x, tens) < 1.0) {
				e = o7_sub(e, 1);
				tens = o7_fmul(tens, 10.0);
			}
			x = o7_fmul(x, tens);
		} else if (10.0 <= x) {
			e = 1;
			tens = 10.0;
			while ((o7_fdiv(x, tens) >= 10.0) && (o7_cmp(e, 307) <=  0)) {
				e = o7_add(e, 1);
				tens = o7_fmul(tens, 10.0);
			}
			x = o7_fdiv(x, tens);
		} else {
			O7_ASSERT((1.0 <= x) && (x < 10.0));
			e = 0;
		}
		if (o7_cmp(e, 307) >  0) {
			s[o7_ind(64, l)] = (o7_char)'i';
			s[o7_ind(64, o7_add(l, 1))] = (o7_char)'n';
			s[o7_ind(64, o7_add(l, 2))] = (o7_char)'f';
			l = o7_add(l, 2);
		} else {
			s[o7_ind(64, l)] = o7_chr(o7_add((int)(o7_char)'0', o7_floor(x)));
			l = o7_add(l, 1);
			s[o7_ind(64, l)] = (o7_char)'.';
			if (o7_cmp(o7_mod(o7_floor(o7_fmul(x, 10.0)), 10), 0) ==  0) {
				l = o7_add(l, 1);
				s[o7_ind(64, l)] = (o7_char)'0';
			} else {
				while ((o7_cmp(l, O7_LEN(s) - 6) <  0) && (o7_cmp(o7_mod(o7_floor(o7_fmul(x, 10.0)), 10), 0) !=  0)) {
					x = o7_fsub(x, o7_flt(o7_mod(o7_floor(x), 10)));
					x = o7_fmul(x, 10.0);
					l = o7_add(l, 1);
					s[o7_ind(64, l)] = o7_chr(o7_add((int)(o7_char)'0', o7_mod(o7_floor(x), 10)));
				}
			}
			if (o7_cmp(e, 0) !=  0) {
				s[o7_ind(64, o7_add(l, 1))] = (o7_char)'E';
				l = o7_add(l, 2);
				if (o7_cmp(e, 0) <  0) {
					e = o7_sub(0, e);
					s[o7_ind(64, l)] = (o7_char)'-';
				} else {
					s[o7_ind(64, l)] = (o7_char)'+';
				}
				d = 100;
				while (o7_cmp(e, d) <  0) {
					d = o7_div(d, 10);
				}
				do {
					l = o7_add(l, 1);
					s[o7_ind(64, l)] = o7_chr(o7_add((int)(o7_char)'0', o7_div(e, d)));
					e = o7_mod(e, d);
					d = o7_div(d, 10);
				} while (!(o7_cmp(d, 0) ==  0));
			}
		}
	}
	if (o7_cmp(o7_add(l, 1), n) >  0) {
		n = o7_sub(o7_add(l, 1), n);
	} else {
		n = 0;
	}
	while (o7_cmp(n, i) <  0) {
		i = o7_sub(i, 1);
		s[o7_ind(64, i)] = (o7_char)' ';
	}
	success = o7_cmp(o7_add(o7_sub(l, i), 1), CFiles_WriteChars(CFiles_out, 64, s, i, o7_add(o7_sub(l, i), 1))) ==  0;
}

extern void Out_Open(void) {
	success = true;
}

extern void Out_init(void) {
	static int initialized = 0;
	if (0 == initialized) {
		CFiles_init();

	}
	++initialized;
}

