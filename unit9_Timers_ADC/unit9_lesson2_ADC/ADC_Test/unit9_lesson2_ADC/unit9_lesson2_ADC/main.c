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
 
	uint8_t arr[16]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,};

	
	LCD_init();
	ADC_init();
	
	u16 digitalValue ,analogVal ;
	u32 volt , percentage; 
	
	while (1)
	{
		ADC_getDigitalValue(ADC_CHANNEL1,&digitalValue);
		LCD_goToSpecificPosition(1,0);
		LCD_sendString("VOLT VAL:    %");
		LCD_goToSpecificPosition(1,10);
		//volt = ((((u32)digitalValue)*5000)/1024) ; 
		percentage = ((((u32)digitalValue)*100)/1024) ;
		LCD_writeNumber(percentage);
		
		if (percentage < 10)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 20)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 30)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 40)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 50)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		
		else if (percentage < 60)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 70)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		else if (percentage < 80)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		
		else if (percentage < 90)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		
		else if (percentage < 100)
		{
			LCD_goToSpecificPosition(2,3);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
			LCD_sendChar(arr[0]);
		}
		
		
		
		
	
		_delay_ms(500);
		LCD_clear();	
		
	}
}