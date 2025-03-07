### **ELF Interpreter (`ld-linux.so`) & PE Loader (`ntdll.dll`)**

---

## **🔹 Linux: ELF Interpreter (`ld-linux.so`)**

In **Linux**, dynamically linked executables require an **interpreter** to load shared libraries and resolve symbols before execution begins. This role is handled by **`ld-linux.so`**.

### **1️⃣ What is `ld-linux.so`?**

`ld-linux.so` (Dynamic Linker/Loader) is a **shared object** (`.so`) responsible for:  
✔️ Loading and linking **shared libraries** (`libc.so`, `libm.so`, etc.).  
✔️ Resolving **symbols** for dynamically linked functions.  
✔️ Setting up the **runtime environment** for the process.

**`ld-linux.so`** does perform **memory mapping**,

### **🔹 Memory Mapping by `ld-linux.so`**

When a **dynamically linked ELF binary** is executed, `ld-linux.so`:
1️⃣ **Maps the executable into memory** (via `mmap()`).  
2️⃣ **Maps shared libraries** (`libc.so.6`, `libm.so`, etc.) into the process’s address space.  
3️⃣ **Resolves symbols** (e.g., function addresses) using **GOT (Global Offset Table)** and **PLT (Procedure Linkage Table)**.  
4️⃣ **Performs relocations** if necessary.  
5️⃣ **Transfers execution** to the program’s entry point.

### **🔹 How Does `ld-linux.so` Use `mmap()`?**

`ld-linux.so` calls `mmap()` to:

- Load **shared libraries** into memory.
- Allocate memory for **.text, .data, .bss, and other sections**.
- Set up memory protection (e.g., **read-only `.text`**, writable `.data`).

### **🔹 Checking Memory Mapping**

To see how `ld-linux.so` maps shared libraries:

```bash
cat /proc/$(pidof <binary>)/maps
```

Example output:

```
7f45d000-7f470000 r-xp 00000000 08:01 123456 /lib64/ld-linux-x86-64.so.2
7f470000-7f471000 r--p 00003000 08:01 123456 /lib64/ld-linux-x86-64.so.2
7f471000-7f472000 rw-p 00004000 08:01 123456 /lib64/ld-linux-x86-64.so.2
```

### **🔹 Key Takeaways**

✔ **Yes, `ld-linux.so` does memory mapping** via `mmap()`.  
✔ It also **resolves symbols, performs relocations, and sets up execution**.  
✔ **Even in static executables**, some memory-mapped regions exist (e.g., `vdso`).

### **2️⃣ Where is it Located?**

- **32-bit Systems:** `/lib/ld-linux.so.2`
- **64-bit Systems:** `/lib64/ld-linux-x86-64.so.2`

You can find the ELF interpreter used by an executable using:

```bash
ldd <binary>  # Shows linked shared libraries
readelf -l <binary> | grep 'interpreter'  # Displays interpreter path
```

### **3️⃣ How `ld-linux.so` Works?**

When a dynamically linked ELF binary is executed:  
1️⃣ The **Linux Kernel** loads the ELF **interpreter** (`ld-linux.so`) into memory.  
2️⃣ `ld-linux.so` loads **necessary shared libraries** (e.g., `libc.so.6`).  
3️⃣ It **resolves symbols** by updating **GOT (Global Offset Table)** and **PLT (Procedure Linkage Table)**.  
4️⃣ Finally, it transfers execution to the **entry point** of the executable.

### **4️⃣ Example: Execution Flow**

```bash
./my_program  # Executing a dynamically linked ELF binary
```

🔹 The **Kernel** loads `ld-linux.so`.  
🔹 `ld-linux.so` loads `libc.so`, `libm.so`, etc.  
🔹 `ld-linux.so` resolves function addresses.  
🔹 Execution is transferred to **`main()`**.

### **5️⃣ Static vs. Dynamic Linking**

- **Static Executable**: **Does NOT use `ld-linux.so`**, as all code is embedded.
- **Dynamic Executable**: **Requires `ld-linux.so`**, which loads shared libraries dynamically.

### **What Happens When a Statically Linked ELF Binary is Executed?**

If an **ELF binary is statically linked**, **`ld-linux.so` is NOT involved** because all necessary libraries are **already embedded** in the binary itself. Instead, the **Linux Kernel** directly loads and maps the executable into memory.

---

### **🔹 Static vs. Dynamic Execution Flow**

| Step                           | **Dynamically Linked (Uses `ld-linux.so`)**                                             | **Statically Linked (No `ld-linux.so`)**             |
| ------------------------------ | --------------------------------------------------------------------------------------- | ---------------------------------------------------- |
| **1️⃣ Kernel Loads ELF Header** | Reads ELF header and finds interpreter (`ld-linux.so`) in `.interp` section.            | Reads ELF header and sees there is no interpreter.   |
| **2️⃣ Loads Interpreter**       | Kernel loads `ld-linux.so`.                                                             | No interpreter is needed.                            |
| **3️⃣ Maps Sections**           | `ld-linux.so` maps the binary and dynamically loads shared libraries (`libc.so`, etc.). | Kernel **directly maps** the executable into memory. |
| **4️⃣ Resolves Symbols**        | `ld-linux.so` resolves symbols using GOT/PLT.                                           | No external symbols—everything is already included.  |
| **5️⃣ Transfers Execution**     | Once linking is done, it jumps to the entry point.                                      | Execution starts immediately at the **entry point**. |

---

### **🔹 Key Differences in Memory Mapping**

| **Memory Region**                         | **Dynamic Executable (`ld-linux.so`)** | **Static Executable (No `ld-linux.so`)**       |
| ----------------------------------------- | -------------------------------------- | ---------------------------------------------- |
| **Executable (`.text`, `.data`, `.bss`)** | Mapped from file.                      | Mapped from file.                              |
| **Shared Libraries (`libc.so`, etc.)**    | Mapped dynamically by `ld-linux.so`.   | **Already included**, so no external mappings. |
| **PLT/GOT**                               | Used for dynamic function resolution.  | **Not needed**—functions are directly called.  |
| **`ld-linux.so`**                         | Mapped into memory.                    | **Not present**.                               |

---

### **🔹 How to Check if a Binary is Statically Linked?**

```bash
ldd my_static_binary  # If it says "not a dynamic executable," it's static.
```

OR

```bash
file my_static_binary  # Look for "statically linked" in the output.
```

---

### **🔹 Conclusion**

✔ **Static binaries do NOT use `ld-linux.so`**—the Kernel loads and maps them directly.  
✔ No external libraries are needed, making **static executables more portable** but **larger in size**.  
✔ **Dynamic executables depend on `ld-linux.so`** to load shared libraries and resolve symbols at runtime.

---

## **🔹 Windows: PE Loader (`ntdll.dll`)**

In **Windows**, when a PE (Portable Executable) file is executed, the **PE Loader** inside `ntdll.dll` is responsible for loading and preparing it for execution.

### **1️⃣ What is `ntdll.dll`?**

`ntdll.dll` (Windows Native API Library) is a **low-level system DLL** responsible for:  
✔️ Handling the **PE loading process**.  
✔️ Managing **memory mapping of sections** (code, data, imports).  
✔️ Resolving **DLL dependencies**.  
✔️ Preparing execution for **`kernel32.dll`** and **user-mode execution**.

### **2️⃣ Where is it Located?**

- `C:\Windows\System32\ntdll.dll` (for 64-bit Windows)
- `C:\Windows\SysWOW64\ntdll.dll` (for 32-bit programs on 64-bit Windows)

### **3️⃣ How `ntdll.dll` Works?**

When an EXE is executed:  
1️⃣ The **Windows Loader** identifies the PE format and **loads `ntdll.dll`** into memory.  
2️⃣ `ntdll.dll` maps the **sections** of the PE file (`.text`, `.data`, `.rdata`).  
3️⃣ It **resolves DLL dependencies** (e.g., `kernel32.dll`, `user32.dll`).  
4️⃣ The process is handed over to `kernel32.dll`, which starts execution.

### **4️⃣ Example: Execution Flow**

```powershell
start my_program.exe  # Running an EXE file
```

🔹 The Windows **PE Loader** maps the executable into memory.  
🔹 `ntdll.dll` loads `kernel32.dll` and resolves dependencies.  
🔹 Execution is transferred to **the entry point** of the executable.

### **5️⃣ Static vs. Dynamic Linking**

- **Static Executable**: Includes all code, reducing reliance on external DLLs.
- **Dynamic Executable**: Uses `ntdll.dll` to load **DLLs dynamically**.

---

## **📌 Summary: ELF vs. PE Loading Mechanism**

| Feature              | Linux (`ld-linux.so`)            | Windows (`ntdll.dll`)           |
| -------------------- | -------------------------------- | ------------------------------- |
| **Role**             | ELF Interpreter & Dynamic Linker | PE Loader                       |
| **Executes**         | Dynamically linked ELF binaries  | PE (EXE, DLL) files             |
| **Loads Libraries**  | `libc.so`, `libm.so`, etc.       | `kernel32.dll`, `user32.dll`    |
| **Resolves Symbols** | GOT, PLT updates                 | Import Address Table (IAT)      |
| **Location**         | `/lib64/ld-linux-x86-64.so.2`    | `C:\Windows\System32\ntdll.dll` |

---

![segments](./img/1.png)
