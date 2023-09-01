/*
 * Stm32_F103C6_USART_Driver.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Ahmedalaalotfy
 */


#include <Stm32_F103C6_USART_Driver.h>


/*
 * =====================================================================================
 * 							Generic Variables
 * =====================================================================================
 */

USART_Config_t* Global_UART_Config = NULL ;


/*
 * =====================================================================================
 * 							Generic Macros
 * =====================================================================================
 */


/*
 * =====================================================================================
 * 							Generic Functions
 * =====================================================================================
 */




/*
 * =====================================================================================
 * 							APIS Supported by "MCAL USART driver"
 * =====================================================================================
 */

/**================================================================
 * @Fn					- MCAL_UART_Init
 * @brief 				- Initializes UART (Supported feature : ASYNCHRONOUS only)
 * @param [in] 			- USARTx: where x can be (1..3) depending on the device used
 * @param [in] 			- UARTCfg: All the UART configurations
 * @retval 				- None
 * Note					- The driver supports Asynchronous mode & HSI clock 8 Mhz
 */
void MCAL_UART_Init(USART_TypeDef* USARTx, USART_Config_t* UART_Config)
{
	Global_UART_Config = UART_Config ;
	uint32_t PCLK , BRR ;

	// Enable the clock for given USART peripheral
	if(USARTx == USART1)
			RCC_USART1_CLK_EN();
		else if(USARTx == USART2)
			RCC_USART2_CLK_EN();
		else if(USARTx == USART3)
			RCC_USART3_CLK_EN();

	// Enable the USART Module (Bit 13 UE: USART enable)
	USARTx->CR1 |= (1<<13) ;

	//Enable TX / RX according to the USART_MODE configuration item
	//USART1_CR1 >> Bit 3 TE: Transmitter enable & Bit 2 RE: Receiver enable
	USARTx->CR1 |=  UART_Config->USART_Mode ;

	//Payload length 8 or 9 bit
	//USART1_CR1 >> Bit 12 M: Word length
	USARTx->CR1 |=  UART_Config->Payload_Length ;

	//configure of parity control bit field
	//USART1_CR1 >> Bit 10 PCE: Parity control enable & Bit 9 PS: Parity selection
	USARTx->CR1 |=  UART_Config->Parity ;

	//configure stop bits	USART_CR2  Bits 13:12 STOP: STOP bits
	USARTx->CR1 |=  UART_Config->StopBits ;

	//USART Hardware Flow Control
	//USART_CR3 >> Bit 8 RTSE: RTS enable & Bit 9 CTSE: CTS enable
	USARTx->CR1 |=  UART_Config->HwFlowCtl ;

	// Configuration BoadRate
	// PCLK1 for USART2 , 3
	// PCLK2 for USART1

	if (USARTx == USART1)
		{
			PCLK = MCAL_RCC_GetPCLK2Freq();
		}
		else
		{
			PCLK = MCAL_RCC_GetPCLK1Freq();
		}

  BRR = UART_BRR_Register(PCLK , UART_Config->BaudRate) ;
  USARTx->BRR = BRR ;

  if(UART_Config->IRQ_Enable != UART_IRQ_Enable_NONE)
  	{
  		USARTx->CR1 |= UART_Config->IRQ_Enable ;
  		//Enable E=interrupt on NVIC
  		if (USARTx == USART1)
  			NVIC_IRQ37_USART1_Enable() ;
  		else if (USARTx == USART2)
  			NVIC_IRQ38_USART2_Enable() ;
  		else if (USARTx == USART3)
  			NVIC_IRQ39_USART3_Enable() ;
  	}

}

/**================================================================
 * @Fn				  - MCAL_UART_DeInit
 * @brief			  - DeInitialization UART (Supported feature Asynch. Only).
 * @param[in]		  - USARTx: where x can be (1..3 depending on device used).
 * @retval			  - NONE
 * Note				  - Reset the model by RCC
 * */

void MCAL_UART_DeInit(USART_TypeDef* USARTx)
{
	if (USARTx == USART1)
	{
		RCC_USART1_CLK_Reset() ;
		NVIC_IRQ37_USART1_Disable() ;
	}

	else if (USARTx == USART2)
	{
		RCC_USART2_CLK_Reset() ;
		NVIC_IRQ38_USART2_Disable() ;
	}

	else if (USARTx == USART3)
	{
		RCC_USART3_CLK_Reset() ;
		NVIC_IRQ39_USART3_Disable() ;
	}

}


/*******************************************************************************************************************
 * 		@Fn               - MCAL_UART_SendData
 * 		@brief            -send buffer on UART
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 *		param[in]         -PtxBuffer: the buffer that will be transmitted
 *		param[in]          -PollingEn enable or disable the polling
 * 		@retval           -none
 * 		Note              -Should initialize UART First
 * 							When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register),
 *							the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect
 *							because it is replaced by the parity.
 *  						When receiving with the parity enabled, the value read in the MSB bit is the received parity
 *
 ********************************************************************************************************************/
void MCAL_UART_SendData(USART_TypeDef* USARTx,uint16_t* pTxBuffer , enum Polling_Mechanism PollingEN)
{
	// Enable Polling
	// Wait until TXE flag is set in the >> USAERx_SR
	//if this bit-7 is 1 that's mean the register is empty & can to send data.
   if (PollingEN == enable)
	   while(! (USARTx->SR & 1<<7));

   //Check the USART_Wordlength item for 9BIT or 8BIT in a frame
   	if (Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
   	{
   		USARTx->DR = (*pTxBuffer & (uint16_t) 0x01FF);
   	}else
   	{
   		// this is 8bit data transfer
   		USARTx->DR = (*pTxBuffer & (uint8_t) 0xFF);
   	}


}

void MCAL_UART_WAIT_TC(USART_TypeDef* USARTx)
{
	// Wait till TC flag is set in the SR
	while (! (USARTx->SR & 1<<6) );
}

/*******************************************************************************************************************
 * 		@Fn               - MCAL_USAET_RecieveData
 * 		@brief            -receive buffer from UART
 *		param[in]         -USARTX :where x can be 1,2,3 depending on device used
 *		param[in]         -PtxBuffer: the recieved buffer
 *		param[in]          -PollingEn enable or disable the polling
 * 		@retval           -none
 * 		Note              -none																										*
 ********************************************************************************************************************/
void MCAL_UART_ReceiveData(USART_TypeDef* USARTx,uint16_t* pRxBuffer , enum Polling_Mechanism PollingEN)
{
	//wait until RXNE is set
		if (PollingEN == enable)
		{
			while(!(USARTx->SR &(1<<5)));
		}


		if(Global_UART_Config->Payload_Length == UART_Payload_Length_9B)
		{
			if(Global_UART_Config->Parity == UART_Parity_NONE)
			{
				//no parity so all 9bits are data
				*((uint16_t*)pRxBuffer) = USARTx->DR ;
			}
			else
			{
				//if parity is used so 8bit is data and the last one is parity
				*((uint16_t*)pRxBuffer) =( USARTx->DR & (uint8_t)0xFF);
			}
		}

		else //8 bit data
		{
			if(Global_UART_Config->Parity == UART_Parity_NONE)
			{
				//no parity so all 8bits are data
				*((uint16_t*)pRxBuffer) = (USARTx->DR   & (uint8_t)0xFF);

			}else{
				//if parity is used so 8bit is data and the last one is parity
				*((uint16_t*)pRxBuffer) =( USARTx->DR & (uint8_t)0x7F);
			}
		}
}



/*••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 * @Fn							- MCAL_UART_GPIO_Set_Pins
 * @brief						- Initialization GPIO Pins for UART (Supported feature Asynch. Only).
 * @param[in]					- USARTx: where x can be (1..3 depending on device used).
 * @retval						- NONE
 * Note							- Sould Enable the corresponding AFIO & GPIO in RCC clock also called after MCAL_UART_Init()
 * */
void MCAL_UART_GPIO_Set_Pins(USART_TypeDef* USARTx)
{
	GPIO_PinConfig_t PinCfg ;

		if(USARTx == USART1)
		{
			//PA9  >>	TX
			//PA10 >>	RX
			//PA11 >>	CTS
			//PA12 >>	RTS

			//PA9  >>	TX
			PinCfg.GPIO_PinNumber = GPIO_PIN_9 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA10 >>	RX
			PinCfg.GPIO_PinNumber = GPIO_PIN_10 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_AF;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA11 >>	CTS
			if(Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_CTS	 || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS )
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_11 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_Init(GPIOA, &PinCfg);

			}

			//PA12 >>	RTS
			if (Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_12 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}
		}

		else if(USARTx == USART2)
		{
			//PA2 >>	TX
			//PA3 >>	RX
			//PA0 >>	CTS
			//PA1 >>	RTS

			//PA2 >>	TX
			PinCfg.GPIO_PinNumber = GPIO_PIN_2 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA3 >>	RX
			PinCfg.GPIO_PinNumber = GPIO_PIN_3 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_AF ;
			MCAL_GPIO_Init(GPIOA, &PinCfg);

			//PA0 >>	CTS
			if(Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_CTS	 || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS )
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_0 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_Init(GPIOA, &PinCfg);

			}

			//PA1 >>	RTS
			if (Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_1 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
				MCAL_GPIO_Init(GPIOA, &PinCfg);
			}
		}

		else if(USARTx == USART3)
		{
			//PB10  >>	TX
			//PB11 >>	RX
			//PB13 >>	CTS
			//PB14 >>	RTS

			//PB10  >>	TX
			PinCfg.GPIO_PinNumber = GPIO_PIN_10 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
			PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB11 >>	RX
			PinCfg.GPIO_PinNumber = GPIO_PIN_11 ;
			PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_FLO ;
			MCAL_GPIO_Init(GPIOB, &PinCfg);

			//PB13 >>	CTS
			if(Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_CTS	 || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS )
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_13 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_INPUT_FLO ;
				MCAL_GPIO_Init(GPIOB, &PinCfg);

			}

			//PB14 >>	RTS
			if (Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS || Global_UART_Config->HwFlowCtl == UART_HWFlowCtrl_RTS_CTS)
			{
				PinCfg.GPIO_PinNumber = GPIO_PIN_14 ;
				PinCfg.GPIO_MODE =	GPIO_MODE_OUTPUT_AF_PP ;
				PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M ;
				MCAL_GPIO_Init(GPIOB, &PinCfg);
			}
		}


}


/*
 * =====================================================================================
 * 							ISR Functions
 * =====================================================================================
 */

void USART1_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}
void USART2_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}
void USART3_IRQHandler (void)
{
	Global_UART_Config->P_IRQ_CallBack();
}



