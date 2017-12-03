/* Generated by Vostok - Oberon-07 translator */

/*  Formatted plain text generator
 *  Copyright (C) 2017 ComdivByZero
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published
 *  by the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#if !defined(HEADER_GUARD_TextGenerator)
#define HEADER_GUARD_TextGenerator 1

#include "V.h"
#include "Utf8.h"
#include "StringStore.h"
#include "VDataStream.h"

typedef struct TextGenerator_Out {
	V_Base _;
	struct VDataStream_Out *out;
	int len;
	int tabs;
	o7_bool isNewLine;
} TextGenerator_Out;
#define TextGenerator_Out_tag V_Base_tag

extern void TextGenerator_Out_undef(struct TextGenerator_Out *r);

extern void TextGenerator_Init(struct TextGenerator_Out *g, struct VDataStream_Out *out);

extern void TextGenerator_SetTabs(struct TextGenerator_Out *g, struct TextGenerator_Out *d);

extern int TextGenerator_CalcLen(int str_len0, o7_char str[/*len0*/], int ofs);

extern void TextGenerator_Str(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_StrLn(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_Ln(struct TextGenerator_Out *gen);

extern void TextGenerator_StrOpen(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_IndentOpen(struct TextGenerator_Out *gen);

extern void TextGenerator_IndentClose(struct TextGenerator_Out *gen);

extern void TextGenerator_StrClose(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_StrLnClose(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_StrIgnoreIndent(struct TextGenerator_Out *gen, int str_len0, o7_char str[/*len0*/]);

extern void TextGenerator_String(struct TextGenerator_Out *gen, struct StringStore_String *word);

extern void TextGenerator_Data(struct TextGenerator_Out *g, int data_len0, o7_char data[/*len0*/], int ofs, int count);

extern void TextGenerator_ScreeningString(struct TextGenerator_Out *gen, struct StringStore_String *str);

extern void TextGenerator_Int(struct TextGenerator_Out *gen, int int_);

extern void TextGenerator_Real(struct TextGenerator_Out *gen, double real);

extern void TextGenerator_init(void);
#endif
