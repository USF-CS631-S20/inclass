#include<stdio.h>

struct nt_rep {
    unsigned int value;
    int width;
    int range_start;
    int range_end;
};

void nt_rep_init(struct nt_rep *ntp)
{
    ntp->value = 0;
    ntp->width = 32;
    ntp->range_start = 0;
    ntp->range_end = 31;
}

void nt_rep_print(struct nt_rep *ntp)
{
    printf("ntp->value = %u\n", ntp->value);
    printf("ntp->width = %d\n", ntp->width);
    printf("ntp->range_start = %d\n", ntp->range_start);
    printf("ntp->range_end = %d\n", ntp->range_end);
}

int parse_command_line(struct nt_rep *ntp, char **argv)
{
    return 0;
}

int parse_input_value(struct nt_rep *ntp)
{
    return 0;
}

int main(int argc, char **argv)
{
    struct nt_rep ntr;

    nt_rep_init(&ntr);
    nt_rep_print(&ntr);

    parse_command_line(&ntr, argv);

    parse_input_value(&ntr);
    
    return 0;
}
