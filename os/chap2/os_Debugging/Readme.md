# Operating-System Debugging

## Failure Analysis

**Debugging** is the process of finding and fixing errors (bugs) in both hardware and software. When something goes wrong in a system—like a program crashing or slowing down—debugging helps identify the problem and fix it. In addition to fixing bugs, debugging can also involve improving the performance of the system by eliminating `bottlenecks` (slow spots) that reduce efficiency.

When a **process fails** (like a program crashing), the operating system usually records the error in a **log file**. This log file contains important information about what went wrong. Sometimes, the system also takes a **core dump**, which is a snapshot of the program's memory at the moment it failed. This memory snapshot is stored in a file and can be analyzed later to help find the cause of the failure.

> [!NOTE]
>
> Memory was referred to as the `core` in the early days of computing.

You can think of **core dumps** like a picture of the program's brain at the time it failed. This picture can be looked at to see what went wrong. Debuggers are special tools that allow developers to examine this core dump or a running program’s memory to understand why it crashed.

### Debugging Operating-System Kernel Failures

Debugging the **kernel** (the core part of the operating system) is much harder than debugging user-level programs. This is because the kernel is much more complex, controls the hardware, and doesn't have the same tools available to users as regular programs do.

When a **kernel failure** happens, it is called a **crash**. Just like user-level programs, the kernel writes error information to a **log file**, and it also saves the system's memory state in something called a **crash dump**. A **crash dump** is a snapshot of the kernel’s memory, saved in case the system needs to be rebooted.

### Saving the Memory State in Kernel Debugging

Since the kernel controls the file system, it would be risky for it to try to save its error information to a file in the same file system (because the file system might be part of the problem). Instead, operating systems usually have a **special area of the disk** set aside just for this purpose. If a kernel failure happens, the system can save its memory to this special area on the disk, avoiding the regular file system.

After the system restarts, a process runs to read the crash dump from this special area and save it as a **crash dump file**. This file can then be analyzed to understand what caused the failure.

### Why Is This Necessary?

For normal user programs, these steps aren't needed because the kernel doesn't have to worry about the file system being broken. But when the kernel crashes, it needs to be extra careful and save its memory in a safe place to avoid losing critical information.

In summary:

- **Failure Analysis** helps find and fix problems when programs or the operating system fail.
- **Core dumps** and **crash dumps** are snapshots of memory that help analyze what went wrong.
- Debugging the kernel is harder than debugging regular programs, so special techniques are used to save important memory data safely during a crash.

---

<br>
<br>

## Performance Monitoring and Tuning

### **Why Performance Monitoring is Important**

When an operating system is **running slow**, it might be because of a **bottleneck** — something that is slowing everything else down (like a traffic jam on one part of the highway).

To **fix performance issues**, we first need to **measure what's happening inside the system** — kind of like using a speedometer or fuel gauge in a car.

This is where **performance monitoring tools** come in.

---

### Two Types of Performance Monitoring Tools

1. **Per-Process Tools** – Show info about individual processes (programs).
2. **System-Wide Tools** – Show info about the entire system (CPU, memory, disk, etc.).

---

### 1. **Counters** (Checking Stats)

Counters are **numbers** kept by the OS about how often certain things happen.

#### Examples of Counter Tools in Linux:

- **Per-Process Tools:**

  - `ps`: Shows details about a specific process.
  - `top`: Shows live stats of processes like CPU and memory usage.

- **System-Wide Tools:**
  - `vmstat`: Shows memory usage.
  - `netstat`: Shows network activity.
  - `iostat`: Shows disk usage.

---

### 📂 `/proc` File System in Linux

Linux has a special folder called **`/proc`** that acts like a window into the kernel's brain.

- It doesn't store files on disk — it's in **RAM only**.
- It has folders like `/proc/1234`, where **1234** is a process ID.
- Inside, you can find info about what that process is doing.
- It also has files with system-wide stats.

So `/proc` is a **treasure chest of real-time system info**.

---

### 2. **Tracing** (Following Events Step by Step)

While counters show **"how many times"** something happened, tracing tools show **"exactly what happened and when"**.

These tools **trace the steps** a program takes — like watching a detective following a suspect.

#### Examples of Tracing Tools:

- **Per-Process:**

  - `strace`: Shows system calls a process makes (like opening a file).
  - `gdb`: A debugger to watch what your code is doing line by line.

- **System-Wide:**
  - `perf`: A powerful set of tools to measure system performance.
  - `tcpdump`: Captures and shows network packets.

---

### Summary

| Feature      | Description                                          | Examples                                   |
| ------------ | ---------------------------------------------------- | ------------------------------------------ |
| **Counters** | Count how often something happens                    | `ps`, `top`, `vmstat`, `iostat`, `netstat` |
| **Tracing**  | Follow events in detail as they happen               | `strace`, `gdb`, `perf`, `tcpdump`         |
| **/proc**    | Special folder to get real-time info from the kernel | `/proc/[PID]`, `/proc/cpuinfo`, etc.       |

---

<br>

to learn how to use the debuging tools click [here](./debuging_tools.md)

<br>
<br>

click [here](./BCC.md) to learn about BCC
