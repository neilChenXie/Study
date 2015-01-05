CC=g++
CFLAGS=-c -g -Wall
SOURCE=test.cpp
OBJECTS=$(SOURCE:.cpp=.o)

EXE=stack

$(EXE):$(OBJECTS)
	$(CC) $(OBJECTS) -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXE)
