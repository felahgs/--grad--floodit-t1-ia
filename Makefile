CC = gcc
CFLAGS = -Wall -std=gnu99
LDFLAGS =
OBJFLODIT = floodit.o mapa.o
OBJTRAB =  mapa.o lista.o grafo.o trab.o aux.o
FLOODIT = floodit
TRAB = trab

all: clean $(FLOODIT) $(TRAB) $(TESTS)

$(FLOODIT): $(OBJFLODIT)
	$(CC) $(CFLAGS) -o $(FLOODIT) $(OBJFLODIT) $(LDFLAGS)

$(TRAB): $(OBJTRAB)
	$(CC) $(CFLAGS) -g -o $(TRAB) $(OBJTRAB) $(LDFLAGS)
	
clean:
	rm -f $(OBJFLODIT) $(OBJTRAB) $(FLOODIT) $(TRAB) *~
	