#include "AC.h"

void AC_TurnOn(void){
	DIO_WritePin(AC_Motor_Signal,1); 
}
void AC_TurnOff(void){
	DIO_WritePin(AC_Motor_Signal,0); 
}