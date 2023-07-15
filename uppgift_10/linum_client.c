#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    char *message = "Hello from Client";
    int socket = 0, status = 0;
    char *buffer[255] = "";
    struct sockaddr_in server;

    if (argc != 3)
    {
        fprintf(stderr, "Fel flaggor: %s. Ange följande format: <server> <port>\n", argv[0]);
        exit(1);
    }
}