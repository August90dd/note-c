CC = gcc
CFLAGS = -Wall -g -fcommon

SRCS := $(wildcard *.c)
OBJS := $(patsubst %.c,%.o,$(SRCS))

.PHONY: clean

all: main 
main: $(OBJS)
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f `file * | grep ELF | cut -d: -f1`
