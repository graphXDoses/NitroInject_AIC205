#include "Queue_internal.h"

internal Boolean Traverse_Default(void* s)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		" using the \'setTraverse_Queue\' function.");
	return(False);
}

internal Boolean (*_traverseFuncPointer)(void*) = Traverse_Default;

void setTraverse_Queue(Boolean (*newFunc)(void*))
{
	_traverseFuncPointer = newFunc;
}

internal void traverseQueue_internal(_Queue* q)
{
	int current;
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (q->_internal.per_elem_size);
	char* Sample = q->_internal.Memory;
	if (!(q->Public.isEmpty()))
	{
		current = q->Front;
		while (current != q->Rear) {
			Sample = ((q->_internal.per_elem_size) * current) + (q->_internal.Memory);
			if (!_traverseFuncPointer(Sample))
				return;
			current = (current + 1) % max_q_elements;
		}
	}
	puts("");
}

#define TRAVERSE_METHOD_IMPL(instance) \
void _Traverse_Queue_##instance(_Queue* targ) \
{ METHOD_INIT(_Queue); traverseQueue_internal(obj); }

TRAVERSE_METHOD_IMPL(01)
TRAVERSE_METHOD_IMPL(02)
TRAVERSE_METHOD_IMPL(03)
TRAVERSE_METHOD_IMPL(04)
TRAVERSE_METHOD_IMPL(05)
TRAVERSE_METHOD_IMPL(06)

#undef TRAVERSE_METHOD_IMPL