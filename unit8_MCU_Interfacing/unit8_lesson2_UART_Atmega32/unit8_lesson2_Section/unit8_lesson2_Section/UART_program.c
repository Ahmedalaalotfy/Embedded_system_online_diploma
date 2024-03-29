/*
 * UART_program.c
 *
 * Created: 10/4/2022 9:29:51 AM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "UART_interface.h"

void UART_init(void)
{
    // writing the UCSRC, // Select UART mode = Asynchronous , // configure no parity .... 
	UCSRC = 0X86 ; // 0b1000110
    CLR_BIT(UCSRB,2); 
	
	// Set buad rate = 9600 ;
	UBRRL = 103 ;

    // Enable Tx
	SET_BIT(UCSRB,3);
    // Enable Rx
	SET_BIT(UCSRB,4);
}
 
void UART_TxChar(u8 data)
{
    UDR = data ;
	while (0== GET_BIT(UCSRA,5)); 	
}

void UART_RxChar(u8* returnedData)
{
	 if (returnedData != NULL)
	 {
		 while (0== GET_BIT(UCSRA,7)); 
		 *returnedData = UDR ; 
	 }
}

void UART_TxString(u8* string)
{
	u8 i ; 
	for (i = 0 ; i<string[i] ; i++)
	{
		UART_TxChar(string[i]);
	}
	
	UART_TxChar('\r');
}


void UART_RxString(u8 *string)
{

<<<<<<< HEAD
void UART_RxChar(u8* returnedData)
{
	 if (returnedData != NULL)
	 {
		 while (0== GET_BIT(UCSRA,7)); 
		 *returnedData = UDR ; 
	 }
}

void UART_TxString(u8* string)
{
	u8 i ; 
	for (i = 0 ; i<string[i] ; i++)
	{
		UART_TxChar(string[i]);
	}
	
	UART_TxChar('\r');
}


void UART_RxString(u8 *string)
{

    u8 i = 0; 
	UART_RxChar(&string[i]);  
	while(string[i] != '\r' )
	{ // when press enter stop recieve 
		i++;
		UART_RxChar(&string[i]);
	}
	
	string[i] = '\0' ; 
} 

void UART_SendNumber(u32 num)
{
	u8 *p=&num ; 
	UART_TxChar(p[0]);
	UART_TxChar(p[1]);
	UART_TxChar(p[2]);
	UART_TxChar(p[3]);
}

u32 UART_ReceiveNumber(void)
{
	u32 num ; 
	u8 *p=&num ; 
	UART_RxChar(p[0]);
	UART_RxChar(p[1]);
	UART_RxChar(p[2]);
	UART_RxChar(p[3]);
=======
    u8 i = 0; 
	UART_RxChar(&string[i]);  
	while(string[i] != '\r' )
	{ // when press enter stop recieve 
		i++;
		UART_RxChar(&string[i]);
	}
>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
	
	string[i] = '\0' ; 
} 

void UART_SendNumber(u32 num)
{
	u8 *p=&num ; 
	UART_TxChar(p[0]);
	UART_TxChar(p[1]);
	UART_TxChar(p[2]);
	UART_TxChar(p[3]);
}

u32 UART_ReceiveNumber(void)
{
	u32 num ; 
	u8 *p=&num ; 
	UART_RxChar(p[0]);
	UART_RxChar(p[1]);
	UART_RxChar(p[2]);
	UART_RxChar(p[3]);
	
	return num ;
}