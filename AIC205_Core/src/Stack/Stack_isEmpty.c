#include "Stack_internal.h"
#pragma warning(disable : 4715)
#pragma warning(disable : 4033)

static Boolean isEmpty_internal(_Stack* s)
{
    return(s->Top == -1);
}

#define ISEMPTY_METHOD_IMPL(instance) \
Boolean _isEmpty_Stack_##instance(_Stack* targ) { METHOD_INIT_ZERO(_Stack); return(isEmpty_internal(obj)); }

ISEMPTY_METHOD_IMPL(01)
ISEMPTY_METHOD_IMPL(02)
ISEMPTY_METHOD_IMPL(03)
ISEMPTY_METHOD_IMPL(04)
ISEMPTY_METHOD_IMPL(05)
ISEMPTY_METHOD_IMPL(06)

#undef ISEMPTY_METHOD_IMPL

#pragma warning(default : 4715)
#pragma warning(default : 4033)