# **🔹 `objdump` Command: Full Detail & Usage**

`objdump` is a powerful tool for analyzing **ELF (Linux) and PE (Windows) binaries**. It helps inspect **assembly instructions, symbols, headers, sections, relocations, debugging information, and more**.

---

## **🔹 Basic Syntax**

```sh
objdump [OPTIONS] <binary>
```

- `<binary>` → The executable, object file, or library to inspect.
- `[OPTIONS]` → Various flags to control output.

---

## **🔹 Commonly Used Options**

| **Option**                         | **Description**                                                    |
| ---------------------------------- | ------------------------------------------------------------------ |
| `-h`                               | Displays the **section headers** (similar to `readelf -S`).        |
| `-x`                               | Displays **all headers** (like `readelf -a`).                      |
| `-s`                               | Dumps the **full content** of all sections in hexadecimal.         |
| `-d`                               | Disassembles **only executable sections** into assembly code.      |
| `-D`                               | Disassembles **entire** binary, including non-executable sections. |
| `-t`                               | Displays the **symbol table** (like `nm` command).                 |
| `-r`                               | Displays **relocation entries**.                                   |
| `-p`                               | Displays the **private headers** of an object file.                |
| `-g`                               | Displays **debugging information**.                                |
| `-j <section>`                     | Dumps only a **specific section** (e.g., `.text`, `.data`).        |
| `--dynamic-syms`                   | Shows **dynamic symbols** (like `readelf --dyn-syms`).             |
| `--disassembler-options=<options>` | Controls **disassembly style**, like **Intel syntax**.             |
| `-M intel`                         | Uses **Intel syntax** for assembly instead of AT&T.                |
| `--start-address=<addr>`           | Start disassembly at a **specific address**.                       |
| `--stop-address=<addr>`            | Stop disassembly at a **specific address**.                        |

---

## **🔹 Examples & Output**

### **1️⃣ View Section Headers (`-h`)**

```sh
objdump -h ./binary
```

#### **📝 Output**

```
Sections:
Idx Name      Size     VMA       LMA       File off  Algn
  0 .text     000000d4  08049000  08049000  00001000  2**4
  1 .data     00000004  0804a000  0804a000  00002000  2**2
  2 .bss      00000008  0804b000  0804b000  00003000  2**2
```

📌 **Explanation**:

- **`.text`** → Contains executable code.
- **`.data`** → Stores initialized global variables.
- **`.bss`** → Stores uninitialized global variables.

---

### **2️⃣ Disassemble Executable Code (`-d`)**

```sh
objdump -d ./binary
```

#### **📝 Output**

```
08049000 <main>:
  8049000: 55                 push   %ebp
  8049001: 89 e5              mov    %esp,%ebp
  8049003: 83 ec 08           sub    $0x8,%esp
  8049006: c9                 leave
  8049007: c3                 ret
```

📌 **Explanation**:

- Shows the **assembly instructions** for executable sections.
- The function **main()** starts at `0x08049000`.
- The instruction **`push %ebp`** sets up a stack frame.

---

### **3️⃣ Full Disassembly (`-D`)**

```sh
objdump -D ./binary
```

📌 **Difference from `-d`** → **Disassembles all sections**, not just executable ones.

---

### **4️⃣ Use Intel Syntax (`-M intel`)**

```sh
objdump -d -M intel ./binary
```

#### **📝 Output**

```
08049000 <main>:
  8049000: 55                    push   ebp
  8049001: 89 e5                 mov    ebp, esp
  8049003: 83 ec 08              sub    esp, 8
  8049006: c9                    leave
  8049007: c3                    ret
```

📌 **Why?**

- Default syntax is **AT&T**, but Intel is easier to read for many.

---

### **5️⃣ Dump Symbol Table (`-t`)**

```sh
objdump -t ./binary
```

#### **📝 Output**

```
00000000 l    d  .text  00000000 .text
08049000 g    F .text  0000002a main
0804a000 g    O .data  00000004 global_var
```

📌 **Explanation**:

- `g` = Global symbol.
- `F` = Function.
- `O` = Object (variable).
- `main()` is at address **`0x08049000`**.

---

### **6️⃣ Dump Dynamic Symbols (`--dynamic-syms`)**

```sh
objdump --dynamic-syms ./binary
```

#### **📝 Output**

```
00000000  w   D  *UND*  00000000  printf
0804a000  g   D  .bss   00000008  global_var
```

📌 **Useful for:**

- Finding **imported functions** (like `printf`).
- Locating dynamically linked symbols.

---

### **7️⃣ Dump Full Hexadecimal Data (`-s`)**

```sh
objdump -s ./binary
```

📌 **Useful for:**

- Viewing raw **hex dump** of sections.

---

### **8️⃣ View Relocations (`-r`)**

```sh
objdump -r ./binary
```

📌 **Useful for:**

- Checking if the binary uses **Position-Independent Code (PIC)**.

---

### **9️⃣ Extract Entry Point**

```sh
objdump -x ./binary | grep "Entry"
```

📌 **Useful for:**

- Finding where the **program starts execution**.

---

## **🔹 `objdump` vs. `readelf`**

| **Feature**             | **objdump**         | **readelf**             |
| ----------------------- | ------------------- | ----------------------- |
| Disassemble Code        | ✅ Yes (`-d`, `-D`) | ❌ No                   |
| Display ELF Headers     | ✅ Yes (`-x`)       | ✅ Yes (`-h`, `-S`)     |
| Display Symbol Table    | ✅ Yes (`-t`)       | ✅ Yes (`-s`)           |
| Display Relocations     | ✅ Yes (`-r`)       | ✅ Yes (`-r`)           |
| Show Debug Info         | ✅ Yes (`-g`)       | ✅ Yes (`--debug-dump`) |
| Faster for ELF Analysis | ❌ Slower           | ✅ Faster               |

📌 **Use `objdump`** when analyzing **assembly code** or debugging a binary.  
📌 **Use `readelf`** when inspecting **headers, sections, and symbols**.

---

## **🔹 Conclusion**

### **💡 Must-Know Commands**

```sh
objdump -h binary         # Show section headers
objdump -x binary         # Show all headers
objdump -d binary         # Disassemble executable code
objdump -D binary         # Disassemble entire binary
objdump -t binary         # Show symbol table
objdump -s binary         # Show raw data (hex dump)
objdump -r binary         # Show relocations
objdump --dynamic-syms binary  # Show dynamic symbols
```

`objdump` is an essential tool for **reverse engineering, exploit development, and debugging**. 🚀
