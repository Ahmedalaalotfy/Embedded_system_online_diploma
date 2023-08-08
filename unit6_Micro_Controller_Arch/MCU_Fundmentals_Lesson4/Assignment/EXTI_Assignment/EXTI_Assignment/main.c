/*
 * EXTI_Assignment.c
 *
 * Created: 8/6/2023 10:12:25 PM
 * Author : Ahmedalaalotfy
 */ 

#define F_CPU 16000000UL 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


typedef unsigned char u8;

// Pins configurations 
#define DDRB   (*(volatile u8*)0x37)
#define DDRD   (*(volatile u8*)0x31)
#define PORTD  (*(volatile u8*)0x32)

      /* EXTERNAL INTERRUPT REGISTERS */

// MCU CONTROL REGISTER
#define MCUCR   (*(volatile u8*)0x55)

// MCU CONTROL AND STATUS REGISTER
#define MCUCSR   (*(volatile u8*)0x54)

// GENERAL INTERRUPT CONTROL REGISTER
#define GICR   (*(volatile u8*)0x5B)

// GENERAL INTERRUPT FLAG REGISTER
#define GIFR   (*(volatile u8*)0x5A)

// STATUS REGISTER
#define SREG   (*(volatile u8*)0x5F)


void Global_interrupt_init(void)
{
	SREG |= (1<<7); 
}
void EXTI0_init(void)
{
	// falling or raising edge mode 
	MCUCR |= 0b01 ;
	//INT0 enable 
	GICR |= (1<<6);
}
void EXTI1_init(void)
{
	//raising edge mode 
	MCUCR |= 0b1100;
	//INT1 enable
	GICR |= (1<<7);
}
void EXTI2_init(void)
{
	// falling edge mode 
	MCUCSR &= ~(1<<6);
	//INT2 enable
	GICR |= (1<<5);
}


int main(void)
{
	
	//EXTIs PINS set to be input
	DDRD  &= ~(1<<2);
	DDRD  &= ~(1<<3);
	DDRB  &= ~(1<<2);
	
	//LEDS PINS set to be output
	DDRD  |= (1<<5);
	DDRD  |= (1<<6);
	DDRD  |= (1<<7);
		
	// inits
	EXTI0_init();
	EXTI1_init();
	EXTI2_init();
	Global_interrupt_init();
	
   
    while (1) 
    {
		PORTD &= ~(1<<5);
		PORTD &= ~(1<<6);
		PORTD &= ~(1<<7);
    }
}

ISR(INT0_vect)
{
	PORTD |=(1<<5);
	_delay_ms(100);
	

	GIFR |=(1<<6);
}
ISR(INT1_vect)
{
	PORTD |=(1<<6);
	_delay_ms(100);
	

	GIFR |=(1<<7);

}
ISR(INT2_vect)
{
	PORTD |=(1<<7);
	_delay_ms(100);
	

    GIFR |=(1<<5);
}