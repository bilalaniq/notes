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

When a process tries to access memory that it isn’t allowed to (such as trying to read or write to another process's memory or the kernel’s memory), the [MMU](./MMU.md) will trigger a page fault or access violation.

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

if you want to learn about `page tables` click [here](./page_table.md)

---

# Process memory model in Linux

### Memory Layout in Linux:

When a program runs on Linux, the memory is divided into four main regions (areas):

1. **Text**: This is where the program’s code (instructions) is stored.
2. **Data**: This region holds global variables, static variables, and constants.
3. **Heap**: This is where dynamic memory allocation happens (like using `malloc` or `new` in your code).
4. **Stack**: This is where local variables (those declared inside functions) and function calls are stored.

The **stack** is placed at the _highest_ address in memory. For a process running on a 64-bit system like **x86-64** Linux, the stack starts at a very high address, which is `0x7fffffffffff`. This is a big number (about **131 terabytes**) and it's close to the maximum address that can be used in the system.

### Why is `0x7fffffffffff` Chosen?

The reason this specific address is chosen has to do with how **64-bit addresses** work:

- **48-bit address space**: On x86-64 Linux, the system uses **48-bit** addresses, meaning it can address memory up to `2^48` (which is about 256 terabytes).
- **Canonical Addresses**: To make sure everything works smoothly, the operating system enforces a rule called **canonical addresses**. This rule states that addresses should not have "garbage" bits in certain higher parts of the address. Specifically, bits 49 to 63 should match the value of bit 48. This makes the address space easier to manage.

  - For example, in a valid "canonical" address, if bit 48 is 1, bits 49–63 should all be 1 as well.
  - If bit 48 is 0, then bits 49–63 should all be 0.

### Why Not Use Bit 48?

- The system decided not to use **bit 48** to ensure that the addresses stay valid under the canonical rule. By setting bit 48 to 1 (for the stack's starting address), it ensures that the higher bits (49 to 63) are all 1s, making it a proper, valid address in the system’s memory space.

### 1. **Canonical Addresses in a 32-bit System**

In a **32-bit** system, the address space is much smaller compared to a 64-bit system. Specifically, a 32-bit system can address **2^32** memory locations, which equals **4 GB** of memory (from 0x00000000 to 0xFFFFFFFF).

- **32-bit Virtual Address**: The virtual memory addresses in a 32-bit system are 32 bits long. This means the system can have a maximum of 4 GB of virtual address space.

- **Canonical Address Concept**: In 32-bit systems, there's no need for special handling of the upper bits like in 64-bit systems. Since the address space is limited to 4 GB (all within the 32-bit range), every address in the 32-bit system is considered a **valid** address. There’s no concept of "canonical" versus "non-canonical" addresses.

  So, in 32-bit systems:

  - All virtual addresses are valid, and there's no distinction between "canonical" and "non-canonical" addresses.
  - There’s no need to use upper bits (like in 64-bit systems) to mark valid or invalid addresses.

#### **Key Points in 32-bit systems:**

- The address space is 4 GB.
- Every address in this space is valid and usable, so there's no need for "canonical" address filtering.
- The OS and hardware rely on this limited address range for address translation.

---

### 2. **Canonical Addresses in a 64-bit System**

In a **64-bit** system, the address space is **enormous** — specifically, **2^64** locations, which translates to a theoretical address space of **18.4 million TB** of memory. However, as you can imagine, it's not practical or necessary to use this entire address range.

So, **canonical addresses** in a 64-bit system refer to a **subset of valid addresses** within the vast address space. The upper bits (most significant bits) of a 64-bit address are often used to **identify whether the address is valid or not**. This helps the system avoid using parts of the address space that are reserved for system-level tasks or hardware.

Here’s how it works in 64-bit systems:

- **Virtual Address Structure**: A 64-bit address is composed of a **48-bit usable address** space (on most systems) and **16 bits** that are reserved or unused. This means that the address space actually used for memory addressing is typically **48-bits** long.
- **Canonical Address Range**: A **canonical address** in a 64-bit system refers to an address where the upper unused bits (usually the top 16 bits) have a **specific value**, often set to **0** or **1**. This ensures that the address is within a valid range and helps the OS and hardware manage memory safely.

  For example:

  - On many 64-bit systems, the upper 16 bits of the address must be **0** (canonical addresses). This gives a usable virtual address range of 48 bits (addressing **256 TB** of memory), and the remaining upper bits are ignored for address translation.
  - Some systems may use these bits in a different way, but the key idea is that canonical addresses are a valid subset of the full 64-bit address space.

#### **How the OS Uses Canonical Addresses in 64-bit Systems**:

- The **canonical address range** helps the OS determine whether an address is a valid virtual address.
- The remaining **non-canonical** addresses (i.e., addresses where the upper bits do not follow the expected pattern) are considered **invalid**. If a program or process tries to access such an address, the operating system will raise an error, often causing a **segmentation fault** or access violation.

- **Memory Management**: The OS uses these canonical address ranges to manage the virtual memory, ensuring programs only access valid areas of memory. This process helps in the isolation of processes and protects kernel memory from being accessed by user-space applications.

#### Example of Canonical Addressing in 64-bit:

- **Canonical Address**: In many systems, the valid addresses are those that fall within the range where the top 16 bits are **0**. This means that valid addresses are typically between `0x0000000000000000` and `0x0000FFFFFFFFFFFF`.
- **Non-Canonical Address**: Addresses where the upper 16 bits are not `0` (e.g., `0xFFFF000000000000`) are considered invalid.

#### **Key Points in 64-bit systems:**

- The 64-bit address space is very large, but only a portion of it is used for valid memory addresses.
- Canonical addresses are the valid addresses within a smaller, usable portion of the 64-bit space (usually 48 bits).
- The upper 16 bits are reserved or set to a specific value (often 0 or 1) to ensure only valid addresses are used.
- Non-canonical addresses (invalid addresses) are those that don’t conform to this pattern and are generally rejected by the OS.

---

### Summary: Canonical Addresses in 32-bit vs 64-bit Systems

- **32-bit Systems**:

  - The address space is small (4 GB).
  - All addresses within the 4 GB range are valid, so the concept of "canonical" addresses doesn’t apply.

- **64-bit Systems**:
  - The address space is vast (up to 18.4 million TB), but only a portion is actually usable.
  - Canonical addresses are valid addresses within the usable portion of the 64-bit address space, typically 48-bits long.
  - The top 16 bits are reserved for OS and hardware use, ensuring that only valid memory addresses are accessed by programs.
  - Non-canonical addresses (addresses with unusual high-order bits) are invalid and not accessible.

In summary, the concept of **canonical addresses** in 64-bit systems is primarily a way to ensure that only valid, meaningful addresses are used for memory access, which improves security, simplifies memory management, and prevents errors. In contrast, 32-bit systems don't need such a system because the address space is much smaller and fully usable.

<br>
<br>

---

![memory maping](https://open4tech.com/wp-content/uploads/2017/04/Memory_Layout.jpg)

---

we see the arrangement of the various memory segments.
At the lowest address we have the text segment . This
segment is shown starting at 0, though both start and main are at higher addresses. It appears that the lowest address in an x86-64 process is Ox400000. The text
segment does not typically need to grow, so the
data segment is placed immediately above the text
segment. Above these two segments are the heap
and stack segments.

The data segment starts with the . data segment which contains initialized data. Above that is
the . bss segment which stands for "block started
by symbol". The . bss segment contains data which
is statically allocated in a process, but is not stored
in the executable file. Instead this data is allocated
when the process is loaded into memory. The initial
contents of the . bss segment are all 0 bits.

The heap is not really a heap in the sense Process
discussed in a data structures course. Instead is a dy- memory layout
namically resizable region of memory which is used
to allocate memory to a process through functions like malloc in C and
the new operator in C++. In x86-64 Linux this region can grow to very
large sizes. The limit is imposed by the sum of physical memory and
swap space.

The final segment of a process is the stack segment. This segment is
restricted in size by the Linux kernel, typically to 16 megabytes. This is
not a large amount of space, but as long as the programmer avoids putting
large arrays on the stack it serves the purpose quite well of managing the
run-time stack keeping track of function calls, parameters, local variables
and return addresses.

Given the top of the stack as Ox7fffffffffff and the stack size
limited to 16 megabytes we see that the lowest valid stack address is
Ox7fffff000000. The stack automatically grows when needed by the
operating system responding to a `page fault`. The operating system recognizes the faulting address as being in the range from Ox7fffff000000
to Ox7fffffffffff, which is only used for the stack and allocates a new
page of memory ( 4096 bytes) to the process.

This simple memory layout is not entirely accurate. There are shared
object files which can be mapped into a process after the program is
loaded which will result in regions in the heap range being used to to
store instructions and data. This region is also used for mapping shared
memory regions into a process.

If you wish to examine the memory used by one of your processes,
you can execute `cat /proc/999/maps` where 999 needs to be replaced
by your process id. To see the memory used by your shell process, enter

```bash
cat /proc/$$/maps
```

to see all the processes running in linux you could use this command

```bash
ps -e -o pid
```

this will only print the process ids of the programs running you could also change the -o type

## example

```bash
section .data

a dd 4
b dd 4.4
c times 10 dd 0
d dw 1 ,2
e db 0xfb
f db "helo world" , 0

section .bss

g       resd 1
h       resd 10
i       resb 100

section .text

global  _start

_start:

push    rbp
mov     rbp, rsp
sub     rsp, 16


xor     eax, eax
leave
ret

```

now if we look at the `.lst` file by this command

```bash
nasm -f elf64 -l memory.lst -o memory.o memory.asm
```

we will get this

```text

     1                                  section .data
     2
     3 00000000 04000000                a dd 4
     4 00000004 CDCC8C40                b dd 4.4
     5 00000008 00000000<rep Ah>        c times 10 dd 0
     6 00000030 01000200                d dw 1 ,2
     7 00000034 FB                      e db 0xfb
     8 00000035 68656C6F20776F726C-     f db "helo world" , 0
     8 0000003E 6400
     9
    10                                  section .bss
    11
    12 00000000 ????????                g       resd 1
    13 00000004 <res 28h>               h       resd 10
    14 0000002C <res 64h>               i       resb 100
    15
    16                                  section .text
    17
    18                                  global  main
    19
    20                                  main:
    21
    22 00000000 55                      push    rbp
    23 00000001 4889E5                  mov     rbp, rsp
    24 00000004 4883EC10                sub     rsp, 16
    25
    26
    27 00000008 31C0                    xor     eax, eax
    28 0000000A C9                      leave
    29 0000000B C3                      ret

```

to examine memory using gdb click [here](./../gdb/Readme.md)

---

<br>
<br>

# Exercises

- #### 1. Assuming that the stack size limit is 16MB, about how large canyou declare an array of doubles inside a C++ function. Do not use the keyword static.

  To calculate the maximum size of an array of doubles you can declare inside a C++ function given that the stack size limit is 16 MB, we need to consider the following factors
  **Stack Size Limit**: You are given that the stack size is limited to 16 MB (16 _ 1024 _ 1024 bytes)
  **Size of `double`**: In most systems, a `double` typically takes **8 bytes** of memory

  ### Steps to Calculate the Maximum Number of Element

  **Total stack size limit**: 16 MB = 16 _ 1024 _ 1024 bytes = 16,777,216 bytes.
  **Size of each `double`**: 8 bytes
  **Maximum number of `double` elements**:
  To calculate the maximum number of `double` elements you can declare, we divide the total stack size by the size of a `double`
  Maximum Number of Doubles = Total Stack Size / Size of Each Double
  Maximum Number of Doubles = 16,777,216 bytes / 8 bytes
  Maximum Number of Doubles = 2,097,152 double

  ### Conclusion

  Given a 16 MB stack size limit, you can declare an array of **2,097,152 doubles** inside a C++ function without exceeding the stack size, assuming the `double` type is 8 bytes (which is the typical size on most platforms)

  ### Important Consideration

  - **Function Call Stack**: The array will be allocated on the **local stack**. If your program uses recursion or has other large local variables, this could affect how much of the stack is available for your array.
  - **Operating System and Compiler Limitations**: Stack size limits may be configurable depending on the platform, operating system, and compiler. The exact behavior could vary, so it's important to verify stack size configurations if you are working in a specific environment
    If the array size exceeds the stack size limit, a **stack overflow** error will occur, causing the program to crash. To allocate larger arrays, consider using **heap memory** (via `new` or `malloc`), which is not limited by the stack size.

---

<br>
<br>

---

- #### 2. Find out the stack size limit using the ulimit command in bash. If bash is not your shell, simply type in bash to start a sub-shell.

  To find out the stack size limit using the `ulimit` command in bash, follow these steps:

  ### Steps:

  1. **Open a Terminal**: If you are not already in a terminal, open one.
  2. **Start a bash shell** (if you are using a different shell):
     If you're not currently using bash, start a bash shell by typing:
     ```bash
     bash
     ```
  3. **Check the Stack Size Limit**:
     Once you're in the bash shell, run the following command:
     ```bash
     ulimit -s
     ```
     This will display the **stack size limit** in kilobytes (KB). For example, you might see something like:
     ```
     8192
     ```
     This means the stack size limit is 8192 KB (or 8 MB).

  ### Explanation:

  - **`ulimit -s`**: This command shows the stack size limit in the current shell session. The stack size refers to the maximum amount of memory that can be allocated for the call stack (i.e., the memory used for function calls, local variables, and return addresses).
  - The output will be in **kilobytes (KB)**. To convert it to megabytes (MB), divide the value by 1024. For instance, 8192 KB is 8 MB.

  ### Additional Information:

  - If you want to check other limits (like the maximum number of open file descriptors), you can use the `ulimit` command with other options. For example:
    ```bash
    ulimit -a  # Displays all current limits, including stack size
    ```
    output:

  ```bash
  > ulimit -a
  real-time non-blocking time  (microseconds, -R) unlimited
  core file size              (blocks, -c) 0
  data seg size               (kbytes, -d) unlimited
  scheduling priority                 (-e) 0
  file size                   (blocks, -f) unlimited
  pending signals                     (-i) 31528
  max locked memory           (kbytes, -l) 65536
  max memory size             (kbytes, -m) unlimited
  open files                          (-n) 1024
  pipe size                (512 bytes, -p) 8
  POSIX message queues         (bytes, -q) 819200
  real-time priority                  (-r) 0
  stack size                  (kbytes, -s) 8192
  cpu time                   (seconds, -t) unlimited
  max user processes                  (-u) 31528
  virtual memory              (kbytes, -v) unlimited
  file locks                          (-x) unlimited
  ```

  ***

<br>
<br>

---

<br>
<br>

- #### 3. Suppose you were given the opportunity to redesign the memory mapping hierarchy for a new CPU. We have seen that 4 KB pages seem a little small. Suppose you made the pages 2^17 = 131072 bytes. How many 64 bit pointers would fit in such a page? How many bits would be required for the addressing of a page table? How would you break up the bit fields of virtual addresses?

  ### 1. **Number of 64-bit pointers in a 128 KB page**:

  - A **64-bit pointer** is 8 bytes.
  - **Page size** is **128 KB (131,072 bytes)**.
  - Number of pointers in the page:

    131,072 / 8 = 16,384 pointers

  ### 2. **Bits for addressing a page table**:

  - Each page table has **16,384 entries**.
  - Bits required to address 16,384 entries:

    log2(16,384) = 14 bits

  ### 3. **Breaking up the virtual address** (for a 64-bit address):

  - **Page size** :
    131,072 bytes / 1024 = 128 KB
  - since 131,072 bytes = 128 KB
    log2(131,072) = 17 bits
    Thus, 17 bits are required for the page offset to address a location within the 128 KB page.
  - Remaining bits for **virtual page number**:

    64 - 17 - 14 = 33 bits

  ### Summary:

  - **Page offset**: **17 bits**
  - **Page table index**: **14 bits**
  - **Virtual page number**: **33 bits**

---

<br>
<br>

- #### 4. Having much larger pages seems desirable. Let's design a memory mapping system with 2^20 = 1048576 bytes but use partial pages for memory mapping tables. Design a system with 3 levels of page mapping tables with at least 48 bits of usable virtual address space.

To design a memory mapping system with **1 MiB (2²⁰ bytes) pages** and **at least 48-bit virtual address space**, while using **partial pages for memory mapping tables**, we can follow this approach:

### **Key Assumptions:**

- **Page size = 1 MiB (2²⁰ bytes)**
- **Virtual address space = 48 bits**
- **Partial pages for page tables (i.e., each table doesn't need a full page)**

### **Breakdown of Virtual Address Structure:**

A **48-bit virtual address** needs to be divided among:

1. **L1 Index** (Level 1 Page Table)
2. **L2 Index** (Level 2 Page Table)
3. **L3 Index** (Level 3 Page Table)
4. **Offset within Page** (Determined by the page size)

Since we are using **1 MiB pages (2²⁰ bytes)**, the **offset** part of the virtual address takes **20 bits**. That leaves us with **28 bits** for indexing page tables.

Using **partial pages**, assume **each page table entry is 8 bytes** (64-bit address), so a **1 KiB (2¹⁰ bytes) partial page** can hold:

2^10(bytes per partial page) / 8 (bytes per entry) = 2^7 = 128 entries per table


Thus, we need **3 levels of page tables** to cover the full 48-bit space:

- **L1 Index:** **10 bits** → 1024 entries
- **L2 Index:** **9 bits** → 512 entries
- **L3 Index:** **9 bits** → 512 entries
- **Offset:** **20 bits** (for 1 MiB pages)


This ensures a **3-level page table** that efficiently maps a **48-bit virtual address space** with **1 MiB pages**, while minimizing page table memory usage by using **partial pages**. 🚀
