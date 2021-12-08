function[f]=Freactionv0(v)
Mass=15000;
Wingarea=50;
Airdensity=1.225;
Gacceleration=9.81;
Thrust=110000;
Liftcoeff=0.6;  
Frictioncoeff=0.02;

W=Gacceleration*Mass;

L=0.5*Airdensity*((v).^2)*Wingarea*Liftcoeff;

f=W-L;

end

