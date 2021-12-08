clear all
close all

x=[1.0;2.0];
y=[3.0;4.0];

Xlin=[x ones(size(x))];

Vlin=inv(Xlin)*y;

a=Vlin(1);
b=Vlin(2);
xplot=(0:0.1:3);

yplot=a*xplot+b;

plot(xplot, yplot);
hold on;
plot(x,y,'ro');
grid;
axis([0 3 0 5]);

hold off









