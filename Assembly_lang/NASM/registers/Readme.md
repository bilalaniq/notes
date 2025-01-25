# x86 Registers (32-bit and 64-bit)

## Table of Contents
- [32-bit Registers (x86)](#32-bit-registers-x86)
  - [General Purpose Registers](#general-purpose-registers)
   
  - [Segment Registers](#segment-registers)
  - [Flags Register](#flags-register)
- [64-bit Registers (x86-64)](#64-bit-registers-x86-64)
  - [General Purpose Registers](#general-purpose-registers-1)
    
  - [Extended Versions of 32-bit Registers](#extended-versions-of-32-bit-registers-lower-32-bits)
  - [Segment Registers](#segment-registers-1)
  - [Flags Register](#flags-register-1)
- [Special Purpose Registers](#special-purpose-registers)
- [Notes](#notes)

---

## 32-bit Registers (x86)

### [General Purpose Registers](#general-purpose-registers)
- [**EAX**](#eax)  
- [**EBX**](#ebx)  
- [**ECX**](#ecx)  
- [**EDX**](#edx)  
- [**ESI**](#esi)  
- [**EDI**](#edi)  
- [**EBP**](#ebp)  
- [**ESP**](#esp)  
- [**EIP**](#eip)  

### [Segment Registers](#segment-registers)
- **CS** (Code Segment)  
- **DS** (Data Segment)  
- **SS** (Stack Segment)  
- **ES** (Extra Segment)  
- **FS**  
- **GS**  

### [Flags Register](#flags-register)
- **FLAGS** (Contains the status flags for the processor)

---

## 64-bit Registers (x86-64)

### [General Purpose Registers](#general-purpose-registers-1)
- [**RAX**](#rax)  
- [**RBX**](#rbx)  
- [**RCX**](#rcx)  
- [**RDX**](#rdx)  
- [**RSI**](#rsi)  
- [**RDI**](#rdi)  
- [**RBP**](#rbp)  
- [**RSP**](#rsp)  
- [**RIP**](#rip)  
- [**R8**](#r8)  
- [**R9**](#r9)  
- [**R10**](#r10)  
- [**R11**](#r11)  
- [**R12**](#r12)  
- [**R13**](#r13)  
- [**R14**](#r14)  
- [**R15**](#r15)

### [Extended Versions of 32-bit Registers](#extended-versions-of-32-bit-registers-lower-32-bits)
- **EAX** → **RAX**  
- **EBX** → **RBX**  
- **ECX** → **RCX**  
- **EDX** → **RDX**  
- **ESI** → **RSI**  
- **EDI** → **RDI**  
- **EBP** → **RBP**  
- **ESP** → **RSP**  
- **EIP** → **RIP**  

### [Segment Registers](#segment-registers-1)
- **CS** (Code Segment)  
- **DS** (Data Segment)  
- **SS** (Stack Segment)  
- **ES** (Extra Segment)  
- **FS**  
- **GS**  

### [Flags Register](#flags-register-1)
- **RFLAGS** (64-bit equivalent of FLAGS)

---

## [Special Purpose Registers](#special-purpose-registers)
- **CR0** - Control Register 0  
- **CR1** - Control Register 1  
- **CR2** - Control Register 2  
- **CR3** - Control Register 3  
- **CR4** - Control Register 4  
- **GDTR** - Global Descriptor Table Register  
- **IDTR** - Interrupt Descriptor Table Register  
- **LDTR** - Local Descriptor Table Register  
- **TR** - Task Register  

---

## [Notes](#notes)
- **R8** to **R15** are only available in the 64-bit architecture (x86-64).
- **EAX, EBX, ECX, etc.** are still present in the 64-bit architecture but refer to the lower 32 bits of the corresponding 64-bit registers.

---

## Register Descriptions

### [EAX](#eax)
- The **EAX** register is used as an accumulator for arithmetic and logic operations, as well as for storing the return value of functions in x86.

### [EBX](#ebx)
- The **EBX** register is used as a base pointer for memory addressing in various instructions and also stores intermediate values.

### [ECX](#ecx)
- The **ECX** register is used for counting loops and shifts, and serves as a counter for instructions like `LOOP` and `REP`.

### [EDX](#edx)
- The **EDX** register is used for extended data in certain arithmetic operations and can hold the higher part of a result in some operations, such as division.

### [ESI](#esi)
- The **ESI** register is typically used for string operations, such as addressing a source in `MOVSB` or `CMPSB` instructions.

### [EDI](#edi)
- The **EDI** register is often used as the destination index in string operations and memory copy functions.

### [EBP](#ebp)
- The **EBP** register is used as the base pointer for stack frames and local variables within function calls.

### [ESP](#esp)
- The **ESP** register points to the top of the stack and is automatically adjusted when data is pushed or popped from the stack.

### [EIP](#eip)
- The **EIP** register stores the instruction pointer, which points to the next instruction to be executed.

### [RAX](#rax)
- **RAX** is the 64-bit extension of **EAX** and is used for general-purpose arithmetic, function return values, and system calls.

### [RBX](#rbx)
- **RBX** is the 64-bit extension of **EBX**, used for base addressing and intermediate values.

### [RCX](#rcx)
- **RCX** is the 64-bit extension of **ECX** and is used as a counter in loops and for string operations.

### [RDX](#rdx)
- **RDX** is the 64-bit extension of **EDX**, and is used in arithmetic and holds the higher part of certain results (like multiplication or division).

### [RSI](#rsi)
- **RSI** is the 64-bit extension of **ESI**, used for source indexing in string operations.

### [RDI](#rdi)
- **RDI** is the 64-bit extension of **EDI**, used for destination indexing in string operations.

### [RBP](#rbp)
- **RBP** is the 64-bit extension of **EBP**, used for stack frames in function calls.

### [RSP](#rsp)
- **RSP** is the 64-bit extension of **ESP**, pointing to the top of the stack.

### [RIP](#rip)
- **RIP** holds the instruction pointer for the 64-bit architecture, pointing to the next instruction.

### [R8-R15](#r8-r15)
- Registers **R8** through **R15** are available only in 64-bit mode and are used for general-purpose storage, additional counters, and specific operations.

