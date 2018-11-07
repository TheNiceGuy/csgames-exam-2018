BINARY=solver

CC=gcc
CCFLAGS=-I. -L. -lproblem -lpthread -Wall

RM=rm

all: $(BINARY)

$(BINARY): main.c solve.c solve.h problem.h libproblem.a
	$(CC) *.c -o $(BINARY) $(CCFLAGS)

clean:
	$(RM) -vf *.o
	$(RM) -vf *.out
	$(RM) $(BINARY)

