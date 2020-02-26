    .global fact_iter_s
    .func fact_iter_s

/* r0 => n
   r1 => p
*/
    
fact_iter_s:
    mov r1, #1
fact_while: 
    cmp r0, #1
    ble fact_while_end
    mul r1, r0, r1
    sub r0, r0, #1
    b fact_while
fact_while_end: 
    mov r0, r1
    bx lr
    .endfunc
