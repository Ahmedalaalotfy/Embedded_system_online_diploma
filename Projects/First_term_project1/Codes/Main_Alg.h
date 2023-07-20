/*
 * Main_Alg.h
 *
 *  Created on: Jul 17, 2023
 *      Author: Ahmedalaalotfy
 */

#ifndef MAIN_ALG_H_
#define MAIN_ALG_H_

#include "state.h"
#include "driver.h"


//Define Ststes 
enum {
    Main_Alg_High_Pressure_Detect,
    Main_Alg_High_Pressure_Not_Detect 
}Main_Alg_state_id;


// Declare states functions Main_Alg

STATE_define(Main_Alg_High_Pressure_Detect) ; 
STATE_define(Main_Alg_High_Pressure_Not_Detect) ;


//STATE pointer to function 
extern void (*Main_Alg_state)();

#endif /* MAIN_ALG_H_ */
