#include<stdio.h>

int add_c(int a, int b);
int add_s(int a, int b);

int main(int argc, char **argv)
{
    int r;

    r = add_c(1, 2);
    printf("add_c(1, 2) = %d\n", r);
    r = add_s(1, 2);
    printf("add_s(1, 2) = %d\n", r);

    r = add_c(-1, 100);
    printf("add_c(-1, 100) = %d\n", r);
    r = add_s(-1, 100);
    printf("add_s(-1, 100) = %d\n", r);    

    return 0;
}
