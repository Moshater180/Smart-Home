#ifndef EX_INTERRUPT_TYPEDEF_H_
#define EX_INTERRUPT_TYPEDEF_H_

typedef enum{
	
	Ext_INT0=0,
	Ext_INT1,
	Ext_INT2
}Ext_Int_Types;


typedef enum{
	Low_volt=0,
	Both_Edges,
	Falling_Edge,
	Rising_Edge
}Ext_ISC_Types;

#endif 