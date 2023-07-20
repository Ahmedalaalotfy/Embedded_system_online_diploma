/*
 * Pressure_Sensor.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"
#include "driver.h"

//Define Ststes 
enum {
    Pressure_Sensor_Reading, 
    Pressure_Sensor_Waiting 
}Pressure_Sensor_state_id;


// Declare states functions Pressure_Sensor

STATE_define(Pressure_Sensor_Reading) ; 
STATE_define(Pressure_Sensor_Waiting) ; 


void Pressure_Sensor_init () ;

//STATE pointer to function 
extern void (*Pressure_Sensor_state)();

#endif /* PRESSURE_SENSOR_H_ */
