clear all 
close all
% hardcode all the variables
Mass=1500;
Wingarea=50;
Airdensity=1.225;
Gacceleration=9.81;
Thrust=110000;
Liftcoeff=0.6;  
Frictioncoeff=0.02;
j=0;
for i=0:0.001:100
    j=j+1;
    v=i;
    L(j)=0.5*Airdensity*((v).^2)*Wingarea*Liftcoeff;
    W=Gacceleration*Mass;
    Freaction=L-W;
    
end
plot(v,Freaction);

% v=0;
% vmax=100;
% while v<=vmax
%     v=v+1;
%     f=Freactionv0(Mass,Gacceleration,Airdensity,Wingarea,Liftcoeff,v);
% end