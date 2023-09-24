#if !defined(STACK_INTERNAL_H)
#define STACK_INTERNAL_H

#include "aic205.h"
#include "method_utils.h"

METHOD_DECL(void, Push_Stack, void*, Stack*)
METHOD_DECL(void*, Pop_Stack, Stack*)
METHOD_DECL(Boolean, isFull_Stack, Stack*)
METHOD_DECL(Boolean, isEmpty_Stack, Stack*)
METHOD_DECL(void, Traverse_Stack, Stack*)

#endif