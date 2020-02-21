int count_zeros_c(int *array, int len)
{
    int i;
    int count = 0;

    for (i = 0; i < len; i++) {
        if (array[i] == 0) {
            count = count + 1;
        }
    }

    return count;
}
