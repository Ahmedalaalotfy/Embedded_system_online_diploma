/*
 * Stm32_F103C6_GPIO_Driver.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Ahmedalaalotfy
 */


#include "Stm32_F103C6_GPIO_Driver.h"


uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case GPIO_PIN_0:
		return 0;
		break;

	case GPIO_PIN_1:
		return 4;
		break;

	case GPIO_PIN_2:
		return 8;
		break;

	case GPIO_PIN_3:
		return 12;
		break;

	case GPIO_PIN_4:
		return 16;
		break;

	case GPIO_PIN_5:
		return 20;
		break;

	case GPIO_PIN_6:
		return 24;
		break;

	case GPIO_PIN_7:
		return 28;
		break;

	case GPIO_PIN_8:
		return 0;
		break;

	case GPIO_PIN_9:
		return 4;
		break;

	case GPIO_PIN_10:
		return 8;
		break;

	case GPIO_PIN_11:
		return 12;
		break;

	case GPIO_PIN_12:
		return 16;
		break;

	case GPIO_PIN_13:
		return 20;
		break;

	case GPIO_PIN_14:
		return 24;
		break;

	case GPIO_PIN_15:
		return 28;
		break;

	default:
		return 0;
		break;
	}
}

/*
 * @Fn				- MCAL_GPIO_Init
 * @brief 			- Initializes the GPIOx PINy according to the specified parameters in PinConfig
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinConfig : pointer to GPIO_PinConfig_t structure that contains the configurations information for GPIO PIN.
 * @retval			- none
 * Note				- stm32F103c6 MCU has GPIO A,B,C,D,E Modules
 * 					  But LQFP48 package has only GPIO A,B,Part of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx,GPIO_PinConfig_t *PinConfig)
{
	// Port configuration register low  (GPIOx_CRL) configure PINS from 0 ==> 7
	// Port configuration register high (GPIOx_CRH) configure PINS from 8 ==> 15

	volatile uint32_t* configregister = NULL ;
	uint8_t PIN_CONFIG = 0 ;
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ?  &GPIOx->CRL : &GPIOx->CRH ;

	//clear CNF MODE
	(*configregister) &= ~(0xf << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;

	//if PIN is output
	if ( (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_OD)|| (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_AF_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) )
	{
		//Set CNF MODE
		PIN_CONFIG = ( (((PinConfig->GPIO_MODE -4 ) << 2) | (PinConfig->GPIO_Output_Speed)) & 0x0f) ;
	}

	else
	{
		if ( (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog) )
		{
			//set CNF
			PIN_CONFIG = ( (((PinConfig->GPIO_MODE ) << 2) | (0x00)) & 0x0f) ;
		}
		else if (PinConfig->GPIO_MODE == GPIO_MODE_INPUT_AF ) //Consider it as input floating
		{
			PIN_CONFIG = ( (((GPIO_MODE_INPUT_FLO) << 2) | (0x00)) & 0x0f) ;
		}
		else //PU PD
		{
			PIN_CONFIG = ( (((GPIO_MODE_INPUT_PU) << 2) | (0x00)) & 0x0f) ;

			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				// PXODR = 1 Input pull up
				GPIOx->ODR |= PinConfig->GPIO_PinNumber ;
			}

			else
			{
				// PXODR = 0 Input pull down
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber) ;
			}
		}
	}
	//write on CRL or CRH
	(*configregister) |= ( (PIN_CONFIG) << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;


}


/*=====================================================================
 * @Fn				- MCAL_GPIO_DeInit
 * @brief 			- reset the GPIOx register
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
	// GPIOx->CRL = 0x44444444;
	// GPIOx->CRH = 0x44444444;
	// GPIOx->ODR = 0x00000000;
	// GPIOx->BSRR= 0x00000000;
	// GPIOx->BRR = 0x00000000;
	// GPIOx->LCKR = 0x00000000;


	//Or you can use Reset Controller
	//APB2 peripheral reset register (APB2RSTR)
	//Set and cleared by software

	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR &= ~(1<<2); // Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR |= (1<<2);
	}
	else if(GPIOx == GPIOB)
	{
		RCC->APB2RSTR &= ~(1<<3); // Bit 3 IOPBRST: IO port B reset
		RCC->APB2RSTR |= (1<<3);
	}
	else if(GPIOx == GPIOC)
	{
		RCC->APB2RSTR &= ~(1<<4); // Bit 4 IOPCRST: IO port C reset
		RCC->APB2RSTR |= (1<<4);
	}
	else if(GPIOx == GPIOD)
	{
		RCC->APB2RSTR &= ~(1<<5); // Bit 5 IOPDRST: IO port D reset
		RCC->APB2RSTR |= (1<<5);
	}
	else if(GPIOx == GPIOE)
	{
		RCC->APB2RSTR &= ~(1<<6); // Bit 6 IOPERST: IO port E reset
		RCC->APB2RSTR |= (1<<6);
	}
}


/*=====================================================================
 * @Fn				- MCAL_GPIO_ReadPin
 * @brief 			- Read specific PIN
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber : Set PinNumber according @ref GPIO_PINS_define
 * @retval			- the input PIN value (two values based on @ref GPIO_PIN_state)
 * Note				- none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx,uint16_t PinNumber )
{
	uint8_t BitStatus ;
	if ( ((GPIOx->IDR) & PinNumber ) != (uint32_t)GPIO_PIN_RESET)
	{
		BitStatus = GPIO_PIN_SET ;
	}
	else
	{
		BitStatus = GPIO_PIN_RESET ;
	}

	return BitStatus ;
}

/*=====================================================================
 * @Fn				- MCAL_GPIO_ReadPort
 * @brief 			- Read specific Port
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			- the input Port value
 * Note				- none
 */

uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx )
{
	uint16_t Port_Value;
	Port_Value = (uint16_t)(GPIOx->IDR) ;
	return Port_Value ;
}


/*=====================================================================
 * @Fn				- MCAL_GPIO_WritePin
 * @brief 			- Write specific PIN
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber : Specifies the port bit to write. Set by @ref GPIO_PINS_define
 * @param [in] 		- Value : Pin Value
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx,uint16_t PinNumber, uint8_t Value)
{
	if ( Value != GPIO_PIN_RESET)
	{
		//GPIOx->ODR = GPIO_PIN_SET ;
		// OR
		//		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Set the corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber ;
	}
	else
	{
		// GPIOx->ODR = GPIO_PIN_RESET ;
		//OR
		//		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		//		These bits are write-only and can be accessed in Word mode only.
		//		0: No action on the corresponding ODRx bit
		//		1: Reset the corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber ;
	}
}


/*=====================================================================
 * @Fn				- MCAL_GPIO_WritePort
 * @brief 			- Write specific Port
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- Value : Pin Value
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx, uint16_t Value )
{
	GPIOx->ODR = (uint32_t)Value ;
}


/*=====================================================================
 * @Fn				- MCAL_GPIO_TogglePin
 * @brief 			- Toggle specific PIN
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber : Specifies the port bit to write. Set by @ref GPIO_PINS_define
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx,uint16_t PinNumber)
{
	GPIOx->ODR ^= (PinNumber) ;
}


/*=====================================================================
 * @Fn				- MCAL_GPIO_TogglePort
 * @brief 			- Toggle specific Port
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @retval			- none
 * Note				- none
 */
void MCAL_GPIO_TogglePort(GPIO_TypeDef *GPIOx)
{
	GPIOx->ODR ^= 0xFFFF;
}



/*=====================================================================
 * @Fn				- MCAL_GPIO_LcokPin
 * @brief 			- The locking mechanism allow the IO configurations to be frozen
 * @param [in] 		- GPIOx: where x can be (A..E depending on device used) to select the GPIO peripheral
 * @param [in] 		- PinNumber : Specifies the port bit to write. Set by @ref GPIO_PINS_define
 * @retval			- Ok if pin config is locked or Error if pin not locked (@ref GPIO_RETURN_LOCK)
 * Note				- none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx,uint16_t PinNumber)
{
	//	Bit 16 LCKK[16]: Lock key
	//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
	//	0: Port configuration lock key not active
	//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
	//	LOCK key writing sequence:
	//	Write 1
	//	Write 0
	//	Write 1
	//	Read 0
	//	Read 1 (this read is optional but confirms that the lock is active)
	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
	//	Any error in the lock sequence will abort the lock.

	//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
	//	These bits are read write but can only be written when the LCKK bit is 0.
	//	0: Port configuration not locked
	//	1: Port configuration locked.

	// set LCKK[16]
	volatile uint32_t temp = 1<<16 ;

	// set LCKy
	temp |= PinNumber ;

	//	Write 1
	GPIOx->LCKR = temp ;
	//	Write 0
	GPIOx->LCKR = PinNumber ;
	//	Write 1
	GPIOx->LCKR = temp ;
	//	Read 0
	temp = GPIOx->LCKR ;
	//	Read 1

	if ((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_ENABLED ;
	}
	else
	{
		return GPIO_RETURN_LOCK_ERROR ;
	}

}



