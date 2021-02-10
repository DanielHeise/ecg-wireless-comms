//*******************************************************
//pause - multiple millisecond delay routine
//*******************************************************
//#include <pic.h>		// Include HITECH CC header file
#include <htc.h>

void msecbase( void );				//Establish millisecond base function

void pause( unsigned short usvalue )

{
	unsigned short x;
	
	for (x=0; x<=usvalue; x++)	//Loop through a delay equal to usvalue
		{						// in milliseconds.
		msecbase();				//Jump to millisec delay routine
		}
}
