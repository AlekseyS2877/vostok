#if !defined HEADER_GUARD_VDataStream
#    define  HEADER_GUARD_VDataStream 1

#include "V.h"

typedef struct VDataStream_RStream *VDataStream_Stream;
typedef struct VDataStream_RStream {
	V_Base _;
	void (*close)(struct V_Base *stream, o7_tag_t *stream_tag);
} VDataStream_RStream;
extern o7_tag_t VDataStream_RStream_tag;

extern void VDataStream_RStream_undef(struct VDataStream_RStream *r);

typedef struct VDataStream_In *VDataStream_PIn;
typedef struct VDataStream_In {
	VDataStream_RStream _;
	o7_int_t (*read)(struct V_Base *in_, o7_tag_t *in__tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);
	o7_int_t (*readChars)(struct V_Base *in_, o7_tag_t *in__tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);
} VDataStream_In;
#define VDataStream_In_tag VDataStream_RStream_tag

extern void VDataStream_In_undef(struct VDataStream_In *r);

typedef struct VDataStream_InOpener *VDataStream_PInOpener;
typedef struct VDataStream_InOpener {
	V_Base _;
	struct VDataStream_In *(*open)(struct V_Base *opener);
} VDataStream_InOpener;
#define VDataStream_InOpener_tag V_Base_tag

extern void VDataStream_InOpener_undef(struct VDataStream_InOpener *r);
typedef struct VDataStream_Out *VDataStream_POut;
typedef struct VDataStream_Out {
	VDataStream_RStream _;
	o7_int_t (*write)(struct V_Base *out, o7_tag_t *out_tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);
	o7_int_t (*writeChars)(struct V_Base *out, o7_tag_t *out_tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);
} VDataStream_Out;
#define VDataStream_Out_tag VDataStream_RStream_tag

extern void VDataStream_Out_undef(struct VDataStream_Out *r);

typedef struct VDataStream_OutOpener *VDataStream_POutOpener;
typedef struct VDataStream_OutOpener {
	V_Base _;
	struct VDataStream_Out *(*open)(struct V_Base *opener);
} VDataStream_OutOpener;
#define VDataStream_OutOpener_tag V_Base_tag

extern void VDataStream_OutOpener_undef(struct VDataStream_OutOpener *r);

typedef o7_int_t (*VDataStream_ReadProc)(struct V_Base *in_, o7_tag_t *in__tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);
typedef o7_int_t (*VDataStream_ReadCharsProc)(struct V_Base *in_, o7_tag_t *in__tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);
typedef o7_int_t (*VDataStream_WriteProc)(struct V_Base *out, o7_tag_t *out_tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);
typedef o7_int_t (*VDataStream_WriteCharsProc)(struct V_Base *out, o7_tag_t *out_tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);

typedef struct VDataStream_In *(*VDataStream_OpenIn)(struct V_Base *opener);
typedef struct VDataStream_Out *(*VDataStream_OpenOut)(struct V_Base *opener);
typedef void (*VDataStream_CloseStream)(struct V_Base *stream, o7_tag_t *stream_tag);

extern void VDataStream_Close(struct VDataStream_RStream *stream);

extern void VDataStream_InitIn(struct VDataStream_In *in_, VDataStream_ReadProc read, VDataStream_ReadCharsProc readChars, VDataStream_CloseStream close);

extern void VDataStream_CloseIn(struct VDataStream_In **in_);

extern o7_int_t VDataStream_Read(struct VDataStream_In *in_, o7_tag_t *in__tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);

extern o7_int_t VDataStream_ReadChars(struct VDataStream_In *in_, o7_tag_t *in__tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);

extern void VDataStream_InitOut(struct VDataStream_Out *out, VDataStream_WriteProc write, VDataStream_WriteCharsProc writeChars, VDataStream_CloseStream close);

extern void VDataStream_CloseOut(struct VDataStream_Out **out);

extern o7_int_t VDataStream_Write(struct VDataStream_Out *out, o7_tag_t *out_tag, o7_int_t buf_len0, char unsigned buf[/*len0*/], o7_int_t ofs, o7_int_t count);

extern o7_int_t VDataStream_WriteChars(struct VDataStream_Out *out, o7_tag_t *out_tag, o7_int_t buf_len0, o7_char buf[/*len0*/], o7_int_t ofs, o7_int_t count);

extern void VDataStream_InitInOpener(struct VDataStream_InOpener *opener, VDataStream_OpenIn open);

extern void VDataStream_InitOutOpener(struct VDataStream_OutOpener *opener, VDataStream_OpenOut open);

extern void VDataStream_init(void);
#endif
