CC = gcc
CFLAGS = -Wall -std=gnu99
LDFLAGS =
OBJTRAB =  mapa.o lista.o grafo.o trab.o aux.o
TRAB = trab

all: clean $(FLOODIT) $(TRAB) $(TESTS)


$(TRAB): $(OBJTRAB)
	$(CC) $(CFLAGS) -g -o $(TRAB) $(OBJTRAB) $(LDFLAGS)
	
clean:
	rm -f $(OBJTRAB)  $(TRAB) *~
	