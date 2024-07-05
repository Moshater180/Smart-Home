#ifndef EX_INTERRUPT_H_
#define EX_INTERRUPT_H_
/*********************************************/
#include "EX_INTERRUPT_typedef.h"
#include "StdTypes.h"
#include "MemoMap.h"
#include "Utils.h"
/*********************************************/

void Ext_Int_Enable(Ext_Int_Types INT_Id);
void Ext_Int_Disable(Ext_Int_Types INT_Id);
void Ext_Int_SC(Ext_Int_Types INT_Id, Ext_ISC_Types SC_Id);




#endif 