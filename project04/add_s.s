    .global add_s
    .func add_s

    /* add_s(a,b) => a + b */
    
add_s:
    add r0, r0, r1
    bx lr
    .endfunc
    
