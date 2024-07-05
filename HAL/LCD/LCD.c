#include "LCD.h"

#if LCD_MODE==_8_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(1);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}

#elif LCD_MODE == _4_BIT

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}


void LCD_Init(void)
{
	_delay_ms(50);
	DIO_WritePin(EN,LOW);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);//  2 line,5*7;
	LCD_WriteCommand(0x0c);//  cursor , 0x0f,  0x0e;
	LCD_WriteCommand(0x01);//  clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//  increase ddram address , no shift
}
#endif


/*************************************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}

void LCD_WriteString(u8*str)
{
	u8 i = 0;
	//	for (i=0;str[i];i++)
	//	{
	//		LCD_WriteChar(str[i]);
	//	}
	do
	{
		LCD_WriteChar(str[i]);
		i++;
	}while(str[i]!='\0');
}


void LCD_WriteNumber(s16 num)//-2503
{
	u8 str[20];
	u8 rem,i=0;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		rem=num%10;
		str[i]=rem+'0';
		num=num/10;
		i++;
	}
	for (s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
}



void LCD_WriteBinary(s64 num)//00000101
{
	s8 i,flag=0;
	for (i=63;i>=0;i--)
	{
		if ((num>>i)&1)
		{
			LCD_WriteChar('1');
			flag=1;
		}
		else
		{
			if (flag==1)
			{
				LCD_WriteChar('0');
			}
			
		}
	}

}

void LCD_WriteHex(s64 num)
{
	u8 str[20];
	u8 rem,i=0;
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if (num<0)
	{
		num=num*-1;
		LCD_WriteChar('-');
	}
	while(num>0)
	{
		rem=num%16;
		switch (rem)
		{
			case 10 :
			str[i]='A';
			break;
			case 11 :
			str[i]='B';
			break;
			case 12 :
			str[i]='C';
			break;
			case 13 :
			str[i]='D';
			break;
			case 14 :
			str[i]='E';
			break;
			case 15 :
			str[i]='F';
			break;
			default:
			str[i]=rem+'0';
			break;
		}
		num=num/16;
		i++;
	}
	for (s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
}
void LCD_WriteNumber_4D(u16 num)//14542
{
	LCD_WriteChar(((num%10000)/1000)+'0');
	LCD_WriteChar(((num%1000)/100)+'0');
	LCD_WriteChar(((num%100)/10)+'0');
	LCD_WriteChar(((num%10)/1)+'0');
}

void LCD_GoTo(u8 line ,u8 cell)
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+cell);
	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+cell);
	}
	
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
	_delay_ms(2);
}

void LCD_GoToClear(u8 line ,u8 cell,u8 numOfCells)
{
	u8 i;
	LCD_GoTo(line,cell);
	for (i=0;i<numOfCells;i++)
	{
		LCD_WriteChar(' ');
	}
	
}

void LCD_GoToWriteString(u8 line,u8 cell,u8*str)
{
	LCD_GoTo(line,cell);
	LCD_WriteString(str);
}
void LCD_Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD
	LCD_WriteCommand(0x80);
}
