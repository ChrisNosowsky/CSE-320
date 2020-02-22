#include <stdio.h>
#include "/user/cse320/Projects/project05.support.h"

/* 
 * My approach is to find all conversions and test the results.
 * I converted dec, hex, bin, oct multiple times.
 * I also had fail test cases where the result returned 0!
 * Finally I tested zero and other random cases. Still works.
 */

int main() {
    int A = 135;
    int B = -26;
    int I = -15;
    char C[80];
    int result;
    
    //TEST A - Checking all conversions + and -
    result = decode(A, "dec", &C[0] );
    printf("Input: %d Convert to: dec Test A Answer: %s Returned: %d\n", A, C, result);
    result = decode(A, "hex", &C[0] );
    printf("Input: %d Convert to: hex Test A Answer: %s Returned: %d\n", A, C, result);
    result = decode(A, "bin", &C[0] );
    printf("Input: %d Convert to: bin Test A Answer: %s Returned: %d\n", A, C, result);
    result = decode(B, "dec", &C[0] );
    printf("Input: %d Convert to: dec Test A Answer: %s Returned: %d\n", B, C, result);
    result = decode(B, "oct", &C[0] );
    printf("Input: %d Convert to: oct Test A Answer: %s Returned: %d\n", B, C, result);
    result = decode(B, "bin", &C[0] );
    printf("Input: %d Convert to: bin Test A Answer: %s Returned: %d\n", B, C, result);
    result = decode(B, "hex", &C[0] );
    printf("Input: %d Convert to: hex Test A Answer: %s Returned: %d\n", B, C, result);
    result = decode(I, "hex", &C[0] );
    printf("Input: %d Convert to: hex Test A Answer: %s Returned: %d\n\n", I, C, result);
    
    //TEST B - Unsuccessful conversions
    int D = 99999999;
    I = 14;
    char F[80];
    result = decode(D, "suhdude", &F[0] ); //Notice wrong name in 2nd arg.
    printf("Input: %d Convert to: suhdude Test B Answer: %s Returned: %d\n", D, F, result);
    result = decode(I, "Hex", &F[0] ); //Case sensitive. Must be lowercase.
    printf("Input: %d Convert to: Hex Test B Answer: %s Returned: %d\n\n", I, F, result);
     
    A = 011;
    B = 0x7F;
    D = 0;
    int E = -694;
    int G = -0x7F;
    char S[100];
    
    //TEST C - Other Random Tests. Shows it works with 0, -'s and others.
    result = decode(A, "bin", &S[0] );
    printf("Input: %d Convert to: bin Test C Answer: %s Returned: %d\n", A, S, result);
    result = decode(A, "oct", &S[0] );
    printf("Input: %d Convert to: oct Test C Answer: %s Returned: %d\n", A, S, result);
    result = decode(B, "hex", &S[0] );
    printf("Input: %d Convert to: hex Test C Answer: %s Returned: %d\n", B, S, result);
    result = decode(B, "dec", &S[0] );
    printf("Input: %d Convert to: dec Test C Answer: %s Returned: %d\n", B, S, result);
    result = decode(D, "oct", &S[0] );
    printf("Input: %d Convert to: oct Test C Answer: %s Returned: %d\n", D, S, result);
    result = decode(E, "bin", &S[0] );
    printf("Input: %d Convert to: bin Test C Answer: %s Returned: %d\n", E, S, result);
    result = decode(G, "bin", &S[0] );
    printf("Input: %d Convert to: bin Test C Answer: %s Returned: %d\n", G, S, result);
    
    return 0;
}

















