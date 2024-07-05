#ifndef APP_LCFG_H_
#define APP_LCFG_H_

#include "StdTypes.h"

#define NOT_STORED   0xFF
#define NOT_SELECTED 0xFF

#define BLOCK_MODE_TIME		   (u32)20000
#define CHARACTER_PREVIEW_TIME (u16)300
#define DEGREES_SYMBOL		   (u8)0xDF

/*********************************** PIN Configuration ***********************************/
#define PASS_SIZE       (u8)5
#define TRIES_ALLOWED   (u8)3
#define PASSWORD_SYMBOL (u8)'*'
#define ASCII_ZERO      (u8)'0'

#define PASS_NOT_SET (u8)0xFF
#define PASS_SET     (u8)0x01

#define ADMIN_PASS_STATUS_ADDRESS (u16)0X100
#define EEPROM_ADMIN_ADDRESS      (u16)0X102
#define LOGIN_BLOCKED_ADDRESS     (u16)0X10A
/*****************************************************************************************/

/************************************   Login configurations *****************************/
#define NO_MODE (u8)0
#define ADMIN   (u8)1
/*****************************************************************************************/

/************************************   Logic values *************************************/
#define FALSE   (u8)0
#define TRUE    (u8)1
/*****************************************************************************************/

#define CHECK_ADMIN_MODE        (u8)'0'

#define SELECT_LED1            (u8)'1'
#define SELECT_LED2            (u8)'2'
#define SELECT_LED3            (u8)'3'
#define SELECT_LED4            (u8)'4'
#define SELECT_LED5            (u8)'5'

#define SELECT_DOOR               (u8)'2'
#define SELECT_AIR_CONDITIONING (u8)'3'


#define DEFAULT_ACK    0xFF
#define DEMAND_RESPONSE 0xFF

#define ON_STATUS   0x01
#define OFF_STATUS  0x00

#endif 