//Guillermo Hernandez & Quim Bolos


#include <stdio.h>
#include <math.h>


int main(int argc, const char * argv[]) {

     // we allocate memory for variables of the number of streamlines(ns) and delta t(t)
     int ns,t;
	 // to perform the loop we need time to be an integer, so we use centiseconds measurement, hence delta t equals 0.1 seconds
	 t=10;
    
     // we ask the user to input the number of streamlines
     printf("Input the number of streamlines:\n");
     scanf("%d", &ns);
	 
	 //We inform the user about the value of t chosen
	 printf("The considered value for delta t is of 0.1 seconds\n");
     
    
     // we create a vector for all y initial values of each streamline  -  yo[ns]
     double yo[ns];
	 //we create a constant - m - which contributes to set an uniform distribution (in y initial values) from -0.75 to 0.75 according to the number of streamlines
     double m=1.5/(ns-1);
	 //we create a value for y - y - that at the moment we consider 0
     double y=0;
	 //we create a constant - s - to start assigning y initial values from -0.75
     double s=-0.75;
	 
	 // we create a loop that calculates a certain amount of y initial values and stores them on a vector - yo[ns]
     int i;
     for (i=0; i<ns; i++){
         // our initial value of y is -0.75
		 y=s;
		 //for the i component of the vector -  yo[ns] - the value assigned is y
         yo[i]=y;
		 //we want - s - to change in each iteration in order to change - y - as well, so we increase the value of - s - with - m -
         s=s+m;
         
        }
     // we create another vector - xo[ns] - for x initial values with the same number of components than the number of streamlines
	 double xo[ns];
	 
	 // with a loop we set the values of each x initial component of the vector according to the number of streamlines
	 int ii;
	 for(ii=0; ii<ns; ii++){
	     // for every streamline the initial value of x is -1
	     xo[ii]=-1;
	    }
	 
	 // we create an array which will contain both x and y initial values of each streamline - zerocoordinates [ns][2] -
	 double zerocoordinates [ns][2];
	 
	 // with a loop we copy the values from - xo[ns] - and - yo[ns] - into - zerocoordinates[ns][2]
	 int j;
	 for (j=0; j<ns; j++){
		 zerocoordinates[j][1]=xo[j];
		 zerocoordinates [j][2]=yo[j];
	    }
	
	 // we allocate memory for the stream file
	 FILE *stream;
	 // with fopen function we create a tecplot file which will start storing the data obtained in following steps 
	 // if the file already exists in the same folder, will be deleted and rewritten
	 stream = fopen("stream.plt","w");
	 // in order to represent the data in tecplot, the file must have an specific format where variables are named right at the start of thr file
	 fprintf(stream,"VARIABLES = \"x\"  \"y\" \n");
	 
	 // we create an array with all the x values and y values - allcoordinates[ns*((2*t)+4)][2] - that we will obtain from integrating along 
	 // all the initial values stored in - zerocoordinates [ns][2] -
	 // the array will have [ns*((2*t)+4)] rows because ns will be the number of times we will have x and y new values (from integrating), 
	 // and then ((2*t)+4) will be the number of new x and y values that we will obtain from each x and y initial values.
	 double allcoordinates[ns*((2*t)+4)][2];
	 // we create the variables for the components of velocity - u - and - v -
	 // we create - x0 - and - y0 - to make easier the syntax of the loop. Those values will store the x and y initial values again
	 double u, v, x0, y0;
	 // we set the value of pi 
	 double pi=4.0*atan(1.0);
	 
	 // we create a loop within another loop, the first one is used to select the desired initial values of x and y we want to integrate
	 int k, kk;
	 for (k=0; k<ns; k++){
	     x0=zerocoordinates[k][1];
		 y0=zerocoordinates[k][2];
		 // for each initial values we are considering a streamline and we want each streamline to be in a different zone
		 // so we plot a new zone for every streamline in our stream tecplot file
		 fprintf(stream,"ZONE T=\"%d\"\n",k);
		 // we also want to plot the x and y initial values in our stream tecplot file
		 fprintf(stream,"%lf %lf",xo[k],yo[k]);
   
		 // the second loop performs numerical integration through the First Order Eurler's Method according to initial values of x and y obtained from the first loop
	     for (kk=0; kk<((2*(t))+4); kk++){
			 // we hardcode the equation 1 of u and v to obtain their values
			 u=1+(x0/(2*pi*((pow(x0, 2))+(pow(y0, 2)))));
		     v=(y0/(2*pi*((pow(x0, 2))+(pow(y0, 2)))));
			 // we hardcode the equation 2 to obtain x and y new values
			 // we also allocate the values of x and y obtained in the - allcoordinates[ns*((2*t)+4)][2] -
			 allcoordinates[kk][1]=x0+(u*t*0.01);
			 allcoordinates[kk][2]=y0+(v*t*0.01);
			 // in order to perform the integration we need the obtained values of x and y to be the new - x0 - and - y0 - within the second loop
			 x0=allcoordinates[kk][1];
		     y0=allcoordinates[kk][2];
			 // in order to perform the loop so values obtained reach the grid of tecplot, we want to keep the integration until x0 equals 1.2
			 if (x0>1.2){
			     break;
			    }
			 // now we want to plot the values obtained into the stream tecplot file through fprintf function
             fprintf(stream," %lf %lf\n",allcoordinates[kk][1],allcoordinates[kk][2]);
	        }
		 
	    }
	
	
	                                                      // EXTENSION EXERCISE
	
	 // we create variable qo to be an x value
	 // we also create vectors - xgrid[101] - and - ygrid[101] - to contain the x and y values of the grid 
	 double qo, xgrid[101], ygrid[101];
	 // we crate variables: 
	 //- ni - (which is the number of points that the gird has in the x axis) 
	 //- nj - (which is the number of points that the gird has in the y axis)
	 //- r - (which is the initial value for both axis)
	 int ni, nj,r;
     nj= 101;
	 ni= 101;
	 r=-1; 
	
	 // we create a loop to set the values that x and y can take in each direction of cartesian coordinates
	 int z;
	 for(z=0;z<nj;z++){
	     qo=r+(0.02*z);
	     xgrid[z]=qo;
	     ygrid[z]=qo;
	    }
	
	 // we allocate memory for the field file
	 FILE *field;
	 // with fopen function we create a tecplot file which will start storing the data obtained in following steps
	 // if the file already exists in the same folder, will be deleted and rewritten
	 field = fopen("field.plt","w");
	 // in order to represent the data in tecplot, the file must have an specific format where variables are named right at the start of thr file
	 fprintf(field,"VARIABLES = \"x\"  \"y\"  \"u\"  \"v\"  \"velocitymagnitude\"\n");
	 fprintf(field,"ZONE I=101 J=101  F=POINT\n");
	 
	 // we create - yfield - and - xfield - which will contain the x and y values obtained from - ygrid[101] - and - xgrid[101] -
	 double yfield, xfield;
	 // we allocate memory for arrays  - vfield[101] - ufield[101] - velocitymagnitude[101] - 
	 // which will contain the components of velocity and the velocity magnitued associated to each value of x and y
	 double vfield[101], ufield[101], velocitymagnitude[101];
	 // again, we create a loop within an other;
	 // the first one sets the value of - yfield - which is the row of the grid
	 
	 int l, h;
	 for (l=0; l<nj; l++){   
	     yfield=ygrid[l];
	   
         // the second one sets the value of - xfield - which is the column of the grid 
		 // and for each combination of - xfield - and - xfield - calculates - ufield[h] - vfield[h] - velocitymagnitude[h] -
	     for (h=0; h<ni; h++){
		     
		     xfield=xgrid[h];
		     // using equation 1 we get the values of u and v and we allocate them in the array
			 ufield[h]=1+(xfield/(2*pi*((pow(xfield, 2))+(pow(yfield, 2)))));
		     vfield[h]=(yfield/(2*pi*((pow(xfield, 2))+(pow(yfield, 2)))));
			 // we calculate the modulus of the components of velocity - velocitymagnitude[101] - and allocate them in the array 
		     velocitymagnitude[h] = sqrt((ufield[h]*ufield[h])+(vfield[h]*vfield[h]));
			 // we print the values of - xfield - yfield - ufield[h] - vfield[h] - velocitymagnitude[h] - in our field tecplot file
		     fprintf(field," %lf %lf %lf %lf %lf\n",xfield, yfield, ufield[h], vfield[h], velocitymagnitude[h]);
     
	        }
	 
	    }
	 // finally we close the files through fclose function
	 fclose(field);
	 fclose(stream);
	
	
	
     return (0);
}