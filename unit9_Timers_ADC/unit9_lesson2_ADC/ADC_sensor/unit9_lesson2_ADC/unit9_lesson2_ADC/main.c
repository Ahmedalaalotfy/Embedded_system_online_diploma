/*
 * unit9_lesson2_ADC.c
 *
 * Created: 9/9/2023 2:36:05 AM
 * Author : ahmed
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>

//UTILES
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "ADC_Interface.h"
#include "DIO_Interface.h"

// HAL
#include "LCD_Interface.h"
#include "LCD_config.h"

int main(void)
{
	
	// LCD Set Direction
	DIO_setPinDirection(DIO_PORTB,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN7,DIO_PIN_OUTPUT);
	
	
	DIO_setPinDirection(DIO_PORTB,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_setPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);	
 

	
	LCD_init();
	ADC_init();
	
	u16 digitalValue ,analogVal ;
	u32 mvolt , Reading; 
	
	while (1)
	{
		ADC_getDigitalValue(ADC_CHANNEL1,&digitalValue);
		LCD_goToSpecificPosition(1,0);
		LCD_sendString("VOLT VAL:    C");
		LCD_goToSpecificPosition(1,10);
		mvolt = ((((u32)digitalValue)*5000)/1024) ; 
		Reading = (mvolt/10) ;
		LCD_writeNumber(Reading);
		
		_delay_ms(500);
		LCD_clear();	
		
	}
}