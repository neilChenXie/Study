CC=g++
CFLAGS=-c -g -Wall
LDFLAGS=-lcrypto
SOURCE=1.cpp func.cpp
OBJECTS=$(SOURCE:.cpp=.o)

EXE=check

$(EXE):$(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm $(EXE)
