/*
 * CortexMX_OS_porting.h
 *
 *  Created on: Oct 29, 2023
 *      Author: ahmed
 */

#ifndef INC_CORTEXMX_OS_PORTING_H_
#define INC_CORTEXMX_OS_PORTING_H_

#include "core_cm3.h"

extern int _estack ;
//extern int _eheap ;
#define MainStackSize  3072

#define OS_SET_PSP(add)                      __asm volatile ("mov r0,%0  \n\t  msr PSP,r0" : : "r" (add) )
#define OS_GET_PSP(add)                      __asm volatile ("mrs r0,PSP \n\t  mov %0,r0  "  : "=r" (add) )


#define OS_SWITCH_SP_TO_PSP                  __asm volatile ("mrs r0,CONTROL \n\t mov r1,#0x02 \n\t orr r0,r0,r1 \n\t msr CONTROL,r0" )
#define OS_SWITCH_SP_TO_MSP                  __asm volatile ("mrs r0,CONTROL \n\t mov r1,#0x05 \n\t and r0,r0,r1 \n\t msr CONTROL,r0" )

#define OS_GENERATE_EXCEPTION                __asm volatile ("SVC #0x3")

//Clear bit0 in control register
#define SWITCH_CPU_AccessLevel_PRIVILEGED    __asm("mrs r3,CONTROL \n\t lsr r3,r3,#0x1 \n\t lsl r3,r3,#0x1 \n\t msr CONTROL,r3")

//Set bit0 in control register
#define SWITCH_CPU_AccessLevel_UNPRIVILEGED  __asm("mrs r3,CONTROL  \n\t orr r3,r3,#0x1 \n\t msr CONTROL,r3")


void trigger_OS_PendSV();
void Start_Ticker();

#endif /* INC_CORTEXMX_OS_PORTING_H_ */






//void SWITCH_CPU_AccessLevel(enum CPUAccessLevel level)
//{
//	switch (level)
//	{
//	case privileged :
//
//		__asm("mrs r3,CONTROL   \n\t"
//				"lsr r3,r3,#0x1 \n\t"
//				"lsl r3,r3,#0x1 \n\t"
//				"msr CONTROL,r3");
//		break;
//
//	case unprivileged :
//
//		__asm("mrs r3,CONTROL   \n\t"
//				"orr r3,r3,#0x1 \n\t"
//				"msr CONTROL,r3");
//
//		break;
//	}
//}
