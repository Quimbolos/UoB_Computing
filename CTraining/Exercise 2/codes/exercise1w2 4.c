#include<stdio.h>
#include<math.h>
 int main () {
   
   /* allocate memory */
   double N, Xo, Tmax, E, x, Xt1, Xt2,t, Xnew;
   
   /* we ask the user to input a value for N */
   printf("Input a value of N:");
   scanf("%lf", &N);
   
   /* check if the root is real and warn the user if not */
   if (N>0.0) {
      N=N;
   } else {
      N=-N;
	  printf("the value of N will be consider as |N|");
   }
   
   /* ask the user to input the rest of variables */
   printf("Input a value of Xo:");
   scanf("%lf", &Xo);
   printf("Input a value of Tmax:");
   scanf("%lf", &Tmax);
   printf("Input a value of E:");
   scanf("%lf", &E);
   
   /* statements */
   
 printf(" t      x(t)      f(x)     f'(x)     x(t+1)\n");
 
   /* Loop */
   for(t=1; t<=Tmax ; t=t+1) {
    
     Xt1=pow(Xo,2)-N;
     Xt2=2*Xo;
     Xnew=(Xo)-(Xt1/Xt2);
	 Xo=Xnew;
	 if (Xt1<=E) {
	   break;
	 }
	 printf("%lf   %lf   %lf   %lf   %lf\n", t, Xo, Xt1, Xt2, Xo);
	}
	
	
   
   
  return(0);
  }