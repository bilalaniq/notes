# System-call

System calls provide an interface to the services made available by an operating system. These calls are generally available as functions written in C and
C++, although certain low-level tasks (for example, tasks where hardware
must be accessed directly) may have to be written using assembly-language
instructions.

## Example

before we study about sys-calls in detail first take an look at this example

When writing a program to copy data from one file to another, multiple system calls are required for handling input/output, error checking, and termination. The sequence of operations includes:

### **1. Getting the File Names**

- The program needs to obtain the names of the input and output files.
- This can be done in different ways depending on the OS:
  - **Command-line argument**: Example in UNIX: `cp in.txt out.txt`
  - **Interactive input**: The program prompts the user to type the file names.
  - **Graphical selection**: A GUI-based system allows the user to select files from a menu.
- Each method requires system calls for writing prompts and reading user input.

### **2. Opening the Input File & Creating the Output File**

- **Opening the input file** (system call)
  - If the file does not exist or lacks read permissions, an error occurs.
  - The program must display an error message (another system call) and may terminate.
- **Creating/opening the output file** (system call)
  - If a file with the same name already exists, possible actions include:
    - Aborting the program.
    - Deleting the existing file (system call) and creating a new one.
    - Asking the user whether to overwrite (requires additional system calls).

### **3. Reading and Writing the File**

- The program enters a loop where:
  - **Reading from the input file** (system call)
    - Errors may occur (e.g., end of file reached, hardware failure).
  - **Writing to the output file** (system call)
    - Errors may occur (e.g., no disk space left).
- Each read/write operation returns a status indicating success or failure.

### **4. Closing Files and Terminating**

- Once the file is copied:
  - **Closing both files** (two system calls).
  - **Displaying a completion message** (system call).
  - **Terminating the program** (final system call).

### **Conclusion**

This example highlights how operating systems expose services through system calls. Every step—getting input, opening files, handling errors, reading/writing, and termination—relies on system calls to interact with hardware and manage resources.

---

<br>
<br>

# API

Operating systems provide numerous services to applications, such as file management, process control, and memory allocation. However, most programmers do not directly invoke **system calls** to access these services. Instead, they use an **Application Programming Interface (API)**, which provides a higher-level interface that simplifies system interactions. An API defines a set of functions that developers can use in their applications, specifying the required parameters, expected return values, and how these functions interact with the operating system. By using APIs, applications can be written in a way that is more **portable**, meaning they can run on different operating systems with minimal modifications.

### Common APIs for Different Operating Systems

There are several well-known APIs that developers use depending on the operating system they are targeting:

1. **Windows API (WinAPI)**

   - The Windows API is the primary API for Windows-based systems and is used for developing applications that interact with the Windows operating system.
   - It provides functions for **window management, file operations, process control, networking, and graphical user interfaces**.
   - The Windows API is accessed through various libraries, including:
     - **Kernel32.dll** (Core system functions like process/thread management and memory allocation)
     - **User32.dll** (Handles user interface elements like windows, menus, and input)
     - **Gdi32.dll** (Manages graphical output like rendering images and text)
     - **Advapi32.dll** (Handles security and registry access)
     - **Ws2_32.dll** (Networking support, including sockets for communication)
   - Windows programs written in **C or C++** often use these libraries to interact with system resources.

2. **POSIX API**

   - The **Portable Operating System Interface (POSIX)** API is a standard for UNIX-like operating systems, including **Linux, macOS, and BSD-based systems**.
   - It provides functions for **process management, file handling, interprocess communication (IPC), and networking**.
   - The standard C library, known as **libc**, provides access to system calls in UNIX-based systems.
   - A widely used implementation of the POSIX API on Linux is **GNU C Library (glibc)**, which provides essential functions such as:
     - `open()`, `read()`, `write()`, and `close()` for file handling
     - `fork()` and `exec()` for process creation and execution
     - `socket()` for network communication
   - Other implementations include **musl libc** (used in lightweight Linux distributions) and **BSD libc** (used in FreeBSD and macOS).

3. **Java API**
   - Unlike WinAPI or POSIX, the **Java API** is platform-independent and is designed for applications running on the **Java Virtual Machine (JVM)**.
   - It provides a vast set of libraries for **file I/O, networking, concurrency, database access, and graphical user interfaces (Swing, JavaFX)**.
   - The Java API abstracts low-level system interactions, meaning that Java applications can run on **Windows, Linux, and macOS** without modification.

---

Behind the scenes, the functions that make up an API typically invoke the
actual system calls on behalf of the application programmer. For example, the
Windows function `CreateProcess()` actually invokes the `NTCreateProcess()` system call in the
Windows kernel.

Why would an application programmer prefer programming according to
an API rather than invoking actual system calls? There are several reasons for
doing so.

### Why Use an API Instead of Direct System Calls?

APIs offer several benefits over directly making system calls:

- **Portability**: Programs written using APIs can often run on different operating systems with little to no modification.
- **Ease of Development**: APIs provide well-documented functions, making it easier for developers to write code without needing to understand complex system internals.
- **Security and Stability**: Direct system calls can lead to errors or vulnerabilities, whereas APIs provide a controlled way to access system resources safely.
- **Backward Compatibility**: Operating system vendors maintain API compatibility over different versions, reducing the risk of breaking applications when upgrading.

---

many of the POSIX and Windows APIs are similar to
the native system calls provided by the UNIX, Linux, and Windows operating
systems.

| **Category**                | **Windows System Call**          | **Unix System Call** |
| --------------------------- | -------------------------------- | -------------------- |
| **Process Control**         | `CreateProcess()`                | `fork()`             |
|                             | `ExitProcess()`                  | `exit()`             |
|                             | `WaitForSingleObject()`          | `wait()`             |
| **File Management**         | `CreateFile()`                   | `open()`             |
|                             | `ReadFile()`                     | `read()`             |
|                             | `WriteFile()`                    | `write()`            |
|                             | `CloseHandle()`                  | `close()`            |
| **Device Management**       | `SetConsoleMode()`               | `ioctl()`            |
|                             | `ReadConsole()`                  | `read()`             |
|                             | `WriteConsole()`                 | `write()`            |
| **Information Maintenance** | `GetCurrentProcessID()`          | `getpid()`           |
|                             | `SetTimer()`                     | `alarm()`            |
|                             | `Sleep()`                        | `sleep()`            |
| **Communications**          | `CreatePipe()`                   | `pipe()`             |
|                             | `CreateFileMapping()`            | `shm_open()`         |
|                             | `MapViewOfFile()`                | `mmap()`             |
| **Protection**              | `SetFileSecurity()`              | `chmod()`            |
|                             | `InitializeSecurityDescriptor()` | `umask()`            |
|                             | `SetSecurityDescriptorGroup()`   | `chown()`            |

This table provides a **side-by-side comparison** of **Windows and Unix/Linux system calls** for various functionalities such as **process control, file management, device management, information maintenance, interprocess communication (IPC), and security management**.


 