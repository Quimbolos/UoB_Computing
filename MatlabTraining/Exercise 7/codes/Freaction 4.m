function[f]=Freaction(Mass,Gacceleration,Airdensity,Wingarea,Liftcoeff)
%Ask the user for a value of velocity
v = input('What is the velocity?');
W=Gacceleration*Mass;

L=0.5*Airdensity*((v).^2)*Wingarea*Liftcoeff;

f=W-L;

end


