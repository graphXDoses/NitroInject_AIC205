#include "Stack_internal.h"
#pragma warning(disable : 4715)
#pragma warning(disable : 4033)

internal Boolean isFull_internal(_Stack* s)
{
	ElementSpecification* spec = (ElementSpecification*)s;
	return (s->Top == ((TOTAL_ELEMENT_ARRAY_BYTES / spec->per_elem_size) - 1));
}

#define ISFULL_METHOD_IMPL(instance) \
Boolean _isFull_Stack_##instance(_Stack* targ) { METHOD_INIT_ZERO(_Stack); return(isFull_internal(obj)); }

ISFULL_METHOD_IMPL(01)
ISFULL_METHOD_IMPL(02)
ISFULL_METHOD_IMPL(03)
ISFULL_METHOD_IMPL(04)
ISFULL_METHOD_IMPL(05)
ISFULL_METHOD_IMPL(06)

#undef ISFULL_METHOD_IMPL

#pragma warning(default : 4715)
#pragma warning(default : 4033)