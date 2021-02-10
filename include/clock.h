/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-10  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     clock.h only for: routers and end devices  	 *****/
/*****     						 						 *****/
/*************************************************************/
/*************************************************************/


/****************************************/
/******* Clock/Oscillator Settings ******/
/****************************************/

#define SLEEP			0					// Config for IDLEN
#define IDLE			1					// Config for IDLEN
#define PRIMARY_OSC			0x00			// Use the "Primary Oscillator"
#define TIMER1_OSC			0x01			// Use Timer1 as the oscillator
#define INTERNAL_OSC_BLOCK	0x03			// Use the Internal Oscillator Block
#define OSC_8M		0x70					// Oscillator system clock frequency selections
#define OSC_4M		0x60					// ranging from 8MHz - 125KHz
#define OSC_2M		0x50					// Intended for setting appropriate bits within
#define OSC_1M		0x40					// the OSCCON register
#define OSC_500K	0x30
#define OSC_250K	0x20
#define OSC_125K	0x10
#define FOSC_8M		8000000L				// Oscillator system clock frequency selections 
#define FOSC_4M		4000000L				// ranging from 8MHz - 125KHz
#define FOSC_2M		2000000L				// Intended for assigning FOSC with an appropriate
#define FOSC_1M		1000000L				// value for the Baud Rate to be calculated; which
#define FOSC_500K	500000L					// is done in EUSART.c
#define FOSC_250K	250000L
#define FOSC_125K	125000L

#define DEVICE_ON_SLEEP		IDLEN			// Idle Enable bit
#define SYSTEM_CLK_SRC		OSCCON			// Oscillator register with System Clock Select bits
#define INT_OSC_FREQ		OSCCON			// Oscillator register with Internal Osc. Frequency Select bits
#define FOSC				FOSC_8M			// Assign the same equivalent value as system clock frequency; OSC

/****************************************/
/************** Functions ***************/
/****************************************/

void init_clock(void);


