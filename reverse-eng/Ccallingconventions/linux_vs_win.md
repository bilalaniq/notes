# Windows vs Linux Ccallling convention

here we will discuss the differnece in the linux and windows Ccalling convention in both x64 and x 86

we will write an small c++/c code and compare there assemblly to see the difference in only the calling convention

```cpp
#include <iostream>

int fun(int a, int b, int c, int d, int e, int f)
{
    return (a + b + c + d + e + f);
}

int main()
{
    int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;

    fun(a, b, c, d, e, f);

    return 0;
}
```

## Windows

- ### X86(cdecl)

In the cdecl calling convention (used by default in 32-bit C/C++ programs on Windows):

- Function arguments are pushed right-to-left onto the stack.
- The caller cleans up the stack after the function returns
- Return value is placed in EAX.

the dissassemblly of the main function before calling the fun() will look like

caller:

```bash
002718E0  mov         eax,dword ptr [f]
002718E3  push        eax
002718E4  mov         ecx,dword ptr [e]
002718E7  push        ecx
002718E8  mov         edx,dword ptr [d]
002718EB  push        edx
002718EC  mov         eax,dword ptr [c]
002718EF  push        eax
002718F0  mov         ecx,dword ptr [b]
002718F3  push        ecx
002718F4  mov         edx,dword ptr [a]
002718F7  push        edx
002718F8  call        fun (02713C0h)  #fun(a, b, c, d, e, f);
002718FD  add         esp,18h
```

in 32-bit, arguments are always passed on the stack.
so meaning that no matter how many arrguments are there it is always passed using stack

Registers like EAX, EBX, ECX, etc., are not used to pass function arguments. They are only used:

- Temporarily to move or store data
- For internal calculations
- To help load arguments from the stack

Why Not Just Work on the Stack?
While technically possible, this is:

- Slower (accessing RAM vs. registers)
- More complex (you can't add [ebp+8], [ebp+12] directly)
- Not how CPUs are optimized to run

---

<br>

callee:

heres the dissassemblly of the callee

```bash
int fun(int a, int b, int c, int d, int e, int f)
{
00271820  push        ebp  # Save old base pointer
00271821  mov         ebp,esp  #  Set new base pointer to current stack pointer
00271823  sub         esp,0C0h  # Reserve 192 bytes (0xC0) for local variables

#  Saving Callee-Saved Registers

00271829  push        ebx
0027182A  push        esi
0027182B  push        edi
0027182C  mov         edi,ebp
0027182E  xor         ecx,ecx
00271830  mov         eax,0CCCCCCCCh
00271835  rep stos    dword ptr es:[edi]
00271837  mov         ecx,offset _2398A6F0_FileName@cpp (027C068h)
0027183C  call        @__CheckForDebuggerJustMyCode@4 (0271325h)
00271841  nop
    return (a + b + c + d + e + f);
00271842  mov         eax,dword ptr [a]  # Actually is [ebp+8]
00271845  add         eax,dword ptr [b]  # Actually is [ebp+12]
00271848  add         eax,dword ptr [c]  # Actually is [ebp+16]
0027184B  add         eax,dword ptr [d]  # Actually is [ebp+20]
0027184E  add         eax,dword ptr [e]  # Actually is [ebp+24]
00271851  add         eax,dword ptr [f]  # Actually is [ebp+28]
}
```

Here’s what the stack looks like just after entering fun():

| Stack Address | Contains       | Accessed As          |
| ------------- | -------------- | -------------------- |
| `ebp+4`       | Return address | (used automatically) |
| `ebp+8`       | Argument `a`   | `[ebp+8]`            |
| `ebp+12`      | Argument `b`   | `[ebp+12]`           |
| `ebp+16`      | Argument `c`   | `[ebp+16]`           |
| `ebp+20`      | Argument `d`   | `[ebp+20]`           |
| `ebp+24`      | Argument `e`   | `[ebp+24]`           |
| `ebp+28`      | Argument `f`   | `[ebp+28]`           |

<br><br>

the callee also saves the caller registers (also called Callee-Saved Registers)

Callee-saved registers are the CPU registers that a called function (callee) must preserve if it wants to use them. That means:
If the callee modifies these registers, it must restore their original values before returning to the caller.

In 32-bit x86 calling convention (cdecl):

These are the callee-saved registers:

- EBX
- ESI
- EDI
- EBP

| Register | Role              | Must be preserved by | Common use                   |
| -------- | ----------------- | -------------------- | ---------------------------- |
| `EBX`    | General-purpose   | **Callee**           | Storage, counters            |
| `ESI`    | Source index      | **Callee**           | String/memory source pointer |
| `EDI`    | Destination index | **Callee**           | String/memory dest pointer   |
| `EBP`    | Stack frame base  | **Callee**           | Frame/local var addressing   |

Why is this important?
The caller may rely on these registers to hold data across function calls. If the callee doesn't restore them, it could lead to bugs and unexpected behavior.

now lets see the return value from the callee

```bash
00271842  mov         eax,dword ptr [a]    # it just adds all the values and moves them in the eax register
00271845  add         eax,dword ptr [b]
00271848  add         eax,dword ptr [c]
0027184B  add         eax,dword ptr [d]
0027184E  add         eax,dword ptr [e]
00271851  add         eax,dword ptr [f]
```

the caller then can access the returned value by using the eax register

after that we get to return

```bash
00751854  pop         edi
00751855  pop         esi
00751856  pop         ebx
00751857  add         esp,0C0h
0075185D  cmp         ebp,esp
0075185F  call        __RTC_CheckEsp (0751249h)
00751864  mov         esp,ebp
00751866  pop         ebp
00751867  ret
```

cleanup and return process of a function.

The instructions are popping the saved registers off the stack

This instruction adjusts the stack pointer (esp) by adding 0xC0 (192 bytes). This is a cleanup operation to restore the stack to its state before the function was called. this is not the full cleanup of the stack the full & last clean up of the tack is done by the caller

`cmp ebp, esp`: This instruction compares the values in the ebp (base pointer) and esp (stack pointer) registers.
ebp is the base pointer used by the function to keep track of the stack frame. By the time the function exits, ebp should be at the same place as esp, ensuring that the stack is clean and in a consistent state.

`call __RTC_CheckEsp`: This instruction calls a runtime check function (`__RTC_CheckEsp`) to verify that the stack pointer (esp) and base pointer (ebp) match up properly. This is a sanity check performed to ensure that the stack hasn’t been corrupted during the function's execution.

`mov esp, ebp`: This instruction restores the stack pointer (esp) to the value of the base pointer (ebp), effectively undoing the changes made to esp by the function.

`pop ebp` : This pops the value of ebp from the stack, which was saved at the beginning of the function.

``ret` : Finally, the ret instruction is used to return control to the calling function. This instruction pops the return address from the stack and jumps to that address, transferring control back to the instruction after the call in the caller

---

<br>
<br>

now the last thing is stack cleanup which is done by the caller in cdecl

```bash
002718FD  add         esp,18h
```

means that 24 bytes (0x18 in hex) are being removed from the stack, effectively cleaning up the stack.

ESP (Stack Pointer) is incremented by 0x18 (24 in decimal).
This discards (removes) 6 arguments × 4 bytes each = 24 bytes, which were pushed onto the stack before a function call.

6 arguments × 4 bytes = 24 bytes (0x18)
