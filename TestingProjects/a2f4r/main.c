#pragma comment(lib, "aic205.lib")
#include "aic205.h"

typedef struct
{
	int value;
} ListElementType;

Boolean traverseLL(int CurrPtr, ListElementType* Data, int Next)
{
	printf(
		"[@%d|%d]%s"
		,
		CurrPtr, Data->value,
		Next == NilValue ? "" : "-->"
	);
	return(True);
}

int main(void)
{
	LinkedList* LL = newLinkedList(sizeof(ListElementType));
	int j, num[6] =  { 8,3,2,5,2,7 };

	setTraverse_LinkedList(traverseLL);
	ITERRAY_BEGIN(num)
		LL->Insert(&(num[i]), -1);
	ITERRAY_END;

	LL->Traverse();

	j = *((int*)(LL->Delete(2)));

	printf("Min was %d\n\n", j);

	LL->Traverse();
	
	return(0);
}