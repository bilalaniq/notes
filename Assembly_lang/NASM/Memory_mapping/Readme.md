# Memory mapping

The memory of a computer can be considered an array of bytes. Each
byte of memory has an address. The first byte is at address 0, the second
byte at address 1, and so on until the last byte of the computer's memory

In modern CPUs there are hardware mapping registers which are used
to give each process a protected address space. This means that multiple
people can each run a program which starts at address Ox4004c8 at the
same time. These processes perceive the same "logical" addresses, while
they are using memory at different "physical" addresses.

in simple words this is a feature of modern CPUs that allows multiple processes to run simultaneously while giving the illusion that each process has its own dedicated memory space. This is achieved using virtual memory and hardware mapping, which provides address translation from "logical" (or virtual) addresses to "physical" addresses in the system's memory.

The hardware mapping registers on an x86-64 CPU can map pages of
2 different sizes - 4096 bytes and 2 megabytes. Linux uses 2 MB pages
for the kernel and 4 KB pages for most other uses. In some of the more
recent CPUs there is also support for 1 GB pages.

The operation of the memory system is to translate the upper bits of
the address-from a process's logical address to a physical address. Let's
consider only 4 KB pages. Then an address is translated based on the page number and the address within the page.

Suppose a reference is
made to logical address Ox4000002220.

Since the page size is 4096 bytes (which is 2^12), the address is split into two parts:

- Page number: This tells you which page the address belongs to.
- Offset: This tells you where the data is within that page.

in binary
0x4000002220 = `0100 0000 0000 0000 0000 0000 0010 0010 0010 0000`

The lowest 12 bits (0x220 in hexadecimal or 0010 0010 0010 0000 in binary) are the offset within the page. So, the offset is `0x220`.

The page number (`0x4000002`) is then used to look up the corresponding physical page in the page table. A page table is a structure in memory that maps virtual page numbers (like 0x4000002) to physical page numbers (where the data actually resides in physical memory).

A hardware register (or multiple
registers) translates this page number to a physical page address, let's say
Ox780000000. Then the two addresses are combined to get the physical
address `Ox780000220`.

```bash
Physical Address = Physical Page Address + Offset
                 = 0x780000000 + 0x220
                 = 0x780000220
```

---

```bash
Logical Address:    0x4000002220
+---------------------+---------------------+
|   Page Number       |      Offset         |
|    0x4000002        |        0x220        |
+---------------------+---------------------+

Page Table Lookup:
Page Number 0x4000002 maps to Physical Page Address 0x780000000

Physical Address:
+-----------------------+-------------------+
| Physical Page Address |   Offset          |
|      0x780000000      |      0x220        |
+-----------------------+-------------------+
Physical Address = 0x780000220

```

![v&p memorry](https://ucarecdn.com/087182f1-1876-46c7-b8f0-6a5c49b5b964/)

---


`note` : while the theoretical limit for 64-bit addresses is 64 bits, 48 bits are actually used for logical addresses in most modern systems (like x86-64).

<br>
<br>

## memory proteection

Amazingly the CPU generally performs the translations without slowing down and this benefits '
the users in several ways. The most obvious
benefit is memory protection. User processes are limited to reading and
writing only their own pages. This means that the operating system is
protected from malicious or poorly coded user programs. Also each user
process is protected from other user processes. In addition to protection
from writing, users can't read other users' data.

The page table is a data structure used by the OS to store the mapping between a process’s virtual addresses and physical addresses
Each page table entry (PTE) contains not just the physical address of the page but also various access permissions that the operating system can enforce:

- Read/Write permissions
- Execute permissions
- User/Supervisor (Kernel) permissions: Determines whether the page is accessible by user-level programs or only by the kernel.

The OS might give the process read and write access to its own pages but no access to other processes' pages.
Kernel pages: These are protected and can only be accessed when the program is in kernel mode. User processes cannot directly access kernel memory.

When a process tries to access memory that it isn’t allowed to (such as trying to read or write to another process's memory or the kernel’s memory), the MMU will trigger a page fault or access violation.

The operating system handles this violation by terminating the offending process or triggering a protective action (e.g., memory protection exception or segmentation fault).
This prevents malicious or buggy code from reading or modifying the memory of other processes or the operating system.

## User and Kernel Space Isolation:

- User space: This is the memory area where user-level processes run. The OS ensures that processes running in user space can only access their own pages.

- Kernel space: This is a separate, protected memory area reserved for the operating system. User processes are not allowed to access kernel memory directly. If a user process tries to access kernel memory (say by performing an illegal operation like writing to a restricted page), the MMU will trigger a page fault or exception, and the OS can handle it appropriately (usually by killing the process).

### for example:

When you write software which accesses data beyond
the end of an array, you sometimes get a segmentation fault . However
you only get a segmentation fault when your logic:al address reaches far
enough past the end of the array to cause the CPU to reference a page
table entry which is not mapped into your process.

---

# Process memory model in Linux



