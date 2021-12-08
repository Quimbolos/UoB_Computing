#include <stdio.h> 
#include <math.h>
int main() {
//variable declarations
 FILE *zerod, *fived, *tend, *tecFile;
 int ii;
 double location, Cp;
 
  printf("zerod\n");
  
//open file 1
 zerod=fopen("naca23015_00degs(1).txt","r");
//open file for reading
 tecFile=fopen("tecFormat.plt", "w");
 fprintf(tecFile,"VARIABLES = \"x\"  \"Cp\"\n");
 fprintf(tecFile,"ZONE T=\"zerod\"\n");
 //continue if file 1 opens ok
  if(zerod!=NULL){
    //read to end of file 1
    while(feof(zerod)==0) {
      fscanf(zerod, "%lf  %lf", &location, &Cp);
		//print location and Cp values
		printf("%lf  %lf\n",location, Cp);
	    fprintf(tecFile,"%lf %lf\n", location, Cp);
	  }
	  
   fclose(zerod);
   
  }
//warn the user
  else {
   printf("Could not open file 1!\n");
  }
  
  printf("fived\n");
  
  //open file 2
 fived=fopen("naca23015_05degs(1).txt","r");
 //open file for reading


         fprintf(tecFile,"ZONE T=\"fived\"\n");
 //continue if file 2 opens ok
  if(fived!=NULL){
    //read to end of file 2
    while(feof(fived)==0) {
      fscanf(fived, "%lf  %lf", &location, &Cp);
		//print location and Cp values
		printf("%lf  %lf\n",location, Cp);
		fprintf(tecFile,"%lf %lf\n", location, Cp);
		
	  }
	 
   fclose(fived);
   
   
  }
//warn the user
  else {
   printf("Could not open file 2!\n");
  }
  
  printf("tend\n");
  
  //open file 3
 tend=fopen("naca23015_10degs(1).txt","r");
 

         fprintf(tecFile,"ZONE T=\"tend\"\n");
 //continue if file 3 opens ok
  if(fived!=NULL){
    //read to end of file 3
    while(feof(tend)==0) {
      fscanf(tend, "%lf  %lf", &location, &Cp);
		//print location and Cp values
		printf("%lf  %lf\n",location, Cp);
		fprintf(tecFile,"%lf %lf\n", location, Cp);
		 
	  }
	  
   fclose(tend);
   
  }
//warn the user
  else {
   printf("Could not open file 3!\n");
  }
fclose(tecFile);


return(0);
}