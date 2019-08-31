# Makefile

CC=g++
SYSTEMC_HOME=/usr/local/systemc-2.3.3
CFLAGS=-I. -I${SYSTEMC_HOME}/include -pipe -O2
LDFLAGS=-L. -L${SYSTEMC_HOME}/lib-linux64 -Wl,-rpath=${SYSTEMC_HOME}/lib-linux64 -lsystemc -lm
DEPS=
OBJS=hello_world.o
EXEC=hello_world

%.o: %.cpp ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}

${EXEC}: ${OBJS}
	${CC} -o $@ $^ ${LDFLAGS}

clean:
	rm -rf ${OBJS} ${EXEC}
