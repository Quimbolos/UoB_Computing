clear all
close all

x=[1.0;2.0;1.5];

y=[3.0;4.0;4.0];

Xlin=[x ones(size(x))];
X=[x.^2 x ones(size(x))];

Vlin=pinv(Xlin)*y;
V=inv(X)*y;

a=Vlin(1);
b=Vlin(2);
d=V(1);
e=V(2);
f=V(3);

xplotlin=(0:0.1:3);
yplotlin=(xplotlin*a)+b;

xplot=(0:0.05:3);

yplot=(d*xplot.^2)+(e*xplot)+f;
plot(xplotlin, yplotlin);
hold on;
plot(xplot, yplot);
hold on;
plot(x,y,'ro');
grid;
legend('Linear','Quadratic')
axis([0 3 0 5]);
hold off;