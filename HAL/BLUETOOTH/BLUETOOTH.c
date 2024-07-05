#include "Bluetooth.h"

void Bluetooth_Init()
{
	UART_Init();
}
void Bluetooth_Transmit(s8 data){
	UART_Send( data);
}
s8 Bluetooth_Receive(){
	return  UART_Recieve();
}
void Bluetooth_TransmitString(s8 * string){
	UART_SendString( string);
}

bool_t BluetoothCheckIfAlpha(s8 data){
	// function used to check if data is a char from a to z (a-z 97-122)
	for( s8 i = 97 ; i <= 122; i++ ) {
		if (i == data){
			return TRUE;
			}else{
			// continue
		}
		
	}
	return FALSE;
}
void Bluetooth_ReceiveString(s8 * ptr)
{
	//UART_recieveString(ptr);
}
