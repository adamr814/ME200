/*******************************************************************************
ENGR 200-??                                                     DATE: 01/27/2020

PROGRAM: A1                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION
This program will ...  

DESCRIPTION OF VARIABLES
NAME   | TYPE     | DESCRIPTION                                
--------------------------------------------------------------------------------
pi     | symbolic | mathematical constant

*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159
#define gravity 9.81

/* Main function */
int main(void)
{
   /* Declare variables */
	double velocity, angle, time, xt, yt, rt, theta;

   /* Print main headings */
	printf("**************************************************");
	printf("\n       ROCKET POSITION CALCULATIONS\n\n");

   /* Enter velocity, angle, and time */
	printf("Enter velocity in m/s : ");
	scanf("%lf",&velocity);
	printf("Enter angle in degrees: ");
	scanf("%lf",&angle);
	printf("Enter time in seconds : ");
	scanf("%lf",&time);
	
   /* Compute Cartesian and Polar coordinates */
   xt = velocity*cos(angle*pi/180.0)*time;
   yt = velocity*sin(angle*pi/180.0)*time - 0.5*gravity*pow(time,2);
   rt = sqrt(pow(xt,2) + pow(yt,2));
   theta = yt / xt;	
	

   /* Print results */
	printf("\n\nComputed Cartesian Coordinates");
	printf("\n          x(t)           y(t)");
	printf("\n          5.1f m",xt);
	printf("                           5.1f m",yt);
	printf("\n/nComputed Polar Coordinates");
	printf("\n          r(t)       theta(t)");
    printf("");  
   /* Exit program */
}
/******************************************************************************/
