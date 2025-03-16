# Resource Management

An operating system is a resource manager.

operating system must manage:

- Process Management
- Memory Management
- File-System Management
- Mass-Storage Management
- Cache Management
- I/O System Management

---

<br>
<br>

# Process Management

A program is a set of instructions that can’t do anything unless the CPU executes them. When a program is running, it's called a **process**. For example, when you run a word processor on your computer or open a social media app on your phone, those are both processes.

A **process** needs resources to run, such as CPU time, memory, files, and devices like a keyboard or screen. When a process is created, it’s given these resources, and it may also receive input to work with. For example, if you open a web browser, the URL you type is passed to the browser process as input. The process uses this input to find and display the web page. Once the process is finished, the operating system takes back any resources it used, so they can be reused by other processes.

It’s important to note that a **program** is not the same as a process. A program is just the instructions stored on your disk, like a file. A process, on the other hand, is what happens when the program is actually running. For a simple program, there’s one process that follows the instructions one after the other. This is called a **single-threaded process**. But for more complex programs, multiple processes or **threads** can run at the same time. Each thread has its own set of instructions and can execute them independently. A **multithreaded process** has multiple threads, each with its own instructions.

A **system** has many processes running at once, some belonging to the operating system (which manage the system), and others that belong to the user (like programs you open). The operating system manages all of these processes, making sure they run correctly by doing things like:

- Creating and deleting processes.
- Deciding which processes get to use the CPU at what times.
- Pausing and restarting processes when needed.
- Making sure processes can work together safely.
- Allowing processes to communicate with each other.

In a system, these processes can run at the same time, either by switching between them on one CPU or running them simultaneously on multiple CPUs.

---

<br>
<br>

# Memory Management

Main memory is a crucial part of a computer system. It is a large collection of bytes, each with a unique address, and its size can range from thousands to billions of bytes. The CPU and input/output (I/O) devices share this memory because it is fast and easily accessible.

The CPU fetches instructions from memory to execute programs and reads/writes data during processing. However, the CPU cannot directly access data stored on a hard drive or SSD. Instead, data from storage must first be transferred to main memory before the CPU can use it. Similarly, program instructions must be loaded into memory before execution.

When a program runs, it is assigned a specific memory space ([virtual memory space](../../../reverse-eng/Assembly_lang/NASM/Memory_mapping)). While running, it fetches instructions and data from this space. Once the program finishes, its memory is freed for other programs to use. To improve CPU efficiency and ensure quick responses, multiple programs are kept in memory at the same time, requiring **memory management**.

The **operating system (OS)** handles memory management by:

- Keeping track of which parts of memory are in use and by which process.
- Allocating memory when a program starts and freeing it when the program ends.
- Deciding which programs or data should be moved in or out of memory for efficient performance.

Different computers use different memory management methods, depending on their hardware design and needs.

---

<br>
<br>

# File-System Management

The operating system makes it easier for users to store and manage information by organizing data into **files**. Instead of dealing with the complex physical details of storage devices, users interact with files in a simple and logical way. The OS handles the details of storing and retrieving these files from storage devices like hard drives, SSDs, and even external media.

**Files** are collections of related data created by users. They can contain programs, documents, images, music, or any other type of information. Some files, like text files, have freeform content, while others, like MP3 files, follow a strict format.

To keep things organized, files are placed into **directories (folders)**. When multiple users share a system, the OS also manages file access permissions, controlling who can read, write, or modify files.

The **operating system** is responsible for:

- Creating and deleting files.
- Organizing files into directories (folders).
- Providing tools to open, edit, and manage files.
- Storing files efficiently on storage devices.
- Backing up important files to prevent data loss.

This file management system makes it easy for users to find, use, and protect their data while allowing the OS to efficiently handle storage.

---

<br>
<br>

# Mass-Storage Management

Computers need **secondary storage** (like hard drives and SSDs) to store programs and data when they are not in use. Most applications, such as web browsers and games, are saved on these devices and only loaded into memory when needed. Because secondary storage is used so often, managing it properly is a key responsibility of the **operating system (OS).**

The OS handles tasks like:

- **Mounting and unmounting** storage devices (making them available or removing them).
- **Managing free space** (keeping track of unused storage).
- **Allocating storage** to files and programs.
- **Disk scheduling** (deciding the order of read/write operations for efficiency).
- **Partitioning** (dividing storage into sections).
- **Protecting stored data** from unauthorized access or corruption.

Since secondary storage is used constantly, it must be **fast and efficient** to keep the computer running smoothly.

For long-term or infrequently used data, **tertiary storage** (such as tapes, CDs, and Blu-rays) is used. This type of storage is slower but more cost-effective. Some OS manage tertiary storage by handling backups, organizing rarely used files, and transferring data between different storage levels. Others leave this task to specialized applications.

---

<br>
<br>

# Cache Management

Caching is a technique used to **speed up data access** by storing frequently used information in a **faster storage area** (cache) for quick retrieval. Instead of always fetching data from slower storage (like a hard disk or main memory), a **copy** is kept in cache, assuming it will be needed again soon.

#### **How Does Caching Work?**

1. When we need data, we **first check the cache** (fast storage).
2. If the data is **found in the cache**, we use it directly (**fast access**).
3. If the data **is not in the cache**, we fetch it from slower storage (main memory or disk) and **store a copy in the cache** for future use.

![storage types](https://www.cs.uic.edu/~jbell/CourseNotes/OperatingSystems/images/Chapter1/1_11_StoragePerformance.jpg)

#### **Registers as High-Speed Cache**

Inside the CPU, there are **programmable registers** that act as **tiny, ultra-fast storage** for storing frequently used data. A **programmer or compiler** decides which data should stay in these registers to optimize performance.

#### **Hardware-Based Caching**

- Many computers have an **instruction cache**, which **stores the next instructions** to be executed. This helps avoid delays when fetching instructions from memory.
- Similarly, **data caches** store frequently accessed data to speed up operations.
- These hardware-based caches work **automatically** without operating system involvement.

#### **Cache Size and Management**

Since caches have **limited space**, managing them properly is crucial. Good **replacement policies** (deciding which old data to remove when new data arrives) improve performance.

#### **Data Movement in Storage Hierarchy**

There are different levels of storage, and data **moves between them** based on usage:

1. **Cache ↔ Registers (Hardware-based, very fast)**
2. **Main Memory ↔ Cache (Software-controlled, still fast)**
3. **Disk ↔ Main Memory (Managed by OS, much slower)**

For example, suppose a file on a **hard disk** contains a value **A** that we need to increment by 1:

- First, the **disk block** containing A is copied to **main memory**.
- Then, A is copied to the **cache** and an **internal register**.
- The CPU updates A in the register.
- The new value of A is **written back to cache, memory, and disk**.

This process ensures the correct value of A is available at every level of storage.

![int a](https://o.quizlet.com/cDC6jR8LAZmy5P2LZPq2QA.png)

#### **Challenges in Multitasking Systems**

If only **one process** runs at a time, data access is simple—always fetching from the highest storage level.  
However, in **multitasking environments**, where multiple programs run **simultaneously**, we must ensure that:

- Each process **gets the latest value** of data.
- Changes made by one process are **visible to others** immediately.

#### **Challenges in Multiprocessor Systems**

If a system has **multiple CPUs**, each CPU may have **its own cache**. If a value (like A) is **stored in multiple caches**, we must ensure that **updates in one cache** are **reflected in all others**. This issue is called **cache coherency** and is usually managed by **hardware** rather than the OS.

#### **Challenges in Distributed Systems**

In **distributed computing**, multiple copies (or **replicas**) of the same file can exist on **different computers**. If one copy is updated, all **other copies must also be updated** to stay consistent. Some systems **automatically synchronize replicas** to ensure **data consistency** across different locations.

---

<br>
<br>

# I/O System Management

An **operating system (OS)** helps users interact with computer hardware **without worrying about the technical details** of each device. This is especially important for **input/output (I/O) devices** like keyboards, printers, and hard drives, which all work differently.

To handle this, the OS has a special **I/O subsystem** that acts as a **middle layer** between the hardware and the rest of the system.

### **Components of the I/O Subsystem**

The I/O subsystem has three main parts:

1. **Memory Management for I/O**

   - **Buffering**: Temporarily holds data while it is being transferred between the CPU and a device (e.g., when streaming a video).
   - **Caching**: Stores frequently used data to speed up access (e.g., keeping a copy of a recently opened file in memory).
   - **Spooling**: Queues data for slow devices like printers so that multiple tasks can continue without waiting (e.g., sending multiple print jobs at once).

2. **General Device-Driver Interface**

   - Provides a **common way** for different devices to communicate with the OS.
   - This makes it easier to add **new devices** without changing the entire OS.

3. **Device Drivers** (Software for Specific Devices)
   - Each device has a **driver**, a small software program that knows exactly **how to communicate with that device**.
   - For example, a **keyboard driver** knows how to process key presses, and a **printer driver** knows how to send print commands.
   - The **OS does not need to know** the details of each device—only the driver does.

### **How It Works**

- When a program wants to **read from or write to a device**, it talks to the **I/O subsystem** instead of directly controlling the hardware.
- The **device driver** then translates the request into **specific instructions** for that device.
- If an operation takes time (e.g., printing a document), the **interrupt handler** helps the CPU move on to other tasks while waiting for the device to finish.

### **Why This Is Important**

- The I/O subsystem **hides hardware complexity** from users and applications.
- It allows **different devices** to work smoothly with the OS **without modifying the entire system**.
- It makes **multitasking efficient** by allowing the CPU to **handle multiple I/O operations** at once.

This makes modern computers **faster, more flexible, and easier to use**!
