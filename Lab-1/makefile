CC=g++
CFLAGS=-c -Wall -std=gnu++11
LDFLAGS=
SOURCES=
OBJECTS=
EXECUTABLE=

all: exercise1 exercise2 exercise3 exercise4 exercise5

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

# Exercise 3
exercise3: exercise3.o
	$(CC) exercise3.o -o exercise3

exercise3.o: exercise3.cc
	$(CC) $(CFLAGS) exercise3.cc

# Exercise 4
exercise4: exercise4.o
	$(CC) exercise4.o -o exercise4

exercise4.o: exercise4.cc
	$(CC) $(CFLAGS) exercise4.cc

# Exercise 5
exercise5: exercise5.o
	$(CC) exercise5.o -o exercise5

exercise5.o: exercise5.cc
	$(CC) $(CFLAGS) exercise5.cc

# Clean up task
clean:
	rm *.o *.exe