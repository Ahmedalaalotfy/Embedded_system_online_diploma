/*
 * DC.c
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */

#include "DC.h"


// variables 
int DC_speed = 0 ;


//STATE pointer to function 
void (*DC_state)();

void DC_init ()
{
	//init PWM
	printf("DC_init");
}

void DC_motor (int s)
{
  DC_speed = s ;
  DC_state = STATE(DC_busy);
  printf("US --------Speed=%d-------->CA\n",DC_speed);
}

STATE_define(DC_idle)
{
   //STATE_name
   DC_state_id = DC_idle ;

   // state action
     // Call PWM to make speed = DC_speed

    printf("DC_Waiting State : Distance= %d speed= %d\n",DC_speed);
}


STATE_define(DC_busy)
{
    //STATE_name
   DC_state_id = DC_busy ;

   // state action
   // Call PWM to make speed = DC_speed
     DC_state = STATE(DC_idle);
    printf("DC_Waiting State : Distance= %d speed= %d\n",DC_speed);
}

