lab7
====

##Prelab

![alt text](https://raw.githubusercontent.com/JeremyGruszka/lab7/master/gradesheet.PNG "gradesheet")

####Things I may need to know for the lab

The MSP430 can only take in 3.3V so the IR sensor will read from 0 to 3.3V.  I will have to figure out what distances I want to read certain voltages and adjust my IR sensor voltage readouts accordingly.  I can use a cell phone camera to see if my IR sensor is working.  The ADC we will be using is a 10 bit converter, so my conversions will be done using this ratio:

Vin     X
---- = ----
3.3v   2^10

Here is a typical ADC configuration:

ADC10CTL1 = INCH_4 | ADC10DIV_3 ;			            // Channel 4, ADC10CLK/4
ADC10AE0 = BIT4; 					                        // Make P1.4 an analog input
ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference

I will have to do one of those for each of the three IR sensors.

The prelab says I'm supposed to test my sensors with a DMM.  I'm not sure when I was supposed to have time to do that so I was not able to complete that task.
