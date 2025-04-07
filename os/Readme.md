# OS (Operating System)

An operating system acts as an intermediary between the user of a
computer and the computer hardware. The purpose of an operating
system is to provide an environment in which a user can execute
programs in a convenient and efficient manner.
An operating system is software that manages the computer hardware. The hardware must provide appropriate mechanisms to ensure the
correct operation of the computer system and to prevent user programs
from interfering with the proper operation of the system.
Internally, operating systems vary greatly in their makeup, since they
are organized along many different lines. The design of a new operating
system is a major task. It is important that the goals of the system be well
defined before the design begins. These goals form the basis for choices
among various algorithms and strategies.
Because an operating system is large and complex, it must be created
piece by piece. Each of these pieces should be a well-delineated portion
of the system, with carefully defined inputs, outputs, and functions.

### **Core Functions of an Operating System**

A computer system can be divided roughly into four
components:

- hardware
- operating system
- application programs,
- user

The hardware— the central processing unit (CPU), the memory, and the
input/output (I/O) devices—provides the basic computing resources for the
system. The application programs—such as word processors, spreadsheets,
compilers, and web browsers—define the ways in which these resources are
used to solve users’ computing problems. The operating system controls the
hardware and coordinates its use among the various application programs for
the various users.
We can also view a computer system as consisting of hardware, software,
and data. The operating system provides the means for proper use of these
resources in the operation of the computer system. An operating system is
similar to a government. Like a government, it performs no useful function
by itself. It simply provides an environment within which other programs can
do useful work.

Operating systems (OS) serve many functions across various types of computers, from toasters to spacecraft, and have evolved rapidly over time. Initially designed for military and government use, OSs expanded into general-purpose systems with the advent of mainframes. Moore's Law, predicting the doubling of transistors every 18 months, led to more powerful and compact computers.

An OS generally refers to software that manages hardware and makes it easier to use, executing programs and handling common tasks such as resource allocation and I/O device management. There is no universally accepted definition of what constitutes an OS, but it is commonly viewed as including the core program (kernel), system programs, and application programs. The exact features of an OS vary widely, from simple systems with minimal features to complex systems with extensive graphical capabilities.

The evolution of OSs was highlighted in legal cases like the 1998 U.S. lawsuit against Microsoft, where the company was accused of bundling too much functionality, stifling competition. In modern mobile OSs like iOS and Android, the OS includes not only a kernel but also middleware that aids app development.

In summary, the OS includes the always-running kernel, middleware for app development, and system programs for managing operations. The focus of this text is on the kernel of general-purpose OSs, though other components are discussed as necessary.

![os](https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcRoPce8JvqWBKm9lVMyp2O5_KIVxpf8fuvpgYnVeJhIkWkQczdY)

---

<br>
<br>

# Computer-System Organization

A modern general-purpose computer system consists of one or more CPUs and
a number of device controllers connected through a common bus that provides
access between components and shared memory . Each device
controller is in charge of a specific type of device (for example, a disk drive,
audio device, or graphics display). Depending on the controller, more than one
device may be attached. For instance, one system USB port can connect to a
USB hub, to which several devices can connect.

A device controller maintains

- Some local buffer storage
- A set of special-purpose registers.

The device controller is responsible for moving the data between the peripheral devices
that it controls and its local buffer storage.
Typically, operating systems have a device driver for each device controller. This device driver understands the device controller and provides the
rest of the operating system with a uniform interface to the device. The CPU and
the device controllers can execute in parallel, competing for memory cycles. To
ensure orderly access to the shared memory, a memory controller synchronizes
access to the memory.

![Computer-System Organization](https://images.slideplayer.com/36/10575294/slides/slide_9.jpg)

---

<br>
<br>

# CHAPTER # 1

## Interrupts

if you want to learn about Interrupts click [here](./chap1/interrupts/Interrupts.md)

---

## Storage Structure

if you want to learn about Storage Structure click [here](./chap1/Storage_Structure/Readme.md)

---

## Computer-System Architecture

if you want to learn about Computer-System Architecture click [here](./chap1/comp-sy-architecture/Readme.md)

---

## Operating-System Operations

if you want to learn about Operating-System Operations click [here](./chap1/os-operations/Readme.md)

---

---

## Resource Management

if you want to learn about Resource Management click [here](./chap1/Resource_managment/Readme.md)

---

## virtulization

click [here](./chap1/virtulization/Readme.md) to learn about virtulization

---

## Distributed Systems

click [here](./chap1/Distributed_Systems/Readme.md) to learn about Distributed Systems

---

## Kernel Data Structures

click [here](./chap1/data_structures/Readme.md) to learn about Kernel Data Structures

---

## Computing Environments

click [here](./chap1/computing_enviroment/Readme.md) to learn about Computing Environments

---

## Chapter #1 Exercise

click [here](./chap1/Exercise/Readme.md) see chapter 1 exercise

---

<br>
<br>

# CHAPTER # 2

An operating system (OS) provides the environment for executing programs and varies in structure depending on its design. Before designing an OS, clear goals must be established to guide decision-making.

Operating systems can be analyzed from three perspectives:

1. **Services provided** – What functionalities the OS offers.
2. **User and programmer interfaces** – How users interact with the OS.
3. **Internal components** – How different parts of the OS connect and function.

This chapter explores OS services, system calls, and various design methodologies, including monolithic, layered, microkernel, modular, and hybrid architectures. It also covers the OS boot process, performance monitoring tools, and Linux kernel module development.

---

## Operating-System Services

An operating system (OS) provides an environment for executing programs and offers various services to users and programs. While specific services vary across OS types, common categories exist. These services simplify programming tasks and improve usability. A visual representation (Figure 2.1) illustrates how different OS services interconnect and support users.

Operating systems provide essential services for both users and system efficiency.

### **User-Oriented Services:**

- **User Interface (UI):** Supports graphical (GUI), command-line (CLI), and touchscreen interfaces.
- **Program Execution:** Loads and runs programs, handling normal and abnormal terminations.
- **I/O Operations:** Manages input and output operations for devices and files, ensuring efficiency and protection.
- **File-System Manipulation:** Enables reading, writing, creating, deleting, and managing file permissions.
- **Communication:** Allows process interaction via shared memory or message passing, both locally and over networks.
- **Error Detection:** Monitors and responds to errors in hardware, I/O devices, and user programs.

### **System-Oriented Services:**

- **Resource Allocation:** Manages CPU, memory, and I/O resources among multiple processes.
- **Logging & Accounting:** Tracks resource usage for monitoring and optimization.
- **Protection & Security:** Controls access to data, ensures process isolation, and secures external connections.

These services collectively ensure a functional, efficient, and secure computing environment.

---

## User and Operating-System Interface

Operating systems provide multiple ways for users to interact with them:

### **1. Command-Line Interface (CLI)**

- Allows users to enter text-based commands directly.
- Found in Linux, UNIX, and Windows, where it is often called a **shell** (e.g., Bash, Korn, C shell).
- Commands can be built into the interpreter or executed as separate system programs.
- CLI is preferred by system administrators and power users for efficiency and automation via shell scripts.

### **2. Graphical User Interface (GUI)**

- Uses a window-based system with icons, menus, and a pointing device (mouse/touchpad).
- First appeared with Xerox Alto (1973) and became popular with Apple Macintosh and Microsoft Windows.
- Common in modern desktop environments like KDE and GNOME (Linux) and Aqua (macOS).

### **3. Touch-Screen Interface**

- Used in smartphones and tablets, enabling interaction via gestures like swiping and tapping.
- Eliminates the need for physical keyboards, replacing them with on-screen versions.
- Common in iOS (Springboard) and Android devices.

### **User Interface Choice**

- CLI is favored by advanced users for automation and system management.
- GUI is preferred by general users for ease of use.
- Modern OSs (e.g., macOS, Windows) provide both CLI and GUI options.
- Mobile systems primarily use touch-screen interfaces, with limited CLI availability.

While the user interface differs across platforms, the OS focuses on providing fundamental services rather than dictating how users interact with the system.

![sevices](https://encrypted-tbn3.gstatic.com/images?q=tbn:ANd9GcQwrqm_g56WL2Wsa_U8ClmiOjpFFIDs_N0z2OFS5-w1ep-tqNIe)

---

<br>
<br>

## system-call

if you want to learn about system calls clcik [here](./chap2/Sys_calls/Readme.md)

---

## **System Services**

System services, or **system utilities**, are programs that help users interact with the operating system. These services make it easier to develop, manage, and run applications. They are like tools or helpers that provide important functions for the computer system. Here's a breakdown of the different categories of system services:

---

### **Types of System Services:**

1. **File Management:**

   - These programs help with organizing and manipulating files. Examples include programs that **create**, **delete**, **copy**, **rename**, or **list** files and directories.

2. **Status Information:**

   - Some services gather information about the system, like **current time**, **available memory**, or **disk space**. These programs might display status info in **text** or a **graphical window**.
   - More complex status tools might track the performance of the system or log events for debugging.

3. **File Modification:**

   - These are tools like **text editors** that help you create or modify the content of files. Some also allow searching within files or transforming the text in various ways.

4. **Programming Language Support:**

   - These services include **compilers**, **debuggers**, and **interpreters** for programming languages like **C**, **C++**, **Java**, and **Python**. They help you write, compile, and test your programs.

5. **Program Loading and Execution:**

   - Once a program is written, it needs to be loaded into memory to run. These services help with **loading** the program into memory and **executing** it. They may include tools like **linkers** (for combining code) and **debugging tools**.

6. **Communications:**

   - These programs allow communication between users or processes. For example, **email**, **messaging**, **file transfer**, or even **remote login**.

7. **Background Services (Daemons):**
   - These are programs that run in the background to help the system function smoothly. They might **start automatically** when the system boots up and run continuously. Examples include network services or print servers.
   - Some daemons handle scheduled tasks like starting programs at specific times.

---

### **How Users Interact with the System:**

- Users mainly interact with the **system services** through **application programs** (like web browsers or text editors) or through **system programs** that make the OS more user-friendly.
- The **user interface** (GUI or command-line) is how users see and interact with the operating system. Even though two operating systems (like macOS and Windows) may use the same physical hardware, the user interface and system services can be very different, giving users different experiences.

---

### **Summary**

System services are programs that help manage and interact with the computer system, like organizing files, managing memory, running applications, and communicating with other systems. While most users don’t interact directly with the system calls, they use the system through the helpful **services** and **programs** the OS provides.

---

<br>

## **Linkers and Loaders**

click [here](./chap2/linker&loader/Readme.md) to learn about linkers and loader

---

<br>

## **Why Applications Are Operating-System Specific**

click [here](./chap2/os_specific_executables/Readme.md)

---

<br>
<br>

## **Operating-System Design and Implementation**

click [here](./chap2/os_design&implimentation/Readme.md)

---

## **Operating-System Structure**

click [here](./chap2/OS_Structure/Readme.md) to learn about Operating-System Structure

---

## **Building and Booting an Operating System**

click [here](./chap2/Building&Booting_os/Readme.md)

---


