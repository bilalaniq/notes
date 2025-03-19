# entry point & main in elf file

this sections is dedicated to finding the main and entry point in an elf inary file

the **entry point** and the **main function** are not the same thing, although they are closely related.

### 1. **Entry Point:**

- The **entry point** is the first instruction that the operating system or the loader will execute when the program is loaded into memory.
- It is defined in the ELF (or any executable) header and points to the address in memory where execution starts.
- The entry point could point to **startup code**, which is responsible for setting up the execution environment before calling the `main()` function. This code can initialize libraries, set up memory, and perform other low-level tasks.

`_start`: The first function that is called when the program is loaded. This is the entry point.

### 2. **Main Function:**

- The **main function** is the entry point for your **program logic**. It is the function where the user-defined code begins executing after the initial setup code.
- In C or C++, the **main function** is typically defined by the programmer. This function is called after the program's startup code has executed and the runtime environment is ready.
- The **main** function is usually located after the program's initialization routines, which are invoked when the entry point address is called.

### How They Are Related:

- When you run a program, the entry point address is where the execution begins. Typically, this is some startup code that prepares the environment and eventually calls the `main()` function. So, the entry point **does not directly point to `main()`**, but rather to the code that initializes and eventually calls `main()`.

---

so the milllion dollar question is that why you need to find the main function
the entry point can easyly be known using `readelf` command

the ans to this question is that when the binary is striped (meaning that there are no debug symbols present ) then you need to find the main function your self

---

<br>
<br>
<br>

Locating main() in a stripped Linux ELF binary is straightforward. No symbol information is required.
it is done using `__libc_start_main`

When the program starts, the execution first goes through the `_start` function, which is set by the operating system (OS) loader. It then calls `__libc_start_main` to initialize the runtime environment.

The `__libc_start_main` function shall initialize the process, call the main function with appropriate arguments, and handle the return from main.

The prototype for `__libc_start_main` is:

```c
int __libc_start_main(int (*main) (int, char**, char**),
                      int argc,
                      char *__unbounded *__unbounded ubp_av,
                      void (*init) (void),
                      void (*fini) (void),
                      void (*rtld_fini) (void),
                      void (*__unbounded stack_end));
```

The memory address of main() is passed as the first argument to `__libc_start_main`.

The address of main is placed on the stack just like any other function argument. So, the memory address of main() is passed in the stack as part of the `__libc_start_main call`

The address of main() gets passed onto the stack when `__libc_start_main` is called so that it can eventually jump to main() and start the execution of the program.

arguments are pushed onto the runtime stack in the `reverse order` of their corresponding parameters in the function definition.

Reverse Order? what does that mean

Now, "reverse order" refers to how the arguments are placed onto the stack. Specifically:

- The last argument of the function gets pushed onto the stack first.
- The first argument gets pushed onto the stack last.

---

<br>
<br>

One can enter main() in gdb in 4 steps:

- Find the program entry point
- Find where `__libc_start_main` is called
- Set a break point to the address last saved on stack prior to the call to `__libc_start_main`
- Let program execution continue until the break point for main() is hit

---

The process is the same for both 32-bit and 64-bit ELF binaries.

Entering main() in an example stripped 32-bit ELF binary called "test_32":

```bash
$ gdb -q -nh test_32
Reading symbols from test_32...(no debugging symbols found)...done.
(gdb) info file                                  #step 1
Symbols from "/home/c/test_32".
Local exec file:
    `/home/c/test_32', file type elf32-i386.
    Entry point: 0x8048310
    < output snipped >
(gdb) break *0x8048310
Breakpoint 1 at 0x8048310
(gdb) run
Starting program: /home/c/test_32

Breakpoint 1, 0x08048310 in ?? ()
(gdb) x/13i $eip                                 #step 2
=> 0x8048310:   xor    %ebp,%ebp
   0x8048312:   pop    %esi
   0x8048313:   mov    %esp,%ecx
   0x8048315:   and    $0xfffffff0,%esp
   0x8048318:   push   %eax
   0x8048319:   push   %esp
   0x804831a:   push   %edx
   0x804831b:   push   $0x80484a0
   0x8048320:   push   $0x8048440
   0x8048325:   push   %ecx
   0x8048326:   push   %esi
   0x8048327:   push   $0x804840b                # address of main()
   0x804832c:   call   0x80482f0 <__libc_start_main@plt>
(gdb) break *0x804840b                           # step 3
Breakpoint 2 at 0x804840b
(gdb) continue                                   # step 4
Continuing.

Breakpoint 2, 0x0804840b in ?? ()                # now in main()
(gdb) x/x $esp+4
0xffffd110: 0x00000001                           # argc = 1
(gdb) x/s **(char ***) ($esp+8)
0xffffd35c: "/home/c/test_32"                    # argv[0]
(gdb)

```

---

Entering main() in an example stripped 64-bit ELF binary called "test_64":

```bash
$ gdb -q -nh test_64
Reading symbols from test_64...(no debugging symbols found)...done.
(gdb) info file                                  # step 1
Symbols from "/home/c/test_64".
Local exec file:
    `/home/c/test_64', file type elf64-x86-64.
    Entry point: 0x400430
    < output snipped >
(gdb) break *0x400430
Breakpoint 1 at 0x400430
(gdb) run
Starting program: /home/c/test_64

Breakpoint 1, 0x0000000000400430 in ?? ()
(gdb) x/11i $rip                                 # step 2
=> 0x400430:    xor    %ebp,%ebp
   0x400432:    mov    %rdx,%r9
   0x400435:    pop    %rsi
   0x400436:    mov    %rsp,%rdx
   0x400439:    and    $0xfffffffffffffff0,%rsp
   0x40043d:    push   %rax
   0x40043e:    push   %rsp
   0x40043f:    mov    $0x4005c0,%r8
   0x400446:    mov    $0x400550,%rcx
   0x40044d:    mov    $0x400526,%rdi            # address of main()
   0x400454:    callq  0x400410 <__libc_start_main@plt>
(gdb) break *0x400526                            # step 3
Breakpoint 2 at 0x400526
(gdb) continue                                   # step 4
Continuing.

Breakpoint 2, 0x0000000000400526 in ?? ()        # now in main()
(gdb) print $rdi
$3 = 1                                           # argc = 1
(gdb) x/s **(char ***) ($rsp+16)
0x7fffffffe35c: "/home/c/test_64"                # argv[0]
(gdb)
```

but that was an over view if you want to learn in detail click [here](./findmain.md)




