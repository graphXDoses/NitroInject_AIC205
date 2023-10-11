#include "LinkedList_internal.h"
#define DEBUG_LL_TRAVERSE

internal Boolean Traverse_Default(int CurrPtr, void* Data, int Next)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		" using the \'setTraverse_LinkedList\' function.");
	return(False);
}

internal Boolean(*printFnc)(int, void*, int) = Traverse_Default;

void setTraverse_LinkedList(Boolean(*newFunc)(int, void*, int))
{
	printFnc = newFunc;
}

internal Boolean protectedTraverse(int CurrPtr, void* Data, int Next, size_t size)
{
	if (CurrPtr == Next) return(False);
	if (Next > (int)(TOTAL_ELEMENT_ARRAY_BYTES / size)) return(False);
	return(printFnc(CurrPtr, Data, Next));
}

internal void Traverse_internal(_LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int   CurrPtr = ll->LLPointer;
	int   step    = spec->per_element_size + sizeof(int);
	int   Next;
	void* Data;
	char* ptr;

	if (!(ll->Public.isEmpty()))
	{
		while (CurrPtr != NilValue)
		{
			ptr  = (spec->Memory + (step * CurrPtr));
			Next = *(((int*)ptr)++);
			Data = (void*)ptr;
			if (!protectedTraverse(CurrPtr, Data, Next, (spec->per_element_size + sizeof(int))))
				break;
			CurrPtr = Next;

		}
		puts("");
	}
	else puts("Empty List..");
}

#define TRAVERSE_METHOD_IMPL(instance) \
void _Traverse_LinkedList_##instance(_LinkedList* targ) \
{ METHOD_INIT(_LinkedList); Traverse_internal(obj); }

#ifdef DEBUG_LL_TRAVERSE
void _Traverse_LinkedList_01(_LinkedList* targ)
{
	METHOD_INIT(_LinkedList);
	Traverse_internal(obj);
}
#else
TRAVERSE_METHOD_IMPL(01)
#endif
TRAVERSE_METHOD_IMPL(02)
TRAVERSE_METHOD_IMPL(03)
TRAVERSE_METHOD_IMPL(04)
TRAVERSE_METHOD_IMPL(05)
TRAVERSE_METHOD_IMPL(06)

#undef TRAVERSE_METHOD_IMPL