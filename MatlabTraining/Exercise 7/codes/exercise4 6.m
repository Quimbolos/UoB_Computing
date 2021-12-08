clear all
close all

%hardcode the values for given data
Mass=15000;
Wingarea=50;
Airdensity=1.225;
Gacceleration=9.81;
Thrust=110000;
Liftcoeff=0.6;  
Frictioncoeff=0.02;

%hardcode intial values
t=0;
x=0;
v=0;
dt=0.1;
i=1;

%creating loop
R(i)= Freactionv0(v(i));
a(i) = accelerationv0(v(i));
while R>0
    
    t(i+1)=t(i) + dt;
    x(i+1)=x(i)+v(i)*dt;
    v(i+1)= v(i)+accelerationv0(v(i))*dt;
%   v(i+1)=v(i)+a(i+1)*dt;   
%   a(i+1)=accelerationv0(v(i+1));  
    R(i+1)=Freactionv0(v(i+1));
   i=i+1;
   
   
   
    
end
%plot t vs v
subplot(2,1,1),plot(t,v,'r')
axis([0 15 0 100])
grid on
xlabel('time (S)')
ylabel('Velocity (m/s)')

%plot t vs R
hold on
subplot(2,1,2),plot(t,R)
axis([0 15 0 150000])
grid on
xlabel('time (S)')
ylabel('Reaction (N)')





