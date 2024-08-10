CC=gcc
CFLAGS=-g -Wall -Wshadow -Wvla -Werror -pedantic -Wno-unused-function
FLAG32=-m32
FLAG64=-m64
DEBUG=debug
TOOL=valgrind
SRC=2.67.c
OBJ=2.67.o
EXE=2.67

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(FLAG64) $< -o $@

run: $(EXE)
	./$(EXE)

debug: $(EXE)
	$(DEBUG) $(EXE)

clean: 
	rm -f $(OBJ) $(EXE)