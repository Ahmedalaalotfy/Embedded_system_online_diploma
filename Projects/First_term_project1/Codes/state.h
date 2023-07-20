/*
 * state.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef STATE_H_
#define STATE_H_


#include "stdio.h"
#include "stdlib.h"

// Automatic STATE Functions generated 
#define STATE_define(_stateFUN_) void ST_##_stateFUN_()
#define STATE(_stateFUN_) ST_##_stateFUN_


//state connection
void Set_Pressure_Value (int Pval) ;
void High_Pressure_Detect ();
void Start_Alarm () ;
void Stop_Alarm () ;

#endif /* STATE_H_ */
