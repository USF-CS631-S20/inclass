#include <stdbool.h>
#include <stdio.h>

#include "armemu.h"

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

    cache_state_init(&as->cstate);
}

void arm_state_free(struct arm_state *as)
{
    cache_state_free(&as->cstate);
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
bool is_add_inst(unsigned int iw)
{
    unsigned int op;
    unsigned int opcode;

    op = (iw >> 26) & 0b11;
    opcode = (iw >> 21) & 0b1111;

    return (op == 0) && (opcode == 0b0100);
}

/* Note: in your implemenation you will want armemu_dp() */
void armemu_add(struct arm_state *state, unsigned int iw)
{
    unsigned int rd, rn, rm, i, imm;

    rd = (iw >> 12) & 0xF;
    rn = (iw >> 16) & 0xF;
    rm = iw & 0xF;
    i = (iw >> 25) & 0b1;
    imm = iw & 0xFF;

    if (i == 0) {
        state->regs[rd] = state->regs[rn] + state->regs[rm];
    } else {
        state->regs[rd] = state->regs[rn] + imm;
    }

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
    
    /* iw = *((unsigned int *) state->regs[PC]); */
    iw = cache_lookup(&state->cstate, state->regs[PC]);

    if (is_bx_inst(iw)) {
        armemu_bx(state, iw);
    } else if (is_add_inst(iw)) {
        armemu_add(state, iw);
    }
}

unsigned int armemu(struct arm_state *state)
{
    int count = 0;
    /* Execute instructions until PC = 0 */
    /* This happens when bx lr is issued and lr is 0 */
    while (state->regs[PC] != 0) {

        if (ARMEMU_DEBUG) {
            arm_state_print(state);
        }
        
        armemu_one(state);

        count = count + 1;
        if (count > MAX_INSTRUCTION_COUT) {
            break;
        }
    }

    return state->regs[0];
}                
 
