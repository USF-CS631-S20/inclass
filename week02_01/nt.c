#include<stdio.h>

struct nt_rep {
    unsigned int v;
    int width;
    int range_start;
    int range_end;
};

void nt_rep_init(struct nt_rep *ntp)
{
    ntp->v = 0;
    ntp->width = 32;
    ntp->range_start = 0;
    ntp->range_end = 31;
}

void nt_rep_print(struct nt_rep *ntp)
{
    printf("ntp->v = %d\n", ntp->v);
    printf("ntp->width = %d\n", ntp->width);
    printf("ntp->range_start = %d\n", ntp->range_start);
    printf("ntp->range_end = %d\n", ntp->range_end);
}

int parse_command_line(char **argv, struct nt_rep *ntp)
{
    return 0;
}

int main(int argc, char **argv)
{
    struct nt_rep ntr;

    nt_rep_init(&ntr);

    parse_command_line(argv, &ntr);

    nt_rep_print(&ntr);

    return 0;
}

