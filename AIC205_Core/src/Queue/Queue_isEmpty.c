#include "Queue_internal.h"
#pragma warning(disable : 4715)
#pragma warning(disable : 4033)
//#define DEBUG_QUEUE_ISEMPTY

static Boolean isEmpty_internal(_Queue* q)
{
	return (q->Front == q->Rear);
}

#define ISEMPTY_METHOD_IMPL(instance) \
Boolean _isEmpty_Queue_##instance(_Queue* targ) \
{ METHOD_INIT_ZERO(_Queue); return(isEmpty_internal(obj)); }

#ifdef DEBUG_QUEUE_ISEMPTY
Boolean _isEmpty_Queue_01(_Queue* targ)
{
	METHOD_INIT_ZERO(_Queue);
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

#pragma warning(default : 4715)
#pragma warning(default : 4033)