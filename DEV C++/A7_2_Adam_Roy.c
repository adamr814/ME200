/*******************************************************************************
ENGR 200-2                                                      DATE: 03/31/2020

PROGRAM: A7                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION:
This program will using only procedures demonstrated in the recorded lecture and in the demo program
dealing with array of structures, write a program in C using an array of structures that will read
planet data from the input file (planet_data) , compute the distance to the horizon from the
highest mountain, and compute the distance an object will free fall after a specified, time
and pring a report to the computer screen and to an output file (planet_report).

DESCRIPTION OF VARIABLES:
NAME         | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
diameter     | int    | Diameter of the planet given
peak         | int    | The highest point on the planet
horizon      | int    | The calculated distance to the horizon from the peak
planets      | struct | The array structure created
i            | int    | The control number
nrows        | int    | The number of rows from the input file
time         | int    | The given value for time
ffall        | int    | The calculated time it takes to fall due to gravity and height
pname        | char   | The name of the planets from the input file
mountname    | char   | The name of highest point on the planet
grav         | double | The value of gravity for each planet
planet_data  | FILE   | The input file
planet_report| FILE   | The output file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\planet_data.txt"
#define outputfile "u:\\engr 200\\planet_report.txt"

/* Define structure for plenet data */
struct planets
{
	int diameter, peak, horizon, ffall;
	char pname[8], mountname[15];
	double grav;
};

/* Main function */
int main(void)
{
	/* Declare variables */
	struct planets pl[10];
	int i, nrows, time=50;
	FILE *planetdata;
	FILE *planetreport;
	
	/* Open input and output files */
	planetdata = fopen(inputfile,"r");
	planetreport = fopen(outputfile,"w");
	
	/* Verify input file */
	if(planetdata == NULL)
	{
		printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
		return 0;
	}
	
	/* Read control number */
	fscanf(planetdata,"%i",&nrows);
	
	/* Read planet data into array */
	for(i=0; i<=nrows-1; i++)
	{
		fscanf(planetdata,"%s %lf %i %s %i",&pl[i].pname,&pl[i].grav,
		&pl[i].diameter,&pl[i].mountname,&pl[i].peak);
	}
	
	/* Calculate distance to horizon */
	for(i=0; i<=nrows-1; i++)
	{
		pl[i].horizon = (sqrt(pow(pl[i].peak,2)+2*(pl[i].diameter/2)*pl[i].peak));
	}
	
	/* Calculate free fall */
	for(i=0; i<=nrows-1; i++)
	{
		pl[i].ffall = 0.5*pl[i].grav*pow(time,2);
	}
	
	/* Print main heading and column headings */
	printf("\n**************************************************************************"
	       "\n                              PLANET DATA");
	printf("\n\nPlanet    Gravity   Diameter      Mountain       Peak   Horizon  Free Fall"
           "\n           m/s^2       km                          m       km        m");
    fprintf(planetreport,"\n**************************************************************************"
	       "\n                              PLANET DATA");
	fprintf(planetreport,"\n\nPlanet    Gravity   Diameter      Mountain       Peak   Horizon  Free Fall"
           "\n           m/s^2       km                          m       km        m");
    
	/* Print array */
	for(i=0; i<=nrows-1; i++)
	{
		printf("\n%-8s   %2.2f      %6i    %-15s   %5i     %3i      %5i",pl[i].pname,pl[i].grav,
		pl[i].diameter,pl[i].mountname,pl[i].peak,pl[i].horizon,pl[i].ffall);
		fprintf(planetreport,"\n%-8s   %2.2f      %6i    %-15s   %5i     %3i      %5i",pl[i].pname,pl[i].grav,
		pl[i].diameter,pl[i].mountname,pl[i].peak,pl[i].horizon,pl[i].ffall);		
    }
	
	/* Print report end */
	printf("\n**************************************************************************");
	fprintf(planetreport,"\n**************************************************************************");
	
	/* Close input and output files */
	fclose(planetdata);
	fclose(planetreport);
	
	/* Exit program */
	return 0;
}
