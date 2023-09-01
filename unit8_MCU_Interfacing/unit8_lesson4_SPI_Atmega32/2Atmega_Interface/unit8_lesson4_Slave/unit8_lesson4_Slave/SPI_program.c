/*
 * SPI_program.c
 *
 * Created: 10/4/2022 1:03:48 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "SPI_interface.h"



void SPI_initMaster(void)
{
	
	// Select Data Order LSB Transmited First 
	SET_BIT(SPI->SPCR,5);
	
	// Select Master Mode
	SET_BIT(SPI->SPCR,4);
	
	// Select CLK Polarity Falling >> Rising ,Select CLK Phase Setup >> Sampling
	SET_BIT(SPI->SPCR,3);
	SET_BIT(SPI->SPCR,2);
	
	// Select Prescaller 16 , Disable Double Speed 
	SET_BIT(SPI->SPCR,0);
	CLR_BIT(SPI->SPCR,1); 
	CLR_BIT(SPI->SPSR,0);
	
	// SPI Enable
	SET_BIT(SPI->SPCR,6);
}

void SPI_initSlave(void)
{
	// Select Data Order LSB Transmited First
	SET_BIT(SPI->SPCR,5);
	
	// Select Slave Mode
	CLR_BIT(SPI->SPCR,4);
	
	// Select CLK Polarity Falling >> Rising ,Select CLK Phase Setup >> Sampling
	SET_BIT(SPI->SPCR,2);
	SET_BIT(SPI->SPCR,3);
	
	
	// SPI Enable
	SET_BIT(SPI->SPCR,6);
	
}

void SPI_transieve(u8 TxData,u8* RxData)
{
	if (RxData != NULL)
	{
		SPI->SPDR = TxData;
		
		while(0 == GET_BIT(SPI->SPSR,7));
		*RxData = SPI->SPDR; 
		

	}
	
}

