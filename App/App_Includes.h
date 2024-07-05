#ifndef APP_INCLUDES_H_
#define APP_INCLUDES_H_

/*********************** Created headers ******************************/
#include "App_lcfg.h"
/***** General lib *****/
#include "MemoMap.h"
#include "StdTypes.h"
#include "Utils.h"

/***** MCAL *****/
#include "DIO_driver.h"
#include "Ex_INTERRUPT.h"
#include "G_INTERRUPT.h"
#include "ADC.h"
#include "Timer0.h"
#include "UART.h"
#include "EEPROM.h"
#include "Timer1.h"

/***** HAL *****/
#include "LEDs.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "BLUETOOTH.h"
#include "LM35.h"
#include "AC_LAMP.h"
#include "BUZZER.h"
#include "DOOR.h"
#include "AC.h"


/************************************************************************/


/*********************** Avr libs ***************************************/
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
/************************************************************************/





#endif 