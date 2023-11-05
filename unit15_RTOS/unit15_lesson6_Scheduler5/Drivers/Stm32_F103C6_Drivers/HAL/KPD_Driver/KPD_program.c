/*
 * KPD.c
 *
 * Created: 9/13/2022 10:02:15 AM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "BIT_MATH.h"
#include "stm32f103x6.h"

/* MCAL */
#include "Stm32_F103C6_GPIO_Driver.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h"



void KPD_GPIO_Init(void)
{

	GPIO_PinConfig_t PinCfg ;

	// KPD
	PinCfg.GPIO_PinNumber = KPD_COL0_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PD;
	PinCfg.GPIO_Output_Speed = 0x00;
	MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_COL1_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_COL2_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_COL3_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_PD;
	MCAL_GPIO_Init(KPD_ROWS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_ROW0_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_ROW1_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_ROW2_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = KPD_ROW3_PIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_2M;
	MCAL_GPIO_Init(KPD_COLS_PORT, &PinCfg);

	MCAL_GPIO_WritePort(KPD_ROWS_PORT, 0xFF);

}

void KPD_getValue(uint8_t *returnedValue)

{
	uint8_t coloumnsPins[4]= {KPD_COL0_PIN, KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN} ;
	uint8_t rowsPins[4]= {KPD_ROW0_PIN, KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	uint8_t KPD_Chars[4][4]	= KPD_KEYS;
	if (returnedValue != NULL)
	{
		*returnedValue = KPD_NOT_PRESSED ;
		uint8_t colsCounter ,rowsCounter ;
		uint8_t pinValue ;
		uint8_t pinFlag=0 ;
		for (colsCounter=0 ; colsCounter<4 ; colsCounter++)
		{
			// Actviate each cols
			MCAL_GPIO_WritePin(KPD_COLS_PORT,coloumnsPins[colsCounter],GPIO_PIN_RESET);

			// Loop to check Rows Values
			for (rowsCounter=0 ; rowsCounter<4 ; rowsCounter++)
			{
				pinValue = MCAL_GPIO_ReadPin(KPD_ROWS_PORT,rowsPins[rowsCounter]);

				if(0==pinValue)
				{
					*returnedValue = KPD_Chars[rowsCounter][colsCounter];
					while (pinValue==0)
					{
						pinValue = MCAL_GPIO_ReadPin(KPD_ROWS_PORT,rowsPins[rowsCounter]);
					}
					pinFlag =1 ;
					break ;
				}else{
					*returnedValue='N';
				}
			}
			// Deactviate each cols
			MCAL_GPIO_WritePin(KPD_COLS_PORT,coloumnsPins[colsCounter],GPIO_PIN_SET);
			if (1==pinFlag)
			{
				break ;
			}
		}
	}
}


unsigned char Get_Pressed_KEY(void){
	uint8_t coloumnsPins[4]= {KPD_COL0_PIN, KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN} ;
	uint8_t rowsPins[4]= {KPD_ROW0_PIN, KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	int i,j;
	for(i=0;i<4;i++){

		MCAL_GPIO_WritePin(KPD_COLS_PORT,rowsPins[0],GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KPD_COLS_PORT,rowsPins[1],GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KPD_COLS_PORT,rowsPins[2],GPIO_PIN_RESET);
		MCAL_GPIO_WritePin(KPD_COLS_PORT,rowsPins[3],GPIO_PIN_RESET);
		//            dms(200);
		MCAL_GPIO_WritePin(KPD_COLS_PORT,rowsPins[i],GPIO_PIN_SET);
		//    wait_ms(30);
		for(j=0;j<4;j++){

			if(MCAL_GPIO_ReadPin(KPD_COLS_PORT, coloumnsPins[j])){
				while(MCAL_GPIO_ReadPin(KPD_COLS_PORT, coloumnsPins[j]));
				switch(i){
				case 0:
					if (j==0) return '7';
					if (j==1) return '8';
					if (j==2) return '9';
					if (j==3) return '/';
					break;
				case 1:
					if (j==0) return '4';
					if (j==1) return '5';
					if (j==2) return '6';
					if (j==3) return '*';

					break;
				case 2:
					if (j==0) return '1';
					if (j==1) return '2';
					if (j==2) return '3';
					if (j==3) return '-';
					break;
				case 3:
					if (j==0) return 'D';
					if (j==1) return '0';
					if (j==2) return '=';
					if (j==3) return '+';
					break;
				default:
					break;
				}
			}
		}

	}
	return 'N';

}





