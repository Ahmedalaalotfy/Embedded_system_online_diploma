/*
 * unit8_lesson6_I2C.c
 *
 * Created: 9/6/2023 2:44:40 PM
 * Author : ahmed
 */ 

#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "TWI_interface.h"
#include "DIO_interface.h"


int main(void)
{
    TWI_initMaster(); 
	
   unsigned char ch = 0  ;
   
   while (1)
   {
	 _delay_ms(1000);
	 TWI_sendStartCondition();
	 TWI_sendSlaveAddWithWrite(0b01010000);
  
	 while((TWSR & 0xF8) != 0x28)	
	 {
		 TWI_sendMasterDataByte(ch++);
	 } 
	 
	            	 
	 TWI_sendStopCondition();
    }
}

