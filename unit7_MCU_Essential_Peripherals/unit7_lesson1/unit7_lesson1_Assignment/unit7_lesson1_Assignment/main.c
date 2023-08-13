/*
 * unit7_lesson1_Assignment.c
 *
 * Created: 8/13/2023 4:23:01 PM
 * Author : ahmed
 */ 

#define F_CPU 16000000UL 

#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"
#include "util/delay.h"

void SSD_Display_Number(unsigned char First_Num,unsigned char Seconed_Num) ; 
static void writeHalfPort(u8 Value);

int main(void)
{
 
 //PIn Direction for leds (Output)
 SET_BIT(DDRC,2); //LED0
 SET_BIT(DDRC,7); //LED1
 SET_BIT(DDRD,3); //LED2
 
 //PIN Direction for Buzzer (Output)
 SET_BIT(DDRA,3);

 //PIN Direction for Buttons (Input)
 CLR_BIT(DDRB,0); //Button0
 CLR_BIT(DDRD,6); //Button1
 CLR_BIT(DDRD,2); //Button2
 
 //PIN Direction for SSD (Output)
 SET_BIT(DDRA,4);
 SET_BIT(DDRA,5);
 SET_BIT(DDRA,6);
 SET_BIT(DDRA,7);
 SET_BIT(DDRB,1);
 SET_BIT(DDRB,2);
 SET_BIT(DDRB,3);
 
 //PIN Values for SSD
 SET_BIT(PORTB,1);
 SET_BIT(PORTB,2); 
 CLR_BIT(PORTB,3);
 
 
 volatile unsigned int flag = 0 ,i ,j,timer;
 
 while (1)
 {
	 // BUZZER
	 if (GET_BIT(PINB,0) == 1)
	 {
		SET_BIT(PORTA,3); 
		_delay_ms(1000);
		CLR_BIT(PORTA,3); 
	 }
	 
	 //LEDs
	 
	 if (GET_BIT(PIND,6) == 1)
	 {
		_delay_ms(250);
		flag++;
	 }
	 
	 if (flag == 1)
	 {
		 SET_BIT(PORTC,2);
		 _delay_ms(250); 
	 }
	 
	 if (flag == 2)
	 {
		 SET_BIT(PORTC,7);
		 _delay_ms(250);
	 }
	 
	 if (flag == 3)
	 {
		 SET_BIT(PORTD,3);
		 _delay_ms(250);
	 }
	 
	 if (flag == 4)
	 {
		 CLR_BIT(PORTC,2);
		 CLR_BIT(PORTC,7);
		 CLR_BIT(PORTD,3);
		 _delay_ms(250);
		 
		  flag =0; 
	 }
	 
	 
	 //SSD
	 
	 if (GET_BIT(PIND,2) == 1)
	 {
		 for (i=0;i<10;i++)
		 { 
			 for(j=0;j<10;j++)
			 {
				 _delay_ms(500);
				for(timer=0;timer<10;timer++)
				{
					SSD_Display_Number(i,j);
					_delay_ms(7);
				}	
			 }
		 } 
	 }
	   
 }
}

void SSD_Display_Number(unsigned char First_Num,unsigned char Seconed_Num) 
{

	CLR_BIT(PORTB,1);
	SET_BIT(PORTB,2);
	CLR_BIT(PORTB,3);
	
	writeHalfPort (First_Num);
	_delay_ms(7);
	
	SET_BIT(PORTB,1);
	CLR_BIT(PORTB,2);
	CLR_BIT(PORTB,3);
	
	writeHalfPort (Seconed_Num);
	_delay_ms(7);
}


static void writeHalfPort(u8 Value)
{
	if (1==GET_BIT(Value,0))
	{
		SET_BIT(PORTA,4);
	}
	else
	{
		CLR_BIT(PORTA,4);
	}
	
	if (1==GET_BIT(Value,1))
	{
		SET_BIT(PORTA,5);
	}
	else
	{
		CLR_BIT(PORTA,5);
	}
	
	if (1==GET_BIT(Value,2))
	{
		SET_BIT(PORTA,6);
	}
	else
	{
		CLR_BIT(PORTA,6);
	}
	
	if (1==GET_BIT(Value,3))
	{
		SET_BIT(PORTA,7);
	}
	else
	{
		CLR_BIT(PORTA,7);
	}
}

