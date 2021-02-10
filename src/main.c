/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-23-10  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     main.c for all nodes: routers, end devices 	 *****/
/*****     and coordinators								 *****/
/*************************************************************/
/*************************************************************/

#include <18f2520.h>
#include <htc.h>
#include <stdio.h>
#include "main.h"
#include "clock.h"
#include "adc.h"
#include "port_io.h"
#include "timers.h"
#include "interrupts.h"
#include "eusart.h"


unsigned int old_time = 0;			// Buffer to hold last pulse time
unsigned int new_time = 0;			// Buffer to hold current pulse time
unsigned int new_time_buff = 0;		// Buffer to hold current pulse time
unsigned int time_btw_pulses = 0;	// Buffer to hold pulse difference
unsigned int heart_rate = 0;		// Buffer to hold pulse difference
unsigned char tmr_buff_low;			// Buffer to hold low byte of Timer0
unsigned int tmr_buff_hi;			// Buffer to hold high byte of Timer0
int tx_low_byte, tx_hi_byte;		// Buffers to hold pulse difference to be TX'ed
char go_flag = 0;					// Tells micro when it can and can't send data

#ifdef DEBUG_CODE
int stored_heart_rates[100] = 0;	// DEBUG USE ONLY!!!!!
int i; 								// DEBUG USE ONLY!!!!!
#endif


void main(void)
{
	init_clock();			// setup the Clock/Oscillator; clock.c
	init_adc();				// setup the ADC; adc.c
	init_ports();			// setup the Port I/O; port_io.c
	init_timers();			// setup the Timer(s); timers.c
	init_ints();			// setup the Interrupt(s); interrupts.c
	init_eusart();			// setup the EUSART; eusart.c

/****************************************/
/************** Main Loop ***************/
/****************************************/

	while(1)						// Wait here for External Interrupt 0
	{
		while(!go_flag);			// Stay here until you get the "go-ahead" to send data
		TXREG = tx_hi_byte;			// Transmit High Byte of heart rate
		while(!TXIF);
		TXREG = tx_low_byte;		// Transmit Low Byte of heart rate
		while(!TXIF);
		go_flag = 0;				// Give the "NO-GO" to send data	

	} // End while

} // End main




/*********************************************/
/**** Interrupt Service Routine Main Loop ****/
/*********************************************/

void interrupt isr(void)		// Interrupt Service Routine
{
	if(EXT_INT0_FLAG)			// Did an external interrupt(0) occur?
	{
		tmr_buff_low = TMR0_LOWER_BYTE;						// TMR0 Lower Byte
		tmr_buff_hi = TMR0_UPPER_BYTE << 8;					// TMR0 Upper Byte
		new_time_buff = (tmr_buff_low + tmr_buff_hi);		// Calculate TMR0 time
		time_btw_pulses = (new_time_buff - old_time);		// Calculate time between pulses

		RC3 ^= 1;											// External Interrupt intervals (pin 14)

		if(time_btw_pulses >= 0x127E && time_btw_pulses <= 0x2DC6)
		{	
			new_time = new_time_buff;						// Calculate TMR0 time
			heart_rate = time_btw_pulses;					// Calculate time between pulses

			tx_low_byte = heart_rate & 0x00FF;				// Low byte of measured heart rate to send
			tx_hi_byte = (heart_rate >> 8) & 0x00FF;		// High byte of measured heart rate to send
			go_flag = 1;									// Give the "GO" to send data
			old_time = new_time;							// Update the "old time" for next pulse comparison

			/*-------------------------*/	
			/* DEBUG USE ONLY -- START */
			/*-------------------------*/
			#ifdef DEBUG_CODE
			//-----------------------------------------------------
					stored_heart_rates[i] = heart_rate;		// Trace predefined # of heart rates
					if(i >= 99)
					{
						i = 0;
					}
					else 
						i++;

					RC2 ^= 1;								// TX intervals (pin 13)
			//-----------------------------------------------------
			#endif // #ifdef DEBUG_CODE
			/*-------------------------*/
			/* DEBUG USE ONLY -- STOP  */
			/*-------------------------*/

		} // End if

	} // End if

	EXT_INT0_FLAG = CLEAR;						// Reset External Interrupt 0

} // End interrupt isr