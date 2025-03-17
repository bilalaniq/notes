# Kernel Data Structures

we have already studies Kernel Data Structures in out dsa notes section [click](../../../dsa/algorithms) here to learn about all the Data Structures

---

<br>
<br>

`note`: The data structures used in the Linux kernel are available in the kernel source
code. The include file `<linux/list.h>` provides details of the linked-list
data structure used throughout the kernel. A queue in Linux is known as a
`kfifo`, and its implementation can be found in the `kfifo.c` file in the kernel
directory of the source code. Linux also provides a balanced binary search tree
implementation using `red-black trees`. Details can be found in the include file
`<linux/rbtree.h>`

these are part of Linux kernel headers, not the standard C library. so you canot use them in your own code.
