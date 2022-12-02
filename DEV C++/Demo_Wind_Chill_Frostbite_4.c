/*******************************************************************************
DEMO: DEVELOPING if and if/else STRUCTURES

PROGRAM DESCRIPTION:
This program will calculate the wind chill and frostbite values after entering
air temperature in degrees Fahrenheit and wind speed in miles per hour.  The
program will determine if the input values for air temperature and wind speed
are within limits.  If the input limits are out of range the program will stop
executing and print an error message.  Also, the program will determine danger
levels based on computed frostbite times.  The results are printed to the
computer screen.

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

   /* Print main heading */
   printf("**************************************************");
   printf("\n    WIND CHILL & FROSTBITE CALCULATION PROGRAM\n\n");

   /* Enter air temperature and wind speed */
   printf("Enter the air temperature in øF: ");
   scanf("%lf",&temp);
   printf("Enter the wind speed in mph    : ");
   scanf("%lf",&speed);
   
   /* Check for wind speed errors */
   if(speed < 3.0 || speed > 40.0)
   {
      printf("\n\nWIND SPEED ERROR OCCURRED"
             "\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Check for air temperature errors */
   if(temp < -50.0 || temp > 20.0)
   {
      printf("\n\nAIR TEMPERATURE ERROR OCCURRED"
             "\nPROGRAM TERMINATED\n\n");
      return 0;
   }
            
   /* Calculate wind chill and frostbite */
   chill = 35.74 + 0.6215*temp - 35.75*pow(speed,0.16) + 
           0.4275*temp*pow(speed,0.16);
   fbite = (-24.5*(0.667*speed*8.0/5.0+4.8)+2111.0)*
           pow((-4.8-(temp-32.0)*5.0/9.0),-1.668);

   /* Print output values */
   printf("\nRESULTS");
   printf("\nAir temperature = %5.1fø F\nWind speed      = %5.1f mph"
          "\nWind chill      = %5.1fø F\nFrostbite time  = %5.1f minutes",
		  temp,speed,chill,fbite);
 
   /* Determine and print danger levels */  
   if(fbite >= 120.0)
   {
    printf("\n\nThe frostbite danger is LOW");
   }
   else if(fbite >= 30.0 && fbite < 120.0)
   {
	printf("\n\nThe frostbite danger is MODERATE");
   }
   else if(fbite >= 10.0 && fbite < 30.0)
   {
	printf("\n\nThe frostbite danger is HAZARDOUS");
   }
   else if(fbite >= 6.0 && fbite < 10.0)
   {
    printf("\n\nThe frostbite danger is SEVERE");
   }
   else if(fbite < 6.0)
   {
    printf("\n\nThe frostbite danger is DEADLY");
   }

   printf("\n**************************************************\n\n");

   /* Exit program */
   return 0;
}
/******************************************************************************/

















