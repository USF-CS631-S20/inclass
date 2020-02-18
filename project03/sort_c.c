int find_max_index_c(int *array, int len);

int sort_c(int *array, int len)
{
    int i;
    int max_index;
    int tmp;

    for (i = 0; i < len; i++) {
        max_index = find_max_index_c(&array[i], len - i) + i;
        if (max_index != i) {
            tmp = array[i];
            array[i] = array[max_index];
            array[max_index] = tmp;
        }
    }
    return len;
}
