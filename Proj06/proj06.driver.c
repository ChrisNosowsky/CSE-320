 /****************************************************************************
  Chris Nosowsky
 Computer Project #6
 ****************************************************************************/
#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

int main(){
        union sp_item num1; //Professor said so!
        union sp_item num2;
        union sp_item result;
        
        //First 3 tests show you that my program
        //  1.Can perform floating point multiplication with single precision
        //  2.Can represent it in both in real and hex
        //  3.Can perform with different and same signs
        
        //Test 1
        num1.frep = -12.7;
        num2.frep = -0.125;
        printf("TEST 1: Multiplying -12.7 and -0.125 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 2 -> Flipped signs
        num1.frep = 12.7;
        num2.frep = 0.125;
        printf("TEST 2: Multiplying 12.7 and 0.125 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 3 -> Different signs
        num1.frep = -12.7;
        num2.frep = 0.125;
        printf("TEST 3: Multiplying -12.7 and 0.125 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Other test cases --> These align with the ones in project notes
        
        //Test 4
        num1.frep = 1.5;
        num2.frep = 2.0;
        printf("TEST 4: Multiplying 1.5 and 2.0 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 5
        num1.frep = 1.5;
        num2.frep = 1.5;
        printf("TEST 5: Multiplying 1.5 and 1.5 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 6
        num1.frep = 1.5;
        num2.frep = 1.375;
        printf("TEST 6: Multiplying 1.5 and 1.375 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Special Test Cases --> Zero, NaN, Infinity.
        
        
        //Test 7
        num1.frep = INFINITY;
        num2.frep = INFINITY;
        printf("TEST 7: Multiplying INFINITY and INFINITY \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        
        //Test 7.1
        num1.frep = INFINITY;
        num2.frep = -5.023;
        printf("TEST 7.1: Multiplying INFINITY and -5.023 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 8
        num1.frep = NAN;
        num2.frep = NAN;
        printf("TEST 8: Multiplying NAN and NAN \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 8.1
        num1.frep = NAN;
        num2.frep = 4.5;
        printf("TEST 8.1: Multiplying NAN and 4.5 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 9
        num1.frep = 0.0;
        num2.frep = 0.0;
        printf("TEST 9: Multiplying 0.0 and 0.0 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 9.1
        num1.frep = 0.0;
        num2.frep = 0.625;
        printf("TEST 9.1: Multiplying 0.0 and 0.625 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        
        //Other test cases below
        
        //Test 10
        num1.frep = 1.0;
        num2.frep = -1.0;
        printf("TEST 10: Multiplying 1.0 and -1.0 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 11
        num1.frep = 10.5;
        num2.frep = -0.0078125;
        printf("TEST 11: Multiplying 10.5 and -0.0078125 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        
        //Test 12 -> Big numbers test
        num1.frep = 100.3;
        num2.frep = 20.6;
        printf("TEST 12: Multiplying 100.3 and 20.6 \n");
        result.frep = mult(num1.frep, num2.frep);
        printf("Real: %f Hex integer: %08x \n", result.frep, result.irep);
        return 0;   
}