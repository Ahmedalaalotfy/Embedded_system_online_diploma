/*
 * TMR_interface.h
 *
 * Created: 9/22/2022 12:37:39 PM
 *  Author: ahmed
 */ 


#ifndef TMR_INTERFACE_H_
#define TMR_INTERFACE_H_
 
#define TMR_TMR0_NORMAL_MODE   1
#define TMR_TMR0_CTC_MODE      2
#define TMR_TMR0_FAST_PWM_MODE 3

/* TIMER0 */
void TMR_timer0Init(void);
void TMR_timer0_OVF_SetCallBack(void(*ptr)(void));
void TMR_timer0_CTC_SetCallBack(void(*ptr)(void));
void TMR_timer0setCompareMatchValue(u8 OCR0_value);
void TMR_timer0Start(void); 
void TMR_timer0Stop(void);

/* TIMER1 */
void TMR_timer1Init(void);
void TMR_timer1Start(void);
void TMR_timer1Stop(void);
void TMR_timer1setCompareAMatchValue(u16 OCR1A_value);




#endif /* TMR_INTERFACE_H_ */