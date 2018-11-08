CC=gcc
CCFLAGS=-I. -L. -lpthread -Wall

RM=rm

all: simple complex

simple:
	$(CC) *.c -o simple $(CCFLAGS) -lproblemsimple

complex:
	$(CC) *.c -o complex $(CCFLAGS) -lproblemcomplex

clean:
	$(RM) -vf *.o
	$(RM) -vf *.out
	$(RM) simple complex

