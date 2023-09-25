#include "LinkedList_internal.h"
#define DEBUG_LL_INSERT

static int GetNode_internal(LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int res = ((LinkedList_*)ll)->FreePtr;

	if (!(ll->isFull()))
		((LinkedList_*)ll)->FreePtr = *((int*)(spec->Memory + ((spec->per_elem_size +
			sizeof(int)) * ((LinkedList_*)ll)->FreePtr)));

	return(res);
}

static void Insert_internal(void* item, int PredPtr, LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int TempPtr = GetNode_internal(ll);
	int step = spec->per_elem_size + sizeof(int);
	char* ptr = spec->Memory;
	char* ptr2 = ptr;

	if (TempPtr != NilValue)
	{
		if (PredPtr == NilValue)
		{
			ptr = (spec->Memory + (step * TempPtr));
			*(((int*)ptr)++) = ((LinkedList_*)ll)->LLPointer;
			memcpy(ptr, item, spec->per_elem_size);
			((LinkedList_*)ll)->LLPointer = TempPtr;
		}
		else
		{
			ptr  = (spec->Memory + (step * TempPtr)); // 5
			ptr2 = (spec->Memory + (step * PredPtr)); // 2

			*((int*)ptr) = *((int*)ptr2);
			ptr = (((int*)ptr) + 1);
			memcpy(ptr, item, spec->per_elem_size);
			*((int*)ptr2)  = TempPtr;
		}
	}
	else
		puts("Full List..\n");
}

#define INSERT_METHOD_IMPL(instance) \
void _Insert_LinkedList_##instance(void* item, int PredPtr, LinkedList* targ) \
{ METHOD_INIT(LinkedList); Insert_internal(item, PredPtr, obj); }

#ifdef DEBUG_LL_INSERT
void _Insert_LinkedList_01(void* item, int PredPtr, LinkedList* targ)
{
	METHOD_INIT(LinkedList);
	Insert_internal(item, PredPtr, obj);
}
#else
INSERT_METHOD_IMPL(01)
#endif
INSERT_METHOD_IMPL(02)
INSERT_METHOD_IMPL(03)
INSERT_METHOD_IMPL(04)
INSERT_METHOD_IMPL(05)
INSERT_METHOD_IMPL(06)

#undef INSERT_METHOD_IMPL
