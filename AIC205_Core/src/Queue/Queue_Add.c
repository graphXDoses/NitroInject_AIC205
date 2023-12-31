#include "Queue_internal.h"

#define DEBUG_QUEUE_ADD

internal void add_internal(void* item, _Queue* q)
{
	ElementSpecification* spec = (ElementSpecification*)q;
	char* ptr = spec->Memory + (q->Rear * spec->per_element_size);
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (spec->per_element_size);
	if (!(q->Public.isFull()))
	{
		memcpy(ptr, item, spec->per_element_size);
		q->Rear = (q->Rear + 1) % max_q_elements;
	}
	else
		puts("Full Queue");
}

#define ADD_METHOD_IMPL(instance) \
void _Add_Queue_##instance(void* item, _Queue* targ) \
{ METHOD_INIT(_Queue); add_internal(item, obj); }

#ifdef DEBUG_QUEUE_ADD
void _Add_Queue_01(void* item, _Queue* targ)
{
	METHOD_INIT(_Queue);
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