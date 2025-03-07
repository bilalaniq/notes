### **🔍 `readelf` - ELF File Analyzer (Linux Binaries)**

`readelf` is a command-line tool used for inspecting **ELF (Executable and Linkable Format) files**, commonly found in **Linux executables, shared libraries, and object files**. Unlike `objdump`, it **does not require debug symbols** and works directly on ELF files.

---

## **📌 Basic Usage**

```sh
readelf [options] binary_name
```

- `readelf` provides **detailed information** about ELF files, including **headers, symbols, sections, dynamic linking info, and relocations**.
- Works with **executables, shared libraries (`.so`), and object files (`.o`)**.

Here’s a **one-line explanation** of each `readelf` option:

---

### **🔹 Basic ELF Information**

| **Command**         | **Description**                                        |
| ------------------- | ------------------------------------------------------ |
| `readelf -h binary` | Show ELF **header** (architecture, entry point, etc.). |
| `readelf -e binary` | Equivalent to `-h -l -S`, shows **all headers**.       |
| `readelf -l binary` | Show **program headers** (segments, memory layout).    |
| `readelf -S binary` | Show **section headers** (text, data, bss, symbols).   |
| `readelf -g binary` | Show **section groups** (related sections).            |
| `readelf -t binary` | Show **detailed section info**.                        |

---

### **🔹 Symbols & Debugging**

| **Command**                 | **Description**                                        |
| --------------------------- | ------------------------------------------------------ |
| `readelf -s binary`         | Show **symbol table** (functions, variables).          |
| `readelf --dyn-syms binary` | Show **dynamic symbols** (imported functions).         |
| `readelf -u binary`         | Show **unwind info** (stack unwinding for exceptions). |
| `readelf -w binary`         | Dump **debugging info** (DWARF, if available).         |
| `readelf -n binary`         | Show **notes** (metadata, build ID).                   |
| `readelf -x <section>`      | Show **hex dump** of a section.                        |
| `readelf -p <section>`      | Show **string dump** of a section.                     |

---

### **🔹 Relocations & Linking**

| **Command**         | **Description**                                         |
| ------------------- | ------------------------------------------------------- |
| `readelf -r binary` | Show **relocations** (addresses modified at runtime).   |
| `readelf -d binary` | Show **dynamic linking info** (shared libraries).       |
| `readelf -D binary` | Use **dynamic symbol table**.                           |
| `readelf -A binary` | Show **architecture-specific details**.                 |
| `readelf -V binary` | Show **version info** (symbol versions in shared libs). |

---

### **🔹 Miscellaneous**

| **Command**         | **Description**                                |
| ------------------- | ---------------------------------------------- |
| `readelf -c binary` | Show **archive index** (for `.a` static libs). |
| `readelf -I binary` | Show **histogram of dynamic symbols**.         |
| `readelf -L binary` | Perform **extra checks for errors**.           |
| `readelf -H`        | Show **help** (all options).                   |
| `readelf -v`        | Show **version info**.                         |

---

### **🔹 Advanced Debugging**

`readelf --sym-base=[0    | 8          | 10  | 16]` Change **symbol address format**.
`readelf --demangle` **Decode C++ symbols** (readable function names).
`readelf --recurse-limit` Limit recursion in **debug info**.  
 `readelf --wide` Print **full width output** (no line truncation).

---

### **🔥 Quick Summary**

For **basic analysis**, use:

```sh
readelf -h -l -S binary
```

For **symbols & functions**, use:

```sh
readelf -s binary
```

For **shared library dependencies**, use:

```sh
readelf -d binary
```

For **relocations & exploit dev**, use:

```sh
readelf -r binary
```

For **debugging symbols**, use:

```sh
readelf -w binary
```
