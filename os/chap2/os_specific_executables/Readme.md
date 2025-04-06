# **Why Applications Are Operating-System Specific**

### ➤ Core Problem:

When you **compile** a program, the compiler generates **binary machine code** that's:

- Tied to a specific **CPU architecture** (e.g., x86, ARM)
- Uses a specific **binary file format** (e.g., ELF, PE, Mach-O)
- Depends on **system calls** and **APIs** provided by the target **operating system**

So, a program built for Linux on x86 will almost certainly **not** work on:

- Windows (different OS, system calls, and binary format)
- ARM Linux (same OS but different CPU architecture)
- macOS (different OS and binary format)

---

## 🔹 Why is it So Hard to Make Applications Cross-Platform?

There are **several deep technical reasons**:

---

### 1. System Calls Are Different

**System calls** are the low-level functions the OS provides to do basic things:

- Create files
- Allocate memory
- Open sockets
- Spawn processes

Each OS has:

- Different **names** and **numbers** for these calls
- Different ways of **passing parameters**
- Different **semantics** (how the system call behaves)

So even if your code says `create_file()`, the actual system call made under the hood is **OS-specific**, like `CreateFile` on Windows vs `open()` on Linux.

---

### 2. Different File and Binary Formats

Each OS expects binary executables in a **different format**:

| OS      | Format | Description                    |
| ------- | ------ | ------------------------------ |
| Linux   | ELF    | Executable and Linkable Format |
| Windows | PE     | Portable Executable            |
| macOS   | Mach-O | Mach Object                    |

These define:

- File layout (headers, sections)
- Entry point (where to start execution)
- Location of code/data
- Symbol and relocation information

A Windows PE file cannot be loaded and understood by the Linux loader.

---

### 3. CPU Instruction Sets Vary

A binary compiled for:

- **x86 (Intel/AMD)** won't run on
- **ARM (used in most phones)**

Different CPUs:

- Use different instructions
- Have different register names and layouts
- Handle function calls, memory, and stack differently

Even if the OS were the same (e.g., Linux), binaries are incompatible across CPU types.

---

### 4. APIs Are Not the Same

Every OS provides different **application programming interfaces (APIs)**, especially for:

- GUI (Graphical User Interface)
- Networking
- File systems
- Security

For example:

- An app that uses `UIKit` from iOS won’t work on Android which uses `Jetpack` or `Compose`.

---

## How Do Some Apps Run on Multiple OSes?

Despite these differences, some apps _do_ work across platforms. How?

Here are the **three main strategies**:

---

### 1. **Interpreted Languages** (e.g., Python, Ruby)

- You write the app in a language that is **not compiled**, but instead **interpreted at runtime**.
- The **interpreter** (like `python.exe`) is installed on each OS.
- The interpreter handles:
  - Reading the code
  - Executing instructions
  - Making system calls in the way that OS understands

✔ Pros:

- Easy portability
- One source code runs anywhere

✘ Cons:

- Slower performance
- Limited access to system-specific features

---

### ✅ 2. **Virtual Machines & RTEs** (e.g., Java, C#)

- The app is compiled to **intermediate code** (e.g., Java bytecode)
- This runs on a **virtual machine** (e.g., JVM, CLR)
- The **VM handles translation** to actual OS system calls and CPU instructions

✔ Pros:

- High portability
- Better performance than interpreters
- Same app can run on Windows, Linux, macOS, Android (with the right VM)

✘ Cons:

- Still not “native”
- You must have the correct VM installed
- Slightly less efficient than compiled native code

---

### ✅ 3. **Porting with APIs & Cross-Platform Libraries**

- Code is written in a language like C or C++, but uses **standard APIs** like POSIX
- Compiler generates **native code** for each platform
- You compile the same source on each platform (this is **porting**)

✔ Pros:

- Best performance (native code)
- Full access to system features

✘ Cons:

- Time-consuming
- Need to compile/test/debug for each OS
- Might need to change parts of the code to adapt to platform-specific APIs

---

## Standard Interfaces: API vs ABI

Let’s distinguish two terms here:

### 🔸 **API** – Application Programming Interface

- How applications talk to the **OS or libraries**
- Example: `fopen()`, `read()`, `printf()`
- Defined in **source code**

### 🔸 **ABI** – Application Binary Interface

- How **compiled code** interfaces at the **binary level**
- Defines:

  - Data type sizes
  - Register usage
  - System call conventions
  - Stack organization

- ABIs are **architecture-specific**. For example:
  - ARMv8 ABI
  - x86-64 ABI

Even if two OSes both use the ELF format and follow the same ABI, that **does not mean** the binary will run on both unless the rest of the environment is identical.

| Feature                    | **API (Application Programming Interface)**                                       | **ABI (Application Binary Interface)**                                    |
| -------------------------- | --------------------------------------------------------------------------------- | ------------------------------------------------------------------------- |
| **Definition**             | Interface for source-level communication between application and system/libraries | Interface for binary-level communication between compiled code and system |
| **Level of Operation**     | Source code level                                                                 | Machine/binary code level                                                 |
| **Used By**                | Programmers writing application code                                              | Compilers, linkers, OS, and CPU architecture                              |
| **Purpose**                | Defines _what_ functions, classes, or services are available                      | Defines _how_ data and functions are represented and accessed at runtime  |
| **Includes**               | Function names, arguments, return types, constants, structures                    | Calling conventions, register usage, data type sizes, stack layout        |
| **Portability**            | Code using standard APIs (e.g., POSIX) can be recompiled for different OSes       | Binary compiled for one ABI may not run on systems with different ABIs    |
| **Example**                | `printf()`, `fopen()`, `socket()` in C standard/POSIX library                     | x86-64 System V ABI, ARMv8 ABI                                            |
| **Stability Importance**   | Allows consistent software development across OS versions                         | Ensures binary compatibility across OS and compiler versions              |
| **Changes Affect**         | May require **code changes and recompilation**                                    | May break **binary compatibility**, even without source changes           |
| **Documentation Audience** | Application developers                                                            | Compiler/toolchain developers, OS kernel developers                       |

---

## Final Summary

| Challenge                   | Why It Matters                                                   |
| --------------------------- | ---------------------------------------------------------------- |
| Different system calls      | Programs expect different services in different ways             |
| Binary formats vary         | OS loaders can’t understand foreign binaries                     |
| CPUs use different code     | Binary for one CPU won’t run on another                          |
| APIs are OS-specific        | GUI, file access, and networking differ                          |
| ABIs define low-level rules | Even binaries using same format (like ELF) may not be compatible |

✔ To make software cross-platform:

- Use interpreters or VMs
- Use standardized APIs (like POSIX)
- Be prepared to recompile and adjust code for each OS/architecture
