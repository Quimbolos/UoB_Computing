#include<stdio.h>
#include<math.h>

//FUNCTION (1) we open the file and store info into the array
double function1(FILE *liftcoeff, double array[12][2], int ii){
	
    //open the file
	liftcoeff=fopen("liftcoeff.txt","r");
    //scan all parameters in the file (for loop)
	for (ii=0; ii<12; ii++){
	fscanf(liftcoeff, "%lf  %lf \n", &array[ii][2], &array[12][ii]);
	printf("%i %lf %lf\n",ii, array[ii][2], array[12][ii]);
	}
	fclose(liftcoeff);
	return(0);
}

//FUNCTION (2) we use the algorithm to calculate the lift coefficient.
double fliftcoeff(double angle, double array[12][2],double xq, double yq, double xi1, double yi1, double xi, double yi, double a, double b, int ii){
	//ask thecdcd user to input an Angle of attack value
	printf("Input a value for the Angle of attack");
	scanf("%lf", &angle);
	//Loop to find the values of xi, yi, xi1, yi1
	for (ii=0; ii<12; ii++){
		if(angle<=array[ii][2]){
			xi=array[ii-1][2];
			xi1=array[ii][2];
			yi=array[12][ii-1];
			yi1=array[12][ii];
			
			break;
		}
	}
	
a=(yi1-yi)/(xi1-xi);
b=yi-(a*xi);
yq=(a*angle)+b;

printf("The lift coefficient is %lf\n", yq);
	
	return(0);
}

 int main() {
	//variable declaration
	int ii;
	double array[12][2], angle, xq, yq, xi1, yi1, xi, yi, a, b;
	FILE *liftcoeff;
	
	function1(liftcoeff, array, ii);
	fliftcoeff(angle, array ,xq, yq, xi1, yi1, xi, yi, a, b, ii); 
	 return(0);
 }