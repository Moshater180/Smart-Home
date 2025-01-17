
#ifndef HEADERS_EEPROM_H_
#define HEADERS_EEPROM_H_

#include "StdTypes.h"

/*
	Function Name        : EEPROM_ui8ReadByteFromAddress
	Function Returns     : u8
	Function Arguments   : const u16 uiAddress
	Function Description :  Read one byte from the given  address.
*/
u8 EEPROM_ui8ReadByteFromAddress(const u16 u16Address);

/*
	Function Name        : EEPROM_vReadBlockFromAddress
	Function Returns     : void
	Function Arguments   : const u16 uiAddress, u8* dist,const u16 size
	Function Description : Read block of bytes of the given size (size) and save the result to given array(dist array).
*/
void EEPROM_vReadBlockFromAddress(const u16 u16Address, u8* dist,const u16 size);

/*
	Function Name        : EEPROM_vWriteByteToAddress
	Function Returns     : void
	Function Arguments   : const u16 uiAddress, const u8 uiData
	Function Description : Write one byte to given address.
*/
void EEPROM_vWriteByteToAddress(const u16 u16Address, const u8 u8Data);

/*
	Function Name        : EEPROM_vWriteBlockToAddress
	Function Returns     : void
	Function Arguments   : const u16 uiAddress, const u8* uiData,const u16 size
	Function Description : Write block of bytes  of the given size (size) to EEPROM at the given address(u16Address) from the given array (u8Data).
*/
void EEPROM_vWriteBlockToAddress(const u16 u16Address, const u8* u8Data,const u16 size);

#endif /* HEADERS_EEPROM_H_ */
