# C calling conventions

**C calling conventions** refer to a set of rules that dictate how functions receive parameters, return values, and how the stack is managed during function calls in the C programming language. These conventions ensure that function calls are handled consistently, allowing different parts of a program (or different programs) to work together without conflict.

A calling convention defines:

1. **How arguments are passed to a function** (e.g., via registers or the stack).
2. **How the return value is returned** (e.g., in a specific register).
3. **How the call stack is managed** (who is responsible for cleaning it up, etc.).
4. **Which registers can be used by the caller or callee**.

In a calling convention, the **caller** is responsible for setting up arguments and cleaning up the stack, while the **callee** is responsible for executing the function and preserving certain registers if necessary.

Calling conventions are platform- and compiler-specific, and different conventions exist for different systems. However, most platforms use a common set of conventions that have been standardized over time. Below, I explain some of the most common elements of calling conventions:

### 1. **Passing Arguments**

- **Registers**: Some calling conventions use CPU registers to pass arguments, as registers are much faster than memory. For example, on many architectures, the first few arguments may be passed in registers like `EAX`, `EBX`, `ECX` (on x86) or `R0`, `R1`, etc. (on ARM).
- **Stack**: If there are too many arguments or if the architecture is designed that way, the remaining arguments may be pushed onto the stack in a specific order.
- **Order**: The order in which arguments are pushed or passed (left-to-right or right-to-left) is defined by the calling convention.

  - Left-to-right: Arguments are passed from the leftmost (first) to the rightmost (last). For example, in a function call like foo(a, b, c), argument a would be passed first, followed by b, and finally c.

  - Right-to-left: Arguments are passed starting from the rightmost (last) to the leftmost (first). In the example foo(a, b, c), c would be passed first, followed by b, and finally a

The choice of order depends on the specific calling convention being used. For instance:

x86 (cdecl) uses right-to-left argument passing.
x86_64 (System V ABI) generally uses left-to-right argument passing.

### 2. **Return Values**

- **Registers**: In many conventions, the return value of a function is passed back to the caller in a specific register. For example, on x86, the `EAX` register is often used to hold the return value of a function.
- **Memory**: In some cases, if the return value is too large to fit in a register (such as a large structure), it may be returned via a pointer passed as an argument.

### 3. **Stack Cleanup**

- **Caller Cleanup**: In some calling conventions, the caller is responsible for cleaning up the stack after a function call (this means removing the function arguments from the stack).
- **Callee Cleanup**: In other conventions, the callee (the function being called) is responsible for cleaning up the stack, particularly if the function pushes local variables onto the stack.

### 4. **Register Usage**

- **Caller-saved registers**: These are registers that the caller (the function that makes the call) must save if it wants to preserve their values. If the called function modifies these registers, the caller is responsible for saving and restoring them.
- **Callee-saved registers**: These are registers that the callee (the function being called) must preserve. If the callee uses these registers, it must save the original values and restore them before returning.

### Common C Calling Conventions

Here are some of the most common calling conventions:

1. **cdecl (C Declaration)**

   - The **cdecl** convention is one of the most widely used calling conventions in C programming, especially in x86 systems.
   - **Argument Passing**: Arguments are pushed onto the stack in right-to-left order.
   - **Return Value**: The return value is placed in the `EAX` register.
   - **Stack Cleanup**: The caller is responsible for cleaning up the stack after the function call.
   - **Usage**: Used by default in many C compilers (including GCC).

2. **stdcall (Standard Call)**

   - **Argument Passing**: Arguments are pushed onto the stack in right-to-left order, just like `cdecl`.
   - **Return Value**: The return value is placed in the `EAX` register.
   - **Stack Cleanup**: The callee is responsible for cleaning up the stack before returning.
   - **Usage**: Common in Windows API functions.

3. **fastcall**

   - **Argument Passing**: The first few arguments are passed in registers (e.g., `ECX` and `EDX` on x86), and any remaining arguments are passed on the stack.
   - **Return Value**: The return value is placed in the `EAX` register.
   - **Stack Cleanup**: The caller is responsible for cleaning up the stack.
   - **Usage**: Used to improve performance by minimizing the number of memory accesses, often used in Microsoft compilers.

4. **thiscall**

   - **Used for C++ member functions** that need to pass the `this` pointer (which points to the instance of the class) to the function.
   - **Argument Passing**: The `this` pointer is passed in the `ECX` register, and the rest of the arguments are passed like `cdecl`.
   - **Return Value**: The return value is placed in the `EAX` register.
   - **Stack Cleanup**: The callee is responsible for cleaning up the stack.

5. **x86-64 (System V AMD64 ABI)**
   - For 64-bit systems, there are several conventions like **System V** (used by Unix-like systems).
   - **Argument Passing**: The first six integer arguments are passed in registers (`RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`), and any additional arguments are passed on the stack.
   - **Return Value**: The return value is placed in the `RAX` register.
   - **Stack Cleanup**: The caller is generally responsible for cleaning up the stack, but it depends on the calling convention.

### Why Are Calling Conventions Important?

- **Interoperability**: When calling functions between different programming languages or components (e.g., C and assembly, or C and C++), it's crucial that both sides agree on the calling convention so that arguments are passed correctly, and the stack is managed appropriately.
- **Compiler Optimization**: Different calling conventions can affect performance, as some conventions minimize stack accesses, which are slow compared to register accesses.
- **Portability**: The calling convention affects how code behaves on different platforms or architectures. Therefore, understanding the calling conventions is important for cross-platform development.

### In Summary:

A **calling convention** defines how functions in C (or any other language) pass arguments, return values, and manage the stack. It also specifies who (the caller or the callee) is responsible for cleaning up the stack and handling register usage. By ensuring a consistent calling convention, programs can call each other's functions in a predictable manner, making multi-language programming and system-level operations more reliable.

---

<br>
<br>
<br>

# example

lets see an example so you can easily understand this concept i will be using x86 c code

```c
int add(int num1,int num2){
    int a=num1;
    a=num1+num2;
    return a;
}

main()
{
    return add(3,7);
}
```

in asssemblly this will look like (i am only using general asm code)

```asm
;call

pushl %ebp
movel %esp, %ebp
subl $4, %esp
movel 8 (%ebp), %eax
movel %eax, -4 (%ebx)
addl 12 (%ebp), %eax
movel %eax, -4 (%ebx)
movel -4 (%ebx), %eах
addl $4, %esp
popl %ebp
return


;main

pushl %ebp
movel %esp, %ebp
pushl $7
pushl $3
call add
addl 8, %esp
popl %ebp
return

```

now lets go through it

We start in main. The line of assembler the instruction pointer (%eip) is pointing at is the first instruction of main.

According to the C calling convention, the first thing to do upon entry to a function is to save `%ebp` the caller's base pointer, by pushing it onto the `stack`. Then the next thing is to copy the `stack pointer` into the `base pointer` so that you can find your arguments after the stack pointer changes.

After that you would adjust your stack to make room for any `locals`, but main doesn't have any so you don't see that here.

So in a minute we're going to call add, so we need to push its arguments on to the stack. The convention says that when calling a function you push its arguments onto the stack in reverse order or right-to-left.

so the 7 will pe pushed first then the 3

as you can look here

```asm
pushl $7
pushl $3
call add
```

Each time something gets pushed on the stack, the stack pointer first moves down in memory, and then the item is moved to that memory location. The stack pointer always points at the last thing that got pushed. For simplicity, everything in this program that goes on the stack is 4 bytes long, so each slot you see is a 4 byte slot. It's also possible to pushw for 2 byte values, and pushb for one byte values. It's also important to remember that the stack grows downward in memory.

`Entering add()` - Preamble again (The opening brace of a function corresponds to the preamble!)

when we `call add` Push return address onto the stack and jump to call

In the new function we save main's %ebp. Now we can copy our stack pointer into %ebp. Now %ebp functions as our base pointer and we can access our arguments above in the stack with positive offsets, and we can access locals (there will be one for the local a) with negative offsets. Next we add 4 to our stack pointer to make room for a.

`a=num1;`

We move the first argument off of the stack into %eax, and then save it into the local storage. That corresponds to the line of C, `a=num1`.

`a=num1+num2;`

The next line is a=num1+num2. That corresponds to the next couple of lines where num2 is pulled off the stack and added to %eax. Then it's saved back into our local on the stack. Then right away we copy it back from the stack to %eax! What's going on here? This is typical of unoptimized code generated by compilers. It looks silly because everything is generated by automated rules. When you turn optimization on it will find all of that stuff and clean it up.

`Epilogue` (The closing brace corresponds to the epilogue)

Like the code prologue, there's a standard way to exit a function. We have to undo the things the prologue does, we adjust the stack, pop the caller's base pointer off the stack so that it points in the right place and with the return address now on the top of the stack, we can return. We have the return value in %eax where the convention says that we're supposed to put it, and so we adjust the stack to get rid of our variable, and pop main's %ebx. Notice that nothing takes the values out of stack memory, the pointer just adjusts to free the memory. Later if something else got pushed onto the stack it would overwrite the values, but otherwise they're just sitting there. Finally, the return pops the return address off of the stack into %eip the instruction pointer, and execution returns to main right after the call.

Main pops the %ebx that belonged to main's caller off the stack and returns to them. Why didn't they have to set up the return value
this is because we did not explicitlly return an value it is an special case for main fun that the compiler will automatically assume that main returns 0.
