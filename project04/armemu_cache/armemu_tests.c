/* armemu_tests.c - test driver */

#include <stdio.h>

#include "armemu.h"

/* Test function prototypes */
int add_s(int a, int b);
int add2_s(int a, int b);

int main(int argc, char **argv)
{
    struct arm_state state;
    unsigned int r;

    /* Emulate add_s */
    arm_state_init(&state, (unsigned int *) add_s, 1, 2, 0, 0);
    arm_state_print(&state);
    r = armemu(&state);
    printf("armemu(add_s(1,2)) = %d\n", r);
    cache_state_stats(&state.cstate);
    arm_state_free(&state);
    
    /* Emulate add2_s */    
    arm_state_init(&state, (unsigned int *) add2_s, 1, 2, 0, 0);
    arm_state_print(&state);
    r = armemu(&state);
    printf("armemu(add2_a(1,2)) = %d\n", r);
    cache_state_stats(&state.cstate);
    arm_state_free(&state);

    return 0;
}
