CC = gcc
CFLAGS = -Wall -g

.PHONY: clean

clean:
	rm -f `file * | grep ELF | cut -d: -f1`
	rm -f *.tst
	rm -f *~
