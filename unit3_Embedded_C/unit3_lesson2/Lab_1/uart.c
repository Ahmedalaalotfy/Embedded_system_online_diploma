#include "uart.h"

#define UART0_DR *((volatile unsigned int* const)((unsigned int*)0x101f1000))


void Uart_send_string( unsigned char *P_tx_string) 
{
    
   while(*P_tx_string != '\0') // loop until end of string 
   {
   	  UART0_DR  = (unsigned int)*P_tx_string ; // transmit char 
   	  P_tx_string++; //increment to next char 
   }
}