int fact_rec_c(int n)
{
    int r = 1;

    if (n > 1) {
        r = fact_rec_c(n - 1) * n;
    }

    return r;
}
