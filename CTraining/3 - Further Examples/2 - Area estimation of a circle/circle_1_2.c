#include <stdio.h>
#include <math.h>

int main()
{
  /* VARIABLE DECLARATIONS */
  FILE *fid;
  int ii, jj, Nelem;
  double sideLength, radius, xc, yc, rc, areaReal, dx, pi, approxarea;

  /* USER INPUT */
  printf("Please input a value for the number of elements in each direction:\n");
  scanf("%i",&Nelem);

  /* CONSTANTS */
  pi=4.0*atan(1.0);
  sideLength=10.0;
  radius=5.0;
  areaReal=pi*pow(radius,2.0);

  /* OPEN TECPLOT FILE FOR READING */
  fid=fopen("circle.plt","w");

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
         fprintf(fid,"%f %f\n",xc,yc);
       }
     }
  }

  /* PRINT FINAL ANSWER TO USER */
  printf("Real area:   %lf\n",areaReal);
  printf("Approx area: %lf\n",approxarea);

  fclose(fid);

  return(0);
}
