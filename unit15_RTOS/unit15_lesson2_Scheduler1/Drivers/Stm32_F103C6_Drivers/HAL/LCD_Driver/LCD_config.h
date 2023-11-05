/*
 * LCD_config.h
 *
 * Created: 9/11/2022 11:29:37 AM
 *  Author: ahmed
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "Stm32_F103C6_GPIO_Driver.h"

/* Macros For Rs configuration */
#define LCD_RS_PORT           GPIOA
#define LCD_RS_PIN            GPIO_PIN_15

/* Macros For Rw configuration */
#define LCD_RW_PORT           GPIOA
#define LCD_RW_PIN            GPIO_PIN_12

/* Macros For En configuration */
#define LCD_EN_PORT           GPIOA
#define LCD_EN_PIN            GPIO_PIN_11

/* Options FOR LCD Mode:
1- LCD_8_BIT_MODE
2- LCD_4_BIT_MODE */
#define LCD_MODE LCD_4_BIT_MODE

#define LCD_DATA_PORT         GPIOB


/* 4 Bit Mode Pins Configurtion */


#define LCD_D4_PIN            GPIO_PIN_5
#define LCD_D4_PORT           GPIOB

#define LCD_D5_PIN            GPIO_PIN_4
#define LCD_D5_PORT           GPIOB

#define LCD_D6_PIN            GPIO_PIN_3
#define LCD_D6_PORT           GPIOB

#define LCD_D7_PIN            GPIO_PIN_10
#define LCD_D7_PORT           GPIOB



#endif /* LCD_CONFIG_H_ */

