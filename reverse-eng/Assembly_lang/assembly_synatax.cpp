// --------------------------------------assembly syntax---------------------------
/*
there are many types of assembly language syntaxhere are the most common ones
Assembly language syntax can vary depending on the specific assembler and architecture being used. Here's a list of some common 
assembly language syntaxes:

1. **AT&T Syntax**: 
   - Used by the GNU Assembler (GAS) and GCC inline assembly.
   - Commonly used on Unix-like systems, including Linux.
   - Features register names prefixed with `%`, and memory operands in the form `displacement(base, index, scale)`.
   - Example:
     ```assembly
     movl $10, %eax
     ```

2. **Intel Syntax**:
   - Commonly used on Windows platforms and by some assemblers like NASM.
   - Features register names without prefix, immediate values used directly, and memory operands in the form `[address]`.
   - Example:
     ```assembly
     mov eax, 10
     ```

3. **MASM Syntax** (Microsoft Macro Assembler Syntax):
   - Used by Microsoft's MASM assembler.
   - Similar to Intel syntax but with some differences in syntax and directives.
   - Widely used for Windows development.
   - Example:
     ```assembly
     mov eax, 10
     ```

4. **NASM Syntax** (Netwide Assembler Syntax):
   - Commonly used on various platforms including Linux, macOS, and Windows.
   - Similar to Intel syntax but with more flexibility and additional features.
   - Example:
     ```assembly
     mov eax, 10
     ```

5. **Gas Syntax**:
   - Similar to AT&T syntax but with some differences.
   - Used by the GNU Assembler (GAS).
   - Commonly used on Unix-like systems, including Linux.
   - Example:
     ```assembly
     movl $10, %eax
     ```

6. **ARM Assembly Syntax**:
   - Specific to ARM architecture.
   - Syntax varies depending on the ARM assembler being used.
   - Example:
     ```assembly
     MOV R0, #10
     ```

7. **SPARC Assembly Syntax**:
   - Specific to SPARC architecture.
   - Syntax varies depending on the SPARC assembler being used.
   - Example:
     ```assembly
     mov 10, %o0
     ```

These are some of the most commonly encountered assembly language syntaxes, but there may be others depending on the specific 
architecture or assembler being used. Each syntax has its own conventions and features, so the choice of syntax often depends on 
personal preference, project requirements, or platform conventions.



if you want to convert assembly syntax in linux from AT&T Syntax to intel Syntax use this code
gcc -S -masm=intel [cpp file] 
where the -S is used to out put the assembly code the out put will be output.s where the .s extention is used for an assemblly language 
file and where -masm=intel

but in this command the terminal convert the AT&T assemblly lanuage to intel

*/