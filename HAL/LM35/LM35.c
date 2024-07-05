#include "LM35.h"

void LM35_Init(void){
	ADC_Init();
}
s16 LM35_Read(){
	s16 temp = 0;
	temp = (ADC_Read(ADC_Channel0))/4;
	return temp;
}
