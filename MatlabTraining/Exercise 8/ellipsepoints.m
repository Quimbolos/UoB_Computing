function [xs,ys]=ellipsepoints(a,b,c,d,e,Npe)
%
% [xs,ys] = ellipsepoints(a,b,c,d,e,Npe)
%
% Returns Npe evenly spaced points on the ellipse
% with equation
%
%   ax^2 + by^2 + cxy + dx + ey = 1
%

% convert to matrix form
alpha = a;
beta = b;
gamma = c/2;
R = [2*gamma 2*beta; 2*alpha 2*gamma];
f = R\[-e; -d];
px = f(1);
py = f(2);
lambda = 1 + alpha*px*px + beta*py*py + 2*gamma*px*py;

% build and factorize matrix
Q = [alpha gamma; gamma beta]/lambda;
R = chol(Q);
Ri = inv(R);

% unit circle
ths = [0:2*pi/Npe:2*pi];
xycu = [cos(ths);sin(ths)];

% skew to ellipse
xyel = Ri*xycu;

xs = px+xyel(1,:);
ys = py+xyel(2,:);