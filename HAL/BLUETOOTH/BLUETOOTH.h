#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "UART.h"

void Bluetooth_Init();
void Bluetooth_Transmit(s8 data);
s8 Bluetooth_Receive();
bool_t BluetoothCheckIfAlpha(s8 data);
void Bluetooth_TransmitString(s8 * string);
void Bluetooth_ReceiveString(s8 * ptr);
#endif 