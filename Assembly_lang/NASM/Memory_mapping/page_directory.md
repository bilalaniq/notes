# page directory

A **Page Directory** is a crucial part of the virtual memory system in an operating system, specifically in a paging mechanism. It serves as an intermediary between the virtual memory space of a process and the physical memory, helping to map virtual addresses to physical addresses.

In modern systems, especially with architectures like x86 and x86-64, the page directory is a fundamental part of the page table hierarchy used for address translation.

Let’s break down the **Page Directory** in full detail:

### 1. **Purpose of the Page Directory**

The page directory helps manage the mapping between **virtual memory** and **physical memory** in systems that use **paging**. In a typical paging system (like x86 architecture), the virtual address is split into multiple parts to locate the corresponding physical address.

- **Page Directory**: Points to multiple **Page Tables**.
- **Page Tables**: Map virtual pages to physical memory frames.

The page directory is part of a hierarchical paging system, where it allows the virtual address to be broken down into different levels.

### 2. **Structure of a Page Directory**

In a typical **x86** architecture with 32-bit addressing, the virtual address is divided into the following parts:

- **Page Directory** (top level)
- **Page Table** (middle level)
- **Page Frame** (bottom level)

For 32-bit systems:

- The **virtual address** is typically 32 bits in length.
- The address is divided as follows:
  - **10 bits** for the Page Directory index
  - **10 bits** for the Page Table index
  - **12 bits** for the offset within the page.

For **x86-64** (64-bit architecture), the address can be divided into more levels, but the basic concept remains similar, with the virtual address split into higher and lower parts that refer to the page directory, page tables, and offsets.

#### **Format of a Page Directory Entry (PDE)**

Each entry in a **Page Directory** is typically 4 bytes (32 bits) on a 32-bit architecture. Here’s how each entry is broken down:

| Bits  | Field Name                     | Description                                                                                                                                                                     |
| ----- | ------------------------------ | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 31-12 | Physical Page Table Address    | Points to a **Page Table** in memory. The physical address of the page table.                                                                                                   |
| 11    | **Reserved**                   | Reserved for alignment, always set to 0.                                                                                                                                        |
| 10    | **User/Supervisor**            | This bit indicates the level of privilege required to access the page. If set to `0`, only the kernel can access this page. If set to `1`, the page is accessible in user mode. |
| 9     | **Read/Write**                 | This bit indicates if the page is read-write (1) or read-only (0).                                                                                                              |
| 8     | **Present (P)**                | This bit indicates whether the page table is in memory and can be used. If set to `1`, the page table is present.                                                               |
| 7     | **Page-Level Write-Through**   | This bit controls the caching behavior. If set to `1`, writes to the page are written through to the physical memory immediately.                                               |
| 6     | **Page-Level Cache Disable**   | If set to `1`, the page is not cached.                                                                                                                                          |
| 5     | **Accessed**                   | This bit is set by the hardware to indicate whether the page has been accessed since the last time the flag was cleared.                                                        |
| 4     | **Dirty**                      | This bit is set when the page has been written to (modified).                                                                                                                   |
| 3     | **Page Attribute Table (PAT)** | Used to control cache settings, this bit is part of a system-wide cache management setting.                                                                                     |
| 2     | **Global Page (G)**            | If set, this entry marks the page as global, meaning it will not be invalidated on a context switch.                                                                            |
| 1     | **Available for Software Use** | This bit is available for operating systems to use for various purposes.                                                                                                        |
| 0     | **No Execute (NX)**            | On systems that support it, this bit can prevent execution of instructions from this page (used for security).                                                                  |

### 3. **How the Page Directory Works**

The page directory itself is an array of **Page Directory Entries (PDEs)**, and each entry points to a **Page Table**.

#### **Steps for Virtual Address Translation (on x86 architecture)**

Let’s take a look at how a virtual address is translated using the page directory and page tables.

1. **Break down the Virtual Address**:
   A 32-bit virtual address is divided as follows:

   - **Bits 31–22**: The **Page Directory Index** (10 bits).
   - **Bits 21–12**: The **Page Table Index** (10 bits).
   - **Bits 11–0**: The **Page Offset** (12 bits).

2. **Access the Page Directory**:

   - The **Page Directory Index** is used to look up the appropriate **Page Directory Entry (PDE)** in the page directory.
   - The PDE will give the physical address of a **Page Table**.

3. **Access the Page Table**:

   - The **Page Table Index** is used to find the corresponding **Page Table Entry (PTE)** within the page table.
   - The PTE will give the physical address of a **Page Frame**.

4. **Final Physical Address**:
   - The **Page Frame Address** from the PTE is combined with the **Page Offset** from the original virtual address to obtain the **final physical address**.

#### **Example:**

- Let's assume a 32-bit virtual address `0x00403010`.
  - The **Page Directory Index** is derived from the top 10 bits: `0x00403` → `Page Directory Index` is `0x004`.
  - The **Page Table Index** is derived from the next 10 bits: `0x10`.
  - The **Page Offset** is the remaining 12 bits: `0x010`.

Using the **Page Directory Index**, the operating system will find the correct entry in the page directory, which points to a page table. The **Page Table Index** will then be used to find the corresponding entry in the page table, which will give the physical address of the page frame.

### 4. **Page Directory in 64-bit Systems**

In 64-bit systems (x86-64), the page directory works similarly, but the architecture uses a more complex paging structure, often called [**four-level paging**](./multi-level_paging_system.md). The virtual address is divided into multiple segments to accommodate the increased address space (64-bit). This allows the virtual address space to be much larger.

### 5. **Page Directory in Context Switching**

When the operating system switches between processes (context switch), the **Page Directory** of the currently running process must be loaded into the CPU's memory management unit (MMU). This ensures that the correct mapping for virtual memory is used for the new process.

### 6. **Usage in Kernel vs. User Space**

- The **kernel** has a dedicated page directory, usually known as the **kernel page directory**. The kernel space addresses are mapped separately from user space addresses.
- Each **user-space process** gets its own page directory, ensuring that one process cannot access the memory of another process.

### Summary

- The **Page Directory** is an essential structure in the virtual memory management system, holding pointers to **Page Tables**, which ultimately map virtual addresses to physical memory.
- It enables efficient memory management by allowing processes to access large virtual memory spaces, while keeping the memory protected and isolated between processes.
- The page directory, combined with page tables, provides the mechanism for address translation, caching control, and memory protection in modern operating systems.

![page-dir](https://ars.els-cdn.com/content/image/3-s2.0-B9780128112779000031-f03-07-9780128112779.jpg)
