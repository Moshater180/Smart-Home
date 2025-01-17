#ifndef ADC_TYPEDEF_H_
#define ADC_TYPEDEF_H_
typedef enum{
	Output_mode=0,
	Falling_out_Edge=2,
	Rising_out_Edge
}ADC_Mode;

typedef enum{
	Left_shift=0,
	Right_shift
}ADC_Result_Adjustment;

typedef enum{
	ADC_Channel0=0,
	ADC_Channel1,
	ADC_Channel2,
	ADC_Channel3,
	ADC_Channel4,
	ADC_Channel5,
	ADC_Channel6,
	ADC_Channel7
}ADC_ChannelTypes;
#endif