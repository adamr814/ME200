/*******************************************************************************
ENGR 200-??                                                     DATE: 02/02/2020

PROGRAM: A2                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION
This program will calculate the forces acting on a hot air balloon in flight
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define pi 3.14159

/* Main Function */
int main(void)
{
	/*declare variables */
	double fxg, fyg, buoy, grav, fxb, fyb, wind, fxw, fyw, fxt, fyt, ra, tw,
	       tg, tb, fto;
	
	/* Print main headings 8 */
	 printf("*****************************************************");
	 printf("\n           HOT AIR BALLOON FLIGHT FORCES\n\n");
	 
	 /* Enter variables */
	 printf("Enter the force due to wind in Newtons    : ");
	 scanf("%lf",&wind);
	 
	 printf("Enter the wind direction in degrees       : ");
	 scanf("%lf",&tw);
	 
	 printf("Enter the force due to gravity in Newtons : ");
	 scanf("%lf",&grav);
	 
	 printf("Enter the gravity direction in degrees    : ");
	 scanf("%lf",&tg);
	 
	 printf("Enter the force due to buoyancy in Newtons: ");
	 scanf("%lf",&buoy);
	 
	 printf("Enter the buoyancy direction in degrees   : ");
	 scanf("%lf",&tb);
	 
	 /* Computations */
	 fxg = grav*cos(tg*pi/180);
	 fyg = grav*sin(tg*pi/180);
	 fxb = buoy*cos(tb*pi/180);
	 fyb = buoy*sin(tb*pi/180);
	 fxw = wind*cos(tw*pi/180);
	 fyw = wind*sin(tw*pi/180);
	 fxt = fxg + fxb + fxw;
	 fyt = fyg + fyb + fyw;
	 ra = atan2(fyt,fxt);
	 fto = fxt + fyt*cos(ra);
	 
	 /* Print Results */
	 printf("\n\nRESULTS\n");
	 printf("Wind magnitude and direction     = %5.1f N and %5.1fø\n",wind, tw);
	 printf("Gravity magnitude and direction  = %5.1f N and %5.1fø\n",grav, tg);
	 printf("Buoyancy magnitude and direction = %5.1f N and %5.1fø\n\n",buoy, tb);
	 printf("COMPUTED FORCES\n");
	 printf("   Horizontal     Vertical\n");
	 printf("       (N)           (N)\n");
	 printf("      %5.2f        %6.2f <----- print wind forces first\n",fxw, fyw);
	 printf("      %5.2f       %6.2f <----- print gravity forces second\n",fxg, fyg);
	 printf("      %5.2f        %6.2f <----- print buoyancy forces third\n\n",fxb, fyb);
	 printf("Computed resultant angle = %5.2fø\n",ra);
	 printf("Computed resultant force = %5.2f N\n\n",fto);
	 printf("******************************************************");
	 /* Exit Program */
     return(0); 
	 
}
