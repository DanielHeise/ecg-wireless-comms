/*************************************************************/
/*************************************************************/
/***** 			Daniel Heise  1-18-11  EET496            *****/
/*****    		   "Wireless Sensor System"              *****/
/*****													 *****/
/*****     port_io.h only for: routers, end devices 	 *****/
/*****      											 *****/
/*************************************************************/
/*************************************************************/


/****************************************/
/********** Port I/O Settings ***********/
/****************************************/

#define OUTPUT	0
#define INPUT	1
#define ANALOG  0x00				// AN0-AN12 = Analog Inputs
#define DIGITAL 0x0F				// AN0-AN12 = Digital I/O

#define PORTA_FUNC		TRISA		// Port A I/O states (pins 2-7,9,10)
#define PORTB_FUNC		TRISB		// Port B I/O states (pins 21-28)
#define PORTC_FUNC		TRISC		// Port C I/O states (pins 11-18)

#define A2D_IO_CONFIG	ADCON1		// A/D channel configurations (pins 2-5,7,21-25)

#define RX_PIN 		TRISC7			// RX pin I/O state (pin 18)
#define TX_PIN 		TRISC6			// TX pin I/O state (pin 17)

#define EXT_INT0	TRISB0			// External Interrupt0 pin I/O state (pin 21)


/****************************************/
/************** Functions ***************/
/****************************************/

void init_ports(void);