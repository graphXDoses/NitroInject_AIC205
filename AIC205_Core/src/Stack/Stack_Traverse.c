#include "Stack_internal.h"

internal Boolean Traverse_Default(void* s)
{
	puts("Please replace \'" __FUNCTION__ "\' with own prototype"
		 " using the \'setTraverse_Stack\' function.");
	return(False);
}

internal Boolean (*_traverseFuncPointer)(void*) = Traverse_Default;

void setTraverse_Stack(Boolean (*newFunc)(void*))
{
	_traverseFuncPointer = newFunc;
}

internal void traverseStack_internal(_Stack* s)
{
	int n;
	ElementSpecification* spec = (ElementSpecification*)s;
	char* Sample = spec->Memory;
	printf("Stack#%d has (%d) elements.\n", s->ID, s->Top + 1);
	for (n = 0; n <= s->Top; n++) {
		if (!_traverseFuncPointer(Sample))
			return;
		Sample += spec->per_element_size;
	}
	puts("");
}

#define TRAVERSE_METHOD_IMPL(instance) \
void _Traverse_Stack_##instance(_Stack* targ) \
{ METHOD_INIT(_Stack); traverseStack_internal(obj); }

TRAVERSE_METHOD_IMPL(01)
TRAVERSE_METHOD_IMPL(02)
TRAVERSE_METHOD_IMPL(03)
TRAVERSE_METHOD_IMPL(04)
TRAVERSE_METHOD_IMPL(05)
TRAVERSE_METHOD_IMPL(06)

#undef TRAVERSE_METHOD_IMPL