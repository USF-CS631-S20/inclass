int find_max_index_c(int *array, int len)
{
    int i;
    int max = array[0];
    int index = 0;

    for (i = 1; i < len; i++) {
        if (array[i] > max) {
            max = array[i];
            index = i;
        }
    }

    return index; 
}
