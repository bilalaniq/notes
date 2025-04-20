# BCC

**BCC** stands for **BPF Compiler Collection**. It’s a toolkit that helps you trace and monitor what’s happening **inside the Linux kernel**, without stopping or restarting the system.

Think of it like a high-tech magnifying glass that lets you watch exactly how the operating system behaves in real time — useful for debugging, performance analysis, and security checks.

---

### **Why do we need BCC?**

Debugging or monitoring what happens **between** your apps and the OS (like reading files, accessing memory, etc.) is very tricky because:

- A lot of it happens in the kernel, which is low-level and hard to see.
- Modifying the kernel to add print/debug statements is dangerous.
- Most tools slow down the system or miss key events.

**BCC solves this** by providing:
✅ Safe kernel tracing  
✅ Low impact on performance  
✅ Real-time visibility  
✅ Tools for both system-wide and process-specific monitoring

---

### **What is eBPF?**

- **eBPF** stands for **extended Berkeley Packet Filter**.
- Originally made for filtering network traffic.
- Now, it’s like a **mini-programming engine inside the Linux kernel**.

With **eBPF**, you can write small programs that the kernel runs safely. These programs can **observe**, **analyze**, and even **respond** to system events like:

- File opens
- System calls
- Network packets
- Disk reads/writes

💡 Think of eBPF like giving the kernel tiny, safe “plugins” that can watch its internal behavior.

---

### **How do BCC and eBPF work together?**

Writing raw eBPF programs is hard — you need to write low-level C code.

So the **BCC toolkit** makes it easier by:

1. Letting you write tools in **Python**.
2. Embedding small bits of **C code** (eBPF programs) inside.
3. Automatically compiling and loading the code into the running kernel.
4. Showing you clean, readable output from tracing events.

---

### **Example BCC Tools**

Let’s look at a few tools BCC gives you out of the box:

#### 1. `disksnoop.py`

Monitors disk I/O (reads/writes) in real-time:

```bash
./disksnoop.py
```

**Output:**

```
TIME(s)     T    BYTES    LAT(ms)
1946.2918   R       8     0.27
1948.3458   W    8192     0.96
```

- `T`: Read (`R`) or Write (`W`)
- `BYTES`: Size of I/O operation
- `LAT(ms)`: Latency (time taken)

#### 2. `opensnoop -p <PID>`

Monitors `open()` system calls **just for a specific process**:

```bash
./opensnoop -p 1225
```

If a process with PID `1225` tries to open a file, you’ll see exactly which file and when.

---

### **Is it safe to use on real systems?**

Yes — that’s a big strength of BCC.

✅ It works on live, production Linux systems  
✅ Has **very little performance impact**  
✅ eBPF code is verified before loading, so it can’t crash or slow the system

---

### **How it all fits together**

```text
        Python Script (BCC Tool)
                ↓
         Embedded eBPF (in C)
                ↓
    BCC compiles & loads it into the Kernel
                ↓
     Kernel runs the code safely using eBPF
                ↓
   Real-time tracing output sent to user space
```

---

### Examples of what you can trace with BCC

| Tool         | Purpose                                        |
| ------------ | ---------------------------------------------- |
| `execsnoop`  | Log process starts (who ran what)              |
| `tcpconnect` | Trace TCP connections                          |
| `funccount`  | Count how often a function is called           |
| `profile`    | Sampling CPU usage                             |
| `xfsdist`    | Trace XFS file system I/O                      |
| `cachetop`   | Monitor file system cache hits/misses          |
| `runqlat`    | Check how long processes wait in CPU run queue |

---

<br>
<br>

![bcc](https://i.sstatic.net/9q40T.png)
