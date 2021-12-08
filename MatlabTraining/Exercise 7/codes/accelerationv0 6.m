function [a2] = accelerationv0(v) 
%hardcode the values for given data
Mass=15000;
Wingarea=50;
Airdensity=1.225;
Gacceleration=9.81;
Thrust=110000;
Liftcoeff=0.6;  
Frictioncoeff=0.02;
%perform some calculations
W=Gacceleration*Mass;
L=0.5*Airdensity*((v).^2)*Wingarea*Liftcoeff;
R=W-L;
F=Frictioncoeff*R;
Cd=0.04+(0.06*((Liftcoeff).^2));
D=0.5*Airdensity*((v).^2)*Wingarea*Cd;
a2=(1/Mass)*(Thrust-(D+F));


end

