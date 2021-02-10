/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-15-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     interrupts.c only for: routers, end devices 	 *****/
/*****     (requires interrupts.h file)					 *****/
/*************************************************************/
/*************************************************************/

#include <htc.h>
#include "main.h"
#include "interrupts.h"

/***********************************/
/**** Initialize for Interrupts ****/
/***********************************/

void init_ints(void)
{
	EXT_INT0_EDGE = FALLING;					// Trigger External Int0 on rising edge
	EXT_INT0 = ENABLED;							// Turn External Int0 ON
	INT_PRIORITY = ENABLED;						// Turn ON priority levels
	PERIPHERAL_INTS = ENABLED;					// Turn ON all low priority peripheral interrupts
	GLOBAL_INTS = ENABLED;						// Turn ON all high priority interrupts
	TX_INTERRUPT = DISABLED;					// Turn OFF transmitter interrupt

} // End init_ints