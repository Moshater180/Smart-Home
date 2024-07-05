#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

#define LM35_ADC_Channel ADC_Channel0
void LM35_Init();
s16 LM35_Read(ADC_Channel0);

#endif 