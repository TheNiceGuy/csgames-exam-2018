CC=gcc
CCFLAGS=-I. -L. -lpthread -Wall

RM=rm

all: simple complex

simple: main.c solve.c solve.h libproblemsimple.a
	$(CC) *.c -o simple $(CCFLAGS) -lproblemsimple

complex: main.c solve.c solve.h libproblemcomplex.a
	$(CC) *.c -o complex $(CCFLAGS) -lproblemcomplex

clean:
	$(RM) -vf *.o
	$(RM) -vf *.out
	$(RM) -vf simple complex

