#include "LinkedList_internal.h"
#define DEBUG_LL_ISEMPTY

internal Boolean isEmpty_internal(_LinkedList* ll)
{
	return (ll->LLPointer == NilValue);
}

#define ISEMPTY_METHOD_IMPL(instance) \
Boolean _isEmpty_LinkedList_##instance(_LinkedList* targ) \
{ METHOD_INIT_ZERO(_LinkedList); return(isEmpty_internal(obj)); }

#ifdef DEBUG_LL_ISEMPTY
Boolean _isEmpty_LinkedList_01(_LinkedList* targ)
{
	METHOD_INIT_ZERO(_LinkedList);
	return(isEmpty_internal(obj));
}
#else
ISEMPTY_METHOD_IMPL(01)
#endif
ISEMPTY_METHOD_IMPL(02)
ISEMPTY_METHOD_IMPL(03)
ISEMPTY_METHOD_IMPL(04)
ISEMPTY_METHOD_IMPL(05)
ISEMPTY_METHOD_IMPL(06)

#undef ISEMPTY_METHOD_IMPL