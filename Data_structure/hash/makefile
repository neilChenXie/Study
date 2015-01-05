hash: main.o hash.o
	g++ -o hash -g main.o hash.o
main.o: main.cpp hash.h hash.cpp
	g++ -g -c -Wall main.cpp
hash.o: hash.h hash.cpp
	g++ -g -c -Wall hash.cpp

clean:
	rm hash *.o
