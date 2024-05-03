SSOURCES=$(wildcard ./src/*server.c)
CSOURCES=$(wildcard ./src/*client.c)

FLAGS=$(shell pkg-config --cflags --libs libmodbus)

ifdef GCC
	CC=gcc
else
	CC=arm-linux-gnueabi-gcc
endif

all: SERVER CLIENT

SERVER: $(SSOURCES)
	$(CC) -Wall -o server $(SSOURCES) $(FLAGS)

CLIENT: $(CSOURCES)
	$(CC) -Wall -o client $(CSOURCES) $(FLAGS)

clean:
	rm -rf *.o server client

.PHONY: all clean
