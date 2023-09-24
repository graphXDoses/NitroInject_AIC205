#include "Queue_internal.h"
//#define DEBUG_QUEUE_REMOVE

static void* remove_internal(Queue* q)
{
	ElementSpecification* spec = (ElementSpecification*)q;
	char* ptr = spec->Memory + (q->Front * spec->per_elem_size);
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (spec->per_elem_size);

	if (!(q->isEmpty()))
	{
		//*val = q->Element[q->Front];
		q->Front = (q->Front + 1) % max_q_elements;
		return(ptr);
	}
	else
	{
		puts("Empty Queue");
		return(NULL);
	}
}

#define REMOVE_METHOD_IMPL(instance) \
void* _Remove_Queue_##instance(Queue* targ) \
{ METHOD_INIT_ZERO(Queue) return(remove_internal(obj)); }

#ifdef DEBUG_QUEUE_REMOVE
void* _Remove_Queue_01(Queue* targ)
{
	METHOD_INIT_ZERO(Queue);
	remove_internal(obj);
}
#else
REMOVE_METHOD_IMPL(01)
#endif
REMOVE_METHOD_IMPL(02)
REMOVE_METHOD_IMPL(03)
REMOVE_METHOD_IMPL(04)
REMOVE_METHOD_IMPL(05)
REMOVE_METHOD_IMPL(06)

#undef REMOVE_METHOD_IMPL