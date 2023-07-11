/*
 * US.c
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */

#include "US.h"


// variables 
int US_distance = 0 ;

//STATE pointer to function 
void (*US_state)();
int US_Get_distance_random (int l , int r , int count) ;


void US_init()
{
	//init US Driver
	printf("US_init");
}

STATE_define(US_busy)
{
   //STATE_name
   US_state_id = US_busy ;

   //STATE_action 
   US_distance = US_Get_distance_random (45 , 55 , 1) ;
    //US_Get_distance(US_distance)

    printf("US_Waiting State : Distance= %d\n",US_distance);
    US_Set_distance(US_distance);
    US_state = STATE(US_busy);

}



int US_Get_distance_random (int l , int r , int count) 
{

    //thid will generate random number in range l to r 
    int i ; 
    for (i = 0 ; i < count ; i++)
    {
        int rand_num = ( rand() % (r-l+1) ) + l ;
        return rand_num ; 
    }

}
