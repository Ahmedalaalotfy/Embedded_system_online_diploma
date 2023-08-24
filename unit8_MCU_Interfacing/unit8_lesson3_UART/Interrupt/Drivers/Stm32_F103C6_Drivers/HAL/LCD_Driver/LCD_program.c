/*
 * LCD_program.c
 *
 * Created: 9/11/2022 11:28:31 AM
 *  Author: ahmed
 */



/* UTILES_LIB */
#include   "BIT_MATH.h"
#include "stm32f103x6.h"

/* MCAL */
#include "Stm32_F103C6_GPIO_Driver.h"

/* HAL */
#include "LCD_interface.h"
#include "LCD_config.h"


void delay_ms(uint32_t time) {
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void LCD_init(void)

{
	delay_ms(35);

#if LCD_MODE == LCD_8_BIT_MODE
	LCD_sendCmnd(0b00111000); // Function Set command 2*16 LCD

#elif LCD_MODE == LCD_4_BIT_MODE
	// set RS pin = 0 ( write command)
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN,GPIO_PIN_RESET);

	// set RW pin = 0 ( write )
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN,GPIO_PIN_RESET);

	writeHalfPort(0b0010);

	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);

	LCD_sendCmnd(0b00101000);

#endif

	delay_ms(1);

	// display on , cursor off , blink on 
	LCD_sendCmnd(0b00001101);
	delay_ms(1);

	// clear display 
	LCD_sendCmnd(0b00000001);
	delay_ms(2);

	// set entry mode 
	LCD_sendCmnd(0b00000110);

}

void LCD_GPIO_Init(void)
{

	GPIO_PinConfig_t PinCfg ;

		// LCD
		PinCfg.GPIO_PinNumber = LCD_RS_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_RS_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = LCD_RW_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_RW_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = LCD_EN_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_EN_PORT, &PinCfg);

		//============================
		// SET THE NEXT 8 PINS AS INPUT
		PinCfg.GPIO_PinNumber = LCD_D4_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = LCD_D5_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = LCD_D6_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

		PinCfg.GPIO_PinNumber = LCD_D7_PIN;
		PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
		PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	//	PinCfg.GPIO_PinNumber = LCD_D4_PIN;
	//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	//	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	//	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	//	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);
	//
	//	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	//	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);
	//
	//	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	//	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	//	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	//	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);
}
void LCD_sendCmnd(uint8_t Cmnd)

{
	// set RS pin = 0 ( write command) 
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN, GPIO_PIN_RESET);

	// set RW pin = 0 ( write )
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN, GPIO_PIN_RESET);

#if LCD_MODE == LCD_8_BIT_MODE
	MCAL_GPIO_WritePort(LCD_DATA_PORT, Cmnd);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN, GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN, GPIO_PIN_RESET);

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write the most 4-bit command on data pins
	writeHalfPort(Cmnd>>4);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);

	// Write the Least 4-bit command on data pins
	writeHalfPort(Cmnd);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);
#endif

}

void LCD_sendChar(uint8_t Data)

{
	// set RS pin = 1 ( write command)
	MCAL_GPIO_WritePin(LCD_RS_PORT,LCD_RS_PIN, GPIO_PIN_SET);

	// set RW pin = 0 ( write )
	MCAL_GPIO_WritePin(LCD_RW_PORT,LCD_RW_PIN, GPIO_PIN_RESET);

#if LCD_MODE == LCD_8_BIT_MODE
	MCAL_GPIO_WritePort(LCD_DATA_PORT, Data);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN, GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN, GPIO_PIN_RESET);

#elif LCD_MODE == LCD_4_BIT_MODE

	// Write the most 4-bit command on data pins
	writeHalfPort(Data>>4);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);

	// Write the Least 4-bit command on data pins
	writeHalfPort(Data);

	/* Enable Pulse *//* H => L */
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_SET);
	delay_ms(1);
	MCAL_GPIO_WritePin(LCD_EN_PORT,LCD_EN_PIN,GPIO_PIN_RESET);
#endif

}

static void writeHalfPort(uint8_t Value)
{
	if (1==GET_BIT(Value,0))
	{
		MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, GPIO_PIN_SET);
	}
	else 
	{
		MCAL_GPIO_WritePin(LCD_D4_PORT, LCD_D4_PIN, GPIO_PIN_RESET);
	}

	if (1==GET_BIT(Value,1))
	{
		MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, GPIO_PIN_SET);
	}
	else
	{
		MCAL_GPIO_WritePin(LCD_D5_PORT, LCD_D5_PIN, GPIO_PIN_RESET);
	}

	if (1==GET_BIT(Value,2))
	{
		MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, GPIO_PIN_SET);
	}
	else
	{
		MCAL_GPIO_WritePin(LCD_D6_PORT, LCD_D6_PIN, GPIO_PIN_RESET);
	}

	if (1==GET_BIT(Value,3))
	{
		MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, GPIO_PIN_SET);
	}
	else
	{
		MCAL_GPIO_WritePin(LCD_D7_PORT, LCD_D7_PIN, GPIO_PIN_RESET);
	}
}

void LCD_sendString(uint8_t *String)

{
	if(String != NULL)
	{
		uint8_t stringLength = 0;
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
	delay_ms(2);
}

void LCD_shift(uint8_t shiftDirection)

{
	if (shiftDirection == LCD_SHIFT_LEFT)
	{
		LCD_sendCmnd(0b00011000) ; 
		delay_ms(10);
	}
	else if (shiftDirection == LCD_SHIFT_RIGHT)
	{
		LCD_sendCmnd(0b00011100) ;
		delay_ms(10);
	}
}

void LCD_goToSpecificPosition(uint8_t LineNumber, uint8_t Position)
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

void LCD_writeNumber(uint32_t number)
{
	uint32_t Local_reversed = 1;
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

void LCD_Custom_Char (uint8_t loc,uint8_t *msg)
{
	uint8_t i;
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


	///  SAVE �
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B11111);
	LCD_sendChar(0B00000);

	///  SAVE �
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B10001);
	LCD_sendChar(0B01110);

	///  SAVE  �
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B00001);
	LCD_sendChar(0B11111);
	LCD_sendChar(0B00000);


	///  SAVE �
	LCD_sendChar(0b00110);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B01110);
	LCD_sendChar(0B00000);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);
	LCD_sendChar(0B00100);

}


