/*
 * DC.h
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

//Define Ststes 
enum {
    DC_idle,
    DC_busy
}DC_state_id;


// Declare states functions DC
STATE_define(DC_idle) ;
STATE_define(DC_busy) ;


void DC_init();

//STATE pointer to function 
extern void (*DC_state)();

#endif /* DC_H_ */
