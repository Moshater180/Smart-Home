#ifndef AC_LAMP_H_
#define AC_LAMP_H_
/********************************************/
#include "DIO_driver.h"
#include "G_INTERRUPT.h"
#include "Ex_INTERRUPT.h"
/*******************************************/
#define Lamp_trigger 27
#define Lamp_port 'C'
#define Lamp_AC_Zero_detect PIND2
#define Lamp_AC_Zero_Port 'D'

void AC_Lamp_Init(void);
void AC_Lamp_On(void);
void AC_Lamp_Off(void);
s16 AC_Lamp_Set_Dimming(u8 data);
void delayDimming(s8 dimming);

#endif 