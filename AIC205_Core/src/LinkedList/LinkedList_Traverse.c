#include "LinkedList_internal.h"
#define DEBUG_LL_TRAVERSE

static Boolean Traverse_Default(int CurrPtr, void* Data, int Next)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		" using the \'setTraverse_LinkedList\' function.");
	return(False);
}

static Boolean(*printFnc)(int, void*, int) = Traverse_Default;

void setTraverse_LinkedList(Boolean(*newFunc)(int, void*, int))
{
	printFnc = newFunc;
}

static Boolean protectedTraverse(int CurrPtr, void* Data, int Next, size_t size)
{
	if (CurrPtr == Next) return(False);
	if (Next > (int)(TOTAL_ELEMENT_ARRAY_BYTES / size)) return(False);
	return(printFnc(CurrPtr, Data, Next));
}

static void Traverse_internal(LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int   CurrPtr = ((LinkedList_*)ll)->LLPointer;
	int   step    = spec->per_elem_size + sizeof(int);
	int   Next;
	void* Data;
	char* ptr;

	if (!(ll->isEmpty()))
	{
		while (CurrPtr != NilValue)
		{
			ptr  = (spec->Memory + (step * CurrPtr));
			Next = *(((int*)ptr)++);
			Data = (void*)ptr;
			if (!protectedTraverse(CurrPtr, Data, Next, (spec->per_elem_size + sizeof(int))))
				break;
			CurrPtr = Next;

		}
		puts("");
	}
	else puts("Empty List..");
}

#define TRAVERSE_METHOD_IMPL(instance) \
void _Traverse_LinkedList_##instance(LinkedList* targ) \
{ METHOD_INIT(LinkedList); Traverse_internal(obj); }

#ifdef DEBUG_LL_TRAVERSE
void _Traverse_LinkedList_01(LinkedList* targ)
{
	METHOD_INIT(LinkedList);
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