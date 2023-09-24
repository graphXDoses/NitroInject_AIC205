#if !defined(QUEUE_INTERNAL_H)
#define QUEUE_INTERNAL_H

#include "aic205.h"
#include "method_utils.h"

METHOD_DECL(Boolean, isEmpty_Queue,  Queue*);
METHOD_DECL(Boolean, isFull_Queue,   Queue*);
METHOD_DECL(void*,   Remove_Queue,   Queue*);
METHOD_DECL(void,    Add_Queue,      void*, Queue*);
METHOD_DECL(void,    Traverse_Queue, Queue*);

#endif