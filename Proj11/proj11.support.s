  /****************************************************************************
    Chris Nosowsky
    Computer Project #11
  ****************************************************************************/
/*---------------------------------------------------------------------------
 Name: search
 Purpose: Searches the player in the table
 Receive: pointer to a table, pointer to pointer to player and jersey number to locate
 Return: 1 if found, 0 if not found
---------------------------------------------------------------------------*/


            .global     search
            .text
            .balign     4

search:
            push    {r4, r5, r6, r7, r8, r9, r10, lr}
            mov     r10, r2
            mov     r4, r0          @ table
            mov     r5, r1          @ jersey to search
            

            ldrh    r6, [r0, #2]    @ count
            ldr     r7, [r0, #4]    @ player mem
            mov     r8, #1          @ index counter

loopity1:
            cmp     r6, r8          @ compare table 
            blt     end

            ldrh    r9, [r7]        @ might not need +0; this is jersey #
            cmp     r9, r5          @ compares to input jersey #
            beq     found           @ if equal, we found it.

            cmp     r9, r5          @ since it is ordered, we compare it this way
            bgt     end


            add     r8, r8, #1      @ increment count
            add     r7, r7, #44     @ next player
          
            b       loopity1 
            
found:
            mov     r0, #1
            str     r7, [r2]
            
            pop     {r4, r5, r6, r7, r8, r9, r10, lr}
            bx      lr
end:
            mov     r0, #0
            str     r7, [r2]
            pop     {r4, r5, r6, r7, r8, r9, r10, lr}
            bx      lr



/*---------------------------------------------------------------------------
 Name: delete
 Purpose: Delete a player from the table if the player exists
 Receive: pointer to a table and jersey number to be deleted
 Return: 1 if deleted, 0 if not deleted
---------------------------------------------------------------------------*/
            .global     delete
            .data
X:          .word       0

            .text
            .balign 4

delete:
            push    {r4, r5, r6, r7, r8, r9, r10, lr}
            mov     r10, #44
            ldrh    r6, [r0, #2]    @ count
            mov     r4, r0          @ table
            mov     r5, r1          @ jersey to search
            ldr     r2, =X          @ four bytes assigned for third arg
            bl      search
            
            mov     r7, r0
            ldr     r8, [r2]

            cmp      r7, #0         @ compare r7, the result of search (we find or not?)
            beq      end2           @ if not found, delete failed

            ldr      r9, [r4, #4]   @ capacity from table gets stored

            sub      r9, r8, r9     @ r9 <= r8 - r9 this gets our search result and subtracts capacity
            sdiv     r9, r9, r10    @ r9 <= r9/44 this gets our total bytes and divides by 44 to see how many entities to move

            sub      r9, r6, r9     @ r9 <= r6 - r9 this subtracts count from calculated entity movement
            mul      r2, r9, r10    @ bytes to copy for memmove

            sub      r6, r6, #1     @ count sub by 1
            strh     r6, [r4, #2]   @ store new
            mov      r0, r8         @ source
            
            add      r1, r0, #44   @ destination
            bl      memmove        @ memmove called to copy r2 bytes into r1 (destination)
final:
            mov     r0, #1          @ found and deleted
            pop     {r4, r5, r6, r7, r8, r9, r10, lr}
            bx      lr
end2:
            mov     r0, #0          @ not found and not deleted
            pop     {r4, r5, r6, r7, r8, r9, r10, lr}
            bx      lr

/*---------------------------------------------------------------------------
 Name: insert
 Purpose: inserts a new player into the table if capacity exists
 Receive: pointer to a table, jersey number to insert, pointer to name of player, number of games played, # of 2 pt baskets, # 3 pt baskets, # free throws
 Return: 1 if player inserted, 0 if false
---------------------------------------------------------------------------*/
            .global     insert
            .data
W:          .word       0

insert:
            push    {r4, r5, r6, r7, r8, r9, r10, r11, lr}
            mov     r11, #44         @ set to player size
            ldrh    r6, [r0, #0]    @ capacity
            ldrh    r7, [r0, #2]    @ count
            
            cmp     r7, r6           @ check if at capacity
            bge     end3             @ if at capacity, end.

            mov     r4, r0           @ table
            mov     r5, r1           @ jersey to search
            mov     r6, r2           @ not part of search, just move r2 to r6 for later insertion.
            ldr     r2, =W           @ assign four bytes to r2 for third arg in search
            bl      search

            mov     r8, r0           @ r8 now has search function result (0 or 1 depending if we found player)

            ldr     r9, [r2]         @ loading player register if there is one, otherwise it loads where we stopped searching last (for order)
            cmp     r8, #1           @ If search found something, then player already exists
            beq     end3

            ldr     r10, [r4, #4]    @ Load in r4, our table...and it's capacity as upper bound

            sub     r10, r9, r10     @ r10 <= r9 - r10 this gets searched register and subtracts capacity

            sdiv    r10, r10, r11    @ r10 <= r10/r11 this gets our total bytes and divides by 44 to see how many entities to move
            sub     r10, r7, r10     @ r10 <= r7 - r10 (count - entity count)

            mov     r8, r3           @ I move the fourth argument (games played) here because if I moved it after memmove, it screwed up the insertion.

            mul     r2, r10, r11     @ how many bytes to copy (r11 is forty four) 
            mov     r1, r9           @ destination
            add     r0, r1, r11      @ source
            bl      memmove

            add     r7, r7, #1       @ count + 1
            strh    r7, [r4, #2]

            mov     r11, r5          @ r11 now has r5..the jersey number
            mov     r10, #0          @ making r10 set to 0 for our loop below when storing chars            
            strh    r11, [r9]   @ jersey number gets stored in player


            mov     r11, #0          @ counter in loop
            mov     r4, #2           @ r4 is our offset; start at two bytes for our char*

loops:                               @ Like proj10, loops through all chars and stores them in register
            ldrb     r10, [r6, r11]  @ r6 is where I stored r2 (the third argument which is name)
            strb     r10, [r9, r4]   @ char gets stored in r9 at offset starting at two
            cmp     r10, #0          @ Compares to zero (NULL byte)
            bne     proceed          @ proceed if not equal to null (end)




            ldr     r4, [sp, #36]   @ go in stack and grab our 2-pt basket (first sp arg)
            ldr     r5, [sp, #40]   @ go in stack and grab our 3-pt basket
            ldr     r7, [sp, #44]   @ go in stack and grab free pointers

            strh    r8, [r9, #+28]  @ games
            strh    r4, [r9, #+30]  @ bask2
            strh    r5, [r9, #+32]  @ bask3
            strh    r7, [r9, #+34]  @ free

            mov     r11, #0         @ set r11 to 0. This is our total points register
            mov     r6, #3          @ multiply by three for 3-pt shots
            mov     r10, #0         @ this is for 2-pt shot tracker
            add     r11, r11, r4    @ r11 <= r11 + r4(2-point)
            add     r11, r11, r11   @ r11 <= r11 + r11 (This is same as r11*2 for 2pter)
            add     r10, r10, r5    @ r10 <= r10 + r5 (3-point)
            mul     r10, r10, r6    @ r10 <= r10 * r6 (points * 3 for 3 pointers)
            add     r11, r11, r10   @ r11 <= r11 + r10 (adding 3 and 2 pointers together)
            add     r11, r11, r7    @ r11 <= r11 + r7 (adding 3 and 2 pointers to free points to get total pts)
            strh    r11, [r9, #+36] @ points total

            fmsr    s0, r11         @ total float
            fsitos  s1, s0          @ conversion from int to float
            
            fmsr    s2, r8          @ games float
            fsitos  s3, s2          @ conversion from int to float
            fdivs   s4, s1, s3      @ does total points / games
            fsts    s4, [r9, #+40]  @ points per game
            

            mov     r0, #1          @ Insert successful.
            pop     {r4, r5, r6, r7, r8, r9, r10, r11, lr}
            bx      lr

end3:
            mov     r0, #0          @ Insert failed.
            pop     {r4, r5, r6, r7, r8, r9, r10, r11, lr}
            bx      lr

proceed:
            add     r11, r11, #1
            add     r4, r4, #1
            b       loops

