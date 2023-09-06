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
	DIO_setPortDirection(PORTA,DIO_PORT_OUTPUT);
    TWI_initMaster(); 
	
   unsigned char ch ;
   while (1)
   {
	 _delay_ms(1000);
	 TWI_sendStartCondition();
	 TWI_sendSlaveAddWithRead(0b01010000);
	 TWI_readMasterDataByte(&ch);
	 PORTA = ch ; 
	 TWI_sendStopCondition();
	 
    }
}

