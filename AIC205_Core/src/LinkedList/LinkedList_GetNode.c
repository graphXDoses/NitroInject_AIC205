#include "LinkedList_internal.h"
#define DEBUG_LL_GETNODE

static int GetNode_internal(LinkedList* ll)
{
	ElementSpecification* spec = (ElementSpecification*)ll;
	int res = ((LinkedList_*)ll)->FreePtr;
	
	//((LinkedList_*)ll)->LLPointer = ((LinkedList_*)ll)->FreePtr;
	if (!(ll->isFull()))
		((LinkedList_*)ll)->FreePtr = *((int*)(spec->Memory + ((spec->per_elem_size +
			sizeof(int)) * ((LinkedList_*)ll)->FreePtr)));
	
	return(res);
}

#define GETNODE_METHOD_IMPL(instance) \
int _GetNode_LinkedList_##instance(LinkedList* targ) \
{ METHOD_INIT_ZERO(LinkedList); return(GetNode_internal(obj)); }

#ifdef DEBUG_LL_GETNODE
int _GetNode_LinkedList_01(LinkedList* targ)
{
	METHOD_INIT_ZERO(LinkedList);
	return(GetNode_internal(obj));
}
#else
GETNODE_METHOD_IMPL(01)
#endif
GETNODE_METHOD_IMPL(02)
GETNODE_METHOD_IMPL(03)
GETNODE_METHOD_IMPL(04)
GETNODE_METHOD_IMPL(05)
GETNODE_METHOD_IMPL(06)

#undef GETNODE_METHOD_IMPL