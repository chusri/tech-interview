# Makefile

CC=g++
CFLAGS=-I. -pipe -O2 -std=c++11
DEPS=slist_node.h slist.h
OBJS=main.o
EXEC=main

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

${EXEC}: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

clean:
	rm -rf ${OBJS} ${EXEC}
