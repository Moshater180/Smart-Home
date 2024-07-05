#include "Ex_INTERRUPT.h"


void Ext_Int_Enable(Ext_Int_Types INT_Id){
	
	switch (INT_Id)
	{
		case Ext_INT0:
		SET_BIT(GICR_Reg,GICR_Reg_INT0);
		break;
		case Ext_INT1:
		SET_BIT(GICR_Reg,GICR_Reg_INT1);
		break;
		case Ext_INT2:
		SET_BIT(GICR_Reg,GICR_Reg_INT2);
		break;
	}
	
	
}
void Ext_Int_Disable(Ext_Int_Types INT_Id){
	switch (INT_Id)
	{
		case Ext_INT0:
		CLR_BIT(GICR_Reg,GICR_Reg_INT0);
		break;
		case Ext_INT1:
		CLR_BIT(GICR_Reg,GICR_Reg_INT1);
		break;
		case Ext_INT2:
		CLR_BIT(GICR_Reg,GICR_Reg_INT2);
		break;
	}
	
}


void Ext_Int_SC(Ext_Int_Types INT_Id, Ext_ISC_Types SC_Id){
	
	switch (INT_Id)
	{
		case Ext_INT0:
		
		MCUCR_Reg = (MCUCR_Reg & 0xFC) | (SC_Id<<0);
		
		break;
		case Ext_INT1:
		MCUCR_Reg = (MCUCR_Reg & 0xF3) | (SC_Id<<2);
		break;
		
		case Ext_INT2:
		if (SC_Id == Rising_Edge){
			SET_BIT(MCUCSR_Reg,MCUCSR_Reg_SC);
		}
		else if(SC_Id == Falling_Edge)
		{
			CLR_BIT(MCUCSR_Reg,MCUCSR_Reg_SC);
		}else
		{
			// do nuthin
		}
		break;
	}

}
