
#ifndef MEMOMAP_H_
#define MEMOMAP_H_

/* DIO_Registers */
#define DDRA (*(volatile unsigned char*)0x3A)
#define DDRB (*(volatile unsigned char*)0x37)
#define DDRC (*(volatile unsigned char*)0x34)
#define DDRD (*(volatile unsigned char*)0x31)

#define PINA (*(const volatile unsigned char*)0x39)
#define PINAA (*(volatile unsigned char*)0x39)
#define PINB (*(volatile unsigned char*)0x36)
#define PINC (*(volatile unsigned char*)0x33)
#define PIND (*(volatile unsigned char*)0x30)

#define PORTA (*(volatile unsigned char*)0x3B)
#define PORTB (*(volatile unsigned char*)0x38)
#define PORTC (*(volatile unsigned char*)0x35)
#define PORTD (*(volatile unsigned char*)0x32)
/********************************************************************************************************/

/* ADC_Registers */
#define ADC_Output_Adj_Bit 5
#define ADMUX_REF1_Bit 7
#define ADMUX_REF0_Bit 6

#define ADCSRA_ADPS0_Bit 0
#define ADCSRA_ADPS1_Bit 1
#define ADCSRA_ADPS2_Bit 2
#define ADCSRA_ADIF_Bit 4
#define ADCSRA_ADSC_Bit 6
#define ADCSRA_Enable_Bit 7

# define ADMUX_Reg (*(volatile u8*) 0x27)
# define ADCSRA_Reg (*(volatile u8*) 0x26)
# define ADCH_Reg (*(volatile u8*) 0x25)
# define ADCL_Reg (*(volatile u8*) 0x24)
/********************************************************************************************************/

/*External Interrupt */
# define GICR_Reg_INT0 6
# define GICR_Reg_INT1 7
# define GICR_Reg_INT2 5
# define MCUCSR_Reg_SC 6

# define GICR_Reg (*(volatile u8*) 0x5B)
# define GIFR_Reg (*(volatile u8*) 0x5A)
# define MCUCR_Reg (*(volatile u8*) 0x55)
# define MCUCSR_Reg (*(volatile u8*) 0x54)
/************************************************************************************************/

/*Global Interrupt */
#define SREG_Enable_bit 7

# define SREG_Reg (*(volatile u8*) 0x5F)
/************************************************************************************************/

/*TIMER 1*/
#define  TCCR1A_WGM11 (1<<1)
#define  TCCR1A_COM1B1 (1<<5)
#define  TCCR1A_COM1A1 (1<<7)

#define  TCCR1B_CS10 (1<<0)
#define  TCCR1B_CS11 (1<<1)
#define  TCCR1B_WGM12 (1<<3)
#define  TCCR1B_WGM13 (1<<4)
#define WGM11   1
#define WGM13   4
#define WGM12   3
#define COM1A1  7
#define CS11    1
#define CS10    0

# define TCCR1A (*(volatile u8*) 0x4F)
# define TCCR1B (*(volatile u8*) 0x4E)
#define TCNT1   (*(volatile unsigned short*)0x4C)
# define TCNT1H (*(volatile u8*) 0x4D)
# define TCNT1L (*(volatile u8*) 0x4C)
# define OCR1AH_Reg (*(volatile u8*) 0x4B)
# define OCR1AL_Reg (*(volatile u8*) 0x4A)
#define ICR1   (*(volatile unsigned short*)0x46)
# define ICR1H (*(volatile u8*) 0x47)
# define ICR1L (*(volatile u8*) 0x46)
/******************************************************************************/

/*****************************UART Registers*******************************/
#define UDR (*(volatile u8 *)0x2C)
#define UCSRA (*(volatile u8 *)0x2B)
#define UCSRB (*(volatile u8 *)0x2A)
#define UCSRC (*(volatile u8 *)0x40)
#define UBRRL (*(volatile u8 *)0x29)
#define UBRRH (*(volatile u8 *)0x40)
#define U2X 1
#define TXEN 3
#define RXEN 4
/******************************************************************************/

/****************************** EEPROM Control Register ****************************/
#define EEPROM_ARH_REG				(*(volatile u8*)0x3F)
#define EEPROM_ARL_REG				(*(volatile u8*)0x3E)
#define EEPROM_DR_REG				(*(volatile u8*)0x3D)
#define EEPROM_CR_REG				(*(volatile u8*)0x3C)

#define EERE				(0u)
#define EEWE             	(1u)
#define EEMWE				(2u)
/******************************************************************************/
/* USART, Rx Complete */
#define UART_RX_vect			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect			__vector_15
#endif 