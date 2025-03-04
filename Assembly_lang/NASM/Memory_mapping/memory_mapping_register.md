# Memory Mapping Register (64 bit mode)

we discuss the details of how virtual addresses are translated to physical addresses in the x86-64 architecture. Some of the data for translation is stored in the CPU and some of it is stored in memory

---

Well the CPU designers named this register `Control Register 3` or just `CR3`. A simplified view of CR3 is that it is a pointer to the top level of a hierarchical collection of tables in memory which define the translation from virtual addresses (the addresses your program sees) to physical addresses. The CPU retains quite a few page translations internally,

but let's consider first how the CPU starts all this translation process.
Somewhere in the kernel of the operating system, an initial hierarchy
of the translation tables is prepared and CR3 is filled with the address
of the top level table in the hierarchy. This table is given the illustrious
name `Page Map Level 4` or `PML4`. When the CPU is switched to using
memory mapping on the next memory reference it starts by using CR3
to fetch the address of PML4. Surely it must retain PML4's address for
future use.


if you want to learn about multi-level paging system click [here](./multi-level_paging_system.md)
