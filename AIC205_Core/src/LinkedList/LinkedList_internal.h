#if !defined(LINKEDLIST_INTERNAL_H)
#define LINKEDLIST_INTERNAL_H

#include "method_utils.h"
#include "aic205.h"

typedef struct
{
	LinkedList public;
	// Privates
	int LLPointer, FreePtr, PredPtr;
} LinkedList_;

METHOD_DECL(void,    Insert_LinkedList,   void*, int, LinkedList*);
METHOD_DECL(void*,   Delete_LinkedList,   int,   LinkedList*);
METHOD_DECL(Boolean, isFull_LinkedList,   LinkedList*);
METHOD_DECL(Boolean, isEmpty_LinkedList,  LinkedList*);
METHOD_DECL(void,    Traverse_LinkedList, LinkedList*);

#endif