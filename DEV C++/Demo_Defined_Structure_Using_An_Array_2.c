/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES USING AN array of structures.

PROGRAM DESCRIPTION:
This program will read hurricane data from an input file, average the hurricane
categories, determine the number of hurricanes that occurred in the Atlantic and
the number that occurred in the Gulf.  The hurricane data, the average category,
and the numbers of hurricanes by ocean are printed to the computer screen.

DESCRIPTION OF VARIABLES:
NAME      | TYPE   | DESCRIPTION
--------------------------------------------------------------------------------
hname     | char   | one-dimensional array containing a hurricane name
ocean     | char   | originating ocean
year      | int    | year the hurricane occurred
category  | int    | hurricane category
nrows     | int    | number of hurricanes in the input file
i         | int    | for loop control variable
avgcat    | int    | average of all hurricane categories
totalcat  | int    | total of all hurricane categories
atlantic  | int    | number of Atlantic hurricanes
gulf      | int    | number of Gulf hurricanes
hc        | struct | one-dimensional array of structures of hurricane data
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "C:\\Users\\adamr\\Google Drive\\College Stuff\\ME 200\\hurricanes.txt"

/* Define the structure for hurricane data */
struct hurricanes
{
	int year, category;
	char hname[9], ocean;
};

/* Main function */
int main(void)
{
   /* Declare variables */
   struct hurricanes hc[7];
   int i, nrows, totalcat=0, gulf=0, atlantic=0, avgcat;
   FILE *storms;

   /* Open input file */
   storms = fopen(inputfile,"r");
   
   /* Verify input file */
   if(storms == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(storms,"%i",&nrows);
      
   /* Read hurricane data into array */
   for(i=0; i<=nrows-1; i++)
   {
   	    fscanf(storms,"%s %i %i %c",&hc[i].hname,&hc[i].year,&hc[i].category,
		   &hc[i].ocean);
   }
      
   /* Sum hurricane categories */
   for(i=0; i<=nrows-1; i++)
   {
   	    totalcat = totalcat+hc[i].category;
   }
   
   /* Compute average hurricane category */ 
   avgcat = totalcat/nrows;

   /* Determine the number of storms in the Gulf and the number of
      storms in the Atlantic */
   for(i=0; i<=nrows-1; i++)
   {
   		if(hc[i].ocean == 'A')
   		{
   			atlantic++;
		}
		if(hc[i].ocean == 'G')
		{
			gulf++;
		}
   }

   /* Print main heading and column headings */
   printf("*****************************************"
          "\n             HURRICANE DATA");
   printf("\n\nHurricane     Year     Category     Ocean");
   
   /* Print array */
   for(i=0; i<=nrows-1; i++)
   {
   	printf("\n%-9s     %4i         %1i          %c",hc[i].hname, hc[i].year,
	   hc[i].category, hc[i].ocean);
   }
   
   /* Print average category and number of storms in Gulf and Atlantic */
   printf("\n\nSUMMARY");
   printf("\nAverage category = %1i",avgcat);
   printf("\nNumber of Gulf storms = %1i"
	      "\nNumber of Atlantic storms = %1i",gulf,atlantic);
	      
   /* Print report end */
   printf("\n*****************************************\n\n");

   /* Close input file */
   fclose(storms);

   /* Exit program */
   return 0;
}
/******************************************************************************/

























