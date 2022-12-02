%**************************************************************************
%ENGR 200-02                                                DATE:04/14/2020



 
%ASSIGNMENT: #8                         Author:Adam Roy
%**************************************************************************

%PROGRAM DESCRIPTION:
%This program will compute the strain and stress put on a sample that is
%placed in a tensile machine to determine how much the sample can
%withstand pressure exerted on it and show how much the sample disforms due
%to the pressure.

%VARIABLE DESCRIPTIONS:
%NAME   | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%af     | double | a matrix of the applied force
%sl     | double | a matrix of the sample length
%report | char   | output file pointer variable
%sdiam  | double | diameter of the sample
%csa    | double | area of the cross section of the sample
%cstre  | double | computed stress matrix
%cstra  | double | computed strain matrix
%**************************************************************************

%Clear Command Window, Workspace, and close plots
clear
clc
close all

%Load input file
af = load('applied_force.txt');
sl = load('sample_length.txt');

%Open output file
report = fopen('tensile_report.txt','wt');

%Print main heading to Command Window and output file
fprintf('**************************************');
fprintf('\n      TENSILE TESTING ANALYSIS');
fprintf(report,'**************************************');
fprintf(report,'\n      TENSILE TESTING ANALYSIS');

%Enter sample diameter
sdiam = input('\n\nEnter sample diameter (inches): ');

%Print sample diameter to output file
fprintf(report,'\n\nSample diameter: %5.3f inches',sdiam);

%Calculate the cross sectional area
csa = (pi*(sdiam*.5)^2);

%Calculate the computed stress
for k=1:1:length(af)
    cstre = ((af/csa).*(sl./2));
end

%Calculate the computed strain
for k=1:1:length(sl)
    cstra = log(sl./2);
end

%Print testing analysis
fprintf('\n\n Load   Length     Stress      Strain');
fprintf('\n (lb)    (in)       (psi)     (in/in)');
fprintf(report,'\n\n Load   Length     Stress      Strain');
fprintf(report,'\n (lb)    (in)       (psi)     (in/in)');    
for k=1:1:length(af)
    fprintf('\n%5.0f    %5.3f    %8.2f       %5.3f',af(k),sl(k),cstre(k),cstra(k));
    fprintf(report,'\n%5.0f    %5.3f    %8.2f       %5.3f',af(k),sl(k),cstre(k),cstra(k));
end

%Print end of report
fprintf('\n**************************************');
fprintf(report,'\n**************************************');

%Close output file
fclose(report);

%**************************************************************************


