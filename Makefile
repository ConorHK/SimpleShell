CC=gcc
CFLAGS=-Wall
HFILES=src/shell.h
SRC=src/execute.c src/main.c src/split.c src/prompt.c src/signal.c src/redirect.c src/cd.c

all: shell
shell:
	$(CC) $(CFLAGS) $(HFILES) $(SRC) -o spsh
dist: clean
	tar -czvf ../assign2_18398031.tar.gz .
clean:
	find . -type f -name 'spsh' -delete
