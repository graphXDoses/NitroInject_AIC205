#include "Queue_internal.h"

Queue* newQueue(size_t size)
{
#define LOAD_FUNCPOOL(name)              _LOAD_FUNCPOOL(Queue, name)
#define BIND_METHOD_TO_OBJECT(name, ...) _BIND_METHOD_TO_OBJECT(Queue, name, __VA_ARGS__)
	INIT_CTOR(Queue);

	LOAD_FUNCPOOL(isEmpty);
	LOAD_FUNCPOOL(isFull);
	LOAD_FUNCPOOL(Remove);
	LOAD_FUNCPOOL(Add);
	LOAD_FUNCPOOL(Traverse);

	if (n >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%llu) Queues!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	THIS._internal.per_elem_size = size;

	// queue init stuff.
	THIS.ID    = n + 1;
	THIS.Front = 0;
	THIS.Rear  = 0;

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(isEmpty, &THIS)
	BIND_METHOD_TO_OBJECT(isFull, &THIS)
	BIND_METHOD_TO_OBJECT(Remove, &THIS)
	BIND_METHOD_TO_OBJECT(Add, 0, &THIS)
	BIND_METHOD_TO_OBJECT(Traverse, &THIS)
#pragma warning(default : 4113)
#undef LOAD_FUNCPOOL
#undef BIND_METHOD_TO_OBJECT

		return(&(THIS.Public));
}