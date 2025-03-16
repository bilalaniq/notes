# Operating-System Operations

An **operating system** is the main software that manages a computer and allows other programs to run. It provides an **environment** where programs can be executed. Although different operating systems work in different ways, they share many common features.

When a computer **starts or reboots**, it needs an **initial program** to run. This program is called the **bootstrap program**. It is usually stored in **firmware** (a type of permanent software inside the hardware). The **bootstrap program** prepares the system by **initializing the CPU, memory, and other hardware components**. Then, it finds the **operating system kernel** and loads it into memory so that the system can start working.

Once the **kernel** is running, it begins **providing services** to users and programs. Some of these services are handled by **system programs** called [**daemons**](./daemons.md), which run continuously in the background. On **Linux**, the first daemon to start is called **systemd**, and it helps launch other daemons. When all system programs are loaded, the computer is **fully booted** and waits for tasks to perform.

If there are no running programs or **user actions**, the operating system remains **idle**, waiting for an event to occur. Most events are triggered by **interrupts**, which are signals sent to the processor. Interrupts can come from hardware (like pressing a key or moving the mouse) or software. A software interrupt is called a **trap (or exception)**. This can happen due to **errors** (like dividing by zero) or when a program requests an **operating system service** using a special command called a **system call**.

<br>
<br>
---

# Multiprogramming and Multitasking

### **Multiprogramming**:

Multiprogramming is a method used by operating systems to improve the efficiency of CPU utilization by executing multiple programs simultaneously. In a multiprogramming system, the CPU is kept busy by switching between different programs or processes, which are loaded into memory. The operating system allocates time slices to each process, allowing the CPU to handle tasks from several programs without idle time. However, at any given moment, only one process is being executed, but because of rapid switching, it seems like multiple programs are running at the same time. The key advantage of multiprogramming is that it maximizes CPU usage and reduces idle time, thus improving the overall performance of the system. The processes are typically independent of each other, and the operating system manages them by keeping track of which process is to be executed next.

### **Multitasking**:

Multitasking is an extension of the concept of multiprogramming, where the operating system can manage multiple tasks or processes, giving the illusion that the system is executing them concurrently. In multitasking, the CPU switches between tasks so quickly that it seems as though all tasks are running at the same time, even though, in reality, the CPU is switching between them. There are two types of multitasking: **preemptive** and **cooperative**. In preemptive multitasking, the operating system can forcibly interrupt a running process to switch to another, ensuring fair distribution of CPU time among all processes. In cooperative multitasking, each process must yield control to the operating system voluntarily. The main benefit of multitasking is that it allows users to run multiple applications simultaneously, improving productivity and system responsiveness. Multitasking is especially useful in modern computing environments where users often need to run several applications concurrently.

---

<br>
<br>

# Dual-Mode and Multimode Operation

Computers use **two modes of operation**: **kernel mode** (also called supervisor mode) and **user mode** to ensure that programs do not interfere with each other or the operating system. A special **mode bit** in the hardware indicates the current mode—**0 for kernel mode** and **1 for user mode**.

At startup, the system begins in **kernel mode**, where the operating system is loaded. Once user applications start, the system switches to **user mode**. If a user program needs to perform an operation that requires system privileges (like accessing hardware), it must make a **system call**, which triggers a switch from user mode to kernel mode. This switch is done using a **trap or interrupt**, and the operating system takes control to execute the requested operation safely.

Some operations, called **privileged instructions** (such as managing I/O or handling interrupts), can only be executed in **kernel mode**. If a user program tries to execute them directly, the hardware prevents it and sends an error to the operating system.

Many modern processors support **more than two modes**. For example, Intel processors have **four protection rings**, but most systems use only **ring 0 (kernel mode)** and **ring 3 (user mode)**. Some CPUs also include a special mode for **virtualization**, allowing a **virtual machine manager (VMM)** to control virtual machines securely.

When a **system call** is made, the processor treats it like a **software interrupt**, switching to kernel mode and executing the requested operation. The OS then verifies the request, executes it, and returns control to the user program. If an error occurs (like accessing restricted memory or executing an invalid instruction), the hardware detects it and **traps** to the OS, which may terminate the program and display an error message.

This dual-mode operation ensures **system stability and security**, preventing user programs from harming the operating system or each other. Almost all modern operating systems, including **Windows, Linux, and Unix**, use this model for protection and resource management.

**Kernel mode vs. user mode** is different from **admin (root) vs. normal user**.

- **Kernel mode vs. User mode** is a **hardware-level** protection mechanism.

  - **Kernel mode** allows execution of privileged instructions that control the system.
  - **User mode** is restricted, preventing direct access to hardware or critical system resources.

- **Admin (root) vs. Normal user** is a **software-level** privilege system.
  - A **normal user** has limited permissions (e.g., cannot modify system files).
  - An **admin (root) user** has higher privileges and can make system-wide changes.

Even if a **root user** has more control over the system, they still run programs in **user mode** by default. They can switch to **kernel mode only through system calls**, just like a normal user. Directly executing kernel-mode instructions still requires **going through the operating system**.

![dual mode](https://blog.kakaocdn.net/dn/dPrnTn/btqB7cEBAY0/GhTW1eYuySrlopH6ULyVzk/img.png)

---

<br>

That is, commands that can cause important dangerous situations can only be operated in kernel mode, and
only operations that do not can be operated through user mode.

![dual mode](https://velog.velcdn.com/images%2Fasdfg5415%2Fpost%2Fe45e9c6d-0af8-4811-8e65-1326c0d5a93e%2Fimage.png)

When a user program calls a function like `open()` to perform a task that needs the operating system’s permission (such as opening a file), it does not directly interact with the system's interrupt handling mechanism.

Instead, it goes through a **wrapper function**, which is part of the **Runtime Environment (RTE)**. This wrapper function is a layer that simplifies the interaction between the user program and the operating system.

Inside this wrapper, the system call is actually made. The function sends necessary details (like parameters and the system call number) to the operating system. At this point, the **Mode bit** changes from **user mode to kernel mode**, allowing the system to perform the requested operation securely.

## Transferring data from user mode to kernel mode

Three general methods are used to pass parameters to the operating system.
The simplest approach is to pass the parameters in registers. In some cases, however, there may be more parameters than registers. In these cases, the parameters are generally stored in a block, or table, in memory, and the address of the block is passed as a parameter in a register

Linux uses a combination of these approaches.
If there are five or fewer parameters, registers are used.
If there are more than five parameters, the block method is used. Parameters also can be placed, or pushed, onto a stack by the program and popped off the stack by the operating system.

Some operating systems prefer the block or stack method because those approaches do not limit the number or length of parameters being passed.

![data transfer](https://velog.velcdn.com/images%2Fasdfg5415%2Fpost%2F0d7cbd14-4f4a-4f81-ab79-da7d9a815cde%2Fimage.png)

Since System Call is also an interrupt, it is processed through the interrupt vector table.
The interrupt vector table number that processes System Call is different for each operating system. (Linux is 128)
Based on Linux, it goes to table 128 and searches for a handler for the System Call.

Afterwards, the actual processing of the corresponding System Call number is performed through the System Call number passed as a parameter (Actual Parameter) inside the handler function that processes the System Call.

![sys-call](https://velog.velcdn.com/images%2Fasdfg5415%2Fpost%2F126a30bb-6b2d-4b73-950b-26790e6ff642%2Fimage.png)

# Timer

The operating system must always stay in control of the CPU. We cannot allow a user program to run forever without returning control to the system. To prevent this, we use a **timer**.

A timer is set to interrupt the computer after a certain time, which can be **fixed** (like every 1/60th of a second) or **adjustable** (from 1 millisecond to 1 second). The timer works with a clock and a counter:

- The OS sets the counter.
- Every clock tick decreases the counter.
- When the counter reaches **zero**, an **interrupt** happens, and the OS takes back control.

Before giving control to a user program, the OS ensures the timer is set. If the timer runs out, the OS can stop the program or give it more time. **Only the OS can change the timer settings** because modifying it is a **privileged operation** to prevent users from disabling it.
