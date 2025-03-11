# Storage Structure

The CPU can load instructions only from memory, so any programs must
first be loaded into memory to run. General-purpose computers run most
of their programs from rewritable memory, called main memory (also called
random-access memory, or RAM). Main memory commonly is implemented in
a semiconductor technology called [dynamic random-access memory (DRAM)](./DRAM.md)

Computers use other forms of memory as well. For example, the first program to run on computer power-on is a bootstrap program, which then loads the operating system. Since RAM is volatile—loses its content when power
is turned off or otherwise lost. we cannot trust it to hold the bootstrap program. Instead, for this and some other purposes, the computer uses [electrically erasable programmable read-only memory (EEPROM)](./EEPROM.md) and other forms of
firmwar —storage that is infrequently written to and is nonvolatile.

Memory in a computer is structured as an array of bytes, with each byte having a unique address. The CPU interacts with memory through load and store instructions. A load operation retrieves data from a specific memory address and places it into a CPU register, while a store operation transfers data from a register back into memory. In addition to these explicit operations, the CPU automatically fetches instructions from memory based on the address stored in the program counter (PC). This process ensures smooth execution of programs by continuously loading and executing instructions from memory.

Ideally, we want the programs and data to reside in main memory permanently. This arrangement usually is not possible on most systems for two reasons:

- Main memory is usually too small to store all needed programs and data
  permanently.

- Main memory, as mentioned, is volatile—it loses its contents when power
  is turned off or otherwise lost.

here comes the `secondary storage`.

**Secondary storage** refers to non-volatile storage devices used to store data permanently, even when the computer is powered off. Examples include hard drives (HDDs), solid-state drives (SSDs), USB flash drives, and optical discs (CDs/DVDs).

Most programs (system and application) are stored in
secondary storage until they are loaded into memory. Many programs then use
secondary storage as both the source and the destination of their processing.
Secondary storage is also much slower than main memory. Hence, the proper
management of secondary storage is of central importance to a computer system

there is also another type of memory called `Tertiary storage`

**Tertiary storage** refers to storage systems used for long-term data archiving and backup, typically involving removable media such as magnetic tapes, optical discs, or cloud-based archival storage. It is slower than primary and secondary storage and is usually accessed infrequently.

In a larger sense, however, the storage structure that we have described
consisting of registers, main memory, and secondary storage is only one
of many possible storage system designs. Other possible components include
cache memory, CD-ROM or blu-ray, magnetic tapes, and so on. Those that are
slow enough and large enough that they are used only for special purposes

![storage](https://o.quizlet.com/np0-vaD4wYT1K-k.2mPNMg.png)

---

<br>
<br>

trade-off between size and speed, with smaller and faster memory closer to the
CPU. As shown in the figure, in addition to differing in speed and capacity, the
various storage systems are either `volatile` or `nonvolatile`.

- **Volatile storage** as mentioned earlier, loses its contents when the power to the device is removed.
- **Non Volatile storage** does not loses its contents when the power to the device is removed.

so data must be written to nonvolatile storage for safekeeping.

- The top four levels of memory in the figure are constructed using semiconductor memory, which consists of semiconductor-based electronic circuits.

- NVM devices, at the fourth level, have several variants but in general are faster
  than hard disks. The most common form of NVM device is [flash memory](./flashmemory.md), which
  is popular in mobile devices such as smartphones and tablets. Increasingly,
  flash memory is being used for long-term storage on laptops, desktops, and
  servers as well.

  Types of NVM

  - Mechanical. A few examples of such storage systems are HDDs, optical
    disks, holographic storage, and magnetic tape.

  - Electrical. A few examples of such storage systems are flash memory,
    FRAM, NRAM, and SSD.

  Mechanical storage is generally larger and less expensive per byte than
  electrical storage. Conversely, electrical storage is typically costly, smaller,
  and faster than mechanical storage
