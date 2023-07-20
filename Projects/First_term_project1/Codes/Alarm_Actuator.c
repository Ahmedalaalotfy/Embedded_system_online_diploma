/*
 * Alarm_Actuator.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#include "Alarm_Actuator.h"

// variables 

//STATE pointer to function 
void (*Alarm_Actuator_state)();

//initialization 
void Alarm_Actuator_init ()
{
  //init Alarm Actuator
}

void Start_Alarm() 
{
  Alarm_Actuator_state = STATE(Alarm_Actuator_Alarm_On);
}

void Stop_Alarm()
{
  Alarm_Actuator_state = STATE(Alarm_Actuator_Alarm_Off);
}



STATE_define(Alarm_Actuator_Alarm_On) 
{
   //STATE_name
   Alarm_Actuator_state_id = Alarm_Actuator_Alarm_On ; 

   //STATE_action 
   Set_Alarm_actuator(0);
   
}


STATE_define(Alarm_Actuator_Alarm_Off) 
{
   //STATE_name
   Alarm_Actuator_state_id = Alarm_Actuator_Alarm_Off ; 

   //STATE_action 
   Set_Alarm_actuator(1);
   
}




