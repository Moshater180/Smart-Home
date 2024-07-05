#ifndef TIMER1_H_
#define TIMER1_H_
/*******************************************/
#include "ADC_typedef.h"
#include "StdTypes.h"
#include "MemoMap.h"
#include "Utils.h"
/******************************************/

void TIMER1_Init(void);
void TIMER1_Set_ICR(u16 ICR);
void TIMER1_Set_OCR1A(u16 OCRA);

#endif 