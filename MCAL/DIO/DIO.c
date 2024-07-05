#include "DIO_driver.h"
#include "DIO_Private.h"

void DIO_InitPin(DIO_Pin_name pin,DIO_PinStatus_type status)
{
	DIO_Port_name port=pin/8;
	u8 pin_num=pin%8;
	switch (port)
	{
		case PA :
		switch (status)
		{
			case OUTPUT :
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case INPULL :
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case INFREE :
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			default:
			break;
		}
		break;
		case PB :
		switch (status)
		{
			case OUTPUT :
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case INPULL :
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case INFREE :
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			default:
			break;
		}
		break;
		case PC :
		switch (status)
		{
			case OUTPUT :
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case INPULL :
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case INFREE :
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			default:
			break;
		}
		break;
		case PD :
		switch (status)
		{
			case OUTPUT :
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			case INPULL :
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
			case INFREE :
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

void DIO_Init(void)
{
	DIO_Pin_name i;
	for (i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
	
}

void DIO_WritePin(DIO_Pin_name pin,DIO_PinVoltage_type volt)//17	
{
	DIO_Port_name port=pin/8;
	u8 pin_num=pin%8;
	
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
	else if (volt==LOW)
	{
		switch(port)
		{
			case PA:
			
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			
			CLR_BIT(PORTD,pin_num);
			break;
		}
	}
}

void DIO_WritePort(DIO_Port_name port,u8 value)
{
	switch (port)
	{
		case PA :
		PORTA=value;
		break;
		case PB :
		PORTB=value;
		break;
		case PC :
		PORTC=value;
		break;
		case PD :
		PORTD=value;
		break;
	}
	
}

DIO_PinVoltage_type DIO_ReadPin(DIO_Pin_name pin)
{
	DIO_Port_name port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVoltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt= READ_BIT(PINA,pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volt= READ_BIT(PINC,pin_num);
		break;
		case PD:
		volt= READ_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

u8 DIO_ReadPort(DIO_Port_name port)
{
	u8 value=0;
	switch(port)
	{
		case PA :
		value = PINA;
		break;
		case PB :
		value = PINB;
		break;
		case PC :
		value = PINC;
		break;
		case PD :
		value = PIND;
		break;
	}
	return value;
}

void DIO_TogglePin(DIO_Pin_name pin)
{
	DIO_Port_name port=pin/8;
	u8 pin_num=pin%8;
	switch(port)
	{
		case PA :
		TOG_BIT(PORTA,pin_num);
		break;
		case PB :
		TOG_BIT(PORTB,pin_num);
		break;
		case PC :
		TOG_BIT(PORTC,pin_num);
		break;
		case PD :
		TOG_BIT(PORTD,pin_num);
		break;
	}
}
