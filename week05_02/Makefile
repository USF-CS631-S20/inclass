PROGS = second add_main max_main
OBJS = second.o add_c.o add_s.o max_c.o max_s.o

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

second : second.s
	as -o second.o second.s
	gcc ${CFLAGS} -o second second.o

add_main : add_main.c add_c.o add_s.o
	gcc ${CFLAGS} -o $@ $^

max_main : max_main.c max_c.o max_s.o
	gcc ${CFLAGS} -o $@ $^

clean :
	rm -rf ${PROGS} ${OBJS} *~



