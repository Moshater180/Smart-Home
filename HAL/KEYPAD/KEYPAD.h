#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "App_Includes.h"
/**********************Config***********************************************/
#define first_output		20
#define first_input			16
#define NO_KEY				0

#define ROWS	4
#define	COLS	4

static u8 keysArray [ROWS][COLS]={{'7','8','9','/'},
								  {'4','5','6','*'},
								  {'1','2','3','-'},
								  {'c','0','=','+'}};					
/**********************************************************************************/

u8 KEYPAD_Getkey(void);
void KEYPAD_Control (bool_t key);
#endif 