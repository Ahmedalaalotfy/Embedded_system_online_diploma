/*
 * ADC_program.c
 *
 * Created: 9/20/2022 12:41:23 PM
 *  Author: ahmed
 */ 

//UTILES
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

//MCAL
#include "ADC_Interface.h"

void ADC_init(void)
{
	// Select Vref = AVCC
	SET_BIT(ADMUX,6);
	CLR_BIT(ADMUX,7);
	
	// Choose Right Adjustment
	CLR_BIT(ADMUX,5);
	
	// Disable Auto Trigger ( Single Conversion Mode )
	CLR_BIT(ADCSRA,5);
	
	// Disable Interrupt 
	CLR_BIT(ADCSRA,3);
	
	// Prescaler 64 for 8MHZ 
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	// ADC Enable 
	SET_BIT(ADCSRA,7);
	
}

void ADC_getDigitalValue(u8 channelNum, u16* digitalValue)
{
	if ( (channelNum<32) && (digitalValue !=  NULL) )
	{
		// Clear ADMUX Channel Bits
		ADMUX &= 0b11100000 ; 
		
		// Select Channel Number 
		ADMUX |= channelNum ;
		
		// Start Conversion 
		SET_BIT(ADCSRA,6);
		
		// Waiting For Flag Of ADC
		while (0 == GET_BIT(ADCSRA,4)) ;
		
		// Clear Flag
		SET_BIT(ADCSRA,4);
		
		*digitalValue = ADC_u16 ; 
	}
}