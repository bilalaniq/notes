# Context Switching in Operating System

Context switching in an operating system involves saving the context or state of a running process so that it can be restored later, and then loading the context or state of another. process and run it.

Context Switching refers to the process/method used by the system to change the process from one state to another using the CPUs present in the system to perform its job.

Suppose in the OS there (N) numbers of processes are stored in a Process Control Block(PCB). like The process is running using the CPU to do its job. While a process is running, other processes with the highest priority queue up to use the CPU to complete their job.

Switching the CPU to another process requires performing a state save of the current process and a state restore of a different process. This task is known as a context switch. When a context switch occurs, the kernel saves the context of the old process in its PCB and loads the saved context of the new process scheduled to run. Context-switch time is pure overhead because the system does no useful work while switching. Switching speed varies from machine to machine, depending on the memory speed, the number of registers that must be copied, and the existence of special instructions (such as a single instruction to load or store all registers). A typical speed is a few milliseconds. Context-switch times are highly dependent on hardware support. For instance, some processors (such as the Sun UltraSPARC) provide multiple sets of registers. A context switch here simply requires changing the pointer to the current register set. Of course, if there are more active processes than there are register sets, the system resorts to copying register data to and from memory, as before. Also, the more complex the operating system, the greater the amount of work that must be done during a context switch

## Need of Context Switching

Context switching enables all processes to share a single CPU to finish their execution and store the status of the system’s tasks. The execution of the process begins at the same place where there is a conflict when the process is reloaded into the system.

- One process does not directly switch to another within the system. Context switching makes it easier for the operating system to use the CPU’s resources to carry out its tasks and store its context while switching between multiple processes.

- Context switching enables all processes to share a single CPU to finish their execution and store the status of the system’s tasks. The execution of the process begins at the same place where there is a conflict when the process is reloaded into the system.

- Context switching only allows a single CPU to handle multiple processes requests parallelly without the need for any additional processors.

## Context Switching Triggers

The three different categories of context-switching triggers are as follows.

- Interrupts:
  When a CPU requests that data be read from a disc, if any interruptions occur, context switching automatically switches to a component of the hardware that can handle the interruptions more quickly.

- Multitasking:
  The ability for a process to be switched from the CPU so that another process can run is known as context switching. When a process is switched, the previous state is retained so that the process can continue running at the same spot in the system.

- User/Kernel switch:
  This trigger is used when the OS needed to switch between the user mode and kernel mode.

---

## What is Process Control Block(PCB)?

So, The Process Control block(PCB) is also known as a Task Control Block. it represents a process in the Operating System. A process control block (PCB) is a data structure used by a computer to store all information about a process. It is also called the descriptive process. When a process is created (started or installed), the operating system creates a process manager.


## Working Process Context Switching

So the context switching of two processes, the priority-based process occurs in the ready queue of the process control block. These are the following steps.

- The state of the current process must be saved for rescheduling. 
- The process state contains records, credentials, and operating system-specific information stored on the PCB or switch.
- The PCB can be stored in a single layer in kernel memory or in a custom OS file.
- A handle has been added to the PCB to have the system ready to run.
- The operating system aborts the execution of the current process and selects a process from the waiting list by tuning its PCB.
- Load the PCB’s program counter and continue execution in the selected process.
- Process/thread values ​​can affect which processes are selected from the queue, this can be important.

---

![context switching](https://media.geeksforgeeks.org/wp-content/uploads/20210615183559/swapping1.png)