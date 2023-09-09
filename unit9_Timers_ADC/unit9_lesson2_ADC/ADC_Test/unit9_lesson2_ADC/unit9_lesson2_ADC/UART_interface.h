/*
 * UART_interface.h
 *
 * Created: 10/4/2022 9:30:13 AM
 *  Author: ahmed
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_init(void);
void UART_TxChar(u8 data);
void UART_RxChar(u8* returnedData);
void UART_TxString(u8* String);



#endif /* UART_INTERFACE_H_ */