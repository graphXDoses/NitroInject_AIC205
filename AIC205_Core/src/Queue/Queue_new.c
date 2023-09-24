#include "Queue_internal.h"

Queue* newQueue(size_t size)
{
#define LOAD_FUNCPOOL(name) \
	name##_Queue_SIGN name##_Queue_##FuncPool[] = \
	{ \
		_##name##_Queue_01, \
		_##name##_Queue_02, \
		_##name##_Queue_03, \
		_##name##_Queue_04, \
		_##name##_Queue_05, \
		_##name##_Queue_06, \
	};

	LOAD_FUNCPOOL(isEmpty)
	LOAD_FUNCPOOL(isFull)
	LOAD_FUNCPOOL(Remove)
	LOAD_FUNCPOOL(Add)
	LOAD_FUNCPOOL(Traverse)

#undef LOAD_FUNCPOOL

	static Queue queue[MAX_DATASTRUCT_OBJECTS] = { 0 };
	static int i = 0;

	if (i >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%llu) Queues!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	((ElementSpecification*)(&queue[i]))->per_elem_size = size;

	// queue init stuff.
	queue[i].ID = i + 1;
	queue[i].Front = 0;
	queue[i].Rear  = 0;

#define THIS                             &(queue[i])
#define BIND_METHOD_TO_OBJECT(name, ...) \
	name##_Queue_##FuncPool[i](__VA_ARGS__); \
	queue[i].name = name##_Queue_##FuncPool[i];

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(isEmpty, THIS)
	BIND_METHOD_TO_OBJECT(isFull, THIS)
	BIND_METHOD_TO_OBJECT(Remove, THIS)
	BIND_METHOD_TO_OBJECT(Add, 0, THIS)
	BIND_METHOD_TO_OBJECT(Traverse, THIS)
#pragma warning(default : 4113)

#undef BIND_METHOD_TO_OBJECT
#undef THIS

		return(&(queue[i++]));
}