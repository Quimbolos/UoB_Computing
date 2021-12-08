//*******************************************************************
//       SOLUTIONS TO LOOPS EXAMPLE SHEET
//       COPYRIGHT D. POOLE, UOB, 2017
//*******************************************************************

#include<stdio.h>
#include<math.h>

//*******************************************************************
//*******************************************************************
//*******************************************************************

// PRINT DECIMAL EQUIVALENTS
int exercise1 () {

  // Variable declarations
  int denommax=10, denom;
  double dec;

  // Loop and print out decimal equivalent of 1/denom
  // User for loop since we know how many times to do it
  for (denom=1; denom<=denommax; denom=denom+1) {
    dec=1.0/denom;
    printf("1/%2i = %10.8lf\n",denom,dec);
  }

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// USER-INPUT POSITIVE NUMBER ONLY
int exercise2 () {

  // Variable declarations
  double uservalue;

  // Keep going until user inputs positive number
  // User do-while since we want loop to execute at least once
  // but we don't know how many times they will get it wrong
  do {

    // Read-in user number
    printf("Please enter a positive number\n");
    scanf("%lf",&uservalue);

    // Keep going if number is negative
  } while (uservalue < 0.0);

  printf("The positive number you have entered is %lf\n",uservalue);

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// USER-INPUT EVEN NUMBER ONLY
int exercise3 () {

  // Variable declarations
  int uservalue;

  // Keep going until user inputs even number
  // User do-while since we want loop to execute at least once
  // but we don't know how many times they will get it wrong
  do {

    // Read-in user number
    printf("Please enter an even number\n");
    scanf("%i",&uservalue);

    // Use the mod operator - if number%2=0, then is even
  } while (uservalue%2 != 0);
  printf("The even number you have entered is %i\n",uservalue);

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// FIBONACCI
int exercise4 () {

  // Variable declarations
  int usermax, val1, val2, val1old;

  // Read-in user number
  printf("Please enter a number\n");
  scanf("%i",&usermax);

  // Initialise first Fibonacci values
  val1=1;
  val2=1;
  printf(" %i",val1);

  // Keep going until the sum gets beyond a certain value
  while (val2<=usermax) {

    // Print first to avoid the next number (which is beyond limit)
    //  being printed.
    printf(" %i",val2);
    val1old=val1;
    val1=val2;
    val2=val1old+val1;

  }
  printf("\n");

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// E MACLAURIN SERIES
int exercise5 () {

  // Variable declarations
  int usern, i, ifactorial, j;
  double sumtotal;

  // Read-in user number
  printf("Please enter number of series elements\n");
  scanf("%i",&usern);

  // First value of series is 1
  sumtotal=1.0;

  // Loop all the way up to n - "for" loop since we know how many times
  for (i=1; i<=usern; i++){

    // Calculate i! - could do this is a function
    // Do nested loop here to show different counters - use j for inner loop
    ifactorial=1;
    for (j=1; j<=i; j++){
      ifactorial=ifactorial*j;
    }

    // Update power series
    sumtotal=sumtotal+(1.0/ifactorial);

  }

  printf("Approx: %20.15lf\n",sumtotal);
  printf("Real:   %20.15lf\n",exp(1.0));


  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// IS USER-INPUT PRIME
int exercise6 () {

  // Variable declarations
  int usern, ii, nfactors;

  // Read-in user number
  printf("Please enter a number\n");
  scanf("%i",&usern);

  // Prime is only divisible by 1 and itself
  // Use % operator to determine number of divisors
  // For loop to loop over all numbers up to user number
  nfactors=0;
  for(ii=1; ii<=usern; ii++){
     if(usern%ii == 0){
        nfactors=nfactors+1;
     }
  }

  // Tell user whether number is prime
  // Is prime if there are only two factors
  if(nfactors == 2){
    printf("%i IS a prime number\n",usern);
  } else {
    printf("%i IS NOT a prime number\n",usern);
  }

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// ALL PRIMES UP TO 100
int exercise7 () {

  // Variable declarations
  int nn, nfactors, ii;

  // Loop over all numbers up to 100. Only print if it is prime.
  for(nn=1; nn<=100; nn++){

    // Determine whether number is prime
    // Will be prime if only divides by 1 and itself, so has two factors
    nfactors=0;
    for(ii=1; ii<=nn; ii++){
      if(nn%ii == 0){
        nfactors=nfactors+1;
      }
    }

    // Print if only two factors
    if(nfactors == 2){
      printf("%i ",nn);
    }

  }
  printf("\n");

  return(0);
}

//*******************************************************************
//*******************************************************************
//*******************************************************************

// MAIN TO SELECT WHICH EXERCISE TO SOLVE
int main () {

  // Variable declarations
  int exer;

  // Ask user which exercise to perform
  printf("\nWhich exercise would you like to run:\n");
  printf("  1. Decimals\n");
  printf("  2. Positive number\n");
  printf("  3. Even number\n");
  printf("  4. Fibonacci\n");
  printf("  5. Power series\n");
  printf("  6. User-input prime\n");
  printf("  7. Primes up to 100\n");
  scanf("%i",&exer);
  printf("\n");

  // Enter function depending on which exercise to solve
  switch (exer) {
    case 1: 
      exercise1();
      break;
    case 2: 
      exercise2();
      break;
    case 3: 
      exercise3();
      break;
    case 4: 
      exercise4();
      break;
    case 5: 
      exercise5();
      break;
    case 6: 
      exercise6();
      break;
    case 7: 
      exercise7();
      break;
    default: 
      printf("ERROR: only up to exercise 7\n");
      break;
  }

  return(0);
}
