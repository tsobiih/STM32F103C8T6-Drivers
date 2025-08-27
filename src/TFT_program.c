/*
 * TFT_program.c
 *
 *  Created on: Apr 12, 2025
 *      Author: Mostafa Mohamed
 */
#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "MGPIO_interface.h"
#include "MSTK_interface.h"
#include "MSPI_interface.h"
#include "TFT_interface.h"
#include "TFT_config.h"
#include "TFT_private.h"
#include <stdio.h>
#include <stdlib.h>


void TFT_Write_Data(u8 data)
{
	MGPIO_voidSetPinValue(A0_PORT, A0_PIN, PIN_HIGH);
	MSPI_voidSend(data);
}
void TFT_Write_Command(u8 cmd)
{
	MGPIO_voidSetPinValue(A0_PORT, A0_PIN, PIN_LOW);
	MSPI_voidSend(cmd);
}

void TFT_init()
{
	MGPIO_voidSetMode(RST_PORT, RST_PIN, OUTPUT_10MHz);
	MGPIO_voidSetOutputType(RST_PORT, RST_PIN, GP_Pushpull);
	MGPIO_voidSetMode(A0_PORT, A0_PIN, OUTPUT_10MHz);
	MGPIO_voidSetOutputType(A0_PORT, A0_PIN, GP_Pushpull);


	/*__________RESET SEQUENCE OF TFT DISPLAY_________*/
	MGPIO_voidSetPinValue(RST_PORT, RST_PIN, PIN_HIGH);
	MSTK_voidDelay_us(100);
	MGPIO_voidSetPinValue(RST_PORT, RST_PIN, PIN_LOW);
	MSTK_voidDelay_us(2);
	MGPIO_voidSetPinValue(RST_PORT, RST_PIN, PIN_HIGH);
	MSTK_voidDelay_us(100);
	MGPIO_voidSetPinValue(RST_PORT, RST_PIN, PIN_LOW);
	MSTK_voidDelay_us(100);
	MGPIO_voidSetPinValue(RST_PORT, RST_PIN, PIN_HIGH);
	MSTK_voidDelay_us(120);

	//SLEEP OUT MODE within sequence
	TFT_Write_Command(0x11);
	MSTK_voidDelay_ms(10);

	//COLOR MODE within sequence
	TFT_Write_Command(0x3A);
	TFT_Write_Data(0x05); //RGB565 color code standard

//	 Inverse Color mode ON
//	TFT_Write_Command(0x21);

	// Row and Column exchange MY=1 , MX=1, MV=0 ( start from top left )
	TFT_Write_Command(0x36);
	TFT_Write_Data(0b11010110);		// MV = 0

	// Select BGR color filter
	//    TFT_Write_Command(TFT_MADCTL);
	//    TFT_Write_Data(0x08);

	//DISPLAY on
	TFT_Write_Command(0x29);
}
void TFT_ImgDisplay(const u16 *imgArr)
{
	u16 i = 0;
	u8 HIGH, LOW;

	//SET X coordinate
	TFT_Write_Command(0x2A);
	// start at -> 0,0
	TFT_Write_Data(0);
	TFT_Write_Data(0);
	// end at -> 127
	TFT_Write_Data(0);
	TFT_Write_Data(127);

	//SET Y coordinate
	TFT_Write_Command(0x2B);
	// start at -> 0,0
	TFT_Write_Data(0);
	TFT_Write_Data(0);
	// end at -> 127
	TFT_Write_Data(0);
	TFT_Write_Data(159);

	// WRITE on screen
	TFT_Write_Command(0x2C);
	for(i=0; i<20480; i++){
		HIGH = (u8)(imgArr[i]>>8);
		LOW = (u8)(imgArr[i]);
		TFT_Write_Data(HIGH);
		TFT_Write_Data(LOW);
	}
}

void TFT_SWReset(void)
{
	TFT_Write_Command(TFT_SWRESET);
	MSTK_voidDelay_ms(150);
}

void TFT_SetDrawingArea(u8 x0, u8 y0, u8 x1, u8 y1)
{
	TFT_Write_Command(TFT_CASET);	// column address

	// Start at x0
	TFT_Write_Data(0);
	TFT_Write_Data(x0);

	//End at x1
	TFT_Write_Data(0);
	TFT_Write_Data(x1);

	TFT_Write_Command(TFT_RASET);	// Row Adress Command
	// Start at y0
	TFT_Write_Data(0);
	TFT_Write_Data(y0);

	// End at y1
	TFT_Write_Data(0);
	TFT_Write_Data(y1);

	TFT_Write_Command(TFT_RAMWR);
}

void TFT_DrawPixel(u8 x, u8 y, u16 color)
{
	if((x >= TFT_WIDTH) || (y >= TFT_HEIGHT))
	{
		return;
	}

	u8 HIGH, LOW;

	TFT_SetDrawingArea(x, y, x+1, y+1);

	HIGH = color>>8;
	LOW = color;

	TFT_Write_Data(HIGH);
	TFT_Write_Data(LOW & 0xFF);

}

void TFT_WriteChar(u8 x, u8 y, char ch, FontDef font, u16 color, u16 bgcolor)
{
	u8 HIGH, LOW;
	u32 i, b, j;

	TFT_SetDrawingArea(x, y, x+font.width-1, y+font.height-1);
	for(i = 0; i < font.height; i++)
	{
		b = font.data[(ch - 32) * font.height + i];
		for(j = 0; j < font.width; j++)
		{
			if((b << j) & 0x8000)
			{
				HIGH = color>>8;
				LOW = color;

				TFT_Write_Data(HIGH);
				TFT_Write_Data(LOW & 0xFF);

			}
			else
			{
				HIGH = bgcolor>>8;
				LOW = bgcolor;

				TFT_Write_Data(HIGH);
				TFT_Write_Data(LOW & 0xFF);
			}
		}
	}
}

void TFT_FillDisplay(const u16 color)
{
	u16 i = 0;
	u8 HIGH, LOW;

	//SET X coordinate
	TFT_Write_Command(0x2A);
	// start at -> 0,0
	TFT_Write_Data(0);
	TFT_Write_Data(0);
	// end at -> 127
	TFT_Write_Data(0);
	TFT_Write_Data(127);

	//SET Y coordinate
	TFT_Write_Command(0x2B);
	// start at -> 0,0
	TFT_Write_Data(0);
	TFT_Write_Data(0);
	// end at -> 127
	TFT_Write_Data(0);
	TFT_Write_Data(159);

	// WRITE on screen
	TFT_Write_Command(0x2C);
	for(i=0; i<20480; i++){
		HIGH = color>>8;
		LOW = color;
		TFT_Write_Data(HIGH);
		TFT_Write_Data(LOW);
	}
}

void TFT_WriteString(u8 x, u8 y, const char* str, FontDef font, u16 color, u16 bgcolor)
{
	while(*str != '\0')
	{
		if(x + font.width >= TFT_WIDTH)
		{
			x = 0;
			y += font.height;

			if(y + font.height >= TFT_HEIGHT)
			{
				break;
			}

			if(*str == ' ')
			{
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}

		TFT_WriteChar(x, y, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}
}
void TFT_FillRectangle(u8 x, u8 y, u8 w, u8 h, u16 color)
{
	u8 HIGH = color >> 8;
	u8 LOW = color & 0xFF;

	if ((x >= TFT_WIDTH) || (y >= TFT_HEIGHT))
		return;

	if ((x + w - 1) >= TFT_WIDTH)
		w = TFT_WIDTH - x;

	if ((y + h - 1) >= TFT_HEIGHT)
		h = TFT_HEIGHT - y;

	TFT_SetDrawingArea(x, y, x + w - 1, y + h - 1);

	for (u16 i = 0; i < h; i++)
	{
		for (u16 j = 0; j < w; j++)
		{
			TFT_Write_Data(HIGH);
			TFT_Write_Data(LOW);
		}
	}
}



