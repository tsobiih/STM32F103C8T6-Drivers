/*
 * TFT_interface.h
 *
 *  Created on: Apr 12, 2025
 *      Author: Mostafa Mohamed
 */
#ifndef TFT_INTERFACE_H_
#define TFT_INTERFACE_H_

#include "fonts.h"

void TFT_Write_Data(u8 data);
void TFT_Write_Command(u8 cmd);
void TFT_init();
void TFT_ImgDisplay(const u16 *imgArr);
void TFT_SWReset(void);
void TFT_SetDrawingArea(u8 x0, u8 y0, u8 x1, u8 y1);
void TFT_DrawPixel(u8 x, u8 y, u16 color);
void TFT_WriteChar(u8 x, u8 y, char ch, FontDef font, u16 color, u16 bgcolor);
void TFT_FillDisplay(const u16 color);
void TFT_WriteString(u8 x, u8 y, const char* str, FontDef font, u16 color, u16 bgcolor);
void TFT_FillRectangle(u8 x, u8 y, u8 w, u8 h, u16 color);

// Color definitions
#define	TFT_BLACK   0x0000
#define TFT_GRAY	0x8C51
#define	TFT_BLUE    0x001F
#define TFT_BBLUE	0x8D1F
#define	TFT_RED     0xF800
#define	TFT_GREEN   0x07E0
#define TFT_CYAN    0x07FF
#define TFT_MAGENTA 0xF81F
#define TFT_YELLOW  0xFFE0
#define TFT_WHITE   0xFFFF




#endif /* TFT_INTERFACE_H_ */
