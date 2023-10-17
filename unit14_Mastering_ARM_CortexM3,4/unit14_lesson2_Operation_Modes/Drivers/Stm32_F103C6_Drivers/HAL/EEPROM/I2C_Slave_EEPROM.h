/*
 * I2C_Slave_EEPROM.h
 *
 *  Created on: Sep 5, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef HAL_EEPROM_I2C_SLAVE_EEPROM_H_
#define HAL_EEPROM_I2C_SLAVE_EEPROM_H_


#include "Stm32_F103C6_I2C_Driver.h"

// E2PROM is an I2C Slave
// Idle Mode : device is in hig_Impedance state and wait for data .
// Master Transmitter Mode : the device is transmit data to the slave receiver .
// Master Receiver Mode : the device is receive data from the slave transmitter .

#define EEPROM_Slave_Address	0x2A

void EEPROM_Init(void);
uint8_t EEPROM_Write_Nbytes(uint32_t Memory_Address , uint8_t* bytes , uint8_t Data_Length);
uint8_t EEPROM_Read_byte(uint32_t Address , uint8_t* dataOut , uint8_t Data_Length);


#endif /* HAL_EEPROM_I2C_SLAVE_EEPROM_H_ */
