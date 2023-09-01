/*
 * LCD_program.c
 *
 * Created: 9/11/2022 11:28:31 AM
 *  Author: ahmed
 */

#define F_CPU 16000000UL 
#include <util/delay.h> 

/* UTILES_LIB */
#include   "STD_TYPES.h"
#include   "BIT_MATH.h"
#include   "ATMEGA32_REG.h"

/* MCAL */
#include "DIO_interface.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_init(void)

{
	_delay_ms(35);
	 
	#if LCD_MODE == LCD_8_BIT_MODE
	LCD_sendCmnd(0b00111000); // Function Set command 2*16 LCD
	
	#elif LCD_MODE == LCD_4_BIT_MODE
	// set RS pin = 0 ( write command)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	// set RW pin = 0 ( write )
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	writeHalfPort(0b0010);
	
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	LCD_sendCmnd(0b00101000);
	
	#endif
	
	_delay_us(45);
	
	// display on , cursor off , blink on 
	LCD_sendCmnd(0b00001101);
	_delay_us(45);
	
	// clear display 
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
	
	// set entry mode 
	LCD_sendCmnd(0b00000110);
	
}

void LCD_sendCmnd(u8 Cmnd)

{
	// set RS pin = 0 ( write command) 
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_LOW);
	
	// set RW pin = 0 ( write )
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	DIO_setPortValue(LCD_DATA_PORT,Cmnd);
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#elif LCD_MODE == LCD_4_BIT_MODE
	
	// Write the most 4-bit command on data pins
	writeHalfPort(Cmnd>>4);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	// Write the Least 4-bit command on data pins
	writeHalfPort(Cmnd);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	#endif 
	
}

void LCD_sendChar(u8 Data)

{
	// set RS pin = 1 ( write Data)
	DIO_setPinValue(LCD_RS_PORT,LCD_RS_PIN,DIO_PIN_HIGH);
	
	// set RW pin = 0 ( write )
	DIO_setPinValue(LCD_RW_PORT,LCD_RW_PIN,DIO_PIN_LOW);
	
	#if LCD_MODE == LCD_8_BIT_MODE
	
	DIO_setPortValue(LCD_DATA_PORT,data);
	
	/* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#elif LCD_MODE == LCD_4_BIT_MODE
	
	// Write the most 4-bit Data on data pins
	writeHalfPort(Data>>4);
	
	 /* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	// Write the Least 4-bit Data on data pins
	writeHalfPort(Data);
	
	 /* Enable Pulse *//* H => L */
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setPinValue(LCD_EN_PORT,LCD_EN_PIN,DIO_PIN_LOW);
	
	#endif
}

static void writeHalfPort(u8 Value)
{
	if (1==GET_BIT(Value,0))
	{
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_HIGH);
	}
	else 
	{
		DIO_setPinValue(LCD_D4_PORT, LCD_D4_PIN, DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,1))
	{
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(LCD_D5_PORT, LCD_D5_PIN, DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,2))
	{
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(LCD_D6_PORT, LCD_D6_PIN, DIO_PIN_LOW);
	}
	
	if (1==GET_BIT(Value,3))
	{
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_HIGH);
	}
	else
	{
		DIO_setPinValue(LCD_D7_PORT, LCD_D7_PIN, DIO_PIN_LOW);
	}
}

void LCD_sendString(u8 *String)

{
	if(String != NULL)
	{
		u8 stringLength = 0;
		while(String[stringLength] != '\0')
		{
			LCD_sendChar(String[stringLength]);
			++stringLength;
		}
	}
}

void LCD_clear(void)

{
	// clear display
	LCD_sendCmnd(0b00000001);
	_delay_ms(2);
}

void LCD_shift(u8 shiftDirection)

{
	if (shiftDirection == LCD_SHIFT_LEFT)
	{
		LCD_sendCmnd(0b00011000) ; 
		_delay_ms(10); 
	}
	else if (shiftDirection == LCD_SHIFT_RIGHT)
	{
		LCD_sendCmnd(0b00011100) ;
		_delay_ms(10);
	}
}

void LCD_goToSpecificPosition(u8 LineNumber, u8 Position)
{
	if (LineNumber == LCD_LINE_ONE)
	{
		if(Position<=15)
		{
			LCD_sendCmnd(0x80 + Position);
		}
	}
	
	else if (LineNumber==LCD_LINE_TWO)
	{
		if(Position<=15)
		{
			LCD_sendCmnd(0xc0 + Position);
		}
	}
}

void LCD_writeNumber(u32 number)
{
	u32 Local_reversed = 1;
	if (number == 0)
	{
		LCD_sendChar('0');
	}
	else
	{
		// Reverse Number
		while (number != 0)
		{
			Local_reversed = Local_reversed*10 + (number%10);
			number /= 10;
		}
		
		do
		{
			LCD_sendChar((Local_reversed%10)+'0');
			Local_reversed /= 10;
		}while (Local_reversed != 1);
	}
}

void LCD_Custom_Char (u8 loc,u8 *msg)
{
    u8 i;
    if(loc<8)
    {
     LCD_sendCmnd(0x40 + (loc*8));  /* Command 0x40 and onwards forces 
                                       the device to point CGRAM address */
       for(i=0;i<8;i++)  /* Write 8 byte for generation of 1 character */
           LCD_sendChar(msg[i]);      
    }   
}

void LCD_SaveIn_CGRAM(void)
{
	LCD_sendCmnd(0b01000000);  //0x40   0b 0100 0000

	//   save Person
	LCD_sendChar(0b01110);
	LCD_sendChar(0b01110);
	LCD_sendChar(0b00100);
	LCD_sendChar(0b01110);
	LCD_sendChar(0b10101);
	LCD_sendChar(0b00100);
	LCD_sendChar(0b01010);
	LCD_sendChar(0b01010);

	//   save smile
	LCD_sendChar(0b00000);
	LCD_sendChar(0b00000);
	LCD_sendChar(0b01010);
	LCD_sendChar(0b00000);
	LCD_sendChar(0b00000);
	LCD_sendChar(0b10001);
	LCD_sendChar(0b01110);
	LCD_sendChar(0b00000);

	//   save LOCK
	LCD_sendChar(0b01110);
	LCD_sendChar(0b10001);
	LCD_sendChar(0b10001);
	LCD_sendChar(0b11111);
	LCD_sendChar(0b11011);
	LCD_sendChar(0b11011);
	LCD_sendChar(0b11111);
	LCD_sendChar(0b00000);


	//   save Heart
	LCD_sendChar(0b00000);
	LCD_sendChar(0b00000);
	LCD_sendChar(0b01010);
	LCD_sendChar(0b10101);
	LCD_sendChar(0b10001);
	LCD_sendChar(0b01110);
	LCD_sendChar(0b00100);
	LCD_sendChar(0b00000);


	///  SAVE Ï
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B11111);
	LCD_sendChar(0B00000);

	///  SAVE ã
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B10001);
	LCD_sendChar(0B01110);

	///  SAVE  Í
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B11111);
	LCD_sendChar(0B00000);


	///  SAVE Ã
	LCD_sendChar(0b00110);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);

}


