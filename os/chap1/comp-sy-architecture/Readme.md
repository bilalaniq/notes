# Computer-System Architecture

general structure of a typical computer system.

- Single-Processor Systems
- Multiprocessor Systems
- Clustered Systems

<br>
<br>
<br>

- # Single-Processor Systems

  Many years ago, most computer systems used a single processor containing
  one CPU with a single processing core. The [core](./core.md) is the component that executes instructions and registers for storing data locally.

  A **single-processor system** is a computer system that has **one central processing unit (CPU)** responsible for executing all instructions. This means that the CPU manages all tasks, including running the operating system, executing user applications, and handling I/O operations.

  ***

  ### **Key Features of Single-Processor Systems**

  ✅ **Single CPU** – All processing is done by one central unit.  
   ✅ **Sequential Execution** – Tasks are executed one at a time or managed through multitasking techniques like time-sharing.  
   ✅ **Simplicity** – Easier to design, program, and manage compared to multi-processor systems.  
   ✅ **Lower Cost** – Generally more affordable than multi-processor systems, making them suitable for personal computers and basic servers.

  ***

  ### **How It Works**

  1. The **CPU fetches** an instruction from memory.
  2. It **decodes and executes** the instruction.
  3. The process repeats for each task in the system.
  4. If multiple tasks need execution, the OS **switches between them** using scheduling techniques like **time-sharing**.

  ***

  ### **Limitations**

  ❌ **Limited Performance** – Since there’s only one CPU, it can become a bottleneck under heavy workloads.  
   ❌ **Inefficient for Parallel Processing** – Tasks cannot run truly parallel (only simulated using multitasking).  
   ❌ **Not Scalable** – Cannot handle large-scale applications as efficiently as multi-processor systems.

  ***

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

- # Multiprocessor Systems

  A **multiprocessor system** is a computer system that has **two or more CPUs (processors) sharing memory and other resources**. These processors work together to execute tasks more efficiently than a **single-processor system**.

  **Example:**

  - A **dual-core** or **quad-core** CPU in a personal computer.
  - High-performance **servers and supercomputers**.

  ***

  ## **2. Types of Multiprocessor Systems**

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

  ***

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

  ***

  ## **3. Multiprocessing vs. Multithreading**

  | Feature                | **Multiprocessing**                                 | **Multithreading**                                               |
  | ---------------------- | --------------------------------------------------- | ---------------------------------------------------------------- |
  | **Definition**         | Multiple CPUs execute different processes.          | A single CPU executes multiple threads of a process.             |
  | **Execution Units**    | Independent **processors**.                         | Independent **threads** inside one process.                      |
  | **Parallel Execution** | True parallelism (if multiple cores are available). | May be parallel (if multiple cores) or concurrent (if one core). |
  | **Efficiency**         | More powerful, but more expensive.                  | Efficient use of a single CPU.                                   |
  | **Example**            | Servers, High-Performance Computing (HPC).          | Web browsers, video players.                                     |

  ***

  ## **4. Architectures of Multiprocessor Systems**

  ### **A. Shared Memory Architecture**

  - **All CPUs share the same memory (RAM).**
  - Fast communication between processors.
  - Used in **modern multi-core CPUs** and **SMP systems**.

  ### **B. Distributed Memory Architecture**

  - Each CPU has **its own memory**.
  - CPUs communicate using a high-speed network.
  - Used in **supercomputers and clusters**.

  ***

  ## **5. Advantages of Multiprocessor Systems**

  ✅ **Higher Performance** – Multiple CPUs execute tasks faster.
  ✅ **Better Reliability & Fault Tolerance** – If one CPU fails, others continue.
  ✅ **Efficient Resource Utilization** – CPUs handle different tasks simultaneously.
  ✅ **Improved Scalability** – More CPUs can be added to increase power.

  ***

  ## **6. Challenges of Multiprocessor Systems**

  ❌ **Synchronization Issues** – Managing shared memory is difficult.
  ❌ **Increased Complexity** – More CPUs require advanced scheduling.
  ❌ **Expensive** – More hardware increases cost.

  ***

  ## **7. Applications of Multiprocessor Systems**

  🚀 **Servers & Data Centers** – Handle multiple user requests.
  🎮 **Gaming & Graphics Rendering** – GPUs use multiple processors for real-time rendering.
  📊 **Scientific Computing** – Weather simulations, AI, and deep learning.
  🔧 **Embedded Systems** – Used in smart devices, self-driving cars, and robotics.

  ***

  ## **Conclusion**

  Multiprocessor systems provide **better performance, reliability, and efficiency** than single-processor systems. They are widely used in **modern computing, from personal PCs to supercomputers**. However, they come with challenges like **higher cost and complexity in memory management**.
