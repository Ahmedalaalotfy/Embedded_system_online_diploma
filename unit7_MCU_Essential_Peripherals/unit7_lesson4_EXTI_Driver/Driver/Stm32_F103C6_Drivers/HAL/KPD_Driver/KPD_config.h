/*
 * KPD_config.h
 *
 * Created: 9/13/2022 10:03:26 AM
 *  Author: ahmed
 */ 


#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#include "Stm32_F103C6_GPIO_Driver.h"

#define KPD_COLS_PORT    GPIOA

#define KPD_COL0_PIN     GPIO_PIN_4
#define KPD_COL1_PIN     GPIO_PIN_5
#define KPD_COL2_PIN     GPIO_PIN_6
#define KPD_COL3_PIN     GPIO_PIN_7

#define KPD_ROWS_PORT    GPIOA

#define KPD_ROW0_PIN     GPIO_PIN_0
#define KPD_ROW1_PIN     GPIO_PIN_1
#define KPD_ROW2_PIN     GPIO_PIN_2
#define KPD_ROW3_PIN     GPIO_PIN_3

#define KPD_KEYS {'7','8','9','/', \
	              '4','5','6','*', \
	              '1','2','3','-', \
	              'D','0','=','+'}




#endif /* KPD_CONFIG_H_ */
