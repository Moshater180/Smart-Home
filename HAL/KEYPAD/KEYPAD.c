#include "KEYPAD.h"
u8 KEYPAD_Getkey(void)
{
	u8 r,c,key=NO_KEY;
	DIO_WritePin(first_output,HIGH);
	DIO_WritePin(first_output+1,HIGH);
	DIO_WritePin(first_output+2,HIGH);
	DIO_WritePin(first_output+3,HIGH);
	for (r=0;r<ROWS;r++)
	{
		DIO_WritePin(first_output+r,LOW);
		for (c=0;c<COLS;c++)
		{
			if (DIO_ReadPin(first_input+c)==LOW)
			{
				key=keysArray[r][c];
				while (DIO_ReadPin(first_input+c)==LOW);
			}
		}
		DIO_WritePin(first_output+r,HIGH);
	}
	return key;
}

void KEYPAD_Control (bool_t key)
{
	//cli();
	u8 KEY_Pressed=NO_KEY;
	LCD_Clear();
	LCD_WriteString("Keypad is ");
	LCD_GoTo(1,0);
	LCD_WriteString("allowed now");
	_delay_ms(1200);
	LCD_Clear();
	LCD_WriteString("Be attention to");
	LCD_GoTo(1,0);
	LCD_WriteString("the following:");
	_delay_ms(1800);
	LCD_Clear();
	LCD_WriteString("Press 1 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Control LED1");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 2 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Control LED2");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 3 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Control LED3");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 4 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Control LED4");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 5 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Control LED5");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 6 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Turn ON LAMP");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 7 ");
	LCD_GoTo(1,0);
	LCD_WriteString("to Turn OFF LAMP");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press 8 to");
	LCD_GoTo(1,0);
	LCD_WriteString("TurnON the Alarm");
	_delay_ms(1000);
	LCD_Clear();
	LCD_WriteString("Press c to Exit");
	LCD_GoTo(1,0);
	LCD_WriteString("from Emergency");
	_delay_ms(1000);
	LCD_Clear();
	while (key==TRUE)
	{
		LCD_WriteString("It is ");
		LCD_GoTo(1,0);
		LCD_WriteString("Emergency now!!!");
		_delay_ms(100);
	//wait till key pressed
	KEY_Pressed=KEYPAD_Getkey();
	while(KEY_Pressed==NO_KEY)
	{
		KEY_Pressed=KEYPAD_Getkey();
	}
	switch (KEY_Pressed)
	{
	case '1' :
	LCD_Clear();
	DIO_TogglePin(LED1_PIN);
	LCD_WriteString("LED1 is Toggled");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '2' :
	LCD_Clear();
	DIO_TogglePin(LED2_PIN);
	LCD_WriteString("LED2 is Toggled");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '3' :
	LCD_Clear();
	DIO_TogglePin(LED3_PIN);
	LCD_WriteString("LED3 is Toggled");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '4' :
	LCD_Clear();
	DIO_TogglePin(LED4_PIN);
	LCD_WriteString("LED4 is Toggled");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '5' :
	LCD_Clear();
	DIO_TogglePin(LED5_PIN);
	LCD_WriteString("LED5 is Toggled");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '6' :
	LCD_Clear();
	AC_Lamp_On();
	LCD_WriteString("AC Lamp On");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '7' :
	LCD_Clear();
	AC_Lamp_Off();
	LCD_WriteString("AC Lamp OFF");
	_delay_ms(500);
	LCD_Clear();
	break;
	case '8' :
	Buzzer_TurnOn();
	LCD_Clear();
	LCD_WriteString("Restart");
	LCD_GoTo(1,0);
	LCD_WriteString("Required");
	while(1);
	break;
	case 'c' :
	LCD_Clear();
	LCD_WriteString("Exiting The");
	LCD_GoTo(1,0);
	LCD_WriteString("Emergency");
	LCD_WriteChar('.');
	_delay_ms(500);
	LCD_WriteChar('.');
	_delay_ms(300);
	LCD_WriteChar('.');
	_delay_ms(300);
	LCD_WriteChar('.');
	_delay_ms(300);
	LCD_WriteChar('.');
	_delay_ms(300);
	LCD_WriteChar('.');
	_delay_ms(300);
	LCD_WriteChar('.');
	_delay_ms(300);
	key=FALSE;
	break;
	default :
	LCD_Clear();
	LCD_WriteString("Worng Key");
	break;
	}
	}
	//sei();
}