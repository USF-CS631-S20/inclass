int max3_c(int a, int b, int c)
{
    int max;

    max = a;
    
    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    return max;
}
