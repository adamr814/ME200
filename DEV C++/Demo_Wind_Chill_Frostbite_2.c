/*******************************************************************************
DEMO: DEVELOPING A "C" PROGRAM WITH INPUT/OUTPUT FUNCTIONS

PROGRAM DESCRIPTION:
This program will calculate the wind chill and frostbite values after entering
air temperature in degrees Fahrenheit and wind speed in miles per hour from the
keyboard.  The results are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME  | TYPE   | DESCRIPTION                                
--------------------------------------------------------------------------------
chill | double | computed wind chill temperature in degrees Fahrenheit
temp  | double | air temperature in degrees Fahrenheit
speed | double | wind speed in miles per hour
fbite | double | computed frostbite time in minutes
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>

/* Main function */
int main(void)
{
   /* Declare variables */
   double chill, speed, temp, fbite;

   /* Print main headings */
   printf("**************************************************");
   printf("\n    WIND CHILL & FROSTBITE CALCULATION PROGRAM\n\n");

   /* Enter air temperature and wind speed */
   printf("Enter the air temperature (degrees F): ");
   scanf("%lf",&temp);
   printf("Enter the wind speed (mph)           : ");
   scanf("%lf",&speed);
   
   /* Calculate wind chill and frostbite */
   chill = 35.74 + 0.6215*temp - 35.75*pow(speed,0.16) + 0.4275*temp*
           pow(speed,0.16);
   fbite = (-24.5*(0.667*speed*8.0/5.0+4.8)+2111.0)*
           pow(-4.8-(temp-32.0)*5.0/9.0,-1.668);
           
   /* Print output values */
   printf("\nRESULTS");
   printf("\nAir temperature = %5.1f degrees F",temp);
   printf("\nWind speed      = %5.1f mph",speed);
   printf("\nWind Chill      = %5.1f degrees F",chill);
   printf("\nFrostbite time  = %5.1f minutes",fbite);
   printf("\n**************************************************\n\n");
   
   /* Exit program */
   return 0;
}
/******************************************************************************/
