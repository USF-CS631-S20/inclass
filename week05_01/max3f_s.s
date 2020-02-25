    .global max3f_s
    .func max3f_s

max3f_s:
    sub sp, sp, #8
    str lr, [sp]
    
    bl max_s
    mov r1, r2
    bl max_s

    ldr lr, [sp]
    add sp, sp, #8
    bx lr
    .endfunc

