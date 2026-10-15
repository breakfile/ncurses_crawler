all:
	gcc *.c -lncurses

bnr: all
	./a.out
