%**************************************************************************
%MATLAB DEMO USING MATRIX MULTIPLICATION, MATRIX CONCATENATING, AND 
%MULTI-VARIABLE PLOTTING
   
%PROGRAM DESCRIPTION:
%This program will compute distance, velocity, and acceleration of a rocket
%as time varies from 0 to 25 seconds in one second intervals.  The program
%will plot the curves of distance, velocity, and acceleration vs time.  The
%results are printed to the Command Window.

%DESCRIPTION VARIABLES:
%NAME   | TYPE   | DESCRIPTION
%--------------------------------------------------------------------------
%time   | double | one-dimensional matrix of time in seconds
%accl   | double | one-dimensional matrix of acceleration in ft/sec^2
%velo   | double | one-dimensional matrix of velocity in ft/sec
%dist   | double | one-dimensional matrix of distance in ft
%flight | double | concatenated one-dimensional matrices
%**************************************************************************

%Clear Command Window, clear memory, and close plots
clc
clear
close all

%Display the main headings and column headings to the Command Window
disp('****************************************************************');
disp('                    ROCKET FLIGHT SIMULATION');
disp(' ');
disp('          TIME   ACCELERATION   VELOCITY     DISTANCE');
disp('          (sec)   (ft/sec^2)    (ft/sec)       (ft)');

%Create a time matrix
time = 0:1:25;

%Using the time matrix, compute the distance, velocity, acceleration matrices
dist = 90+2.125*time.^2-0.00125*time.^4;
velo = 4.25*time-0.005*time.^3;
accel = 4.25-0.15*time.^2;

%Using concatenation, merge the four matrices
flight = [time;accel;velo;dist];

%Using a single print command, print the four matrices to Command Window
fprintf('           %2i      %6.2f         %5.2f       %6.2f\n',flight);

%Display the closing line of the output format 
disp('****************************************************************');

%Plot the distance, velocity, and acceleration matrices vs the time matrix
plot(time,dist,time,accel,'--',time,velo,'.-'),title('Rocket Flight'),...
    xlabel('Time'),ylabel('Distance, Acceleration, Velocity'),...
    legend('Distance','Acceleration','Velocity'),grid on, axis square
%**************************************************************************
