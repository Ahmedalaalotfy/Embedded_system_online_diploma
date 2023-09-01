<<<<<<< HEAD
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
void UART_TxString(u8* string);
void UART_RxString(u8 *string);
void UART_SendNumber(u32 num);
u32 UART_ReceiveNumber(void);



=======
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
void UART_TxString(u8* string);
void UART_RxString(u8 *string);
void UART_SendNumber(u32 num);
u32 UART_ReceiveNumber(void);



>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
#endif /* UART_INTERFACE_H_ */