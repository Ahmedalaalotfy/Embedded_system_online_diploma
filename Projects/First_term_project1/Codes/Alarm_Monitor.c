/*
 * Alarm_Monitor.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#include "Alarm_Monitor.h"

// variables 
int Alarm_Time = 60 ;

High_Pressure_Detected()
{
    Alarm_Monitor_state = STATE(Alarm_Monitor_Alarm_On);
}


//STATE pointer to function 
void (*Alarm_Monitor_state)();


STATE_define(Alarm_Monitor_Alarm_On) 
{
   //STATE_name
   Alarm_Monitor_state_id = Alarm_Monitor_Alarm_On ; 

   //STATE_action 
    //Start Alarm 
     Start_Alarm(); 

    //call Waiting State
    Alarm_Monitor_state = STATE(Alarm_Monitor_Waiting);
   
}

STATE_define(Alarm_Monitor_Waiting) 
{
   //STATE_name
   Alarm_Monitor_state_id = Alarm_Monitor_Waiting ; 

   //STATE_action 
    //Delay for 60s
     Delay(Alarm_Time); 

    //call Off State
    Alarm_Monitor_state = STATE(Alarm_Monitor_Alarm_Off);
}

STATE_define(Alarm_Monitor_Alarm_Off) 
{
   //STATE_name
   Alarm_Monitor_state_id = Alarm_Monitor_Alarm_Off ; 

   //STATE_action 
    //Delay stop Alarm
     Stop_Alarm(); 

    //call Off State
    Alarm_Monitor_state = STATE(Alarm_Monitor_Alarm_Off);
}








