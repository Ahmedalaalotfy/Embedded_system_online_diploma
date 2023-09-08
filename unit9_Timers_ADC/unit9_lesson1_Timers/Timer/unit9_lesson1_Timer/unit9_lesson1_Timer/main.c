/*
 * unit8_lesson1_Timer.c
 *
 * Created: 9/8/2023 3:38:48 AM
 * Author : ahmed
 */
 
#define F_CPU 8000000UL
#include <util/delay.h>

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include   "TMR_interface.h"
#include   "TMR_config.h"
#include   "DIO_interface.h"
#include   "GI_interface.h"


//void OVF_func (void);
void CTC_func (void);


int main(void)
{
	

    DIO_setPortDirection(DIO_PORTA,DIO_PORT_HIGH); 

	GI_enable();
	TMR_timer0_CTC_SetCallBack(&CTC_func);
	
	TMR_timer0Init();
	TMR_timer0Start();
	u8 K = 0 ;
	
	while (1)
	{
		
	}
}

/*void OVF_func(void)
{

}*/

void CTC_func(void)
{
  PORTA = ~PORTA ;
}
