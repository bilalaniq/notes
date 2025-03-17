# Distributed Systems

## **1. What is a Distributed System?**

A **distributed system** is a collection of **independent computers (nodes)** that communicate and coordinate over a network to achieve a common goal. These systems appear as a **single system** to the user but are actually made up of multiple machines working together.

🔹 **Example**: The internet, cloud computing (AWS, Google Cloud), blockchain networks, and microservices architecture.

---

## **2. Key Characteristics of Distributed Systems**

✅ **Multiple Nodes** – A distributed system consists of multiple independent computers.  
✅ **Network Communication** – Nodes communicate over a network (LAN, WAN, or the Internet).  
✅ **Decentralization** – No single point of control; decisions can be made at multiple points.  
✅ **Concurrency** – Multiple processes run at the same time.  
✅ **Fault Tolerance** – If one node fails, others continue working.  
✅ **Scalability** – Can add more nodes to increase performance.  
✅ **Transparency** – Users see it as a single system, not multiple computers.

---

## **3. Types of Distributed Systems**

| Type                               | Description                                                                      | Example                                                         |
| ---------------------------------- | -------------------------------------------------------------------------------- | --------------------------------------------------------------- |
| **Distributed Computing System**   | Multiple computers share processing power for a common task.                     | Cloud computing, parallel computing                             |
| **Distributed Information System** | A system where data is stored and processed across multiple locations.           | Banking systems, airline reservation systems                    |
| **Distributed File System**        | Files are stored across multiple machines but appear as a single storage system. | Google File System (GFS), Hadoop Distributed File System (HDFS) |
| **Distributed Database System**    | A database spread across multiple machines, but managed as one.                  | Google Bigtable, Amazon DynamoDB                                |
| **Peer-to-Peer System (P2P)**      | Every node is equal, and there is no central authority.                          | BitTorrent, Blockchain, Napster                                 |
| **Cluster Computing**              | A group of computers closely connected to function as one.                       | Supercomputers, Google Search servers                           |

---

## **4. Advantages of Distributed Systems**

✅ **Reliability** – If one node fails, the system still works.  
✅ **Scalability** – More nodes can be added to handle more tasks.  
✅ **Efficiency** – Load is shared across multiple machines.  
✅ **Resource Sharing** – Multiple users can share files, databases, and computing power.  
✅ **Low Latency** – Data can be processed close to the user, reducing delays.

---

## **5. Challenges of Distributed Systems**

🚩 **Network Latency** – Communication delay between nodes.  
🚩 **Security Issues** – More points of attack due to multiple systems.  
🚩 **Data Consistency** – Ensuring all nodes have the same data.  
🚩 **Fault Handling** – Detecting and recovering from node failures.  
🚩 **Concurrency Control** – Preventing conflicts when multiple processes access shared data.

---

## **6. Architecture of Distributed Systems**

### **(a) Client-Server Model**

- Clients request services, and servers provide them.
- Example: Web applications (Google, Facebook).

### **(b) Peer-to-Peer Model (P2P)**

- Every node acts as both client and server.
- Example: BitTorrent, blockchain.

### **(c) Three-Tier Architecture**

- Divides system into **Presentation Layer**, **Application Layer**, and **Database Layer**.
- Example: Web applications with front-end, business logic, and database.

### **(d) Microservices Architecture**

- System is broken into small services that communicate via APIs.
- Example: Netflix, Amazon.

---
