main: main.o graph_link_list.o
	g++ -o main -g main.o graph_link_list.o
main.o: main.cpp graph_link_list.h graph_link_list.cpp
	g++ -g -c -Wall main.cpp
graph_link_list.o: graph_link_list.h graph_link_list.cpp
	g++ -g -c -Wall graph_link_list.cpp
clean:
	rm main *.o
