CC=gcc
CFLAGS=-I.

x12make:
	$(CC) -o x12 main.c -lX11 $(CFLAGS)
