/*
 * CA.h
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

//Define Ststes 
enum {
    CA_waiting, 
    CA_driving 
}CA_state_id;


// Declare states functions CA
STATE_define(CA_waiting) ; 
STATE_define(CA_driving) ; 



//STATE pointer to function 
extern void (*CA_state)();

#endif /* CA_H_ */