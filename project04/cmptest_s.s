    .global cmptest_s
    .func cmptest_s

cmptest_s:
    mov r0, #33
    mov r1, #33
    cmp r0, r1
    cmp r0, #32
    bx lr
    .endfunc
    
