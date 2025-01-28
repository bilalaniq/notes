# The client server model

Most interprocess communication uses the client server model. These terms refer to the two processes which will be communicating with each other. One of the two processes, the client, connects to the other process, the server, typically to make a request for information. A good analogy is a person who makes a phone call to another person.


Notice that the client needs to know of the existence of and the address of the server, but the server does not need to know the address of (or even the existence of) the client prior to the connection being established.

Notice also that once a connection is established, both sides can send and receive information.

---


### The steps involved in establishing a socket on the client side are as follows:

- Create a socket with the `socket()` system call
- Connect the socket to the address of the server using the `connect()` system call
- Send and receive data. There are a number of ways to do this, but the simplest is to use the `read()` and `write()` system calls.
<br>
<br>



### The steps involved in establishing a socket on the server side are as follows:

- Create a socket with the `socket()` system call
- Bind the socket to an address using the `bind()` system call. For a server socket on the Internet, an address consists of a port number on the host machine.
- Listen for connections with the `listen()` system call
Accept a connection with the `accept()` system call. This call typically blocks until a client connects with the server.
- Send and receive data


---

## Socket
When a socket is created, the program has to specify the address domain and the socket type. Two processes can communicate with each other only if their sockets are of the same type and in the same domain.

1. ### address domains
There are two widely used address domains, 
- `unix domain`: in which two processes which share a common file system communicate
Unix domain sockets are used for inter-process communication (IPC) on the same machine (same host). These sockets allow processes that are running on the same operating system (OS) to communicate with each other.
The address of a socket in the Unix domain is a character string which is basically an entry in the file system.


- `Internet domain`: in which two processes running on any two hosts on the Internet communicate. Each of these has its own address format. These sockets use IP addresses and port numbers to communicate over a network.

The address of a socket in the Internet domain consists of the Internet address of the host machine (every computer on the Internet has a unique 32 bit address, often referred to as its IP address).
In addition, each socket needs a port number on that host.
Port numbers are 16 bit unsigned integers.
The lower numbers are reserved in Unix for standard services. For example, the port number for the FTP server is 21. It is important that standard services be at the same port on all computers so that clients will know their addresses.
However, port numbers above 2000 are generally available.


### Socket types
There are two widely used socket types
stream sockets, and datagram sockets. 
- `Stream sockets` treat communications as a continuous stream of characters
Stream sockets use TCP (Transmission Control Protocol), which is a reliable, stream oriented protocol

- `datagram sockets` have to read entire messages at once.  datagram sockets use UDP (User Datagram Protocol), which is unreliable and message oriented.

The examples in this tutorial will use sockets in the Internet domain using the TCP protocol.

