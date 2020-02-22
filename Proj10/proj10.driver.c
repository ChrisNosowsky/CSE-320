  /****************************************************************************
    Chris Nosowsky
    Computer Project #10
  ****************************************************************************/
/******************************************************************************
   The C string library
******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "/user/cse320/Projects/project10.support.h"
/*-----------------------------------------------------------------------------
   Purpose:  Demonstrate selected operations from the C string library
 Comparing it against the five arm assembly languages I wrote in my support.s file
-----------------------------------------------------------------------------*/

int main()
{
  const int MAX = 80;
  const char A[] = "tiger",B[] = "apples", C[] = "apple",
          D[]="ZOINK", E[]="hey", F[]="letter", G[]="jJjlKsasd";
  char I[MAX];
  char X[] = "Testing123";
  char Y[] = "tupac";
  char Z[] = "hello";

  printf( "Number of characters in A: %d\n", strlen(A) );
  printf( "Number of characters in A MY FUNCTION: %d\n\n", length(A) );
  printf( "Number of characters in B: %d\n", strlen(B) );
  printf( "Number of characters in B MY FUNCTION: %d\n\n", length(B) );
  printf( "Number of characters in C: %d\n", strlen(C) );
  printf( "Number of characters in C MY FUNCTION: %d\n\n", length(C) );
  printf( "Number of characters in D: %d\n", strlen(D) );
  printf( "Number of characters in D MY FUNCTION: %d\n\n", length(D) );
  printf( "Number of characters in E: %d\n", strlen(E) );
  printf( "Number of characters in E MY FUNCTION: %d\n\n", length(E) );
  printf( "Number of characters in F: %d\n", strlen(F) );
  printf( "Number of characters in F MY FUNCTION: %d\n\n", length(F) );
  printf( "Number of characters in G: %d\n", strlen(G) );
  printf( "Number of characters in G MY FUNCTION: %d\n\n", length(G) );
  
  strcpy( I, A );
  printf( "Copied A to I; I now contains: %s\n", I );
  copy(I,A);
  printf( "Copied A to I; I now contains MY FUNCTION: %s\n\n", I );
  
  strcpy( I, C );
  printf( "Copied C to I; I now contains: %s\n", I );
  copy(I,C);
  printf( "Copied C to I; I now contains MY FUNCTION: %s\n\n", I );
  
  strcpy( I, F );
  printf( "Copied F to I; I now contains: %s\n", I );
  copy(I,F);
  printf( "Copied F to I; I now contains MY FUNCTION: %s\n\n", I );
  
  strcpy( I, E );
  printf( "Copied E to I; I now contains: %s\n", I);
  copy(I,E);
  printf( "Copied E to I; I now contains MY FUNCTION: %s\n\n", I);
  
  strcpy( X, Y );
  printf( "Copied Y to X; X now contains: %s\n", X);
  copy(X,Y);
  printf( "Copied Y to X; X now contains MY FUNCTION: %s\n\n", X);
  printf( "TESTING Y TO SEE THAT IT DOESN'T GET CHANGED: %s\n\n", Y);
  
  strcpy( Z, X );
  printf( "Copied X to Z; Z now contains: %s\n", Z);
  copy(Z,X);
  printf( "Copied X to Z; Z now contains MY FUNCTION: %s\n\n", Z);
  printf( "TESTING X TO SEE THAT IT DOESN'T GET CHANGED: %s\n\n", X);
  
  
  strcat( I, C );
  printf( "Appended C to I; I now contains: %s\n", I );
  append(I,C);
  printf( "Appended C to I; I now contains MY FUNCTION: %s\n\n", I );
  
  
  strcat( I, A );
  printf( "Appended A to I; I now contains: %s\n", I );
  append(I,A);
  printf( "Appended A to I; I now contains MY FUNCTION: %s\n\n", I );
  
  strcat( I, B );
  printf( "Appended B to I; I now contains: %s\n", I );
  append(I,B);
  printf( "Appended B to I; I now contains MY FUNCTION: %s\n\n", I );
  
  
  char * result = duplicate(A);
  printf( "Location of A: %p\n", &A);
  printf( "Location of duplicated A (SHOULD BE DIFFERENT ADDRESS): %p\n", result);
  printf( "Duplicate of A MY FUNCTION: %s\n", result);
  printf( "Comparing to Original: %d\n\n", strcmp(A, result));
  
  result = duplicate(B);
  printf( "Location of B: %p\n", &B);
  printf( "Location of duplicated B (SHOULD BE DIFFERENT ADDRESS): %p\n", result);
  printf( "Duplicate of B MY FUNCTION: %s\n", result);
  printf( "Comparing to Original: %d\n\n", strcmp(B, result));
  
  
  result = duplicate(C);
  printf( "Location of C: %p\n", &C);
  printf( "Location of duplicated C (SHOULD BE DIFFERENT ADDRESS): %p\n", result);
  printf( "Duplicate of C MY FUNCTION: %s\n", result);
  printf( "Comparing to Original: %d\n\n", strcmp(C, result));
  
  result = duplicate(D);
  printf( "Location of D: %p\n", &D);
  printf( "Location of duplicated D (SHOULD BE DIFFERENT ADDRESS): %p\n", result);
  printf( "Duplicate of D MY FUNCTION: %s\n", result );
  printf( "Comparing to Original: %d\n\n", strcmp(D, result));
  
  
  printf("DIFFERENCE IN NUMBERS DOESN'T MATTER. SIGN SIMILARITY MATTERS ONLY BELOW!\n");
  printf( "Comparing B to D: %d\n", strcmp(B, D) );
  printf( "Comparing B to D MY FUNCTION: %d\n\n", compare(B, D) );
  
  printf( "Comparing D to B: %d\n", strcmp(D, B) );
  printf( "Comparing D to B MY FUNCTION: %d\n\n", compare(D, B) );
  
  printf( "Comparing B to C: %d\n", strcmp(B, C) );
  printf( "Comparing B to C MY FUNCTION: %d\n\n", compare(B, C) );
  
  printf( "Comparing B to B: %d\n", strcmp(B, B) );
  printf( "Comparing B to B MY FUNCTION: %d\n\n", compare(B, B) );
  
  printf( "Comparing F to F: %d\n", strcmp(F, F) );
  printf( "Comparing F to F MY FUNCTION: %d\n\n", compare(F, F) );
  
  printf( "Comparing A to F: %d\n", strcmp(A, F) );
  printf( "Comparing A to F MY FUNCTION: %d\n\n", compare(A, F) );
}

