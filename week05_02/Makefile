PROGS = count_zeros_main
OBJS = count_zeros_c.o count_zeros_s.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

max_main : max_main.c max_c.o max_s.o
	gcc ${CFLAGS} -o $@ $^

count_zeros_main : count_zeros_main.c count_zeros_c.o count_zeros_s.o
	gcc ${CFLAGS} -o $@ $^

clean :
	rm -rf ${PROGS} ${OBJS} *~



