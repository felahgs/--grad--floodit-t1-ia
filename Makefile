CC = gcc
CFLAGS = -Wall -std=gnu99
LDFLAGS =
OBJFLODIT = floodit.o mapa.o
OBJTRAB =  mapa.o lista.o grafo.o trab.o
OBJTESTS =  mapa.o lista.o grafo.o tests.o
FLOODIT = floodit
TRAB = trab
TESTS = tests

all: clean $(FLOODIT) $(TRAB) $(TESTS)

$(FLOODIT): $(OBJFLODIT)
	$(CC) $(CFLAGS) -o $(FLOODIT) $(OBJFLODIT) $(LDFLAGS)

$(TRAB): $(OBJTRAB)
	$(CC) $(CFLAGS) -o $(TRAB) $(OBJTRAB) $(LDFLAGS)
	
$(TESTS): $(OBJTESTS)
	$(CC) $(CFLAGS) -o $(TESTS) $(OBJTESTS) $(LDFLAGS)

clean:
	rm -f $(OBJFLODIT) $(OBJTRAB) $(FLOODIT) $(TRAB) *~
	