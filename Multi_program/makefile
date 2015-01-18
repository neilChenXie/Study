test: main.o
	g++ -o test -fopenmp main.o -lpthread
main.o: main.cpp
	g++ -g -c -fopenmp -Wall main.cpp

clean:
	rm test *.o
