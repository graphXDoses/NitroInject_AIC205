#include "LinkedList_internal.h"
#define DEBUG_LL_ISFULL

static Boolean isFull_internal(_LinkedList* ll)
{
	return (ll->FreePtr == NilValue);
}

#define ISFULL_METHOD_IMPL(instance) \
Boolean _isFull_LinkedList_##instance(_LinkedList* targ) \
{ METHOD_INIT_ZERO(_LinkedList); return(isFull_internal(obj)); }

#ifdef DEBUG_LL_ISFULL
Boolean _isFull_LinkedList_01(_LinkedList* targ)
{
	METHOD_INIT_ZERO(_LinkedList);
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