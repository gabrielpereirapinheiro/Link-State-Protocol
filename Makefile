IDIR = ./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR = ./obj
LDIR =./lib
SRC = ./src

LIBS=-lm

_DEPS = biblioteca.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = lsp.o funcoes.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

lsp: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 