#include<stdio.h>
#include<math.h>

//function1
   
   double secmoment(double c, double t){
    
	double I;
	
	I=(c*t*t*t)/12;
	
   return(I);
   }
   
   //function2
     double loading(double Wwing, double Wfuel, double s){
    
	double q;
	
	q=(Wwing+Wfuel)/s;
	
   return(q);
   }
   
   
   //function3
   
   double wingdeflection(double Wwing, double Wfuel, double s, double E, double c, double t){
   
   double w, I , q;
   I=secmoment(c, t);
   q=loading(Wwing, Wfuel, s);   
   
   w=(q*s*s*s*s)/(8*E*I);
   
   return(w);
   }
   
 int main () {
   
   //variables
   
   double t, c, s, E, Wwing, h, I, Wfuel, q, w, Wtest, U, L, error;
   
   printf("Input a value for Wfuel:");
   scanf("%lf", &Wfuel);
   t=0.07;
   c=0.6;
   s=13.5;
   E=69e9;
   Wwing=1150;
   h=0.5;
   I=secmoment(c,t);
   printf("%lf\n", I);
   q=loading(Wwing,Wfuel,s);
   printf("%lf\n", q);
   w=wingdeflection(Wwing, Wfuel, s, E, c, t); 
   printf("%lf\n", w);   
   printf("Input a value for U:");
   scanf("%lf", &U);
   printf("Input a value for L:");
   scanf("%lf", &L);
   printf("Input a value for error:");
   scanf("%lf", &error);
   printf(" Lower         Upper        Wfuel       Def\n");
   while (Wtest!=Wfuel) {
      Wtest=0.5*(U+L);
      w=wingdeflection(Wwing, Wtest, s, E, c, t);
 
	if (w>(h+error)) {
		U=Wtest;
	 }
	 else if (w<(h-error)) {
		L=Wtest;
	 }
	 else {
		Wfuel=Wtest;
	 }
   printf("%lf     %lf     %lf     %lf\n", L, U, Wfuel, w);
   }
   
   printf(" Weight of fuel is %lfN with %lfm deflection", Wfuel, w); 
 
 
	return(0);
  }