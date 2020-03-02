/* -- hello01.s */
.data
 
greeting:
 .asciz "Hello world!"

argc_str:
 .asciz "Number of args : %d\n"   
    
.text
 
.global main
.func main
main:
    sub sp, sp, #8
    str lr, [sp]
    str r0, [sp, #4]
    
    ldr r0, =greeting


    /* Call puts() from C Library */
    bl puts

    /* restore r0 (argc) from main into r1 */
    ldr r1, [sp, #4]
    ldr r0, =argc_str

    /* Call printf() from C Library */
    bl printf
    
    ldr lr, [sp]
    add sp, sp, #8
    bx lr
    .endfunc
    
/* External */
.global puts
.global printf
