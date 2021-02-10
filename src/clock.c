/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-10  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     clock.c only for: routers and end devices  	 *****/
/*****     (requires clock.h file)						 *****/
/*************************************************************/
/*************************************************************/

#include <htc.h>
#include "main.h"
#include "clock.h"

/****************************************/
/***** Initialize for System Clock ******/
/****************************************/

void init_clock(void)
{	
	unsigned char int_osc_freq_buff, int_osc_freq;			// Buffer variables for calculating the Internal
	unsigned char system_clk_src_buff, osc_src;				// Oscillator Freq. and the System Clock Source

	DEVICE_ON_SLEEP = IDLE;						// Device enters an Idle mode on SLEEP instruction
	int_osc_freq = OSC_8M;						// Set the Internal Oscillator Freq. to 8MHz
	osc_src = INTERNAL_OSC_BLOCK;				// Use the Internal Oscillator Block as the Oscillator Source

	/* Initilize the Internal Oscillator Frequency */
	int_osc_freq_buff = INT_OSC_FREQ & 0x8F;					// Mask off appropriate bits for munipulation
	int_osc_freq_buff = int_osc_freq_buff | int_osc_freq;		// Assign Freq. selection to unmasked bits
	INT_OSC_FREQ = int_osc_freq_buff;							// Reload the new value into OSCCON register

	/* Initilize the System Clock Source */
	system_clk_src_buff = SYSTEM_CLK_SRC & 0xFC;				// Mask off appropriate bits for munipulation 
	system_clk_src_buff = system_clk_src_buff | osc_src;		// Assign Source selection to unmasked bits
	SYSTEM_CLK_SRC = system_clk_src_buff;						// Reload the new value into OSCCON register

} // End init_clock