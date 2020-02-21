#include<stdio.h>

void smult_c(int *array, int len, int s);
void smult_s(int *array, int len, int s);


void print_array(int *array, int len)
{
    int i;

    printf("{");
    for (i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i != len-1) {
            printf(", ");
        }
    }
    printf("}");
}

void copy_array(int *a1, int *a2, int len)
{
    int i;

    for (i = 0; i < len; i++) {
        a2[i] = a1[i];
    }
}

int main(int argc, char **argv)
{
    int a[] = {1, 2, 3, 4, 5};
    int a1[5];
    int a2[5];

    copy_array(a, a1, 5);
    copy_array(a, a2, 5);    
        
    printf("smult_c(");
    print_array(a1, 5);
    printf(",5,2) = ");
    smult_c(a1, 5, 2);
    print_array(a1, 5);
    printf("\n");

    /*
    printf("smult_s(");
    print_array(a2, 5);
    printf(",5,2) = ");
    smult_s(a2, 5, 2);
    print_array(a2, 5);
    printf("\n");    
    */
    
    return 0;
}
