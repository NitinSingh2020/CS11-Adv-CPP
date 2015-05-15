CC=g++
CFLAGS=-c -Wall -std=gnu++11
LDFLAGS=
SOURCES=
OBJECTS=
EXECUTABLE=

all: exercise1 exercise2

# Exercise 1
exercise1: exercise1.o
	$(CC) exercise1.o -o exercise1

exercise1.o: exercise1.cc
	$(CC) $(CFLAGS) exercise1.cc

# Exercise 2
exercise2: exercise2.o
	$(CC) exercise2.o -o exercise2

exercise2.o: exercise2.cc
	$(CC) $(CFLAGS) exercise2.cc

clean:
	rm *.o *.exe