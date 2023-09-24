#pragma comment(lib, "aic205.lib")
#include "aic205.h"

typedef struct
{
	int value;
} QueueElementType;

Boolean SearchQ(Queue*, QueueElementType);
Boolean traverseQ(QueueElementType*);

int main(void)
{
	Queue* Q1 = newQueue(sizeof(QueueElementType));
	QueueElementType i;
	setTraverse_Queue(traverseQ);

	for (i.value = 3; i.value < 100; i.value += 3)
		Q1->Add(&i);

	Q1->Traverse();

	printf("Give the search value: ");
	scanf("%d", &(i.value)); getchar();
#ifdef CMD_INPUT
	printf("%d\n", i.value);
#endif
	printf("%sFound\n", SearchQ(Q1, i) ? "" : "Not ");

	Q1->Traverse();

	return(0);
}

Boolean SearchQ(Queue* Queue, QueueElementType item)
{
	QueueElementType Sample;
	Boolean outcome = False;

	while (!Queue->isEmpty())
	{
		Sample = *((QueueElementType*)(Queue->Remove()));
		if ((outcome = (Boolean)(item.value == Sample.value)))
			return(outcome);
	}
	return(outcome);
}

Boolean traverseQ(QueueElementType* element)
{
	printf("%d ", element->value);
	return(True);
}