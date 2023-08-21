/*
 * SWITCH_program.c
 *
 * Created: 9/10/2022 11:11:40 PM
 *  Author: ahmed
 */ 


/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "SWITCH_interface.h"

void SWITCH_getState(u8 PortId, u8 PinId ,u8 connectionType ,u8* StateValue)

{
	u8 Local_switchState ; 
    if ( (PortId<=3) && (PinId<=7) && (StateValue != NULL ) && (connectionType == forward || connectionType == reverse) ) 
	{
		DIO_getPinValue(PortId,PinId,&Local_switchState) ;
		
		if (connectionType == forward )
		{
			if (Local_switchState == 1)
			{
				*StateValue = SWITCH_PRESSED ;
			}
			else if (Local_switchState == 0)
			{
				*StateValue = SWITCH_NOT_PRESSED ;
			}	
		}
		
		else if (connectionType == reverse)
		{
			if (Local_switchState == 1)
			{
				*StateValue = SWITCH_NOT_PRESSED ;
			}
			else if (Local_switchState == 0)
			{
				*StateValue = SWITCH_PRESSED ;
			}
		}
		
	}
}