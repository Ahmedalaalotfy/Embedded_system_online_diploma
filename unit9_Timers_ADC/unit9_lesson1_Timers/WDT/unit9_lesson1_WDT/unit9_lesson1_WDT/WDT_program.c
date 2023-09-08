/*
 * WDT_program.c
 *
 * Created: 9/29/2022 1:29:18 PM
 *  Author: ahmed
 */ 



/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "WDT_interface.h"


void WDT_start(void)
{
	// Select Prescaler Value >>> 1 Sec 
	CLR_BIT(WDTCR,0);
	SET_BIT(WDTCR,1);
	SET_BIT(WDTCR,2);
	
	// Enable WDT
	SET_BIT(WDTCR,3);
}

void WDT_stop(void)
{
	/* Write logical one to WDTOE and WDE */
	WDTCR = (1<<4) | (1<<3);
	/* Turn off WDT */
	WDTCR = 0x00;
}