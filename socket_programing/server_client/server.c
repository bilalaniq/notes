// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h> // for Unix domain socket programming.

#define SOCKET_PATH "./unix_socket" // Path to the Unix domain socket file

int main()
{
    int server_sock, client_sock;
    struct sockaddr_un server_addr, client_addr;
    // These structures are used to store information about Unix domain socket addresses, both for the server and the client.
    //     in backend it looks like
    //  struct sockaddr_un {
    //      sa_family_t sun_family;   // Address family (should be AF_UNIX for Unix domain sockets)
    //      char sun_path[108];       // Path to the Unix domain socket (file system path)
    //  };

    char buffer[1024];
    socklen_t client_addr_len = sizeof(client_addr);
    // socklen_t is a data type used to represent the size of a socket address structure.

    // Create the socket (Unix domain socket)
    server_sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_sock == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    // AF_UNIX specifies the address family for the socket.
    // SOCK_STREAM  indicates that the socket is a stream socket
    // The third parameter specifies the protocol to be used. In most cases, when creating a stream socket, setting it to 0 allows the
    // system to choose the appropriate protocol (in this case, it will choose the default protocol for AF_UNIX sockets, which is
    // usually 0, meaning the system will use the default Unix domain socket protocol).
    // If you were creating an Internet domain socket (e.g., AF_INET for IPv4), you would typically specify a protocol like IPPROTO_TCP
    // for TCP or IPPROTO_UDP for UDP.

    // Prepare the server address
    memset(&server_addr, 0, sizeof(server_addr)); // Initializing the structure to 0
    server_addr.sun_family = AF_UNIX;
    strcpy(server_addr.sun_path, SOCKET_PATH); // The path to the socket file

    // Unlink the socket file if it already exists
    unlink(SOCKET_PATH);

    /*
      The unlink() function is a system call in Unix-like operating systems (such as Linux) that deletes a file or socket file from the filesystem.
      it is used for
      Cleanup: When the server application finishes using a Unix domain socket, the socket file should be deleted to avoid
      leaving stale socket files on the filesystem.
      Avoid Conflicts: If the socket file already exists before the server starts, the bind() function will fail because it cannot
      bind to an existing file. By calling unlink() before binding, you ensure that any existing socket file is removed before the
      server creates its new one.
    */

    // Bind the socket to the address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // the secound parameter is an backlog: This is the maximum number of connections that can be queued up before the system starts 
    // rejecting new connection requests. It essentially sets the size of the backlog queue for pending connections.

    printf("Server is listening on %s...\n", SOCKET_PATH);

    // Accept a client connection
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sock == -1)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Read data from the client
    int bytes_received = read(client_sock, buffer, sizeof(buffer));
    if (bytes_received == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }

    buffer[bytes_received] = '\0'; // Null-terminate the received data
    printf("Received from client: %s\n", buffer);

    // Send a response to the client
    const char *response = "Hello from the server!";
    if (write(client_sock, response, strlen(response)) == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the sockets
    close(client_sock);
    close(server_sock);
    unlink(SOCKET_PATH); // Remove the socket file

    return 0;
}
