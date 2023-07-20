/*
 * main.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */
#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "Pressure_Sensor.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"
#include "Main_Alg.h"


void setup () 
{
    // init all the drivers 
    // init IRQ ....
    // init HAL US_Driver DC_Driver 
    // init Block
    GPIO_INITIALIZATION(); 
	Pressure_Sensor_init ();
	Alarm_Actuator_init () ;
    // Set States pointers for each Block 
    Pressure_Sensor_state = STATE(Pressure_Sensor_Reading);
    Main_Alg_state        = STATE(Main_Alg_High_Pressure_Not_Detect);
    Alarm_Monitor_state   = STATE(Alarm_Monitor_Alarm_Off);
    Alarm_Actuator_state  = STATE(Alarm_Actuator_Alarm_Off);
}

int main ()
{
	setup () ;
	GPIO_INITIALIZATION();
	while (1)
	{
	//Implement your Design 
    Pressure_Sensor_state();
    Main_Alg_state();
    Alarm_Monitor_state();
    Alarm_Actuator_state();
    Delay(10);
	}

}
