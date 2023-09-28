#pragma comment(lib, "aic205.lib")
#include "aic205.h"

#define TOTAL_CLINICS 5
#define MAX_PATIENTS  (TOTAL_ELEMENT_ARRAY_BYTES / sizeof(QueueElementType))

#ifdef SIM_INPUT
#define STDIN_GRAB(fmt, arg) scanf(fmt, &(arg)); getchar(); printf(fmt"\n", arg)
#define STDIN_GRAB_S(fmt, arg) scanf(fmt, arg); getchar(); printf(fmt"\n", arg)
#else
#define STDIN_GRAB(fmt, arg) scanf(fmt, &(arg)); getchar()
#define STDIN_GRAB_S(fmt, arg) scanf(fmt, arg); getchar()
#endif


typedef struct
{
	char name[25];
	int  clinicID;
	char phoneNumber[10];
} QueueElementType;

Boolean newAppointment(int, Queue*, Queue*);
Boolean traverseClinicQueue(QueueElementType*);
Boolean traverseWaitingQueue(QueueElementType*);
void    showQ(Queue*, int);
void    showWaitingQ(Queue*);

int main(void)
{
	Queue* Clinic[TOTAL_CLINICS];
	Queue* Waiting_Queue = newQueue(sizeof(QueueElementType));
	int i, n;

	ITERRAY_BEGIN(Clinic)
		Clinic[i] = newQueue(sizeof(QueueElementType));
	ITERRAY_END;

	randomForceSeed(54);
	for (i = 0; i < MAX_PATIENTS; ++i)
	{   n = randomIntFromTo(1, TOTAL_CLINICS);
		if (!(newAppointment(n, Clinic[n-1], Waiting_Queue))) break; }
	puts("");

	ITERRAY_BEGIN(Clinic)
		showQ(Clinic[i], i+1);
	ITERRAY_END;

	showWaitingQ(Waiting_Queue);

	return(0);
}

Boolean newAppointment(int clinicID, Queue* ClinicQ, Queue* WaitQ)
{
	QueueElementType Sample;
	char res = 0;
	int Front = *(((int*)(ClinicQ + 1)) + 1);
	int Rear = *(((int*)(ClinicQ + 1)) + 2);
	Boolean ClinicFull = (Boolean)((Rear - Front) > 1);

	printf("Give your name: ");
	if (!ClinicFull)
	{
		STDIN_GRAB_S("%s", Sample.name);
		Sample.clinicID = clinicID;
		ClinicQ->Add(&Sample);
		printf("Successful appointment for clinic %i\n", clinicID);
	}
	else {
		STDIN_GRAB_S("%s", Sample.name);
		Sample.clinicID = clinicID;
		printf("You are in a waiting list\nGive your phone number: ");
		STDIN_GRAB_S("%s", Sample.phoneNumber);
		WaitQ->Add(&Sample);
	}

	while (!(res == 'Y' || res == 'N'))
	{
		printf("Continue Y/N (Y=Yes, N=No): ");
		STDIN_GRAB("%c", res);
		res -= res > 90 ? 32 : 0;
	}
	return(res == 89);
}

void showQ(Queue* ClinicQ, int ClinicID)
{
	printf("Appointments of clinic %i\n", ClinicID);
	setTraverse_Queue(traverseClinicQueue);
	ClinicQ->Traverse();
}

void showWaitingQ(Queue* WaitQ)
{
	printf("Waiting list:\n");
	setTraverse_Queue(traverseWaitingQueue);
	WaitQ->Traverse();
}

Boolean traverseClinicQueue(QueueElementType* patient)
{
	printf("%s\n", patient->name);
}

Boolean traverseWaitingQueue(QueueElementType* patient)
{
	printf("%s, %s\n", patient->name, patient->phoneNumber);
}