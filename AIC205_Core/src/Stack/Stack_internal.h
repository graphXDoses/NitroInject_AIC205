#if !defined(STACK_INTERNAL_H)
#define STACK_INTERNAL_H

#include "aic205.h"
#include "method_utils.h"
#include "element_specification.h"

typedef struct
{
	ElementSpecification _internal;
	Stack Public;
	int ID, Top;
} _Stack;

METHOD_DECL(void, Push_Stack, void*, _Stack*)
METHOD_DECL(void*, Pop_Stack, _Stack*)
METHOD_DECL(Boolean, isFull_Stack, _Stack*)
METHOD_DECL(Boolean, isEmpty_Stack, _Stack*)
METHOD_DECL(void, Traverse_Stack, _Stack*)

#endif