clear all
close all

load('radardata(1).mat', 'ys')
load('radardata(1).mat', 'xs')
load('radardata(1).mat', 'v')

r=6.38e6;
angle=0:0.1:2*pi;

x=r*cos(angle);
y=r*sin(angle);


plot(xs,ys,'b.');
hold on
plot(x,y,'g');
grid;


X=[xs.^2 ys.^2 xs+ys xs ys];
A=pinv(X)*ones(size(X));

a=A(1)
b=A(2)
c=A(3)
d=A(4)
e=A(5)




