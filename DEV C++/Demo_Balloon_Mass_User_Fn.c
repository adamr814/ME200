/*******************************************************************************
DEMO: THIS PROGRAM DEMONSTRATES A user-defined FUNCTION

PROGRAM DESCRIPTION:
This program will read pressure, volume, and temperature from an input file and
pass the values to a user-defined function. The user-defined function will
compute the mass of a balloon and pass the computed value back to the main
function.  The results are printed to the computer screen and to an output file.
         
DESCRIPTION OF VARIABLES:
NAME   | TYPE    | DESCRIPTION
--------------------------------------------------------------------------------
c_mass | double  | computed mass of the balloon
press  | double  | pressure inside the balloon in pounds/ft^3
temp   | double  | temperature inside the balloon in degrees
vol    | double  | volume of the balloon in ft^3
i      | integer | for loop control variable
ndata  | integer | number of data record lines in input file
*******************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "u:\\engr 200\\balloon.txt"
#define outputfile "u:\\engr 200\\balloon_table.txt"

/* Main function */
int main(void)
{
   /* Declare variables */
   double mass(double, double, double);
   double c_mass, press, vol, temp;
   int i, ndata;
   FILE *balloon, *table;

   /* Open input and output files */
   balloon = fopen(inputfile, "r");
   table = fopen(outputfile, "w");
   
   /* Verify input file */
   if(balloon == NULL)
   {
      printf("\n\nERROR OPENING INPUT FILE\n\nPROGRAM TERMINATED\n\n");
      return 0;
   }
   
   /* Read control number */
   fscanf(balloon,"%i",&ndata);
   
   /* Print headings */
   printf("************************************************");
   printf("\n             TABLE OF BALLOON MASSES"
          "\n\nBalloon   Pressure   Volume   Temperature   Mass");
   fprintf(table,"************************************************");
   fprintf(table,"\n             TABLE OF BALLOON MASSES"
           "\n\nBalloon   Pressure   Volume   Temperature   Mass");

   /* Read values, call function, count zeros, and print table */
   for(i=1; i<=ndata; i++)
   {
      fscanf(balloon,"%lf %lf %lf",&press, &vol, &temp),
      c_mass = mass(press,vol,temp);
      printf("\n   %1i       %5.1f     %5.1f       %4.1f     %4.1f",i,press,vol,
	         temp,c_mass);
      fprintf(table,"\n   %1i       %5.1f     %5.1f       %4.1f     %4.1f",i,
	          press,vol,temp,c_mass);
   }

   /* Print number of balloons with zero values */
   /*printf("\n\nThere were %1i balloons with zero values.",count);
   fprintf(table,"\n\nThere were %1i balloons with zero values.",count);*/
   printf("\n************************************************\n\n");
   fprintf(table,"\n************************************************\n\n");
  
   /* Close input and output files */
   fclose(balloon);
   fclose(table);
   
   /* Exit the program */
   return 0;
}
/*******************************************************************************
The user-defined function will calculate the MASS of a balloon after receiving
pressure, volume, and temperature.
*******************************************************************************/
double mass(double press, double vol, double temp)
{
	/* Declare variables */
	double computed_mass;
	
	/* Computer balloon mass */
	computed_mass = (press*vol)/(.42*(temp+459.67));
	
	/* Return computed mass */
	return computed_mass;
}
/******************************************************************************/
