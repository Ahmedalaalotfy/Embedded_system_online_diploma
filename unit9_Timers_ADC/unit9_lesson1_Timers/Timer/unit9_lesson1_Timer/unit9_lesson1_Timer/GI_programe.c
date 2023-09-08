/*
 * GI_programe.c
 *
 * Created: 9/18/2022 9:44:51 AM
 *  Author: ahmed
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "GI_interface.h"


void GI_enable(void)
{
	SET_BIT (SREG,7);
}
void GI_disable(void)
{
	CLR_BIT (SREG,7);
}