#include "/user/cse320/Projects/project05.support.h"

//Helper function for decode's second arg.
int compare_strings(char *s1, const char *s2) {
    int i = 0;
    while(s1[i] == s2[i]) {
        if(s1[i] == '\0' && s2[i] == '\0')
            break;
        i++;
    }
    return s1[i]-s2[i];
}

//Helper function used for purpose of base conversion
char set_check(int num) 
{ 
    if (num >= 0 && num <= 9) 
        return num + '0'; 
    else //for the hex's
        return (num - 10) + 'A'; //Reversed from proj handout.
} 


int decode (int val, const char conv[], char store[]) {
    int i = 1;
    int base;

    if (val < 0) { //checks if negative or positive value for first argument.
        store[0] = '-';
        val = val - (val*2);
    }
    else if (val > 0)
        store[0] = '+';
    else { //if zero then just end it here.
        store[0] = '+';
        store[1] = '0';
        store[2] = '\0';
        return 1;
    }
   
    int resultdec = compare_strings("dec", conv); //test for if statements since
    int resulthex = compare_strings("hex", conv); //i can't use c lib functions
    int resultbin = compare_strings("bin", conv);
    int resultoct = compare_strings("oct", conv);
    
    if (resultdec == 0) //Check to see if right argument name given.
        base = 10;
    else if (resulthex == 0)
        base = 16;
    else if (resultbin == 0)
        base = 2;
    else if (resultoct == 0)
        base = 8;
    else {
        store[0] = '\0';
        return 0;
    }
     
    int j = 0;
    char tempBin[32]; //temporary. Will be easier for me.
    while(val > 0) { //Repeated division
        tempBin[j] = set_check(val % base);
        j++;
        val /= base;
    }
    for (int x = j-1; x>=0; x--) { //un-reverses and stores in the character array.
        store[i] = tempBin[x];
        i++;
    }
    store[i] = '\0'; //Null terminates. Must include.
    return 1; //If reached that means we converted successfully.
}
