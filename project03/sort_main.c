#include<stdio.h>

int find_max_index_c(int *array, int len);
int sort_c(int *array, int len);

void print_array(int *array, int len)
{
    int i;
    
    printf("{");
    for (i = 0; i < len; i++) {
        printf("%d", array[i]);
        if (i != (len - 1)) {
            printf(", ");
        }
    }
    printf("}");
}

int main(int argc, char **argv)
{
    int arr1[5] = {3, 5, 1, 2, 4};

    printf("sort_c(");
    print_array(arr1, 5);
    printf(", 5) = ");
    sort_c(arr1, 5);
    print_array(arr1, 5);
    printf("\n");

    return 0;
}

