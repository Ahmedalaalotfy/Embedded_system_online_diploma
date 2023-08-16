/*
 * KPD.c
 *
 * Created: 9/13/2022 10:02:15 AM
 *  Author: ahmed
 */ 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "KPD_interface.h"
#include "KPD_config.h" 

void KPD_getValue(u8 *returnedValue)

{
	u8 coloumnsPins[4]= {KPD_COL0_PIN, KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN} ;
    u8 rowsPins[4]= {KPD_ROW0_PIN, KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
	u8 KPD_Chars[4][4]	= KPD_KEYS;
	if (returnedValue != NULL)
	{
		*returnedValue = KPD_NOT_PRESSED ;
		u8 colsCounter ,rowsCounter ;
		u8 pinValue ;
		u8 pinFlag=0 ;
		for (colsCounter=0 ; colsCounter<4 ; colsCounter++)
		{
			// Actviate each cols 
			DIO_setPinValue(KPD_COLS_PORT,coloumnsPins[colsCounter],DIO_PIN_LOW);
			
			// Loop to check Rows Values 
			for (rowsCounter=0 ; rowsCounter<4 ; rowsCounter++) 
			{
				DIO_getPinValue(KPD_ROWS_PORT,rowsPins[rowsCounter],&pinValue);
				
				if(0==pinValue)
				{
				   *returnedValue = KPD_Chars[rowsCounter][colsCounter];
				   while (pinValue==0)
				   {
					 DIO_getPinValue(KPD_ROWS_PORT,rowsPins[rowsCounter],&pinValue);
				   }
				   pinFlag =1 ;
				   break ;
				}
			}
		   // Deactviate each cols 	 
           DIO_setPinValue(KPD_COLS_PORT,coloumnsPins[colsCounter],DIO_PIN_HIGH);
		   if (1==pinFlag)
		   {
			   break ;
		   }
		}
	}
}