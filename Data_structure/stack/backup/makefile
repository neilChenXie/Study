stack: main.o
	g++ -o stack -g main.o
main.o: main.cpp stack.h
	g++ -g -c -Wall main.cpp

clean:
	rm hash *.o
