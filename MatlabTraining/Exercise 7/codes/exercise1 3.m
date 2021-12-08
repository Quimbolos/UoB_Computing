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


%run the function

f=Freaction(Mass,Gacceleration,Airdensity,Wingarea,Liftcoeff);
disp(f);

