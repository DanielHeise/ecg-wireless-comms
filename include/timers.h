/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-16-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     timers.h only for: routers, end devices 	 	 *****/
/*****      											 *****/
/*************************************************************/
/*************************************************************/


/********************************/
/******** Timer Settings ********/
/********************************/

#define SIXTEEN_BIT		0					// Timer/Counter register size
#define EIGHT_BIT		1
#define INTERNAL		0					// Clock source selection
#define EXTERNAL		1
#define YES				0
#define NO				1
#define PRE_256			0x07				// Prescaler Values:
#define PRE_128			0x06				// ratios of Clock Source
#define PRE_64			0x05	
#define PRE_32			0x04
#define PRE_16			0x03
#define PRE_8			0x02
#define PRE_4			0x01
#define PRE_2			0x00

#define TIMER0					TMR0ON			// Timer0 On/Off Control bit
#define TIMER0_SIZE				T08BIT			// Timer0 8-Bit/16-Bit Control bit
#define TMR0_CLK_SRC			T0CS			// Timer0 Clock Source Select bit
#define TIMER0_EDGE				T0SE			// Timer0 Source Edge Select bit
#define TMR0_PRESCALER_USE		PSA				// Timer0 Prescaler Assignment bit
#define TMR0_PRESCALER			T0CON			// Timer0 register with Prescaler Select bits
#define TMR0_LOWER_BYTE			TMR0L			// Timer0 Lower byte of 16-bit register
#define TMR0_UPPER_BYTE			TMR0H			// Timer0 Upper byte of 16-bit register


/****************************************/
/************** Functions ***************/
/****************************************/

void init_timers(void);