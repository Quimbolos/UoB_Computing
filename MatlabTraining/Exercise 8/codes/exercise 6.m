clear all
close all

%we load the cartesian values and the vector from the file
load('radardata(1).mat', 'ys')
load('radardata(1).mat', 'xs')


%we create the cartesian form of earth
r=6.38e6;
Angle=0:0.1:2*pi;
x=r*cos(Angle);
y=r*sin(Angle);

%we plot the earth and the values given from the file
plot(xs,ys,'b.')
hold on
plot(x,y, 'g ')
hold on
grid
hold on

%For the second part we solve the equation given in matrix form
%X equals the matrix of the cartesian values
%Then we create a ones matrix
%A matrix contains a,b,c,d,e values and it's the matrix to be solved
X=[xs.^2 ys.^2 xs.*ys xs ys];
A=pinv(X)*ones(size(X));

%we assign the values of matrix A 
a=A(1);
b=A(2);
c=A(3);
d=A(4);
e=A(5);
Npe=1000;

% %we call the function in order to generate the elipse points
[xs,ys]=ellipsepoints(a, b, c, d, e, Npe);

% %Now we plot the ellipse as a red line 
plot(xs,ys,'r')
hold on

%we load it for further exercices
load('radardata(1).mat')

%Hardcode some extra values
G=6.67e-11;
mj=5.97e24;
xi=[xs(1) ys(1)];
xj=[0 0];
t=0;
dt=100;
v=v';
i=1;

%we use a loop to integrate the physics formula
while t<=210000
   a= (G*mj*(xj-xi(i,1:2)))/(sqrt(sum((xj-xi(i,1:2)).^2)))^3; 
   xi(i+1,1:2)= xi(i,1:2)+v*dt;
   v=v+a*(dt);
   t=t+dt;
   i=i+1;  
end

%% Now we plot the results
x=xi(:,1);
y=xi(:,2);
plot(x,y,'m')
xlabel('x coordinates(m)')
ylabel('y coordinates(m)')
legend('Contact points','Earth','parameter Fit')




