  /****************************************************************************
    Chris Nosowsky
    Computer Project #8
  ****************************************************************************/
 /*---------------------------------------------------------------------------
 Name: main
 Purpose: loop through and test if statements. If condition if satisfied, increase count of a particular register
 at the end of loop, store the registers in the arguments and call printf to print to output stream
 ---------------------------------------------------------------------------*/
            .global main



            .text
main:       push    {lr}

            mov     r4, #0  @ initializing registers to all have 0
            mov     r5, #0
            mov     r6, #0
            mov     r7, #0
            mov     r8, #0
            mov     r9, #0
            mov     r10, #0
loop:       bl      getchar

            cmp     r0, #0
            beq     end
            
            bl      putchar @ calling putchar if not EOF
            add     r4, r4, #1

ifNL:       cmp     r0, #0xA    @ newline test
            bne     endifNL

thenNL:     add     r5,r5, #1

endifNL:

ifWhite:    cmp     r0, #0x20   @ whitespace test
            beq      thenWhite

            cmp     r0, #0x09
            beq      thenWhite

            cmp     r0, #0xA
            bne     endifWhite

thenWhite:  add     r6,r6, #1

endifWhite:

ifArith:    cmp     r0, #0x2F   @ arithmetic test
            beq      thenArith

            cmp     r0, #0x2A
            beq      thenArith

            cmp     r0, #0x2D
            beq      thenArith

            cmp     r0, #0x2B
            bne     endifArith

thenArith:  add     r7,r7, #1

endifArith:

ifDec:      cmp     r0, #0x39   @ decimal test
            bgt     endifDec
            cmp     r0, #0x30
            blt     endifDec

thenDec:    add     r8,r8, #1
            add     r9,r9, #1

endifDec:

ifHexUpp:   cmp     r0, #0x46   @ Hex testing upper set {A-F}
            bgt     endifHexUpp
            cmp     r0, #0x41
            blt     endifHexUpp

thenHexUpp: add     r9,r9, #1

endifHexUpp:

ifHexLow:   cmp     r0, #0x66   @ Hex lower test {a-f}
            bgt     endifHexLow
            cmp     r0, #0x61
            blt     endifHexLow

thenHexLow: add     r9,r9, #1

endifHexLow:


ifLetLow:   cmp     r0, #0x7A   @ Letter lower test {a-z}
            bgt     endifLetLow
            cmp     r0, #0x61
            blt     endifLetLow

thenLetLow: add     r10,r10, #1

endifLetLow:

ifLetHi:    cmp     r0, #0x5A   @ letter upper test {A-Z}
            bgt     endifLetHi
            cmp     r0, #0x41
            blt     endifLetHi
            

thenLetHi:  add     r10,r10, #1

endifLetHi: b       loop

end:
            ldr     r0, =fmt1   @ formatting all of the strings
            mov     r1, r4      @ moving total char to register1
            bl      printf

            ldr     r0, =fmt2
            mov     r1, r5
            bl      printf

            ldr     r0, =fmt3
            mov     r1, r6
            bl      printf

            ldr     r0, =fmt4
            mov     r1, r7
            bl      printf

            ldr     r0, =fmt5
            mov     r1, r8
            bl      printf

            ldr     r0, =fmt6
            mov     r1, r9
            bl      printf

            ldr     r0, =fmt7
            mov     r1, r10
            bl      printf
            
            pop     {lr}    @ clearing the stack(last in first out) by popping
            bx      lr


fmt1:   .asciz  "\nNumber of characters: %d\n"
fmt2:   .asciz  "Number of newlines: %d\n"
fmt3:   .asciz  "Number of whitespace characters: %d\n"
fmt4:   .asciz  "Number of arithmetic operators: %d\n"
fmt5:   .asciz  "Number of decimal digits: %d\n"
fmt6:   .asciz  "Number of hexadecimal digits: %d\n"
fmt7:   .asciz  "Number of letters: %d\n"
