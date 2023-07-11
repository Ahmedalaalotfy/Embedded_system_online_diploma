/*
 * main.c
 *
 *  Created on: Jul 11, 2023
 *      Author: ahmed
 */
#include "CA.h"
#include "US.h"
#include "DC.h"

void setup () 
{
    // init all the drivers 
    // init IRQ ....
    // init HAL US_Driver DC_Driver 
    // init Block 
	US_init();
	DC_init();
    // Set States pointers for each Block 
    CA_state = STATE(CA_waiting);
    US_state = STATE(US_busy);
    DC_state = STATE(DC_idle);
}

void main ()
{
	setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    volatile int d ;

	setup();

	while(1)
	{
		// Call state for each block
		US_state() ;
		CA_state() ;
		DC_state() ;
		for (d - 0 ; d <= 1000 ; d++ );
	}
}


