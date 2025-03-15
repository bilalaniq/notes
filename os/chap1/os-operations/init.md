# init

### **The Init Process in an Operating System**

The **init** (short for _initialization_) process is the **first user-space process** started by the kernel after the system boots. It is responsible for initializing the system and managing system services and processes.

---

### **Key Responsibilities of Init**

1. **Process Management:**

   - The init process is the **parent of all other processes** on the system.
   - Any orphaned process (a process whose parent has terminated) is adopted by init.

2. **System Initialization:**

   - Mounting necessary file systems.
   - Checking and repairing disks (if needed).
   - Loading necessary kernel modules.

3. **Starting Services and Daemons:**

   - Init starts essential system services like networking, logging, and security services.
   - Runs background processes called **daemons**.

4. **Managing Runlevels (SysV Init) or Targets (systemd):**

   - Controls different system states (e.g., multi-user mode, graphical mode, recovery mode).

5. **Handling Shutdown and Reboot Requests:**
   - Ensures services stop properly before shutting down.

---

### **Types of Init Systems**

Different Linux distributions use different init systems:

| **Init System** | **Description**                                                                      | **Used In**                                                 |
| --------------- | ------------------------------------------------------------------------------------ | ----------------------------------------------------------- |
| **SysV Init**   | Traditional init system based on runlevels and shell scripts. Sequential and slow.   | Older Linux distros like RHEL 5, Debian 6                   |
| **Upstart**     | Event-driven init system developed by Ubuntu. Faster than SysV.                      | Ubuntu 9.10–14.04, RHEL 6                                   |
| **systemd**     | Modern, parallelized, and socket-based init system. Uses units instead of runlevels. | Most modern Linux distros (Ubuntu, Debian, Fedora, RHEL 7+) |
| **OpenRC**      | Lightweight init system for Unix-like OS, commonly used in Gentoo.                   | Gentoo, Alpine Linux                                        |

---

### **How to Check the Init System in Linux**

To find out which init system your Linux system is using, run:

```sh
ps -p 1 -o comm=
```

or

```sh
ls -l /sbin/init
```

- If `/sbin/init` points to `/lib/systemd/systemd`, then you are using **systemd**.
- If `/sbin/init` points to `/sbin/init` without a symlink, then it’s likely **SysV Init**.
- If it points to `/sbin/upstart`, you are using **Upstart**.

---

### **Why systemd Replaced SysV Init**

**SysV Init** was slow because it started services sequentially, while **systemd** can start multiple services in parallel, improving boot time. It also includes features like logging (`journald`), socket activation, and dependency management.
