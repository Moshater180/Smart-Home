#include "App_Includes.h"

//volatile u16 session_counter = 0;//indicate session time
//u8 timeout_flag = FALSE;//stores if the session is still valid or outdated
u8 pass_counter=0;//the counter of the characters of the password
u8 pass[PASS_SIZE]={NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED,NOT_STORED};//the array where it stored the password
u8 block_mode_flag = FALSE;//is true if the login is blocked or false if not blocked
s16 TempReading = 0;
u8 key_pressed = NO_KEY;
bool_t Keypad_allowed=FALSE;
u8 LCD_flag_on = 0;
u8 LCD_flag_off= 0;
int main(void)
{
	u8 flag=0;
	u8 login_mode = NO_MODE; //Store the current user mode admin or guest or not logged in
	u8 data_pressed = NULL;//
	
	/*****************  INITIALIZE  ***********************/
	DIO_Init();
	LCD_Init();//initializes the LCD screen
	UART_Init();//initializes the communication protocol of UART
	ADC_Init();//initialize the ADC of the micro controller
	AC_Lamp_Init();
	Bluetooth_Init();
	DOOR_Init();
	LM35_Init();
	cli();
	/******************************************************/
	/* Printing Welcome screen */
	LCD_WriteString("Welcome to smart");
	LCD_GoTo(1,0);
	LCD_WriteString("home system");
	_delay_ms(1000);//Halt the system for the given time in (ms)
	LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
	/***************************/
	u8 request = DEFAULT_ACK;//the value that is received from Bluetooth
	u8 response = DEFAULT_ACK;//the values that is sent back to Bluetooth
	/*Setting Admin and Guest passwords if not set */
	//read the state of the the passwords of the admin and guest if both are set or not set
	if ( (EEPROM_ui8ReadByteFromAddress(ADMIN_PASS_STATUS_ADDRESS)!=PASS_SET))
	{
		LCD_WriteString("Login for");//printing login menu
		LCD_GoTo(1,0);//move the cursor to the second line
		LCD_WriteString("first time");
		_delay_ms(1000);//Halt the system for the given time in (ms)
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		LCD_WriteString("Set Admin pass");//printing the set admin password menu
		_delay_ms(1000);
		LCD_Clear();
		LCD_WriteString("Admin pass:");
		_delay_ms(1000);
		LCD_GoTo(1,0);
		/********************************* setting Admin password **********************************************/
		while (pass_counter<PASS_SIZE )//loop till the user finish inserting the pass
		{
			data_pressed=0;
			data_pressed=Bluetooth_Receive();
			while(data_pressed==NULL)
			{
				data_pressed=Bluetooth_Receive();
			}
			while(data_pressed!='Q' && flag==0)
			{
				data_pressed=Bluetooth_Receive();
			}
			
			if(data_pressed =='Q')
			{
				flag=1;
				while(data_pressed=='Q' || data_pressed==NULL)
				{
					data_pressed=Bluetooth_Receive();
				}
			}
			if (data_pressed!=0 || flag==1)
			{
				pass[pass_counter]=data_pressed;//add the entered character to the pass array
				LCD_WriteChar(data_pressed);//print the entered character
				_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
				LCD_GoTo(1,0+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
				LCD_WriteChar(PASSWORD_SYMBOL); // to display (Password sign *)
				_delay_ms(100);//Halt the system for the given time in (ms)
				pass_counter++;//increase the characters count
			}
		}
		data_pressed=Bluetooth_Receive();
		while(data_pressed!='Q' || data_pressed==NULL)
		{
			data_pressed=Bluetooth_Receive();
		}
		EEPROM_vWriteBlockToAddress(EEPROM_ADMIN_ADDRESS,pass,PASS_SIZE);//save the entire password as a block to the EEPROM
		EEPROM_vWriteByteToAddress(ADMIN_PASS_STATUS_ADDRESS,PASS_SET);//write the status of pass as it is set
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		LCD_WriteString("Pass Saved");// show pass saved message
		_delay_ms(500);//Halt the system for the given time in (ms)
		LCD_Clear();//remove all previously printed characters on the LCD and move the cursor to the first column of the first row
		EEPROM_vWriteByteToAddress(LOGIN_BLOCKED_ADDRESS,FALSE);
	}//The end of if admin and guest password is set
	else//this code of else run only if the system is not running for the first time (ADMIN and GUEST passwords are set)
	{
		block_mode_flag = EEPROM_ui8ReadByteFromAddress(LOGIN_BLOCKED_ADDRESS); //read the blocked location from EEPROM
	}
	sei();
	while (1)//The start of the periodic code
	{
		/********************************** Air Cond. ************************************************************/
		TempReading =(LM35_Read(LM35_ADC_Channel)); // Read Sensor values constantly
		if (TempReading > 28)
		{
			AC_TurnOn();
			if(LCD_flag_on == 0)
			{
				LCD_flag_on = 1;
				LCD_flag_off = 0;
				LCD_GoTo(0,0);
				//				_delay_ms(100);
				LCD_WriteString("Air Conditioner");
				LCD_GoTo(1,0);
				//				_delay_ms(100);
				LCD_WriteString("is ON           ");
			}
		}
		else if (TempReading < 21 )
		{
			AC_TurnOff();
			if(LCD_flag_off == 0)
			{
				LCD_flag_on = 0;
				LCD_flag_off = 1;
				LCD_GoTo(0,0);
				//				_delay_ms(100);
				LCD_WriteString("Air Conditioner");
				LCD_GoTo(1,0);
				//				_delay_ms(100);
				LCD_WriteString("is OFF          ");
			}
		}
	}// end of the main while(1)
}//end of main function

ISR (USART_RXC_vect)
{
	LCD_flag_off = 0;
	LCD_flag_on  = 0;
	cli();
	u8 data=Bluetooth_Receive();
	u8 data_to_print=0;
	if(data == 'U')
	{
		LCD_Clear();
		/********************************* Login as user **********************************************/
		pass_counter=0;
		LCD_WriteString("Log in as user");
		LCD_GoTo(1,0);
		LCD_WriteString("User name:");
		data_to_print=Bluetooth_Receive();
		while(pass_counter<PASS_SIZE)
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while( data_to_print==NULL || data_to_print=='Q')
			{
				data_to_print=Bluetooth_Receive();
			}
				LCD_GoTo(1,11+pass_counter);
				LCD_WriteChar(data_to_print);
				if (pass_counter==PASS_SIZE-1)
				{
					_delay_ms(500);
				}
				pass_counter++;
			
		}
		pass_counter=0;
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("User pass:");
		LCD_GoTo(1,0);
		while (pass_counter<PASS_SIZE )//loop till the user finish inserting the pass
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while(data_to_print==NULL || data_to_print=='Q')
			{
				data_to_print=Bluetooth_Receive();
			}
				pass[pass_counter]=data_to_print;//add the entered character to the pass array
				LCD_WriteChar(data_to_print);//print the entered character
				_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
				LCD_GoTo(1,0+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
				LCD_WriteChar(PASSWORD_SYMBOL); // to display (Password sign *)
				_delay_ms(100);//Halt the system for the given time in (ms)
				pass_counter++;//increase the characters count
		}
		_delay_ms(500);
		LCD_Clear();
	}
	/************************************** Door *****************************************************************/
	if(data=='D')
	{
		LCD_Clear();
		LCD_WriteString("Door Control:");
		LCD_GoTo(1,0);
		_delay_ms(100);
		LCD_WriteString("Open		Close");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='F')
	{
		LCD_Clear();
		DOOR_Open();
		LCD_WriteString("Door is opened");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='G')
	{
		LCD_Clear();
		DOOR_Close();
		LCD_WriteString("Door is Closed");
		_delay_ms(500);
		LCD_Clear();
	}
	/************************************** Light *****************************************************************/
	if(data=='L')
	{
		LCD_Clear();
		LCD_WriteString("Light Control:");
		LCD_GoTo(1,0);
		LCD_WriteString("ON		OFF");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='C')
	{
		LCD_Clear();
		DIO_TogglePin(LED1_PIN);
		LCD_WriteString("LED1 is Toggled");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='V')
	{
		LCD_Clear();
		DIO_TogglePin(LED2_PIN);
		LCD_WriteString("LED2 is Toggled");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='B')
	{
		LCD_Clear();
		DIO_TogglePin(LED3_PIN);
		LCD_WriteString("LED3 is Toggled");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='N')
	{
		LCD_Clear();
		DIO_TogglePin(LED4_PIN);
		LCD_WriteString("LED4 is Toggled");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='M')
	{
		LCD_Clear();
		DIO_TogglePin(LED5_PIN);
		LCD_WriteString("LED5 is Toggled");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='Z')
	{
		LCD_Clear();
		AC_Lamp_On();
		LCD_WriteString("AC Lamp On");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='X')
	{
		LCD_Clear();
		AC_Lamp_Off();
		LCD_WriteString("AC Lamp OFF");
		_delay_ms(500);
		LCD_Clear();
	}
	/************************************** Log out *****************************************************************/
	if(data=='H')
	{
		main();
	}
	/************************************** Log in failed 3 times *****************************************************************/
	if(data=='J')
	{
		Buzzer_TurnOn();
		LCD_Clear();
		LCD_WriteString("Restart");
		LCD_GoTo(1,0);
		LCD_WriteString("Required");
		while(1);
	}
	/************************************** User Control *****************************************************************/
	if(data=='E')
	{
		LCD_Clear();
		LCD_WriteString("Add , Edit ");
		LCD_GoTo(1,0);
		LCD_WriteString("OR Delete Users");
		_delay_ms(1000);
		LCD_Clear();
	}
	if(data=='%')
	{
		LCD_Clear();
		LCD_WriteString("User1 deleted! ");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='@')
	{
		LCD_Clear();
		LCD_WriteString("User2 deleted! ");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='*')
	{
		LCD_Clear();
		LCD_WriteString("User3 deleted! ");
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='I')
	{
		LCD_Clear();
		pass_counter=0;
		LCD_WriteString("User1 name:");
		LCD_GoTo(1,0);
		data_to_print=Bluetooth_Receive();
		while(pass_counter<PASS_SIZE)
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while( data_to_print==NULL || data_to_print=='Q')
			{
				data_to_print=Bluetooth_Receive();
			}
				LCD_WriteChar(data_to_print);
				if (pass_counter==PASS_SIZE-1)
				{
					_delay_ms(500);
				}
			pass_counter++;
			
		}
		pass_counter=0;
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("User1 pass:");
		LCD_GoTo(1,0);
		while (pass_counter<PASS_SIZE )//loop till the user finish inserting the pass
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while(data_to_print==NULL || data_to_print=='Q' )
			{
				data_to_print=Bluetooth_Receive();
			}
				pass[pass_counter]=data_to_print;//add the entered character to the pass array
				LCD_WriteChar(data_to_print);//print the entered character
				_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
				LCD_GoTo(1,0+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
				LCD_WriteChar(PASSWORD_SYMBOL); // to display (Password sign *)
				_delay_ms(100);//Halt the system for the given time in (ms)
				pass_counter++;//increase the characters count
		}
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='O')
	{
		LCD_Clear();
		pass_counter=0;
		LCD_WriteString("User2 name:");
		LCD_GoTo(1,0);
		data_to_print=Bluetooth_Receive();
		while(pass_counter<PASS_SIZE)
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while( data_to_print==NULL || data_to_print=='Q')
			{
				data_to_print=Bluetooth_Receive();
			}
			LCD_WriteChar(data_to_print);
			if (pass_counter==PASS_SIZE-1)
			{
				_delay_ms(500);
			}
			pass_counter++;
			
		}
		pass_counter=0;
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("User2 pass:");
		LCD_GoTo(1,0);
		while (pass_counter<PASS_SIZE )//loop till the user finish inserting the pass
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while(data_to_print==NULL || data_to_print=='Q' )
			{
				data_to_print=Bluetooth_Receive();
			}
			pass[pass_counter]=data_to_print;//add the entered character to the pass array
			LCD_WriteChar(data_to_print);//print the entered character
			_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
			LCD_GoTo(1,0+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
			LCD_WriteChar(PASSWORD_SYMBOL); // to display (Password sign *)
			_delay_ms(100);//Halt the system for the given time in (ms)
			pass_counter++;//increase the characters count
		}
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='P')
	{
		LCD_Clear();
		pass_counter=0;
		LCD_WriteString("User3 name:");
		LCD_GoTo(1,0);
		data_to_print=Bluetooth_Receive();
		while(pass_counter<PASS_SIZE)
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while( data_to_print==NULL || data_to_print=='Q')
			{
				data_to_print=Bluetooth_Receive();
			}
			LCD_WriteChar(data_to_print);
			if (pass_counter==PASS_SIZE-1)
			{
				_delay_ms(500);
			}
			pass_counter++;
			
		}
		pass_counter=0;
		LCD_Clear();
		LCD_GoTo(0,0);
		LCD_WriteString("User3 pass:");
		LCD_GoTo(1,0);
		while (pass_counter<PASS_SIZE )//loop till the user finish inserting the pass
		{
			data_to_print=0;
			data_to_print=Bluetooth_Receive();
			while(data_to_print==NULL || data_to_print=='Q' )
			{
				data_to_print=Bluetooth_Receive();
			}
			pass[pass_counter]=data_to_print;//add the entered character to the pass array
			LCD_WriteChar(data_to_print);//print the entered character
			_delay_ms(CHARACTER_PREVIEW_TIME);//Halt the system for the given time in (ms)
			LCD_GoTo(1,0+pass_counter);//move the lcd cursor to the previous location to write the password symbol over the character
			LCD_WriteChar(PASSWORD_SYMBOL); // to display (Password sign *)
			_delay_ms(100);//Halt the system for the given time in (ms)
			pass_counter++;//increase the characters count
		}
		_delay_ms(500);
		LCD_Clear();
	}
	if(data=='K')
	{
		Keypad_allowed=TRUE;
		KEYPAD_Control(Keypad_allowed);
	}
	sei();
}
