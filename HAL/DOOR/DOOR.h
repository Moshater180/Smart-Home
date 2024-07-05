#ifndef DOOR_H_
#define DOOR_H_
/*********************************************/
#include "StdTypes.h"
#include "DIO_driver.h"
#include "MemoMap.h"
/*********************************************/
#define DOOR_Signal PIND5
#define DOOR_Port 'D'
#define OCR1A     (*(volatile unsigned short*)0x4A)
void DOOR_Init(void);
void DOOR_Open(void);
void DOOR_Close(void);

#endif 