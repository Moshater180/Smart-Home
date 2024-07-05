#include "ADC.h"



void ADC_Init(){
	//ACSR_Reg = (ACSR_Reg & 0xFC)|(mode<<0);
	SET_BIT(ADMUX_Reg,ADMUX_REF0_Bit); // internal volt ref set 2.56v
	SET_BIT(ADMUX_Reg,ADMUX_REF1_Bit);
	//CLR_BIT(ADMUX_Reg,ADC_Output_Adj_Bit);
	
	SET_BIT(ADCSRA_Reg,ADCSRA_Enable_Bit); // enable
	
	//SET_BIT(ADCSRA_Reg,ADCSRA_ADPS0_Bit); // F_CPU /128
	SET_BIT(ADCSRA_Reg,ADCSRA_ADPS1_Bit);
	SET_BIT(ADCSRA_Reg,ADCSRA_ADPS2_Bit);
}


s16 ADC_Read(ADC_ChannelTypes ChannelId){
	s16 read = 0;
	
	//ADMUX_Reg = (ADMUX_Reg & 0xE0)|(ChannelId & 0b00011111);
	SET_BIT(ADCSRA_Reg,ADCSRA_ADSC_Bit);
	while(IS_BIT_CLR(ADCSRA_Reg,ADCSRA_ADIF_Bit));
	SET_BIT(ADCSRA_Reg,ADCSRA_ADIF_Bit);
	read = ADCL_Reg;
	read |=  (ADCH_Reg << 8);
	return read;
}

