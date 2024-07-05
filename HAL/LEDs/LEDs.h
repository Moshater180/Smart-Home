#ifndef LEDS_H_
#define LEDS_H_
/************************************************************/
#include "DIO_driver.h"
#include "LEDs_cfg.h"
#include "LCD.h"
/*************************************************************/
#define LED1_PIN    11
#define LED2_PIN    12
#define LED3_PIN    13
#define LED4_PIN    14
#define LED5_PIN    15
/*
	Function Name        : LED_vToggle
	Function Returns     : void
	Function Arguments   : u8 portname,u8 pinnumber
	Function Description : Toggle the led connected to the given pin and port.
*/
void LED_vToggle(u8 pin);//


#endif 