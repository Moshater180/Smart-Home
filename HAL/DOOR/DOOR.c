#include "Door.h"



void DOOR_Init(void){
	TCNT1 = 0;			/* Set timer1 count zero */
	ICR1 = 2499;		/* Set TOP count for timer1 in ICR1 register */
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
}


void DOOR_Open(void){		
	OCR1A = 316;	/* Set servo shaft at +90° position */
}
void DOOR_Close(void){	
	OCR1A = 97;		/* Set servo shaft at 0° position */
}