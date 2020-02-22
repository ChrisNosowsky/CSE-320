/****************************************************************************
 Chris Nosowsky
 Computer Project #7
 ****************************************************************************/
#include "/user/cse320/Projects/project07.hardware.h"
void execute();
 /*---------------------------------------------------------------------------
 Name: execute
 Purpose: Updates register file and CPSR based on the ARM processor instructions
 Receive: None
 Return: None
 ---------------------------------------------------------------------------*/
void execute() {
    signal4 rs1 = (IR >> 16) & 0xf; //everything we need
    signal4 rs2 = IR & 0xf;
    signal4 i = (IR >> 25) & 0x1;
    signal4 s = (IR>>20) & 0x1;
    signal4 opcode = (IR >> 21) & 0xf;
    signal4 rd = (IR >> 12) & 0xf;
    signal4 cond = (IR >> 26) & 0x3f;
    signal4 rm = (IR) & 0xf;
    signal4 immediate = (IR) & 0xff; //8 bits
    signal4 other1 = (IR >> 8) & 0xf;
    signal4 other0 = (IR >> 4) & 0xff;
    signal4 C = CPSR >> 29 & 0x1;
    
    signal4 result, operand2, RS1, RS2;
    signal4 determineC;
    read_reg_file(rs1, rs2, &RS1, &RS2);
    if (i != 0x0) { //if i = 1
        operand2 = immediate;
        if (cond != 0x00000038 || other1 != 0x0000) { //legal check
            CPSR = CPSR | 0x1;
            return;
        }

    }
    else { //if i = 0
        operand2 = RS2;
        if (cond != 0x00000038 || other0 != 0x00000000) { //legal check
            CPSR = CPSR | 0x1;
            return;
        }
    }
    //if front is 111000 and other zeros are indeed all zero, then it is legal. Proceed.
    //and
    if ((opcode == 0x0)) {
        result = RS1 & operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE; //b/c we dont care about last two(C and V)
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    //eor
    else if ((opcode == 0x1)) {
        result = RS1 ^ operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    //sub
    else if ((opcode == 0x2)) {
        result = RS1 - operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = (((~(RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || (((result >> 31) & 0x1) && ((~(RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 != (operand2 >> 31) & 0x1) { //opposite sign
                if((operand2 >> 31) & 0x1 == (result >> 31) & 0x1) { //same sign as operand2
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    //rsb
    else if ((opcode == 0x3)) {
        result = operand2 - RS1;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = (((~(RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || (((result >> 31) & 0x1) && ((~(RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 != (operand2 >> 31) & 0x1) { //opposite sign
                if((operand2 >> 31) & 0x1 == (result >> 31) & 0x1) { //same sign as operand2
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
            
        }
    }
    //add
    else if ((opcode == 0x4)) {
        result = RS1 + operand2;
        if (s == 0x1) {
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = ((((RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || ((~(result >> 31) & 0x1) && (((RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 == (operand2 >> 31) & 0x1) { //same sign op's
                if((RS1 >> 31) & 0x1 != (result >> 31) & 0x1) { //operand opposite of result sign
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    //adc
    else if ((opcode == 0x5)) {
        result = RS1 + operand2 + (C & 0x1);
        if (s == 0x1) {
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = ((((RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || ((~(result >> 31) & 0x1) && (((RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 == (operand2 >> 31) & 0x1) { //same sign op's
                if((RS1 >> 31) & 0x1 != (result >> 31) & 0x1) { //operand opposite of result sign
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    //sbc
    else if ((opcode == 0x6)) {
        result = RS1 - operand2 - (~C & 0x1);
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = (((~(RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || (((result >> 31) & 0x1) && ((~(RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 != (operand2 >> 31) & 0x1) { //opposite sign
                if((operand2 >> 31) & 0x1 == (result >> 31) & 0x1) { //same sign as operand2
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    //rsc
    else if ((opcode == 0x7)) {
        result = operand2 - RS1 - (~C & 0x1);
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = (((~(RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || (((result >> 31) & 0x1) && ((~(RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 != (operand2 >> 31) & 0x1) { //opposite sign
                if((operand2 >> 31) & 0x1 == (result >> 31) & 0x1) { //same sign as operand2
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    
    //tst (ands)
    else if ((opcode == 0x8)) {
        result = RS1 & operand2;
        //N bit calculation
        if(s == 0x1) {
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    
    //teq (eors)
    else if ((opcode == 0x9)) {
        result = RS1 ^ operand2;
        if(s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    
    //cmp (subs)
    else if ((opcode == 0xA)) {
        result = RS1 - operand2;
        if(s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = (((~(RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || (((result >> 31) & 0x1) && ((~(RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 != (operand2 >> 31) & 0x1) { //opposite sign
                if((operand2 >> 31) & 0x1 == (result >> 31) & 0x1) { //same sign as operand2
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }
        }
    }
    //cmn (adds)
    else if ((opcode == 0xB)) {
        result = RS1 + operand2;
        if(s == 0x1) {
            //n bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x7FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
            //C Bit Calculation
            determineC = ((((RS1 >> 31) & 0x1) && ((operand2 >> 31) & 0x1)) || ((~(result >> 31) & 0x1) && (((RS1 >> 31) & 0x1) || ((operand2 >> 31) & 0x1)) ));
            if(determineC == 0x00000001) {//carry is 1
                CPSR = CPSR | 0x20000000;
            } 
            else {
                CPSR = CPSR & 0xDFFFFFFE;
            }
            //V Bit Calculation
            if((RS1 >> 31) & 0x1 == (operand2 >> 31) & 0x1) { //same sign op's
                if((RS1 >> 31) & 0x1 != (result >> 31) & 0x1) { //operand opposite of result sign
                    CPSR = CPSR | 0x10000000;
                } //if these two conditions not satisfied, keep at 0(2 and 8 both 0 on v bit)
            }  
        }
    }
    
    //orr
    else if ((opcode == 0xC)) {
        result = RS1 | operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    
    //mov
    else if ((opcode == 0xD)) {
        result = operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    //bic
    else if ((opcode == 0xE)) {
        result = RS1 & ~operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    //mvn
    else if ((opcode == 0xF)) {
        result = ~operand2;
        if (s == 0x1) {
            //N bit calculation
            if((result >> 31) & 0x1 == 1) {
                CPSR = CPSR | 0x80000000;
            }
            else {
                CPSR = CPSR & 0x4FFFFFFE;
            }
            //Z Bit Calculation
            if(~(result | 0x00000000) == 0xFFFFFFFF) { //all zero
                CPSR = CPSR | 0x40000000; //gets Z 
            }
        }
    }
    //if the opcode is not 8-B then we can store the result.
    if((opcode != 0x8) && (opcode != 0x9) && (opcode != 0xA) && (opcode != 0xB)) {
        write_reg_file(rd, result);
    }
    return;
}