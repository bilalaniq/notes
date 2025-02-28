# gdb

Using **GDB** to debug **assembly programs** is an incredibly useful skill, as it allows you to examine the execution of your program, check the state of registers, and inspect memory to track down errors.

Below is a detailed guide on using **GDB** to debug **assembly programs**.

---

### 1. **Preparing the Assembly Program for Debugging**

To debug assembly programs with GDB, you need to compile your program with debugging symbols using the `-g` flag.

For example, if you have an assembly program `program.asm`, you can assemble and link it using `nasm` and `gcc`:

### Assemble and Link the Program:

```bash
nasm -f elf64 -g -o program.o program.asm  # Assemble with debugging info
gcc -nostartfiles -g -o program program.o  # Link the object file with debugging info when using main

# and when using _start use

ld -o program program.o

```

- `-g`: Generates debugging symbols for the program.
- `-nostartfiles`: Tells the linker not to link against the standard C library or startup files, which is commonly used in assembly programs.

### 2. **Starting GDB for Assembly Programs**

Once you have the program compiled and linked, you can start GDB with the executable:

```bash
gdb ./program
```

GDB will open the program and allow you to start debugging.

---

### 3. **Setting Breakpoints in GDB**

You can set breakpoints at specific labels or addresses in your assembly program to stop the program's execution at that point.

- **Set a breakpoint at a label**:

  ```bash
  (gdb) break _start  # Set breakpoint at the program's entry point (e.g., _start label)
  ```

- **Set a breakpoint at a specific address** (useful in assembly):

  ```bash
  (gdb) break *0x400080  # Set breakpoint at address 0x400080
  ```

- **Set a breakpoint at a function** (e.g., `main`):
  ```bash
  (gdb) break main  # If you have a main label or function
  ```

---

### 4. **Running the Program in GDB**

To run the program inside GDB, use the `run` command:

```bash
(gdb) run
```

The program will execute until it hits the first breakpoint.

---

### 5. **Stepping Through Assembly Code**

Once the breakpoint is hit, you can step through your program one instruction at a time using GDB commands.

- **Step through the program one instruction**:

  ```bash
  (gdb) stepi  # Step one instruction at a time
  ```

- **Step through the program one line** (if source code is available):
  ```bash
  (gdb) next  # Step to the next line in the assembly code
  ```

---

### 6. **Inspecting Registers**

When debugging assembly programs, you often want to check the state of the **CPU registers**, as they store the current execution context of the program.

- **Show all registers**:

  ```bash
  (gdb) info registers  # Display all the CPU registers and their values
  ```

- **Show the value of a specific register**:
  ```bash
  (gdb) print $rax  # Show the value of the RAX register
  ```

Registers like **RAX**, **RBX**, **RCX**, etc., store data and control information during the program's execution.

---

### 7. **Inspecting Memory**

You can inspect the contents of memory to understand how data is being manipulated.

- **Examine memory at a specific address**:

  ```bash
  (gdb) x/10gx 0x601000  # Examine 10 quadwords (8 bytes) starting at address 0x601000
  ```

- **Examine a specific variable in memory**:
  ```bash
  (gdb) x/4b &var  # Examine 4 bytes of the variable `var` in memory
  ```

---

### 8. **Modifying Registers and Memory**

While debugging, you can modify registers and memory to experiment with different behaviors.

- **Set a register value**:

  ```bash
  (gdb) set $rax = 42  # Set the value of the RAX register to 42
  ```

- **Modify memory at a specific address**:

  ```bash
  (gdb) set {int}0x601000 = 42  # Set the value at address 0x601000 to 42
  ```

- **Set a value at a specific address**:
  ```bash
  (gdb) set {char}0x601000 = 0x41  # Set the value at address 0x601000 to 0x41 (ASCII 'A')
  ```

---

### 9. **Viewing the Stack**

In assembly, the stack is particularly important for function calls and local variables. You can inspect the stack to understand the current execution context.

- **View the call stack**:

  ```bash
  (gdb) backtrace  # Show the current call stack
  ```

- **View the stack from a specific address**:

  ```bash
  (gdb) x/20x $rsp  # Examine 20 words (4 bytes each) from the current stack pointer (RSP)
  ```

- **View the contents of the stack**:
  ```bash
  (gdb) info stack  # Show the stack contents
  ```

---

### 10. **Listing Source Code in GDB**

If you have the source code available (from the `-g` flag), you can list the assembly code in GDB.

- **List source code around the current execution point**:

  ```bash
  (gdb) list
  ```

- **List source code at a specific line or function**:
  ```bash
  (gdb) list 20  # List 20 lines of assembly code around the current line
  ```

---

### 11. **Exiting GDB**

Once you’re done with debugging, you can exit GDB:

```bash
(gdb) quit
```

---



# Examining memory with gdb 


