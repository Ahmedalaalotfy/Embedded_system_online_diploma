/*
 * unit8_lesson2_Section.c
 *
 * Created: 8/23/2023 2:33:38 AM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "UART_interface.h"
#include   "DIO_interface.h"


/* HAL */
#include   "LCD_interface.h"
#include   "LCD_config.h"



int main(void)
{
	u8 str[100] ; 
	
    DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
    DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
    DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
    DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
    
    DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
    DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
    DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	DIO_setPinDirection(DIO_PORTD,DIO_PIN0,DIO_PIN_INPUT); // Rx
	DIO_setPinDirection(DIO_PORTD,DIO_PIN1,DIO_PIN_OUTPUT); //Tx
	
	LCD_init();
	UART_init();
	
	UART_TxString("AHMED");
		
    while (1) 
    {  
	UART_RxString(str);
	LCD_sendString(str);
	
    }
}

