/*
 * unit8_lesson4_Section.c
 *
 * Created: 8/30/2023 10:36:49 PM
 * Author : Ahmedalaalotfy
 */ 

<<<<<<< HEAD
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
=======
#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
#include "SPI_interface.h"
#include "DIO_interface.h"

/* HAL */
#include   "LCD_interface.h"
#include   "LCD_config.h"


int main(void)
{
	u8 i ;
	
	//LCD 
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT); // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);  // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT); //CLK
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT); //SS
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH); //SS = 1
	
	LCD_init();
	SPI_initMaster();
	u8 returnedData ;
	

	while (1)
	{
		
	
		for (i = 0 ; i<=9 ; i++)
		{
			DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW); //SS = 0
			SPI_transieve(i,&returnedData);
			DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH); //SS = 1
			LCD_sendChar(returnedData);
			_delay_ms(500);
			LCD_clear();
		}
		
	
	}
}
