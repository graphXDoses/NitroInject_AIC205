#include "Stack_internal.h"
#define DEBUG_PUSH

static void push_internal(void* item, _Stack* s)
{
    ElementSpecification* spec = (ElementSpecification*)s;
    s->Top++;
    char* ptr = &(spec->Memory[s->Top * spec->per_elem_size]);

    memcpy(ptr, item, spec->per_elem_size);
}

#define PUSH_METHOD_IMPL(instance) \
void _Push_Stack_##instance(void* item, _Stack* targ) { METHOD_INIT(_Stack); push_internal(item, obj); }

#ifdef DEBUG_PUSH
void _Push_Stack_01(void* item, _Stack* targ)
{ 
    METHOD_INIT(_Stack)
    push_internal(item, obj);
}
#else
PUSH_METHOD_IMPL(01)
#endif
PUSH_METHOD_IMPL(02)
PUSH_METHOD_IMPL(03)
PUSH_METHOD_IMPL(04)
PUSH_METHOD_IMPL(05)
PUSH_METHOD_IMPL(06)

#undef PUSH_METHOD_IMPL