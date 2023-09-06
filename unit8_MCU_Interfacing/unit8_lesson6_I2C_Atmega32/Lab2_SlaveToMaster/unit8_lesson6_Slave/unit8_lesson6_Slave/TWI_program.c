/*
 * TWI_program.c
 *
 * Created: 10/6/2022 1:24:47 PM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"
#include    <avr/io.h>

/* MCAL */
#include "TWI_interface.h"

void TWI_initMaster(void)
{
	// Set Prescaller = 1 >>S Set Clock Freq TO Max = 50 Khz
	CLR_BIT(TWSR,0);
	CLR_BIT(TWSR,1);
	TWBR = 72 ;
	
	// Enable ACK
	SET_BIT(TWCR,6);
	
	// Enable TWI 
	SET_BIT(TWCR,2);              
}

void TWI_initSlave(u8 SlaveAdd)
{
	if (SlaveAdd<128)
	{
		// Set Slave Address 
		TWAR = SlaveAdd<<1 ;
		
		// Disable General Call
		CLR_BIT(TWAR,0);
		
		// Enable ACK
		SET_BIT(TWCR,6);
		
		// Enable TWI
		SET_BIT(TWCR,2);
	}
}

void TWI_sendStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear Flag To Start Current Job
	SET_BIT(TWCR,7);
	
	// Wait For Flag
	while (0==GET_BIT(TWCR,7));
	
	// Check ACK == SC ACK
	while((TWSR & 0xF8) != 0x08);
}

void TWI_sendRepStartCondition(void)
{
	// Send Start Condition
	SET_BIT(TWCR,5);
	
	// Clear Flag To Start Current Job
	SET_BIT(TWCR,7);
	
	// Wait For Flag
	while (0==GET_BIT(TWCR,7));
	
	// Check ACK == Repeated SC ACK
	while((TWSR & 0xF8) != 0x10);
}

void TWI_sendStopCondition(void)
{
	// Send Stop Condition
	SET_BIT(TWCR,4);
	
	// Clear Flag To Start Current Job
	SET_BIT(TWCR,7);
}

void TWI_sendSlaveAddWithWrite(u8 SlaveAdd)
{
	if (SlaveAdd < 128)
	{
	 // Select Slave Adress 	
     TWDR = SlaveAdd << 1 ;	
	 
	 // Select Write Operation 
	 CLR_BIT(TWDR,0);
	 
	 // Clear Start Condition Bit
	 CLR_BIT(TWCR,5);
	 
	 // Clear Flag To Start Current Job
	 SET_BIT(TWCR,7);
	 
	 // Wait For Flag
	 while (0==GET_BIT(TWCR,7));
	 
	 // Check ACK == Master Transmit (Slave Address + Write Request) ACK
	 while((TWSR & 0xF8) != 0x18);
	}
}


void TWI_sendSlaveAddWithRead(u8 SlaveAdd)
{
   if (SlaveAdd < 128)
   {
   	// Select Slave Adress
   	TWDR = SlaveAdd << 1 ;
   	
   	// Select Read Operation
   	SET_BIT(TWDR,0);
   	
   	// Clear Start Condition Bit
   	CLR_BIT(TWCR,5);
   	
   	// Clear Flag To Start Current Job
   	SET_BIT(TWCR,7);
   	
   	// Wait For Flag
   	while (0==GET_BIT(TWCR,7));
   	
   	// Check ACK == Master Transmit (Slave Address + Read Request) ACK
   	while((TWSR & 0xF8) != 0x40);
   }
}

void TWI_sendMasterDataByte(u8 data)
{
	// Write Data Into Data Register 
	TWDR = data ; 
	
	// Clear Flag To Start Current Job
	SET_BIT(TWCR,7);
	
	// Wait For Flag
	while (0==GET_BIT(TWCR,7));
	
	// Check ACK == Master Transmit Data ACK
	while((TWSR & 0xF8) != 0x28);
	
}

void TWI_readMasterDataByte(u8* returnedData)
{
	// Clear Flag To Start Current Job
	SET_BIT(TWCR,7);
	
	// Wait For Flag
	while (0==GET_BIT(TWCR,7));
	
	// Check ACK == Master Receiced Data ACK
	while((TWSR & 0xF8) != 0x50);
	
	// Read Data From Data Register
	*returnedData = TWDR ; 
}

unsigned char TWI_Slave_Read(unsigned char ack)
{
	unsigned char x=0;
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while ((TWCR & 0x80) == 0);
	
}
 
 void TWI_Slave_Write(unsigned char cByte)
 {
	 TWDR = cByte;
	 TWCR = (1<<TWINT)|(1<<TWEN);
	 while ((TWCR & 0x80)==0);
 }