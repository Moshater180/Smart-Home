#include "AC_Lamp.h"


void AC_Lamp_Init(void){
	
	
	// initialize lamp bits for trigger and detector to 0
	DIO_WritePin(Lamp_AC_Zero_detect,1);
	DIO_WritePin(Lamp_trigger,0);
	
	// Enable global interrupts and external interrupt to use in zero detect circuit
	Globle_Int_Enable();			// Enable global interrupt
	Ext_Int_Enable(Ext_INT0);		// Enable external interrupt on PIN 2 in PORT D
	Ext_Int_Disable(Ext_INT0);
	Ext_Int_SC(Ext_INT0,Low_volt); // interrupt on low volts
	
	
}
void AC_Lamp_On(void){
	DIO_WritePin(Lamp_trigger,1);

}
void AC_Lamp_Off(void){
	DIO_WritePin(Lamp_trigger,0);

}

s16 AC_Lamp_Set_Dimming(u8 data){
	s16 dimming = 75*data; // set delay value to control dimming of lamp
	return dimming;
}

void delayDimming(s8 dimming){
	
	while(dimming > 0){
		
		_delay_ms(1);
		dimming--;
		
	}	
}
