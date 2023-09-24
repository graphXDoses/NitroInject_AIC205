#if !defined(AIC205_H)
#define AIC205_H

#include <stdio.h>
#include <string.h>

#pragma region Utils
#define BYTE_OFFSET(end, start) (((char*)end) - ((char*)start))
#define ITERRAY_BEGIN(a)        { void* q; int i; for(q = (void*)a, i=0; BYTE_OFFSET(q, a) < sizeof(a); ((char*)q)+=sizeof(a[0]), i++){
#define ITERRAY_END             }}

typedef enum { False, True } Boolean;
#define NilValue                -1

extern  void randomForceSeed(int);
extern  int  randomInt(void);
extern  int  randomIntFromTo(int, int);
#pragma endregion

#define TOTAL_ELEMENT_ARRAY_BYTES 512

typedef struct
{
	char   Memory[TOTAL_ELEMENT_ARRAY_BYTES];
	size_t per_elem_size;
} ElementSpecification;

#pragma region Stack
typedef struct
{
	ElementSpecification _internal;
	int ID, Top;
	// Methods
	void    (*Push)(void*);
	void*   (*Pop)(void);
	Boolean (*isFull)(void);
	Boolean (*isEmpty)(void);
	void    (*Traverse)(void);
} Stack;

extern Stack* newStack(size_t);
extern void setTraverse_Stack(Boolean (*)(void*));
#pragma endregion

#pragma region Queue
typedef struct
{
	ElementSpecification _internal;
	int ID, Front, Rear;
	// Methods
	Boolean (*isEmpty)(void);
	Boolean (*isFull)(void);
	void*   (*Remove)(void);
	void    (*Add)(void*);
	void    (*Traverse)(void);
} Queue;

extern Queue* newQueue(size_t);
extern void setTraverse_Queue(Boolean (*)(void*));
#pragma endregion

#pragma region LinkedList
typedef struct
{
	ElementSpecification _internal;
	int ID;
	// Methods
	void    (*Insert)(void*,int);
	void*   (*Delete)(int);
	int     (*GetNode)(void);
	Boolean (*isFull)(void);
	Boolean (*isEmpty)(void);
	void    (*Traverse)(void);
} LinkedList;

extern LinkedList* newLinkedList(size_t);
extern void setTraverse_LinkedList(Boolean(*)(int, void*, int));
#pragma endregion


#endif