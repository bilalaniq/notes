# Computing Environments

- Traditional
- Mobile
- Client-Server
- Peer-to-Peer
- Cloud computing
- Real-time Embedded

---

<br>
<br>

# Traditional

Traditional computing, often referred to as classical computing, involves the processing of data using conventional computational models, algorithms, and hardware systems. This type of computing is based on the principles of **Boolean logic**, **binary operations**, and **deterministic processes**.

### 1. **Fundamentals of Traditional Computing**

At the heart of traditional computing is the **binary system** and **digital logic**. In classical computing, data is represented in **binary format** (0s and 1s), where each bit (short for binary digit) can hold one of two values, either 0 or 1. These bits are used to encode all kinds of data and instructions.

#### 1.1 **Binary Representation**

- **Bit**: The smallest unit of data in traditional computing. It can either be a 0 or a 1.
- **Byte**: A group of 8 bits, commonly used as the basic unit of data storage.
- **Data Structures**: Larger data structures like integers, floats, strings, and images are ultimately stored as binary data.

#### 1.2 **Boolean Logic**

- The core of classical computing is Boolean algebra, which operates on binary values using logical operations like AND, OR, NOT, XOR, etc.
- **AND**: Both inputs must be true for the output to be true.
- **OR**: At least one input must be true for the output to be true.
- **NOT**: Inverts the input.

These operations are the building blocks of computational circuits and algorithms.

### 2. **Key Components of Traditional Computers**

#### 2.1 **Central Processing Unit (CPU)**

The **CPU** is the brain of the computer and executes instructions from programs. It performs basic arithmetic, logic, control, and input/output operations specified by instructions in the program.

- **Control Unit (CU)**: Directs the operation of the processor by interpreting and executing instructions.
- **Arithmetic Logic Unit (ALU)**: Performs arithmetic and logical operations.
- **Registers**: Small, fast storage locations within the CPU that temporarily hold data, instructions, and addresses.

#### 2.2 **Memory**

Memory is used to store data and instructions that the CPU can access quickly. Traditional memory is often divided into two categories:

- **Primary Memory (RAM)**: Volatile memory that stores data that is actively used by the CPU. When the computer is powered off, this data is lost.
- **Secondary Memory (Storage)**: Non-volatile memory such as hard drives (HDDs), solid-state drives (SSDs), or optical disks, where data is stored persistently.

#### 2.3 **Input and Output (I/O)**

Input devices (such as keyboards, mice, and sensors) allow the user to interact with the computer, while output devices (such as monitors, printers, and speakers) display or present the results of computations.

- **Input**: Accepts data from the outside world (keyboard, mouse, microphone, etc.).
- **Output**: Sends data to the outside world (monitor, speakers, printers, etc.).

### 3. **Traditional Computing Models**

#### 3.1 **Von Neumann Architecture**

The most commonly used architecture in traditional computing is the **Von Neumann architecture**. It is a design model that describes a computer with the following components:

- **Memory**: Stores data and instructions.
- **Control Unit**: Fetches instructions from memory, decodes them, and executes them.
- **ALU (Arithmetic Logic Unit)**: Performs the calculations.
- **Input/Output (I/O)**: Facilitates communication with external devices.

A key feature of this architecture is that both **data** and **program instructions** are stored in the same memory space, leading to the **Von Neumann bottleneck**, which is the limitation of throughput between the CPU and memory.

#### 3.2 **Stored Program Concept**

This concept means that a computer’s program is stored in its memory and can be modified and executed. The instructions are fetched one at a time from memory and executed by the CPU.

#### 3.3 **Turing Machine**

The **Turing Machine** is a theoretical model of computation invented by Alan Turing. It consists of:

- **Tape**: An infinite memory that stores symbols.
- **Head**: Reads and writes symbols on the tape.
- **State Register**: Holds the current state of the machine.
- **Transition Function**: Dictates the next state based on the current state and symbol.

This model is a basis for understanding what can be computed and forms the foundation of modern computational theory.

---

<br>
<br>

# Mobile

Mobile computing refers to the use of portable computing devices, such as smartphones, tablets, laptops, and wearable technologies, to access, process, and store data while on the move. It relies on wireless networks like Wi-Fi, cellular, and Bluetooth to enable internet connectivity and data transfer. Mobile computing empowers users to stay connected to digital resources, communicate, work, and access applications anytime and anywhere, making it a vital aspect of modern life and business. The key benefits include increased flexibility, convenience, and productivity, but it also introduces challenges related to battery life, security, and network reliability.

---

<br>
<br>

# Client-Server

### **Client-Server Computing: Definition**

Client-server computing is a **network architecture** where multiple clients (computers or devices) request and receive services from a central server. The server processes requests, manages resources, and provides data or services to the clients over a network.

---

### **Key Components**

1. **Client**

   - Requests services from the server.
   - Can be a computer, smartphone, or any other device.
   - Examples: Web browsers, email applications.

2. **Server**

   - Processes client requests and provides the necessary data or services.
   - Can be a physical machine or a cloud-based system.
   - Examples: Web servers, database servers, file servers.

3. **Network**
   - Connects clients and servers.
   - Can be a LAN (Local Area Network) or the Internet.

---

Server systems can be broadly categorized as `compute servers` and `file servers`:

- The `compute-server system` provides an interface to which a client can
  send a request to perform an action (for example, read data). In response,
  the server executes the action and sends the results to the client. A server running a database that responds to client requests for data is an example
  of such a system.

- The `file-serve system` provides a file-system interface where clients can
  create, update, read, and delete files. An example of such a system is a
  web server that delivers files to clients running web browsers. The actual
  contents of the files can vary greatly, ranging from traditional web pages
  to rich multimedia content such as high-definition video.

![CLIENT-SERVER](https://velog.velcdn.com/images/kkj6235/post/f3468010-a618-43d6-bb05-3b05251427f7/image.png)

---

<br>
<br>

# Peer-to-Peer

### **Peer-to-Peer (P2P) Systems – Simplified Summary**

In a **Peer-to-Peer (P2P) system**, there is no fixed distinction between clients and servers. Instead, all devices (called **peers**) can act as both **clients** (requesting services) and **servers** (providing services). This model removes the bottleneck issue found in traditional **client-server** systems, as multiple peers share the workload.

#### **How Peers Join and Find Services**

1. **Using a Centralized Lookup Server:**

   - A new peer registers its services with a **centralized server**.
   - When another peer needs a service, it contacts this server to find a provider.
   - After that, direct communication happens between the peers.

2. **Using a Decentralized Discovery Method:**
   - No central server is involved.
   - A peer broadcasts a request to all other peers in the network.
   - The peer offering the requested service responds directly.
   - A **discovery protocol** helps peers find available services.

#### **Examples of P2P Systems**

- **Napster (1990s):** Used a **centralized** lookup server to index files but allowed direct file sharing between peers. It was shut down in 2001 due to copyright issues.
- **Gnutella:** Used a **fully decentralized** approach where peers broadcast file requests to find providers.
- **Skype:** Uses a **hybrid model**—a centralized server for login, but **peer-to-peer communication** for calls and messages.

#### **Advantages of P2P Systems**

- No single point of failure like in client-server systems.
- Distributes workload across multiple peers.
- Reduces dependence on a central server.

However, **P2P networks can be misused** for sharing copyrighted materials illegally, leading to legal issues, as seen with **Napster**.

![p2p](https://www.cs.csustan.edu/~john/Classes/CS3750/Notes/Chap01/1_23p2pSys.jpg)

---

<br>
<br>

# Cloud computing

**Cloud computing** is a way of delivering **computing power, storage, and applications** as a **service** over a network, usually the **Internet**. Instead of buying and maintaining expensive hardware, users can **rent** resources and pay based on their usage.

It builds on **virtualization**, which allows multiple virtual machines (VMs) to run on a single physical machine. This makes cloud computing **flexible, scalable, and cost-effective**.

#### **Types of Cloud Computing**

1. **Public Cloud:** Available to anyone on the Internet, provided by companies like **Amazon AWS, Google Cloud, and Microsoft Azure**.
2. **Private Cloud:** Owned and used **exclusively** by a company for its own operations.
3. **Hybrid Cloud:** A mix of **public and private clouds**, allowing businesses to store **sensitive data privately** while using public cloud resources for other tasks.

#### **Cloud Service Models**

- **SaaS (Software as a Service):** Ready-to-use applications like **Google Docs, Gmail, or Dropbox** that run on the cloud.
- **PaaS (Platform as a Service):** A **development environment** that includes tools like databases, frameworks, and runtime environments (e.g., **Google App Engine, AWS Elastic Beanstalk**).
- **IaaS (Infrastructure as a Service):** Provides **virtual servers and storage** (e.g., **Amazon EC2, Google Compute Engine**).

---

### **How Virtual Machines (VMs) Relate to Cloud Computing**

- A **Virtual Machine (VM)** is a **software-based computer** that runs inside a physical machine using **virtualization technology**.
- Cloud providers **host thousands or millions of VMs** on powerful servers.
- Users can **rent** these VMs instead of buying real servers.
- Virtualization allows **efficient resource use**, as multiple VMs can share the same physical machine.
- **Example:** Amazon EC2 provides virtual machines on demand.

**Key Benefits of VMs in Cloud:**

- **Scalability:** Instantly increase or decrease resources.
- **Cost Efficiency:** Pay only for what you use.
- **Isolation:** Each VM runs separately, increasing security and stability.

![cloud computing](https://wangwilly.github.io/willywangkaa/images/1526615255622.png)

---

<br>
<br>

# Real-time Embedded

**Embedded computers** are special-purpose computers designed for **specific tasks**. They are the most common type of computers and can be found **everywhere**, from **car engines** and **home appliances** to **manufacturing robots**. Unlike personal computers, they usually don’t have a complex user interface because they are built to **monitor and control hardware**.

---

## **Types of Embedded Systems**

1. **General-Purpose Embedded Systems:**

   - Run standard operating systems like **Linux** with special applications.
   - Example: A **smart thermostat** running Linux.

2. **Special-Purpose Embedded Systems:**

   - Use a **custom embedded OS** that provides only necessary functions.
   - Example: **Digital camera firmware** controlling the lens and image processing.

3. **ASIC-Based Systems (Application-Specific Integrated Circuits):**

   - Hardware designed for a **single specific task**.
   - **No operating system** required.
   - Example: **Graphics processing chips** in gaming consoles.

4. **SCS (Single-Chip Systems):**
   - Everything (CPU, memory, and I/O) is on **one chip**.
   - Used in **simple devices** like **digital watches and microwave ovens**.

---

## **Real-Time Operating Systems (RTOS)**

Most embedded systems run **Real-Time Operating Systems (RTOS)** because they require **fast and predictable responses**. These systems must process inputs **within strict time limits**; otherwise, they **fail**.

- **Example:**
  - A **robotic arm** in a factory must **stop immediately** when an error is detected.
  - If it reacts too late, it could damage the car it is assembling.

### **Types of Real-Time Systems**

1. **Hard Real-Time Systems:**

   - Must **always** meet time constraints; failure causes serious damage.
   - Example: **Aircraft control systems, medical devices.**

2. **Soft Real-Time Systems:**
   - Performance is important but not **critical** for system function.
   - Example: **Video streaming, gaming consoles.**

---

### example:

The `ESP32`, while not having a full-fledged operating system like a PC, utilizes a real-time operating system (RTOS) called `FreeRTOS`, and can also support other RTOS like RIOT-OS, depending on the specific project and development framework.

if you want to learn about esp32 click [here](https://github.com/bilalaniq/esp32-proj)
