#if !defined(LINKEDLIST_INTERNAL_H)
#define LINKEDLIST_INTERNAL_H

#include "method_utils.h"
#include "aic205.h"
#include "element_specification.h"

typedef struct
{
	ElementSpecification _internal;
	LinkedList Public;
	// Privates
	int ID, LLPointer, FreePtr, PredPtr;
} _LinkedList;

METHOD_DECL(void,    Insert_LinkedList,   void*, int, _LinkedList*);
METHOD_DECL(void*,   Delete_LinkedList,   int,   _LinkedList*);
METHOD_DECL(Boolean, isFull_LinkedList,   _LinkedList*);
METHOD_DECL(Boolean, isEmpty_LinkedList,  _LinkedList*);
METHOD_DECL(void,    Traverse_LinkedList, _LinkedList*);

#endif