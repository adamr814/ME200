/*******************************************************************************
ENGR 200-2                                                      DATE: 02/18/2020

PROGRAM: A3                               Author: Adam Roy
********************************************************************************

PROGRAM DESCRIPTION
This program will calculate oil exploration and will read and write to files
the information that it writes.
*******************************************************************************/
/* u:\\engr 200\\ */
/* Preprocessor directives */
#include <stdio.h>
#include <math.h>
#define inputfile "c:\\Users\\adamr\\Google Drive\\College Stuff\\ME 200\\oil_explore.txt"
#define outputfile "c:\\Users\\adamr\\Google Drive\\College Stuff\\ME 200\\oil_repor.txt"

/* Main Function */
int main(void)
{
	
	/*declare variables */
	FILE *oilexplore;
	FILE *oilreport;
	double ratio, idealchg, length, weight;
	int numstk, depth, site;

	/* open input file */
	oilexplore = fopen(inputfile, "r");
	if(oilexplore == NULL)
	{
		printf("\n\nERROR OPENING INPUT FILE\n\n"
		       "PROGRAM TERMINATED\n\n");
		       return 0;
	}
	
	/* Open output file */
    oilreport = fopen(outputfile, "w");
    if(oilreport == NULL)
    {
    	printf("\n\nERROR OPENING OUTPUT FILE\n\n"
		       "PROGRAM WILL NOT BE RECORDED\n\n");
	}
       
    /* Scan first line */
	fscanf(oilexplore,"%lf,%lf",&length,&weight);

    /* Scan next lines */
	fscanf(oilexplore,"%i,%i",&site,&depth);

    /* Print main headings */
	printf("**********************************************\n");
	fprintf(oilreport,"**********************************************\n");
	printf("            DAILY DRILLING REPORT\n\n");
	fprintf(oilreport,"            DAILY DRILLING REPORT\n\n");
	
	 /* Print Results */
	printf("SITE   DEPTH   IDEAL POWDER   NUMBER OF STICKS\n");
	fprintf(oilreport,"SITE   DEPTH   IDEAL POWDER   NUMBER OF STICKS\n");
	printf(" ID     (ft)      (lbs)\n");
	fprintf(oilreport," ID     (ft)      (lbs)\n");
	
     
     
	/* Computations */
	while(site != -999 && depth != -999)
	 {
	 	ratio=depth/3.0;
	 	idealchg=ratio/length*weight;
	 	numstk=(int)ratio/(int)length;
        if(depth <= 30)
        {
         printf("%4i    %3i   HOLE TOO SHALLOW FOR BLASTING\n",site,depth);
		 fprintf(oilreport,"%4i    %3i   HOLE TOO SHALLOW FOR BLASTING\n",site,depth);
		  
        }
        else
        {
		
         printf("%4i    %3i      %6.2f           %3i\n",site,depth,
		        idealchg,numstk);
		 fprintf(oilreport,"%4i    %3i      %6.2f           %3i\n",site,depth,
		        idealchg,numstk);	
				       
        }
        
        fscanf(oilexplore,"%i,%i",&site,&depth);
     }
    printf("**********************************************\n");
    fprintf(oilreport,"**********************************************\n");
    
	 /* Close external files */	        
	 fclose(oilexplore);
	 fclose(oilreport);
	 
     /* Exit Program */
     return(0);
	  
	 
}
