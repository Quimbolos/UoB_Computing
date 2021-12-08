#include <stdio.h> 
#include <math.h>
int main() {
/* Allocate memory */
 double dynamicPressure, velocity, density, angleIncidence, liftCoefficient, Lift, PI;
/* Hard-code a value of density */
 density=1.225;
 PI=3.1415926536;
/* Ask user for input value of velocity and read in */
 printf("Input a value for velocity:"); 
 scanf("%lf", &velocity);
 printf("Input a value for angle of incidence:");
 scanf("%lf", &angleIncidence);
/* Calculate the dynamic pressure */
 dynamicPressure=0.5*density*(pow(velocity, 2));
 angleIncidence=(angleIncidence*PI)/180;
 liftCoefficient=2*PI*angleIncidence;
 Lift=dynamicPressure*liftCoefficient;
/* Print the dynamic pressure */
 printf("The dynamic pressure is %lf\n", dynamicPressure);
 printf(" & The angle of incidence is %lf\n", angleIncidence);
 printf(" & The lift coefficient is %lf\n", liftCoefficient);
 printf(" & The total lift is %lf\n", Lift);

return(0);
}