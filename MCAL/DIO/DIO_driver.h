
#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_
#include "StdTypes.h"
#include "MemoMap.h"
#include "Utils.h"

typedef enum {
	PA=0,
	PB=1,
	PC=2,
	PD=3
}DIO_Port_name;

typedef enum {
	OUTPUT,
	INFREE,
	INPULL
}DIO_PinStatus_type;

typedef enum {
	LOW,
	HIGH
}DIO_PinVoltage_type;

typedef enum {
	PINA0=0,
	PINA1=1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS
}DIO_Pin_name;

void DIO_Init(void);

void DIO_WritePin(DIO_Pin_name pin,DIO_PinVoltage_type volt);

void DIO_WritePort(DIO_Port_name port,u8 value);

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_name pin);

u8 DIO_ReadPort(DIO_Port_name port);

void DIO_TogglePin(DIO_Pin_name pin);




#endif 