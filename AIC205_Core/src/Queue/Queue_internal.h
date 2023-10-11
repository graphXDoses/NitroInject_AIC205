#if !defined(QUEUE_INTERNAL_H)
#define QUEUE_INTERNAL_H

#include "aic205.h"
#include "method_utils.h"
#include "element_specification.h"

typedef struct
{
	ElementSpecification _internal;
	Queue Public;
	int ID, Front, Rear;
} _Queue;

METHOD_DECL(Boolean, isEmpty_Queue,  _Queue*);
METHOD_DECL(Boolean, isFull_Queue,   _Queue*);
METHOD_DECL(void*,   Remove_Queue,   _Queue*);
METHOD_DECL(void,    Add_Queue,      void*, _Queue*);
METHOD_DECL(void,    Traverse_Queue, _Queue*);

#endif