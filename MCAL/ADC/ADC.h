#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include "MemoMap.h"
#include "ADC_typedef.h"
#include "Utils.h"
#include "StdTypes.h"
#define F_CPU 16000000UL
#include <util/delay.h>


void ADC_Init();
s16 ADC_Read(ADC_ChannelTypes ChannelId);
#endif 