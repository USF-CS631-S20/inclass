PROGS = fact_main hello_s
OBJS = fact_iter_c.o fact_iter_s.o fact_rec_c.o fact_rec_s.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

fact_main : fact_main.c fact_iter_c.o fact_iter_s.o fact_rec_c.o fact_rec_s.o
	gcc ${CFLAGS} -o $@ $^

hello_s : hello_s.s
	gcc ${CFLAGS} -o $@ $^

clean :
	rm -rf ${PROGS} ${OBJS} *~



