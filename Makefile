# compiler setup
CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -lm

# pickp all sources
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=%.o)

# define targets
TARGETS=infinite_product codeinvim gigel_and_the_checkboard nomogram

build: $(OBJS) $(TARGETS)

infinite_product: infinite_product.o
	$(CC) $(CFLAGS) $^ -o $@ -lm

codeinvim: codeinvim.c
	$(CC) $(CFLAGS) $^ -o $@

gigel_and_the_checkboard: gigel_and_the_checkboard.c
	$(CC) $(CFLAGS) $^ -o $@

nomogram: nomogram.c
	$(CC) $(CFLAGS) $^ -o $@

pack:
	zip -FSr 325CA_PopescuMariaBianca_Tema1.zip README Makefile *.c *.h

clean:
	rm -f $(TARGETS) $(OBJS)

.PHONY: pack clean
