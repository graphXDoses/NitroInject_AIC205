#include "LinkedList_internal.h"
#define DEBUG_LL_DELETE

internal void ReleaseNode_internal(_LinkedList* ll, int TempPtr)
{
    ElementSpecification* spec = (ElementSpecification*)ll;
    int step = spec->per_elem_size + sizeof(int);
    char* ptr = spec->Memory;
    
    *((int*)(&(ptr[(step * TempPtr)]))) = ll->FreePtr;
    ll->FreePtr = TempPtr;
}

internal void* Delete_internal(int ref, _LinkedList* ll)
{
    ElementSpecification* spec = (ElementSpecification*)ll;
    int TempPtr;
    //int PredPtr = ((LinkedList_*)ll)->PredPtr;
    int step = spec->per_elem_size + sizeof(int);
    char* ptr = spec->Memory;
    char* ptr2 = ptr;

    if (!(ll->Public.isEmpty()))
    {
        if (ref == NilValue)
        {
            TempPtr = ll->LLPointer;
            ll->LLPointer = *((int*)(&(ptr[(step * TempPtr)])));
        }
        else
        {
            ref = ref < 1 ? 0 : ref;
            TempPtr = *((int*)(&(ptr[(step * (ref + 1))])));
            *((int*)(&(ptr[(step * (ref + 1))]))) = *((int*)(&(ptr[(step * TempPtr)])));
        }
        ReleaseNode_internal(ll, TempPtr);
        ptr2 = ((int*)(&(ptr[(step * TempPtr)]))) + 1;
    }
    else
    {
        puts("Empty List..");
        return(NULL);
    }

    return(ptr2);
}

#define DELETE_METHOD_IMPL(instance) \
void* _Delete_LinkedList_##instance(int ref, _LinkedList* targ) \
{ METHOD_INIT_ZERO(_LinkedList); return(Delete_internal(ref, obj)); }

#ifdef DEBUG_LL_DELETE
void* _Delete_LinkedList_01(int ref, _LinkedList* targ)
{
	METHOD_INIT_ZERO(_LinkedList);
	return(Delete_internal(ref, obj));
}
#else
ISEMPTY_METHOD_IMPL(01)
#endif
DELETE_METHOD_IMPL(02)
DELETE_METHOD_IMPL(03)
DELETE_METHOD_IMPL(04)
DELETE_METHOD_IMPL(05)
DELETE_METHOD_IMPL(06)

#undef DELETE_METHOD_IMPL