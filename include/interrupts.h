/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-15-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     interrupts.h only for: routers, end devices 	 *****/
/*****      											 *****/
/*************************************************************/
/*************************************************************/


/****************************************/
/********** Interrupt Settings **********/
/****************************************/

#define FALLING 		0					// Config for INTEDG0
#define RISING			1					// Config for INTEDG0

#define EXT_INT0_EDGE		INTEDG0			// EXT INT0 Edge Select bit
#define EXT_INT0			INT0IE			// EXT INT0 Enable bit
#define INT_PRIORITY		IPEN			// INT Priority Enable bit
#define PERIPHERAL_INTS		PEIE			// Peripheral Int. Enable bit
#define GLOBAL_INTS			GIE				// Global Int. Enable bit
#define EXT_INT0_FLAG		INT0IF			// EXT INT0 Flag bit
#define TX_INTERRUPT		TXIE			// EUSART Transmit Interrupt Enable bit


/****************************************/
/************** Functions ***************/
/****************************************/

void init_ints(void);