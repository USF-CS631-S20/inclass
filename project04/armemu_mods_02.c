#include <stdbool.h>
#include <stdio.h>

#define NREGS 16
#define STACK_SIZE 1024
#define SP 13
#define LR 14
#define PC 15

/* Assembly functions to emulate */
int add_s(int a, int b);
int add2_s(int a, int b);

/* The complete machine state */
struct arm_state {
    unsigned int regs[NREGS];
    unsigned int cpsr;
    unsigned char stack[STACK_SIZE];

    /* metrics */
    struct ...

    /* cache */
    struct ...    
    
};

/* Initialize an arm_state struct with a function pointer and arguments */
void arm_state_init(struct arm_state *as, unsigned int *func,
                    unsigned int arg0, unsigned int arg1,
                    unsigned int arg2, unsigned int arg3)
{
    int i;

    /* Zero out all registers */
    for (i = 0; i < NREGS; i++) {
        as->regs[i] = 0;
    }

    /* Zero out CPSR */
    as->cpsr = 0;

    /* Zero out the stack */
    for (i = 0; i < STACK_SIZE; i++) {
        as->stack[i] = 0;
    }

    /* Set the PC to point to the address of the function to emulate */
    as->regs[PC] = (unsigned int) func;

    /* Set the SP to the top of the stack (the stack grows down) */
    as->regs[SP] = (unsigned int) &as->stack[STACK_SIZE];

    /* Initialize LR to 0, this will be used to determine when the function has called bx lr */
    as->regs[LR] = 0;

    /* Initialize the first 4 arguments */
    as->regs[0] = arg0;
    as->regs[1] = arg1;
    as->regs[2] = arg2;
    as->regs[3] = arg3;
}

void arm_state_print(struct arm_state *as)
{
    int i;

    for (i = 0; i < NREGS; i++) {
        printf("reg[%d] = %d\n", i, as->regs[i]);
    }
    printf("cpsr = %X\n", as->cpsr);
}

/* Note: in your implemenation you will want is_dp_inst() */
bool is_dp_inst(unsigned int iw)
{
    unsigned int op;

    op = (iw >> 26) & 0b11;

    return (op == 0);
}

/* Note: in your implemenation you will want armemu_dp() */
void armemu_dp(struct arm_state *state, unsigned int iw)
{
    unsigned int rd, rn, rm, i, imm;
    unsigned int opcode;
    
    rd = (iw >> 12) & 0xF;
    rn = (iw >> 16) & 0xF;
    rm = iw & 0xF;
    i = (iw >> 25) & 0b1;
    imm = iw & 0xFF;

    opcode = (iw >> 21) & 0b1111;

    if (i == 0) {
        op2 = state->regs[rm];
    } else {
        op2 = imm;
    }
    
            

    if (opcode == 0b0100) {
        /* add */
        state->regs[rd] = state->regs[rn] + op2;
        ....
    } else if (opcode == 0b0010) {
        /* sub */
        ...
    } else if (opcode == 0b1010) {
        /* cmp */
        cpsr_update_cmp(&state->cpsr, state->regs[rn], op2);

    if (rd != PC) {
        state->regs[PC] = state->regs[PC] + 4;
    }
}

bool is_bx_inst(unsigned int iw)
{
    unsigned int bx_code;

    bx_code = (iw >> 4) & 0x00FFFFFF;

    return (bx_code == 0b000100101111111111110001);
}

void armemu_bx(struct arm_state *state, unsigned int iw)
{
    unsigned int rn;

    rn = iw & 0b1111;

    state->regs[PC] = state->regs[rn];
}

void armemu_one(struct arm_state *state)
{
    unsigned int iw;
    
    //iw = *((unsigned int *) state->regs[PC]);
    iw = cache_lookup(state, state->regs[PC]);

    /* Start with most contrained and go to least constrained. */
    if (is_bx_inst(iw)) {
        armemu_bx(state, iw);
    } else if (is_mul_inst(iw)) {
        armemu_mul(state, iw);
    } else if (is_add_inst(iw)) {
        armemu_add(state, iw);
    }
}

unsigned int armemu(struct arm_state *state)
{
    /* Execute instructions until PC = 0 */
    /* This happens when bx lr is issued and lr is 0 */
    while (state->regs[PC] != 0) {
        armemu_one(state);
    }

    return state->regs[0];
}                
  
int main(int argc, char **argv)
{
    struct arm_state state;
    unsigned int r;

    /* Emulate add_s */
    arm_state_init(&state, (unsigned int *) add_s, 1, 2, 0, 0);
    arm_state_print(&state);
    r = armemu(&state);
    printf("armemu(add_s(1,2)) = %d\n", r);

    /* Emulate add2_s */    
    arm_state_init(&state, (unsigned int *) add2_s, 1, 2, 0, 0);
    arm_state_print(&state);
    r = armemu(&state);
    printf("armemu(add2_a(1,2)) = %d\n", r);

    /* Project03 Tests */

    /* quadratic */

    r = quadratic_c(1, 1, 1, 1);
    printf("quadratic_c(1, 1, 1, 1) = %r\n", r);
    r = quadratic_s(1, 1, 1, 1);
    printf("quadratic_s(1, 1, 1, 1) = %r\n", r);        

    arm_state_init(&state, (unsigned int *) quadratic_s, 1, 1, 1, 1);
    r = armemu(&state);
    printf("quadratic_e(1, 1, 1, 1) = %r\n", r);
    arm_state_metrics_print(&state);
    arm_state_cache_print(&state);    
    
    return 0;
}

void test_quadratic_one(int x, int a, int b, int c)
{

}

void test_quadratic(void)
{
    test_quadratic_one(1, 1, 1, 1);
    test_quadratic_one(2, 2, 2, 2);    
}
