### **Tables Used in Linking (Static & Dynamic) for EXE & ELF Files**

When linking an executable (either **statically** or **dynamically**), several tables are involved in the process. Below is a complete list of all the tables used in **static linking** and **dynamic linking** for both **Windows PE (Portable Executable)** and **ELF (Executable and Linkable Format)**.

---

## **📌 Linking Tables in EXE (Windows PE Format)**

### **🔹 Used in Static Linking**

1. **Symbol Table** – Stores function and variable symbols during compilation.
2. **String Table** – Stores symbol names referenced in the symbol table.
3. **Relocation Table** – Contains address fix-ups when linking the final binary.
4. **Section Table** – Defines memory layout and sections of the binary.
5. **Import Table (before linking)** – Used during linking to resolve function calls.
6. **Export Table (before linking)** – Lists functions available for external linking.

### **🔹 Used in Dynamic Linking**

1. **Import Address Table (IAT)** – Holds addresses of dynamically loaded functions.
2. **Import Table** – Lists DLLs and their functions required at runtime.
3. **Export Table** – Contains functions and symbols that other programs can use.
4. **Bound Import Table** – Optimizes DLL loading for faster resolution.
5. **Delay Import Table** – Allows lazy loading of DLLs at runtime.
6. **Relocation Table** – Used when loading the executable at a different memory address.

---

## **📌 Linking Tables in ELF (Linux & Unix ELF Format)**

### **🔹 Used in Static Linking**

1. **Symbol Table (.symtab)** – Holds function and variable symbols during linking.
2. **String Table (.strtab)** – Stores names of symbols for the symbol table.
3. **Relocation Table (.rel.text, .rel.data, etc.)** – Fixes addresses for linked symbols.
4. **Section Header Table** – Defines program sections such as `.text`, `.data`, `.bss`.

### **🔹 Used in Dynamic Linking**

1. **Dynamic Symbol Table (.dynsym)** – Stores symbols required for dynamic linking.
2. **Dynamic String Table (.dynstr)** – Holds names of dynamically linked symbols.
3. **Dynamic Section (.dynamic)** – Stores information for dynamic linking.
4. **Global Offset Table (GOT)** – Used for indirect addressing of dynamically linked functions.
5. **Procedure Linkage Table (PLT)** – Helps resolve function addresses dynamically.
6. **Relocation Table (.rela.dyn, .rela.plt)** – Fixes addresses of dynamically linked symbols.
7. **Hash Table (.hash or .gnu.hash)** – Optimizes symbol lookup for dynamic linking.

---

## **🛠 Summary of Differences Between Static & Dynamic Linking**

| Feature               | Static Linking                | Dynamic Linking                                     |
| --------------------- | ----------------------------- | --------------------------------------------------- |
| **Exec Size**         | Larger (all code included)    | Smaller (shared libraries)                          |
| **Symbol Resolution** | At compile time               | At runtime                                          |
| **Relocation**        | Done before execution         | Happens dynamically when loading                    |
| **Performance**       | Faster (no runtime lookup)    | Slightly slower (runtime resolution)                |
| **Flexibility**       | Less flexible (code is fixed) | More flexible (DLLs/Shared Objects can be replaced) |

