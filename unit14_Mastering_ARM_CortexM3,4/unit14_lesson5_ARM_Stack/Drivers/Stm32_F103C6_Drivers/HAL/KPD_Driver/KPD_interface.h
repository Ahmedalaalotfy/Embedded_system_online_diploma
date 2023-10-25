/*
 * KPD_interface.h
 *
 * Created: 9/13/2022 10:03:04 AM
 *  Author: ahmed
 */ 


#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#define KPD_NOT_PRESSED     0xff

void KPD_GPIO_Init(void);
void KPD_getValue(uint8_t *returnedValue);
unsigned char Get_Pressed_KEY(void);



#endif /* KPD_INTERFACE_H_ */
