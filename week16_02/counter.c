#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    int i = 0;

    while (1) {
        printf(1, "i = %d\n", i);
        sleep(30);
        i = i + 1;
    }

    exit();
}

