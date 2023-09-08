/*
 * unit9_lesson1_PWM.c
 *
 * Created: 9/8/2023 5:56:02 AM
 * Author : ahmed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "TMR_interface.h"
#include   "TMR_config.h"
#include   "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);

	TMR_timer0Init();
	TMR_timer0Start();
	TMR_timer0setCompareMatchValue(50);
	
	while (1)
	{

	}
}