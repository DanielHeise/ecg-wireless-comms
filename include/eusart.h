/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-10  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     eusart.h only for: routers and end devices  	 *****/
/*****     						 						 *****/
/*************************************************************/
/*************************************************************/


/****************************************/
/************ EUSART Settings ***********/
/****************************************/

#define BAUD_RATE 	9600L				// Intended for Baud Rate calculation
										// done in EUSART.c
#define EIGHT_BIT		0				// Config for TX9, RX9 and BRG16
#define NINE_BIT		1				// Config for TX9 and RX9
#define SIXTEEN_BIT		1				// Config for BRG16
#define ASYNCHRONOUS	0				// Config for SYNC
#define SYNCHRONOUS		1				// Config for SYNC
#define LOW_SPEED		0				// Config for BRGH
#define HI_SPEED		1				// Config for BRGH

#define TX_MSG_SIZE		TX9				// 9-bit Transmit Enable bit
#define TRANSMITTER		TXEN			// Transmit Enable bit
#define EUSART_MODE		SYNC			// EUSART Mode Select bit
#define MODE_SPEED		BRGH			// High Baud Rate Select bit
#define SERIAL_PORT		SPEN			// Serial Port Enable bit
#define RX_MSG_SIZE		RX9				// 9-bit Receive Enable bit
#define CONSTANTLY_RX	CREN			// Continuou Receive Enable bit
#define BAUD_REG_SIZE	BRG16			// 16-bit Baud Rate Register Enable bit
#define BAUD_DETECTION	ABDEN			// Auto-Baud Detect Enable bit


/****************************************/
/************** Functions ***************/
/****************************************/

void init_eusart(void);


