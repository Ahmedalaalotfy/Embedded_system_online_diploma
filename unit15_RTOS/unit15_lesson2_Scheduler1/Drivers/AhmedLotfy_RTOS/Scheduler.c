/*
 * Scheduler.c
 *
 *  Created on: Oct 29, 2023
 *      Author: ahmed
 */

#include "Scheduler.h"
#include "string.h"
#include "MYRTOS_FIFO.h"

struct {
	Task_ref* OSTasks[100] ; //Scheduler Table
	unsigned int _S_MSP_Task ;
	unsigned int _E_MSP_Task ;
	unsigned int PSP_Task_Locator ;
	unsigned int NoOfActiveTasks ;
	Task_ref* CurrentTask ;
	Task_ref* NextTask ;
	enum {
		OSsuspend,
		OSRunning
	}OSmodeID;
}OS_Control;

FIFO_Buf_t Ready_QUEUE ;
Task_ref* Ready_QUEUE_FIFO[100];
Task_ref MYRTOS_idleTask ;


void OS_SVC_Services(int* StackFramePointer)
{
	//OS_SVC_Set stack start found in -> r0 , r0 is pointed by StackFramePointer
	//OS_SVC_Set stack : r0,r1,r2,r12,LR,PC,XPSR

	unsigned char SVC_number ;

	SVC_number = *((unsigned char*)(((unsigned char*)StackFramePointer[6])-2)) ;

	switch(SVC_number)
	{
	case 0 : //Activate Task

		break;

	case 1 : //Terminate Task

		break;

	case 2 : //

		break;

	case 3 : //

		break;
	}

}

void PendSV_Handler()
{
	//PendSV_HandlerB
}


int OS_SVC_Set( int SVC_ID)
{

	switch(SVC_ID)
	{
	case 1 : //Activate Task
		__asm("svc #0x01");
		break;

	case 2 : //Terminate Task
		__asm("svc #0x02");
		break;

	case 3 :
		__asm("svc #0x03");
		break;

	case 4 :
		__asm("svc #0x04");
		break;
	}

}

void MYRTOS_IdleTask()
{
	while (1)
	{
		__asm("NOP") ;
	}
}


void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP_Task = &_estack ;

	//Aligned 8 Bytes spaces between Main Task and PSP tasks
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - MainStackSize ;

	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8);

	// if (_E_MSP_Task < _&eheap) Error : Exceeded the available stack size
}



MYRTOS_ErrorID MYRTOS_Init()
{
	MYRTOS_ErrorID error = NoError ;

	//Update OS Mode (OS Suspend)
	OS_Control.OSmodeID = OSsuspend ;

	//Specify the Main Stack For OS
	MYRTOS_Create_MainStack();

	//Create OS Ready Queue
	if (FIFO_init(&Ready_QUEUE,Ready_QUEUE_FIFO, 100) != FIFO_NO_ERROR )
	{
		error = Ready_Queue_init_error ;
	}

	//Configure Idle Task
	strcpy(MYRTOS_idleTask.TaskName,"IdleTask");
	MYRTOS_idleTask.priority = 255 ;
	MYRTOS_idleTask.p_TaskEntry = MYRTOS_IdleTask ;
	MYRTOS_idleTask.Stack_Size = 300 ;


	error += MYRTOS_CreateTask(&MYRTOS_idleTask);

	return error ;
}






void MYRTOS_Create_Task_Stack(Task_ref* Tref)
{
	/*Task Frame
	 * ======
	 * XPSR
	 * PC (Next Task Instruction which should be Run)
	 * LR (return register which is saved in CPU while Task1 running before TaskSwitching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *====
	 *r5, r6 , r7 ,r8 ,r9, r10,r11 (Saved/Restore)Manual
	 */

	Tref->Current_PSP = Tref->_S_PSP_Task ;

	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = 0x01000000;         //DUMMY_XPSR should T =1 to avoid BUS fault;//0x01000000

	Tref->Current_PSP-- ;
	*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC

	Tref->Current_PSP-- ; //LR = 0xFFFFFFFD (EXC_RETURN)Return to thread with PSP
	*(Tref->Current_PSP)  = 0xFFFFFFFD ;

	for (int  j=0 ; j< 13 ; j++ )
	{
		Tref->Current_PSP-- ;
		*(Tref->Current_PSP)  = 0 ;

	}

}

MYRTOS_ErrorID MYRTOS_CreateTask(Task_ref* Tref )
{
	MYRTOS_ErrorID error = NoError ;

	//Create Its OWN PSP stack
	//Check task size exceeded the PSP stack
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator ;
	Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size ;

	//	-				-
	//	- _S_PSP_Task	-
	//	-	Task Stack	-
	//	- _E_PSP_Task	-
	//	-				-
	//	- _eheap		-
	//	-				-
	//

	if (Tref->_E_PSP_Task < (unsigned int)(&(_eheap)))
	{
		return Task_exceeded_StackSize ;
	}

	//Aligned 8 Bytes spaces between Task PSP and Other
	OS_Control.PSP_Task_Locator = (Tref->_E_PSP_Task - 8) ;

	//Initialize PSP Task Stack
	MYRTOS_Create_Task_Stack(Tref);

	//Task State Update -> Suspend
	Tref->TaskState = Suspend ;

	return error ;
}


