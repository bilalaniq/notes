# **Thunk**

A **thunk** is a small piece of code that helps in **function calls, lazy evaluation, or execution redirection**. It acts as an intermediary, often used for:

- **Function call adaptation** (changing calling conventions, adjusting arguments).
- **Lazy evaluation** (delaying computation until needed).
- **Execution redirection** (jumping to another function dynamically).

Thunks appear in **compilers, operating systems, virtual machines, and shared libraries**.

---

## **Types of Thunks and Their Uses**

### **1. Calling Convention Thunks**

- Used when a function call needs to adapt to a different calling convention (e.g., argument passing style).
- Example: When a C++ method needs to call a C function with a different parameter setup.

**Example (Windows x86 stdcall to cdecl thunk)**

```assembly
stdcall_func_thunk:
    pop   ecx         ; Get return address
    pop   edx         ; Get first argument
    push  ecx         ; Restore return address
    call  real_func   ; Call actual function
    ret
```

- This adjusts the stack because `stdcall` functions clean up their own stack, but `cdecl` functions expect the caller to do so.

---

### **2. Virtual Method Thunks (C++ VTable)**

- C++ virtual functions use a **vtable (virtual table)**, which stores function pointers.
- A **vtable thunk** adjusts `this` pointer before calling the actual function.

**Example (Adjusting `this` pointer in multiple inheritance)**

```assembly
vtable_thunk:
    add  eax, 4        ; Adjust `this` pointer for second base class
    jmp  [eax + 8]     ; Jump to actual virtual function
```

- This thunk ensures the correct object layout when calling a virtual function.

---

### **3. Lazy Evaluation Thunks**

- Used in languages like Haskell, Python, and JavaScript to **delay computation** until necessary.
- Helps with **performance optimization** (avoid unnecessary computations).

**Example (Haskell-like lazy evaluation)**

```haskell
thunk = \() -> expensiveComputation()
result = thunk()  -- Computation happens only when called
```

---

### **4. Import Table Thunks (Windows DLLs / PLT in Linux)**

- When a program calls a function from a **shared library (DLL, SO file)**, it first goes through a thunk that **resolves the actual address** dynamically.

**Windows IAT Thunk Example**

```assembly
jmp [import_table + 0x10]  ; Jump to dynamically loaded function
```

- This lets the **dynamic linker** patch in the real function address.

**Linux PLT Thunk Example**

```assembly
jmp *got_entry          ; Jump to function from the GOT table
call resolve_symbol     ; If unresolved, call the dynamic linker
```

- The **PLT (Procedure Linkage Table)** uses a thunk to call the real function after resolving it.

---

### **5. Position-Independent Code (PIC) Thunks**

- Used in **shared libraries** to access **global variables** when the code’s base address is unknown.
- The `__x86.get_pc_thunk.ax` function is an example of this (seen in Linux).

**Example: Retrieving the PC (EIP) in x86 PIC**

```assembly
__x86.get_pc_thunk.ax:
    mov eax, [esp]   ; Get return address (PC)
    ret              ; Return with EAX holding the PC
```

- Helps compute **global variable addresses** in position-independent code.

---

### **6. Reverse Thunks**

- Used when a function call **crosses a boundary in the opposite direction** than usual.
- Example: A **reverse thunk** is needed when an unmanaged function (e.g., C) calls managed code (e.g., C# in .NET).

**Example (Reverse thunk from C to C# in .NET)**

```c
// Native function pointer to managed method
typedef void (*ManagedThunk)(void);
ManagedThunk func_ptr = GetManagedFunctionPointer();
func_ptr();  // Calls into managed code
```

- The thunk **wraps the managed function** so it can be called from native code.

---

## **Why Are Thunks Useful?**

| **Use Case**                    | **Purpose**                                             | **Example**                    |
| ------------------------------- | ------------------------------------------------------- | ------------------------------ |
| Calling Convention Adaption     | Ensures different function calling styles work together | Windows API (stdcall vs cdecl) |
| Virtual Functions (VTable)      | Adjusts `this` pointer for multiple inheritance         | C++ polymorphism               |
| Lazy Evaluation                 | Delays execution for performance                        | Haskell, JavaScript            |
| Dynamic Linking                 | Resolves function addresses at runtime                  | Windows IAT, Linux PLT         |
| Position-Independent Code (PIC) | Retrieves PC-relative addresses                         | `__x86.get_pc_thunk.ax`        |
| Reverse Thunks                  | Allows native code to call managed code                 | .NET P/Invoke                  |

