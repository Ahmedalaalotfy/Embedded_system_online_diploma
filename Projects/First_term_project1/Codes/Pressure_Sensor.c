/*
 * Pressure_Sensor.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#include "Pressure_Sensor.h"

 

// variables 
int Pval = 0 ;
int Psensor_Pull_Timer = 100 ;

//STATE pointer to function 
void (*Pressure_Sensor_state)();

//initialization 
void Pressure_Sensor_init ()
{
  //init Pressure Snsor
}


STATE_define(Pressure_Sensor_Reading) 
{
   //STATE_name
   Pressure_Sensor_state_id = Pressure_Sensor_Reading ; 

   //STATE_action 
    //Get pressure value 
    Pval = getPressureVal(); 

   //Set Pressure Value
    Set_Pressure_Val(Pval); 

    //call Waiting State
    Pressure_Sensor_state = STATE(Pressure_Sensor_Waiting);
   
}


STATE_define(Pressure_Sensor_Waiting) 
{
    //STATE_name
    Pressure_Sensor_state_id = Pressure_Sensor_Reading ; 
   
   //STATE_action

    //Delay for 100s
    Delay(Psensor_Pull_Timer); 

     //call Reading State
    Pressure_Sensor_state = STATE(Pressure_Sensor_Reading);
}





