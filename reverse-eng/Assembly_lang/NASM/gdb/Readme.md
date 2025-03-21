# Examining memory with gdb

In this section we will focus on using the gdb print (p) and examine (x)
commands. Print is a simple command which can print some data values
and is versatile enough to print various forms of C expressions. Examine
is strictly for printing data from memory and is quite useful for printing
arrays of various types.

# Printing with gdb

The format for the p command is either p expression or p/FMT expression
where FMT is a single letter defining the format of data to print. The format choices are

| Format | Description       |
| ------ | ----------------- |
| `d`    | Decimal (default) |
| `X`    | Hexadecimal       |
| `t`    | Binary            |
| `u`    | Unsigned          |
| `f`    | Floating point    |
| `1`    | Instruction       |
| `c`    | Character         |
| `s`    | String            |
| `a`    | Address           |

`note` : i have used gef(GDB Enhanced Features) so donot be confussed by it

```bash
(gdb) p a
$32 = 4
(gdb) p/a &a
$33 = Ox601018 <a>
(gdb) p b
$34 = 1082969293
(gdb) p/f b
$35 = 4 . 400000 1
(gdb) p/a &b
$36 = Ox60101c <b>
(gdb) p/x &b
$37 = Ox60101c
(gdb) p/a &c
$39 = Ox601020 <c>
(gdb) p/a &d
$40 = Ox601048 <d>
(gdb) p/a &e
$41 = Ox60104c <e>
(gdb) p/a &f
$42 = Ox60104d <f>

# .bss

(gdb) p/a &g
$43 = Ox601070 <g>
(gdb) p/a &h
$45 = Ox601074 <h>
(gdb) p/a &i
$46 = Ox60109c <i>
```

We see that gdb handles a perfectly. It gets the type right and the
length. It needs the If option to print b correctly. Notice that a is
located at address `Ox601018` which is `24` bytes after the start of a page
in memory. gdb will prohibit accessing memory before a, though there is
no hardware restriction to the previous 24 bytes. We see that the data
segment variables are placed in memory one after another until f which
starts at `Ox60104d` and extends to `Oc601058`. There is a gap until the bss
segment which starts with g at address Ox60 1070. The bss data items
are placed back to back in memory with no gaps.

- From a to f: These variables are in the data segment (initialized variables), placed sequentially in memory.
- From g to i: These variables are in the BSS segment (uninitialized variables), placed one after another without any gaps.

To understand why `0x601018` is **24 bytes after the start of a page**, let's break it down step by step:

1. **Memory Pages**:

   - Memory is often divided into chunks called **pages**. A typical page size is **4 KB** (4,096 bytes).
   - This means the starting address of each page is a multiple of 4,096 (like `0x0`, `0x1000`, `0x2000`, and so on).

2. **Finding the Page Boundary**:

   - The memory address `0x601018` is where a variable (`a`) is located.
   - To check how far this address is from the start of the page, we need to find the **page boundary** (the nearest multiple of 4,096 before `0x601018`).

3. **Calculate the Start of the Page**:

   - To find the start of the page that contains `0x601018`, we simply **clear the lower 12 bits** (since 4 KB = 4096 bytes, and `0x1000` is 4096 in hexadecimal).
   - `0x601018` in binary is `0110 0000 0001 0000 0001 1000`. The lower 12 bits are `001 000 0001 1000`, and when cleared, you get `0x601000`.

   Therefore, the **start of the page** for `0x601018` is `0x601000`.

4. **Calculate the Offset**:
   - Now, to find how far `0x601018` is from `0x601000`, subtract:
     ```
     0x601018 - 0x601000 = 0x18 (24 bytes)
     ```
   - So, `0x601018` is **24 bytes** after `0x601000`, the start of the page.

The address `0x601018` is **24 bytes** after the start of a page (`0x601000`), meaning it's 24 bytes into the page that starts at `0x601000`.

# Examining memory

Notice that there are no length specifiers with p. If you want to print
doubles in memory it could be done with some mental gymnastics with
p. The examine command handles this job readily.

The format for examine is `x/NFS address`

- N is the number of items to print (default is 1 if not specified).
- F is a single letter format specifier that tells GDB how to display the data (e.g., hexadecimal, decimal, character, etc.).
- S is the size of each memory location you want to examine (e.g., byte, word, etc.).
- address is the memory address you want to examine.

GDB uses certain letters for size

| Size Type    | Memory Representation |
| ------------ | --------------------- |
| b (byte)     | 1 byte                |
| h (halfword) | 2 bytes               |
| w (word)     | 4 bytes               |
| g (giant)    | 8 bytes               |

Unfortunately gdb picked some size letters which conflict with some of the size options in
yasm/Nasm for example

in nasm the `WORD` is 2 bytes where in gdb it is 4 bytes

Here are the examples based on the `x/NFS address` command format in GDB:

### Example 1: Examine 2 bytes in hexadecimal

```bash
x/2xb 0x601000
```

- **2**: Number of items (2 bytes).
- **x**: Format (hexadecimal).
- **b**: Size (byte, 1 byte per item).
- **0x601000**: Memory address.

### Example 2: Examine 3 words in decimal

```bash
x/3wd 0x601000
```

- **3**: Number of items (3 words).
- **w**: Size (word, 4 bytes per item).
- **d**: Format (decimal).
- **0x601000**: Memory address.

### Example 3: Examine 4 halfwords in hexadecimal

```bash
x/4xh 0x601000
```

- **4**: Number of items (4 halfwords).
- **x**: Format (hexadecimal).
- **h**: Size (halfword, 2 bytes per item).
- **0x601000**: Memory address.

### Example 4: Examine 2 giant values in hexadecimal

```bash
x/2xg 0x601000
```

- **2**: Number of items (2 giants).
- **x**: Format (hexadecimal).
- **g**: Size (giant, 8 bytes per item).
- **0x601000**: Memory address.

### Example 5: Examine 5 bytes in decimal

```bash
x/5bd 0x601000
```

- **5**: Number of items (5 bytes).
- **b**: Size (byte, 1 byte per item).
- **d**: Format (decimal).
- **0x601000**: Memory address.

# Exercises

- #### 1. Write a data-only program like the one in this chapter to define anarray of 10 8 byte integers in the data section, an array of 5 2 byteintegers in the bss section, and a string terminated by 0 in the datasection. Use gdb's examine command to print the 8 byte integers inhexadecimal, the 2 byte integers as unsigned values, and the stringas a string.

  ```nasm
  section .data
      ; Array of 10 8-byte integers
      long_integers dq 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

      ; String terminated by 0
      my_string db 'Hello, world!', 0

  section .bss
      ; Array of 5 2-byte unsigned integers
      short_integers resw 5 ; resw reserves 5 words (2 bytes each)

  section .text
      global _start

  _start:
      ; Exit the program (for GDB to inspect)
      mov eax, 60         ; syscall number for exit
      xor edi, edi        ; exit code 0
      syscall

  ```

  ```bash
  gef➤  x/10xg &long_integers
  0x402000 <long_integers>:       0x0000000000000001      0x0000000000000002
  0x402010:       0x0000000000000003      0x0000000000000004
  0x402020:       0x0000000000000005      0x0000000000000006
  0x402030:       0x0000000000000007      0x0000000000000008
  0x402040:       0x0000000000000009      0x000000000000000a
  ```

  here you can see all the 10 8 bytes array

  ```bash
  gef➤  x/10uh &short_integers
  0x402060 <short_integers>:      0       0       0       0       0       0       0       0
  0x402070:       0       0
  ```

  as you can see all the values are 0 because all the values in .bss section are initilized to 0
  and two zero are equal to one no

  ```bash
  gef➤  x/sb &my_string
  0x402050 <my_string>:   "Hello, world!"
  ```

---

<br>
<br>

- #### 2. Print the value of rsp in gdb. How many bits are required to store this value?

  **Print the Value of `rsp`**:
  To print the value of `rsp` (stack pointer), use the following GDB command:

  ```bash
  (gdb) info registers rsp
  ```

  This will display the current value of the `rsp` register, which points to the top of the stack.

  Example output:

  ```
  gef➤  info registers rsp
  rsp            0x7fffffffdb40      0x7fffffffdb40
  ```

### How Many Bits Are Required to Store the Value of `rsp`?

The size of `rsp` depends on the architecture of the system you're working on. Here's how you can determine how many bits are required:

- **For 64-bit systems (x86_64 architecture)**, `rsp` is a 64-bit value, and it typically holds an address within a 64-bit address space. Therefore, it will require **64 bits** to store.
- **For 32-bit systems (x86 architecture)**, `rsp` would be a 32-bit value, and it would require **32 bits** to store.

### How to Determine the Number of Bits:

You can check whether you're running on a 32-bit or 64-bit system by using the following command in GDB:

```bash
(gdb) show architecture
```

This will tell you if you are using a 32-bit or 64-bit architecture.

### Conclusion:

- **On a 64-bit system**, `rsp` is typically 64 bits (8 bytes) long.
- **On a 32-bit system**, `rsp` is 32 bits (4 bytes) long.

So, if you are working on a 64-bit system, `rsp` will be **64 bits**. On a 32-bit system, it will be **32 bits**.

---

<br>
<br>
<br>
<br>

---

# deguging c

lets debug an c program

```c
int f(int i)
{
    int a=3;
    i=4+i+a;
    return i;
}

int
main()
{
    return f(2);
}
```

compile it using

```bash
gcc -ggdb -o test test.c
```

I tell gdb, `set disassemble-next-line` on which makes it print the next line of assembler that will be executed the same way you're used to it printing out the next line of C that will be executed. Since several lines of assembler correspond to one line of C, everytime a line of C is printed, you'll see several lines of assembler like this

but note that this does not work in gef (GDB Enhanced Features)
so dissable it for now using this command

```bash
gdb -n
```

```bash

0x080483a4	5	    i=4+i+a;
=> 0x080483a1 <f+13>:	 8b 45 08	mov    0x8(%ebp),%eax
   0x080483a4 <f+16>:	 83 c0 04	add    $0x4,%eax
   0x080483a7 <f+19>:	 03 45 fc	add    -0x4(%ebp),%eax
   0x080483aa <f+22>:	 89 45 08	mov    %eax,0x8(%ebp)

```

This tells you that line 5 from the C source compiled to four lines of assembler.

I step through the assembler with si (step instruction), and you'll see that gdb will tell you which line of the assembler will be executed next by marking it on the left with =>. Each time you tell gdb to step to the next instruction, the => will move down one, but the line of C won't change until you si off the bottom of the assembler lines that correspond to the line of C.

When you start doing mixed assembler and C/C++ debugging there will be times you, by habit, type n (next) or s (step) and go to the next line of C when you meant to type ni (next instruction) or si (step instruction). It will be frustrating. At the worst you will have just done a lot of work to set up to see the smoking gun on a rare, hard to trace, bug and then you'll have to start over. Be careful. I'll do several step immediate before the C line will change. I'll only type si for the first one, I'll just press enter to take advantage of the way gdb will repeat the last instruction everytime you press `enter`.

lets debug :)

```bash
(gdb) r

Breakpoint 1, main () at test.cpp:13
13          return f(2);
=> 0x565561b4 <main()+13>:      6a 02                   push   $0x2
   0x565561b6 <main()+15>:      e8 c2 ff ff ff          call   0x5655617d <_Z1fi>
   0x565561bb <main()+20>:      83 c4 04                add    $0x4,%esp

```

```bash
(gdb) si
0x565561b6      13          return f(2);
   0x565561b4 <main()+13>:      6a 02                   push   $0x2
=> 0x565561b6 <main()+15>:      e8 c2 ff ff ff          call   0x5655617d <_Z1fi>
   0x565561bb <main()+20>:      83 c4 04                add    $0x4,%esp
```

now the function at 0x5655617d will be called

```bash
(gdb)
f (i=2) at test.cpp:4
4       {
=> 0x5655617d <_Z1fi+0>:        55                      push   %ebp
   0x5655617e <_Z1fi+1>:        89 e5                   mov    %esp,%ebp
   0x56556180 <_Z1fi+3>:        83 ec 10                sub    $0x10,%esp
   0x56556183 <_Z1fi+6>:        e8 39 00 00 00          call   0x565561c1 <__x86.get_pc_thunk.ax>
   0x56556188 <_Z1fi+11>:       05 6c 2e 00 00          add    $0x2e6c,%eax

```

if you want to know about the `thunk` what is this and its related context click [here](../../../Thunk/Readme.md)

but in short `__x86.get_pc_thunk.ax` is an example of a thunk function used in x86 assembly, particularly in Position-Independent Code (PIC) for dynamically linked executables (shared libraries).

if you also want to learn about pic and pie click [here](../../../pie&pic/Readme.md)

```c
(gdb)
0x565561c0 in __x86.get_pc_thunk.ax ()
=> 0x565561c0 <__x86.get_pc_thunk.ax+0>:        8b 04 24                mov    (%esp),%eax
```

```c
(gdb)
5           int a=3;
=> 0x5655618d <f+16>:   c7 45 fc 03 00 00 00    movl   $0x3,-0x4(%ebp)
```

```c
(gdb)
6           i=4+i+a;
=> 0x56556194 <f+23>:   8b 45 08                mov    0x8(%ebp),%eax
   0x56556197 <f+26>:   8d 50 04                lea    0x4(%eax),%edx
```

```c
(gdb)
0x56556197      6           i=4+i+a;
   0x56556194 <f+23>:   8b 45 08                mov    0x8(%ebp),%eax
=> 0x56556197 <f+26>:   8d 50 04                lea    0x4(%eax),%edx
```

```c
(gdb)
7           return i;
=> 0x565561a2 <f+37>:   8b 45 08                mov    0x8(%ebp),%eax
```

```c
8       }
=> 0x565561a5 <f+40>:   c9                      leave
   0x565561a6 <f+41>:   c3                      ret
```

```c
(gdb)
0x565561bb in main () at test.c:13
13          return f(2);
   0x565561b4 <main+13>:        6a 02                   push   $0x2
   0x565561b6 <main+15>:        e8 c2 ff ff ff          call   0x5655617d <f>
=> 0x565561bb <main+20>:        83 c4 04                add    $0x4,%esp
```

```c
(gdb)
14      }
=> 0x565561be <main+23>:        c9                      leave
   0x565561bf <main+24>:        c3                      ret

```

end of main

We backed out of main and into the function that called main, `__libc_start_main`.
if you want to learn about the how main is called click [here](../../../elf/entrypoint/Readme.md) to learn

So I just type c (continue) and let the program exit, since we don't have any need to debug functions in libc.

---

<br>
<br>
<br>
<br>

# What does array access look like in assembler?

We'll write a simple C program to access elements of an array of ints so that you'll see what sort of assembler code corresponds to your C. We save the program as array1.c and then

```bash
gcc -ggdb -o array1 array1.c
```

```c
int array1[]={ 0,1,2,3,4,5 };

int
main()
{
    int index, i=array1[1];
    array1[4]=40;
    index=3;
    array1[index]=array1[index+1];
}
```

We'll load it up in gdb and see what it looks like.


