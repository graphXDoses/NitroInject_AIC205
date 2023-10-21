#pragma comment(lib, "aic205.lib")
#include "aic205.h"

typedef struct {
    int          id;
    int          start;
    int          end;
    unsigned int arrival_time;
    unsigned int stay_time;
} QueueElementType;

typedef Queue QueueType;

Boolean    TraverseQueue(QueueElementType*);
void       DisplayStatusQueue(QueueType*);
void       AppendCustomersInWaitingQueue(QueueType*);
QueueType  TimesInQueue(QueueType*);

int main(void)
{
    QueueType Waiting_Queue = *(newQueue(sizeof(QueueElementType)));
    QueueType Service_Queue;
    setTraverse_Queue(TraverseQueue);

    AppendCustomersInWaitingQueue(&Waiting_Queue);
    DisplayStatusQueue(&Waiting_Queue);
    Waiting_Queue.Traverse();

    Service_Queue = TimesInQueue(&Waiting_Queue);
    DisplayStatusQueue(&Waiting_Queue);
    Waiting_Queue.Traverse();
    DisplayStatusQueue(&Service_Queue);
    Service_Queue.Traverse();

    return(0);
}

Boolean TraverseQueue(QueueElementType* clientInfo)
{
    printf(
        "%-7s%-18d%-8d%-8d%-8u%-5u\n",
        "Client", clientInfo->id, clientInfo->start, clientInfo->end,
        clientInfo->arrival_time, clientInfo->stay_time
    );
    return(True);
}

void DisplayStatusQueue(QueueType* q)
{
    const char* QNAME[] = { "Waiting Queue", "Service Queue" };

    if (q->isEmpty())
    {
        printf("\n%s is empty\n", QNAME[q->getID() - 1]);
        return;
    }

    puts(QNAME[q->getID() - 1]);
    printf(
        "%-25s%-8s%-8s%-8s%-5s\n"
        ,
        "Client", "Start", "End", "Arrival", "Stay"
    );
}

void AppendCustomersInWaitingQueue(QueueType* q)
{
    QueueElementType e;
    int n;

    e.start = e.end = -1;

    for (n = 0; n < 3; n++)
    {
        printf("Give: arrival time, stay time for client %d: ", (e.id = n + 1));
        scanf("%u,%u", &(e.arrival_time), &(e.stay_time)); getchar();
#ifdef CMD_INPUT
        printf("%u,%u\n", e.arrival_time, e.stay_time);
#endif
        q->Add(&e);
    }
}

QueueType TimesInQueue(QueueType* w_q)
{
    QueueType* s_q = newQueue(sizeof(QueueElementType));
    QueueElementType* e;
    int temp = -1;

    while (!(w_q->isEmpty()))
    {
        e = (QueueElementType*)(w_q->Remove());
        e->start = temp == -1 ? e->arrival_time : temp;
        e->end = e->start + e->stay_time;
        temp = e->end;
        s_q->Add(e);
    }

    return(*s_q);
}