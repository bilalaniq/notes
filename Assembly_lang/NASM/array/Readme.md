### Example: Array in Assembly

```nasm
section .data
    ; Define an array of 5 integers (4 bytes each)
    array dd 10, 20, 30, 40, 50  ; dd = define double word (4 bytes)
    array_size equ ($ - array) / 4  ; Calculate the number of elements in the array

    ; $: The symbol $ represents the current address or location in the code, which is the "current position" or
    ;"current offset" at that point in the program.

section .text
    global _start

_start:
    ; Example: Access and modify array elements

    ; Load the base address of the array into ESI
    mov esi, array

    ; Access the first element (array[0])
    mov eax, [esi]  ; eax = 10

    ; Access the second element (array[1])
    mov ebx, [esi + 4]  ; ebx = 20

    ; Modify the third element (array[2] = 100)
    mov dword [esi + 8], 100  ; array[2] = 100

    ; Loop through the array and print each element (for demonstration purposes)
    mov ecx, array_size  ; Number of elements in the array
    mov esi, array       ; Base address of the array

print_loop:
    ; Load the current element into EAX
    mov eax, [esi]

    ; Print the value (this is just a placeholder; actual printing requires syscalls)
    ; For example, you can use `printf` in a C wrapper or Linux syscalls.

    ; Move to the next element
    add esi, 4

    ; Decrement the loop counter
    loop print_loop

    ; Exit the program
    mov eax, 1       ; syscall: exit
    xor ebx, ebx     ; exit code 0
    int 0x80         ; invoke syscall
```

---

### Explanation of the Code

1. **Defining the Array**

   - The array is defined in the `.data` section using the `dd` (define double word) directive. Each element is 4 bytes (32 bits).
   - Example:
     ```asm
     array dd 10, 20, 30, 40, 50
     ```
     This creates an array with 5 elements: `[10, 20, 30, 40, 50]`.

2. **Calculating the Array Size**

   - The size of the array is calculated using the `$` symbol, which represents the current location counter.
   - Example:
     ```asm
     array_size equ ($ - array) / 4
     ```
     Here, `($ - array)` gives the total size of the array in bytes, and dividing by 4 gives the number of elements.

3. **Accessing Array Elements**

   - The base address of the array is loaded into a register (e.g., `esi`).
   - Elements are accessed using an offset from the base address. For example:
     ```asm
     mov eax, [esi]        ; Access array[0]
     mov ebx, [esi + 4]    ; Access array[1]
     mov dword [esi + 8], 100  ; Modify array[2]
     ```

4. **Looping Through the Array**
   - A loop is used to iterate through the array. The `loop` instruction decrements `ecx` and jumps to the specified label if `ecx` is not zero.
   - Example:
     ```asm
     mov ecx, array_size  ; Set loop counter
     mov esi, array       ; Set base address
     print_loop:
         mov eax, [esi]   ; Load current element
         add esi, 4       ; Move to the next element
         loop print_loop  ; Repeat until ecx == 0
     ```

<br>  
<br>  


- # **ecx** (Extended Count Register)

In the x86 architecture, the **`ECX`** register is a **general-purpose register** that is part of the **32-bit** register set, and it's often used for various purposes in assembly programming. Specifically, **`ECX`** is the **extended version** of the 16-bit **`CX`** register, and its use is quite flexible. Here’s an overview of `ECX` and its main uses:

### Key Facts About `ECX`:

- **Size**: `ECX` is a 32-bit register (4 bytes). The 16-bit version is `CX`, and the 8-bit versions are `CL` (lower byte) and `CH` (higher byte).
- **Purpose**: It is primarily used for:

  - **Loop counter**: `ECX` is commonly used as a counter in **loops**, especially in string operations or iteration.
  - **Shift and rotate operations**: The `ECX` register is used to specify the number of positions for bit shifts and rotations.
  - **Function argument passing**: In some calling conventions, `ECX` is used to pass arguments to functions.

- # **esi** (Extended Source Index)

esi: This is a register in the x86 architecture. Specifically, ESI stands for Extended Source Index.
It's commonly used to hold addresses for string or array operations and is often used as a pointer to an
array or a location in memory.

- # **loop**
  The LOOP instruction in x86 assembly is used to implement a looping structure. It repeats a block of code a specific number of times, based on the value in the ECX register. The LOOP instruction automatically decrements the value of ECX and, if the value of ECX is not zero, it jumps to the target label to repeat the loop. If ECX reaches zero, the loop terminates and the program continues to the next instruction after the loop.


<br>  
<br>  


5. **Exiting the Program**
   - The program exits using the `exit` syscall:
     ```asm
     mov eax, 1  ; syscall: exit
     xor ebx, ebx  ; exit code 0
     int 0x80  ; invoke syscall
     ```

---

### Assembling and Linking

1. Save the code in a file, e.g., `array.asm`.
2. Assemble the code using NASM:
   ```bash
   nasm -f elf32 -o array.o array.asm
   ```
3. Link the object file to create an executable:
   ```bash
   ld -m elf_i386 -o array array.o
   ```
4. Run the executable:
   ```bash
   ./array
   ```

---

### Notes

- The example does not include actual printing of array elements because printing in assembly requires system calls or external libraries (e.g., `printf` in a C wrapper).
- If you want to print the array elements, you can use Linux syscalls (e.g., `sys_write`) or link with a C library.
