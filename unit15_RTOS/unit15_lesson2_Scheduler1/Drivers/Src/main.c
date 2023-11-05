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

Task_ref Task1, Task2 , Task3 ;

void task1 ()
{
	while(1)
	{
		//Task1 Code
	}
}

void task2 ()
{
	while(1)
	{
		//Task2 Code
	}
}

void task3 ()
{
	while(1)
	{
		//Task3 Code
	}
}

int main(void)
{
	MYRTOS_ErrorID error ;
	//HW_Init (Initialize Clock tree , Reset Controller)
	HW_Init();

	if ( MYRTOS_Init() != NoError )
		while(1) ;


	Task1.Stack_Size = 1024 ;
	Task1.p_TaskEntry = task1 ;
	Task1.priority = 3 ;
	strcpy(Task1.TaskName ,"task1");

	Task2.Stack_Size = 1024 ;
	Task2.p_TaskEntry = task2 ;
	Task2.priority = 3 ;
	strcpy(Task2.TaskName ,"task2");


	Task3.Stack_Size = 1024 ;
	Task3.p_TaskEntry = task3 ;
	Task3.priority = 3 ;
	strcpy(Task3.TaskName ,"task3");

	error += MYRTOS_CreateTask(&Task1);
	error += MYRTOS_CreateTask(&Task2);
	error += MYRTOS_CreateTask(&Task3);

	while (1)
	{

	}

}