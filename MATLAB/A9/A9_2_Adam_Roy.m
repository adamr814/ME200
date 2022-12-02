%**************************************************************************
%ENGR 200-02                                                DATE:04/21/2020



 
%ASSIGNMENT: #9                         Author:Adam Roy
%**************************************************************************

%Description of program: the program will load the input file compute the
%average water height over a six-year period, and compute the average water
%height for each year. Also the program will determine the minimum and
%maximum water heights for the six-year period and determine the month and
%year that the min and max values occurred.

%VARIABLE DESCRIPTIONS:
%NAME   | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%lake   | double | two-dimensional matrix of lake height in feet
%report | double | location of printed output file
%nrows  | double | number of rows in the matrix
%ncols  | double | number of columns in the matrix
%minwh  | double | minumum water height
%maxwh  | double | maximum water height
%months | char   | two-dimensional character matrix of months
%years  | double | one-dimensional matrix of years
%m      | double | outer loop control variable
%n      | double | inner loop contril variable
%
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
lake = load('lake_powell.txt');

%Open output file
report = fopen('lake_powell_report.txt','wt');

%Size matrix
[nrows,ncols] = size(lake);

%Matrix of months
months = ['January    ';'February   ';'March      ';'April      ';...
          'May        ';'June       ';'July       ';'August     ';...
          'September  ';'October    ';'November   ';'December   '];
      
%Matrix of years
years = 2000:1:2005;

%Compute averages and max/min values
yave = mean(lake);
avewh = mean(lake(:));
minwh = min(lake(:));
maxwh = max(lake(:));

%Find minimum and maximum water loactions in the matrix
[minrow,mincol] = find(lake == minwh);
[maxrow,maxcol] = find(lake == maxwh);

%Print to Command Window
disp('*************************************************************************');
disp('                    LAKE POWELL RESERVOIR STATISTICS');
disp('                           (elevations in feet)');
disp(' ');
fprintf('             ');
fprintf('%4i      ',years);
disp(' ');

disp([months,num2str(lake,'%7.2f   ')]);

disp(' ');
disp('                                Yearly Averages');
fprintf('           ');
fprintf('%7.2f   ',yave(:));
fprintf('\n\nResevoir Statistics:');
fprintf('\nAverage water height above sea level is %7.2f feet',avewh);
fprintf('\nMinimum water height above sea level is %7.2f feet in %s, %4i',...
    minwh,months(minrow,:),years(mincol));
fprintf('\nMaximum water height above sea level is %7.2f feet in %s, %4i\n',...
    maxwh,months(maxrow,:),years(maxcol));
disp('*************************************************************************');
disp(' ');
disp(' ');

%Print to output file
fprintf(report,'*************************************************************************\n');
fprintf(report,'                     LAKE POWELL RESERVOIR STATISTICS\n');
fprintf(report,'                            (elevations in feet)\n\n');
fprintf(report,'             ');
fprintf(report,'%4i      ',years);

for m=1:1:nrows
    fprintf(report,'\n%s',months(m,:));
    for n=1:1:ncols
        fprintf(report,'%7.2f   ',lake(m,n));
        
    end
end

fprintf(report,'\n\n                                Yearly Averages');
fprintf(report,'\n           ');
fprintf(report,'%7.2f   ',yave(:));
fprintf(report,'\n\nResevoir Statistics:');
fprintf(report,'\nAverage water height above sea level is %7.2f feet',avewh);
fprintf(report,'\nMinimum water height above sea level is %7.2f feet in %s, %4i',...
    minwh,months(minrow,:),years(mincol));
fprintf(report,'\nMaximum water height above sea level is %7.2f feet in %s, %4i',...
    maxwh,months(maxrow,:),years(maxcol));
fprintf(report,'\n*************************************************************************');

%Close output file
fclose(report);
%%**************************************************************************




