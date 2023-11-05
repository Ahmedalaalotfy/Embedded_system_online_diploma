/*
 * Scheduler.h
 *
 *  Created on: Oct 29, 2023
 *      Author: ahmed
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "CortexMX_OS_porting.h"



typedef enum {
	NoError,
	Ready_Queue_init_error,
	Task_exceeded_StackSize,
	MutexIsReachedToMaxNumberOfUsers
}MYRTOS_ErrorID;


typedef struct {

	unsigned int Stack_Size ;
	unsigned char priority ;
	void (*p_TaskEntry)(void) ;  //Pointer To Task c Function
	unsigned char AutoStart ;
	unsigned int _S_PSP_Task ;   //Not Entered by the user
	unsigned int _E_PSP_Task ;   //Not Entered by the user
	unsigned int* Current_PSP ;  //Not Entered by the user
	char TaskName[30];
	enum {
		Suspend,
		Running,
		Waiting,
		ready
	}TaskState; //Not Entered by the user
	struct {
		enum {
			Enable,
			Disable
		}Blocking;
		unsigned int Ticks_Count ;
	}TimingWaiting;
}Task_ref;

typedef struct {
unsigned char* Ppayload;
unsigned int PayloadSize ;
Task_ref* CurrentTUser ;
Task_ref* NextTUser ;
char MutexName[30];
}Mutex_ref;


//APIs
MYRTOS_ErrorID MYRTOS_Init();
MYRTOS_ErrorID MYRTOS_CreateTask(Task_ref* Tref );
void MYRTOS_ActivateTask(Task_ref* Tref);
void MYRTOS_TerminateTask(Task_ref* Tref);
void MYRTOS_StartOS();
void MYRTOS_TaskWait(unsigned int NoTicks ,Task_ref* SelfTref);
MYRTOS_ErrorID MYRTOS_AquireMutex(Mutex_ref* Mref ,Task_ref* Tref);
void MYRTOS_ReleaseMutex(Mutex_ref* Mref);



#endif /* INC_SCHEDULER_H_ */
