/*
 * SPI_interface.h
 *
 * Created: 10/4/2022 1:04:06 PM
 *  Author: ahmed
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_initMaster(void);
void SPI_initSlave(void);
void SPI_transieve(u8 TxData,u8* RxData);


#endif /* SPI_INTERFACE_H_ */