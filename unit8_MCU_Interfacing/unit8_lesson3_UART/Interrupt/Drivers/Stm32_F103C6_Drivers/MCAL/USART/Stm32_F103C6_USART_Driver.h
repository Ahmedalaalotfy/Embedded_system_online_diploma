/*
 * Stm32_F103C6_USART_Driver.h
 *
 *  Created on: Aug 16, 2023
 *      Author: ahmed
 */

#ifndef INC_STM32_F103C6_USART_DRIVER_H_
#define INC_STM32_F103C6_USART_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------

#include "stm32f103x6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_RCC_Driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
  uint8_t         USART_Mode ;        // Specifies Tx/Rx Enable/Disable
	                                  // This parameter must be defined based on @ref UART_Mode_define

  uint32_t        BaudRate ;          // Configures communication baud rate
	                                  // This parameter must be defined based on @ref UART_BaudRate_define

  uint8_t         Payload_Length;     // Specifies the number of data bits to be transmitted or recieved
	                                  // This parameter must be defined based on @ref UART_Payload_Length_define

  uint8_t         Parity;             // Specifies parity mode
	                                  // This parameter must be defined based on @ref UART_Parity_define

  uint8_t         StopBits;           // Specifies the number of stop bits to be transmitted or recieved
	                                  // This parameter must be defined based on @ref UART_StopBits_define

  uint8_t         HwFlowCtl;          // Specifies whether the hardware flow control is enabled or not
	                                  // This parameter must be defined based on @ref UART_HWFlowCtrl_define

  uint8_t         IRQ_Enable;         // Specifies whether the hardware flow control is enabled or not
	                                  // This parameter must be defined based on @ref UART_HWFlowCtrl_define

  void(*P_IRQ_CallBack)(void);	      // Set the C function which will be called once the IRQ happens

}USART_Config_t;


//-----------------------------
//Macros Configuration References
//-----------------------------


/* @ref UART_Mode_define */
#define UAERT_Mode_RX                       (uint32_t)(1<<2)   // Bit 2 RE: Receiver enable
#define UAERT_Mode_TX                       (uint32_t)(1<<3)   // Bit 3 TE: Transmitter enable
#define UAERT_Mode_TX_RX                    (uint32_t)(1<<2 | 1<<3)

/* @ref UART_BaudRate_define */
#define UART_BaudRate_2400                   2400
#define UART_BaudRate_9600                   9600
#define UART_BaudRate_19200                  19200
#define UART_BaudRate_57600                  57600
#define UART_BaudRate_115200                 115200
#define UART_BaudRate_230400                 230400
#define UART_BaudRate_460800                 460800
#define UART_BaudRate_921600                 921600
#define UART_BaudRate_2250000                2250000
#define UART_BaudRate_4500000                4500000

/* @ref UART_Payload_Length_define */
#define UART_Payload_Length_8B				(uint32_t)(0)
#define UART_Payload_Length_9B				(uint32_t)(1<<12)

/* @ref UART_Parity_define */
#define UART_Parity_NONE					(uint32_t)(0)
#define UART_Parity_EVEN					(uint32_t)(1<<10)
#define	UART_Parity_ODD						((uint32_t)(1<<10 | 1<<9))

/* @ref UART_StopBits_define */
#define UART_StopBits_Half					(uint32_t)(1<<12)
#define UART_StopBits_1						(uint32_t)(0)
#define UART_StopBits_1AndHalf				(uint32_t)(3<<12)
#define UART_StopBits_2						(uint32_t)(2<<12)


/* @ref UART_HWFlowCtrl_define */
#define UART_HWFlowCtrl_NONE				(uint32_t)(0)
#define UART_HWFlowCtrl_RTS					(uint32_t)(1<<8)
#define UART_HWFlowCtrl_CTS					(uint32_t)(1<<9)
#define UART_HWFlowCtrl_RTS_CTS				(uint32_t)(1<<8 | 1<<9)

/* @ref UART_IRQ_Enable_define */
#define UART_IRQ_Enable_NONE				(uint32_t)(0)
#define UART_IRQ_Enable_TXE					(uint32_t)(1<<7)	// Transmit data register empty
#define UART_IRQ_Enable_TC					(uint32_t)(1<<6)    // Transmission complete
#define UART_IRQ_Enable_RXNE				(uint32_t)(1<<5)    // Received data ready to be read
#define UART_IRQ_Enable_PE					(uint32_t)(1<<8)	// Parity error

enum Polling_Mechanism
{
	enable ,
	disable
};



/*BaudRate Calculation*/

// USARTDIV = fclk / (16* Baudrate)
// USARTDIV_MUL100 = 25*fclk / (4* Baudrate)
// DIV_Mantissa_MUL100 = Integar Part of (USARTDIV) * 100
// DIV_Mantissa = Integar Part of (USARTDIV)
// DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) * 16 ) / 100

#define USARTDIV(_PCLK_,_BAUD_)						(uint32_t)(_PCLK_/(16 * _BAUD_))
#define USARTDIV_MUL100(_PCLK_,_BAUD_)				(uint32_t)((25 * _PCLK_)/(4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_,_BAUD_)				(uint32_t)(USARTDIV(_PCLK_,_BAUD_)*100)
#define Mantissa(_PCLK_,_BAUD_)						(uint32_t)(USARTDIV(_PCLK_,_BAUD_))
#define DIV_Fraction(_PCLK_,_BAUD_)					(uint32_t)(((USARTDIV_MUL100(_PCLK_,_BAUD_) - Mantissa_MUL100(_PCLK_,_BAUD_)) * 16)/100)
#define UART_BRR_Register(_PCLK_,_BAUD_)			((Mantissa(_PCLK_,_BAUD_) << 4) | (DIV_Fraction(_PCLK_,_BAUD_) & 0xf))

/*
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/

void MCAL_UART_Init(USART_TypeDef* USARTx, USART_Config_t* UART_Config);
void MCAL_UART_DeInit(USART_TypeDef* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx);

void MCAL_UART_SendData(USART_TypeDef* USARTx,uint16_t* pTxBuffer , enum Polling_Mechanism PollingEN);
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx,uint16_t* pRxBuffer , enum Polling_Mechanism PollingEN);

void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx);

//to do MCAL_USART_LIN_Init ()  					//LIN
//to do MCAL_USART_Init ()  						//Synchronous
//to do  MCAL_USART_DMA_Init () 					// Multibuffer Communication


#endif /* INC_STM32_F103C6_USART_DRIVER_H_ */
