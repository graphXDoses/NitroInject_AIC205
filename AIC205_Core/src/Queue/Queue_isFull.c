#include "Queue_internal.h"
#pragma warning(disable : 4715)
#pragma warning(disable : 4033)

static Boolean isFull_internal(Queue* q)
{
	ElementSpecification* spec = (ElementSpecification*)q;
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (spec->per_elem_size);
	return ((q->Front) ==
		((q->Rear + 1) % max_q_elements));
}

#define ISFULL_METHOD_IMPL(instance) \
Boolean _isFull_Queue_##instance(Queue* targ) \
{ METHOD_INIT_ZERO(Queue); return(isFull_internal(obj)); }

ISFULL_METHOD_IMPL(01)
ISFULL_METHOD_IMPL(02)
ISFULL_METHOD_IMPL(03)
ISFULL_METHOD_IMPL(04)
ISFULL_METHOD_IMPL(05)
ISFULL_METHOD_IMPL(06)

#undef ISFULL_METHOD_IMPL

#pragma warning(default : 4715)
#pragma warning(default : 4033)