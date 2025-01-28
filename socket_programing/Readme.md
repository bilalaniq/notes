Socket programming  allows you to create networked applications that can communicate over a network using the socket interface. Sockets provide a mechanism for communication between two devices (hosts) over a network, either locally or across the internet. The most common use cases are client-server applications, where the client sends requests to the server, and the server responds.

---

Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while the other socket reaches out to the other to form a connection. The server forms the listener socket while the client reaches out to the server.

---

![alt text](https://media.geeksforgeeks.org/wp-content/uploads/20220330131350/StatediagramforserverandclientmodelofSocketdrawio2-448x660.png)

---


### **1. Basic Concepts**
In socket programming, you need to understand a few basic concepts:
- **Socket:** An endpoint for communication between two machines.
- **Server:** Listens for incoming requests from clients and responds.
- **Client:** Sends requests to the server and waits for a response.
- **IP Address:** Identifies a device on the network.
- **Port Number:** Identifies a specific application or service on the device.
- **Protocol:** Defines the rules for communication (e.g., TCP, UDP).

The two main types of sockets are:
- **Stream Sockets (TCP):** Reliable, connection-oriented communication. Ensures data arrives in order.
- **Datagram Sockets (UDP):** Unreliable, connectionless communication. Does not guarantee order or delivery.

### **2. Socket Programming Steps**
Socket programming typically involves the following steps:

1. **Create a socket.**
2. **Bind the socket to a specific IP and port.**
3. **Listen for incoming connections (on the server-side).**
4. **Accept connections (on the server-side).**
5. **Send and receive data.**
6. **Close the socket.**

---

Socket programming in C provides a foundation for networked applications and services. While the above example is a basic server-client setup, you can extend it with features such as file transfer, remote procedure calls (RPC), or chat applications, all of which rely on these basic principles of socket communication.