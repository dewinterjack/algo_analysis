# code details

EXE_DIR = .
EXE = $(EXE_DIR)/sort

SRC= main.c tools.c sort.c output.c

# generic build details

CC=      c99
COPT=    -O
CFLAGS=

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o: main.c tools.h
sort.o: sort.c sort.h tools.h
tools.o: tools.c tools.h sort.h
output.o: output.c tools.h

