#include "LinkedList_internal.h"
#define DEBUG_LL_ISFULL

static Boolean isFull_internal(LinkedList* ll)
{
	LinkedList_* _this = (LinkedList_*)ll;
	return (_this->FreePtr == NilValue);
}

#define ISFULL_METHOD_IMPL(instance) \
Boolean _isFull_LinkedList_##instance(LinkedList* targ) \
{ METHOD_INIT_ZERO(LinkedList); return(isFull_internal(obj)); }

#ifdef DEBUG_LL_ISFULL
Boolean _isFull_LinkedList_01(LinkedList* targ)
{
	METHOD_INIT_ZERO(LinkedList);
	return(isFull_internal(obj));
}
#else
ISFULL_METHOD_IMPL(01)
#endif
ISFULL_METHOD_IMPL(02)
ISFULL_METHOD_IMPL(03)
ISFULL_METHOD_IMPL(04)
ISFULL_METHOD_IMPL(05)
ISFULL_METHOD_IMPL(06)

#undef ISFULL_METHOD_IMPL