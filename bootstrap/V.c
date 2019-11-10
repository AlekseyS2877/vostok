#include <o7.h>

#include "V.h"

#define V_Message_tag o7_base_tag
extern void V_Message_undef(struct V_Message *r) {
}
#define V_Base_tag V_Message_tag
extern void V_Base_undef(struct V_Base *r) {
	V_Message_undef(&r->_);
	r->do_ = NULL;
}
#define V_Error_tag V_Base_tag
extern void V_Error_undef(struct V_Error *r) {
	V_Base_undef(&r->_);
}
#define V_MsgFinalize_tag V_Base_tag
extern void V_MsgFinalize_undef(struct V_MsgFinalize *r) {
	V_Base_undef(&r->_);
}
#define V_MsgNeedMemory_tag V_Base_tag
extern void V_MsgNeedMemory_undef(struct V_MsgNeedMemory *r) {
	V_Base_undef(&r->_);
}
#define V_MsgCopy_tag V_Base_tag
extern void V_MsgCopy_undef(struct V_MsgCopy *r) {
	V_Base_undef(&r->_);
	r->copy = NULL;
}
#define V_MsgLinks_tag V_Base_tag
extern void V_MsgLinks_undef(struct V_MsgLinks *r) {
	V_Base_undef(&r->_);
	r->diff = O7_INT_UNDEF;
	r->count = O7_INT_UNDEF;
}
#define V_MsgContentPass_tag V_Base_tag
extern void V_MsgContentPass_undef(struct V_MsgContentPass *r) {
	V_Base_undef(&r->_);
	r->id = O7_INT_UNDEF;
}
#define V_MsgHash_tag V_Base_tag
extern void V_MsgHash_undef(struct V_MsgHash *r) {
	V_Base_undef(&r->_);
	r->hash = O7_INT_UNDEF;
}

static o7_bool Nothing(struct V_Message *this_, struct V_Message *mes) {
	return (0 > 1);
}

extern void V_Init(struct V_Base *base) {
	(*base).do_ = Nothing;
}

extern void V_SetDo(struct V_Base *base, V_Handle do_) {
	O7_ASSERT((*base).do_ == Nothing);
	(*base).do_ = do_;
}

extern o7_bool V_Do(struct V_Base *handler, struct V_Message *message) {
	return (*handler).do_(&(*handler)._, &(*message));
}
