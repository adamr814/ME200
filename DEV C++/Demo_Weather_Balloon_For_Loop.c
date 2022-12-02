/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES THE "for" LOOP STRUCTURE

                        for(expression 1;expression 2;expression 3)
                        {
                           statements;
                        }

PROGRAM DESCRIPTION:
This program will compute the altitude and velocity of a weather balloon.  As
time varies from 1 hour to 24 hours in increments of 1 hour, a table of times,
altitudes, and velocities will be generated. The results are printed to the
computer screen.

DESCRIPTION OF VARIABLES:
NAME     | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
time     | double | loop control variable
altitude | double | balloon height in meters
velocity | double | balloon speed in meters/hour
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare variables */
   double altitude,velocity, time;
   
   /* Print main headings */
   printf("**********************************"
          "\n   WEATHER BALLOON CALCULATIONS\n\n"
          "   TIME    ALTITUDE    VELOCITY\n"
          "  (hours)  (meters)     (m/hr)");
             
   /* Compute and print time, altitude, and velocity values */
   for(time=1.0; time<=24.0; time++)
   {
      altitude = -0.12*pow(time,4) + 12.0*pow(time,3) - 380.0*pow(time,2) +
	             4100.0*time + 220.0;
      velocity = -0.48*pow(time,3) + 36.0*pow(time,2) - 760.0*time + 4100.0;
      printf("\n    %2.0f      %5.0f      %5.0f",time,altitude,velocity);
   }
   printf("\n**********************************\n\n");
   
   /* Exit program */
   return 0;
}
/******************************************************************************/
