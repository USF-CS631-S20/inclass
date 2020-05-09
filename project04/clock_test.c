#include<stdio.h>
#include<time.h>
#include<unistd.h>


int main(int argc, char **argv)
{
    struct timespec tp_start, tp_end;
    int i, x = 1;
    unsigned long long ns_start, ns_start_sec, ns_start_nsec,
        ns_end, ns_end_sec, ns_end_nsec, ns_total, ms_total;
    
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp_start);

    for (i = 0; i < 200000000; i++) {
        x = x + 1;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp_end);

    ns_start_sec = (unsigned long long) tp_start->tv_sec;
    
    
    ns_total = 1000000000 * (unsigned long long) ((tp_end.tv_sec - tp_start.tv_sec)
                                                  + (tp_end.tv_nsec - tp_start.tv_nsec));

    ms_total = ns_total / 1000;

    printf("ns_total (nanoseconds) = %d\n", ns_total);    
    printf("ms_total (micorseconds) = %d\n", ms_total);
        
    printf("tp_start->tv_sec = %d\n", tp_start.tv_sec);
    printf("tp_start->tv_nsec = %d\n", tp_start.tv_nsec);

    printf("tp_start->tv_sec = %d\n", tp_end.tv_sec);
    printf("tp_start->tv_nsec = %d\n", tp_end.tv_nsec);    

    ns_start = (unsigned long long) tp_start.tv_nsec;
    printf("ns_start = %llu\n", ns_start);
    
    ns_start = (tp_start.tv_sec * 100000000000) + tp_start.tv_nsec;
    ns_end = (tp_end.tv_sec * 100000000000) + tp_end.tv_nsec;    

    printf("ns_start = %d\n", ns_start);
    printf("ns_end = %d\n", ns_end);    
    
    ns_total = ns_end - ns_start;
    ms_total = ns_total / 1000;
    //execTime = 1000000000 * (tock.tv_sec ‐ tick.tv_sec) + tock.tv_nsec ‐ tick.tv_nsec;
    
    printf("ns_total (nanoseconds) = %d\n", ns_total);    
    printf("ms_total (micorseconds) = %d\n", ms_total);
    
    return 0;
}
