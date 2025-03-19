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

xor of anything with itself sets it to zero. so the `xor %ebp,%ebp` sets %ebp to zero. This is suggested by the ABI (Application Binary Interface specification), to mark the outermost frame. Next we pop off the top of the stack.

Next we pop off the top of the stack. On entry we have argc, argv and envp on the stack, so the pop makes argc go into %esi. We're just going to save it and push it back on the stack in a minute. Since we popped off argc, %esp is now pointing at argv. The mov puts argv into %ecx without moving the stack pointer.

Then we and the stack pointer with a mask that clears off the bottom four bits. `and    $0xfffffff0,%esp`

