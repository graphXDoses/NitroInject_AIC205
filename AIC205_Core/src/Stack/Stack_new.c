#include "Stack_internal.h"

Stack* newStack(size_t size)
{
#define LOAD_FUNCPOOL(name)              _LOAD_FUNCPOOL(Stack, name)
#define BIND_METHOD_TO_OBJECT(name, ...) _BIND_METHOD_TO_OBJECT(Stack, name, __VA_ARGS__)
	INIT_CTOR(Stack);

	LOAD_FUNCPOOL(Push);
	LOAD_FUNCPOOL(Pop);
	LOAD_FUNCPOOL(isFull);
	LOAD_FUNCPOOL(isEmpty);
	LOAD_FUNCPOOL(Traverse);


	if (n >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%u) Stacks!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	THIS._internal.per_element_size = size;

	THIS.ID  = n + 1;
	THIS.Top = -1;

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(Push, 0, &THIS)
	BIND_METHOD_TO_OBJECT(Pop, &THIS)
	BIND_METHOD_TO_OBJECT(isFull, &THIS)
	BIND_METHOD_TO_OBJECT(isEmpty, &THIS)
	BIND_METHOD_TO_OBJECT(Traverse, &THIS)
#pragma warning(default : 4113)
#undef LOAD_FUNCPOOL
#undef BIND_METHOD_TO_OBJECT

	return(&(THIS.Public));
}