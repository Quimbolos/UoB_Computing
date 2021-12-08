#include<stdio.h>
#include<math.h>

  int main() {
  
  //variables 
  
   int N, ii;
   
   double Xo, X, fx, fprime, Tmax, error, x;
   
   ii=1;
   
   //input value of N:
   
   printf("Input a value of N:");
   scanf("%i", &N);
   
   //warn about absolute value:
   
   if (N>0) {
	   
	   N=N;
	   
   } else {
	   
	   N=-N;
	   printf("N will be considered as |N|\n");
  
   }
   
   //value inputs
   
   printf("value of Xo=");
   scanf("%lf", &Xo);
   printf("value of Tmax=");
   scanf("%lf", &Tmax);
   printf("value of error=");
   scanf("%lf", &error);
   
   printf("t       x(t)       f(x)       f'(x)       x(t+1)\n");
   
   //looping
   
   while (ii<=Tmax) {
	   fx=pow(Xo,2)-N;
	   fprime=2*N;
	   X=Xo;
       X=X-(fx/fprime);
	   
	   printf("%i       %lf       %lf       %lf       %lf\n", ii, X, fx, fprime, Xo);
	   ii=ii+1;
	   
	   //error tolerance
	   
	   if (fx<=error) {
		   
		   break;
	   }
   }
   
   return(0);
  
  }