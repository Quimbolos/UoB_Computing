#include <stdio.h>
#include <math.h>

int main()
{
  /* VARIABLE DECLARATIONS */
  FILE *fid;
  int ii, jj, Nelem;
  double sideLength, radius, xc, yc, rc, areaReal, dx, pi;
  double approxarea , testexit, minerror;

  /* USER INPUT */
  printf("Please input a value for the minimum error (e.g. 0.01):\n");
  scanf("%lf",&minerror);

  /* CONSTANTS */
  pi=4.0*atan(1.0);
  sideLength=10.0;
  radius=5.0;
  areaReal=pi*pow(radius,2.0);
  Nelem=0;

  /* LOOP OVER DIFFERENT N TO DETERMINE MINIMUM ONE NEEDED */
  do{

    Nelem=Nelem+1;
    approxarea=0.0;
    dx=sideLength/Nelem;

    /* LOOP OVER EACH ROW AND COLUMN TO CHECK WHETHER EACH 
       CENTRE OF SQUARE IS INSIDE OR OUTSIDE CIRCLE */
    for (jj=1; jj<=Nelem; jj++){
      yc=(-sideLength/2)+dx/2+((jj-1)*dx);
      for (ii=1; ii<=Nelem; ii++) {
        xc=(-sideLength/2)+dx/2+((ii-1)*dx);

       /* CALCULATE CENTRE DISTANCE */
       rc=sqrt((xc*xc)+(yc*yc));

       /* CHECK WHETHER CENTRE IS IN OR OUT */
        if (rc <= radius){
          approxarea=approxarea+(dx*dx);
        }
      }
    }
    testexit=fabs(areaReal-approxarea)/areaReal;

  /* KEEP GOING WHILE ERROR IS OUTSIDE TOLERANCE */
  } while (testexit > minerror);

  printf("Number of elements required is: %i\n",Nelem);
  printf("Real area:   %lf\n",areaReal);
  printf("Approx area: %lf\n",approxarea);

  return(0);
}
