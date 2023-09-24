#include "LinkedList_internal.h"
#define DEBUG_LL_DELETE

static void* Delete_internal(int ref, LinkedList* ll)
{
	return(NULL);
}

#define DELETE_METHOD_IMPL(instance) \
void* _Delete_LinkedList_##instance(int ref, LinkedList* targ) \
{ METHOD_INIT_ZERO(LinkedList); return(Delete_internal(ref, obj)); }

#ifdef DEBUG_LL_DELETE
void* _Delete_LinkedList_01(int ref, LinkedList* targ) \
{
	METHOD_INIT_ZERO(LinkedList);
	return(Delete_internal(ref, obj));
}
#else
ISEMPTY_METHOD_IMPL(01)
#endif
DELETE_METHOD_IMPL(02)
DELETE_METHOD_IMPL(03)
DELETE_METHOD_IMPL(04)
DELETE_METHOD_IMPL(05)
DELETE_METHOD_IMPL(06)

#undef DELETE_METHOD_IMPL