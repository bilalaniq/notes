# multi-level paging system

Multilevel paging is a memory management technique used in modern computer systems to efficiently handle large amounts of memory. It breaks down the virtual address space into smaller, more manageable pieces, organized into multiple levels of page tables.

Multilevel Paging consists of two or more levels of page tables in a `hierarchical manner`. It is also known as hierarchical paging. The entries of the level 1 page table are pointers to a level 2 page table and entries of the level 2 page tables are pointers to a level 3 page table and so on. The entries of the last level page table store actual frame information. Level 1 contains a single-page table and the address of that table is stored in `PTBR` (Page Table Base Register)

Multilevel paging in operating systems is a memory management technique which is used to manage large amounts of memory more efficiently. It breaks down the page table into smaller parts, which reduces the memory needed to store the page table. This approach is scalable, meaning it can handle larger memory sizes without becoming impractical.

## Why Multi-Level Paging is Required?

Consider a 32-bit physical address space with page size = 4KB and let there be 2^20 = 1M, the total entries in the page table, page table entry size = 2^32 /2^12 = 2^20, and adding some protection bits and a dirty bit in the page table entry. Now page table size =2^20 \* 24 = 3MB

which should be in the physical memory and since each process has its own page table there is so much memory wastage only for storing page tables.

One solution to the large memory requirements of the page tables is to use multilevel paging, only the outermost page table will reside in the main memory and other page tables will be brought to the main memory as per the requirement because, at a particular time, we do not need complete page table, also we can save much memory space because outermost page table can fit in exactly one frame.

![paging-levels](https://media.geeksforgeeks.org/wp-content/uploads/20190608174849/virtual2.png)

---

In multilevel paging whatever may be levels of paging, all the page tables will be stored in the main memory. So it requires more than one memory access to get the physical address of the page frame. One access for each level is needed. Each page table entry except the last level page table entry contains the base address of the next level page table.

![paging-levels](https://media.geeksforgeeks.org/wp-content/uploads/20190608174704/multilevel.png)

---

## Reference to actual page frame:

- Reference to PTE in level 1 Page Table = PTBR Value + Level 1 Offset present in the Virtual Address.
- Reference to PTE in level 2 Page Table = Base address (present in Level 1 PTE) + Level 2 offset (present in VA).
- Reference to PTE in level 3 Page Table= Base address (present in Level 2 PTE) + Level 3 offset (present in VA).
- Actual page frame address = PTE (present in level 3).

Generally, the page table size will be equal to the size of the page.
If page table size > desired size then create 1 more level.

## Advantages of Multilevel Paging in Operating Systems

- Reduced memory overhead: Multilevel paging can help to reduce the memory overhead associated with the page table. This is because each level contains fewer entries, which means that less memory is required to store the page table.
- Faster page table lookup: With a smaller number of entries per level, it takes less time to perform a page table lookup. This can lead to faster system performance overall.
- Flexibility: Multilevel paging provides greater flexibility in terms of how the memory space is organized. This can be especially useful in systems with varying memory requirements, as it allows the page table to be adjusted to accommodate changing needs.

## Disadvantages of Multilevel Paging in Operating Systems

- Increased complexity: Multilevel paging adds complexity to the memory management system, which can make it more difficult to design, implement, and debug.
- Increased overhead: Although multilevel paging can reduce the memory overhead associated with the page table, it can also increase the overhead associated with page table lookups. This is because each level must be traversed to find the desired page table entry.
- Fragmentation: Multilevel paging can lead to fragmentation of the memory space, which can reduce overall system performance. This is because the page table entries may not be contiguous, which can result in additional overhead when accessing memory.

---

# paging systems

Here is a list of different paging systems:

1. **3-Level Paging** (used in 32-bit systems)
2. **4-Level Paging** (used in x86-64 architecture)
3. **5-Level Paging** (extended for larger address spaces in x86-64)
4. **1-Level Paging** (Flat Paging)
5. **Segmented Paging** (used in older x86 systems like Real Mode and Protected Mode)
6. **Inverted Page Tables (IPT)**
7. **Hybrid Paging Systems** (mix of paging and other memory management techniques)
8. **Memory Management Unit (MMU) Optimizations** (such as Translation Lookaside Buffers (TLBs) and large pages)
9. **Superpages / Large Pages** (2 MB, 1 GB pages for optimizing paging)

The systems, like 3-Level Paging, 1-Level Paging, Segmented Paging, Inverted Page Tables, and Hybrid Paging, are either legacy or used in specific cases but are not widely used in modern x86-64 systems today.

so we will be discussing only the `4-Level-paging-system` because it is the mostlly used in x86-64 bit systems

- ## **4-Level Paging** (used in x86-64 architecture)

  In x86-64 architecture, **4-level paging** is a method of virtual memory management that uses four levels of page tables to translate virtual addresses into physical addresses. This is a more complex address translation mechanism compared to 32-bit systems, which often only used two or three levels of paging. In the 64-bit architecture (x86-64), paging uses four levels to allow for large address spaces, providing support for 64-bit virtual addresses, which can theoretically address up to 18.4 million TB of memory.

### Overview of 4-Level Paging

When a program accesses a memory location, the virtual address it uses must be translated to a physical address in RAM. This translation process is handled by the paging mechanism, which splits the virtual address into different parts. The address translation happens through multiple levels of page tables that map virtual addresses to physical addresses.

In 4-level paging, the virtual address is broken down into five distinct parts:

- **PML4 (Page Map Level 4) Index**
- **PDPT (Page Directory Pointer Table) Index**
- **PDT (Page Directory Table) Index**
- **PT (Page Table) Index**
- **Offset within the page**

Each of these components maps to a specific level in the page table hierarchy. Here's how the translation process works:

### 1. Virtual Address Breakdown

The x86-64 architecture divides a 64-bit virtual address into 5 fields:

- **PML4 (Page Map Level 4) index**: 9 bits
- **PDPT (Page Directory Pointer Table) index**: 9 bits
- **PDT (Page Directory Table) index**: 9 bits
- **PT (Page Table) index**: 9 bits
- **Offset**: 12 bits (since the page size is typically 4 KB)

This gives a 48-bit virtual address space (since the upper 16 bits are reserved for higher memory management functions and aren't used directly for addressing). The breakdown looks like this:

```
|  PML4  | PDPT | PDT | PT  | Offset |
|  9 bits | 9 bits | 9 bits | 9 bits | 12 bits |
```

### 2. Translation Process (4-Level Paging)

The translation of a 48-bit virtual address to a physical address using 4-level paging proceeds as follows:

1. **PML4 Index**:

   - The 9 most significant bits of the virtual address are used to index into the **Page Map Level 4 (PML4) table**.
   - The PML4 contains pointers to the **Page Directory Pointer Tables (PDPTs)**.
   - If the entry for the PML4 index is valid, it points to the corresponding PDPT.

2. **PDPT Index**:

   - The next 9 bits are used to index into the **Page Directory Pointer Table (PDPT)**.
   - The PDPT contains pointers to the **Page Directory Tables (PDTs)**.
   - If the entry is valid, it points to the corresponding PDT.

3. **PDT Index**:

   - The following 9 bits are used to index into the **Page Directory Table (PDT)**.
   - The PDT contains pointers to the **Page Tables (PTs)**.
   - If the entry is valid, it points to the corresponding Page Table.

4. **PT Index**:

   - The next 9 bits are used to index into the **Page Table (PT)**.
   - The PT contains pointers to the **physical pages** (in the form of physical page numbers).
   - If the entry is valid, it provides a physical page number, and this, combined with the **offset**, gives the final physical address.

5. **Offset**:
   - The last 12 bits are the **offset** within the page (since each page is 4 KB, 2^12 = 4096 bytes). This determines the exact location within the page.

Page Directory Pointers (PDPs), which in turn point to Page Directories (PDs), and then these Page Directories finally point to the actual physical memory pages.

- PML4: Points to 512 entries (each pointing to a PDP).
- PDP: Each entry in the PDP can point to 512 Page Directories.
- Page Directory: Each PD entry can point to a page table or a large page (2 MB or 1 GB).
- In the case of a process that needs to map a large virtual address space, the system may have several Page Directories that manage different parts of that address space.

### 3. Example of Virtual Address Translation

Let’s break down the steps using an example. Suppose we have a virtual address `0x00007fffffffffff` (which is close to the upper limit of a 48-bit virtual address).

#### Step-by-step process:

- **PML4 Index**: Use the top 9 bits (from the 64-bit virtual address) to index into the PML4 table.
- **PDPT Index**: Use the next 9 bits to index into the corresponding PDPT entry.
- **PDT Index**: Use the next 9 bits to index into the PDT.
- **PT Index**: Use the next 9 bits to index into the PT.
- **Offset**: The remaining 12 bits give the byte offset within the 4 KB page.

Each entry in the Page Tables (PML4, PDPT, PDT, PT) contains a physical address pointing to the next level. Finally, after all translations, you reach the physical page, and the offset tells you the exact location in the physical memory.

### 4. Page Table Entries (PTE)

Each entry in the page tables (PML4, PDPT, PDT, and PT) holds a **physical address** of the next level’s table or the actual page (in the case of the PT). These entries are 8 bytes (64 bits) in size and contain various flags, such as:

- **Present**: Indicates that the page is in memory.
- **Writable**: Indicates that the page can be written to.
- **User/Supervisor**: Controls access rights, where "user" mode can access the page, or only "supervisor" (kernel) mode can access it.
- **Global**: If set, the entry is global, meaning it does not get flushed during a context switch.
- **Page size**: Indicates if the page size is large (such as 2 MB or 1 GB, instead of the default 4 KB).
- **Accessed**: Marks if the page has been accessed (read or written).
- **Dirty**: Marks if the page has been written to.

### 5. Advantages of 4-Level Paging

- **Large Address Space**: With 4-level paging, x86-64 systems can address up to 256 TB of physical memory, much more than 32-bit systems or even 32-bit with 2-level paging.
- **Efficient Memory Management**: The hierarchical structure helps to manage large amounts of memory efficiently. Not all pages need to be mapped, which allows systems to use physical memory efficiently.
- **Flexibility**: Allows support for both 4 KB pages and larger pages like 2 MB and 1 GB (huge pages) for better performance in certain scenarios.

### 6. Conclusion

4-level paging in x86-64 architecture is an essential feature that enables the translation of large virtual addresses into physical addresses. It supports efficient memory management by using multiple levels of page tables, enabling 64-bit systems to manage a vast address space while maintaining high efficiency in memory access and usage.

---

# Large pages

The normal size page is 4096 bytes. The CPU designers have added
support for large pages using three levels of the existing translation tables.
By using 3 levels of tables, there are 9 + 12 = 21 bits left for the within
page offset field. This makes large pages 221 = 2097152 bytes.

this can extend to 1 gb

### Large Pages in 64-bit Systems

In 64-bit systems, you can also use **large pages** (such as **2 MB** or **1 GB** pages), which reduce the number of page table levels required. Here’s how it works:

1. **2 MB Pages**:

   - If you're using a 2 MB page, you need **21 bits for the page offset** (because ( 2^21 = 2 text MB )).
   - To accommodate this, you use the **PML4**, **PDP**, and **PD** levels for mapping, skipping the **PT** level because large pages do not need the page table (PT) level for translation.
   - This results in a 2 MB page size.

2. **1 GB Pages**:
   - For **1 GB pages**, you would need **30 bits for the page offset** (because ( 2^30 = 1 text GB )).
   - The system can use only the **PML4** and **PDP** levels to map the virtual address, skipping both the **PD** and **PT** levels.
   - This results in a 1 GB page size.

---

if you want to learn about page directory click [here](./page_directory.md)
