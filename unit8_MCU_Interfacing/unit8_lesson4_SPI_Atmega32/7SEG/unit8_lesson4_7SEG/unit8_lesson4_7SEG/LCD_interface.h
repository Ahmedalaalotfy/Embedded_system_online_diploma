/*
 * LCD_interface.h
 *
 * Created: 9/11/2022 11:28:56 AM
 *  Author: ahmed
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* Macros For LCD Shifting Direction */
#define LCD_SHIFT_LEFT        0
#define LCD_SHIFT_RIGHT       1 

/* Macros For LCD Line Id */
#define LCD_LINE_ONE          1
#define LCD_LINE_TWO          2

#define LCD_8_BIT_MODE        1
#define LCD_4_BIT_MODE        2



static void writeHalfPort(u8 Value);

void LCD_init(void);
void LCD_sendCmnd(u8 Cmnd);
void LCD_sendChar(u8 Data);
void LCD_sendString(u8 *String); 
void LCD_clear(void);
void LCD_shift(u8 shiftDirection);
void LCD_goToSpecificPosition(u8 LineNumber, u8 Position);
// void LCD_writeSpecificChar(u8 *Pattern , u8 charPositin ,u8 LineNumber, u8 Position )
void LCD_writeNumber(u32 number); 
void LCD_Custom_Char(u8 loc,u8 *msg);
void LCD_SaveIn_CGRAM(void) ;


 
#endif

