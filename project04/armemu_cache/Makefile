PROGS = armemu_tests
OBJS = armemu.o cache.o utils.o add_s.o add2_s.o
HFILES = armemu.h cache.h utils.h

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c
	gcc ${CFLAGS} -c -o $@ $<

%.o : %.s
	as -o $@ $<


all : ${PROGS}

armemu.o : armemu.c armemu.h
	gcc ${CFLAGS} -c -o $@ $<

cache.o : cache.c cache.h
	gcc ${CFLAGS} -c -o $@ $<

utils.o : utils.c utils.h
	gcc ${CFLAGS} -c -o $@ $<

armemu_tests : armemu_tests.c ${OBJS}
	gcc ${CFLAGS} -o $@ $^

test :
	./armemu_tests

clean :
	rm -rf ${PROGS} ${OBJS} *~



