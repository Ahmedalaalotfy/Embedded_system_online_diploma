/*
 * LCD_KPD_Driver.c
 *
 * Created: 8/16/2023 6:02:08 AM
 * Author : Ahmedalaalotfy
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
#include "KPD_interface.h"
#include "KPD_config.h"



int main(void)
{
    u8 KPD_Returned_Value ;
	
	//Set pins direction for KPD
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_setPinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INPUT);
	DIO_setPinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INPUT);
	
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW0_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW1_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW2_PIN);
	DIO_setInputPinResistance(KPD_ROWS_PORT,KPD_ROW3_PIN);
	
	//Set pins direction for LCD
	DIO_setPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTA,DIO_PIN7,DIO_PIN_OUTPUT);
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);
	
	LCD_init();
	
	 
    while (1) 
    {
		KPD_getValue(&KPD_Returned_Value);
		
		if(KPD_NOT_PRESSED != KPD_Returned_Value)
		{
			LCD_sendChar(KPD_Returned_Value);
		}
    }
}

