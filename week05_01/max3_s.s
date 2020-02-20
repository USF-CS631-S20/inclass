.global max3_s
.func max3_s

max3_s:
    mov r3, r0
    cmp r1, r3
    blt max3_1
    mov r3, r1
max3_1:
    cmp r2, r3
    blt max3_end
    mov r3, r2
max3_end:
    mov r0, r3
    bx lr

.endfunc

