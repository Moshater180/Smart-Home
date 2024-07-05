
#include "Utils.h"
#include "StdTypes.h"

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

/* UART Modes */
#define SYNCHRONOUS                       0
#define ASYNCHRONOUS_NORMAL_SPEED         1
#define ASYNCHRONOUS_DOUBLE_SPEED         2
/* stop bit options */
#define ONE_STOP_BIT                      0
#define TWO_STOP_BIT                      1
/* parity bit options */
#define NO_PARITY_BIT                     0
#define ODD_PARITY_BIT                    1
#define EVEN_PARITY_BIT                   2
/* data size options */
#define FIVE_BIT_DATA                     0
#define SIX_BIT_DATA                      1
#define SEVEN_BIT_DATA                    2
#define EIGHT_BIT_DATA                    3
#define NINE_BIT_DATA                     4


#define U2X 1
#define TXEN 3
#define RXEN 4
#define RXCIE 7

/* Function name        : UART_Init
   Function description : Initialize UART peripheral 
   Function arguments   : void 
   Function returns     : void
*/
void UART_Init(void);

/* Function name        : UART_Send
   Function description : send char using UART 
   Function arguments   : u8 Copy_u8Char
   Function returns     : void
*/
void UART_Send(u8 Copy_u8Char);

/* Function name        : UART_Recieve
   Function description : Receive char using UART
   Function arguments   : u8 Copy_u8Char
   Function returns     : void
*/
u8 UART_Recieve(void);

/* Function name        : UART_SendString
   Function description : Send string using UART protocol
   Function arguments   : u8 *Copy_u8PtrString
   Function returns     : void
*/
void UART_SendString(u8 *Copy_u8PtrString);
void UART_DisableRX (void);
void UART_EnableRX (void);
#endif /* UART_INTERFACE_H_ */