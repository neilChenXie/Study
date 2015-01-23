list: main.o link_list.o
	g++ -o list -g main.o link_list.o
main.o: main.cpp link_list.h link_list.cpp
	g++ -g -c -Wall main.cpp
link_list.o: link_list.h link_list.cpp
	g++ -g -c -Wall link_list.cpp

clean:
	rm list *.o
