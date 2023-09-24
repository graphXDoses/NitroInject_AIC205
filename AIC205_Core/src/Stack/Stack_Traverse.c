#include "Stack_internal.h"

static Boolean Traverse_Default(void* s)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		 " using the \'setTraverse_Stack\' function.");
	return(False);
}

static Boolean (*_traverseFuncPointer)(void*) = Traverse_Default;

void setTraverse_Stack(Boolean (*newFunc)(void*))
{
	_traverseFuncPointer = newFunc;
}

static void traverseStack_internal(Stack* s)
{
	int i;
	ElementSpecification* spec = (ElementSpecification*)s;
	char* Sample = spec->Memory;
	printf("Stack#%d has (%d) elements.\n", s->ID, s->Top + 1);
	for (i = 0; i <= s->Top; i++) {
		if (!_traverseFuncPointer(Sample))
			return;
		Sample += spec->per_elem_size;
	}
	puts("");
}

#define TRAVERSE_METHOD_IMPL(instance) \
void _Traverse_Stack_##instance(Stack* targ) \
{ METHOD_INIT(Stack); traverseStack_internal(obj); }

TRAVERSE_METHOD_IMPL(01)
TRAVERSE_METHOD_IMPL(02)
TRAVERSE_METHOD_IMPL(03)
TRAVERSE_METHOD_IMPL(04)
TRAVERSE_METHOD_IMPL(05)
TRAVERSE_METHOD_IMPL(06)

#undef TRAVERSE_METHOD_IMPL