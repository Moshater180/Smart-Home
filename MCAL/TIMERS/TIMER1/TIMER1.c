#include "Timer1.h"


void TIMER1_Init(void){
	TCCR1A|= (TCCR1A_COM1A1)|(TCCR1A_COM1B1)|(TCCR1A_WGM11); // //NON Inverted PWM
	
	TCCR1B|= (TCCR1B_WGM13)|(TCCR1B_WGM12)|(TCCR1B_CS11)|(TCCR1B_CS10); //PRESCALER=64 MODE   14(FAST PWM) 1110
}

void TIMER1_Set_ICR(u16 ICR){
	
	ICR1H = (u8) ((ICR>>8) & 0x00FF);
	ICR1L = (u8) (ICR & 0x00FF);
	
	
}

void TIMER1_Set_OCR1A(u16 OCRA){
	
	OCR1AH_Reg = (u8) ((OCRA>>8) & 0x00FF);
	OCR1AL_Reg = (u8) (OCRA & 0x00FF);
	
	
}