    .global fact_rec_s
    .func fact_rec_s

    /*
    r0 => n
    r1 => r
    */
    
fact_rec_s:
    mov r1, #1          /* initialize r = 0 */
    cmp r0, #1          /* compare r to 1 */
    ble fact_rec_s_end  /* base case if r <= 1 */

    sub sp, sp, #8      /* allocate 2 words on stack */
    str lr, [sp]        /* save lr */
    str r0, [sp, #4]    /* save n */

    sub r0, r0, #1      /* n = n - 1 */
    bl fact_rec_s       /* recursive call */

    ldr r1, [sp, #4]    /* retrieve n */
    mul r1, r0, r1      /* fact_rec_s(n-1) * n */

    ldr lr, [sp]        /* restore lr */
    add sp, sp, #8      /* restore sp */
    
fact_rec_s_end: 
    mov r0, r1          /* set return value, r0 */
    bx lr               /* return to caller */
    .endfunc
    
