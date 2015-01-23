CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lcrypto
SOURCE=main.cpp graph_link_lish.cpp
OBJECTS=$(SOURCE:.cpp=.o)

EXE=main

$(EXE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXE)
