# Interrupts

In a typical I/O operation, the device driver initiates the process by loading registers in the device controller, which then performs the action (e.g., reading data from the keyboard). The controller transfers the data to its local buffer, and once complete, it notifies the device driver. The device driver then returns control to the operating system, providing either the data or status information (e.g., “write completed successfully”). The controller informs the driver of its completion using an **interrupt**.

# Overview

Interrupts are signals sent by hardware to the CPU, usually via the system bus, that inform the CPU to stop its current task and handle the interrupt. The CPU then transfers execution to a specific location, called the `interrupt service routine (ISR)`, where it addresses the interrupt. Once the interrupt is processed, the CPU resumes its previous task.

To manage interrupts efficiently, the CPU uses a table of pointers to the interrupt service routines. This table, called the `interrupt vector`, contains the addresses of ISRs for various devices. When an interrupt occurs, the unique interrupt number is used to index this table and direct the CPU to the appropriate ISR. This process is faster than using a generic routine, which would examine the interrupt before calling the correct handler.

Additionally, the interrupt system must save the state of the interrupted task (e.g., the values of registers) so that the task can continue from where it left off after the interrupt is serviced. If the ISR modifies the CPU’s state, it must save the current state before making changes, and then restore it once the interrupt is handled. After servicing the interrupt, the CPU loads the return address into the program counter and resumes the interrupted task.

---

<br>
<br>

if you want to learn about `ISR` click [here](./ISR.md)

## Types of Interrupt

1. Software Interrupts:
   A sort of interrupt called a software interrupt is one that is produced by software or a system as opposed to hardware. Traps and exceptions are other names for software interruptions. They serve as a signal for the operating system or a system service to carry out a certain function or respond to an error condition. Generally, software interrupts occur as a result of specific instructions being used or exceptions in the operation. In our system, software interrupts often occur when system calls are made.

2. Hardware Interrupts
   In a **hardware interrupt** system, multiple devices are connected to a single **Interrupt Request (IRQ) line**. When a device needs attention, it sends an interrupt by closing its associated switch, and the IRQ line shows the logical OR of all the device requests.

   There are two types of **hardware interrupts**:

   3. **Maskable Interrupt**: This type of interrupt can be enabled or disabled using an interrupt mask register. The register allows the system to control which interrupts are allowed, making it possible to ignore certain interrupts when needed.

   4. **Spurious Interrupt**: A spurious interrupt occurs when an interrupt happens without a real cause or source, often due to wiring issues or system malfunctions. These "ghost" interrupts can be hard to diagnose and fix.

   In short, maskable interrupts can be controlled, while spurious interrupts are unwanted and difficult to track.

![intrupts type](https://media.geeksforgeeks.org/wp-content/uploads/20241210153745065033/Types-of-Interrupt.png)

---

<br>
<br>

## Flowchart of Interrupt Handling Mechanism

![Interrupt Handling Mechanism](https://media.geeksforgeeks.org/wp-content/uploads/20240801184747/Flowchart.png)

- Step 1:- Any time that an interrupt is raised, it may either be an I/O interrupt or a system interrupt.
- Step 2:- The current state comprising registers and the program counter is then stored in order to conserve the state of the process.
- Step 3:- The current interrupt and its handler is identified through the interrupt vector table in the processor.
- Step 4:- This control now shifts to the interrupt handler, which is a function located in the kernel space.
- Step 5:- Specific tasks are performed by Interrupt Service Routine (ISR) which are essential to manage interrupt.
- Step 6:- The status from the previous session is retrieved so as to build on the process from that point.
- Step 7:- The control is then shifted back to the other process that was pending and the normal process continues.

---

## Interrupt Priority Schemes

Interrupt priority schemes are used in microprocessors and microcontrollers to manage multiple interrupt requests (IRQs). These schemes ensure that more urgent tasks are processed before less important ones, making them essential for real-time systems and efficient interrupt handling.

### Types of Interrupt Priority Schemes

- Fixed Priority Scheme: In this scheme, each interrupt has a predetermined priority level. The interrupt with the highest priority is handled first. If two interrupts occur simultaneously, the one with the higher priority is serviced. Example: Interrupt A (priority 1) is serviced before Interrupt B (priority 2).

- Dynamic Priority Scheme: In a dynamic priority scheme, the priority of an interrupt can change based on system conditions. This helps prioritize real-time or critical tasks over others. Example: A system may increase the priority of a sensor interrupt based on its importance at a particular moment.

- Vectored Interrupt Scheme: Here, each interrupt has a specific memory address (vector). The processor jumps to this address to handle the interrupt, and the interrupt with the highest priority is processed first. Example: The system uses memory addresses to quickly handle the most urgent interrupts.

- Priority Masking: This scheme allows lower-priority interrupts to be temporarily disabled, ensuring that high-priority interrupts are handled immediately without delay. Example: If Interrupt A is more critical than Interrupt B, Interrupt B may be masked until Interrupt A is processed.

- Round-Robin Priority Scheme: In this scheme, interrupts are processed in a cyclic order, ensuring each interrupt gets handled fairly, especially when all interrupts have the same priority. Example:Interrupts A, B, and C are handled in a round-robin manner.

## What is Interrupt Latency?

The amount of time between the generation of an interrupt and its handling is known as interrupt latency. The number of created interrupts, the number of enabled interruptions, the number of interrupts that may be handled, and the time required to handle each interrupt all affect interrupt latency. When the device generating the interrupt needs a specific length of time to generate the interrupt, interrupt latency is required. For instance, if a printer is printing paper, the computer needs to stop the printing program and wait for the document to finish printing. The interrupt latency is the amount of time the computer has to stop the program from operating.

![intrupt](https://media.geeksforgeeks.org/wp-content/uploads/20241210152453757547/Interrupt-Latency.png)

# Implementation

The basic interrupt mechanism works as follows. The CPU hardware has a
wire called the interrupt-request line that the CPU senses after executing every
instruction. When the CPU detects that a controller has asserted a signal on
the interrupt-request line, it reads the interrupt number and jumps to the
interrupt-handler routine by using that interrupt number as an index into
the interrupt vector. It then starts execution at the address associated with
that index. The interrupt handler saves any state it will be changing during
its operation, determines the cause of the interrupt, performs the necessary
processing, performs a state restore, and executes a return from interrupt
instruction to return the CPU to the execution state prior to the interrupt. We
say that the device controller raises an interrupt by asserting a signal on the
interrupt request line, the CPU catches the interrupt and dispatches it to the
interrupt handler, and the handler clears the interrupt by servicing the device.

Most CPUs have two interrupt request lines. One is the `nonmaskable`
interrupt, which is reserved for events such as unrecoverable memory errors.
The second interrupt line is `maskable`: it can be turned off by the CPU before
the execution of critical instruction sequences that must not be interrupted. The
maskable interrupt is used by device controllers to request service.

## vector table

A **vector table** is a table that contains the addresses of interrupt service routines (ISRs) for each interrupt that a processor can handle. The vector table serves as a map for the CPU to know where to jump to in memory when a specific interrupt occurs.

### Key Points:

1. **Interrupt Vector**: Each interrupt has a unique **vector** (or address) associated with it. This vector points to the starting address of the corresponding **Interrupt Service Routine (ISR)**. When an interrupt occurs, the CPU uses the interrupt vector to find the appropriate ISR to execute.

2. **Vector Table Structure**: The vector table is a block of memory, typically located at the beginning of the memory space (often at a fixed location like address `0x0000` or `0x1000`, depending on the architecture). Each entry in the vector table corresponds to a different interrupt type, storing the address of the ISR for that interrupt.

3. **How It Works**:
   - When an interrupt is triggered, the CPU checks the vector table.
   - The CPU retrieves the address of the ISR for that specific interrupt from the table.
   - The CPU jumps to that address and starts executing the ISR.
   - Once the ISR completes, control is returned to the program that was interrupted.

### Example:

In a microcontroller or a processor, if there are multiple interrupt sources (such as timer interrupts, external device interrupts, or error interrupts), the vector table would look something like this:

| Interrupt Number | Vector Address  |
| ---------------- | --------------- |
| 0                | Address of ISR0 |
| 1                | Address of ISR1 |
| 2                | Address of ISR2 |
| ...              | ...             |
| n                | Address of ISRn |

---

The purpose of a vectored interrupt mechanism is to reduce the
need for a single interrupt handler to search all possible sources of interrupts
to determine which one needs service. In practice, however, computers have
more devices (and, hence, interrupt handlers) than they have address elements
in the interrupt vector. A common way to solve this problem is to use interrupt
chaining, in which each element in the interrupt vector points to the head of
a list of interrupt handlers. When an interrupt is raised, the handlers on the
corresponding list are called one by one, until one is found that can service
the request.

---

<br>

![vectortable](https://slideplayer.com/slide/17141160/99/images/23/13.2+I/O+Hardware+Intel+Pentium+Processor+Event-Vector+Table.jpg)

<br>

Figure illustrates the design of the interrupt vector for Intel processors.
The events from 0 to 31, which are nonmaskable, are used to signal various
error conditions. The events from 32 to 255, which are maskable, are used for
purposes such as device-generated interrupts

The interrupt mechanism also implements a system of `interrupt priority levels`. These levels enable the CPU to defer the handling of low-priority interrupts without masking all interrupts and makes it possible for a high-priority
interrupt to preempt the execution of a low-priority interrupt.
In summary, interrupts are used throughout modern operating systems to
handle asynchronous events (and for other purposes we will discuss throughout the text). Device controllers and hardware faults raise interrupts. To enable the most urgent work to be done first, modern computers use a system of interrupt priorities. Because interrupts are used so heavily for time-sensitive processing, efficient interrupt handling is required for good system performance.
