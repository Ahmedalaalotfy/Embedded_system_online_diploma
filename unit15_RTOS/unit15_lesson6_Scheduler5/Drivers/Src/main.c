/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"
#include "stm32f103x6.h"
#include "core_cm3.h"
#include "Scheduler.h"

Task_ref Task1, Task2 , Task3 , Task4 ;
unsigned char Task1_LED , Task2_LED , Task3_LED , Task4_LED ;
Mutex_ref Mutex1 ,Mutex2 ;
unsigned char payload[3] = {1,2,3} ;
unsigned char payload2[3] = {4,5,6} ;


void task1 ()
{
	static int count = 0 ;
	while(1)
	{
		//Task1 Code
		Task1_LED ^= 1 ;
		count++ ;

		if (count == 100)
		{
			MYRTOS_AquireMutex(&Mutex1, &Task1);
			MYRTOS_ActivateTask(&Task4);
			MYRTOS_AquireMutex(&Mutex2, &Task1);

		}

		if (count == 200)
		{
			count = 0;
			MYRTOS_ReleaseMutex(&Mutex1);
		}

	}
}

void task2 ()
{
	static int count = 0 ;
	while(1)
	{
		//Task2 Code
		Task2_LED ^= 1 ;
		count++ ;

		if (count == 100)
		{
			MYRTOS_ActivateTask(&Task3);
		}

		if (count == 200)
		{
			count = 0;
			MYRTOS_TerminateTask(&Task2);
		}

	}
}

void task3 ()
{
	static int count = 0 ;
	while(1)
	{
		//Task3 Code
		Task3_LED ^= 1 ;
		count++ ;

		if (count == 100)
		{
			MYRTOS_ActivateTask(&Task4);
		}

		if (count == 200)
		{
			count = 0;
			MYRTOS_TerminateTask(&Task3);
		}

	}

}

void task4 ()
{
	static int count = 0 ;
	while(1)
	{
		//Task4 Code
		Task4_LED ^= 1 ;
		count++ ;


		if (count == 5)
		{
			MYRTOS_AquireMutex(&Mutex2, &Task4);
			MYRTOS_AquireMutex(&Mutex1, &Task4);
		}

		if (count == 200)
		{
			count = 0;
			MYRTOS_ReleaseMutex(&Mutex1);
			MYRTOS_TerminateTask(&Task4);
		}

	}

}

int main(void)
{
	MYRTOS_ErrorID error ;
	//HW_Init (Initialize Clock tree , Reset Controller)
	HW_Init();

	if ( MYRTOS_Init() != NoError )
		while(1) ;

	Mutex1.PayloadSize = 3 ;
	Mutex1.Ppayload = payload ;
	strcpy(Mutex1.MutexName ,"Mutex_shared_T1&T4");

	Mutex2.PayloadSize = 3 ;
	Mutex2.Ppayload = payload2 ;
	strcpy(Mutex2.MutexName ,"Mutex2_shared_T1&T4");



	Task1.Stack_Size = 1024 ;
	Task1.p_TaskEntry = task1 ;
	Task1.priority = 4 ;
	strcpy(Task1.TaskName ,"task1");

	Task2.Stack_Size = 1024 ;
	Task2.p_TaskEntry = task2 ;
	Task2.priority = 3 ;
	strcpy(Task2.TaskName ,"task2");


	Task3.Stack_Size = 1024 ;
	Task3.p_TaskEntry = task3 ;
	Task3.priority = 2 ;
	strcpy(Task3.TaskName ,"task3");

	Task4.Stack_Size = 1024 ;
	Task4.p_TaskEntry = task4 ;
	Task4.priority = 1 ;
	strcpy(Task4.TaskName ,"task4");

	error += MYRTOS_CreateTask(&Task1);
	error += MYRTOS_CreateTask(&Task2);
	error += MYRTOS_CreateTask(&Task3);
	error += MYRTOS_CreateTask(&Task4);



	MYRTOS_ActivateTask(&Task1);


	MYRTOS_StartOS();


	while (1)
	{

	}

}
