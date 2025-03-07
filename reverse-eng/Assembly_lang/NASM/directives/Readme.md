# directives

**directives** are commands that provide instructions to the assembler about how to process the assembly code. These directives do not directly correspond to machine instructions that the CPU will execute. Instead, they guide the assembler on how to assemble the program, define memory spaces, initialize data, or set various conditions required for the assembly process.

### Key Points:
- **Assembler Instructions vs Directives**: While assembler instructions (e.g., `MOV`, `ADD`, `SUB`) generate machine code that the CPU will execute, directives are used to control the assembly process but do not generate machine code directly.
- **Purpose**: Directives help in setting up data, organizing code sections, managing memory allocation, and providing other helpful configurations for the assembly program.

### Common Directives in NASM (Netwide Assembler):

1. **`section`**:
   - Defines a segment or section of the code, such as `.text`, `.data`, `.bss`, etc.
   - It tells the assembler where to place the instructions or data.
   ```nasm
   section .data
       message db "Hello, World!", 0   ; data section for defining variables
   section .text
       ; code section
   ```

2. **`db` (Define Byte)**:
   - Allocates one or more bytes in memory and initializes them with a specified value.
   ```nasm
   db 0x1, 0x2, 0x3   ; Defines three bytes: 0x1, 0x2, 0x3
   ```

3. **`dw` (Define Word)**:
   - Allocates space for a 16-bit (2-byte) word and initializes it with a specified value.
   ```nasm
   dw 1234h   ; Defines a 16-bit word with value 0x1234
   ```

<br>

- `note` : In the context of assembly language, the term "word" refers to a specific unit of data storage, typically consisting of a fixed number of bits, depending on the architecture of the system. 


<br>

4. **`dd` (Define Double Word)**:
   - Allocates space for a 32-bit (4-byte) word and initializes it with a specified value.
   ```nasm
   dd 0x12345678   ; Defines a 32-bit value with 0x12345678
   ```

5. **`dq` (Define Quad Word)**:
   - Allocates space for an 8-byte value and initializes it with a specified value.
   ```nasm
   dq 12345678901234h   ; Defines an 8-byte value
   ```

6. **`equ` (Equate)**:
   - Defines a constant value (or symbol) that can be used later in the program.
   ```nasm
   MAX_VALUE equ 100    ; Defines a constant called MAX_VALUE with the value 100
   ```

7. **`global`**:
   - Declares a symbol as global, making it accessible from other files or parts of the program.
   ```nasm
   global _start   ; Exposes the symbol _start to be accessible externally
   ```

8. **`extern`**:
   - Declares a symbol that is defined externally (i.e., outside the current file).
   ```nasm
   extern printf   ; Declares that the `printf` function is external
   ```

9. **`resb`, `resw`, `resd`, `resq`**:
   - These directives reserve uninitialized memory space:
     - `resb` reserves a byte.
     - `resw` reserves a word (2 bytes).
     - `resd` reserves a double word (4 bytes).
     - `resq` reserves a quad word (8 bytes).
   ```nasm
   resb 10    ; Reserves 10 bytes of space
   resd 5     ; Reserves 5 double words (20 bytes)
   ```

10. **`align`**:
    - Aligns the memory address to a specified boundary (e.g., 16-byte, 32-byte).
    ```nasm
    align 4    ; Aligns the next data or code on a 4-byte boundary
    ```

11. **`times`**:
    - Repeats a specified value or instruction a number of times.
    ```nasm
    times 10 db 0   ; Defines 10 bytes initialized to 0
    ```

12. **`if`/`else`/`endif`**:
    - Conditional directives for conditional assembly.
    ```nasm
    %if SOME_CONDITION
        ; Code to be included if condition is true
    %else
        ; Code to be included if condition is false
    %endif
    ```

13. **`macro`**:
    - Defines a macro (a reusable sequence of instructions).
    ```nasm
    %macro add_two_numbers 2
        add eax, [esp+4]
        add eax, [esp+8]
    %endmacro
    ```

### Summary:
- **Directives** are instructions to the assembler, helping control various aspects of assembly code such as memory allocation, defining constants, and organizing code into sections.
- They do not directly translate to machine code, but guide how the assembler should process and organize the source code.
