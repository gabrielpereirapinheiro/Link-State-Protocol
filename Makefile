IDIR = ./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR = ./obj
LDIR =./lib
SRC = ./src

LIBS=-lm

_DEPS = grafos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = grafos.o testagrafos.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

testagrafos: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 