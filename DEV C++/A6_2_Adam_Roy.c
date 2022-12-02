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
NAME         | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
sdata        | double | Sensor Data from input file
savg         | double | Averages from sensor data
sumsensor    | double | Sum of the values from each sensor
i            | int    | Control value for rows in the table
j            | int    | Control value for columns in the table
nrows        | int    | The number of rows in the table
ncols        | int    | The number of columns in the table
time         | char   | The time value from the input file
sensor_data  | FILE   | The input file
sensor_report| FILE   | The output file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "U:\\engr200\\sensor_data.txt"
#define outputfile "U:\\engr200\\sensor_report.txt"

int main (void)
{
	/* Declare and initialize variables */
	double sdata[20][5], savg[20][5], sumsensor=0;
	int i, j, nrows, ncols;
	char time[20][5];
	FILE *sensor_data, *sensor_report;
	
	/* Open input/output files */
	sensor_data = fopen(inputfile,"r");
	sensor_report = fopen(outputfile,"w");
	
	/* Verify input file */
	if(sensor_data == NULL)
	{
		printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
	}
	
	 /* Read control number */
   fscanf(sensor_data,"%i %i",&nrows, &ncols);
   
   /* Read time and sensor values into arrays */
   for(i=0; i<=nrows-1; i++)
   {
        for(j=0; j<=ncols-1; j++)
        {
   		    fscanf(sensor_data,"%lf",&sdata[i][j]);
   	    }
   }
   
   
   /* Calculate sensor averages */
   for(j=0; j<=ncols-1; j++)
   {
   	    for(i=0; j<=nrows-1; i++)
   	    {
   	    sumsensor = sumsensor + sdata[i][j];
		}
		savg[i][j]=sumsensor/nrows;
   }
   
   /* Print main headings and column headings */
   printf("**************************************************************************"
          "\n                  TEMPERATURE SENSOR DATA & ANALYSIS"
          "\n                                 (øF)"
          "\n\n  Time     Sensor 1   Sensor 2   Sensor 3   Sensor 4   Sensor 5   Averages"
		  "\n\n                             Sensor Averages");
   fprintf(sensor_report,"**************************************************************************"
          "\n                  TEMPERATURE SENSOR DATA & ANALYSIS"
          "\n                                 (øF)"
          "\n\n  Time     Sensor 1   Sensor 2   Sensor 3   Sensor 4   Sensor 5   Averages"
		  "\n\n                             Sensor Averages");
          
   /* Print table */
   for(i=0; i<=nrows-1; i++)
   {
   		printf("\n%s",time[i]);
   		for(j=0; j<=ncols-1; j++)
   		{
   			printf("%7.4f     \n",sdata[i][j]);
   			
		   }
		   printf("&7.4f", savg[i][j]);
	}
	for(i=0; i<=nrows-1; i++)
   {
   		fprintf(sensor_report,"\n%s",time[i]);
   		for(j=0; j<=ncols-1; j++)
   		{
   			fprintf(sensor_report,"%7.4f     ",sdata[i][j]);
   			
		   }
		   fprintf(sensor_report,"&7.4f", savg[i][j]);
	}
   
   /* Print report closing */
   printf("\n***************************************************");
   fprintf(sensor_report,"\n***************************************************");
   
   /* Close external files */
   fclose(sensor_data);
   fclose(sensor_report);
   
   /* Exit program */
   return 0;   
   
}
