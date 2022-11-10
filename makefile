CC= gcc
CFLAGS= -Wall -Wextra -std=c11 -O2
LDLIBS= -lm
NAMEONE= main
ONE= main.o bossInfo.o adventurerInfo.o mapInfo.o

.PHONY: all clean

all: main

main: main.o bossInfo.o adventurerInfo.o mapInfo.o
	$(CC) $(CFLAGS) -o $(NAMEONE) $(ONE)  $(LDLIBS)
clean:
	-rm -rf $(NAMEONE) $(ONE)