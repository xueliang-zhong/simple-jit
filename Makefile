CC=gcc
CFLAGS=-O0 -g

all:
	@$(CC) $(CFLAGS) jit.c -o jit

clean:
	@rm jit
