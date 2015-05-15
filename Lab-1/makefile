CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=
OBJECTS=
EXECUTABLE=

all: exercise1

exercise1: exercise1.o
	$(CC) exercise1.o -o exercise1

exercise1.o: exercise1.cc
	$(CC) $(CFLAGS) exercise1.cc

clean:
	rm *.o *.exe