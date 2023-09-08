/*
 * TMR_config.h
 *
 * Created: 9/22/2022 12:37:59 PM
 *  Author: ahmed
 */ 


#ifndef TMR_CONFIG_H_
#define TMR_CONFIG_H_

// Init Timer With Preload Value
#define TMR_TMR0_PRELOAD_VALUE         6


#define TMR_TMR0_OVERFLOW_COUNTER      1000

/*Option for timer 0 mode 
1- TMR_TMR0_NORMAL_MODE
2- TMR_TMR0_CTC_MODE
3- TMR_TMR0_FAST_PWM_MODE 
*/
#define TMR_TMR0_MODE   TMR_TMR0_CTC_MODE

#define TMR_TMR0_CTC_COUNTER           1000


              /*TIMER1*/
			  
#define TMR_TMR1_OVERFLOW_VALUE   4999			  

#endif /* TMR_CONFIG_H_ */