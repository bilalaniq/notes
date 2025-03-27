# Linux x86 Program Start Up or - How the heck do we get to main()?

This is for people who want to understand how programs get loaded under linux. In particular it talks about dynamically loaded x86 ELF files. The information you learn will let you understand how to debug problems that occur in your program before main starts up

![main png](https://doremin.github.io/assets/images/2021-02-06/2021-02-06-1.png)

---

<br>
<br>

## How did we get to main?

We're going to build the simplest C program possible, an empty main, and then we're going to look at the disassembly of it to see how we get to main. We'll see that the first thing that's run is a function linked to every program named `_start` which eventually leads to your program's main being run.

```c
int
main()
{
}
```

```bash
gcc -ggdb -o prog1 prog1.c
```

to get the dissassembly use this command

```bash
objdump -d prog1 >prog1.dump
```

## But first, how do we get to `_start`?

When you run a program, whether from a shell or a graphical user interface (GUI), the system essentially uses the `execve()` system call to load and execute the program.

The shell or GUI is responsible for invoking this system call. The execve() function replaces the current running process (the shell or GUI itself) with the new program you want to execute

If you want to learn more about how the execve() system call works, you can type man execve in your terminal. This will bring up the manual page for execve(), which provides detailed information about its usage, parameters, and behavior.

When execve() is called to execute a new program, it prepares a stack for the new program to run. The stack is used to store important data such as `command-line arguments` and `environment variables`.

The stack contains:

- argc: This is the number of command-line arguments passed to the program.
- argv: This is an array of strings containing the actual command-line arguments.
- envp: This is an array of strings containing the environment variables passed to the program (such as PATH, HOME, etc.).

## File Descriptors

In Unix-like operating systems, there are three standard file descriptors for every running process:

- 0: Standard input (stdin)
- 1: Standard output (stdout)
- 2: Standard error (stderr)

When execve() is invoked, it doesn’t modify these file descriptors. It assumes that these file descriptors have already been set up by the calling process (such as the shell). This means that if you're executing a command in the shell, the input and output of your program will behave as expected (e.g., input comes from the terminal, output goes to the terminal, and errors go to the terminal unless redirected)

so The file descriptions 0, 1, and 2, (stdin, stdout, stderr), are left to whatever the shell set them to.

After execve() has set up the stack and prepared the necessary environment, the loader takes over. The loader is responsible for loading the program into memory and performing relocations.

Relocations involve adjusting memory addresses in the program's code, so it can run correctly in the system's memory. For example, the program may use shared libraries, and the loader ensures that the program can find the correct addresses for these libraries when running.

The loader may also prepare other things, like setting up the initial state of the program, so it is ready to run.

When everything is ready, control is handed to your program by calling `_start()`

`_start` is, oddly enough, where we start

```bash
080482e0 <_start>:
80482e0:       31 ed                   xor    %ebp,%ebp
80482e2:       5e                      pop    %esi
80482e3:       89 e1                   mov    %esp,%ecx
80482e5:       83 e4 f0                and    $0xfffffff0,%esp
80482e8:       50                      push   %eax
80482e9:       54                      push   %esp
80482ea:       52                      push   %edx
80482eb:       68 00 84 04 08          push   $0x8048400
80482f0:       68 a0 83 04 08          push   $0x80483a0
80482f5:       51                      push   %ecx
80482f6:       56                      push   %esi
80482f7:       68 94 83 04 08          push   $0x8048394
80482fc:       e8 c3 ff ff ff          call   80482c4 <__libc_start_main@plt>
8048301:       f4                      hlt
```

xor of anything with itself sets it to zero. so the `xor %ebp,%ebp` sets %ebp to zero. This is suggested by the ABI (Application Binary Interface specification), to mark the outermost frame.

Next we pop off the top of the stack. On entry we have argc, argv and envp on the stack, so the pop makes argc go into %esi. We're just going to save it and push it back on the stack in a minute. Since we popped off `argc`, %esp is now pointing at `argv`. The mov puts argv into %ecx without moving the stack pointer.

Then we and the stack pointer with a mask that clears off the bottom four bits. `and    $0xfffffff0,%esp`
Depending on where the stack pointer was it will move it lower, by 0 to 15 bytes.

16-byte alignment refers to the practice of arranging data in memory such that the address of the data is a multiple of 16 bytes (0x10 in hexadecimal). This means that the memory address where the data starts should be divisible by 16.

This is an important operation, particularly in modern architectures and for ensuring the proper functioning of certain hardware and software features.

- Memory Alignment for Performance:

  Memory alignment is a key consideration for modern CPUs. Accessing memory that is properly aligned (to boundaries like 16 bytes) can be much faster than accessing unaligned memory. Misaligned memory access can cause performance penalties or even faults on certain architectures.

- SSE (Streaming SIMD Extensions) Requirements:

  Modern CPUs often use SIMD instructions like SSE to perform operations on multiple pieces of data at once (e.g., processing 4 single-precision floating-point numbers simultaneously). These instructions often require that the data being processed is aligned on 16-byte boundaries for correct operation. If the stack pointer (%esp) is not aligned, accessing the data could cause SSE exceptions or degrade performance

- ABI (Application Binary Interface) Convention:

  The ABI specification for many platforms (such as Linux x86-64) requires that the stack pointer be aligned to 16-byte boundaries when entering functions, particularly when calling certain library functions.

<br>

Suppose %esp initially points to some address, say 0x12345678.

Applying the and $0xfffffff0, %esp operation would modify %esp to align it to the nearest 16-byte boundary, which would be 0x12345670. The lower 4 bits are cleared, ensuring it is aligned to a multiple of 16.

This alignment is done so that all of the stack variables are likely to be nicely aligned for memory and cache efficiency, in particular, this is required for SSE (Streaming SIMD Extensions), instructions that can work on vectors of single precision floating point simultaneously.

---

<br>
<br>

## Now set up for calling `__libc_start_main`

So now we start pushing arguments for `__libc_start_main` onto the stack.

```bash
80482e8:       50                      push   %eax
80482e9:       54                      push   %esp
80482ea:       52                      push   %edx
80482eb:       68 00 84 04 08          push   $0x8048400
80482f0:       68 a0 83 04 08          push   $0x80483a0
80482f5:       51                      push   %ecx
80482f6:       56                      push   %esi
80482f7:       68 94 83 04 08          push   $0x8048394
```

The first one, %eax is garbage pushed onto the stack just because 7 things are going to be pushed on the stack and they needed an 8th one to keep the 16-byte alignment. It's never used for anything.

`__libc_start_main` is linked in from glibc. In the source tree for glibc, it lives in csu/libc-start.c. `__libc_start_main` is specified like

```c
int __libc_start_main(  int (*main) (int, char * *, char * *),
			    int argc, char * * ubp_av,
			    void (*init) (void),
			    void (*fini) (void),
			    void (*rtld_fini) (void),
			    void (* stack_end));
```

So we expect `_start` to push those arguments on the stack in reverse order before the call to `__libc_start_main`.

| **Register/Memory** | **Value**                          | **Description**                                                                                                                                                                                                                                                               |
| ------------------- | ---------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **$eax**            | Don't know.                        | Don't care. This value is not important in this context.                                                                                                                                                                                                                      |
| **%esp**            | `void (*stack_end)`                | Our aligned stack pointer, pointing to the top of the stack. special argument passed to `__libc_start_main`. It represents the end of the stack area, often used to mark the boundary of the stack or to track the end of the stack space used during program initialization. |
| **%edx**            | `void (*rtld_fini)(void)`          | Destructor of the dynamic linker passed in `%edx`. It is used to call the FINI for dynamic libraries.                                                                                                                                                                         |
| `0x8048400`         | `void (*fini)(void)`               | `__libc_csu_fini` - Destructor of this program, registered by `__libc_start_main`.                                                                                                                                                                                            |
| `0x80483a0`         | `void (*init)(void)`               | `__libc_csu_init` - Constructor of this program, called by `__libc_start_main` before `main`.                                                                                                                                                                                 |
| **%ecx**            | `char **ubp_av`                    | Points to the `argv` (argument vector) on the stack, which is the list of command-line arguments passed to the program.                                                                                                                                                       |
| **%esi**            | `argc`                             | The number of command-line arguments (count) passed to the program, popped from the stack.                                                                                                                                                                                    |
| `0x8048394`         | `int (*main)(int, char**, char**)` | The address of the `main` function, called by `__libc_start_main`. The return value of `main` is passed to `exit()` to terminate the program.                                                                                                                                 |

---

<br>

### 1. **`rtld_fini` (Runtime Linker Destructor)**:

- **Role**: This function is the **destructor of the dynamic linker** and is responsible for cleaning up the dynamic linker and any resources it used during the program’s execution. It is related to unloading shared libraries and performing necessary finalization steps for the dynamic linker itself.
- **Purpose**: It is registered by the `__libc_start_main` function (or other similar startup functions) and is part of the program’s dynamic loading process. The dynamic linker loads and links shared libraries during program startup, and `rtld_fini` handles cleanup when the program finishes, particularly in relation to the shared libraries.
- **Where it is used**: `rtld_fini` is involved in the process of finalizing the environment of dynamically loaded libraries and their destructors. It is passed via the `rtld_fini` argument in `__libc_start_main` and is executed before the program exits.

### 2. **`fini` (Program’s C-level Destructor)**:

- **Role**: This function, often **`__libc_csu_fini`**, is the **C-level destructor of the program**. It handles cleanup tasks specific to the program itself, especially for static variables and any finalization required for the program’s own resources.
- **Purpose**: `fini` is used for program-specific cleanup (like cleaning up static variables or performing any final actions before the program completely terminates). It is registered by `__libc_start_main` using the `__cxat_exit()` mechanism to ensure that destructors of dynamically linked libraries are called when the program exits.
- **Where it is used**: It is called after all dynamic linkers' destructors (`rtld_fini`) and is responsible for cleaning up program-specific resources (like calling destructors of global/static variables in the main program).

---

<br>
<br>

## envp

Did you notice that we didn't get envp, the pointer to our environment variables off the stack? It's not one of the arguments to `__libc_start_main`, either. But we know that main is called int main(int argc, char** argv, char** envp) so what's up?

When the program starts, `__libc_start_main` is called, and it first invokes `__libc_init_first`. This function uses internal knowledge to locate the environment variables (`envp`), which are placed right after the argument vector (`argv`) in memory. It finds them by looking just past the **null terminator** that marks the end of the argument list. Once it identifies the environment variables, it sets a global variable called `__environ` to point to them. This allows `__libc_start_main` and other parts of the program to access the environment variables later on. Additionally, just after the environment variables, there’s another section of memory called the **ELF auxiliary vector**, which contains additional information passed to the process by the loader. You can view this auxiliary vector by setting the environment variable `LD_SHOW_AUXV=1` before running the program.

```bash
The auxiliary vector is a special structure used in the Linux operating system to pass additional information from the dynamic linker/loader to a running program when it is started. It is primarily used to convey useful system-level information about the environment in which the program is running, such as memory layout, program entry point, and other critical runtime details
```

```bash
export LD_SHOW_AUXV=1
./cpp
```

output:

```bash
AT_SYSINFO_EHDR:      0x7ffd8b71b000
AT_MINSIGSTKSZ:       1776
AT_HWCAP:             1f8bfbff
AT_PAGESZ:            4096
AT_CLKTCK:            100
AT_PHDR:              0x55e508e89040
AT_PHENT:             56
AT_PHNUM:             13
AT_BASE:              0x7fcd3e788000
AT_FLAGS:             0x0
AT_ENTRY:             0x55e508e8a060
AT_UID:               1000
AT_EUID:              1000
AT_GID:               1000
AT_EGID:              1000
AT_SECURE:            0
AT_RANDOM:            0x7ffd8b6d2a19
AT_HWCAP2:            0x2
AT_EXECFN:            ./cpp
AT_PLATFORM:          x86_64
Hello World
```

| **Auxiliary Vector** | **Value**      | **Description**                                                            |
| -------------------- | -------------- | -------------------------------------------------------------------------- |
| **AT_SYSINFO_EHDR**  | 0x7ffd8b71b000 | Address of the system call interface header in memory.                     |
| **AT_MINSIGSTKSZ**   | 1776           | Minimum stack size required for signal handling.                           |
| **AT_HWCAP**         | 1f8bfbff       | Hardware capabilities of the CPU (bitmask indicating supported features).  |
| **AT_PAGESZ**        | 4096           | Memory page size (in bytes) used by the system (4 KB).                     |
| **AT_CLKTCK**        | 100            | Number of clock ticks per second on the system.                            |
| **AT_PHDR**          | 0x55e508e89040 | Address of the program header in memory.                                   |
| **AT_PHENT**         | 56             | Size (in bytes) of each entry in the program header table.                 |
| **AT_PHNUM**         | 13             | Number of entries in the program header table.                             |
| **AT_BASE**          | 0x7fcd3e788000 | Base address of the loaded program in memory.                              |
| **AT_FLAGS**         | 0x0            | Flags related to the program's execution environment.                      |
| **AT_ENTRY**         | 0x55e508e8a060 | Entry point address of the program.                                        |
| **AT_UID**           | 1000           | User ID of the program’s creator (real UID).                               |
| **AT_EUID**          | 1000           | Effective User ID of the program.                                          |
| **AT_GID**           | 1000           | Group ID of the program’s creator (real GID).                              |
| **AT_EGID**          | 1000           | Effective Group ID of the program.                                         |
| **AT_SECURE**        | 0              | Indicates whether the program is running in a secure environment (0 = no). |
| **AT_RANDOM**        | 0x7ffd8b6d2a19 | A pointer to a random number used for entropy (for security purposes).     |
| **AT_HWCAP2**        | 0x2            | Additional hardware capabilities.                                          |
| **AT_EXECFN**        | ./cpp          | Path to the executable file that was executed.                             |
| **AT_PLATFORM**      | x86_64         | The platform the program is running on (e.g., x86_64 architecture).        |

---

<br>
<br>

## **environment variables (envp)** `vs` **auxiliary vector (auxv)**:

| **Aspect**             | **Environment Variables (envp)**                                                                    | **Auxiliary Vector (auxv)**                                                                                              |
| ---------------------- | --------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------ |
| **Purpose**            | Holds user-defined settings or configuration values (e.g., `PATH`, `HOME`, `USER`).                 | Holds system-level information passed by the operating system to the program (e.g., system page size, CPU capabilities). |
| **Content**            | Key-value pairs (e.g., `PATH=/usr/bin`, `HOME=/home/user`).                                         | System-level values (e.g., `AT_PAGESZ`, `AT_ENTRY`, `AT_HWCAP`).                                                         |
| **Source**             | Set by the user or shell before running the program.                                                | Set by the operating system when the program starts.                                                                     |
| **Usage**              | Used by the program to configure its runtime environment (e.g., locating executables, directories). | Used by the program (via loader) to obtain system-level information like memory pages, hardware features.                |
| **Location in Memory** | Stored in a null-terminated array of strings passed to `main` or accessed via `environ`.            | Stored as a structured list of key-value pairs passed to the program by the loader.                                      |
| **Modification**       | Can be modified by the user or program during execution.                                            | Cannot be modified directly by the program.                                                                              |
| **Examples**           | `PATH`, `HOME`, `USER`, `LANG`, `SHELL`.                                                            | `AT_PAGESZ`, `AT_ENTRY`, `AT_HWCAP`, `AT_SYSINFO_EHDR`.                                                                  |

In summary:

- **envp** contains user-configurable environment variables that the program can use to interact with the system or control its behavior.
- **auxv** contains low-level system information that is passed by the OS to the program to provide it with details about the environment it's running in, such as system architecture and memory page size.

if that was not enough for you then see this [example](./envp.md) this will give you an idea of `envp`

note : to unset the `LD_SHOW_AUXV` use

```bash
unset LD_SHOW_AUXV
```

now your program will work as normal or you could restart the terminal again

---

<br>
<br>

few!!! lets get back to `__libc_start_main` which calls `__libc_init_first`

```c
void __libc_init_first(int argc, char *arg0, ...)
{
    char **argv = &arg0, **envp = &argv[argc + 1];
    __environ = envp;   // converting the argument vector to global
    __libc_init (argc, argv, envp);
}
```

this is about as much as we are going to cover about `__libc_start_main`
but in general, it

- Takes care of some security problems with `setuid` `setgid` programs

  setuid and setgid are special flags that can be set on executables or scripts, allowing them to run with the privileges of the user who owns the file (often root), rather than the user who runs the program. This is commonly used for programs that need elevated privileges, such as changing system settings.

- Starts up `threading`
- Registers the `fini` (our program), and `rtld_fini` (run-time loader) arguments to get run by `at_exit` to run the program's and the loader's cleanup routines
- Calls the `init` argument
- Calls the `main` with the `argc` and `argv` arguments passed to it and with the global `__environ` argument as detailed above.
- Calls `exit` with the return value of main

---

<br>
<br>

## Calling the init argument

The init argument, to `__libc_start_main`, is set to `__libc_csu_init` which is also linked into our code. It's compiled from a C program which lives in the glibc source tree in csu/elf-init.c and linked into our program. The C code is similar to (but with a lot more #ifdefs)

`__libc_csu_init` is a function in the GNU C Library (glibc) that is called during the initialization of a program, specifically in the startup process before the `main()` function is invoked. It is part of the program's setup to handle various initialization tasks, particularly for programs that require elevated privileges (like those using `setuid` or `setgid`). This function is compiled from a source file (`csu/elf-init.c`) in the glibc source tree and linked into the final executable. The main responsibilities of `__libc_csu_init` include performing security checks (such as clearing out dangerous environment variables), handling library initialization, and setting the correct user and group IDs for the program. It ensures that the program starts with the right environment and privileges, reducing the risk of security vulnerabilities before the `main()` function starts executing.

```c
void
__libc_csu_init (int argc, char **argv, char **envp)
{

  _init ();

  const size_t size = __init_array_end - __init_array_start;
  for (size_t i = 0; i < size; i++)
      (*__init_array_start [i]) (argc, argv, envp);
}
```

The `__libc_csu_init` function is crucial for setting up a program when it starts executing. Even though the term "constructor" is often associated with C++, the concept of constructors and destructors actually existed long before C++ and applies to C programs as well. Every executable has a C-level constructor (`__libc_csu_init`) and a C-level destructor (`__libc_csu_fini`). These functions are responsible for initializing and cleaning up the environment for the program.

The `__libc_csu_init` function is executed when the program starts, before entering the `main()` function. This function's role is to search for and call any global C-level constructors that the program may have, ensuring that they are executed properly before the main logic begins. Although it may feel like the concept of constructors and destructors belongs to C++, these functions are used in C programs as well, and they are often referred to as "initializers" (for constructors) and "finalizers" (for destructors). This mechanism allows a C program to have setup and teardown routines similar to those in C++.

```bash
080483a0 <__libc_csu_init>:
 80483a0:       55                      push   %ebp
 80483a1:       89 e5                   mov    %esp,%ebp
 80483a3:       57                      push   %edi
 80483a4:       56                      push   %esi
 80483a5:       53                      push   %ebx
 80483a6:       e8 5a 00 00 00          call   8048405 <__i686.get_pc_thunk.bx>
 80483ab:       81 c3 49 1c 00 00       add    $0x1c49,%ebx
 80483b1:       83 ec 1c                sub    $0x1c,%esp
 80483b4:       e8 bb fe ff ff          call   8048274 <_init>
 80483b9:       8d bb 20 ff ff ff       lea    -0xe0(%ebx),%edi
 80483bf:       8d 83 20 ff ff ff       lea    -0xe0(%ebx),%eax
 80483c5:       29 c7                   sub    %eax,%edi
 80483c7:       c1 ff 02                sar    $0x2,%edi
 80483ca:       85 ff                   test   %edi,%edi
 80483cc:       74 24                   je     80483f2 <__libc_csu_init+0x52>
 80483ce:       31 f6                   xor    %esi,%esi
 80483d0:       8b 45 10                mov    0x10(%ebp),%eax
 80483d3:       89 44 24 08             mov    %eax,0x8(%esp)
 80483d7:       8b 45 0c                mov    0xc(%ebp),%eax
 80483da:       89 44 24 04             mov    %eax,0x4(%esp)
 80483de:       8b 45 08                mov    0x8(%ebp),%eax
 80483e1:       89 04 24                mov    %eax,(%esp)
 80483e4:       ff 94 b3 20 ff ff ff    call   *-0xe0(%ebx,%esi,4)
 80483eb:       83 c6 01                add    $0x1,%esi
 80483ee:       39 fe                   cmp    %edi,%esi
 80483f0:       72 de                   jb     80483d0 <__libc_csu_init+0x30>
 80483f2:       83 c4 1c                add    $0x1c,%esp
 80483f5:       5b                      pop    %ebx
 80483f6:       5e                      pop    %esi
 80483f7:       5f                      pop    %edi
 80483f8:       5d                      pop    %ebp
 80483f9:       c3                      ret
```

# something intresting:

Not much to talk about here, but I thought you'd want to see it. The get_pc_thunk thing is a little interesting.

<`__i686.get_pc_thunk.bx`> what is this

A "thunk" in programming, especially in low-level systems programming, is a small piece of code that acts as an intermediary to modify the control flow or perform some setup before jumping to the target code. It essentially "thunks" or "wraps" around another function or action to adjust something before that function is executed.

if you want to learn about thunks click [here](../../Thunk/Readme.md)

## Position-Independent Code (PIC):

This code involves involves **position-independent code (PIC)**, which is code designed to run correctly regardless of its memory address. This is crucial for shared libraries, where the code must work no matter where it's loaded in memory.

we seem to be looking at some assembly code related to position-independent code (PIC) and the **Global Offset Table (GOT)**, which is part of how dynamic linking works in such code.

Here's what’s going on step-by-step:

1. **The Goal of Position-Independent Code**:

   - Position-independent code is meant to run correctly regardless of where it is loaded in memory.
   - To do this, the code needs to access certain global variables or functions, but the addresses of those variables or functions are not known until runtime (when the code is actually loaded into memory). This is where the Global Offset Table (GOT) comes in—it holds addresses to variables and functions that the program can access.

2. **`__get_pc_thunk_bx`**:
   - The `__get_pc_thunk_bx` function is a special assembly function used in PIC to obtain the correct address of the **Global Offset Table** (GOT).
   - The basic problem being solved is how to get the correct address of the **GOT** when the code is not at a fixed memory address.
3. **The Code**:

   - The code involves a **call** to `__get_pc_thunk_bx`. Here’s a breakdown of what happens:

   ```asm
   push %ebx                       ; Save the value in the ebx register
   call __get_pc_thunk_bx          ; Call __get_pc_thunk_bx, which gets the current address
   add $_GLOBAL_OFFSET_TABLE_, %ebx ; Adds the offset to the base of the GOT
   ```

4. **The `__get_pc_thunk_bx` Function**:

   ```asm
   __get_pc_thunk_bx:
   movel (%esp), %ebx    ; Move the return address from the stack (the address after the call) into ebx
   return                ; Return, which jumps to the address stored in ebx (the return address)
   ```

   - The call instruction pushes the return address (the address of the instruction following the `call` to `__get_pc_thunk_bx`) onto the stack.
   - Inside the `__get_pc_thunk_bx` function, this return address is popped into `%ebx`, so that `%ebx` now holds the address of the next instruction.
   - The `return` instruction then pops the value off the stack and jumps back to the address of the instruction that follows the `call`.
   - The key trick here is that the return address will be the address where the instruction after the `call` was located, which is important because that's the code we're trying to calculate the offset from in order to access the GOT.

5. **Adding the Offset**:
   - After returning from `__get_pc_thunk_bx`, the next instruction adds `$_GLOBAL_OFFSET_TABLE_` (a symbol representing the address of the GOT) to `%ebx`.
   - This allows the code to compute the correct address for the global offset table, enabling the code to access global variables or functions that are stored in the GOT.

### Why All This Is Needed:

- In position-independent code, addresses of global variables or functions are not known at compile time.
- The GOT holds these addresses, but since the code could be loaded at any address in memory, it needs to use a **thunk** (a helper function like `__get_pc_thunk_bx`) to dynamically calculate the correct address of the GOT and the data/functions inside it.

### A More Concrete Example:

Imagine you have a global variable `myVar` that is part of a shared library. In a typical program, the compiler would just use the address of `myVar` directly. But in a shared library (using PIC), the actual address of `myVar` isn’t known until runtime. So, the code uses the GOT to store the address of `myVar` (which is fixed at runtime), and the program uses the thunk to get that address dynamically.

The **thunk** is a tiny helper function that sets up the address of the Global Offset Table (GOT) in position-independent code. It's part of the machinery that allows dynamic linking, so even though your code doesn’t know the exact memory location of global data and functions when it’s compiled, it can calculate those addresses at runtime and continue execution.

click [here](../../pie&pic/Readme.md) to learn about pic and pie

---

<br>
<br>
<br>
<br>

## loop ?

```asm
80483eb:       83 c6 01                add    $0x1,%esi
80483ee:       39 fe                   cmp    %edi,%esi
80483f0:       72 de                   jb     80483d0 <__libc_csu_init+0x30>
```

The loop from `__libc_csu_init` will be discussed in a minute after we discuss the init() call that really calls `_init`. For now, just remember that it calls any C level initializers for our program.

---

## `_init` gets the call

Ok, the loader handed control to `_start`, who called `__libc_start_main` who called `__libc_csu_init` who now calls `_init`.

that is what we have learned so far

```asm
08048274 <_init>:
 8048274:       55                      push   %ebp
 8048275:       89 e5                   mov    %esp,%ebp
 8048277:       53                      push   %ebx
 8048278:       83 ec 04                sub    $0x4,%esp
 804827b:       e8 00 00 00 00          call   8048280 <_init+0xc>
 8048280:       5b                      pop    %ebx
 8048281:       81 c3 74 1d 00 00       add    $0x1d74,%ebx        (.got.plt)
 8048287:       8b 93 fc ff ff ff       mov    -0x4(%ebx),%edx
 804828d:       85 d2                   test   %edx,%edx
 804828f:       74 05                   je     8048296 <_init+0x22>
 8048291:       e8 1e 00 00 00          call   80482b4 <__gmon_start__@plt>
 8048296:       e8 d5 00 00 00          call   8048370 <frame_dummy>
 804829b:       e8 70 01 00 00          call   8048410 <__do_global_ctors_aux>
 80482a0:       58                      pop    %eax
 80482a1:       5b                      pop    %ebx
 80482a2:       c9                      leave
 80482a3:       c3                      ret
```

It starts with the regular C calling convention. click [here](../../Ccallingconventions/Readme.md) to learn about C calling conventions

the `_init` calls the three functions (there are others but we will only disscous 3)

- `_gmon_start__`
- `frame_dummy`
- `__do_global_ctors_aux`

---

<br>
<br>

# `_gmon_start__`

`__gmon_start__` is a function used by the GNU `gprof` profiler for runtime instrumentation. It is part of the GNU toolchain’s mechanism to collect profiling information when a program is compiled with the `-pg` flag.

- It is a function that gets called at runtime to initialize the GNU profiling system (`gprof`).
- It is usually invoked in the `_init` section of dynamically linked ELF executables and shared libraries.
- If the program is not compiled for profiling, `__gmon_start__` may not exist or may be a weak symbol that does nothing.

---

## When and Where is `__gmon_start__` Used?

- It appears in binaries that are compiled with **profiling support (`-pg`)**.
- It is typically called from the ELF **initialization routines** (e.g., `_init` or `__libc_csu_init`).
- The linker may automatically insert it in dynamically linked programs.

## What Happens if `__gmon_start__` is Not Defined?

- Since `__gmon_start__` is a **weak symbol**, it does not cause a linker error if missing.
- If the binary is not compiled with profiling (`-pg` is not used), `_init` will **not** call `__gmon_start__`.

You should see a call to `__gmon_start__` somewhere in `_init` or `__libc_csu_init`.

---

- `__gmon_start__` is used by `gprof` for profiling.
- It is usually called in `_init` or other initialization routines.
- If `-pg` is **not** used, `_init` does **not** call `__gmon_start__`.
- It is a weak symbol, meaning its absence does not cause linker errors.

lets see in our code where is `__gmon_start__` being called the

```
00001000 <_init>:
    1000:       53                      push   %ebx
    1001:       83 ec 08                sub    $0x8,%esp
    1004:       e8 f8 00 00 00          call   1101 <__x86.get_pc_thunk.bx>
    1009:       81 c3 eb 2f 00 00       add    $0x2feb,%ebx
    100f:       8d 83 bc d0 ff ff       lea    -0x2f44(%ebx),%eax
    1015:       85 c0                   test   %eax,%eax
    1017:       74 02                   je     101b <_init+0x1b>
    1019:       ff d0                   call   *%eax
    101b:       83 c4 08                add    $0x8,%esp
    101e:       5b                      pop    %ebx
    101f:       c3                      ret
```

here you can see that i have compiled the program using `-pg` and still not seeing the `__gmon_start__` fun

`__gmon_start__` is typically called indirectly via GOT

Since RIP-relative addressing is available in x86-64, function addresses can often be accessed without the GOT.

so we see direct call in x64 bit

now i will debug this in gdb to see what is `call   *%eax` calling to

it is calling to

```asm
Dump of assembler code for function __gmon_start__:
   0x565560b0 <+0>:     push   %ebx
   0x565560b1 <+1>:     call   0x56556101 <__x86.get_pc_thunk.bx>
   0x565560b6 <+6>:     add    $0x2f3e,%ebx
   0x565560bc <+12>:    sub    $0x8,%esp
   0x565560bf <+15>:    mov    0x24(%ebx),%edx
   0x565560c5 <+21>:    test   %edx,%edx
   0x565560c7 <+23>:    jne    0x565560f7 <__gmon_start__+71>
   0x565560c9 <+25>:    sub    $0x8,%esp
   0x565560cc <+28>:    lea    -0x3ff4(%ebx),%eax
   0x565560d2 <+34>:    push   -0x8(%ebx)
   0x565560d8 <+40>:    push   %eax
   0x565560d9 <+41>:    movl   $0x1,0x24(%ebx)
   0x565560e3 <+51>:    call   0x56556050 <__monstartup@plt>
   0x565560e8 <+56>:    pop    %eax
```

Then we grab the address of gmon_start. If it's zero then we don't call it, instead we jump past it. Otherwise, we call it to set up profiling. It runs a routine to start profiling, and calls at_exit to schedule another routine to run later to write gmon.out at the end of execution.

if you want to learn about profiling click [here](../../profiling/Readme.md)

---

<br>
<br>

# `frame_dummy`

`frame_dummy` is a small, compiler-generated function used to set up exception handling by preparing arguments for the `__register_frame_info` function. `__register_frame_info` is a function used in the GNU toolchain (primarily in GCC and related environments) to register exception handling and stack unwinding information for dynamically loaded code. It is part of the DWARF Exception Handling (EH) system, which helps manage stack unwinding when an exception is thrown. However, in many cases, especially in simple programs without C++ exceptions or global constructors, `frame_dummy` is either empty or never executed. While it plays a role in program initialization, it is not always relevant for analysis unless you are specifically investigating exception handling mechanisms.

---

<br>
<br>

# `__do_global_ctors_aux`

The function `__do_global_ctors_aux` is responsible for **calling global constructors** in a compiled program. This is part of the **C++ runtime initialization** process, ensuring that all global (static) objects with constructors are properly initialized before `main()` is executed.

The addresses of constructors and destructors of static objects are each stored in a different section in ELF executable. for the constructors there is a section called .CTORS and for the destructors there is the .DTORS section.

the compiler creates two auxillary functions `__do_global_ctors_aux` and `__do_global_dtors_aux` for calling the constructors and destructors of these static objects, respectively.

`__do_global_ctors_aux` function simply performs a walk on the .CTORS section, while the `__do_global_dtors_aux` does the same job only for the .DTORS section which contains the program specified destructors functions.

---

#### **Background: Global Constructors in C++**

In C++, objects declared at the global (or static) scope are initialized before `main()` starts. This includes:

- **Global static objects**
- **Local static objects within functions**
- **Static objects inside shared libraries (`.so` or `.dll`)**

Because their constructors must run before `main()`, the compiler generates code to **collect and call** them during program startup.

---

#### **What `_do_global_ctors_aux` Does**

- It **iterates over an array of function pointers** to all global constructors.
- It **calls each constructor** in the correct order, ensuring all global objects are initialized before `main()`.
- This function is usually called from `_init` or a similar startup routine.

##### **Sequence of Execution**

1. The linker places global constructor function pointers in a special section (usually `.ctors` or `.init_array`).
2. `_do_global_ctors_aux` retrieves these function pointers.
3. It loops through them and **calls each constructor function**.
4. Once all constructors have run, control is passed to `main()`.

---

#### **Where You Might See It**

- In disassembled binaries where static/global objects exist.
- In debugging sessions when tracing **program startup**.
- Inside dynamic libraries (`.so`, `.dll`) to handle **per-library constructor calls**.

---

### **Example (Simplified Pseudocode)**

```cpp
// Example of a global object
class Global {
public:
    Global() { std::cout << "Global constructor called!" << std::endl; }
};

// Global instance
Global g;
```

At the **assembly level**, the runtime initialization mechanism ensures:

1. `_do_global_ctors_aux` is invoked before `main()`.
2. The constructor of `g` is called before execution proceeds.

```assembly
call _do_global_ctors_aux  ; Calls all global constructors
call main                  ; Proceeds to main()
```

---

### **Why Does This Matter?**

- If `__do_global_ctors_aux` **fails**, uninitialized objects could cause crashes.
- If debugging startup issues, tracing `__do_global_ctors_aux` can reveal **constructor-related bugs**.
- Understanding it helps when analyzing **malware or reverse-engineering C++ programs**.

In C++, global and static objects with constructors are explicitly initialized before main(). This is why `__do_global_ctors_aux` is needed.

In C, since there are no constructors, `_do_global_ctors_aux` is not used. However, initialization functions may still run before main()—especially when using GCC attributes (**attribute**((constructor))) or compiler-specific sections (.init_array).

## How Does C Handle Initialization Before main()?

- ### Static and Global Variable Initialization

  In C, global and static variables are initialized before main() starts, but only with:

  - Zero for uninitialized variables (.bss section).
  - Their defined values (.data section).
    Unlike C++, C does not have constructors, so `_do_global_ctors_aux` is unnecessary.

- ### `__attribute__((constructor)) in GCC`

  In GCC and Clang, you can force functions to run before main() using:

  ```c
  #include <stdio.h>

  __attribute__((constructor))
  void before_main() {
      printf("This runs before main!\n");
  }

  int main() {
      printf("Main function!\n");
      return 0;
  }
  ```

  output:

  ```bash
  This runs before main!
  Main function!
  ```

  The function marked with `__attribute__((constructor))` executes before main(), similar to a C++ constructor.
  This is used in shared libraries (.so / .dll) for initialization.

  if you want to learn about `__attribute__` click [here](../../__attribute__/Readme.md)

- ## .init_array Section (Used in ELF Binaries)

  When a program is compiled, the linker places initialization functions in a special section called .init_array.
  The runtime calls each function in .init_array before main() starts.
  This is similar to `_do_global_ctors_aux` but applies to both C and C++

<br>
<br>

In C++, `_do_global_ctors_aux` ensures global constructors are executed before main().
In C, there are no constructors, but functions can run before main() using `__attribute__((constructor))` or .init_array.
In both cases, the program ensures necessary initialization is done before entering main().

but Modern compilers, like g++ with recent versions of glibc and libstdc++, have moved to a different mechanism using .init_array sections instead of explicit function calls.

Instead of a single function like `__do_global_ctors_aux`, constructors are now stored in the `.init_array` section of the ELF binary.
The runtime loader automatically calls each function in .init_array in order, eliminating the need for `_do_global_ctors_aux`.

Old GCC versions (before .init_array) used `_do_global_ctors_aux` to call global constructors before main().

but `__do_global_dtors_aux` Still Exists

The destruction mechanism (`__do_global_dtors_aux`) still exists because the runtime needs to ensure proper cleanup of global objects.

if you want to learn about global constructor and distructor in c (not in c++ ) click [here](../../c_con_&_dis/Readme.md)

so click [here](../init_array.md) to learn about `init_array`

but learning about `_do_global_ctors_aux` give you an overview of how things work

so in summary

`_do_global_ctors_aux` was used in older GCC versions (before .init_array).

Modern GCC and Clang use .init_array instead.

C++ global constructors are now called via `__libc_csu_init()`.

---

<br>
<br>
<br>

but wtf it is still used i have cheaked it in the gcc code `gcc/libgcc/crtstuff.c`
why this is

`__do_global_ctors_aux` is still used in older GCC versions, certain embedded systems, or systems that explicitly use the .ctors and .dtors sections for global initialization and destruction. However, modern compilers (GCC, Clang) prefer using .init_array and `__libc_csu_init()` for initialization, making `__do_global_ctors_aux` less relevant in newer toolchains. Nevertheless, it's still included in some contexts for backward compatibility.

so lets see its code

```c
__do_global_ctors_aux (void)
{
  func_ptr *p;
  for (p = __CTOR_END__ - 1; *p != (func_ptr) -1; p--)
    (*p) ();
}
```

In this code, `__do_global_ctors_aux` initializes a pointer `p` to point at `__CTOR_END__ - 1`. `__CTOR_END__` is a global variable that marks the end of the constructor function table, and subtracting 1 from it makes the pointer point to the last constructor in the table. The code then enters a loop where it checks if the function pointer at `p` is not equal to `-1` (a sentinel value marking the end of the table). If it isn't `-1`, the function pointed to by `p` is called, and `p` is decremented to point to the previous function in the table. This process repeats until the sentinel value (`-1`) is reached, indicating the end of the constructor list. The use of pointer arithmetic allows the code to traverse the table of function pointers in reverse order, calling each constructor function in sequence.

lets convert this code into assemblly

```asm
08048450 <__do_global_ctors_aux>:
 8048450:       55                      push   %ebp
 8048451:       89 e5                   mov    %esp,%ebp
 8048453:       53                      push   %ebx
 8048454:       83 ec 04                sub    $0x4,%esp
 8048457:       a1 14 9f 04 08          mov    0x8049f14,%eax
 804845c:       83 f8 ff                cmp    $0xffffffff,%eax
 804845f:       74 13                   je     8048474 <__do_global_ctors_aux+0x24>
 8048461:       bb 14 9f 04 08          mov    $0x8049f14,%ebx
 8048466:       66 90                   xchg   %ax,%ax
 8048468:       83 eb 04                sub    $0x4,%ebx
 804846b:       ff d0                   call   *%eax
 804846d:       8b 03                   mov    (%ebx),%eax
 804846f:       83 f8 ff                cmp    $0xffffffff,%eax
 8048472:       75 f4                   jne    8048468 <__do_global_ctors_aux+0x18>
 8048474:       83 c4 04                add    $0x4,%esp
 8048477:       5b                      pop    %ebx
 8048478:       5d                      pop    %ebp
 8048479:       c3                      ret
```

There's the normal preamble with the addition of saving %ebx as well because we're going to use it in the function, and we also save room for the pointer p. You'll notice that even though we save room on the stack for it, we never store it there. p will instead live in %ebx, and `*p` will live in %eax

It looks like an optimization has occurred, instead of loading `__CTOR_END__` and then subtracting 1 from it, and dereferencing it, instead, we go ahead and load `*(__CTOR_END__ - 1)`, which is the immediate value `0x8049f14`. We load the value in it (remember `$0x8049f14` would mean put that value, without the $, just 0x8049f14 means the contents of that address), into %eax.

Immediately, we compare this first value with -1 and if it's equal, we're done and jump to address 0x8048474, where we clean up our stack, pop off the things we've saved on there and return

Assuming that there's at least one thing in the function table, though, we also move the immediate value $0x8049f14, into %ebx which is f our function pointer, and then do the `xchg %ax,%ax`. What the heck is that? Well, grasshopper, that is what they use for a `nop (No OPeration)` in 16 or 32 bit x86. It does nothing but take a cycle and some space. In this case, it's used to make the loop (the top of the loop is the subtract on the next line) start on 8048468 instead of 8048466. The advantage of that is that it aligns the start of the loop on a 4 byte boundary and gives a better chance that the whole loop will fit in a cache line instead of being broken across two. It speeds things up.

Next we subtract 4 from %ebx to be ready for the next time through the loop, call the function we've got the address of in %eax, move the next function pointer into %eax, and compare it to -1. If it's not -1 we jump back up to the subtract and loop again.

Otherwise we fall through into our function epilogue and return to `_init`, which immediately falls through into its epilogue and returns to `__libc_csu_init__`. Bet you forgot all about him. There's still a loop to deal with

---

<br>
<br>

# Back up to `__libc_csu_init__`

here it is in C.

```c
void
__libc_csu_init (int argc, char **argv, char **envp)
{

  _init ();

  const size_t size = __init_array_end - __init_array_start;
  for (size_t i = 0; i < size; i++)
      (*__init_array_start [i]) (argc, argv, envp);
}
```

What is this `__init_array`? I thought you'd never ask. You can have code run at this stage as well. Since this is just after returning from running `_init` which ran our constructors, that means anything in this array will run after constructors are done. You can tell the compiler you want a function to run at this phase. The function will receive the same arguments as main.

```c
void init(int argc, char **argv, char **envp) {
 printf("%s\n", __FUNCTION__);
}

__attribute__((section(".init_array"))) typeof(init) *__init = init;

```

but before we do this there are more things to disscous

We'll be all the way back in `__libc_start_main__`

it calls our main now, and then passes the result to exit().

# exit

exit() runs some more loops of functions

The `exit()` function in C and C++ is used to terminate a program, and it goes through several steps to clean up before the program ends. Specifically, when `exit()` is called, it ensures that various resources are properly released and that certain functions are executed before the program terminates. Here's a detailed breakdown of the sequence of events that `exit()` triggers:

### Steps exit() Calls:

1. **Functions Registered with `atexit()`**:

   - These are functions that have been registered by the program using the `atexit()` function. They are executed in reverse order of their registration.
   - These functions are typically used for cleanup tasks that should be performed before the program exits.
   - They are executed **first** in the process of termination.
   - For example, if you register cleanup functions using `atexit()`, they will be called when `exit()` is invoked.

2. **Functions in the `.fini` Section (Fini Array)**:

   - After running `atexit()` functions, the program will look for functions in the **fini section** (sometimes called the **fini array**) of the program's binary.
   - These functions are typically responsible for more low-level or platform-specific cleanup, such as deallocating resources, unregistering signal handlers, or freeing memory used by static data structures.
   - The functions in the **.fini** section are executed after `atexit()` functions and before destructors.

3. **Destructors**:

   - If your program is written in C++, the **destructors** of global and static objects are executed next. These are the functions that clean up any objects that were created during the program's execution.
   - Destructors are typically used to release any resources (like memory or file handles) associated with global or static objects.
   - These destructors are executed **last** in the exit process, in reverse order of their construction.

   one example of this is `__do_global_dtors_aux`

### High-Level Breakdown of `exit()` Calls:

1. **atexit() Functions**: Functions registered via `atexit()` are executed first.
2. **Fini Array Functions**: Functions in the `.fini` section (used mainly for low-level cleanup).
3. **Destructors**: The destructors for static and global objects are called last.

### Example Code:

```c
#include <stdio.h>
#include <stdlib.h>

void cleanup1() {
    printf("Cleanup function 1\n");
}

void cleanup2() {
    printf("Cleanup function 2\n");
}

int main() {
    atexit(cleanup1);  // Register cleanup1
    atexit(cleanup2);  // Register cleanup2

    printf("Program is ending...\n");
    exit(0);  // Exit the program
}
```

### Output:

```
Program is ending...
Cleanup function 2
Cleanup function 1
```

### How This Works:

- `cleanup1()` and `cleanup2()` are registered using `atexit()`, so they are executed in reverse order of their registration when `exit()` is called.
- The program will print "Program is ending..." and then call the registered cleanup functions in the order `cleanup2()` first, then `cleanup1()`.

---

<br>
<br>
<br>
<br>

# summery

at last i will give you an code which will give you the order in which the c/c++ elf files are executed

```c
#include <stdio.h>
#include <stdlib.h>

void preinit(int argc, char **argv, char **envp) {
    printf("%s\n", __FUNCTION__);
}

void init(int argc, char **argv, char **envp) {
    printf("%s\n", __FUNCTION__);
}

void fini() {
    printf("%s\n", __FUNCTION__);
}

__attribute__((section(".init_array"))) typeof(init) *__init = init;
__attribute__((section(".preinit_array"))) typeof(preinit) *__preinit = preinit;
__attribute__((section(".fini_array"))) typeof(fini) *__fini = fini;

void  __attribute__ ((constructor)) constructor() {
    printf("%s\n", __FUNCTION__);
}

void __attribute__ ((destructor)) destructor() {
    printf("%s\n", __FUNCTION__);
}

void my_atexit() {
    printf("%s\n", __FUNCTION__);
}

void my_atexit2() {
    printf("%s\n", __FUNCTION__);
}

int main() {
    atexit(my_atexit);
    atexit(my_atexit2);
    return 0;
}

```

output:

```bash
preinit
init
constructor
my_atexit2
my_atexit
destructor
fini
```

---

<br>

# The End
