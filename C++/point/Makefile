# Makefile

CC=g++
CFLAGS=-I. -pipe -O2 -std=c++11
DEPS=point.h
OBJS=point.o main.o
EXEC=main

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

${EXEC}: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

clean:
	rm -rf ${EXEC} ${OBJS}
