/*
 * Alarm_Monitor.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"
#include "driver.h"

//Define Ststes 
enum {
    Alarm_Monitor_Alarm_Off, 
    Alarm_Monitor_Alarm_On,
    Alarm_Monitor_Waiting 
}Alarm_Monitor_state_id;


// Declare states functions Pressure_Sensor

STATE_define(Alarm_Monitor_Alarm_Off) ; 
STATE_define(Alarm_Monitor_Alarm_On) ;
STATE_define(Alarm_Monitor_Waiting);  


//STATE pointer to function 
extern void (*Alarm_Monitor_state)();

#endif /* ALARM_MONITOR_H_ */
