/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"
#include "stm32f103x6.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KPD_interface.h"
#include "KPD_config.h"


unsigned int IRQ_Flag = 0 ;
IRQ_Flag = 1 ;

void clock_init()
{
	//Enable clock GPIOA
	RCC_GPIOA_CLK_EN() ;

	//Enable clock GPIOB
	RCC_GPIOB_CLK_EN() ;

	//Enable clock AFIO
	AFIO_GPIOE_CLK_EN() ;



}
void GPIO_init()
{
	LCD_GPIO_Init();
	KPD_GPIO_Init();
}

void wait (int x)
{
	unsigned int i , j ;
	for (i= 0 ; i<x ; i++)
		for (j= 0 ; j<255 ; j++);
}

void EXTI9_CallBack(void)
{
	IRQ_Flag = 1 ;
	LCD_sendString("Ahmedalaalotfy");
	wait(1000);
}

int main(void)
{
	clock_init();
	GPIO_init();
	LCD_init();

	EXTI_PinConfig_t EXTI_CFG;
	EXTI_CFG.EXTI_PIN = EXTI9PB9 ;
	EXTI_CFG.Trigger_Case = EXTI_Trigger_RISING ;
	EXTI_CFG.P_IRQ_CallBack = EXTI9_CallBack ;
	EXTI_CFG.IRQ_EN = EXTI_IRQ_Enable ;

	MCAL_EXTI_GPIO_Init(&EXTI_CFG);

	IRQ_Flag = 1 ;

	while (1)
	{

      if (IRQ_Flag)
      {
    	  LCD_clear();
    	  IRQ_Flag = 0 ;
      }

	}



}
