/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-10  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     eusart.c only for: routers and end devices  	 *****/
/*****     (requires eusart.h file)						 *****/
/*************************************************************/
/*************************************************************/

#include <htc.h>
#include "main.h"
#include "eusart.h"
#include "clock.h"				// Required for FOSC #define

/****************************************/
/******** Initialize for EUSART *********/
/****************************************/

void init_eusart(void)
{	
	unsigned int baudsettings = 0;

	MODE_SPEED = HI_SPEED;					// Utilize faster baud rates
	BAUD_REG_SIZE = SIXTEEN_BIT;			// 16-bit generator register = more accurate rates

	/*******************************************/
	/* Setup the the Baud Rate Generator Speed */
	/*******************************************/

	if(BAUD_REG_SIZE == EIGHT_BIT && MODE_SPEED == LOW_SPEED)
	{
		baudsettings = ((FOSC/BAUD_RATE/64UL) - 1);			// 8-bit,Asynchronous,Slow
	}
	else if(BAUD_REG_SIZE == EIGHT_BIT && MODE_SPEED == HI_SPEED ||
			BAUD_REG_SIZE == SIXTEEN_BIT && MODE_SPEED == LOW_SPEED)
	{
		baudsettings = ((FOSC/BAUD_RATE/16UL) - 1);			// 8-bit,Asynchronous,Fast or 16-bit,Asynchronous,Slow
	}
	else if(BAUD_REG_SIZE == SIXTEEN_BIT && MODE_SPEED == HI_SPEED)
	{
		baudsettings = ((FOSC/BAUD_RATE/4UL) - 1);			// 16-bit,Asynchronous,Fast
	}		
	/* Assigning calculated Baud Rate */
	SPBRG = baudsettings & 0x00FF;					// Low Byte of Baud Rate Generator Register
	SPBRGH = (baudsettings >> 8) & 0x00FF;			// High Byte of Baud Rate Generator Register

	TX_MSG_SIZE = EIGHT_BIT;						// 8-bit transmissions
	RX_MSG_SIZE = EIGHT_BIT;						// 8-bit receptions

	TRANSMITTER = ENABLED;							// Turn transmitter ON
	SERIAL_PORT = ENABLED;							// Turn Serial Communications ON
	EUSART_MODE = ASYNCHRONOUS;						// Asynchronous communications
	BAUD_DETECTION = DISABLED;						// Do NOT auto-detect baud rate

	/*************************************************************/
	/* Setup Receiver according to the EUSART mode configuration */
	/*************************************************************/

	if(EUSART_MODE != ASYNCHRONOUS)
	{
		CONSTANTLY_RX = DISABLED;			// DON'T always look for data
	}
	else
		CONSTANTLY_RX = ENABLED;			// Always look for data


} // End init_eusart