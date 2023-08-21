/*
 * SWITCH_interface.h
 *
 * Created: 9/10/2022 11:12:33 PM
 *  Author: ahmed
 */ 


#ifndef SWITCH_INTERFACE_H_
#define SWITCH_INTERFACE_H_

#define forward             1 // active high
#define reverse             0 // active low

#define SWITCH_PRESSED      1 
#define SWITCH_NOT_PRESSED  0 

void SWITCH_getState(u8 PortId, u8 PinId ,u8 connectionType ,u8* StateValue);



#endif /* SWITCH_INTERFACE_H_ */