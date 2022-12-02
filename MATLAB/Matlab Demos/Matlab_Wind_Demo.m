%**************************************************************************
%MATLAB DEMO PROGRAM USING A ONE-DIMENSIONAL MATRIX

%PROGRAM DESCRIPTION:
%This program will compute the power output of a wind powered generator
%based on a one-dimensional matrix of wind speeds.  The output computations
%will be for 20 percent, 30 percent, 40 percent, and 50 percent.  The
%results are printed to the command window and to an output file.

%VARIABLE DESCRIPTIONS:
%NAME   | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%ws     | double | a matrix of wind speeds in mph
%nrows  | double | number of rows of wind speeds in the input matrix
%report | char   | output file pointer variable
%airden | double | density of air (1.225 kg/m^3)
%brad   | double | length of a blade in cm
%sarea  | double | computed swept area of rotating blade in m^2
%p20    | double | computed power output matrix in watts at 30 percent
%p30    | double | computed power output matrix in watts at 35 percent
%p40    | double | computed power output matrix in watts at 40 percent
%p50    | double | computed power output matrix in watts at 50 percent
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clear
clc
close all

%Load input file
ws = load('wind_speeds.txt');

%Open output file
report = fopen('power_results.txt','wt');

%Print main heading to Command Window and output file
fprintf('****************************************************');
fprintf('\n           WIND TURBINE POWER CALCULATIONS');
fprintf(report,'****************************************************');
fprintf(report,'\n           WIND TURBINE POWER CALCULATIONS');


%Enter air density and blade radius
airden = input('\n\nEnter air density in kg/m^3: ');
brad = input('Enter blade radius in cm   : ');

%Print air density and blade radius to output file
fprintf(report,'\n\nAir density = %5.3f kg/m^3',airden);
fprintf(report,'\n\nBlade radius = %4.1f cm',brad);

%Compute rotating blade swept area in square meters
sarea = pi*(brad/100)^2;

%Print column headings to Command Window and output file
fprintf('\n                            Power');
fprintf('\n                           (watts)');
fprintf('\n           30 pct     35 pct     40 pct     50 pct');
fprintf('\nWind');
fprintf('\n(m/h)');
fprintf(report,'\n                            Power');
fprintf(report,'\n                           (watts)');
fprintf(report,'\n           30 pct     35 pct     40 pct     50 pct');
fprintf(report,'\nWind');
fprintf(report,'\n(m/h)');

%Compute power output for 20% 30% 40% and 50%
p20 = .2*(0.5*airden*sarea*(ws*0.44704).^3);
p30 = .3*(0.5*airden*sarea*(ws*0.44704).^3);
p40 = .4*(0.5*airden*sarea*(ws*0.44704).^3);
p50 = .5*(0.5*airden*sarea*(ws*0.44704).^3);

%Print power output table to Command Window and output file
for k=1:1:length(ws)
    if ws(k) == 0
        fprintf('\n%4.1f       NO ELECTRICAL OUTPUT',ws(k));
        fprintf(report,'\n%4.1f       NO ELECTRICAL OUTPUT',ws(k));
    else
        fprintf('\n%4.1f       %5.1f      %5.1f      %5.1f      %5.1f',...
        ws(k),p20(k),p30(k),p40(k),p50(k));
        fprintf(report,'\n%4.1f       %5.1f      %5.1f      %5.1f      %5.1f',...
        ws(k),p20(k),p30(k),p40(k),p50(k));
    end
end

%Print end of report
fprintf('\n****************************************************\n\n');
fprintf(report,'\n****************************************************\n\n');

%Close output file
fclose(report);
%**************************************************************************

















