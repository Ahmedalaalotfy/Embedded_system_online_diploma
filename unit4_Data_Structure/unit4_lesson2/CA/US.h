/*
 * US.h
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */

#ifndef US_H_
#define US_H_

#include "state.h"

//Define Ststes 
enum {
    US_busy,
}US_state_id;


// Declare states functions US
STATE_define(US_busy) ;


void US_init();


//STATE pointer to function 
extern void (*US_state)();

#endif /* US_H_ */
