# Operating-System Structure

Modern operating systems are very **large and complex**, so they need to be **carefully planned and organized** to work properly and be easy to update or fix.

A **common method** used is to **divide the OS into smaller parts**, called **modules**, instead of making it one big chunk of code.

Each **module** handles a specific part of the system, like memory, input/output, or file management. These modules have:

- **Clear responsibilities** (what they do),
- **Well-defined boundaries** (what they don’t do), and
- **Specific ways to communicate** with each other (called interfaces).

---

### **Analogy with Writing Code**

Think about how you write your own programs:

- Instead of putting all your code inside the `main()` function,
- You create **separate functions** for different tasks,
- Each function has **input (parameters)** and **output (return values)**,
- Then you **call** these functions from `main()` to keep your program clean and organized.

The same idea is used when building an operating system—break it into clean, manageable pieces that can work together smoothly.

---

## Types of Operating System Structures

- Monolithic Structure
- Layered Approach
- Microkernels
- Modules
- Hybrid Systems
  - macOS and iOS
  - Android

---

<br>
<br>

# Monolithic Structure (tightly coupled system)

The **monolithic structure** is one of the earliest and simplest ways to design an operating system. In this structure, **the entire operating system is compiled into one large program** that runs in a **single address space**, typically in **kernel mode**. All the core functionalities are packed together without strict separation.

---

### **How It Works**

In a monolithic kernel, all major components of the operating system—like file management, memory management, device drivers, system call handling, CPU scheduling, and more—are part of **one large program**. This means:

- There’s no clear boundary between different parts of the OS.
- All components can call each other freely, which can make the system faster but also more complex to manage.

---

### **Example: UNIX**

A good example of a monolithic structure is the **original UNIX operating system**. UNIX was split into two main parts:

1. **System programs** – Utilities and tools that help users interact with the OS.
2. **The kernel** – The core of the OS that interacts with the hardware and performs essential functions.

Inside the UNIX kernel, components like the file system, CPU scheduler, and memory manager were bundled together, even though they were loosely organized into layers. This gave a feeling of structure but didn’t fully separate each part.

![unix os structure](https://unchained112.github.io/assets/OSNotes/UNIXstructure.png)

---

### **Modern Example: Linux**

The **Linux kernel** is also monolithic. All core parts of the OS run in **kernel mode** and **share the same memory space**. However, Linux includes some improvements over traditional monolithic systems:

- It supports **modular design**, which means new functionalities like device drivers can be **added or removed at runtime** as modules.
- Even though it’s monolithic, Linux allows more flexibility compared to the classic UNIX structure.

---

### **Advantages of Monolithic Structure**

1. **Performance**: All components share the same address space, so **inter-component communication is very fast**.
2. **Low Overhead**: There’s minimal overhead when system calls are made, because everything is in one space.
3. **Simple for small systems**: For small or simple systems, this approach can be easier to manage initially.

---

### **Disadvantages of Monolithic Structure**

1. **Hard to maintain and extend**: Since everything is tightly connected, **adding new features or fixing bugs** can be risky—one mistake might crash the whole system.
2. **Low modularity**: It's difficult to **isolate components**, test them individually, or reuse them in other systems.
3. **Security concerns**: If one part of the kernel is compromised (like a buggy driver), the **entire system becomes vulnerable**.

---

### **Why It’s Still Used**

Despite the drawbacks, monolithic kernels are still used in major operating systems like **Linux**, **UNIX**, and even **Windows** (though Windows is more of a hybrid). The main reason is **performance**—fast system call handling and internal communication make monolithic systems efficient for many use cases.

---

### **Summary**

The **monolithic structure** organizes an OS as a single large program running in one address space. It is **fast and efficient** but **difficult to modify and maintain**. Systems like **UNIX and Linux** follow this structure, although modern implementations try to make it more modular.

---

![linux sys structure](https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcSoQ02n-vZQDTNEY4ofs7Q4-E4X3Akzo2vpHzp9zWHCyWDabJsL)

---

<br>
<br>
<br>

# Layered Approach

The **Layered Approach** is a way to structure an operating system so that it is organized into **multiple levels (or layers)**, each with specific and limited functionality. Instead of putting everything into one large program (as in the monolithic structure), the OS is broken down into manageable components, which improves **modularity**, **maintainability**, and **debugging**.

---

### **Why Use a Layered Approach?**

In a **monolithic kernel**, all components are tightly connected. This means a change in one part might cause unexpected problems in another. This **tight coupling** makes it hard to update or fix specific features.

To overcome this, the **layered approach promotes loose coupling**. Each part of the system (layer) is independent from the others, relying only on the functionality of the layers directly below it.

---

### **Structure of the Layers**

The layered operating system is usually organized like this:

- **Layer 0** – Hardware (CPU, memory, disk, etc.)
- **Layer 1** – Basic hardware drivers and low-level functions
- **Layer 2** – Memory management, process scheduling
- **Layer 3** – File systems, device management
- **Layer N** – User interface or system calls

Each layer interacts **only** with the layer directly below it and **provides services** to the layer directly above it. This creates a **clean and clear structure**, like a stack.

---

### **How Each Layer Works**

Each layer is like a **black box**: the layers above don’t need to know how it works internally—they just need to know **what it does**.

For example:

- A higher layer may request to read a file.
- It doesn’t need to know **how** the file system works or how the disk is accessed.
- It just uses an interface provided by the lower layer (e.g., "read_file()").

This way, **implementation details are hidden**, and developers can change or improve one layer **without breaking the others**.

---

### **Benefits of the Layered Approach**

1. **Simplicity and Clarity**

   - Each layer has a **clear role** and purpose.
   - The system is easier to understand and design.

2. **Ease of Debugging**

   - You can debug **one layer at a time**.
   - If a problem occurs in a layer, it's easier to locate because the layers below it are already tested and stable.

3. **Modularity**

   - You can **change, improve, or replace** one layer without affecting others.
   - New features can be added to specific layers without reworking the entire OS.

4. **Abstraction**
   - Each layer **abstracts** hardware or services, making it easier for upper layers to operate without dealing with complex lower-level details.

---

### **Challenges and Limitations**

While the layered approach has many benefits, it also comes with some **downsides**:

1. **Defining Layers is Difficult**

   - It’s not always clear **where one layer should end and the next should begin**.
   - Poorly designed layers can cause confusion and inefficiency.

2. **Performance Overhead**

   - A system call (e.g., reading a file) might need to go through **multiple layers**, increasing execution time.
   - Each step adds overhead, which can **slow down the system**.

3. **Rare in Pure Form**
   - Few operating systems use **a purely layered design** due to the issues above.
   - Most modern OSes (like Windows and Linux) use a **partially layered** or **hybrid** model to balance performance with modularity.

---

### **Real-World Use**

- The **TCP/IP protocol stack** in networking is a great example of a successful layered system (e.g., physical layer, data link, network, transport, application).
- Web applications often follow a layered architecture: frontend → backend → database.

Some older operating systems like **THE OS** and **Multics** were based on a strict layered model, but modern OSes have moved toward **flexible layering** with broader layers containing more functionality.

---

### **Summary**

The **Layered Approach** structures an operating system into distinct levels, each building on the functionality of the layer beneath it. This makes the OS easier to design, develop, debug, and maintain. However, careful planning is required to define the layers properly and avoid performance issues. While **pure layered systems are rare**, many modern OSes borrow ideas from this model to achieve a balance of structure and speed.

![layered approach](https://education.sakshi.com/sites/default/files/images/2015/12/11/LayeredOS.jpg)

---

<br>
<br>
<br>

# Microkernels

Early operating systems like **UNIX** used a **monolithic structure**, where everything was packed into a single, large kernel. As UNIX systems expanded over time, the kernel became **too large and hard to manage**. To solve this problem, a new design approach was introduced called the **Microkernel Architecture**.

---

### **What is a Microkernel?**

A **microkernel** is a type of operating system architecture that **removes all nonessential components from the kernel** and implements them in **user space** as separate programs. This results in a **smaller, more manageable kernel**.

- The goal is to **keep the kernel as small as possible**.
- Only **essential functions** are kept in the kernel (like basic process management, memory management, and inter-process communication).
- Everything else—like file systems, device drivers, and networking—is moved out to **user space**, where it runs as **user-level services**.

This design is shown in typical **microkernel architecture diagrams**, where the kernel is in the center and everything else (file server, device drivers, etc.) runs outside the kernel in user space.

![microkernel](https://image4.slideserve.com/9082949/microkernel-system-structure-l.jpg)

---

### **Key Component: Message Passing**

Since services are separated from the kernel and from each other, they need a way to **communicate**. This is handled using **message passing**.

- The **microkernel acts as a middleman**, passing messages between the client (user program) and services.
- For example, if a user program wants to open a file:
  - It **does not talk directly** to the file system.
  - Instead, it **sends a message to the kernel**, which then **relays** that message to the file server process.
  - The file server processes the request and sends a response **back through the microkernel**.

This method of communication helps with **isolation and modularity**, but it also adds some **performance overhead** (discussed later).

---

### **Advantages of Microkernel Design**

1. ### **Easier to Extend the OS**

   - New features or services can be added **without changing the kernel**.
   - These new services just run in user space.
   - This makes **development and updates safer and faster**.

2. ### **Smaller Kernel**

   - Since only essential parts are in the kernel, any updates or changes to the kernel are **minimal**.
   - Easier to **test, maintain, and debug**.

3. ### **Easier Portability**

   - Because the kernel is small and hardware-specific code is limited, it is **easier to move** (port) the operating system to **different hardware platforms** (like phones, embedded devices, or PCs).

4. ### **Better Security and Reliability**
   - If a **user-level service crashes**, the kernel and the rest of the system **are not affected**.
   - This isolation helps prevent bugs and security issues from spreading.
   - Fewer components in kernel space means **fewer risks of system-wide failures**.

---

### **Examples of Microkernel Operating Systems**

1. ### **Darwin (macOS and iOS)**

   - Darwin is the **core of Apple’s macOS and iOS**.
   - It actually uses two kernels, one of which is the Mach microkernel, and the other is the BSD kernel.

     These two are integrated into a single kernel image in macOS and iOS, forming a `hybrid kernel` that combines microkernel features (from Mach) and monolithic features (from BSD) for both modularity and performance.

     we will discous this latter on

2. ### **QNX**
   - A **real-time operating system** often used in **embedded systems**.
   - The **QNX Neutrino microkernel** handles:
     - Process scheduling
     - Message passing
     - Hardware interrupts
     - Low-level networking
   - All other services (e.g., file system, drivers) are **user-space processes**.

---

### **Disadvantages of Microkernels**

While microkernels offer many benefits, they are not without problems. The **main issue** is **performance**:

1. ### **Message Passing Overhead**

   - Since services are in **different address spaces**, communication between them requires **copying data** back and forth through the kernel.
   - Every request from one service to another needs:
     - **Multiple message copies**
     - **Process context switches** (which are expensive)

2. ### **Slower Than Monolithic Kernels**
   - The time taken to pass messages and switch between processes adds **delay**.
   - These extra steps make **microkernels slower**, especially in tasks that require lots of communication (e.g., file access, device control).

---

### **Case Study: Windows NT**

- **Windows NT** (the early version of modern Windows) originally used a **layered microkernel design**.
- However, **performance was poor** compared to **Windows 95**, which used a more monolithic structure.
- In response:
  - **Windows NT 4.0** moved some parts from **user space into the kernel** to improve speed.
- By the time **Windows XP** came out, the design was **more monolithic than microkernel**.

---

### **How macOS Deals with Microkernel Performance**

While **macOS** uses the **Mach microkernel**, Apple addressed its performance issues by:

- **Integrating more functions into the kernel** space (just like Windows NT did).
- This results in a **hybrid kernel**, which tries to balance **modularity and performance**.

---

### **Summary**

| Feature              | Microkernel                                                                                           |
| -------------------- | ----------------------------------------------------------------------------------------------------- |
| **Design**           | Minimal kernel, many services in user space                                                           |
| **Communication**    | Message passing via the microkernel                                                                   |
| **Advantages**       | Easy to extend, better security, portability, smaller kernel                                          |
| **Disadvantages**    | Slower due to message passing and context switching                                                   |
| **Examples**         | Darwin (macOS/iOS), QNX                                                                               |
| **Real-World Shift** | Systems like Windows and macOS moved towards hybrid structures to balance performance with modularity |

---

<br>
<br>
<br>

Sure, here's a detailed explanation of **Section 2.8.4: Modules** in easy and complete terms:

---

# Modules

Modern operating systems are large and complex. One of the best ways to design them today is to **break them down into parts** that can be **loaded and unloaded as needed**. This is known as using **Loadable Kernel Modules (LKMs)**.

### What Are Modules?

Think of modules as **plug-ins for the operating system kernel**. Instead of building one giant program that includes every feature or driver the OS might need, we keep a small "core" and allow other features to be added **on demand**.

These modules can include things like:

- Device drivers (for USB, printers, etc.)
- File system support (like FAT32, NTFS, ext4)
- Network protocols

Modules are **loaded into the kernel** either:

- **At boot time** (when the system starts), or
- **During run time** (for example, when you plug in a USB device)

---

### 🎯 Why Use Modules?

Let’s say you’re developing a new file system or a new type of device driver. If the kernel was **not modular**, you would have to:

- Modify the kernel code
- Recompile the entire kernel
- Reboot your system

With modules, you can just write the module separately and **load it into the running kernel** using a tool like `insmod` (insert module) or `modprobe`. You can also **unload it** with `rmmod`.

---

### FStructure: How Is This Different From Other OS Designs?

#### Compared to Monolithic Kernels:

- Monolithic kernels are fast but not very flexible (everything is built-in).
- Module-based kernels keep the **core small** but can **dynamically grow** as needed, without rebooting.
- Linux is still monolithic in terms of structure but supports modules for flexibility.

#### Compared to Layered Systems:

- Layered systems have strict rules: higher layers only talk to lower ones.
- With modules, any part of the system can talk to any other module (not limited by layers), which makes it **more flexible**.

#### Compared to Microkernels:

- Microkernels use **message passing** for communication between components (which can be slow).
- Modules **live in the kernel’s address space**, so they don’t need message passing, making them **faster**.

---

### Example: Linux and LKMs

Linux is a great example of a modular system.

- When you plug in a USB device, Linux checks if it has the right driver.
- If not, it can **load a module on the fly** to support that device.
- Later, if the device is removed, the driver can also be **unloaded**.

This gives you:

- **Performance** (because Linux is still monolithic and fast)
- **Flexibility** (because new features can be added or removed on demand)
- **Maintainability** (because you don’t need to recompile the entire kernel)

![modren unix](../img/modren_unix.png)

---

### 📦 Summary

| Feature         | Modules Approach                                |
| --------------- | ----------------------------------------------- |
| **Modularity**  | Kernel is made of a core + plug-in modules      |
| **Flexibility** | Add/remove functionality during runtime         |
| **Efficiency**  | No message passing overhead like microkernels   |
| **Use Cases**   | File systems, device drivers, network protocols |
| **Popular In**  | Linux, macOS, Solaris, Windows                  |

---

if you are intrested in writing lkms click [here](https://sysprog21.github.io/lkmpg)

---

<br>
<br>
<br>

# Hybrid Systems

In real-world scenarios, most modern operating systems do not follow a single, strict architectural model like purely monolithic or purely microkernel. Instead, they use a **hybrid structure**, combining the strengths of multiple approaches to balance **performance, flexibility, security, and usability**.

For instance, **Linux** is considered a **monolithic kernel** because all core services run in a single address space, which makes it **highly efficient** in terms of speed. However, Linux is also **modular**, meaning it supports **loadable kernel modules** (LKMs) that allow new features like device drivers or file systems to be added without rebooting the system or recompiling the kernel. This gives Linux both the performance of a monolithic system and the flexibility of a modular one.

Similarly, **Windows** is also largely monolithic, with most core components running in kernel mode for performance. But it incorporates certain **microkernel concepts**, such as running **subsystems in user mode**, which improves security and stability. These subsystems—called **operating-system personalities**—allow Windows to support different application environments. Additionally, like Linux, Windows also supports **dynamically loadable modules**, which contribute to its flexibility.

These blended designs are what we call **hybrid systems**. They aim to avoid the strict limitations of one single architectural style while taking advantage of each approach’s strengths. In the sections that follow, this hybrid model is explored further through real-world examples like **macOS**, **iOS**, and **Android**, which are leading examples of how hybrid operating system designs are implemented today.

<br>
<br>

## macOS and iOS

<br>
<br>

# Android
