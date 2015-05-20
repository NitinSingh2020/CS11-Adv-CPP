CC=g++
CFLAGS=-c -Wall -std=gnu++11
LDFLAGS=
SOURCES=
OBJECTS=
EXECUTABLE=

all: Vector3F.o

Vector3F.o: Vector3F.cc
	$(CC) $(CFLAGS) Vector3F.cc

# Clean up task
clean:
	rm *.o *.exe

# Code styling
style: Vector3F.cc
	python cpplint.py Vector3F.cc

.PHONY: style
