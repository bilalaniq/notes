# Computer-System Architecture

general structure of a typical computer system.

- Single-Processor Systems
- Multiprocessor Systems
- Clustered Systems

<br>
<br>
<br>

# Single-Processor Systems

Many years ago, most computer systems used a single processor containing
one CPU with a single processing core. The [core](./core.md) is the component that executes instructions and registers for storing data locally.

A **single-processor system** is a computer system that has **one central processing unit (CPU)** responsible for executing all instructions. This means that the CPU manages all tasks, including running the operating system, executing user applications, and handling I/O operations.

---

### **Key Features of Single-Processor Systems**

✅ **Single CPU** – All processing is done by one central unit.  
 ✅ **Sequential Execution** – Tasks are executed one at a time or managed through multitasking techniques like time-sharing.  
 ✅ **Simplicity** – Easier to design, program, and manage compared to multi-processor systems.  
 ✅ **Lower Cost** – Generally more affordable than multi-processor systems, making them suitable for personal computers and basic servers.

---

### **How It Works**

1. The **CPU fetches** an instruction from memory.
2. It **decodes and executes** the instruction.
3. The process repeats for each task in the system.
4. If multiple tasks need execution, the OS **switches between them** using scheduling techniques like **time-sharing**.

---

### **Limitations**

❌ **Limited Performance** – Since there’s only one CPU, it can become a bottleneck under heavy workloads.  
 ❌ **Inefficient for Parallel Processing** – Tasks cannot run truly parallel (only simulated using multitasking).  
 ❌ **Not Scalable** – Cannot handle large-scale applications as efficiently as multi-processor systems.

---

### **Examples of Single-Processor Systems**

- Personal computers (older desktops and laptops).
- Embedded systems (like ATMs, smartwatches, or home appliances).
- Simple servers used for basic tasks.
  Modern computing is shifting towards **multi-core** and **multi-processor** architectures, but **single-processor systems** are still widely used in many embedded and low-power applications.

---

<br>
<br>
    
    PCs contain a microprocessor in the keyboard
    to convert the keystrokes into codes to be sent to the CPU. In other systems or
    circumstances, special-purpose processors are low-level components built into
    the hardware. The operating system cannot communicate with these processors; they do their jobs autonomously. The use of special-purpose microprocessors is common and does not turn a single-processor system into a multiprocessor. If there is only one general-purpose CPU with a single processing core, then
    the system is a single-processor system. According to this definition, however,
    very few contemporary computer systems are single-processor systems.
    
<br>
<br>
<br>

# Multiprocessor Systems

A **multiprocessor system** is a computer system that has **two or more CPUs (processors) sharing memory and other resources**. These processors work together to execute tasks more efficiently than a **single-processor system**.

**Example:**

- A **dual-core** or **quad-core** CPU in a personal computer.
- High-performance **servers and supercomputers**.

---

### **Types of Multiprocessor Systems**

Multiprocessor systems are classified based on how processors share memory and how they communicate with each other.

### **A. Symmetric Multiprocessing (SMP)**

- All **processors share the same memory and I/O devices**.
- Each processor runs **its own tasks** but has equal access to the OS.
- **Example:** Most modern **multi-core CPUs** (Intel i7, AMD Ryzen).

✅ **Advantages:**
✔️ Efficient load balancing (work is shared evenly).

✔️ If one CPU fails, others can continue (better fault tolerance).

❌ **Disadvantages:**

❌ **Memory bottleneck** (as all CPUs access the same memory).

❌ **Synchronization overhead** (managing multiple processors is complex).

---

Notice that each
CPU processor has its own set of registers, as well as a private—or local—
cache. However, all processors share physical memory over the system bus.
The benefit of this model is that many processes can run simultaneously
—N processes can run if there are N CPUs—without causing performance
to deteriorate significantly. However, since the CPUs are separate, one may
be sitting idle while another is overloaded, resulting in inefficiencies. These
inefficiencies can be avoided if the processors share certain data structures. A
multiprocessor system of this form will allow processes and resources—such
as memory— to be shared dynamically among the various processors and can
lower the workload variance among the processors.

### **B. Asymmetric Multiprocessing (AMP)**

- **One CPU is the master**, and others are slaves.
- The **master CPU controls the entire system** and assigns tasks.
- **Used in older systems**, real-time OS, and some embedded systems.

✅ **Advantages:**

✔️ Simple design (easier to manage).

✔️ Efficient in systems where only **one processor needs full control**.

❌ **Disadvantages:**

❌ If the **master CPU fails, the entire system fails**.

❌ **Slaves cannot work independently** (less flexibility).

---

## **5. Advantages of Multiprocessor Systems**

✅ **Higher Performance** – Multiple CPUs execute tasks faster.

✅ **Better Reliability & Fault Tolerance** – If one CPU fails, others continue.

✅ **Efficient Resource Utilization** – CPUs handle different tasks simultaneously.

✅ **Improved Scalability** – More CPUs can be added to increase power.

---

## **6. Challenges of Multiprocessor Systems**

❌ **Synchronization Issues** – Managing shared memory is difficult.

❌ **Increased Complexity** – More CPUs require advanced scheduling.

❌ **Expensive** – More hardware increases cost.

   <br>
   <br>

## Private Cache vs. Shared Cache

- ### **Private Cache**

in this case there is no cache shared among the cpu's

![non-shared](https://slader-solution-uploads.s3.amazonaws.com/931eede4-8a8f-4f3e-801c-73a3efdfd475-1692296664061559.png)

- ### **Shared Cache**

  In the Figure below, we show a dual-core design with two cores on the same processor chip. In this design, each core has its own register set, as well as its own
  local cache, often known as a level 1, or L1, cache. Notice, too, that a level 2 (L2)
  cache is local to the chip but is shared by the two processing cores. Most architectures adopt this approach, combining local and shared caches, where local,
  lower-level caches are generally smaller and faster than higher-level shared caches

  ![shared](https://o.quizlet.com/IzygMf252WT0-g0YnxQmqw.png)

---

The definition of multiprocessor has evolved over time and now includes
multicore systems, in which multiple computing cores reside on a single chip.
Multicore systems can be more efficient than multiple chips with single cores
because on-chip communication is faster than between-chip communication.

In addition, one chip with multiple cores uses significantly less power than
multiple single-core chips, an important issue for mobile devices as well as
laptops.

Adding additional CPUs to a multiprocessor system will increase computing power; however, as suggested earlier, the concept does not scale very well,
and once we add too many CPUs, contention for the system bus becomes a
bottleneck and performance begins to degrade. so the solution to this problem is `NUMA` and `UMA`

## **Non-Uniform Memory Access (NUMA)**

- Memory is divided into multiple local memory regions
- Each processor has faster access to its local memory but slower access to others
- Used in high-performance computing (HPC) and large-scale servers

Example: AMD Threadripper, IBM Power systems

Because NUMA systems can scale to accommodate a large
number of processors, they are becoming increasingly popular on servers as
well as high-performance computing systems.

disadventage of this is that CPU1 cannot access the local memory of CPU2 as quickly as it can access its own local memory, slowing down performance

<br>

![numa](https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcS9Cwzz5zdO6LUN_ookVG2HC3qUHN4bHYpc54_ZOBset6kAQRmd)

## **Uniform Memory Access (UMA)**

- Also called Symmetric Multiprocessing (SMP)
- All processors share a single, uniform memory
- Memory access time is equal for all processors
- Common in multi-core CPUs, servers, and workstations

Example: Intel Xeon, AMD Ryzen with multiple cores

---

<br>
<br>

- `CPU`: The hardware that executes instructions.
- `Processor`: A physical chip that contains one or more CPUs.
- `Core`: The basic computation unit of the CPU.
- `Multicore`: Including multiple computing cores on the same CPU.
- `Multiprocessor`: Including multiple processors

Although virtually all systems are now multicore, we use the general term
CPU when referring to a single computational unit of a computer system and
core as well as multicore when specifically referring to one or more cores on
a CPU.

Virtually all modern operating
systems—including Windows, macOS, and Linux, as well as Android and iOS
mobile systems—support multicore SMP systems.

---

<br>
<br>

# Clustered Systems

### **Clustered Systems in Detail**

#### **Definition**

A clustered system is a type of multiprocessor system where multiple computers (nodes) are connected and work together as a single system. These nodes communicate and share workloads to improve performance, reliability, and availability. Clustered systems are widely used in high-performance computing, cloud computing, and enterprise environments.

---

#### **Types of Clustering**

1. **Asymmetric Clustering**

   - One machine (active node) performs operations while another (standby node) remains idle or on standby mode.
   - If the active node fails, the standby node takes over, ensuring high availability.
   - Common in failover and high-availability systems.

2. **Symmetric Clustering**

   - All nodes are actively working and sharing computational tasks.
   - More efficient than asymmetric clustering since all resources are utilized.
   - Commonly used in load balancing and parallel computing.

3. **Load-Balanced Clustering**

   - Distributes the workload evenly across all nodes.
   - Improves system responsiveness and prevents overloading of any single node.
   - Used in web servers, database clusters, and cloud environments.

4. **Parallel Clustering**
   - Nodes work together to perform large-scale computations.
   - Used in scientific computing, data analysis, and machine learning applications.

---

#### **Advantages of Clustered Systems**

- **High Availability** – If one node fails, another can take over without system downtime.
- **Scalability** – More nodes can be added to increase processing power.
- **Improved Performance** – Tasks are divided among multiple nodes for faster execution.
- **Fault Tolerance** – Redundancy reduces the risk of total system failure.
- **Load Balancing** – Ensures efficient utilization of resources by distributing workloads.

---

#### **Applications of Clustered Systems**

- **Data Centers & Cloud Computing** – Ensures high availability and distributed processing.
- **Scientific Research & Simulations** – Used in weather forecasting, genome sequencing, and physics simulations.
- **Financial Systems** – Supports high-speed trading and banking applications.
- **E-commerce & Web Hosting** – Improves performance and uptime for online platforms.
- **AI & Machine Learning** – Parallel processing accelerates complex computations.

When combined with a Storage Area Network (SAN), clustered systems achieve high-performance storage management, making them suitable for enterprise applications, databases, and cloud environments.

A Storage Area Network (SAN) is a high-speed, dedicated storage network that provides block-level access to storage devices. Unlike traditional storage solutions (e.g., NAS), a SAN allows multiple servers in a clustered system to access shared storage simultaneously

![SAN](https://o.quizlet.com/8KoVBAurik-hnDY8NBnyJQ.png)