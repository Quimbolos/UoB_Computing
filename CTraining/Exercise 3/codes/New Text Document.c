#include<stdio.h>
#include<math.h>

//funtction1
   
   double I=secmoment(double c, double t){
    
	I=(c*t*t*t)/12;
	
   return(I);
   }
   
 int main () {
   
   //variables
   
   double t, c, s, E, Wwing, h;
   
   t=0.07;
   c=0.6;
   s=13.5;
   E=69*1000000000;
   Wwing=1150;
   h=0.5;
   I=secmoment(c,t);
   printf("%lf", I);
  
   
   
   
 
 
  return(0)
  }