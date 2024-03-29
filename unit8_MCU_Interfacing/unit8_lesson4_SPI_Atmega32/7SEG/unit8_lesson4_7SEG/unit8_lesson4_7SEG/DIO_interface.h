<<<<<<< HEAD
/*
 * DIO_interface.h
 *
 * Created: 9/6/2022 11:39:23 PM
 *  Author: ahmed
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN0       0
#define DIO_PIN1       1
#define DIO_PIN2       2
#define DIO_PIN3       3
#define DIO_PIN4       4
#define DIO_PIN5       5
#define DIO_PIN6       6
#define DIO_PIN7       7 

#define DIO_PIN_OUTPUT 1 
#define DIO_PIN_INPUT  0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORTA      0
#define DIO_PORTB      1
#define DIO_PORTC      2
#define DIO_PORTD      3

/* Macros For Port Direction */ 
#define DIO_PORT_INPUT   0x00 // zeros
#define DIO_PORT_OUTPUT  0xff //ones 

/* Macros For Port State */ 
#define DIO_PORT_HIGH   0xff // ones
#define DIO_PORT_LOW  0x00 //zeros 

/* PINS APIS*/ /*API == APLICATION PROGRAM INTERFACE */   
void DIO_setPinDirection       (u8 PortId, u8 PinId , u8 PinDirection ) ;
void DIO_setPinValue           (u8 PortId, u8 PinId , u8 PinValue);
void DIO_getPinValue           (u8 PortId, u8 PinId , u8* PinValue);
void DIO_togglePinValue        (u8 PortId, u8 PinId); 
void DIO_setInputPinResistance (u8 PortId, u8 PinId);

/* PORTS APIS*/ 
void DIO_setPortDirection       (u8 PortId , u8 PortDirection ) ;
void DIO_setPortValue           (u8 PortId , u8 PortValue);
void DIO_getPortValue           (u8 PortId , u8* PortValue);
void DIO_togglePortValue        (u8 PortId ); 
void DIO_setInputPortResistance (u8 PortId);

=======
/*
 * DIO_interface.h
 *
 * Created: 9/6/2022 11:39:23 PM
 *  Author: ahmed
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_PIN0       0
#define DIO_PIN1       1
#define DIO_PIN2       2
#define DIO_PIN3       3
#define DIO_PIN4       4
#define DIO_PIN5       5
#define DIO_PIN6       6
#define DIO_PIN7       7 

#define DIO_PIN_OUTPUT 1 
#define DIO_PIN_INPUT  0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0

#define DIO_PORTA      0
#define DIO_PORTB      1
#define DIO_PORTC      2
#define DIO_PORTD      3

/* Macros For Port Direction */ 
#define DIO_PORT_INPUT   0x00 // zeros
#define DIO_PORT_OUTPUT  0xff //ones 

/* Macros For Port State */ 
#define DIO_PORT_HIGH   0xff // ones
#define DIO_PORT_LOW  0x00 //zeros 

/* PINS APIS*/ /*API == APLICATION PROGRAM INTERFACE */   
void DIO_setPinDirection       (u8 PortId, u8 PinId , u8 PinDirection ) ;
void DIO_setPinValue           (u8 PortId, u8 PinId , u8 PinValue);
void DIO_getPinValue           (u8 PortId, u8 PinId , u8* PinValue);
void DIO_togglePinValue        (u8 PortId, u8 PinId); 
void DIO_setInputPinResistance (u8 PortId, u8 PinId);

/* PORTS APIS*/ 
void DIO_setPortDirection       (u8 PortId , u8 PortDirection ) ;
void DIO_setPortValue           (u8 PortId , u8 PortValue);
void DIO_getPortValue           (u8 PortId , u8* PortValue);
void DIO_togglePortValue        (u8 PortId ); 
void DIO_setInputPortResistance (u8 PortId);

>>>>>>> bd560d5b990063eaea5362409ab455504410aa69
#endif /* DIO_INTERFACE_H_ */