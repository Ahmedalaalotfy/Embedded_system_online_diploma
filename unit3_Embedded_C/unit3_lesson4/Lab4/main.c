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
#include <stdint.h>

#define SYSCTL_RCGC2_R    *(volatile uint32_t *) (0x400FE108)
#define GPIO_PORTF_DIR_R  *(volatile uint32_t *) (0x40025400)
#define GPIO_PORTF_DEN_R  *(volatile uint32_t *) (0x4002551C)
#define GPIO_PORTF_DATA_R *(volatile uint32_t *) (0x400253FC)


int main(void)
{

    volatile uint32_t delay_count; 

SYSCTL_RCGC2_R = 0x20; 
// delay to make sure GPIO is up and running 
for (delay_count = 0 ; delay_count<200;delay_count++);

GPIO_PORTF_DIR_R |= 1<<3 ;  
//Dir is output for pin 3 port F 

GPIO_PORTF_DEN_R |= 1<<3 ;


	while (1)
	{
      GPIO_PORTF_DATA_R |= 1<<3 ;
     for (delay_count = 0 ; delay_count<200000;delay_count++);
      GPIO_PORTF_DATA_R &= ~(1<<3) ;
     for (delay_count = 0 ; delay_count<200000;delay_count++);
	}


}
