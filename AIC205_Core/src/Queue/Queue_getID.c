#include "Queue_internal.h"

#define DEBUG_QUEUE_GETID

internal int getID_internal(_Queue* q)
{
	return(q->ID);
}

#define ADD_METHOD_IMPL(instance) \
int _getID_Queue_##instance(_Queue* targ) \
{ METHOD_INIT_ZERO(_Queue); return(getID_internal(obj)); }

#ifdef DEBUG_QUEUE_GETID
int _getID_Queue_01(_Queue* targ)
{
	METHOD_INIT_ZERO(_Queue);
	return(getID_internal(obj));
}
#else
ADD_METHOD_IMPL(01)
#endif
ADD_METHOD_IMPL(02)
ADD_METHOD_IMPL(03)
ADD_METHOD_IMPL(04)
ADD_METHOD_IMPL(05)
ADD_METHOD_IMPL(06)

#undef ADD_METHOD_IMPL