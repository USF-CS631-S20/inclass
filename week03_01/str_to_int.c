#include<stdio.h>
#include<string.h>

int str_to_int(char *s)
{
    int i, d;
    int v = 0;
    int slen = strlen(s);

    for (i = 0; i < slen; i++) {
        v = v * 10;
        d = (int) s[i] - '0';
        v = v + d;
    }

    return v;
}

int main(int argc, char **argv)
{
    printf("%s = %d\n", argv[1], str_to_int(argv[1]));
    return 0;
}
