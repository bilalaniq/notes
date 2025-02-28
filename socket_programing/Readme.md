# Sockets Programming in C using TCP/IP

Socket programming allows you to create networked applications that can communicate over a network using the socket interface. Sockets provide a mechanism for communication between two devices (hosts) over a network, either locally or across the internet. The most common use cases are client-server applications, where the client sends requests to the server, and the server responds.

---

Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.

---

## TCP/IP

TCP/IP provides end-to-end connectivity specifying how data
should be

- formatted
- addressed
- transmitted
- routed
- received at the destination

![tcp/ip](https://o.quizlet.com/ufjEhPrrLkJzRCGyBq91ow.png)

---

## TCP vs UDP

| **Feature**            | **TCP (Transmission Control Protocol)**                              | **UDP (User Datagram Protocol)**                         |
| ---------------------- | -------------------------------------------------------------------- | -------------------------------------------------------- |
| **Reliability**        | Reliable, ensures data delivery and order                            | Unreliable, no guarantee of delivery or order            |
| **Connection**         | Connection-oriented (requires handshake to establish connection)     | Connectionless, no connection setup                      |
| **Speed**              | Slower due to overhead (error checking, connection setup)            | Faster, minimal overhead                                 |
| **Data Order**         | Guarantees correct order of packets                                  | Does not guarantee packet order                          |
| **Error Checking**     | Built-in error checking, retransmission if data is lost or corrupted | Uses checksums for error detection but no retransmission |
| **Flow Control**       | Yes, uses flow control and congestion control                        | No flow control, relies on the application for handling  |
| **Congestion Control** | Yes, adjusts transmission rate to avoid network congestion           | No congestion control                                    |
| **Use Cases**          | Web browsing, file transfer, email, etc. (reliable applications)     | Streaming, VoIP, online gaming, DNS (real-time apps)     |
| **Header Size**        | Larger (20 bytes)                                                    | Smaller (8 bytes)                                        |
| **Performance**        | Lower performance due to overhead                                    | Higher performance due to less overhead                  |

Some common examples of TCP and UDP with their default ports:

- DNS lookup UDP 53
- FTP TCP 21
- HTTP TCP 80
- POP3 TCP 110
- Telnet TCP 23

---

# Berkley Sockets

- Universally known as Sockets
- It is an abstraction through which an
  application may send and receive data
- Provide generic access to interprocess
  communication services
- e.g. IPX/SPX, Appletalk, TCP/IP
- Standard API for networking

![socket](https://encrypted-tbn1.gstatic.com/images?q=tbn:ANd9GcQPmuYDDhSHyEvE7ojsHWSolHfT8CZGEmH4fS5r0wjpQypgyPYa)

## Sockets

- Uniquely identified by

  - an internet address
  - an end-to-end protocol (e.g. TCP or UDP)
  - a port number

- Two types of (TCP/IP) sockets

  - Stream sockets (e.g. uses TCP)
    - provide reliable byte-stream service
  - Datagram sockets (e.g. uses UDP)
    - provide best-effort datagram service
    - messages up to 65.500 bytes

- Socket extend the convectional UNIX I/O facilities
  - file descriptors for network communication
  - extended the read and write system calls

lets explain the last point
Socket extend the convectional UNIX I/O facilities

`UNIX I/O Facilities`: In a typical UNIX-based system, communication with files, devices, and other resources happens through file descriptors. A file descriptor is an integer that represents an open file or a stream in the operating system. When you use standard system calls like read(), write(), open(), and close(), you're interacting with file descriptors.
Sockets for Network Communication: A socket is an endpoint for communication between two machines over a network. Sockets allow processes to communicate with each other over the internet or a local network. A socket is similar to a file in the sense that you can think of it as a resource that can be read from or written to, just like you would with a file on disk.

`File Descriptors for Network Communication`: In UNIX, a socket is treated just like a file. When you create a socket (using the socket() system call), the system assigns it a file descriptor. You can then use the standard UNIX system calls, like read(), write(), open(), and close(), to communicate over the network through this socket. This is a key point: sockets extend the concept of file descriptors to network communication.

`Extended Read and Write System Calls`: Normally, the read() and write() system calls are used to read from and write to files. With sockets, these system calls are extended to also handle network communication. For example:

read() can be used to receive data over a network connection through a socket.
write() can be used to send data over a network connection via the socket.

![socket](https://www.researchgate.net/publication/307941914/figure/fig4/AS:667790130294800@1536224982874/Network-communication-via-UDP-TCP-sockets-22.ppm)

---

<br>
<br>
<br>


The socket() function in c has the following parameters 

```c
int sockid = socket(family, type, protocol);
```

<br>



- ## Family 

The **"family"** in a socket refers to the **communication domain** or the type of addresses that will be used with the socket. The communication domain determines how the socket communicates with other sockets (i.e., over the network, locally, etc.). Here are some of the most common socket families:

### Common Socket Families

1. **`PF_INET` (IPv4)**:
   - **Meaning**: Stands for **"Protocol Family: Internet"**. This is used for **IPv4** (Internet Protocol version 4) communication over the network.
   - **Used For**: Standard networking, such as web browsers, email, file transfers, etc.
   - **Address Type**: **IPv4 addresses** (e.g., `192.168.1.1`).
   - **Protocol**: Typically **TCP** or **UDP**.
   
   ```c
   sockfd = socket(PF_INET, SOCK_STREAM, 0); // For TCP/IP communication
   ```

2. **`PF_INET6` (IPv6)**:
   - **Meaning**: Stands for **"Protocol Family: Internet Version 6"**. This is used for **IPv6** (Internet Protocol version 6), which is the successor to IPv4.
   - **Used For**: Networking with **IPv6** addresses (e.g., `fe80::1`), which allows for a larger address space and better routing.
   - **Address Type**: **IPv6 addresses** (e.g., `fe80::1`).
   - **Protocol**: Typically **TCP** or **UDP**.
   
   ```c
   sockfd = socket(PF_INET6, SOCK_STREAM, 0); // For IPv6 communication
   ```

3. **`PF_UNIX` or `PF_LOCAL` (Local Communication)**:
   - **Meaning**: Used for **inter-process communication (IPC)** on the **same machine** (local communication). The socket operates using **file system paths** instead of IP addresses.
   - **Used For**: Local applications or processes running on the same system (e.g., a database server and a client on the same machine).
   - **Address Type**: **Unix file system paths** (e.g., `/tmp/mysocket`).
   - **Protocol**: **Local communication**.
   
   ```c
   sockfd = socket(PF_UNIX, SOCK_STREAM, 0); // For local communication
   ```

4. **`PF_PACKET` (Raw Packet Communication)**:
   - **Meaning**: This is used for **low-level network interface communication**. It allows the socket to directly access the network interface to send/receive raw packets.
   - **Used For**: Specialized network operations, like **packet sniffing** or **raw socket communication** at the data link layer (e.g., Ethernet).
   - **Protocol**: Allows for raw access to the network stack (e.g., working with Ethernet frames).
   
   ```c
   sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL)); // For raw packet access
   ```

5. **`PF_NETLINK` (Kernel/User-space Communication)**:
   - **Meaning**: Used for communication between the **kernel** and **user-space applications**. This is mainly used for **network configuration** and **netlink sockets**.
   - **Used For**: Kernel communication with user-space programs, for example, for network configuration tasks or network interface status monitoring.
   
   ```c
   sockfd = socket(PF_NETLINK, SOCK_RAW, NETLINK_ROUTE); // For netlink communication
   ```

6. **`PF_TIPC` (Transparent Inter-Process Communication)**:
   - **Meaning**: The **TIPC (Transparent Inter-Process Communication)** protocol family is used for **highly available, fault-tolerant, and distributed systems**.
   - **Used For**: Communication in a cluster of machines. Typically used in high-availability systems (like databases or distributed applications).
   
   ```c
   sockfd = socket(PF_TIPC, SOCK_RDM, 0); // For TIPC communication
   ```

7. **`PF_KEY` (IPsec)**:
   - **Meaning**: Used for **IPsec (Internet Protocol Security)** related operations.
   - **Used For**: Handling key management protocols related to IPsec.
   
   ```c
   sockfd = socket(PF_KEY, SOCK_RAW, 0); // For IPsec key management
   ```

8. **`PF_XDP` (eXpress Data Path)**:
   - **Meaning**: This is used for **high-performance networking** with **eBPF** (extended Berkeley Packet Filter). It allows high-throughput packet processing, often used in low-latency applications like network switches.
   - **Used For**: Advanced network performance techniques, often in data centers or network appliances.
   
   ```c
   sockfd = socket(PF_XDP, SOCK_RAW, 0); // For high-performance data path
   ```

### Summary of Socket Families:

| **Family**       | **Description**                                     | **Common Use**                                |
| ---------------- | --------------------------------------------------- | --------------------------------------------- |
| **`PF_INET`**    | IPv4 (Internet Protocol version 4)                  | Standard networking (web, email, etc.)        |
| **`PF_INET6`**   | IPv6 (Internet Protocol version 6)                  | Networking with IPv6 addresses                |
| **`PF_UNIX`**    | Local communication using file paths                | IPC between processes on the same machine     |
| **`PF_PACKET`**  | Raw packet communication (access to the link layer) | Packet sniffing, raw socket communication     |
| **`PF_NETLINK`** | Communication with the kernel and user-space apps   | Network configuration, kernel-user space comm |
| **`PF_TIPC`**    | Transparent Inter-Process Communication             | High availability systems, distributed apps   |
| **`PF_KEY`**     | IPsec (Internet Protocol Security)                  | Key management for IPsec                      |
| **`PF_XDP`**     | High-performance network data path                  | Low-latency, high-throughput networking       |

### Additional Details:
- **`PF_INET`** and **`PF_INET6`** are the most commonly used families for **Internet-based** communication. They use IP addresses (IPv4 or IPv6) to identify the source and destination of communication.
- **`PF_UNIX`** is used for communication between processes on the **same machine** and does not use IP addresses, but instead uses **file system paths** to create and access sockets.
- **`PF_PACKET`** allows for direct access to network hardware and is used for specialized tasks like monitoring or processing raw packets.

<br>
<br>

- ## Type
In socket programming, the **type** of socket defines the communication characteristics, such as whether the communication is reliable, connection-based, connectionless, and whether it is stream-oriented or message-oriented. Here are the key socket types that you might encounter:

### 1. **`SOCK_STREAM`**:
   - **Description**: 
     - **Reliable**, **two-way**, **connection-based** communication.
     - This type of socket is used for **stream-oriented communication**, which means data is sent in a continuous stream of bytes.
     - It is used when you need **reliable communication** where the data is guaranteed to be delivered in order and without errors (thanks to protocols like **TCP**).

   - **Characteristics**:
     - **Connection-based**: Before sending or receiving data, a connection must be established between the sender and receiver. The connection is maintained for the duration of the communication.
     - **Reliable**: It ensures that the data reaches the destination without errors. If there is any packet loss, retransmission will occur automatically.
     - **Two-way communication**: Data can be sent and received in both directions (client to server and server to client).
     - **In-order delivery**: Data is received in the exact order in which it was sent.
   
   - **Common Protocols**:
     - **TCP** (Transmission Control Protocol): Used for ensuring reliable and ordered delivery of data over the network.
   
   - **Example Use Case**:
     - **Web Browsing (HTTP)**, **Email (SMTP, IMAP)**, **FTP**.
   
   - **Example Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_STREAM, 0);  // TCP Socket
     ```

### 2. **`SOCK_DGRAM`**:
   - **Description**:
     - **Unreliable**, **connectionless**, **message-oriented** communication.
     - This type of socket is used for **datagram communication**, where data is sent as discrete packets or messages.
     - It does not guarantee delivery, order, or error correction, so the application needs to handle these issues (if needed).

   - **Characteristics**:
     - **Connectionless**: No need to establish a connection before sending data. Each message is sent independently from the others, and the receiver may not even be ready to receive it.
     - **Unreliable**: The system makes no guarantees about the delivery or integrity of the data. If the data is lost, it is not automatically retransmitted.
     - **Message-oriented**: Data is sent in discrete chunks (datagrams). Each message is sent as a whole and is not broken up into smaller chunks, unlike stream-based sockets.
     - **No in-order delivery**: The order in which messages are received is not guaranteed.

   - **Common Protocols**:
     - **UDP** (User Datagram Protocol): Provides a fast but unreliable communication service where packets may be lost, duplicated, or arrive out of order.
   
   - **Example Use Case**:
     - **DNS** (Domain Name System), **Streaming media** (audio/video), **Online games**, **VoIP** (Voice over IP).
   
   - **Example Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // UDP Socket
     ```

### 3. **`SOCK_RAW`**:
   - **Description**:
     - **Raw socket** allows direct access to lower layers of the network stack.
     - Used to send or receive packets without any protocol-specific headers (e.g., IP, TCP, UDP headers). This allows for custom packet construction or packet inspection.

   - **Characteristics**:
     - **Direct access to network layer**: No protocol handling (like TCP/UDP) is done by the kernel.
     - Used for **custom protocols**, **network diagnostics**, or **packet sniffing**.
     - **Requires administrative privileges** in many systems (because raw sockets can manipulate low-level network packets).
   
   - **Common Protocols**:
     - **IP** (Internet Protocol), **ICMP** (Internet Control Message Protocol).
   
   - **Example Use Case**:
     - **Network tools** like **ping**, **traceroute**, and custom network security tools.
   
   - **Example Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);  // Raw socket for ICMP
     ```

### 4. **`SOCK_SEQPACKET`**:
   - **Description**:
     - **Reliable**, **connection-oriented**, but **message-based** communication.
     - Data is sent in **separate messages** that are delivered in the order they were sent and without any loss.
     - It's **reliable** like `SOCK_STREAM`, but it is message-oriented like `SOCK_DGRAM`.

   - **Characteristics**:
     - **Connection-based**: A connection is established before communication starts.
     - **Message-oriented**: Data is sent as discrete chunks or packets, similar to `SOCK_DGRAM`.
     - **Reliable**: Guarantees delivery of each message without duplication, and in order.
     - **Ordered delivery**: Unlike `SOCK_DGRAM`, the messages are received in the order they were sent.
   
   - **Common Protocols**:
     - This socket type is rarely used but could be implemented by protocols like **ISO Transport Protocol** (ISO 8073).
   
   - **Example Use Case**:
     - Some specialized **transport protocols** that need reliable, message-based communication.

   - **Example Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_SEQPACKET, 0);  // Sequenced, reliable, message-based
     ```

### 5. **`SOCK_RDM`** (Reliable Datagram):
   - **Description**:
     - **Reliable**, **connectionless**, **message-based** communication.
     - This type is typically used for a communication method where **messages are reliable** but no connection is established (similar to `SOCK_DGRAM` but with reliability).
   
   - **Characteristics**:
     - **Connectionless**: No need to establish a connection before sending data.
     - **Reliable**: Guarantees that the messages will be delivered without loss, and typically in the correct order.
     - **Message-oriented**: Like `SOCK_DGRAM`, data is sent as discrete messages.
   
   - **Common Protocols**:
     - **RDM** (Reliable Datagram Protocol) or some custom protocols designed for specific applications.
   
   - **Example Use Case**:
     - **Fault-tolerant applications** that need reliable delivery but don’t require a connection.

   - **Example Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_RDM, 0);  // Reliable datagram socket
     ```

### Summary of Socket Types:

| **Socket Type**    | **Description**                                       | **Protocol Example** | **Communication Characteristics**                                    |
| ------------------ | ----------------------------------------------------- | -------------------- | -------------------------------------------------------------------- |
| **SOCK_STREAM**    | Reliable, two-way, connection-based (Stream-oriented) | **TCP**              | Connection-based, reliable, in-order data delivery                   |
| **SOCK_DGRAM**     | Unreliable, connectionless, message-oriented          | **UDP**              | Connectionless, unreliable, no order guarantee                       |
| **SOCK_RAW**       | Low-level communication (access to raw packets)       | **IP**, **ICMP**     | Custom packet manipulation, used for diagnostics or custom protocols |
| **SOCK_SEQPACKET** | Reliable, connection-oriented, message-based          | **ISO Transport**    | Connection-based, reliable, message-based, in-order delivery         |
| **SOCK_RDM**       | Reliable, connectionless, message-based (rarely used) | **RDM**              | Connectionless, reliable, message-oriented, in-order delivery        |

### Which to Use?

- **SOCK_STREAM (TCP)**: Use when you need **reliable**, **ordered**, and **two-way** communication, like web browsing, file transfer, or email.
- **SOCK_DGRAM (UDP)**: Use for **unreliable**, **fast**, and **simple** communication where packet loss is acceptable (e.g., real-time applications like video streaming or online gaming).
- **SOCK_RAW**: Use for **custom packet manipulation** and network diagnostics (e.g., packet sniffing, custom network tools).
- **SOCK_SEQPACKET**: Use for situations where you need **reliable** message-based communication, and you need to send and receive discrete messages reliably.
- **SOCK_RDM**: Use for **connectionless**, **reliable**, and **message-oriented** communication where you want reliability but don’t need a connection to be established (rare use case).



<br>
<br>

- ## protocol

In socket programming, the **protocol** field specifies which protocol to use for the communication. The protocol is used in conjunction with the **family** (e.g., `AF_INET` for IPv4) and **type** (e.g., `SOCK_STREAM` for TCP) to define how data is transmitted between computers.

While the **family** and **type** determine the general structure of the communication, the **protocol** specifies a more specific method or implementation for that communication. Below are explanations for common protocol options used in socket programming.

### Common Protocol Options:
1. **`IPPROTO_TCP`** (Transmission Control Protocol):
   - **Description**: 
     - `IPPROTO_TCP` specifies that the protocol used for communication will be **TCP** (Transmission Control Protocol). TCP is a **connection-oriented** protocol, meaning that before data can be sent, a connection must be established between the sender and the receiver.
   - **Characteristics**:
     - **Reliable**: Ensures that the data is delivered in order and without errors. If a packet is lost, it will be retransmitted.
     - **Stream-oriented**: Data is sent as a continuous stream of bytes, without boundaries.
     - **Flow Control**: Uses mechanisms to prevent network congestion and ensure that the sender does not overwhelm the receiver.
     - **Connection Establishment**: Requires a handshake process (SYN, SYN-ACK, ACK) to establish the connection between the client and the server.
   - **Common Use**: 
     - Web browsing (HTTP/HTTPS), File Transfer (FTP), Email (SMTP, IMAP).
   - **Example in Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // TCP Socket
     ```

2. **`IPPROTO_UDP`** (User Datagram Protocol):
   - **Description**:
     - `IPPROTO_UDP` specifies that the protocol used will be **UDP** (User Datagram Protocol). UDP is a **connectionless** and **unreliable** protocol, which means there is no formal connection setup or guarantee of delivery.
   - **Characteristics**:
     - **Unreliable**: There is no guarantee that data will be delivered. Lost packets are not retransmitted, and out-of-order delivery may occur.
     - **Datagram-oriented**: Data is sent in discrete packets (datagrams), and each packet is treated independently.
     - **No Connection Setup**: No handshake is required to start communication. Each message (datagram) is sent individually.
     - **Low Overhead**: Because of the lack of error correction and connection setup, UDP has lower overhead and is faster than TCP.
   - **Common Use**:
     - Real-time applications such as streaming audio/video (e.g., IPTV), online gaming, VoIP (Voice over IP), DNS (Domain Name System) queries.
   - **Example in Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);  // UDP Socket
     ```

3. **`IPPROTO_ICMP`** (Internet Control Message Protocol):
   - **Description**:
     - `IPPROTO_ICMP` specifies that the protocol used will be **ICMP**. ICMP is used for network diagnostics and error reporting (e.g., used by tools like `ping` and `traceroute`).
   - **Characteristics**:
     - **Error Reporting**: Used for sending error messages indicating issues with packet delivery (e.g., "Destination Unreachable").
     - **Diagnostic**: Provides feedback about network conditions and operational status.
     - **Connectionless**: ICMP does not establish a connection between endpoints; it simply sends and receives messages.
   - **Common Use**:
     - Tools like **ping**, **traceroute**, and **network diagnostics**.
   - **Example in Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);  // Raw Socket for ICMP
     ```

4. **`IPPROTO_RAW`** (Raw Socket):
   - **Description**:
     - `IPPROTO_RAW` is used for **raw sockets**. This allows direct access to the IP layer, bypassing the transport layer protocols like TCP and UDP. It is typically used for custom protocols or network diagnostics (e.g., custom packet generation or packet sniffing).
   - **Characteristics**:
     - **Direct Access to IP Layer**: With raw sockets, the application can create its own packet headers, unlike with TCP or UDP, which automatically handle the headers.
     - **Network Control**: Raw sockets allow more granular control over the packet data but are typically only available to privileged users (admin/root).
     - **Custom Protocols**: It can be used for creating and testing custom network protocols.
   - **Common Use**:
     - **Packet Sniffing** (e.g., Wireshark), **Network Security Testing**, **Custom Protocol Development**.
   - **Example in Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);  // Raw Socket for custom protocols
     ```

5. **`IPPROTO_IP`** (Generic IP Protocol):
   - **Description**:
     - `IPPROTO_IP` is used for **generic IP-level** communication. It allows applications to work at the IP layer without specifying a specific transport protocol (like TCP or UDP).
   - **Characteristics**:
     - **Generic Protocol**: It is a placeholder that allows sending and receiving packets without defining the transport layer protocol.
     - It is generally used with raw sockets to handle IP-level operations.
   - **Common Use**:
     - Used in advanced networking tasks where a specific transport protocol is not required, or when working directly with the IP layer.
   - **Example in Code**:
     ```c
     int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_IP);  // Generic IP Protocol
     ```

6. **`IPPROTO_UDP` and `IPPROTO_TCP` for IPv6**:
   - **`IPPROTO_TCP` and `IPPROTO_UDP`** can also be used with **IPv6**. In this case, the socket family would be set to **`AF_INET6`**, and the protocol field specifies whether you are using TCP or UDP for IPv6 communication.
   - Example for IPv6:
     ```c
     int sockfd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);  // TCP over IPv6
     int sockfd = socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP);  // UDP over IPv6
     ```

### Default Protocol (Set to 0):
- **Default Behavior**: If the **protocol** field is set to **0**, the operating system automatically selects the appropriate protocol based on the **socket family** and **socket type**.
  - For example, if you choose `SOCK_STREAM` for the socket type, the protocol will default to **`IPPROTO_TCP`**.
  - Similarly, if you choose `SOCK_DGRAM`, the protocol will default to **`IPPROTO_UDP`**.

### Summary of Protocols:

| **Protocol Name**      | **Protocol Identifier**  | **Typical Use**                                     | **Common Protocol**  |
|------------------------|--------------------------|-----------------------------------------------------|----------------------|
| **Transmission Control Protocol (TCP)** | `IPPROTO_TCP`              | Reliable, connection-oriented communication (e.g., HTTP, FTP) | **TCP**              |
| **User Datagram Protocol (UDP)**        | `IPPROTO_UDP`              | Connectionless, unreliable communication (e.g., DNS, VoIP) | **UDP**              |
| **Internet Control Message Protocol (ICMP)** | `IPPROTO_ICMP`            | Error and diagnostic reporting (e.g., ping, traceroute) | **ICMP**             |
| **Raw Protocol**      | `IPPROTO_RAW`             | Direct IP-layer communication, custom protocols     | **Raw**              |
| **Generic IP Protocol** | `IPPROTO_IP`              | Used for IP-level operations, bypassing transport protocols | **IP**               |

### When to Use Each Protocol:
- **`IPPROTO_TCP`**: Use when you need reliable, ordered, and connection-based communication (e.g., web browsing, email).
- **`IPPROTO_UDP`**: Use when you need faster, connectionless communication, where reliability is not critical (e.g., streaming, real-time gaming, DNS).
- **`IPPROTO_ICMP`**: Use when performing network diagnostics or reporting errors (e.g., ping, traceroute).
- **`IPPROTO_RAW`**: Use when you need direct access to the IP layer or want to build a custom protocol (e.g., network tools, packet sniffers).
- **`IPPROTO_IP`**: Use in advanced networking applications requiring access to the raw IP layer.

In general, most socket applications will default to `0` for the protocol field, and the operating system will select the correct protocol automatically based on the socket type (`SOCK_STREAM` or `SOCK_DGRAM`). However, specifying a protocol can give you more control over your communication if needed.



---

# Client-Server communication

### **Basic Concepts**

In socket programming, you need to understand a few basic concepts:

- **Socket:** An endpoint for communication between two machines.
- **Server:** Listens for incoming requests from clients and responds.
  - `passive socket`: passive socket refers to a socket that is used to listen for incoming network connections
- **Client:** Sends requests to the server and waits for a response.
  - `active socket` : active socket refers to a socket that is used to initiate a connection to a remote server
  - must know the address and the port of the server
- **IP Address:** Identifies a device on the network.
- **Port Number:** Identifies a specific application or service on the device.
- **Protocol:** Defines the rules for communication (e.g., TCP, UDP).

The two main types of sockets are:

- **Stream Sockets (TCP):** Reliable, connection-oriented communication. Ensures data arrives in order.
- **Datagram Sockets (UDP):** Unreliable, connectionless communication. Does not guarantee order or delivery.

### **Sockets - Procedures**

Socket programming typically involves the following steps:

1. **Create a socket.**
2. **Bind the socket to a specific IP and port.**
3. **Listen for incoming connections (on the server-side).**
4. **Accept connections (on the server-side).**
5. **Send and receive data.**
6. **Close the socket.**



| **Primitive** | **Meaning**                                     |
| ------------- | ----------------------------------------------- |
| **Socket**    | Create a new communication endpoint             |
| **Bind**      | Attach a local address to a socket              |
| **Listen**    | Announce willingness to accept connections      |
| **Accept**    | Block caller until a connection request arrives |
| **Connect**   | Actively attempt to establish a connection      |
| **Send**      | Send some data over the connection              |
| **Receive**   | Receive some data over the connection           |
| **Close**     | Release the connection                          |


---

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png)

---
