#include "LinkedList_internal.h"

static void initializeStoragePool(LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int i, NumberOfNodes, step;
	step = spec->per_elem_size + sizeof(int);
	
	NumberOfNodes = TOTAL_ELEMENT_ARRAY_BYTES / step;
	for (i = 0; i < NumberOfNodes - 1; i++)
	{
		*((int*)(spec->Memory + (i * step))) = i + 1;
	}
	*((int*)(spec->Memory + ((NumberOfNodes - 1) * step))) = NilValue;
}

LinkedList* newLinkedList(size_t size)
{
#define LOAD_FUNCPOOL(name) \
	name##_LinkedList_SIGN name##_LinkedList_##FuncPool[] = \
	{ \
		_##name##_LinkedList_01, \
		_##name##_LinkedList_02, \
		_##name##_LinkedList_03, \
		_##name##_LinkedList_04, \
		_##name##_LinkedList_05, \
		_##name##_LinkedList_06  \
	};

	LOAD_FUNCPOOL(Insert)
	LOAD_FUNCPOOL(Delete)
	LOAD_FUNCPOOL(GetNode)
	LOAD_FUNCPOOL(isFull)
	LOAD_FUNCPOOL(isEmpty)
	LOAD_FUNCPOOL(Traverse)

#undef LOAD_FUNCPOOL

	static LinkedList_ ll[MAX_DATASTRUCT_OBJECTS] = {0};
	static int i = 0;

	if (i >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%llu) LinkedLists!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	((ElementSpecification*)(&ll[i]))->per_elem_size = size;

	// LinkedList init stuff
	ll[i].public.ID = i + 1;
	ll[i].FreePtr   = 0;
	ll[i].PredPtr   = NilValue;
	ll[i].LLPointer = NilValue;
	initializeStoragePool(&(ll[i]));

#define THIS                        ((LinkedList*)(&ll[i]))
#define BIND_METHOD_TO_OBJECT(name, ...) \
	name##_LinkedList_##FuncPool[i](__VA_ARGS__); \
	THIS->name = name##_LinkedList_##FuncPool[i];

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(Insert, 0, 0, THIS)
	BIND_METHOD_TO_OBJECT(Delete, 0, THIS)
	BIND_METHOD_TO_OBJECT(GetNode,  THIS)
	BIND_METHOD_TO_OBJECT(isFull,   THIS)
	BIND_METHOD_TO_OBJECT(isEmpty,  THIS)
	BIND_METHOD_TO_OBJECT(Traverse, THIS)
#pragma warning(default : 4113)

#undef BIND_METHOD_TO_OBJECT
#undef THIS

	return(&(ll[i++]));

}