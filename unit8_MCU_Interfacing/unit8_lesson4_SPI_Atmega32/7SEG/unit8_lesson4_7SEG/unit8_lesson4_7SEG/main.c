/*
 * unit8_lesson4_Section.c
 *
 * Created: 8/30/2023 10:36:49 PM
 * Author : Ahmedalaalotfy
 */ 

<<<<<<< HEAD
#define F_CPU 1000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
=======
#define F_CPU 1000000UL
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

void execute(unsigned char cmd, unsigned char data)
{
	PORTB &= ~(1 << DIO_PIN4);
	SPI->SPDR = cmd;
	while (!(SPI->SPSR & (1 << 7)));
	SPI->SPDR = data;
	while (!(SPI->SPSR & (1 << 7)));
	PORTB |= (1 << DIO_PIN4);
}

int main(void)
{
	u8 i = 0 ;
	unsigned char index_display;

	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT); // MOSI
	//DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_INPUT);  // MISO
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT); //CLK
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT); //SS
	
	DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH); //SS = 1
	
	LCD_init();
	SPI_initMaster();
	u8 returnedData ;
	
	
	
	execute(0x09, 0xFF);
	execute(0x0A, 0xFF);
	execute(0x0B, 0xF7);
	execute(0x0C, 0x01);
	

	while (1)
	{
	
		for (index_display = 1; index_display < 9; index_display++)
		{
			DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_LOW); //SS = 0
			execute(index_display, i++);
			DIO_setPinValue(DIO_PORTB,DIO_PIN4,DIO_PIN_HIGH); //SS = 1
		}
		
		_delay_ms(1000);
		
	
	}
}
