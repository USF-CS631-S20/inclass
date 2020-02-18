/* second.s */
/* This is a comment */
.global main
.func main
 
main:
    mov r0, #1
    mov r1, #2
    add r0, r0, r1
    bx lr /* return from main */

    
