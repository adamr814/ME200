/*******************************************************************************
ENGR 200-2                                                      DATE: 02/18/2020

PROGRAM: A3                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION
This program will calculate input and output files for a loop, if structure,
and a user-defined function
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\thermal.txt"
#define outputfile "u:\\engr 200\\thermalres.txt"

/* Main function */
int main(void)
{
	/* Declare variables */
	FILE *thermal;
	double temp, cond;
	int ndata, i;
	
	/* Open input file */
	thermal = fopen(inputfile, "r");
	thermalres = fopen(outputfile, "w");
	
	/* Verify input file */
	if(thermal == NULL)
	{
		printf("ERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
		return 0;
	}
	
	/* Read control number  */
	fscanf(thermal, "%i",&ndata);
	
	/* Print headings */
	printf("*******************************************\n");
	printf("    TEMPERATURE vs THERMAL CONDUCTIVITY\n\n");
	printf("Temp    Conduct    Temp Sqrd    Temp*Conduct\n");
	
	fprintf(thermalres,"*******************************************\n");
	fprintf(thermalres,"    TEMPERATURE vs THERMAL CONDUCTIVITY\n\n");
	fprintf(thermalres,"Temp    Conduct    Temp Sqrd    Temp*Conduct\n");
	
	/* Calculations */
	for
}
