#include<stdio.h>

int main(int argc, char **argv)
{
    signed char a;
    
    a = 0;
    printf("a = %d\n", (int) a);
    
    a = a - 1;
    printf("a = %d\n", (int) a);

    return 0;
}
