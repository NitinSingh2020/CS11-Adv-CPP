CC=g++
CFLAGS=-c -Wall -std=gnu++11
LDFLAGS=
SOURCES=
OBJECTS=
EXECUTABLE=

all: Vector3F.o test_Vector3F

Vector3F.o: Vector3F.hh Vector3F.cc
	$(CC) $(CFLAGS) Vector3F.cc

test_Vector3F: test_Vector3F.cc
	$(CC) -Wall -I gtest-1.7.0/include gtest-1.7.0/make/gtest-all.o Vector3F.o test_Vector3F.cc -o test_Vector3F

# Clean up task
clean:
	rm *.o *.exe

# Code styling
style: Vector3F.cc test_Vector3F.cc
	python cpplint.py Vector3F.cc test_Vector3F.cc

.PHONY: style