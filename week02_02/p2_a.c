#include<stdio.h>

struct foo {
    int a;
    int b;
    char c;
    char d;
    char e;
};

int main(int argc, char **argv)
{
    struct foo myfoo;
    int *p;
    int x;
    char *c;

    printf("sizeof(struct foo) = %d\n", sizeof(struct foo));   
 
    myfoo.a = 1;
    myfoo.b = 2;
    myfoo.c = '1';
    myfoo.d = '2';
    myfoo.e = '\0';
    
    p = &myfoo.a;
    p = p + 1;
    
    x = *p;
    
    printf("x = %d\n", x);
    
    p = p + 1;
    c = (char *) p;
    
    printf("c = %s\n", c);
    
    return 0;
}
