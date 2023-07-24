#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define MAX_LINE_LENGTH 255

char *searchStudentByID(const char *studentID)
{
    FILE *file = fopen("students.txt", "r");
    if (!file)
    {
        perror("Error opening file");
        return NULL;
    }

    char *line = (char *)malloc(MAX_LINE_LENGTH);
    char *foundData = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        if (strncmp(line, studentID, strlen(studentID)) == 0)
        {
            foundData = (char *)malloc(strlen(line) + 1);
            strcpy(foundData, line);
            break;
        }
    }

    free(line);
    fclose(file);

    return foundData;
}

int main(int argc, char *argv[])
{
    int simpleSocket = 0, returnStatus = 0;
    struct sockaddr_in simpleServer;
    char *messageFromServer;
    char buffer[255] = "";
    messageFromServer = "Hello from Server";

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
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
    simpleServer.sin_addr.s_addr = htonl(INADDR_ANY);
    simpleServer.sin_port = htons(atoi(argv[1]));

    returnStatus = bind(simpleSocket, (struct sockaddr *)&simpleServer, sizeof(simpleServer));
    if (returnStatus != 0)
    {
        fprintf(stderr, "Could not bind to adress\n");
        close(simpleSocket);
        exit(1);
    }
    else
    {
        fprintf(stderr, "Bind completed\n");
    }

    returnStatus = listen(simpleSocket, 5);
    if (returnStatus == -1)
    {
        fprintf(stderr, "Could not listen to addresss\n");
        close(simpleSocket);
        exit(1);
    }
    else
    {
        fprintf(stderr, "Listen complete\n");
    }

    while (1)
    {
        struct sockaddr_in clientName = {0};
        int simpleChildSocket = 0;
        int clientNameLenght = sizeof(clientName);

        simpleChildSocket = accept(simpleSocket, (struct sockaddr *)&clientName, (socklen_t *)&clientNameLenght);
        if (simpleChildSocket == -1)
        {
            fprintf(stderr, "Cannot accept connection\n");
            close(simpleSocket);
            exit(1);
        }
        fprintf(stderr, "Client connected\n");
        read(simpleChildSocket, buffer, sizeof(buffer));
        fprintf(stderr, "Message from client: %s\n", buffer);
        messageFromServer = searchStudentByID(buffer);
        if (messageFromServer != NULL)
        {
            write(simpleChildSocket, messageFromServer, strlen(messageFromServer));
            free(messageFromServer);
        }
        else
        {
            write(simpleChildSocket, "Student not found.", sizeof("Student not found.") - 1);
        }
        write(simpleChildSocket, messageFromServer, strlen(messageFromServer));
        close(simpleChildSocket);
    }

    close(simpleSocket);
    return 0;
}