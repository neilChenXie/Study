hash: main.o
	g++ -o hash -g main.o
main.o: main.cpp hash.h
	g++ -g -c -Wall main.cpp

clean:
	rm hash *.o
