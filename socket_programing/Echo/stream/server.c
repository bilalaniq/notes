#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // for socket(), bind(), listen(), accept(), etc.
#include <netinet/in.h> // for sockaddr_in, IPPROTO_TCP, and other network-related constants
#include <arpa/inet.h>  // for inet_addr() and inet_pton(), which help with IP address conversions
#include <unistd.h>     // for close() system call

#define echoServPort 8080
#define MAXPENDING 5

void DieWithError(const char *errorMessage, int sockfd)
{
    perror(errorMessage);
    close(sockfd);
    exit(1);
}

int main()
{
    int servSock, clientSock;
    struct sockaddr_in echoServAddr, clietAddr;
    socklen_t clientlen;

    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        perror("socket not created succesfully");
        exit(1);
    }

    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    echoServAddr.sin_port = htons(echoServPort);      /* Local port */

    if (bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
    {
        DieWithError("bind() failed", servSock);
    }

    if (listen(servSock, MAXPENDING) < 0)
    {
        DieWithError("listen() failed", servSock);
    }

    printf("Waiting for connections on port %d...\n", echoServPort);

    for (;;)
    {
        clientlen = sizeof(clietAddr);
        if ((clientSock = accept(servSock, (struct sockaddr *)&clientSock, &clientlen)) < 0)
        {
            DieWithError("accept() failed", servSock);
        }
    }

    return 0;
}
