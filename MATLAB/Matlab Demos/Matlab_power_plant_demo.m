%**************************************************************************
%MATLAB DEMO USING MULTIPLE MATLAB FUNCTIONS, ONE-DIMENSIONAL AND 
%TWO-DIMENSIONAL MATRICES
   
%PROGRAM DESCRIPTION:
%This program will compute the average power output of a two-dimensional
%power matrix.  The program will determine the minimum power, the maximum
%power, the row and column location of the minimum power, the row and
%column location of the maximum power, and the daily power averages.  The
%results are printed to the Command Window and to an output file.

%DESCRIPTION VARIABLES:
%NAME   | TYPE   | DESCRIPTION
%-------------------------------------------------------------------------
%plant  | double | two-dimensional matrix of power in megawatts
%avepow | double | computed overall average power
%dayavg | double | computed daily power averages
%nrows  | double | number of rows in the matrix
%ncols  | double | number of columns in the matrix
%minpow | double | minimum power output
%maxpow | double | maximum power output
%minrow | double | row location of minimum power
%mincol | double | column location of minimum power
%maxrow | double | row location of maximum power
%maxcol | double | column location of maximum power
%wk     | char   | two-dimensional character matrix of weeks
%dy     | double | one-dimensional matrix of days
%m      | double | outer loop control variable
%n      | double | inner loop control variable
%report | double | location of printed output file
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
plant = load('power_plant_data.txt');

%Open output file
report = fopen('power_plant_report.txt','wt');

%Size matrix
[nrows,ncols] = size(plant);

%Matrix of weeks
wk = ['Week1    ';'Week2    ';'Week3    ';'Week4    ';'Week5    ';...
      'Week6    ';'Week7    ';'Week8    '];
 
%Matrix of days
dy = 1:1:7;

%Compute overall average power,compute daily averages, find min/max power
avepow = mean(plant(:));
dayavg = mean(plant);
minpow = min(plant(:));
maxpow = max(plant(:));

%Find minimum and maximum power locations in the matrix
[minrow,mincol] = find(plant == minpow);
[maxrow,maxcol] = find(plant == maxpow);

%Print to Command Window
disp('************************************************');
disp('           POWER OUTPUT IN MEGAWATTS');
disp(' ');
fprintf('        ');
fprintf('Day%1i  ',dy);
disp(' ');

disp([wk,num2str(plant,'%3i   ')]);

disp(' ');
disp('                      Daily Averages');
fprintf('         ');
fprintf('%3.0f   ',dayavg);
fprintf('\n\nMinimum power = %3i megawatts at %s, Day%1i', ...
        minpow,wk(minrow,:),dy(mincol));
fprintf('\nMaximum power = %3i megawatts at %s, Day%1i', ...
        maxpow,wk(maxrow,:),dy(maxcol));
fprintf('\nAverage power = %3.0f megawatts\n',avepow);
disp('*************************************************');
disp(' ');
disp(' ');

%Print to output file
fprintf(report,'***************************************************');
fprintf(report,'\n             POWER OUTPUT IN MEGAWATTS\n\n        ');
fprintf(report,'Day%1i  ',dy);

for m=1:1:nrows
    fprintf(report,'\n%s',wk(m,:));
    for n=1:1:ncols
        fprintf(report,'%3i   ',plant(m,n));
    end
end

fprintf(report,'\n\n                    Daily Averages\n         ');
fprintf(report,'%3.0f   ',dayavg);
fprintf(report,'\n\nMinimum power = %3i megawatts at %s, Day%1i', ...
        minpow,wk(minrow,:),dy(mincol));
fprintf(report,'\nMaximum power = %3i megawatts at %s, Day%1i', ...
        maxpow,wk(maxrow,:),dy(maxcol));
fprintf(report,'\nAverage power = %3.0f megawatts',avepow);
fprintf(report,'\n***************************************************');

%Close output file
fclose(report);
%**************************************************************************