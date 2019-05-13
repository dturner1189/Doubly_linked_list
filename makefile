OUT = structtest
OBJECTS = driver.c list.h list.c

SOURCE_DIR = $(CURDIR)
CC = gcc

$(OUT): $(OBJECTS)
	$(CC) -o $(OUT) $^
	rm -rf *.o

%.0: %.c
	$(CC)-c -g -o $@ $<

clean:
	rm -rf $(OUT)
