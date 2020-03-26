/* armemu.h - Public data structures and functions from armemu.c */
#ifndef ARMEMU_H
#define ARMEMU_H

/* cache.h is needed for struct arm_state */
#include "cache.h"

#define NREGS 16
#define STACK_SIZE 1024
#define SP 13
#define LR 14
#define PC 15

/* The complete machine state */
struct arm_state {
    unsigned int regs[NREGS];
    unsigned int cpsr;
    unsigned char stack[STACK_SIZE];
    struct cache_state cstate;    
};

/* Public functions prototypes */
void arm_state_init(struct arm_state *as, unsigned int *func,
                    unsigned int arg0, unsigned int arg1,
                    unsigned int arg2, unsigned int arg3);
void arm_state_free(struct arm_state *as);
void arm_state_print(struct arm_state *as);
unsigned int armemu(struct arm_state *state);

#endif /* ARMEMU_H */

