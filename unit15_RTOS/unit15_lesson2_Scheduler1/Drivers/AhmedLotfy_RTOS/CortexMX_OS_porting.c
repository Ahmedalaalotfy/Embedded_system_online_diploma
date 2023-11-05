/*
 * CortexMX_OS_porting.c
 *
 *  Created on: Oct 29, 2023
 *      Author: ahmed
 */

#include "CortexMX_OS_porting.h"



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
			"mrsne r0,MSP  \n\t"
			"B OS_SVC_Services");
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
}
