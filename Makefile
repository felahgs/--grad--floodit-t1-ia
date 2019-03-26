CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFLODIT = floodit.o mapa.o
OBJTRAB = trab.o mapa.o
FLOODIT = floodit
TRAB = trab

all: $(FLOODIT) $(TRAB)

$(FLOODIT): $(OBJFLODIT)
	$(CC) $(CFLAGS) -o $(FLOODIT) $(OBJFLODIT) $(LDFLAGS)

$(TRAB): $(OBJTRAB)
	$(CC) $(CFLAGS) -o $(TRAB) $(OBJTRAB) $(LDFLAGS)

clean:
	rm -f $(OBJFLODIT) $(OBJTRAB) $(FLOODIT) $(TRAB) *~
	