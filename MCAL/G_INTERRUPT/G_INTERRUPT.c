# include "G_INTERRUPT.h"

void Globle_Int_Enable(){
	
	SET_BIT(SREG_Reg,SREG_Enable_bit);
	
}