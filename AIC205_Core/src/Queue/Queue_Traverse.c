#include "Queue_internal.h"

/*
int current;
if (!(s->isEmpty()))
{
	current = s->Front;
	while (current != s->Rear) {
		printf("%d ", s->Element[current]);
		current = (current + 1) % MAX_QUEUE_ELEMENTS;
	}
		printf("\n");
}
*/

static Boolean Traverse_Default(void* s)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		" using the \'setTraverse_Queue\' function.");
	return(False);
}

static Boolean (*_traverseFuncPointer)(void*) = Traverse_Default;

void setTraverse_Queue(Boolean (*newFunc)(void*))
{
	_traverseFuncPointer = newFunc;
}

static void traverseQueue_internal(Queue* q)
{
	int current;
	int max_q_elements = TOTAL_ELEMENT_ARRAY_BYTES / (q->_internal.per_elem_size);
	char* Sample = q->_internal.Memory;
	if (!(q->isEmpty()))
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
void _Traverse_Queue_##instance(Queue* targ) \
{ METHOD_INIT(Queue); traverseQueue_internal(obj); }

TRAVERSE_METHOD_IMPL(01)
TRAVERSE_METHOD_IMPL(02)
TRAVERSE_METHOD_IMPL(03)
TRAVERSE_METHOD_IMPL(04)
TRAVERSE_METHOD_IMPL(05)
TRAVERSE_METHOD_IMPL(06)

#undef TRAVERSE_METHOD_IMPL