# Ghidra2GDB

here in this directory i will explain the differnce between address of ghidra and gdb and how to use the ghidra addressses in gdb

### **Why is the Ghidra Address Different from GDB?**

When analyzing a binary in **Ghidra**, the addresses shown are often **Relative Virtual Addresses (RVAs)**, while in **GDB**, you see the **actual runtime addresses** where the binary is loaded in memory.

---

### **1. Understanding Ghidra Addresses**

- Ghidra **disassembles** the binary but does not execute it.
- It shows **addresses relative to the start of the program's memory layout**.
- The start of the `.text` (code) section in Ghidra might be **0x00100000 or 0x00000000**, depending on the binary.

However, **at runtime**, Linux loads the binary at a different address.

---

### **2. Why is the Address Different in GDB?**

When the binary is loaded in **GDB**, the OS assigns it a **load address**.
For example, from your `vmmap` output:

```
0x0000555555555000 0x0000555555556000 r-x /mnt/c/Users/bilal/Videos/ctf/bin
```

This means that the **actual** base address of the code section at runtime is `0x0000555555555000`, not `0x00100000` like in Ghidra.

---

### **3. How to Convert a Ghidra Address to a GDB Address?**

#### Formula:

\[
\text{Actual Runtime Address} = \text{Load Address} + (\text{Ghidra Address} - \text{Ghidra Base Address})
\]

#### Example:

If **Ghidra shows `0x0010186c`** but the **real load address in GDB is `0x5555555555000`**, and if Ghidra’s base was `0x00100000`, then:

```
Runtime Address = 0x5555555555000 + (0x0010186c - 0x00100000)
                = 0x5555555555000 + 0x186c
                = 0x555555556686c
```

Now, in GDB:

```sh
break *0x555555556686c
run
```

---

### **4. How to Find Ghidra’s Base Address?**

- Look at the **memory mappings** in Ghidra.
- Typically, the `.text` section starts at `0x00100000` in Ghidra for ELF binaries.

If you’re unsure, check the binary’s headers:

```sh
readelf -l ./binary | grep LOAD
```

Look for the base virtual address.

---

### **5. Automating the Address Conversion**

If you often need to convert addresses, you can use GDB:

```sh
python
ghidra_addr = 0x0010186c
ghidra_base = 0x00100000
gdb_base = 0x5555555555000
runtime_addr = gdb_base + (ghidra_addr - ghidra_base)
print(hex(runtime_addr))
end
```

Then, set a breakpoint using:

```sh
break *0x555555556686c
```

---

### **Conclusion**

- **Ghidra shows RVAs**, while **GDB shows runtime addresses**.
- **Use `vmmap` in GDB** to find the real load address.
- **Convert addresses using the formula** before setting breakpoints.
