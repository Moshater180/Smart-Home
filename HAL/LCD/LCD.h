
#ifndef LCD_H_
#define LCD_H_

#define  F_CPU   8000000
#include <util/delay.h>
#include "StdTypes.h"
#include "DIO_driver.h"
#include "Utils.h"
#define  _4_BIT  1
#define  _8_BIT  2


/**************************pin config************************/

#define  LCD_MODE   _4_BIT

#define  RS   10		//Register Selection H: Display Data L: Instruction Code
#define  EN   8		//Enable  Read data when E is “H”, write data at the falling edge of E
#define  RW   9

#define  D7   7
#define  D6   6
#define  D5   5
#define  D4   4
#define  D3   3
#define  D2   2
#define  D1   1
#define  D0   0

#define  LCD_PORT   PA

/****************************************************************************/


void LCD_Init();

void LCD_Clear(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8*str);
void LCD_WriteNumber(s16 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_WriteBinary(s64 num);
void LCD_WriteHex(s64 num);

void LCD_GoTo(u8 line ,u8 cell);

void LCD_GoToClear(u8 line ,u8 cell,u8 numOfCells);

void LCD_GoToWriteString(u8 line,u8 cell,u8*str);
void LCD_Create_Character(u8*p,u8 address);

#endif /* LCD_H_ */