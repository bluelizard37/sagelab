CC=gcc
CFLAGS=-c -Wall -std=c99 -g
LDFLAGS=
SOURCES=nqueen.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=nqueen

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o nqueen
