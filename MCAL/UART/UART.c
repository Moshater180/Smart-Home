#define F_CPU 8000000
#include <util/delay.h>
#include "UART.h"
#include "UART_Private.h"
#include "UART_Confic.h"
#include <avr/interrupt.h>
void UART_Init(void)
{
	//baud rate 9600 f=8mhz,normal speed
	UBRRL=51;
	//normal speed
	CLR_BIT(UCSRA,U2X);
	//frame-> parity , data bits , stop bits
	//enable
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	sei();
	SET_BIT(UCSRB,RXCIE);
}
void UART_DisableRX (void)
{
	CLR_BIT(UCSRB,RXEN);
}
void UART_EnableRX (void)
{
	CLR_BIT(UCSRB,RXEN);
}

void UART_Send(u8 Copy_u8Char)
{
	/* wait while UDR buffer is not empty */
	while(READ_BIT(UCSRA,5)==0);
	/* store data in UDR */
	UDR=Copy_u8Char;
}

u8 UART_Recieve(void)
{
	
	//	while(READ_BIT(UCSRA,7)==0); // wait while the receive buffer is empty
	if (READ_BIT(UCSRA,7)==1)
	{
		return UDR;
	}
	else
	{
		return NULL;
	}
}

void UART_SendString(u8 *Copy_u8PtrString)
{
	while(*Copy_u8PtrString!='\0')
	{
		UART_Send(*Copy_u8PtrString);
		Copy_u8PtrString++;
		_delay_ms(200);
	}
}
