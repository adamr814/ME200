%**************************************************************************
%MATLAB DEMO USING A TWO-DIMENSIONAL MATRIX AND PLOTTING
%   
%PROGRAM DESCRIPTION:
%This program will load time and temperature data into a two-dimensional
%matrix.  It will compute the summations of time, temperature, time squared,
%and time*temperature values.  The program will compute the slope and
%y-intercept of a linear equation and plot the experimental data and the
%computed linear data to a graph.  The results are printed to the Command
%Window and an time-temperature plot is generated.
%
%DESCRIPTION VARIABLES:
%NAME        | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%experi       | double | two-dimensional matrix of time and temperature data
%sumtime     | double | summation of all time values
%sumtemp     | double | summation of all temperatute values
%sumtimesq   | double | summation of all time squared values
%sumtimetemp | double | summation of all time*temperature values
%slope       | double | computed slope
%yint        | double | computed y-intercept
%computed    | double | one-dimensional matrix using the linear equation
%lin_eq      | char   | one-dimensional matrix of character data
%nrows       | double | number of rows in the matrix
%timesq      | double | computed time squared values
%timetemp    | double | computed time x temperature values
%merged      | double | all matrices merged for printing
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Load input file
experi = load('experimental_data.txt');

%Size matrix
[nrows,~] = size(experi);

%Compute time^2 and time*temperature
timesq = experi(:,1).^2;
timetemp = experi(:,1).*experi(:,2);

%Compute summations
sumtime = sum(experi(:,1));
sumtemp = sum(experi(:,2));
sumtimesq = sum(timesq);
sumtimetemp = sum(timetemp);

%Compute slope and y-intercept
slope = (sumtime*sumtemp - nrows*sumtimetemp)/(sumtime^2 - nrows*sumtimesq);
yint = (sumtemp-slope*sumtime)/nrows;

%Compute linear data for printing and graphing
computed = slope*experi(:,1)+yint;

%Merge all matrices for printing
merged = [experi,timesq,timetemp,computed];

%Store linear equation as character string for printing
lin_eq = ['y=',num2str(slope),'*time+',num2str(yint)];

%Print headings to the Command Window
disp('*****************************************************');
disp('             LINEAR REGRESSION ANALYSIS');
disp(' ');
disp(' Time   Temperature   Time^2   Time x Temp   Computed');

%Print results to Command Window
fprintf('%5.1f      %5.1f    %8.1f      %7.1f      %5.1f\n',merged');
fprintf('\n               ');
disp(lin_eq);
disp('*****************************************************');
disp(' ');

%Plot time, temperature, and computed values
plot(experi(:,1),experi(:,2),experi(:,1),computed),...
    title('Temperature vs Time'),xlabel('Time (minutes)'),...
    ylabel('Temperature (°F)'),axis square,grid on,...
    legend('Experimental','Computed'),gtext(lin_eq)

%**************************************************************************
