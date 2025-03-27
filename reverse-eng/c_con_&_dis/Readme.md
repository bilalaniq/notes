# Global Constructors and Destructors with C (not C++)

In the OOP world, global objects get initialized with a constructor and destroyed at the end with a destructor. Interestingly, the GNU gcc has attributes to mark functions as constructor and destructors, which can greatly simply system startup and shutdown, even if not using C++.

With the GNU gcc compiler, I can mark functions with an attribute, so they get called before entering main() or after exit of main(). The attribute works both in C and C++, but it especially useful in C to initialize modules in an automated way.

In C++, when having global objects or variables, then they need to be constructed automatically at program startup, and destructed at program shutdown.

Consider the following example:

```cpp

class Car {
  private: int price;
  public:
      Car(void) { // constructor
        price = 1000; // initial base price for every car
      }
      ~Car(void) { // destructor
        price = -1;
      }
      void SetPrice(int price) { // setter method
        this->price = price;
      }
};

// global variables
static Car c; // global object, shall be initialized by startup (constructor)
static int i; // initialized by startup (zero-out)
static int j = 0x1234; // initialized by startup (copy-down)

```

Here the program startup will call the constructor of Car c and initialize it that way, in a similar way as the startup zero-out and startup copy-down initializes variables in C.

- Zero-Out Initialization: It refers to automatically setting all variables (especially global or static ones) to zero at the start of the program before main() executes. This is handled by the startup code in languages like C.

example:

```c
#include <stdio.h>

int globalVar;  // This will be zero-initialized automatically.

int main() {
    printf("Global variable is: %d\n", globalVar);  // Output: 0
    return 0;
}

```

- Copy-Down Initialization: This refers to copying initialized values from a higher memory level (such as global or static memory) into local variables during the startup of a program. It is typically done before the main() function runs. Essentially, it ensures that variables are properly initialized from predefined values, often from a memory section reserved for initialization.

```c
#include <stdio.h>

int globalVar = 10;  // This value is copied down to `globalVar` during program startup.

int main() {
    printf("Global variable is: %d\n", globalVar);  // Output: 10
    return 0;
}
```

All this will be handled by the startup code, and the initialization happens before calling main().

The idea is to use that concept of calling function calls before main() for normal C modules, to have them initialized and de-initialized, so I don’t have to do this manually in my code.

# GCC Constructor and Destructor Attributes

if you want to learn about attributes click [here](../__attribute__/Readme.md)

The solution is to take advantage of special GNU gcc compiler attributes.

From the gcc user manual:

constructor
destructor
The constructor attribute causes the function to be called automatically before execution enters main (). Similarly, the destructor attribute causes the function to be called automatically after main () has completed or exit () has been called. Functions with these attributes are useful for initializing data that will be used implicitly during the execution of the program.

With this, I can mark my initialization and de-initialization routines with the attributes, for example:

```c
__attribute((destructor))
void STEPPER_Deinit(void) {
  ...
}

__attribute((constructor))
void STEPPER_Init(void) {
  ...
}
```

It is possible to mark a function both as constructor and destructor. It can be mixed with the prototype/declaration and definition, and vice versa:

```c

3
4
__attribute((constructor)) void CalledAsConstructerAndDestructor(void)
__attribute((destructor)) void CalledAsConstructerAndDestructor(void) {
  /* called both in constructing and destructing phase */
}
```

## Order of Calls

In many cases, you might want to have control over the order of calls. It is possible to give the destructor and constructor a ‘priority’, with lower numbers the higher urgency, for example:

```c
__attribute__ ((constructor(101)))
void myInit(void) {
  ...
}
```

why 101

GCC allows setting priorities for constructor `(__attribute__((constructor(priority))))` and destructor `(__attribute__((destructor(priority))))` functions. However, priority values 0 to 100 are reserved for the compiler's own initialization routines, so user-defined functions should use values above 100 to avoid conflicts.

If no value/argument is provided, then they get a lower priority than the ones with the number.

---

# linker

This linker script ensures that **constructors and destructors** are correctly placed in memory so that they are called at the right time during program execution.

---

### **1. Purpose of the Linker Script**

In embedded systems (or even in some OS environments), constructors (`__attribute__((constructor))`) and destructors (`__attribute__((destructor))`) are not automatically handled unless explicitly linked into the correct sections.

This linker script:

- **Aligns memory** properly to ensure correct execution.
- **Ensures constructors and destructors are included** using `KEEP()`, preventing them from being removed by the linker.
- **Places C++ global/static constructors and destructors** into the appropriate sections (`.init_array`, `.fini_array`, `.ctors`, `.dtors`).

---

### **2. Key Sections Explained**

#### **2.1 ISR Vector Table**

```ld
__vectors_start__ = ABSOLUTE(.) ;
KEEP(*(.isr_vector))
```

- This ensures the **Interrupt Service Routine (ISR) vector table** is placed at the beginning of the `.text` section.
- `ABSOLUTE(.)` locks the address.

---

#### **2.2 Global Section Table**

```ld
__data_section_table = .;
LONG(LOADADDR(.data));
LONG(ADDR(.data));
LONG(SIZEOF(.data));
```

- This sets up the `.data` section (initialized global/static variables).
- `LOADADDR(.data)`: Address where `.data` is stored in **Flash**.
- `ADDR(.data)`: Address where `.data` will be copied to **RAM**.
- `SIZEOF(.data)`: The size of the `.data` section.

Similar logic is applied to `.bss` (uninitialized global/static variables).

---

#### **2.3 Main `.text` and Read-Only Data Sections**

```ld
*(.text*)
*(.rodata .rodata.* .constdata .constdata.*)
```

- `.text*` → Code and functions.
- `.rodata` → Read-only data (e.g., string literals, `const` variables).

---

#### **2.4 Constructors and Destructors**

```ld
/* Constructors and Destructors */
. = ALIGN(4);
KEEP(*(.init))

. = ALIGN(4);
__preinit_array_start = .;
KEEP (*(.preinit_array))
__preinit_array_end = .;

. = ALIGN(4);
__init_array_start = .;
KEEP (*(SORT(.init_array.*)))
KEEP (*(.init_array))
__init_array_end = .;

KEEP(*(.fini));
```

- `.init`: Legacy constructor section.
- `.preinit_array`: Early-stage constructors (used before `main`).
- `.init_array`: Normal constructors.
- `.fini`: Destructor section.

> **Why `KEEP()`?**
>
> - Prevents the linker from discarding sections that **don’t seem referenced** but are needed for initialization.

---

#### **2.5 C++ Global Constructors/Destructors**

```ld
KEEP (*crtbegin.o(.ctors))
KEEP (*(EXCLUDE_FILE (*crtend.o) .ctors))
KEEP (*(SORT(.ctors.*)))
KEEP (*crtend.o(.ctors))
```

- This ensures global C++ objects **with constructors** are initialized properly before `main()`.
- Similar logic applies to `.dtors` (destructors).

---

### **3. How This Affects `__attribute__((constructor))`**

When you use:

```c
void my_init_function(void) __attribute__((constructor));
```

- The compiler places `my_init_function()` inside `.init_array`.
- The linker **ensures** it’s in the correct section (`__init_array_start` → `__init_array_end`).
- The **startup code** (provided by the system or runtime) loops over `__init_array` and calls your function **before `main()`**.

---

### **4. Why Is This Needed?**

- In embedded systems, there is **no automatic execution of constructors** unless explicitly placed.
- The linker script ensures the startup code **knows where to find them** and executes them in order.

---

### **5. What If I Remove This?**

- If you remove these sections, constructors and destructors **may not run**, breaking initialization for global/static variables.

---

### **Summary**

This linker script:

- **Places `.init_array` (constructors) and `.fini_array` (destructors) properly.**
- **Ensures startup code finds and executes constructors before `main()`.**
- **Keeps `.ctors/.dtors` for C++ static/global object initialization.**
- **Aligns sections correctly to avoid memory corruption.**

---

In summary, I have now an elegant way to call initialization and de-initialization in my application.

Happy constructing and destructing 🙂

---

<br>
<br>

---

where are constructors and distructors stored

### **In C (with `constructor`/`destructor` attributes)**:

- **Constructor-like functions** (with the `constructor` attribute) are typically stored in the **`init_array`** section in the **data segment** (this is where function pointers to constructors are placed).
- **Destructor-like functions** (with the `destructor` attribute) are stored in the **`fini_array`** section in the **data segment** (this is where function pointers to destructors are placed).
- Additionally, some compilers may still place constructor and destructor functions in the **`.ctors`** and **`.dtors`** sections, but the modern approach uses **`init_array`** and **`fini_array`**.

### **In C++**:

- **Constructors and destructors** are stored in the **text section** (code segment) as part of the class's code.
- **Global/static constructors and destructors** are typically stored in the **`.ctors`** and **`.dtors`** sections.
- **Virtual functions** are stored in the **vtable** in the **data segment**.
- Global/static constructors and destructors can also be placed in the **`init_array`** and **`fini_array`** sections, where function pointers are stored and executed before and after `main()`.

if you want to learn about init_array and finit_array click [here](../elf/init&finit_array.md)
