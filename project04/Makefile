PROGS = analyze armemu
OBJS = add_s.o add2_s.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

analyze : analyze.c add2_s.o
	gcc ${CFLAGS} -o $@ $^

armemu : armemu.c add_s.o add2_s.o
	gcc ${CFLAGS} -o $@ $^

clean :
	rm -rf ${PROGS} ${OBJS} *~



