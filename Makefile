CXXFLAGS=-g

all: test

test: LinkedList.o test.cpp
	g++ -o test test.cpp LinkedList.o