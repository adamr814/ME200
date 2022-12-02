/*******************************************************************************
DEMO: DEVELOPING A "C" PROGRAM

PROGRAM DESCRIPTION:
This program will calculate the wind chill temperature and frostbite time values
after assigning air temperature in degrees Fahrenheit and wind speed in miles
per hour.  The results are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME  | TYPE   | DESCRIPTION                                
--------------------------------------------------------------------------------
temp  | double | air temperature in degrees Fahrenheit
speed | double | wind speed in miles per hour
chill | double | computed wind chill temperature in degrees Fahrenheit
fbite | double | computed frostbite time in minutes
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare variables */
   double temp=0.0, speed=15.0, chill, fbite;

   /* Calculate wind chill temperature and frostbite time */
   chill = 35.74 + 0.6215*temp-35.75*pow(speed,0.16) +
		0.4275*temp*pow(speed,0.16);
   fbite = (-24.5*(0.667*speed*(8.0/5.0)+4.8)+2111.0)*pow((-4.8-temp-32.0)*(5.0/9.0)),-1.668);           
   /* Print air temperature, wind speed, wind chill, and frostbite time */
	printf("%5.1f   %4.1f   %5.1f   %4.1f",temp,speed,chill,fbite);
   
   /* Exit program */
   return 0;
}
/******************************************************************************/














