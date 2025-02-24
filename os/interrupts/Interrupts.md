# Interrupts

In a typical I/O operation, the device driver initiates the process by loading registers in the device controller, which then performs the action (e.g., reading data from the keyboard). The controller transfers the data to its local buffer, and once complete, it notifies the device driver. The device driver then returns control to the operating system, providing either the data or status information (e.g., “write completed successfully”). The controller informs the driver of its completion using an **interrupt**.

# Overview

Interrupts are signals sent by hardware to the CPU, usually via the system bus, that inform the CPU to stop its current task and handle the interrupt. The CPU then transfers execution to a specific location, called the `interrupt service routine (ISR)`, where it addresses the interrupt. Once the interrupt is processed, the CPU resumes its previous task.

To manage interrupts efficiently, the CPU uses a table of pointers to the interrupt service routines. This table, called the interrupt vector, contains the addresses of ISRs for various devices. When an interrupt occurs, the unique interrupt number is used to index this table and direct the CPU to the appropriate ISR. This process is faster than using a generic routine, which would examine the interrupt before calling the correct handler.

Additionally, the interrupt system must save the state of the interrupted task (e.g., the values of registers) so that the task can continue from where it left off after the interrupt is serviced. If the ISR modifies the CPU’s state, it must save the current state before making changes, and then restore it once the interrupt is handled. After servicing the interrupt, the CPU loads the return address into the program counter and resumes the interrupted task.

![intrupt](https://media.geeksforgeeks.org/wp-content/uploads/20241210152453757547/Interrupt-Latency.png)

---

<br>
<br>

if you want to learn about `ISR` click [here](./ISR.md)
