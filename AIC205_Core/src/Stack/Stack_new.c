#include "Stack_internal.h"

Stack* newStack(size_t size)
{
#define LOAD_FUNCPOOL(name) \
	name##_Stack_SIGN name##_Stack_##FuncPool[] = \
	{ \
		_##name##_Stack_01, \
		_##name##_Stack_02, \
		_##name##_Stack_03, \
		_##name##_Stack_04, \
		_##name##_Stack_05, \
		_##name##_Stack_06, \
	};

	LOAD_FUNCPOOL(Push)
	LOAD_FUNCPOOL(Pop)
	LOAD_FUNCPOOL(isFull)
	LOAD_FUNCPOOL(isEmpty)
	LOAD_FUNCPOOL(Traverse)

#undef LOAD_FUNCPOOL

	static Stack stack[MAX_DATASTRUCT_OBJECTS] = { 0 };
	static int i = 0;

	if (i >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%u) Stacks!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	((ElementSpecification*)(&stack[i]))->per_elem_size = size;

	stack[i].ID = i + 1;
	stack[i].Top = -1;

#define THIS                             &(stack[i])
#define BIND_METHOD_TO_OBJECT(name, ...) \
	name##_Stack_##FuncPool[i](__VA_ARGS__); \
	stack[i].name = name##_Stack_##FuncPool[i];

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(Push, 0, THIS)
	BIND_METHOD_TO_OBJECT(Pop, THIS)
	BIND_METHOD_TO_OBJECT(isFull, THIS)
	BIND_METHOD_TO_OBJECT(isEmpty, THIS)
	BIND_METHOD_TO_OBJECT(Traverse, THIS)
#pragma warning(default : 4113)

#undef BIND_METHOD_TO_OBJECT
#undef THIS

	return(&(stack[i++]));
}