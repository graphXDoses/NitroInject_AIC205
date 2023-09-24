#pragma comment(lib, "aic205.lib")
#include "aic205.h"

typedef struct
{
	float value;
} StackElementType;

typedef Queue QueueType;

void ReverseQ(QueueType*);
Boolean traverseQueue(StackElementType*);

int main(void)
{
	QueueType Q1 = *(newQueue(sizeof(StackElementType)));
	StackElementType i;
	setTraverse_Queue(traverseQueue);

	for (i.value = 0.0f; i.value <= 10.0f; i.value += 0.5f)
		Q1.Add(&i);

	Q1.Traverse();
	ReverseQ(&Q1);
	Q1.Traverse();

	return(0);
}

void ReverseQ(QueueType* q)
{
	Stack S1 = *(newStack(sizeof(StackElementType)));

	while (!(q->isEmpty()))
	{
		S1.Push(q->Remove());
	}

	while (!(S1.isEmpty()))
	{
		q->Add(S1.Pop());
	}
}

Boolean traverseQueue(StackElementType* flt)
{
	printf("%.2f ", flt->value);
	return(True);
}