/*******************************************************************************
ENGR 200-2                                                      DATE: 03/21/2020

PROGRAM: A6                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION:
This program will use two one dimensional arrays to calculate the heat index
in respect to relative humidity and temperature. The program will also determine
if the given heat index fits in different categories of danger as specified by
the NOAA

DESCRIPTION OF VARIABLES:
NAME       | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
heat_index | double | The calculated heat index value
humid      | double | one-dimensional array of humidity
heat       | double | one-dimensional array of temperatures
heattable  |  FILE  | output file containing results and levels of danger
temphumid  |  FILE  | input file containing lines of data temperatures and humidity
ndata      |  int   | number of record lines in the input file
i          |  int   | loop control variable
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "C:\\Users\\adamr\\Google Drive\\College Stuff\\ME 200\\sensor_data.txt"
#define outputfile "C:\\Users\\adamr\\Google Drive\\College Stuff\\ME 200\\sensor_report.txt"

int main (void)
{
	/* Declare and initialize variables */
	double temp[20][5];
	int i, j;
	FILE *sensor_data, *sensor_report;
	
	/* Open input/output files */
	sensor_data = fopen(inputfile,"r");
	Sensor_report = fopen(outputfile,"w");
	
	/* Verify input file */
	if(sensor_data == NULL)
	{
		printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
	}
	
	 /* Read control number */
   fscanf(sensor_data,"%i %j",&i,%j);
   
   /* Read time and sensor values into arrays */
   for(i=0; i<=20-1; i++)
   {
        for(j=0; j<=5-1; j++)
        {
   		    fscanf(temphumid,"%lf %lf",&time[i][j],&sensor[i][j]);
   	    }
   }
   
   
   /* Calculate sensor averages */
   for(i=0; i<=20-1; i++)
   {
   	    for(j=0; j<=5-1; j++)
   }
   
   /* Print main headings and column headings */
   printf("***************************************************"
          "\n                  HEAT INDEX TABLE"
          "\n\nTemperature   Humidity   Heat Index    Danger"
		  "\n     øF           %%          øF        Level\n");
   fprintf(heattable,"***************************************************"
          "\n                  HEAT INDEX TABLE"
          "\n\nTemperature   Humidity   Heat Index    Danger"
          "\n     øF           %%          øF        Level\n");
          
   /* Print table */
   for(i=0; i<=ndata-1; i++)
   {
   		printf("\n    %3.0f          %2.0f         %3.0f     "
		   ,heat[i],humid[i],heat_index[i]);
		fprintf(heattable,"\n    %3.0f          %2.0f         %3.0f     "
		   ,heat[i],humid[i],heat_index[i]);
		   	   
	if(heat_index[i] <= 90.0)
   {
    printf("Caution");
    fprintf(heattable,"Caution");
   }
   else if(heat_index[i] > 90.0 && heat_index[i] <= 103.0)
   {
	printf("Extreme Caution");
	fprintf(heattable,"Extreme Caution");
   }
   else if(heat_index[i] > 103.0 && heat_index[i] <= 124.0)
   {
	printf("Danger");
	fprintf(heattable,"Danger");
   }
   else if(heat_index[i] > 124.0)
   {
    printf("Extreme Danger");
    fprintf(heattable,"Extreme Danger");
   }
   }
   
   /* Print report closing */
   printf("\n***************************************************");
   fprintf(heattable,"\n***************************************************");
   
   /* Close external files */
   fclose(temphumid);
   fclose(heattable);
   
   /* Exit program */
   return 0;   
   
}
