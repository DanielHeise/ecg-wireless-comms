/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     port_io.c only for: routers, end devices  	 *****/
/*****     (requires port_io.h file) 					 *****/
/*************************************************************/
/*************************************************************/

#include <htc.h>
#include "main.h"
#include "port_io.h"

/***********************************/
/***** Initialize for Port I/O *****/
/***********************************/

void init_ports(void)
{	
	PORTB_FUNC = INPUT;					// Make all Port B inputs (pins 21-28)
	PORTC_FUNC = OUTPUT;				// Make all Port C outputs (pins 11-18)

	A2D_IO_CONFIG = DIGITAL;			// Make all A/D channels Digital (pins 2-5,7,21-25)

	RX_PIN = INPUT;						// Config RX pin as input; not used (pin 18)
	TX_PIN = OUTPUT;					// Config TX pin as output (pin 17)

	EXT_INT0 = INPUT;					// Config Ext Int0 as input (pin 21)

} // End init_ports