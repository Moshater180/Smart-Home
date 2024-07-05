#ifndef BUZZER_H_
#define BUZZER_H_

#include "DIO_driver.h"

#define Buzzer_Signal PINA3
#define Buzzer_Port 'A'
void Buzzer_TurnOn(void);
void Buzzer_TurnOff(void);

#endif 