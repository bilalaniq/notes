# `__attribute__`

One of the best (but little known) features of GNU C is the `__attribute__` mechanism, which allows a developer to attach characteristics to function declarations to allow the compiler to perform more error checking. It was designed in a way to be compatible with non-GNU implementations, and we've been using this for years in highly portable code with very good results.

`__attribute__` is not part of C, but is an extension in GCC that is used to convey special information to the compiler. The syntax of `__attribute__` was chosen to be something that the C preprocessor would accept and not alter (by default, anyway), so it looks a lot like a function call. It is not a function call, though.

Like much of the information that a compiler can learn about C code (by reading it), the compiler can make use of the information it learns through `__attribute__` data in many different ways -- even using the same piece of data in multiple ways, sometimes.

The `__attribute__` keyword is a **compiler-specific extension** used in both **C** and **C++** to provide additional information about variables, functions, types, or structures to the compiler. This keyword is primarily used in **GCC** (GNU Compiler Collection) . It is a way to apply various optimizations, specify alignment, control function visibility, or manage other compiler behaviors.

Here's a breakdown of what `__attribute__` does in **C** and **C++**:

### **General Syntax of `__attribute__`**

```c
__attribute__((attribute))
```

The `attribute` specifies what kind of optimization or property you want to apply to a function, variable, or type. The parentheses are required, and the attributes are usually separated by commas if there are multiple attributes.

---

### **1. `__attribute__((unused))`**

- **Purpose**: Suppresses warnings for variables or functions that are declared but not used.
- **Usage**:
  ```c
  int unused_variable __attribute__((unused));
  ```

---

### **2. `__attribute__((deprecated))`**

- **Purpose**: Marks a function or variable as deprecated. It triggers a warning when the function/variable is used.
- **Usage**:
  ```c
  void old_function(void) __attribute__((deprecated));
  ```

---

### **3. `__attribute__((noreturn))`**

- **Purpose**: Indicates that a function will not return (e.g., `exit()` or `abort()`).
- **Usage**:
  ```c
  void my_exit_function(void) __attribute__((noreturn));
  ```

---

### **4. `__attribute__((pure))`**

- **Purpose**: Specifies that the function has no side effects, and its return value depends solely on the input arguments. The compiler can optimize calls to such functions.
- **Usage**:
  ```c
  int square(int x) __attribute__((pure));
  ```

---

### **5. `__attribute__((const))`**

- **Purpose**: Similar to `pure`, but the return value depends solely on the arguments, and the function does not access global variables.
- **Usage**:
  ```c
  int add(int x, int y) __attribute__((const));
  ```

---

### **6. `__attribute__((aligned(n)))`**

- **Purpose**: Specifies that the variable or type should be aligned to a specific boundary (`n` bytes).
- **Usage**:
  ```c
  int x __attribute__((aligned(32)));
  ```

---

### **7. `__attribute__((packed))`**

- **Purpose**: Forces the compiler to pack the members of a struct or union, eliminating any padding between members.
- **Usage**:
  ```c
  struct MyStruct {
      char a;
      int b;
  } __attribute__((packed));
  ```

---

### **8. `__attribute__((constructor))`**

- **Purpose**: Marks a function to be called before `main()` starts. This is often used for initialization tasks in shared libraries.
- **Usage**:
  ```c
  void init_function(void) __attribute__((constructor));
  ```

---

### **9. `__attribute__((destructor))`**

- **Purpose**: Marks a function to be called after `main()` ends, typically used for cleanup or deallocation tasks.
- **Usage**:
  ```c
  void cleanup_function(void) __attribute__((destructor));
  ```

---

### **10. `__attribute__((always_inline))`**

- **Purpose**: Tells the compiler to always inline the function, even if it normally would not be inlined.
- **Usage**:
  ```c
  inline void my_function(void) __attribute__((always_inline));
  ```

---

### **11. `__attribute__((noinline))`**

- **Purpose**: Prevents the compiler from inlining the function, even if it would normally choose to do so.
- **Usage**:
  ```c
  void my_function(void) __attribute__((noinline));
  ```

---

### **12. `__attribute__((visibility("hidden")))`**

- **Purpose**: Hides a symbol from the dynamic linker, making it unavailable outside the shared library or object file.
- **Usage**:
  ```c
  void hidden_function(void) __attribute__((visibility("hidden")));
  ```

---

### **13. `__attribute__((alias("name")))`**

- **Purpose**: Creates an alias for a function or variable, allowing multiple names to refer to the same symbol.
- **Usage**:
  ```c
  void my_function(void);
  void alias_function(void) __attribute__((alias("my_function")));
  ```

---

### **14. `__attribute__((warn_unused_result))`**

- **Purpose**: Warns if the return value of a function is ignored.
- **Usage**:
  ```c
  int critical_function(void) __attribute__((warn_unused_result));
  ```

---

### **15. `__attribute__((used))`**

- **Purpose**: Prevents the compiler from optimizing out variables or functions, even if they are not directly referenced.
- **Usage**:
  ```c
  int my_variable __attribute__((used)) = 42;
  ```

---

### **16. `__attribute__((sentinel))`**

- **Purpose**: Marks the last parameter of a function as a sentinel value, which is used to mark the end of a variable argument list.
- **Usage**:
  ```c
  void my_function(const char *format, ...) __attribute__((sentinel));
  ```

---

### **17. `__attribute__((section("name")))`**

- **Purpose**: Specifies that a variable or function should be placed in a specific section of the object file.
- **Usage**:
  ```c
  int my_var __attribute__((section(".my_section"))) = 10;
  ```

---

### **18. `__attribute__((fastcall))`**

- **Purpose**: Specifies the calling convention to be used for a function (in this case, the `fastcall` convention).
- **Usage**:
  ```c
  void my_function(void) __attribute__((fastcall));
  ```

---

### **19. `__attribute__((fnspec))`**

- **Purpose**: Used in some specific scenarios, often in embedded programming, to specify certain function attributes (e.g., `naked`, which indicates no prologue or epilogue code).
- **Usage**: (Platform-specific)

---

### **20. `__attribute__((interrupt))`**

- **Purpose**: Used in embedded systems programming to specify that a function should be treated as an interrupt handler.
- **Usage**:
  ```c
  void interrupt_handler(void) __attribute__((interrupt));
  ```

---

### **21. `__attribute__((malloc))`**

- **Purpose**: Tells the compiler that a function allocates memory and does not return any previously allocated memory, allowing the compiler to optimize memory management.
- **Usage**:
  ```c
  void *my_malloc(size_t size) __attribute__((malloc));
  ```

---

### **22. `__attribute__((returns_nonnull))`**

- **Purpose**: Specifies that a function’s return value is never `NULL`, allowing the compiler to optimize code that uses the return value.
- **Usage**:
  ```c
  char *get_string(void) __attribute__((returns_nonnull));
  ```

---

### **23. `__attribute__((deprecated("message")))`**

- **Purpose**: Allows for a custom deprecation message when a deprecated function or variable is used.
- **Usage**:
  ```c
  void old_function(void) __attribute__((deprecated("Use new_function instead")));
  ```

---

### **24. `__attribute__((likely))`**

- **Purpose**: Provides a hint to the compiler that a certain condition is likely to be true, which may help in optimization.
- **Usage**:
  ```c
  if (condition) __attribute__((likely)) {
      // Code for the likely case
  }
  ```

---

### **25. `__attribute__((unlikely))`**

- **Purpose**: Provides a hint to the compiler that a certain condition is unlikely to be true, which may help in optimization.
- **Usage**:
  ```c
  if (condition) __attribute__((unlikely)) {
      // Code for the unlikely case
  }
  ```

---

### **26. `__attribute__((vector_size(n)))`**

- **Purpose**: Specifies that a type is a vector type, used for SIMD (Single Instruction, Multiple Data) operations with a specific size.
- **Usage**:
  ```c
  typedef int v4si __attribute__((vector_size(16)));
  ```

---

### **27. `__attribute__((aligned(m)))`**

- **Purpose**: Specifies the minimum alignment for a variable or type, ensuring that memory alignment constraints are met.
- **Usage**:
  ```c
  struct MyStruct {
      char a;
      int b;
  } __attribute__((aligned(8)));
  ```

---

### **28. `__attribute__((may_alias))`**

- **Purpose**: Tells the compiler that two types may alias, and it should not assume they do not overlap in memory.
- **Usage**:
  ```c
  int *p1;
  long *p2 __attribute__((may_alias));
  ```

---

### **29. `__attribute__((no_sanitize("type")))`**

- **Purpose**: Disables a specific sanitizer for a function or variable, useful for turning off sanitization in specific situations.
- **Usage**:
  ```c
  void my_function(void) __attribute__((no_sanitize("address")));
  ```

---

These are the most commonly used `__attribute__` specifiers in **C** and **C++** with **GCC** and **Clang**. They provide various ways to control function behavior, memory usage, optimizations, and visibility across different platforms and compilers.

### **Compatibility**

- The `__attribute__` keyword is mostly supported by **GCC** and **Clang**, and its usage may not be portable to compilers like **MSVC** (Microsoft Visual C++). However, other compilers may offer similar extensions with slightly different syntax or functionality.

---

### **Conclusion**

In **C** and **C++**, `__attribute__` is a powerful tool for giving the compiler additional information about how to handle certain parts of your code. Whether you're optimizing performance, controlling memory layout, or managing code generation for constructors and destructors, the `__attribute__` mechanism provides a way to fine-tune your program to meet specific needs or constraints. However, since it's a compiler extension, it may not be supported by all compilers, so it's important to ensure compatibility when writing cross-platform code.
