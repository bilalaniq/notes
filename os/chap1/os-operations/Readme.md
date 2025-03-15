# Operating-System Operations

An **operating system** is the main software that manages a computer and allows other programs to run. It provides an **environment** where programs can be executed. Although different operating systems work in different ways, they share many common features.

When a computer **starts or reboots**, it needs an **initial program** to run. This program is called the **bootstrap program**. It is usually stored in **firmware** (a type of permanent software inside the hardware). The **bootstrap program** prepares the system by **initializing the CPU, memory, and other hardware components**. Then, it finds the **operating system kernel** and loads it into memory so that the system can start working.

Once the **kernel** is running, it begins **providing services** to users and programs. Some of these services are handled by **system programs** called [**daemons**](./daemons.md), which run continuously in the background. On **Linux**, the first daemon to start is called **systemd**, and it helps launch other daemons. When all system programs are loaded, the computer is **fully booted** and waits for tasks to perform.

If there are no running programs or **user actions**, the operating system remains **idle**, waiting for an event to occur. Most events are triggered by **interrupts**, which are signals sent to the processor. Interrupts can come from hardware (like pressing a key or moving the mouse) or software. A software interrupt is called a **trap (or exception)**. This can happen due to **errors** (like dividing by zero) or when a program requests an **operating system service** using a special command called a **system call**.

<br>
<br>
---

# 
