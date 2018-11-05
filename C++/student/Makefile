# Makefile

CC=g++
EXE=main
OBJS=main.o
DEPS=Student.h GradStudent.h
CFLAGS=-I. -pipe -O2 -std=c++11

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

${EXE}: ${OBJS}
	${CC} -o $@ $^ ${CFLAGS}

clean:
	rm -rf ${OBJS} ${EXE}
