  /****************************************************************************
    Chris Nosowsky
    Computer Project #9
  ****************************************************************************/
/*---------------------------------------------------------------------------
 Name: negate
 Purpose: Takes a number and complements/negates it
 Receive: integer N, the number to negate
 Return: -N, the negated number
---------------------------------------------------------------------------*/
            .global     negate
            
negate:
            push    {r4, r5, r6, r7, lr}
            mov     r4, r0
            
            
            adds     r5, r5, #-1
            
            smull     r6, r7, r4, r5        @ never would be overflow so no bvs needed
valid:
            mov     r0, r6
            b       done
            
done:
            pop     {r4, r5, r6, r7, lr}
            bx      lr



/*---------------------------------------------------------------------------
 Name: absolute
 Purpose: Takes a number and returns the absolute value of that number
 Receive: integer N, the number to take the absolute value
 Return: abs(N), the absolute value of N
 ---------------------------------------------------------------------------*/
            .global     absolute

            .text
absolute:
            push    {r4, r5, r6, r7, lr}
            mov     r4, r0
            
            cmp     r0, #0
            blt     neg

            b       done2       @ if positive, leave it alone
neg:
            adds     r5, r5, #-1    @ if negative, then go in here and it will change to positive

            smull     r6, r7, r4, r5

valid2:
            mov     r0, r6
            mov     r1, r7
            b       done2
            
done2:
            pop     {r4, r5, r6, r7, lr}
            bx      lr


/*---------------------------------------------------------------------------
 Name: add
 Purpose: Adds two numbers to get a result that gets returned
 Receive: integers a,b. The numbers to add
 Return: The result of integers a+b
 ---------------------------------------------------------------------------*/
            .global     add
            
            .text
add:
            push    {r4, r5, r6, lr}
            mov     r4, r0
            mov     r5, r1
            
            adds    r6, r4, r5
            
            bvs     error3
valid3:
            mov     r0, r6
            b       done3
error3:      
            mov     r0, #0x80000000
            
done3:
            pop     {r4, r5, r6, lr}
            bx      lr





/*---------------------------------------------------------------------------
 Name: sub
 Purpose: Subtracts two numbers and returns the result
 Receive: integers a,b
 Return: integer of a-b
 ---------------------------------------------------------------------------*/
            .global     sub
            
            .text
sub:
            push    {r4, r5, r6, lr}
            mov     r4, r0
            mov     r5, r1
            
            subs    r6, r4, r5
            
            bvs     error4
valid4:
            mov     r0, r6
            b       done4
error4:      
            mov     r0, #0x80000000
            
done4:
            pop     {r4, r5, r6, lr}
            bx      lr



/*---------------------------------------------------------------------------
 Name: mul
 Purpose: Multiplies two numbers to get a product
 Receive: integers a,b
 Return: integer product of a*b
 ---------------------------------------------------------------------------*/
@ need to do error checking
            .global     mul
            
            .text
mul:
            push    {r4, r5, r6, r7, lr}
            mov     r4, r0
            mov     r5, r1
            
            smull   r6, r7, r4, r5

            cmp     r6, #0
            blt     negi

            cmp     r7, #0x00000000
            bne     error5
            
            b       valid5
negi:
            cmp     r7, #0xffffffff
            bne     error5
            
            b       valid5
valid5:
            mov     r0, r6
            b       done5
error5:      
            mov     r0, #0x80000000
            
done5:
            pop     {r4, r5, r6, r7, lr}
            bx      lr



/*---------------------------------------------------------------------------
 Name: divide
 Purpose: Takes two numbers and divides them and returns the quotient
 Receive: integers a,b, the numbers to divide out
 Return: integer quotient of a/b
 ---------------------------------------------------------------------------*/
            .global     divide
 @ No overflow can occur for division           
            .text
divide:
            push    {r4, r5, r6, r7, lr}
            mov     r4, r0
            mov     r5, r1

            cmp     r5, #0
            beq     error6
            
            sdiv    r7, r4, r5
            
valid6:
            mov     r0, r7
            b       done6
error6:      
            mov     r0, #0x80000000
            
done6:
            pop     {r4, r5, r6, r7, lr}
            bx      lr



/*---------------------------------------------------------------------------
 Name: power
 Purpose: Takes two arguments, argument 1 is a number and argument 2 is a number that argument will be raised to the power by
 Receive: integers a,b
 Return: the integer result of a^b
 ---------------------------------------------------------------------------*/
            .global     power
            
            .text
power:
            push    {r4, r5, r6, r7, lr}
            mov     r4, r0
            mov     r5, r1

if:         cmp     r4, r5      @ compare r4 and r5. if equal then check if zero. if so, error it. Cannot have 0^0
            beq     then

            b       end

then:
            cmp     r4, #0
            beq     error7

end:
            cmp     r5, #1
            beq     done7

            cmp     r4, #1      @ if the first arg is 1, it will be 1 always
            beq     done7
            
            cmp     r4, #0      @ if 0, always 0 no matter what power raised by
            beq     zero
            
            cmp     r5, #0      @ if 0, always 0 no matter what power raised by
            blt     zero

            mov     r6, r4

loopity:
            sub     r5, r5, #1
            cmp     r5, #0
            beq     valid7

            smull   r6, r7, r6, r4
            
            cmp     r6, #0
            blt     neg1
            
            cmp     r7, #0x00000000
            bne     error7

            b       loopity
 
neg1:
            cmp     r7, #0xffffffff
            bne     error7
            
            b       loopity
            

valid7:
            mov     r0, r6
            b       done7
error7:      
            mov     r0, #0x80000000
            b       done7

zero:
            mov     r0, #0x00000000
            b       done7
            
done7:
            pop     {r4, r5, r6, r7, lr}
            bx      lr


/*---------------------------------------------------------------------------
 Name: factorial
 Purpose: recursively multiplies the number times the number subtracted by 1 and so on
 Receive: integer N, the number to take the factorial by
 Return: integer result of the factorial
 ---------------------------------------------------------------------------*/

            .global     factorial
            
            .text
factorial:
            push    {r4, lr}
            mov     r4, r0
            
            cmp     r0, #0      @ if the factorial is negative
            blt     error8

            cmp     r0, #0      @ if r0 is not 0, loop it
            bne     loopit

            mov     r0, #1      
            b       done8
loopit:
            subs    r0, r0, #1  @ every loop you subtract 1. So it would be ex: 5-1 = 4
            bl      factorial   @ recursively call factorial function

            mov     r1, r4      @ moving my r4 that holds the n to r1. r0 will have n-1
            smull   r0, r1, r0, r1  @ so when we multiply, its n * n-1

            cmp     r1, #0x00000000 @ since factorial will always be pos, we only compare this
            bne     error8
 

done8:
            pop     {r4, lr}
            bx      lr

error8:
            mov     r0, #0x80000000
            b       done8


