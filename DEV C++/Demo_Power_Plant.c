/*******************************************************************************
DEMO: DEMONSTRATION OF ONE-DIMENSIONAL ARRAYS

PROGRAM DESCRIPTION:
This program will read power output for three power plants into three
one-dimensional arrays for an eight week period.  It will compute the average
power output for each week using a one-dimensional array to sum the power
outputs and a one-dimensional array to compute the weekly averages.  The
program will print a report to the computer screen and to an output file.

DESCRIPTION OF VARIABLES:
NAME     | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
avers    | double | one-dimensional array of power averages
plant1   | double | one-dimensional array of first power plant data
plant2   | double | one-dimensional array of second power plant data
plant3   | double | one-dimensional array of third power plant data
sumpower | double | one-dimensional array of summations of weekly power output
ndata    | int    | number of record lines in the input file
i        | int    | loop control variable
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\power_plant_data.txt"
#define outputfile "u:\\engr 200\\power_plant_report.txt"

int main(void)
{
   /* Declare and initialize variables */
   double plant1[8],plant2[8],plant3[8],sumpower[8]={0.0},avers[8];
   int i,ndata;
   FILE *power, *report;

   /* Open input/output files */
   power = fopen(inputfile,"r");
   report = fopen(outputfile,"w");

   /* Verify input file */
   if(power == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(power,"%i",&ndata);

   /* Read power values into arrays */
   for(i=0; i<=ndata-1; i++)
   {
   		fscanf(power,"%lf %lf %lf",&plant1[i],&plant2[i],&plant3[i]);
   }

   /* Sum power for 8 weeks */
   for(i=0; i<=ndata-1; i++)
   {
   	  sumpower[i] = sumpower[i]+plant1[i]+plant2[i]+plant3[i];
   }
    
   /* Compute average power output for 8 weeks */
   for(i=0;i<=ndata-1; i++)
   {
   	  avers[i] = sumpower[i]/3.0;
   }

   /* Print main headings and column headings */
   printf("***************************************"
          "\n       POWER OUTPUT IN MEGAWATTS"
          "\n\nPlant 1   Plant 2   Plant 3   Averages");
   fprintf(report,"***************************************"
          "\n       POWER OUTPUT IN MEGAWATTS"
          "\n\nPlant 1   Plant 2   Plant 3   Averages");
   
   /* Print table */ 
   for(i=0; i<=ndata-1; i++)
   {
   	  printf("\n  %3.0f       %3.0f       %3.0f       %5.1f"
		 ,plant1[i],plant2[i],plant3[i],avers[i]);
	  fprintf(report,"\n  %3.0f       %3.0f       %3.0f       %5.1f"
		 ,plant1[i],plant2[i],plant3[i],avers[i]);
   }
   
   /* Print report closing */
   printf("\n***************************************\n\n");
   fprintf(report,"\n***************************************\n\n");
   
   /* Close the input file */
   fclose(power);
   fclose(report);

   /* Exit program */
   return 0;
}
/******************************************************************************/
