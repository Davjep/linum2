#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    int simpleSocket = 0, returnStatus = 0;
    char buffer[255] = "";
    struct sockaddr_in simpleServer;

    if (argc != 3)
    {
        fprintf(stderr, "Incorrect usage: %s. Expected: <server> <port>\n", argv[0]);
        exit(1);
    }

    char personalID[255];
    printf("Enter personal ID: ");
    scanf("%s", personalID);

    simpleSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (simpleSocket == -1)
    {
        fprintf(stderr, "Could not create socket\n");
        exit(1);
    }
    else
    {
        fprintf(stderr, "Socket created\n");
    }

    bzero(&simpleServer, sizeof(simpleServer));
    simpleServer.sin_family = AF_INET;
    simpleServer.sin_addr.s_addr = inet_addr(argv[1]);
    simpleServer.sin_port = htons(atoi(argv[2]));

    returnStatus = connect(simpleSocket, (struct sockaddr *)&simpleServer, sizeof(simpleServer));
    if (returnStatus != 0)
    {
        fprintf(stderr, "Could not connect to adress\n");
        close(simpleSocket);
        exit(1);
    }
    else
    {
        fprintf(stderr, "Connect completed\n");
    }

    write(simpleSocket, personalID, strlen(personalID));
    returnStatus = read(simpleSocket, buffer, sizeof(buffer));
    if (returnStatus > 0)
    {
        fprintf(stdout, "Return status = %d \n", returnStatus);
        fprintf(stdout, "Student: %s \n", buffer);
    }
    else
    {
        fprintf(stdout, "Return status -1: %d \n", returnStatus);
    }

    close(simpleSocket);
    return 9;
}