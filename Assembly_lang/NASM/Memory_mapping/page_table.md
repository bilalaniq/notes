# Page Table and Mapping

The page table is a data structure used by a virtual memory in a computer OS to store the mapping between virtual addresses and physical addresses

It maps the page number to its frame number where that particular page is stored. CPU generates the logical address of the page, but the main memory recognizes the Physical address. Then, the Page Table maps the logical address to the Physical address

## Main characteristics of page Table

- When a process is loaded to execute, then its page table is also loaded in the main memory. The page table contains the information about every entry of the page, which is loaded into the frame of main memory.
- The size of the page table varies from process to process. Having more entries in the page table will increase the size and vice versa.
- The page size of the process is always equal to the frame size of the main memory. If the page size is 2Bytes, the frame size is also 2Bytes because pages are loaded into frames of main memory.
- Each process has its unique independent table

The greater the number of entries in the page table of a process, the higher the size of the page table. If the page table size is greater than the frame size of the main memory, then Multi-level paging comes into the picture.

The size of a page depends on the processor mode (protected, compatibility or long mode)

if you want to learn about modes click [here](./mode.md)

![page table](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/Page-table-in-operating-system.jpg?ezimgfmt=rs:730x345/rscb1/ng:webp/ngcb1)

---

<br>
<br>

## Logical to Physical Address mapping through Page Table

There are four main steps for mapping the logical to physical address through the page table.

1. Generation of logical address

CPU creates a logical address for each page of the process. This created address holds two things:

- page number: it tells the required page of process

- offset: it tells the specific byte from that page

2. Scaling

CPU uses the page table base register to store the base address of the page table. The value of the page table base register is added to the page number so that the actual location of that page in the page table can be obtained.

3. Generation of Physical Address

When the required page is found in the page table, then its corresponding value, which is the frame number, is easily obtained. It is the physical address because it is the address of the main memory where the actual data is present.

The physical address also has two parts

- The frame number is the address of the main memory where the CPU request page is present.

- Offset: The offset of the logical address is similar to the offset of the physical address. So, it will copy from the logical address to the physical address.

4. Getting Actual Frame Number

The frame number and offset of the physical address are mapped to the main memory so that the actual byte or word address can be accessed.

## Let’s explain Page Table and Mapping with an example.

Let processes P1 and P2 have the size 10Bytes and 8Bytes, respectively, and exist in secondary memory. There are 5 pages of process 1 and 4 pages of process 2, but each page is 2 bytes in size. Suppose 4 pages of process 1 and 4 pages of process 2 exist in the main memory. But the page table contains the whole record of its pages whether they are loaded in main memory or not. Suppose the CPU request for the 2nd byte of the 5th page of process 1 exists in the main memory. Then the explanation with diagram is.

![example](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/Mapping-through-page-table-in-operating-system.jpg?ezimgfmt=rs:730x437/rscb1/ng:webp/ngcb1)

---

# Page Table Entries

Page table has page table entries, and each page table entry contains

- frame number
- optional status like present/Absent bit
- Protection
- Reference
- Caching
- Dirty bit.

![tabel entries](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/Page-Table-Entries.jpg?ezimgfmt=rs:596x206/rscb1/ng:webp/ngcb1)

1. Frame Number:
   It gives the frame number of the main memory for the required page.

2. Present/absent bit:
   The present or absent bit tells about the presence or absence of a particular page you are looking for in the main memory. If the required page is found, it is a case of Page Hit, denoted by 1. When a required page is not found, it results in a page fault, which is indicated by 0. Page fault is controlled by OS, using the virtual memory concept.

3. Protection bit:
   The protection bit tells about the protection that you want to apply on that page. There are three permissions available on any page: read, write, and execute.

4. Referenced Bit:
   The referenced bit tells whether this page has been accessed in the last clock cycle or not. If it is accessed earlier, then the reference bit is set to 1. If this page referred first time then reference bit set to 0. It is used in memory access algorithms like LRU, etc.

5. Caching Enabled/Disabled:
   The cache is a memory that is faster and closer to the CPU. The least Recently used information is stored in the Cache. The cache can be enabled or disabled for pages.
   Sometimes, we need the fresh data (Dynamic). If we use an account and our balance dynamically changes with time, then in such cases, keep the cache disabled.
   Sometimes, we need the Static data as a video, which we use again and again. Then, for this type of task, a cache can be enabled.

6. Modified bit:
   It is also called a dirty bit. It tells whether the page has been modified or not. If the value of modified bit is 1 then it means the value of this page is updated in RAM by CPU with the permission of Process Write. If dirty value=1, then OS will update the value of this page on the hard disk. If dirty value=0, then it means no change is performed in RAM by the CPU.

---

# Page Fault

If the CPU requests a particular page and that page is not found in the main memory, then it will be a page fault situation. Then, the OS loads that page from the hard disk to the main memory. When loading that particular page from Secondary memory to the main memory, the CPU sits idle. The operating system is responsible for loading a page from secondary memory to main memory. Due to CPU idleness, System performance decreases.

## Page Fault example

Suppose a CPU generates a logical address 0111. The first three bits represent the page number, and the last represents the offset. Remember that 011 denotes the 3rd page, and 1 represents the second byte of that page.

The page table has no corresponding frame if the requested page is not in the main memory. It is the page fault situation. As shown in the diagram given below.

![page failt 1](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/example-of-page-fault-in-operating-system-STEP-1.jpg?ezimgfmt=rs:730x448/rscb1/ng:webp/ngcb1)

---

Now, a trap is generated, which requests the OS to load that page from secondary memory to main memory, as shown in the diagram below.

![page failt 2](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/example-of-page-fault-in-operating-system-STEP-2.jpg?ezimgfmt=rs:730x448/rscb1/ng:webp/ngcb1)

---

As the requested page is loaded in the frame of the main memory, the Page table is updated, which assigns the frame number from the main memory. Look at the following diagram

![page failt 3](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/example-of-page-fault-in-operating-system-STEP-3.jpg?ezimgfmt=rs:730x448/rscb1/ng:webp/ngcb1)

---

The physical address is now generated, as shown in the diagram below.

![page failt 4](https://sf.ezoiccdn.com/ezoimgfmt/cstaleem.com/wp-content/uploads/2020/05/example-of-page-fault-in-operating-system-STEP-4.jpg?ezimgfmt=rs:730x448/rscb1/ng:webp/ngcb1)

---

Note: If the number of page faults increases, then the effective access time of the system will also increase.
Effective Access Time (EAT) is the average time it takes for a system to retrieve data from memory, considering both hits (when the data is already in RAM) and misses (when the data is not in RAM and a page fault occurs, requiring loading from disk).

---

if you want to learn about `memory mapping register` click [here](./memory_mapping_register.md)
