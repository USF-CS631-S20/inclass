    .global count_zeros_s
    .func count_zeros_s
    /*
    int *array => r0
    int len    => r1
    int i      => r2
    int count  => r3
    */    
count_zeros_s:
    mov r2, #0
    mov r3, #0    

count_zeros_loop:
    cmp r2, r1
    beq count_zeros_endloop
    ldr r12, [r0]
    cmp r12, #0
    bne count_zeros_notzero
    add r3, r3, #1
count_zeros_notzero:
    add r0, r0, #4
    add r2, r2, #1
    b count_zeros_loop

count_zeros_endloop:    
    mov r0, r3
    bx lr
    
    .endfunc
