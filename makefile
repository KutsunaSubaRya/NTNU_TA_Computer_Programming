CC= gcc
CFLAGS= -Wall -Wextra -std=c11 -O2
LDLIBS= -lm
NAMEONE= main
ONE= main.o api.o

.PHONY: all clean

all: main

main: main.o api.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)