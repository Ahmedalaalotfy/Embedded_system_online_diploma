/*
 * TWI_interface.h
 *
 * Created: 10/6/2022 1:25:05 PM
 *  Author: ahmed
 */ 


#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_

void TWI_initMaster(void);
void TWI_initSlave(u8 SlaveAdd);
void TWI_sendStartCondition(void);
void TWI_sendRepStartCondition(void);
void TWI_sendStopCondition(void);
void TWI_sendSlaveAddWithWrite(u8 SlaveAdd);
void TWI_sendSlaveAddWithRead(u8 SlaveAdd);
void TWI_sendMasterDataByte(u8 data);
void TWI_readMasterDataByte(u8* returnedData);


#endif /* TWI_INTERFACE_H_ */