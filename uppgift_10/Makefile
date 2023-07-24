CC=gcc
CFLAGS=-Wall -std=c99

all: server client

server: linum_server.c
	$(CC) $(CFLAGS) -o server/server linum_server.c

client: linum_client.c
	$(CC) $(CFLAGS) -o client/client linum_client.c

clean:
	rm -f server/server client/client
