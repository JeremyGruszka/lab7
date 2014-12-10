lab7
====

##Prelab

![alt text](https://raw.githubusercontent.com/JeremyGruszka/lab7/master/gradesheet.PNG "gradesheet")

####Things I may need to know for the lab

The MSP430 can only take in 3.3V so the IR sensor will read from 0 to 3.3V.  I will have to figure out what distances I want to read certain voltages and adjust my IR sensor voltage readouts accordingly.  I can use a cell phone camera to see if my IR sensor is working.  The ADC we will be using is a 10 bit converter, so my conversions will be done using this ratio:

```
Vin     X
---- = ----
3.3v   2^10
```

I will have 0V = 0x000 and 3.3V = 0x3FF.  I will figure out what distances I want to read what voltages once I get into the lab and get a look at the maze.

Here is a typical ADC configuration:

```
ADC10CTL1 = INCH_4 | ADC10DIV_3 ;			            // Channel 4, ADC10CLK/4
ADC10AE0 = BIT4; 					                        // Make P1.4 an analog input
ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;	// Vcc & Vss as reference
```

I will have to do one of those for each of the three IR sensors. I'll have P1.3 go to the left, P1.4 go to the center, and P1.5 go to the right.

The prelab says I'm supposed to test my sensors with a DMM.  I'm not sure when I was supposed to have time to do that so I was not able to complete that task.

##Labwork

This lab was was way more difficult for me than it should have been.  I had the IR sensors working and reading right away.  All I had to do for that was to run Dr. Coulston's code.  The problem was that I could not get the lights to work for the life of me.  After hours of trying different things to get the lights to turn on, I decided out of frustration to put my wires straight into the MSP430.  Lo and behold, it worked.  Originally, I had plugged my IR sensor into the black rails conntected to the MSP430, but when I plugged them straight into the board it worked.  Thus, I was able to complete required functionality.  B functionality was very easy.  I merely had to split up my code into a header file, an implementation file, and a main file.  It took about 5 minutes tops.  The B functionality ended up being very useful in lab 8, as it served as my base code.  Here is a picture of my wiring:

![alt text](https://raw.githubusercontent.com/JeremyGruszka/lab7/master/lab7_8robot.jpg "robot")

I did not attempt A functionality.

Documentation: none
