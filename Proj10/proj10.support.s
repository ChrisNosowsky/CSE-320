  /****************************************************************************
    Chris Nosowsky
    Computer Project #10
  ****************************************************************************/
/*---------------------------------------------------------------------------
 Name: length
 Purpose: Returns the char length of the received string
 Receive: string source
 Return: integer denoting the number of characters in string
---------------------------------------------------------------------------*/
                .global     length

length:
                push    {r4, r5, lr}
                
                mov     r4, #0          @ our counter

loop:          
                ldrb    r5, [r0, r4]
                strb    r5, [r0, r4]
                
                cmp     r5, #0          @ check if end of char--> null byte
                beq     end

                adds    r4, r4, #1      @ if not null byte, add and loop
                b       loop
end:
                mov     r0, r4          @ return counter count, aka length
                pop     {r4, r5, lr}
                bx      lr


/*---------------------------------------------------------------------------
 Name: copy
 Purpose: Copies source string into destination
 Receive: string dest, string source
 Return:
---------------------------------------------------------------------------*/
                .global     copy

copy:
                push    {r4, r5, r6, lr}
                mov     r4, #0              @ initialize counters for both dest and source
                mov     r6, #0

loopity2:       
                ldrb    r5, [r1, r6]        @ load r1 and store into r0, our dest.
                strb    r5, [r0, r4]
                cmp     r5, #0              @ check for null byte, if not proceed by adding counters and looping
                bne     proceed

endend:
                pop     {r4, r5, r6, lr}
                bx      lr

proceed:
                adds    r4, r4, #1
                adds    r6, r6, #1
                b     loopity2

/*---------------------------------------------------------------------------
 Name: append
 Purpose: appends source to end of destination
 Receive: string dest, string source
 Return:
---------------------------------------------------------------------------*/
                .global     append

append:
                push    {r4, r5, r6, lr}
                mov     r4, #0              @ intialize counters
                mov     r6, #0
loopit1:
                ldrb    r5, [r0, r4]
                cmp     r5, #0              @ compare our char to null byte
                bne     notend              @ if not null byte, add r4 counter and loop
               
loopit2:
                ldrb    r5, [r1, r6]        @ load our source and store it into dest with offset of what we calculated above
                strb    r5, [r0, r4]        @ so offset r4 is end of first string!
                cmp     r5, #0
                bne     notend2

endit1:
                pop     {r4, r5, r6, lr}
                bx      lr
notend:
                adds    r4, r4, #1
                b       loopit1
notend2:
                adds   r4, r4, #1
                adds   r6, r6, #1
                b      loopit2
                


/*---------------------------------------------------------------------------
 Name: duplicate
 Purpose: duplicates a string into a new memory address
 Receive: string source
 Return: address of the duplicated string
---------------------------------------------------------------------------*/
                .global     duplicate   

duplicate:
                push    {r4, r6, r8, r9, r10, lr}
                mov     r6, r0
                
                bl      length          @ calling length to retrieve the amount to allocate
                mov     r4, r4          @ putting length in r0
                bl      malloc          @ could also call copy
                mov     r8, r0
                mov     r10, #0         @ an offset counter for going through every char

loop5:
                ldrb    r9, [r6, r10]   @ loading our source and storing it
                strb    r9, [r0, r10]   
                add     r10, r10, #1    @ advancing offset count so we can load next char
                subs    r4, r4, #1
                cmp     r4, #0
                bne     loop5           @ if not end (null byte)
                b       end5

 end5:
                mov     r0, r8
                pop     {r4, r6, r8, r9, r10, lr}
                bx      lr




/*---------------------------------------------------------------------------
 Name: compare
 Purpose: Compares two strings
 Receive: string source1, string source2
 Return: Integer result of comparing two strings. Equal strings returns 0,
 source 1 less then source2 returns negative integer and
 source1 greater then source2 returns positive integer
---------------------------------------------------------------------------*/

                .global     compare

compare:
                push    {r4, r5, r6, lr}
                mov     r4, #0
step1:
                ldrb    r5, [r0, r4]        @ start with offset 0 and go up (looks at every char in r0)
                ldrb    r6, [r1, r4]        @ start with offset 0 and go up (looks at every char in r1)
                

step2:
                cmp     r5, r6              @ if source1 less than source2, return negative
                blt     neg
                cmp     r5, r6              @ if source1 greater then source2, return positive
                bgt     pos
                cmp     r5, r6              @ if source1 same as source2, return zero
                bne     ends
                cmp     r5, #0
                beq     zero
                cmp     r5, #0              @ if we reached null byte, end it
                beq     ends
                adds    r4, r4, #1          @ if not null, add and repeat loop
                b       step1
neg:
                mov     r0, #-1
                b       ends
pos:
                mov     r0, #1
                b       ends
zero:
                mov     r0, #0
                b       ends

ends:
                pop     {r4, r5, r6, lr}
                bx      lr
