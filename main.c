//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include <msp430g2553.h>
#include "lab7h.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void)
{

	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0 | BIT6;										//set LEDs as outputs

	while(1)
	{
		readLeft();
		readCenter();
		readRight();
	} // end infinite loop

} // end main


