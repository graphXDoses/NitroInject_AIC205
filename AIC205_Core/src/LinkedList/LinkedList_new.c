#include "LinkedList_internal.h"

static void initializeStoragePool(LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int n, NumberOfNodes, step;
	step = spec->per_elem_size + sizeof(int);
	
	NumberOfNodes = TOTAL_ELEMENT_ARRAY_BYTES / step;
	for (n = 0; n < NumberOfNodes - 1; n++)
	{
		*((int*)(spec->Memory + (n * step))) = n + 1;
	}
	*((int*)(spec->Memory + ((NumberOfNodes - 1) * step))) = NilValue;
}

LinkedList* newLinkedList(size_t size)
{
#define LOAD_FUNCPOOL(name)              _LOAD_FUNCPOOL(LinkedList, name)
#define BIND_METHOD_TO_OBJECT(name, ...) _BIND_METHOD_TO_OBJECT(LinkedList, name, __VA_ARGS__)
	INIT_CTOR(LinkedList);

	LOAD_FUNCPOOL(isEmpty);
	LOAD_FUNCPOOL(isFull);
	LOAD_FUNCPOOL(Insert);
	LOAD_FUNCPOOL(Delete);
	LOAD_FUNCPOOL(Traverse);

	if (n >= MAX_DATASTRUCT_OBJECTS)
	{
		printf("Cannot create more than (%llu) LinkedLists!\n", MAX_DATASTRUCT_OBJECTS);
		return(NULL);
	}

	THIS._internal.per_elem_size = size;

	// LinkedList init stuff
	THIS.ID        = n + 1;
	THIS.FreePtr   = 0;
	THIS.PredPtr   = NilValue;
	THIS.LLPointer = NilValue;
	initializeStoragePool(&(THIS.Public));

#pragma warning(disable : 4113)
	BIND_METHOD_TO_OBJECT(isEmpty,  &THIS)
	BIND_METHOD_TO_OBJECT(isFull,   &THIS)
	BIND_METHOD_TO_OBJECT(Insert, 0, 0, &THIS)
	BIND_METHOD_TO_OBJECT(Delete, 0, &THIS)
	BIND_METHOD_TO_OBJECT(Traverse, &THIS)
#pragma warning(default : 4113)
#undef LOAD_FUNCPOOL
#undef BIND_METHOD_TO_OBJECT

	return(&(THIS.Public));

}