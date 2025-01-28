// client.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCKET_PATH "/tmp/unix_socket" // Path to the Unix domain socket file

int main() {
    int sock;
    struct sockaddr_un server_addr;
    char buffer[1024];

    // Create the socket (Unix domain socket)
    sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH); // The path to the socket file

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    const char *message = "Hello from the client!";
    if (write(sock, message, strlen(message)) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    int bytes_received = read(sock, buffer, sizeof(buffer));
    if (bytes_received == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received data
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}
