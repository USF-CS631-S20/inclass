#include<stdio.h>

int main(int argc, char **argv)
{
    char a;
    short b;

    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(int) = %d\n", sizeof(int));
    
    a = 0;
    printf("a = %d\n", (int) a);
    
    a = a - 1;

    if (a == 255) {
        printf("a == 255\n");
    }

    if (a == -1) {
        printf("a == -1\n");
    }
        
    printf("a = %d\n", (int) a);

    b = 0;
    printf("b = %d\n", (int) b);
    
    b = b - 1;

    printf("b = %d\n", (int) b);

    return 0;
}

