    .global smult_s
    .func smult_s
    /*
    int *array => r0
    int len    => r1
    int s      => r2
    int i      => r3
    */    
smult_s:
    mov r3, #0    
smult_loop:
    cmp r3, r1
    beq smult_endloop
    ldr r12, [r0]
    mul r12, r2, r12
    add r3, r3, #1
    add r0, r0, #4
    b smult_loop
smult_endloop:    
    bx lr
    
    .endfunc
