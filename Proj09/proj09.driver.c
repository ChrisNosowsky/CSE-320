#include <stdio.h>
#include "/user/cse320/Projects/project09.support.h"



int main() {
    
    //Test 1: Negate. Errors + Normal
    printf("##################NEGATION##################\n");
    printf("Negation of -2 is: %08x\n", negate(-2));
    printf("Negation of -2 DECIMAL is: %d\n\n", negate(-2));
    
    printf("Negation of -1 is: %08x\n", negate(-1));
    printf("Negation of -1 DECIMAL is: %d\n\n", negate(-1));
    
    printf("Negation of 0 is: %08x\n", negate(0));
    printf("Negation of 0 DECIMAL is: %d\n\n", negate(0));
    
    printf("Negation of 1 is: %08x\n", negate(1));
    printf("Negation of 1 DECIMAL is: %d\n\n", negate(1));
    
    printf("Negation of 2 is: %08x\n", negate(2));
    printf("Negation of 2 DECIMAL is: %d\n\n", negate(2));
    
    printf("Negation of 1024 is: %08x\n", negate(1024));
    printf("Negation of 1024 DECIMAL is: %d\n\n", negate(1024));
    
    printf("Negation of -1024 is: %08x\n", negate(-1024));
    printf("Negation of -1024 DECIMAL is: %d\n\n", negate(-1024));
    
    //LETS FAIL!
    printf("FAILS BELOW\n");
    printf("Negation of 80000000 is: %08x\n", negate(0x80000000));
    printf("Negation of 80000000 DECIMAL is: %d\n\n", negate(0x80000000));
    
    
    //Test 2: Absolute
    printf("##################ABSOLUTE##################\n");
    printf("Abs of 1 is: %08x\n", absolute(1));
    printf("Abs of 1 DECIMAL is: %d\n\n", absolute(1));
    
    printf("Abs of -1 is: %08x\n", absolute(-1));
    printf("Abs of -1 DECIMAL is: %d\n\n", absolute(-1));
    
    printf("Abs of 0 is: %08x\n", absolute(0));
    printf("Abs of 0 DECIMAL is: %d\n\n", absolute(0));
    
    printf("Abs of -50 is: %08x\n", absolute(-50));
    printf("Abs of -50 DECIMAL is: %d\n\n", absolute(-50));
    
    printf("Abs of 99999 is: %08x\n", absolute(99999));
    printf("Abs of 99999 DECIMAL is: %d\n\n", absolute(99999));
    
    printf("Abs of -6736456 is: %08x\n", absolute(-6736456));
    printf("Abs of -6736456 DECIMAL is: %d\n\n", absolute(-6736456));
    
    //Fail Case
    printf("FAILS BELOW\n");
    printf("Abs of 0x80000000 is: %08x\n", absolute(0x80000000));
    printf("Abs of 0x80000000 DECIMAL is: %d\n\n", absolute(0x80000000));
    
    
    //Test 3: Add
    printf("##################ADD##################\n");
    printf("Addtion of 0 and 1 is: %08x\n", add(0,1));
    printf("Addition of 0 and 1 DECIMAL is: %d\n\n", add(0,1));   
 
    
    printf("Addtion of 0 and 0 is: %08x\n", add(0,0));
    printf("Addition of 0 and 0 DECIMAL is: %d\n\n", add(0,0));  
    
    printf("Addtion of 50 and 72 is: %08x\n", add(50,72));
    printf("Addition of 50 and 72 DECIMAL is: %d\n\n", add(50,72)); 
    
    //FAILS
    printf("FAILS BELOW\n");
    printf("Addtion of 0x7fffffff and 1 is: %08x\n", add(0x7fffffff,1));
    printf("Addition of 0x7fffffff and 1 DECIMAL is: %d\n\n", add(0x7fffffff,1));
    
    printf("Addtion of 0x80000000 and -1 is: %08x\n", add(0x80000000,-1));
    printf("Addition of 0x80000000 and -1 DECIMAL is: %d\n\n", add(0x80000000,-1));
    
    
    
    //Test 4: Subs
    printf("##################SUB##################\n");
    printf("Subtraction of 50 and 72 is: %08x\n", sub(50,72));
    printf("Subtraction of 50 and 72 DECIMAL is: %d\n\n", sub(50,72)); 
    
    printf("Subtraction of 1 and -1 is: %08x\n", sub(1,-1));
    printf("Subtraction of 1 and -1 DECIMAL is: %d\n\n", sub(1,-1));
    
    printf("Subtraction of -15 and -15 is: %08x\n", sub(-15,-15));
    printf("Subtraction of -15 and -15 DECIMAL is: %d\n\n", sub(-15,-15));
    
    printf("Subtraction of 0x80000000 and 0x80000001 is: %08x\n", sub(0x80000000,0x80000001));
    printf("Subtraction of 0x80000000 and 0x80000001 DECIMAL is: %d\n\n", sub(0x80000000,0x80000001));
    
    
    printf("Subtraction of 0 and 0 is: %08x\n", sub(0,0));
    printf("Subtraction of 0 and 0 DECIMAL is: %d\n\n", sub(0,0));
    
    
    printf("Subtraction of -600000 and 400000 is: %08x\n", sub(-600000,400000));
    printf("Subtraction of -600000 and 400000 DECIMAL is: %d\n\n", sub(-600000,400000));
    
    printf("FAILS BELOW\n");
    printf("Subtraction of 0x80000000 and 12 is: %08x\n", sub(0x80000000,12));
    printf("Subtraction of 0x80000000 and 12 DECIMAL is: %d\n\n", sub(0x80000000,12));
    
    printf("Subtraction of 0x7fffffff and -109 is: %08x\n", sub(0x7fffffff,-109));
    printf("Subtraction of 0x7fffffff and -109 DECIMAL is: %d\n\n", sub(0x7fffffff,-109));
    
    printf("Subtraction of 0x7fffffff and -1 is: %08x\n", sub(0x7fffffff,-1));
    printf("Subtraction of 0x7fffffff and -1 DECIMAL is: %d\n\n", sub(0x7fffffff,-1));
    
    
    //Test 5: Multiply
    printf("##################MULTIPLY##################\n");
    printf("Multiplication of 0 and 0 is: %08x\n", mul(0,0));
    printf("Multiplication of 0 and 0 DECIMAL is: %d\n\n", mul(0,0));
    
    
    printf("Multiplication of 5 and 5 is: %08x\n", mul(5,5));
    printf("Multiplication of 5 and 5 DECIMAL is: %d\n\n", mul(5,5));
    
    printf("Multiplication of 2000 and 98 is: %08x\n", mul(2000,98));
    printf("Multiplication of 2000 and 98 DECIMAL is: %d\n\n", mul(2000,98));
    
    printf("Multiplication of -25 and -69 is: %08x\n", mul(-25,-69));
    printf("Multiplication of -25 and -69 DECIMAL is: %d\n\n", mul(-25,-69));
    
    printf("Multiplication of 1 and -33 is: %08x\n", mul(1,-33));
    printf("Multiplication of 1 and -33 DECIMAL is: %d\n\n", mul(1,-33));
    
    printf("Multiplication of -696969 and 2 is: %08x\n", mul(-696969, 2));
    printf("Multiplication of -696969 and 2 DECIMAL is: %d\n\n", mul(-696969,2));
    
    printf("Multiplication of 0x7fffffff and 1 is: %08x\n", mul(0x7fffffff,1));
    printf("Multiplication of 0x7fffffff and 1 DECIMAL is: %d\n\n", mul(0x7fffffff,1));
    
    
    printf("Multiplication of 0x80000000 and 0 is: %08x\n", mul(0x80000000,0));
    printf("Multiplication of 0x80000000 and 0 DECIMAL is: %d\n\n", mul(0x80000000,0));
    
    
    printf("FAILS BELOW\n");
    
    printf("Multiplication of 0x80000000 and 5 is: %08x\n", mul(0x80000000,5));
    printf("Multiplication of 0x80000000 and 5 DECIMAL is: %d\n\n", mul(0x80000000,5));
    
    printf("Multiplication of 0x80000000 and -55 is: %08x\n", mul(0x80000000,-55));
    printf("Multiplication of 0x80000000 and -55 DECIMAL is: %d\n\n", mul(0x80000000,-55));
    
    printf("Multiplication of 0x80000000 and 0x80000000 is: %08x\n", mul(-2147483648,-2147483648));
    printf("Multiplication of 0x80000000 and 0x80000000 DECIMAL is: %d\n\n", mul(0x80000000,0x80000000));
     
    printf("Multiplication of 0x7fffffff and 5 is: %08x\n", mul(0x7fffffff,5555));
    printf("Multiplication of 0x7fffffff and 5 DECIMAL is: %d\n\n", mul(0x7fffffff,5555));
    
    
    printf("##################DIVIDE##################\n");
    printf("Division of 5 and 5 is: %08x\n", divide(5,5));
    printf("Division of 5 and 5 DECIMAL is: %d\n\n", divide(5,5));
    
    printf("Division of -1 and 2 is: %08x\n", divide(-1,2));
    printf("Division of -1 and 2 DECIMAL is: %d\n\n", divide(-1,2));    
 
    printf("Division of 0 and 5 is: %08x\n", divide(0,5));
    printf("Division of 0 and 5 DECIMAL is: %d\n\n", divide(0,5));
    
    printf("Division of -16 and -5 is: %08x\n", divide(-16,-5));
    printf("Division of -16 and -5 DECIMAL is: %d\n\n", divide(-16,-5));
    
    printf("Division of 5678 and 128 is: %08x\n", divide(5678,128));
    printf("Division of 5678 and 128 DECIMAL is: %d\n\n", divide(5678,128));
    
    
    printf("FAILS BELOW\n");
    printf("Division of 5 and 0 is: %08x\n", divide(5,0));
    printf("Division of 5 and 0 DECIMAL is: %d\n\n", divide(5,0)); 
    
    
    printf("##################POWER##################\n");
    printf("Power of 2 to the 3 is: %08x\n", power(2,3));
    printf("Power of 2 to the 3 DECIMAL is: %d\n\n", power(2,3));
    
    printf("Power of 5 to the 5 is: %08x\n", power(5,5));
    printf("Power of 5 to the 5 DECIMAL is: %d\n\n", power(5,5));
    
    printf("Power of 0 to the 420 is: %08x\n", power(0,420));
    printf("Power of 0 to the 420 DECIMAL is: %d\n\n", power(0,420));
    
    printf("Power of 1 to the 420 is: %08x\n", power(1,420));
    printf("Power of 1 to the 420 DECIMAL is: %d\n\n", power(1,420));
    
    printf("Power of -1 to the 420 is: %08x\n", power(-1,420));
    printf("Power of -1 to the 420 DECIMAL is: %d\n\n", power(-1,420));
    
    printf("Power of 4 to the 3 is: %08x\n", power(4,3));
    printf("Power of 4 to the 3 DECIMAL is: %d\n\n", power(4,3));
    
    printf("Power of -4 to the 3 is: %08x\n", power(-4,3));
    printf("Power of -4 to the 3 DECIMAL is: %d\n\n", power(-4,3));
    
    printf("Power of 4 to the -3 is: %08x\n", power(4,-3));
    printf("Power of 4 to the -3 DECIMAL is: %d\n\n", power(4,-3));
    
    printf("Power of 2 to the 30 is: %08x\n", power(2,30));
    printf("Power of 2 to the 30 DECIMAL is: %d\n\n", power(2,30));
    
    printf("FAILS BELOW\n");
    printf("Power of 0 to the 0 is: %08x\n", power(0,0));
    printf("Power of 0 to the 0 DECIMAL is: %d\n\n", power(0,0));
    
    printf("Power of 2 to the 31 is: %08x\n", power(2,31));
    printf("Power of 2 to the 31 DECIMAL is: %d\n\n", power(2,31));
    
    printf("Power of -5 to the 999999999 is: %08x\n", power(-5,999999999));
    printf("Power of -5 to the 999999999 DECIMAL is: %d\n\n", power(-5,999999999));
    
    printf("##################FACTORIAL##################\n");
    printf("Factorial of 2 is: %08x\n", factorial(2));
    printf("Factorial of 2  is DECIMAL is: %d\n\n", factorial(2));
    
    printf("Factorial of 4 is: %08x\n", factorial(4));
    printf("Factorial of 4  is DECIMAL is: %d\n\n", factorial(4));
    
    printf("Factorial of 0 is: %08x\n", factorial(0));
    printf("Factorial of 0  is DECIMAL is: %d\n\n", factorial(0));
    
    printf("FAILS BELOW\n");
    printf("Factorial of -6 is: %08x\n", factorial(-6));
    printf("Factorial of -6  is DECIMAL is: %d\n\n", factorial(-6));
    
    printf("Factorial of -696969 is: %08x\n", factorial(-696969));
    printf("Factorial of -696969  is DECIMAL is: %d\n\n", factorial(-696969));
    
    printf("Factorial of 15 is: %08x\n", factorial(15));
    printf("Factorial of 15  is DECIMAL is: %d\n\n", factorial(15));
    
    
    printf("Neg: %08x\n", negate(-35));
    printf("Neg: %d\n\n", negate(-35));
    
        printf("Neg: %08x\n", negate(12345678));
    printf("Neg: %d\n\n", negate(12345678));
    
        printf("Neg: %08x\n", negate(6789));
    printf("Neg: %d\n\n", negate(6789));
    
        printf("Neg: %08x\n", negate(0));
    printf("Neg: %d\n\n", negate(0));
    
    
}