# ELF

**ELF** stands for **Executable and Linkable Format**, and it is a common standard file format for executables, object code, shared libraries, and core dumps. ELF is primarily used on Unix-based systems, including Linux, but it is also supported by other operating systems like Solaris, BSD, and others.

### ELF Overview

ELF was designed to be flexible, extensible, and platform-independent, providing a unified file format for various types of executables. It is used by operating systems to execute programs, link shared libraries, and manage core dumps for debugging.

### Structure of an ELF File

before learning abourt the structure of elf file you should also know about `/usr/include/elf.h` click [here](./elf.md)

An ELF file is divided into several key sections, each serving a different purpose. The general structure of an ELF file includes:

1. **ELF Header**:

   - The ELF header provides basic information about the file. It tells the system how to interpret the file and contains information such as the target architecture, endianness, and entry point (the address where the program starts executing).

2. **Program Header Table**:

   - The program header defines how the program's segments are loaded into memory. A program segment typically contains code and data that the system loads into memory for execution.

3. **Section Header Table**:

   - The section header table describes sections of the ELF file, which can contain data like symbol tables, string tables, debug information, and code (text section). Sections are used by tools (like linkers and debuggers) to handle and manipulate different parts of the file.

4. **Sections**:
   ELF files contain different types of sections, which may include:

   - **Text Section**: Contains the executable code of the program.
   - **Data Section**: Contains initialized global and static variables.
   - **BSS Section**: Contains uninitialized global and static variables (it is not stored in the file itself; it is initialized to zero when the program starts).
   - **String Table**: Contains strings used by the program, such as function names or variable names.
   - **Symbol Table**: Contains information about functions and variables that are used by the program, including external symbols (for dynamic linking).
   - **Relocation Section**: Contains information used to adjust addresses in the program when it is loaded into memory.

5. **Program Segments**:

   - A program segment is a contiguous region of memory containing executable code or data. Segments are directly related to how the operating system loads the program into memory. There are several types of segments:
     - **Code Segment**: Contains the machine code that is executed.
     - **Data Segment**: Contains data that is used by the program.
     - **Stack Segment**: Used for function call management and local variables.
     - **Heap Segment**: Used for dynamic memory allocation during the program's execution.

6. **Dynamic Section** (for shared libraries and dynamic linking):
   - The dynamic section contains information that is needed for dynamic linking. It includes the names of shared libraries the program depends on, relocation entries, and symbols that need to be resolved at runtime.

### Types of ELF Files

There are different types of ELF files, based on their intended use. They include:

1. **Executable File**:

   - An ELF executable contains machine code ready to be executed by the operating system. It includes all the necessary code and data to run the program.

2. **Object File**:

   - An ELF object file is an intermediate file produced by a compiler. It contains code and data, but it cannot be directly executed. It is usually linked with other object files to form an executable or shared library.

3. **Shared Object (SO) File**:

   - ELF shared objects are dynamic libraries that can be linked to other programs at runtime. These files are often used to reduce duplication of common code (e.g., libraries like libc). They allow programs to load code dynamically during execution.

4. **Core Dump File**:
   - An ELF core dump is created when a program crashes. It contains a snapshot of the program’s memory at the time of the crash, which is useful for debugging. It helps developers examine the state of the program at the point of failure.

### ELF File Header

The ELF file header is the first part of the ELF file. It consists of several fields that describe the file and how to process it. Some key fields in the ELF header include:

- **e_ident**: A magic number used to identify the file as an ELF file and some additional file-specific information (e.g., architecture, endianness).
- **e_type**: The type of file (e.g., executable, shared object, relocatable).
- **e_machine**: The architecture for which the file is intended (e.g., x86, ARM).
- **e_version**: The version of the ELF format used.
- **e_entry**: The entry point address of the program (i.e., where the program starts executing).
- **e_phoff**: The offset to the program header table.
- **e_shoff**: The offset to the section header table.
- **e_flags**: Architecture-specific flags.
- **e_ehsize**: The size of the ELF header.
- **e_phentsize**: The size of a program header entry.
- **e_shentsize**: The size of a section header entry.

### Program Header Table

The program header table describes how to create processes (programs) from the ELF file. Each entry in this table describes a segment in the ELF file and contains information about how it should be loaded into memory. For example:

- **p_type**: The type of the segment (e.g., loadable, dynamic).
- **p_offset**: The offset where the segment starts in the file.
- **p_vaddr**: The virtual address where the segment should be loaded in memory.
- **p_paddr**: The physical address where the segment should be loaded (used in some architectures).
- **p_filesz**: The size of the segment in the file.
- **p_memsz**: The size of the segment in memory.
- **p_flags**: Flags describing access permissions for the segment (e.g., readable, writable, executable).
- **p_align**: The alignment of the segment in memory.

### Section Header Table

The section header table contains metadata about each section in the ELF file. Each entry in the section header table corresponds to a specific section (like `.text`, `.data`, etc.). Key fields include:

- **sh_name**: The name of the section.
- **sh_type**: The type of the section (e.g., text, data).
- **sh_flags**: Flags describing the section's properties (e.g., executable, writable).
- **sh_addr**: The address in memory where the section will be loaded.
- **sh_offset**: The offset to the section's data in the file.
- **sh_size**: The size of the section in bytes.
- **sh_link**: For some sections, this is an index to another section.
- **sh_info**: Additional information for sections.
- **sh_addralign**: The alignment requirements for the section.
- **sh_entsize**: The size of entries if the section contains a table (e.g., symbol table).

### ELF File Example

Here’s a simple example of a typical ELF file structure for a Linux executable:

1. **ELF Header**: Contains metadata about the file.
2. **Program Header Table**: Describes how to load the program into memory.
3. **Section Header Table**: Describes the sections and their locations.
4. **Sections**:
   - `.text` (contains code)
   - `.data` (contains initialized variables)
   - `.bss` (contains uninitialized variables)
   - `.rodata` (contains read-only data like strings)
   - `.symtab` (contains the symbol table)

### Conclusion

The **ELF (Executable and Linkable Format)** file format is an essential part of how modern operating systems manage executable programs, object files, dynamic libraries, and debugging information. It is highly flexible and supports various types of systems and architectures. ELF allows efficient loading, linking, and debugging of programs, which is why it is widely used in Unix-like operating systems, particularly Linux.
