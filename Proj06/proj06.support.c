/****************************************************************************
 Chris Nosowsky
 Computer Project #6
 ****************************************************************************/
#include <stdio.h>
#include "/user/cse320/Projects/project06.support.h"

 /*---------------------------------------------------------------------------
 Name: mult
 Purpose: Takes single precision integers and multiplies it
 Receive: Two floating point numbers
 Return: The product of multiplying the two floating point numbers
 ---------------------------------------------------------------------------*/

float mult(float number1, float number2) {
    union sp_item num1; //parts needed for floating pt. THESE ARE WHAT ALLOWS US TO DO THE BITWISE OPERATIONS.
    union sp_item num2;
    union sp_item fraction;
    
    unsigned long long result;
    signed exp1;
    signed exp2;
    float product; //resultant
    num1.frep = number1; //Just our parameter (input values).
    num2.frep = number2;
    
    //This process is indicated in project06 notes #4
    //0xff just masks off our first 8 bits
    exp1 = ((num1.irep >> 23) & 0xff) - 0x7f; //Gets us our true exponent by shifting right 23 to the rightmost of our 32 bit unsigned int
    exp2 = ((num2.irep >> 23) & 0xff) - 0x7f;
    
    if (exp1 == -0x3FE) {
        exp1 = 0;
        num1.frep = 0;
    }
    if (exp2 == -0x3FE) {
        exp2 = 0;
        num2.frep = 0;
    }
    
    //test cases: NaN, Infinity, Zero
    if (num1.irep == 0x7fc00000 || num2.irep == 0x7fc00000) { //NAN case
        product = NAN;
    }
    else if(num1.irep == 0x7f800000 || num2.irep == 0x7f800000) { //Infinity case
        product = INFINITY; //product = 0x7f800000
    }
    else if(num1.irep == 0x00000000 || num2.irep == 0x00000000) { //Zero case
        product = 0x00000000;
    }
    else { // No special cases
        unsigned i = 0;
        unsigned test = 0x00800000;
        unsigned exp_total = (num1.irep & 0x7f800000) - 0x3f800000 + (num2.irep & 0x7f800000);
        //below solves the "48 bit" problem using suggested solution from notes #9
        result = (unsigned long long)((num1.irep & 0x007fffff) + test) *
                (unsigned long long)((num2.irep & 0x007fffff) + test); //multiplying our result!
        
        unsigned bit_32_result = (result>>24);//lose the least significant bits at end ( 24*24bit = 48 bit - 32 bit = lost in precision)
        //Making sure we right shift 24 to mask off the end(least significant) bits
        printf("result: %u \n", bit_32_result);
        printf("test = %u", test);
        while ((bit_32_result & test) != test) { //this figures out how far we need to
            test>>=1;
            i++;
        }
        printf("i = %u", i);
        bit_32_result<<=i; // move however many bits we needed to the left
        i<<=23;
        bit_32_result = bit_32_result - i; //after moving the 32 bit result left to get our  binary point in right spot
        fraction.irep = bit_32_result; //fraction field we will add after the binary point
        
        //grabbing our SIGNIFICANT BIT!! SIGN BIT STATEMENTS BELOW.
        if ((num1.irep >> 31) == (num2.irep >> 31)) { //same sign? Always +
            fraction.irep = 0x0 | (bit_32_result + exp_total); //Keeping it 0 for positive(0000)
        }
        else { //if negative sign then flip bits with the 0x80000000. Negative always(1)
            fraction.irep = 0x80000000 | (bit_32_result + exp_total); //Flipping with the 8(1000) where 1 flips it
        }
        
        //Check if Denormal, if not then return our floating representation.
        if (exp_total == 0x00000000 && fraction.irep == 0x00000000) { //DENORMAL
            product = 0; //processed as zero
        }
        else {
            product = fraction.frep; //gets our answer to floating point representation
        }
    }
    return product;
}