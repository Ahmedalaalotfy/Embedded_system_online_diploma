/*
 * LCD_test.c
 *
 * Created: 9/11/2022 11:27:12 AM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"
#include "SWITCH_interface.h"

u8 customChar[] = {
	0x0A,
	0x0A,
	0x0A,
	0x00,
	0x11,
	0x11,
	0x0E,
	0x00
};

void Write_Custom_Character(void){
	LCD_sendCmnd(0x40);           // Set CGRAM Address in address counter to 0x00
	for(int i=0;i<8;i++){
		LCD_sendChar(customChar[i]); // Write data to CGRAM(Character Graphics Random Access Memory)
	}
	LCD_sendCmnd(0x01);           // Clear Display
	LCD_sendChar(0x00);              // Write the Data to LCD stored on address 0x00
}


int main(void)
{
	
	
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
		
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN0,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN6,DIO_PIN_INPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	
	DIO_setPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_OUTPUT);
	
	
	LCD_init();
	LCD_sendString("Hi!  Press B0");
	
    u8 SWITCH_STATE0 , SWITCH_STATE1 ;
    while (1) 
    {
		
		SWITCH_getState(DIO_PORTB,DIO_PIN0,forward,&SWITCH_STATE0);
		
		if(SWITCH_STATE0 == SWITCH_PRESSED)
		{
			
			LCD_clear();
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(200);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			
			LCD_sendString("Learn in depth !");
			_delay_ms(200);
			
			LCD_goToSpecificPosition(2,1);
			
			LCD_sendString("Press B1");
			
		}
		
		SWITCH_getState(DIO_PORTD,DIO_PIN6,forward,&SWITCH_STATE1);
		
		if(SWITCH_STATE1 == SWITCH_PRESSED)
		{
			LCD_clear();
			
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
			_delay_ms(200);
			DIO_setPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
			
			LCD_sendString("Ahmedalaalotfy");
			_delay_ms(200);
			
			LCD_goToSpecificPosition(2,1);
			
			LCD_sendString("Thanks !");
			
		}
		
		
		
       _delay_ms(500);

    } 
}


