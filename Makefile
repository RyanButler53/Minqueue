CXX = clang++
CXXFLAGS = -std=c++2a -g -O2 -Wall -pedantic
TARGET = minqueue-test

all: $(TARGET)

minqueue-test: test.o
	$(CXX) -o test test.o

experiment.o: test.cpp minqueue.hpp minqueue-private.hpp quack.hpp quack-private.hpp
	$(CXX) -c test.cpp $(CXXFLAGS)

clean: 
	rm -rf $(TARGET) *.o