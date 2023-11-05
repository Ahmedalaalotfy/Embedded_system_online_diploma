/*
 * CortexMX_OS_porting.c
 *
 *  Created on: Oct 29, 2023
 *      Author: ahmed
 */

#include "CortexMX_OS_porting.h"

unsigned char SysTick_LED ;

void HardFault_Handler (void)
{
	while (1) ;
}
void MemManage_Handler (void)
{
	while (1) ;
}
void BusFault_Handler (void)
{
	while (1) ;
}
void UsageFault_Handler (void)
{
	while (1) ;
}

__attribute ((naked)) void SVC_Handler()
{
	__asm("tst lr,#4       \n\t"
			"ITE EQ        \n\t"
			"mrseq r0,MSP  \n\t"
			"mrsne r0,PSP  \n\t"
			"B OS_SVC");
}

void HW_Init ()
{
	//Initialize Clock Tree (RCC -> SysTick Timer & CPU) 8Mhz
	// init HW
	// Clock Tree
	// RCC Default Values Makes CPU Clock & SysTick Timer Clock = 8 Mhz
	// 8Mhz
	// 1 Count -> 0.125
	// X Count -> 1 ms
	// X = 800 Count

	//decrease PenSV  interrupt priority to be  smaller than or equal  SySTICK Timer
	//SysTICK have a priority 14
	__NVIC_SetPriority(PendSV_IRQn, 15);

}

void trigger_OS_PendSV()
{
	SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk ;
}

void Start_Ticker()
{
	// 8Mhz
	// 1 Count -> 0.125
	// X Count -> 1 ms
	// X = 800 Count
	SysTick_Config(8000);
}


void SysTick_Handler()
{
	SysTick_LED ^= 1 ;

	MYRTOS_Update_TaskWaiting_Time();

	//Determine PCurrent & PNext
	Decide_WhatNext();

	//Switch Context & Restore
	trigger_OS_PendSV();

}
