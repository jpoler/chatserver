EXE=chatserver
CC=gcc
OBJECTS=chatserver.o
PORT=8080

$(EXE) : $(OBJECTS)
	$(CC) $(DEBUG) -o $(EXE) $(OBJECTS)

%.o : %.c %.h
	$(CC) $(DEBUG) -o %.o %.c
clean:
	rm -rf $(OBJECTS) $(EXE)

run :
	./$(EXE)

