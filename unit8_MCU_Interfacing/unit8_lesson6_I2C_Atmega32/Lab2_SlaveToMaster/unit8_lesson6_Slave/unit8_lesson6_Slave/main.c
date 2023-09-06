/*
 * unit8_lesson6_I2C_Slave.c
 *
 * Created: 9/6/2023 3:41:24 PM
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
	u8 ch = 0 ;
	TWI_initSlave(0b01010000); 
    while (1) 
    {
	   TWI_Slave_Read(1) ;  
	   TWI_Slave_Write(ch++) ;
    }
}

