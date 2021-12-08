function  [a] = acceleration(Thrust,Mass,Liftcoeff,Wingarea,Frictioncoeff,Gacceleration,Airdensity )
%Ask the user for a value of velocity
v = input('What is the velocity?');
%Calculate value of R
W=Gacceleration*Mass;
L=0.5*Airdensity*((v).^2)*Wingarea*Liftcoeff;
R=W-L;
F=Frictioncoeff*R;
Cd=0.04+(0.06*((Liftcoeff).^2));
D=0.5*Airdensity*((v).^2)*Wingarea*Cd;
a=(1/Mass)*(Thrust-(D+F));

end

