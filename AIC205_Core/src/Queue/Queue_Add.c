#include "Queue_internal.h"

#define DEBUG_QUEUE_ADD

static void add_internal(void* item, Queue* q)
{
	ElementSpecification* spec = (ElementSpecification*)q;
	char* ptr = spec->Memory + (q->Rear * spec->per_elem_size);
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (spec->per_elem_size);
	if (!(q->isFull()))
	{
		//q->Element[q->Rear] = val;
		memcpy(ptr, item, spec->per_elem_size);
		q->Rear = (q->Rear + 1) % max_q_elements;
	}
	else
		puts("Full Queue");
}

#define ADD_METHOD_IMPL(instance) \
void _Add_Queue_##instance(void* item, Queue* targ) \
{ METHOD_INIT(Queue); add_internal(item, obj); }

#ifdef DEBUG_QUEUE_ADD
void _Add_Queue_01(void* item, Queue* targ)
{
	METHOD_INIT(Queue);
	add_internal(item, obj);
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