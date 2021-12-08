clear all 
close all
% hardcode all the variables
Mass=15000;
Wingarea=50;
Airdensity=1.225;
Gacceleration=9.81;
Thrust=110000;
Liftcoeff=0.6;  
Frictioncoeff=0.02;
%we crate a vector
v=0:100;
f=Freactionv0(v);

plot(v,f);
grid;
title('Reaction on aircraft for varying velocity');
ylabel('Reaction force(N)');
xlabel('Velocity(m/s)');