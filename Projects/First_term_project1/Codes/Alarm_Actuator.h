/*
 * Alarm_Actuator.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"
#include "driver.h"

//Define Ststes 
enum {
    Alarm_Actuator_Alarm_Off, 
    Alarm_Actuator_Alarm_On
}Alarm_Actuator_state_id;


// Declare states functions Pressure_Sensor

STATE_define(Alarm_Actuator_Alarm_On) ; 
STATE_define(Alarm_Actuator_Alarm_Off) ;


void Alarm_Actuator_init () ;

//STATE pointer to function 
extern void (*Alarm_Actuator_state)();

#endif /* ALARM_ACTUATOR_H_ */
