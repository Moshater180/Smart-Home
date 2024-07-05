#include "Buzzer.h"


void Buzzer_TurnOn(void){
	 
	DIO_WritePin(Buzzer_Signal,1);
}
void Buzzer_TurnOff(void){
	
	DIO_WritePin(Buzzer_Signal,0);
}