#include<stdio.h>

int max_c(int a, int b);
int max_s(int a, int b);

int main(int argc, char **argv)
{
    int r;

    r = max_c(1, 2);
    printf("max_c(1, 2) = %d\n", r);
    r = max_s(1, 2);
    printf("max_s(1, 2) = %d\n", r);

    r = max_c(-1, 100);
    printf("max_c(-1, 100) = %d\n", r);
    r = max_s(-1, 100);
    printf("max_s(-1, 100) = %d\n", r);    

    return 0;
}
