#include "Stack_internal.h"
#pragma warning(disable : 4715)
#pragma warning(disable : 4033)

internal void* pop_internal(_Stack* s)
{
	ElementSpecification* spec = (ElementSpecification*)s;
	char* ptr = &(spec->Memory[s->Top-- * spec->per_element_size]);
	return((void*)ptr);
}

#define POP_METHOD_IMPL(instance) \
void* _Pop_Stack_##instance(_Stack* targ) { METHOD_INIT_ZERO(_Stack); return(pop_internal(obj)); }

POP_METHOD_IMPL(01)
POP_METHOD_IMPL(02)
POP_METHOD_IMPL(03)
POP_METHOD_IMPL(04)
POP_METHOD_IMPL(05)
POP_METHOD_IMPL(06)

#undef POP_METHOD_IMPL

#pragma warning(default : 4715)
#pragma warning(default : 4033)