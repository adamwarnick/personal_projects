CFLAGS=-std=c++11 -g

all: lab8

lab8: main.cpp *.cpp
	g++ $(CFLAGS) *.cpp -o o.out
	
clean :
	rm -f o.out
