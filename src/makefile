EXE=app
IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR) -I.

ODIR=obj
LDIR=../lib

LIBS=-lm

_DEPS = xlog.h
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = xlog.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean run

clean:
	rm -f $(ODIR)/*.o $(EXE)

run:
	./$(EXE)
