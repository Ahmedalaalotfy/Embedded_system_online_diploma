/*
 * unit9_lesson1_WDT.c
 *
 * Created: 9/7/2023 9:48:20 PM
 * Author : ahmed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "WDT_interface.h"
#include   "DIO_interface.h"


int main(void)
{
	DIO_setPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	_delay_ms(500);
	while (1)
	{
		WDT_start();
		DIO_togglePinValue(DIO_PORTC,DIO_PIN0);
	    _delay_ms(2000);
		WDT_stop();
	}
}
