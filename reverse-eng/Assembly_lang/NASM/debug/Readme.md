For **NASM (Netwide Assembler)**, the key **debugging formats** that are supported are:

### Debugging Formats for NASM:

1. **DWARF**
   - **Purpose**: The **DWARF** format is the most common debugging format when using **NASM**. It provides detailed debugging information that helps debuggers like **GDB** map the assembly code to the original source code.
   - **Usage**: You can use the `-g` flag in **NASM** to include DWARF debugging information when assembling code. This is commonly used for Linux-based development.
   - **Example**: 
     ```bash
     nasm -g dwarf -f elf64 program.asm
     ```
   - **Supported Platforms**: Primarily used on **Linux** and other Unix-like systems.

2. **STABS**
   - **Purpose**: **STABS** is an older format for debugging and is supported by **NASM** but is less commonly used today. It is primarily used for older Unix systems.
   - **Usage**: It can also be generated by **NASM** using the `-g` flag but is less popular now, as DWARF has become the preferred format.
   - **Supported Platforms**: Used mainly on **Unix-like systems** in legacy codebases.