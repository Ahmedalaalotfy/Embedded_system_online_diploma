<<<<<<< HEAD
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
unsigned char SPI_MasterTransmit(unsigned char cData) ;
unsigned char SPI_SlaveRecieve(unsigned char cData) ;


=======
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
unsigned char SPI_MasterTransmit(unsigned char cData) ;
unsigned char SPI_SlaveRecieve(unsigned char cData) ;


>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
#endif /* SPI_INTERFACE_H_ */