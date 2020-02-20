PROGS = max3_main count_zeros_main smult_main
OBJS = max3_c.o max3_s.o count_zeros_c.o count_zeros_s.o smult_c.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

max3_main : max3_main.c max3_c.o max3_s.o
	gcc ${CFLAGS} -o $@ $^

count_zeros_main : count_zeros_main.c count_zeros_c.o count_zeros_s.o
	gcc ${CFLAGS} -o $@ $^

smult_main : smult_main.c smult_c.o
	gcc ${CFLAGS} -o $@ $^

clean :
	rm -rf ${PROGS} ${OBJS} *~



