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
   - x86_64 (System V ABI) generally uses left-to-right argument passing.
   - **Argument Passing**: The first six integer arguments are passed in registers (`RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`), and any additional arguments are passed on the stack.
   - **Return Value**: The return value is placed in the `RAX` register.
   - **Stack Cleanup**: The caller is generally responsible for cleaning up the stack, but it depends on the calling convention.

---

### **Key Differences Between x86 and x86-64 Calling Conventions**

| Feature              | x86 (32-bit `cdecl`)               | x86-64 (System V ABI)                      |
| -------------------- | ---------------------------------- | ------------------------------------------ |
| **Argument Passing** | **Right to left (stack)**          | **Left to right (registers first)**        |
| **Registers Used**   | None (all on stack)                | RDI, RSI, RDX, RCX, R8, R9                 |
| **Stack Cleanup**    | Caller cleans stack (`add esp, X`) | Caller responsible, but typically not used |
| **Return Value**     | `EAX`                              | `RAX`                                      |

📌 **In 64-bit, registers are used for arguments instead of the stack**.

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
;add

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
this is because we did not explicitlly return an value it is an special case for main fun that the compiler will automatically assume that main returns 0 or any other value upon error.

---

lets see what are the changes in the 64 bit version of this code

```asm

;add

0x000055555555512d      4       {
0x0000555555555129 <add+0>:  55                      push   %rbp
0x000055555555512a <add+1>:  48 89 e5                mov    %rsp,%rbp
0x000055555555512d <add+4>:  89 7d ec                mov    %edi,-0x14(%rbp)
0x0000555555555130 <add+7>:  89 75 e8                mov    %esi,-0x18(%rbp)


int a = num1;
=> 0x0000555555555133 <add+10>: 8b 45 ec                mov    -0x14(%rbp),%eax
   0x0000555555555136 <add+13>: 89 45 fc                mov    %eax,-0x4(%rbp)

0x000055555555513f      6  a = num1 + num2;
0x0000555555555139 <add+16>: 8b 55 ec                mov    -0x14(%rbp),%edx
0x000055555555513c <add+19>: 8b 45 e8                mov    -0x18(%rbp),%eax
0x000055555555513f <add+22>: 01 d0                   add    %edx,%eax
0x0000555555555141 <add+24>: 89 45 fc                mov    %eax,-0x4(%rbp)

7           return a;
=> 0x0000555555555144 <add+27>: 8b 45 fc                mov    -0x4(%rbp),%eax

8       }
0x0000555555555147 <add+30>: 5d                      pop    %rbp
0x0000555555555148 <add+31>: c3                      ret


; main

0x0000555555555157      12          return add(3, 7);
0x000055555555514d <main+4>: be 07 00 00 00          mov    $0x7,%esi
0x0000555555555152 <main+9>: bf 03 00 00 00          mov    $0x3,%edi
0x0000555555555157 <main+14>:        e8 cd ff ff ff          call   0x555555555129 <add>

13      }
=> 0x000055555555515c <main+19>:        5d                      pop    %rbp
   0x000055555555515d <main+20>:        c3                      ret


```

now if you are an keen observer you can see that the parameters of the function add are not pushed on the stack
rather they are moved to the registers

lets see the other differences between both architectures

# **Differences in Calling Conventions (x86 vs. x86-64)**

The **x86 (32-bit)** and **x86-64 (64-bit)** versions of your assembly code follow different calling conventions. The major differences include:

| Feature                        | x86 (32-bit, `cdecl`)                                      | x86-64 (System V ABI)                                      |
| ------------------------------ | ---------------------------------------------------------- | ---------------------------------------------------------- |
| **Argument Passing**           | Pushed **right-to-left** onto the stack                    | Passed **left-to-right** in registers (`RDI`, `RSI`, etc.) |
| **Function Cleanup**           | Caller removes arguments from the stack (`add $0x8, %esp`) | No cleanup needed (registers are used)                     |
| **Base Pointer (`EBP`/`RBP`)** | Used to access stack variables                             | Still used, but stack is **aligned**                       |
| **Return Value**               | Stored in `EAX`                                            | Stored in `RAX`                                            |

---

## **Step-by-Step Comparison of `add(int num1, int num2)`**

### **1. Function Prologue (Setting Up the Stack Frame)**

**x86 (32-bit):**

```assembly
push   %ebp          ; Save old base pointer
mov    %esp, %ebp    ; Set up new base pointer
sub    $0x10, %esp   ; Allocate space for local variables
```

- The function saves `EBP` and sets it up for referencing function arguments.
- Stack space is allocated manually.

**x86-64 (64-bit):**

```assembly
push   %rbp          ; Save old base pointer
mov    %rsp, %rbp    ; Set up new base pointer
```

- The same concept, but **`RSP` is already aligned**, so no need for explicit stack space allocation in this case.

---

### **2. Passing Arguments to the Function**

**x86 (32-bit) (`cdecl`):**

```assembly
push  $0x7       ; Push second argument (rightmost)
push  $0x3       ; Push first argument (leftmost)
call  add        ; Call function
```

- Arguments are **pushed onto the stack from right to left**.
- The **caller** (`main()`) is responsible for **cleaning up the stack** after the function call.

**x86-64 (64-bit) (System V ABI):**

```assembly
mov  $0x7, %esi  ; Move second argument into `RSI`
mov  $0x3, %edi  ; Move first argument into `RDI`
call add         ; Call function
```

you may be asking why not use 64bit registers the reason behind this is that

The assembler optimizes mov $0x7, %rsi into mov $0x7, %esi because 32-bit moves automatically clear the upper 32 bits of the 64-bit register. and also This results in a smaller and more efficient instruction encoding (4 bytes instead of 7).

- Arguments are **passed in registers** (`RDI`, `RSI`, `RDX`, etc.).
- No need to push values onto the stack.
- No stack cleanup is required since registers are used instead.

---

### **3. Accessing Function Parameters**

**x86 (32-bit) (`cdecl`):**

```assembly
mov  0x8(%ebp), %eax  ; Load num1 from stack
mov  0xc(%ebp), %eax  ; Load num2 from stack
```

- Arguments are accessed via `EBP + X` because they were pushed onto the stack.

**x86-64 (64-bit) (System V ABI):**

```assembly
mov  %edi, -0x14(%rbp)  ; Store num1 in local variable
mov  %esi, -0x18(%rbp)  ; Store num2 in local variable
```

- No need to fetch arguments from the stack; they are **already in registers**.

but what the heck is -0x14 and -0x18 !!!

In x86 (32-bit, cdecl), the stack alignment is only 4-byte.

In x86-64 (System V ABI), the stack must be 16-byte aligned before calling another function.

%ebp points to the saved base pointer, and arguments are right next to it (small positive offsets).
Local variables are right below %ebp (small negative offsets).

function needs to store arguments in memory, they are stored farther from %rbp to maintain alignment.
Local variables also follow alignment rules, which can push them farther away.

so -0x14 is `-20` and -0x18 is `-24`

you should know that padding is often added when a function is called, but not always. It depends on the stack alignment requirements and the calling convention.

Padding is added only when necessary to maintain 16-byte stack alignment(64 bit ) and 4-byte stack alignment

and if you are an keen absorver you can see that In x86-64, the parameters (num1 and num2) are stored in memory (-0x14(%rbp) and -0x18(%rbp)), whereas in x86 (32-bit), they are used directly from the stack without storing them in local variables.

this is because registers are volatile, meaning their values can be overwritten by another function call
To ensure the values are preserved, the compiler often stores them in memory (even though they are not local variables).

---

### **4. Performing the Addition**

**x86 (32-bit) (`cdecl`):**

```assembly
mov  0x8(%ebp), %edx  ; Load num1
mov  0xc(%ebp), %eax  ; Load num2
add  %edx, %eax       ; num1 + num2
mov  %eax, -0x4(%ebp) ; Store result in `a`
```

**x86-64 (64-bit) (System V ABI):**

```assembly
mov  -0x14(%rbp), %edx  ; Load num1
mov  -0x18(%rbp), %eax  ; Load num2
add  %edx, %eax         ; num1 + num2
mov  %eax, -0x4(%rbp)   ; Store result in `a`
```

- **Same operations**, but in 64-bit, the function parameters are stored in local variables **after being passed via registers**.

now what the hell -0x4(%rbp) it is storing the eax value with an alighnment of 4 bytes what is this
we have talked that the parameters variable stored are stored using 16 bytes alighnment

this is because Parameter variables (coming from function arguments) must follow 16-byte alignment rules for consistent stack alignment.

Local variables (created inside the function) only need natural alignment (4 or 8 bytes) unless they are large.

32-bit does not have this issue because all parameters are pushed sequentially onto the stack and do not need to worry about register-based argument passing.

---

### **5. Returning the Value**

**x86 (32-bit) (`cdecl`):**

```assembly
mov  -0x4(%ebp), %eax  ; Load return value into EAX
leave                  ; Restore stack frame (mov %ebp, %esp + pop %ebp)
ret                    ; Return to caller
```

**x86-64 (64-bit) (System V ABI):**

```assembly
mov  -0x4(%rbp), %eax  ; Load return value into EAX (same as 32-bit)
pop  %rbp              ; Restore base pointer
ret                    ; Return to caller
```

- The return value is stored in **`EAX` (`RAX` in 64-bit)** in both cases.

---

## **Summary of Key Differences**

| Feature                 | x86 (32-bit) `cdecl`    | x86-64 (System V ABI)                           |
| ----------------------- | ----------------------- | ----------------------------------------------- |
| **Argument Passing**    | Right-to-left on stack  | Left-to-right in registers (`RDI`, `RSI`, etc.) |
| **Stack Cleanup**       | Caller (`add $X, %esp`) | No cleanup (registers used)                     |
| **Accessing Arguments** | `EBP + X` (stack-based) | Directly in registers                           |
| **Return Value**        | `EAX`                   | `RAX`                                           |

### **Why is x86-64 More Efficient?**

1. **Faster Argument Passing**: Using registers is much faster than pushing/popping from the stack.
2. **Less Stack Manipulation**: No need to push/pop arguments or clean up the stack after function calls.
3. **Better Performance**: Avoids memory accesses when possible.

---

<br>
<br>
<br>
<br>

# **Handling More Parameters Than Registers in x86 (32-bit) vs. x86-64 (64-bit)**

When a function has **more parameters than available registers**, the system must handle the extra arguments properly. The way this is done is **different** in **32-bit (x86)** and **64-bit (x86-64)**.

---

## **1. 32-bit (x86 - cdecl Calling Convention)**

### **How Parameters Are Passed?**

- **All parameters are pushed onto the stack** in **right-to-left order**.
- **There are no register-based arguments** in cdecl (everything is on the stack).

### **What Happens if There Are Many Parameters?**

- Since **all parameters are already passed on the stack**, nothing changes.
- The **function accesses arguments by reading from `EBP`**:
  ```assembly
  mov  0x8(%ebp), %eax  ; Load first argument
  mov  0xc(%ebp), %edx  ; Load second argument
  mov  0x10(%ebp), %ecx  ; Load third argument
  ```
- If there are **more parameters**, they just have higher offsets:
  ```
  0x8(%ebp)   -> First argument
  0xC(%ebp)   -> Second argument
  0x10(%ebp)  -> Third argument
  0x14(%ebp)  -> Fourth argument
  ```
- The **stack grows downward**, and every extra argument is pushed onto the stack.

#### **Example: `void func(int a, int b, int c, int d, int e, int f);`**

- The caller pushes arguments **right-to-left**:
  ```assembly
  push f
  push e
  push d
  push c
  push b
  push a
  call func
  ```
- The function accesses them from the stack:
  ```assembly
  mov  0x8(%ebp), %eax  ; Load a
  mov  0xC(%ebp), %edx  ; Load b
  mov  0x10(%ebp), %ecx ; Load c
  ```

👉 **In 32-bit, nothing special happens when more parameters are passed**—they are all just pushed onto the stack.

---

## **2. 64-bit (x86-64 - System V ABI)**

### **How Parameters Are Passed?**

- **First 6 integer parameters** are passed **in registers**:
  - `RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`
- **Any additional parameters are passed on the stack**.

### **What Happens if There Are More Than 6 Parameters?**

- The **first 6 arguments** go into registers.
- **Remaining arguments are pushed onto the stack**, similar to 32-bit.

#### **Example: `void func(int a, int b, int c, int d, int e, int f, int g, int h);`**

1. The **caller assigns**:
   ```assembly
   mov  $a, %rdi   ; First parameter (register)
   mov  $b, %rsi   ; Second parameter (register)
   mov  $c, %rdx   ; Third parameter (register)
   mov  $d, %rcx   ; Fourth parameter (register)
   mov  $e, %r8    ; Fifth parameter (register)
   mov  $f, %r9    ; Sixth parameter (register)
   push h          ; Eighth parameter (stack)
   push g          ; Seventh parameter (stack)
   call func
   ```
2. **Inside the function**:
   - The first 6 parameters are in registers.
   - The 7th and 8th parameters are in **memory** at:
     ```
     0(%rsp)  -> g
     8(%rsp)  -> h
     ```

### **How Does the Function Access Extra Parameters?**

- **First 6 arguments: Registers** (`RDI`, `RSI`, etc.).
- **Arguments 7 and beyond: Stack (accessed using `RSP`)**.
  ```assembly
  mov  0(%rsp), %rax  ; Load g from stack
  mov  8(%rsp), %rbx  ; Load h from stack
  ```
- The stack **still follows 16-byte alignment rules**, so padding may be added.

👉 **In 64-bit, when there are more than 6 parameters, the extra ones are passed on the stack, but the first 6 remain in registers.**

---

## **3. Summary: How Extra Parameters Are Handled**

| **Architecture**                   | **Where First Arguments Go**                 | **Where Extra Arguments Go**      | **How They Are Accessed**                       |
| ---------------------------------- | -------------------------------------------- | --------------------------------- | ----------------------------------------------- |
| **32-bit (x86 - cdecl)**           | **Stack** (`push`ed right-to-left)           | **Stack** (next memory locations) | Accessed via `EBP` (`mov  0x8(%ebp), %eax`)     |
| **64-bit (x86-64 - System V ABI)** | **Registers** (`RDI, RSI, RDX, RCX, R8, R9`) | **Stack** (after 6th parameter)   | First 6: Registers, others: `mov 0(%rsp), %rax` |

🚀 **Key Takeaways**:

- **In 32-bit**: Everything is already on the stack, so extra arguments are just at higher memory addresses.
- **In 64-bit**: The first 6 are in registers, and **only extra ones go to the stack**.
- **In both cases, extra parameters are accessed via stack memory (`EBP` in x86, `RSP` in x86-64).**

---
