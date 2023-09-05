/*
 * I2C_Slave_EEPROM.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Ahmedalaalotfy
 */

#include "I2C_Slave_EEPROM.h"


void EEPROM_Init(void)
{

	/*======================= I2C INIT =====================*/
	// 			PB6:I2C1_SCL
	// 			PB7:I2C1_SDA

	I2C_Config_t I2C1CFG ;

	//I2C Controller act as Master

	I2C1CFG.General_Call_Adress_Detection = I2C_ENGC_Enable ;
	I2C1CFG.I2C_ACK_Control = I2C_ACK_Enable ;
	I2C1CFG.I2C_ClockSpeed = I2C_SCLK_SM_100K ;
	I2C1CFG.I2C_Mode =I2C_Mode_I2C ;
	I2C1CFG.P_Slave_Event_CallBack = NULL ;
	I2C1CFG.StrechMode = I2C_StretchMode_Enable ;

	MCAL_I2C_GPIO_Set_Pins(I2C1);
	MCAL_I2C_Init(I2C1, &I2C1CFG);

}

uint8_t EEPROM_Write_Nbytes(uint32_t Memory_Address , uint8_t* bytes , uint8_t Data_Length)
{
	uint8_t i=0;

	//MISRA C++ 2008 --> Dynamic heap memory allocation shall not be used
	//Violate MISRA Rule
	//(uint8_t*)malloc(Data_Length+2) ;
	uint8_t buffer[256];

	buffer[0] = (uint8_t)(Memory_Address>>8); // Upper Byte Memory Address
	buffer[1] = (uint8_t)(Memory_Address);	   // Lower Byte Memory Address

	for(i=2 ; i< (Data_Length+2) ; i++)
	{buffer[i] = bytes[i-2];}

	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, (Data_Length+2), WithStop, Start);// Write the data at the Slave address

	return 0;
}
uint8_t EEPROM_Read_byte(uint32_t Address , uint8_t* dataOut , uint8_t Data_Length)
{
	uint8_t buffer[2];
	buffer[0] = (uint8_t)(Address>>8); // Upper Byte Memory Address
	buffer[1] = (uint8_t)Address;	   // Lower Byte Memory Address

	MCAL_I2C_Master_TX(I2C1, EEPROM_Slave_Address, buffer, 2 , WithoutStop, Start);// Send The address
	MCAL_I2C_Master_RX(I2C1, EEPROM_Slave_Address, dataOut, Data_Length , WithStop, RepeatedStart);// Read the data at the address

	return 0;
}
