/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-16-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     timers.c only for: routers, end devices 	 	 *****/
/*****     (requires timers.h file) 					 *****/
/*************************************************************/
/*************************************************************/

#include <htc.h>
#include "main.h"
#include "timers.h"
#include "interrupts.h"				// Required for RISING/FALLING #defines

/***********************************/
/****** Initialize for Timers ******/
/***********************************/

void init_timers(void)
{
	unsigned char tmr0_prescaler_buff, tmr0_prescaler_value;

	TIMER0 = ENABLED;							// Turn Timer0 ON
	TIMER0_SIZE = SIXTEEN_BIT;					// Configure as a 16-bit register
	TMR0_CLK_SRC = INTERNAL;					// Use internal CLK0
	TIMER0_EDGE = RISING;						// Trigger on the Rising edge
	TMR0_PRESCALER_USE = YES;					// Use a prescaler
	tmr0_prescaler_value = PRE_256;				// [8MHz/4] => [1/2MHz] => [0.5us * 256] => 0.128 msec/clk pulse
												// Timer0 will run for 8.388 seconds before overflowing
	if(TMR0_PRESCALER_USE == YES)
	{
		tmr0_prescaler_buff = TMR0_PRESCALER & 0xF8;							// Mask off appropriate bits for munipulation
		tmr0_prescaler_buff = tmr0_prescaler_buff | tmr0_prescaler_value;		// Assign Prescaler selection to unmasked bits
		TMR0_PRESCALER = tmr0_prescaler_buff;									// Reload the new value into T0CON register
	}

} // End init_timers