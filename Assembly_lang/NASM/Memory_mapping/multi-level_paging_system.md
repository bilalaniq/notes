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

so we will be discussing only the paging systems currentlly being used
