    .global fact_rec_s
    .func fact_rec_s

    /* r0 => n
       r1 => r
    */
    
fact_rec_s:
    sub sp, sp, #8
    str lr, [sp]

    mov r1, #1

    cmp r0, #1
    ble fact_rec_s_end

    str r0, [sp, #4]    

    sub r0, r0, #1
    bl fact_rec_s

    ldr r1, [sp, #4]
    mul r1, r0, r1
    
fact_rec_s_end: 
    mov r0, r1
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
    .endfunc
