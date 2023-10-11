#include "Queue_internal.h"
//#define DEBUG_QUEUE_REMOVE

internal void* remove_internal(_Queue* q)
{
	ElementSpecification* spec = (ElementSpecification*)q;
	char* ptr = spec->Memory + (q->Front * spec->per_element_size);
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (spec->per_element_size);

	if (!(q->Public.isEmpty()))
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
void* _Remove_Queue_##instance(_Queue* targ) \
{ METHOD_INIT_ZERO(_Queue) return(remove_internal(obj)); }

#ifdef DEBUG_QUEUE_REMOVE
void* _Remove_Queue_01(_Queue* targ)
{
	METHOD_INIT_ZERO(_Queue);
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