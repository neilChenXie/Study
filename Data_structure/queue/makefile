queue: main.o
	g++ -o queue -g main.o
main.o: main.cpp queue.h
	g++ -g -c -Wall main.cpp

clean:
	rm *.o queue
