PROGS = hello

CFLAGS = -g

all : ${PROGS}

hello : hello.c hello_print.h hello_print.c
	gcc ${CFLAGS} -o hello hello.c hello_print.c

clean :
	rm -rf ${PROGS}


