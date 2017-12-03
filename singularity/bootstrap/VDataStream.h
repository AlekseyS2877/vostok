/* Generated by Vostok - Oberon-07 translator */

/*  Abstract interfaces for data input and output
 *  Copyright (C) 2016-2017 ComdivByZero
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
#if !defined(HEADER_GUARD_VDataStream)
#define HEADER_GUARD_VDataStream 1

#include "V.h"

typedef struct VDataStream_In *VDataStream_PIn;
typedef struct VDataStream_In {
	V_Base _;
	int (*read)(struct V_Base *in_, o7_tag_t in__tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);
	int (*readChars)(struct V_Base *in_, o7_tag_t in__tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);
} VDataStream_In;
#define VDataStream_In_tag V_Base_tag

extern void VDataStream_In_undef(struct VDataStream_In *r);

typedef struct VDataStream_Out *VDataStream_POut;
typedef struct VDataStream_Out {
	V_Base _;
	int (*write)(struct V_Base *out, o7_tag_t out_tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);
	int (*writeChars)(struct V_Base *out, o7_tag_t out_tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);
} VDataStream_Out;
#define VDataStream_Out_tag V_Base_tag

extern void VDataStream_Out_undef(struct VDataStream_Out *r);

typedef int (*VDataStream_ReadProc)(struct V_Base *in_, o7_tag_t in__tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);
typedef int (*VDataStream_ReadCharsProc)(struct V_Base *in_, o7_tag_t in__tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);
typedef int (*VDataStream_WriteProc)(struct V_Base *out, o7_tag_t out_tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);
typedef int (*VDataStream_WriteCharsProc)(struct V_Base *out, o7_tag_t out_tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);

extern void VDataStream_InitIn(struct VDataStream_In *in_, VDataStream_ReadProc read, VDataStream_ReadCharsProc readChars);

extern int VDataStream_Read(struct VDataStream_In *in_, o7_tag_t in__tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);

extern int VDataStream_ReadChars(struct VDataStream_In *in_, o7_tag_t in__tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);

extern void VDataStream_InitOut(struct VDataStream_Out *out, VDataStream_WriteProc write, VDataStream_WriteCharsProc writeChars);

extern int VDataStream_Write(struct VDataStream_Out *out, o7_tag_t out_tag, int buf_len0, char unsigned buf[/*len0*/], int ofs, int count);

extern int VDataStream_WriteChars(struct VDataStream_Out *out, o7_tag_t out_tag, int buf_len0, o7_char buf[/*len0*/], int ofs, int count);

extern void VDataStream_init(void);
#endif
