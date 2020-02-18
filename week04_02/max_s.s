.global max_s
.func max_s

max_s:
    cmp r0, r1
    bgt max_end
    mov r0, r1
max_end:
    bx lr

.endfunc
    
   
