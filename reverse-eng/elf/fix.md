- ## `sh_addralign`:

  `sh_addralign` defines **alignment constraints** for a section in an ELF file. If a section contains data that requires a specific memory alignment (e.g., doublewords, words, or bytes), the system ensures that the section’s **memory address (`sh_addr`) is properly aligned**.

  ***
  - The **value of `sh_addr` must be a multiple of `sh_addralign`**.
  - Mathematically:

    sh_addr mod sh_addralign = 0

  - Only **0 or positive powers of 2** (e.g., 1, 2, 4, 8, 16, ...) are allowed.

  ***

  ### **What Happens at Runtime?**

  - The OS **ensures** that the section is **placed at a memory address that follows alignment rules**.
  - If the alignment is incorrect, it can cause **performance issues or crashes**.

  ***

  ### **Examples**

  #### **Case 1: No Alignment Constraints (`sh_addralign = 0 or 1`)**

  - The section can be placed **anywhere in memory**.
  - Example: A section with **byte** (char) data doesn’t need strict alignment.

  #### **Case 2: Word-Aligned (`sh_addralign = 4`)**

  - The section’s address (`sh_addr`) must be **a multiple of 4**.
  - Example: A section containing `int` (4-byte values).

  #### **Case 3: Doubleword-Aligned (`sh_addralign = 8`)**

  - The section’s address (`sh_addr`) must be **a multiple of 8**.
  - Example: A section containing `double` (8-byte values).

  ***

  ### **Real ELF Example (`readelf` Output)**

  ```sh
  readelf -S my_binary
  ```

  #### **Output**

  ```
   [Nr] Name     Type     Addr     Off    Size   ES Flg Lk Inf Al
   [ 1] .text    PROGBITS 08048000 001000 000100 00 AX  0   0  16
   [ 2] .data    PROGBITS 08049000 002000 000080 00 WA  0   0  8
  ```

  - `.text` (code section) has `sh_addralign = 16`, meaning its address **must be a multiple of 16**.
  - `.data` (global variables) has `sh_addralign = 8`, meaning it must be **aligned to 8**.

  ***

  ### **Why Is This Important?**

  1.  **Performance**: Misaligned memory accesses can be **slow** or even **crash** on some CPUs.
  2.  **Correctness**: Some architectures **require strict alignment** (e.g., ARM, RISC-V).
  3.  **Memory Layout**: Ensures that the binary’s sections are loaded **at the right addresses**.

  ***

  ### **Conclusion**

  ✅ **`sh_addralign` forces a section to start at a specific memory address multiple**.  
   ✅ **The OS and loader handle this automatically**.  
   ✅ **Use powers of 2 to avoid issues** (1, 2, 4, 8, 16, ...).
