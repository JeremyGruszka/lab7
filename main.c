//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
#include "msp430g2553.h"

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

		// Configure P1.4 to read center IR
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_4 | ADC10DIV_3 ;						// Channel 4, ADC10CLK/4
		ADC10AE0 = BIT4;		 								// Make P1.4 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		if (ADC10MEM > 0x0200)	P1OUT |= BIT0 | BIT6;
		else					P1OUT &= ~BIT0 & ~BIT6;

		//configure p1.3 to read left IR
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_3 | ADC10DIV_3 ;						// Channel 3, ADC10CLK/4
		ADC10AE0 = BIT3;		 								// Make P1.3 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		if (ADC10MEM > 0x0200)
		{
			P1OUT |= BIT0;
		}
		else					P1OUT &= ~BIT0;

		//configure p1.5 to read right IR
		ADC10CTL0 = 0;											// Turn off ADC subsystem
		ADC10CTL1 = INCH_5 | ADC10DIV_3 ;						// Channel 5, ADC10CLK/4
		ADC10AE0 = BIT5;		 								// Make P1.5 analog input
		ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;		// Vcc & Vss as reference

		ADC10CTL0 |= ADC10SC;									// Start a conversion
		while(ADC10CTL1 & ADC10BUSY);							// Wait for conversion to complete
		if (ADC10MEM > 0x0200)	P1OUT |= BIT6;
		else					P1OUT &= ~BIT6;

	} // end infinite loop

} // end main


