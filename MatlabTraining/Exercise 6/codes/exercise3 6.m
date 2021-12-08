clear all
close all
load('passengerdata(1).mat');

X=[xs.^2 xs ones(size(xs))];

V=pinv(X)*ys;

d=V(1);
e=V(2);
f=V(3);

xplot=(1950:2010);
yplot=(d*xplot.^2)+(e*xplot)+f;
plot(xs,ys,'rx');
hold on;
plot(xplot, yplot);
grid;
axis([1950 2010 0 2.5*10^5]);
legend('Real data','Quadratic','Location','northwest');
title('Air Passenger Data and Predictions');
ylabel('Passengers');
xlabel('Year');
hold off