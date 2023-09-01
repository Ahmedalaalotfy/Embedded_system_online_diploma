/*
 * unit8_lesson4_Section_Slave.c
 *
 * Created: 8/30/2023 10:36:49 PM
 * Author : Ahmedalaalotfy
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
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
	
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_INPUT); // MOSI
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);  // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_INPUT); //CLK
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_INPUT); //SS
	
	
	LCD_init();
	SPI_initSlave();
	u8 returnedData ;
	

	while (1)
	{
		for (i = 'A' ; i<= 'Z' ; i++)
		{
			SPI_transieve(i,&returnedData);
			LCD_writeNumber(returnedData);
			_delay_ms(500);
			LCD_clear();
		}
		
	
	}
}
