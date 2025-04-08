# Building and Booting an Operating System

When you buy a computer, it usually already has an operating system installed—like Windows or macOS. But what if you want to:

- Install a different OS (like Linux),
- Install multiple OSes (dual boot),
- Or build your own OS from scratch?

Then you have to go through a **system generation** process, which means preparing the OS so it works on your specific hardware.

---

### Steps to Build an Operating System (like Linux)

1. **Write or get the source code**

   - You can write your own OS or download one (e.g., Linux from [kernel.org](https://kernel.org)).

2. **Configure the OS for your hardware**

   - You tell the OS what hardware it's going to run on.
   - In Linux, this is done using `make menuconfig`, which generates a `.config` file.

3. **Compile (build) the OS**

   - This turns the source code into a working "kernel" file (`vmlinuz` in Linux).

4. **Compile kernel modules**

   - These are extra features (like device drivers) that aren’t built directly into the kernel.

5. **Install modules and kernel**

   - Use commands like `make modules_install` and `make install` to move them into the system.

6. **Boot the new OS**
   - Reboot the computer and the new OS starts running.

> If you're just trying Linux, you can also use a **virtual machine** like VirtualBox or VMware instead of installing it directly.

---

### Three Ways OS Can Be Built (System Generation)

| Method                 | Description                                                                      | Used for                                              |
| ---------------------- | -------------------------------------------------------------------------------- | ----------------------------------------------------- |
| 1. **Full Compile**    | Compile entire OS based on specific hardware. Most customizable, slowest.        | Embedded systems (like routers, ATMs).                |
| 2. **Linking Modules** | Pick from precompiled modules and link only what’s needed. Faster, more general. | Most desktop/laptop OS builds.                        |
| 3. **Fully Modular**   | Everything is loadable at runtime (no compile or link). Just configure hardware. | Modern systems with dynamic hardware (plug-and-play). |

---

## **Booting the System (Boot Process)**

After the OS is built, it has to be **booted**, i.e., loaded into the computer’s memory and started. But how does the system know what to load?

### 1. **Boot Loader (Bootstrap Program) Starts**

When the computer is powered on or restarted, the first code that runs isn't the operating system—it’s the **firmware** (like **BIOS** or **UEFI**). This firmware performs some basic checks, like whether memory is working (POST – Power-On Self Test). After that, it looks for the **boot loader**—a small, low-level program responsible for **loading the OS kernel** into memory.

- In older systems using BIOS, the boot loader resides in the **Master Boot Record (MBR)**.
- In modern systems using UEFI, the boot loader is an **.efi file** stored in the **EFI system partition (ESP)**.

Boot loaders like **GRUB** (for Linux) or **Windows Boot Manager** are flexible. They can present a menu to the user to choose between multiple operating systems or kernels.

---

### 2. **Kernel is Loaded**

Once the boot loader has located the **OS kernel** (for example, `/boot/vmlinuz` in Linux), it **loads it into RAM**. This kernel is usually compressed to save space and is **decompressed in memory**.

The kernel is the **core part of the operating system**. It has complete control over the system and is responsible for managing hardware, processes, memory, and other system resources.

After loading, the boot loader **hands control over to the kernel**. At this point, the kernel takes over and begins executing.

---

### 3. **Kernel Initializes Hardware**

Now that the kernel is in charge, it begins **hardware initialization**. This step is also called **hardware abstraction and probing**.

- It sets up the **CPU**, **memory management** (RAM), and **I/O devices**.
- It loads drivers for hardware like keyboards, mice, storage controllers, USB devices, etc.
- In Linux systems, it may temporarily use a **RAM-based file system** like **initramfs** to load drivers that are not built into the kernel itself.

This step ensures that the OS can interact with the computer’s physical components correctly and efficiently.

---

### 4. **Root File System is Mounted**

Once the necessary drivers are loaded, the kernel mounts the **real root file system** (like `/dev/sda1`), which is the main area where the OS is installed.

- It stops using the temporary initramfs (in regular Linux setups).
- The root file system contains the full operating system: `/bin`, `/etc`, `/home`, `/lib`, etc.

Mounting the root file system is crucial because:

- It gives the system access to essential files and programs.
- It allows the system to start the first user-space process (like **`systemd`** in modern Linux), which brings up all other services.

At this point, the system is almost fully operational and will eventually reach the **login screen** or start running background services.

---

### BIOS vs UEFI

| BIOS                                     | UEFI                                    |
| ---------------------------------------- | --------------------------------------- |
| Old-style firmware                       | Modern replacement                      |
| Loads tiny boot code, then bigger loader | Directly loads OS, faster               |
| Uses boot block                          | Uses EFI system partition               |
| Slower, 16-bit                           | Faster, supports large disks and 64-bit |

---

### Linux Boot Process

1. **BIOS/UEFI starts and loads GRUB**
2. **GRUB (bootloader) loads the kernel**

   - GRUB can let you pick between OSes, change settings, etc.
   - It reads a config file (like `/proc/cmdline`) with kernel parameters.

3. **Compressed Linux kernel (`vmlinuz`) is loaded**
4. **Temporary file system (`initramfs`) is mounted**

   - This contains essential drivers and modules.

5. **Kernel starts `systemd` (or `init`)**
   - This process manages everything else—user logins, services like web servers, etc.

---

### 📱 Android Boot Process (Different from Linux)

- Android uses a different bootloader, **LK (Little Kernel)**, not GRUB.
- It also loads a compressed kernel and an initial RAM file system.
- Unlike Linux, Android **keeps the RAM-based file system as its root**.
- After loading the kernel, Android starts its own `init` and services, then shows the **home screen**.

---

### Recovery/Single-User Mode

All modern OSes—Windows, Linux, macOS, Android, iOS—support special **recovery** or **diagnostic modes**. These let you:

- Fix file system problems
- Run system repairs
- Reinstall the OS
- Access command-line tools even when the main system is broken

---

## Summary

- OS building is the process of compiling, configuring, and installing an OS to match your hardware.
- Booting is the process where the system powers on and loads the kernel.
- GRUB, BIOS, UEFI, initramfs, and systemd all play roles in getting your system up and running.
- Android’s boot process is similar but uses different tools (like LK).
- You can boot Linux directly or in a virtual machine, or modify existing systems.

---

<br>
<br>
<br>

### Why Android's File System Looks Different from Linux

it is because of `Initial RAM File System (initramfs) `

When you open a terminal or a file browser in a traditional Linux system (like Ubuntu), you usually see this full directory structure:

```
/
├── bin
├── etc
├── home
├── lib
├── usr
├── var
├── dev
├── proc
└── tmp
```

But in Android, even if you have root access or use `adb shell`, the file system looks **different** and often **limited**. Here's why:

---

### 1. **Android Uses Initramfs as the Permanent Root**

- As explained earlier, Android loads the kernel and a compressed **initramfs** (initial RAM file system) at boot.
- That **initramfs becomes the permanent root** (`/`) and stays in memory — there’s no switch to a traditional disk-based root file system.
- So, `/` only contains the **basic directories needed to boot** and start Android services.

---

### 2. **Key Parts of the OS Are in Separate Partitions**

Instead of putting everything under `/` like traditional Linux, Android splits the system across **separate partitions**, each mounted at specific mount points. For example:

| Partition | Mount Point | Contents                                                            |
| --------- | ----------- | ------------------------------------------------------------------- |
| `/boot`   | -           | Kernel + initramfs                                                  |
| `/system` | `/system`   | Main OS files (`/system/bin`, `/system/lib`, etc.)                  |
| `/data`   | `/data`     | App data, user data                                                 |
| `/vendor` | `/vendor`   | Device-specific drivers and configurations                          |
| `/sdcard` | `/sdcard`   | User-accessible storage (mapped to internal flash or external card) |

That’s why most Android system files are **not directly under `/bin`, `/lib`, or `/usr`** — they’re under `/system/bin`, `/system/lib`, etc.

---

### 3. **Some Paths Are Missing or Stubbed**

To keep things lean and security-hardened, Android doesn’t include:

- `home` directories (you use `/data/data/<app>` instead).
- Traditional `usr`, `sbin`, etc.
- Some paths exist as **symlinks** or **mount namespaces** managed by Android’s `init`.

---

### 4. **Security and Sandboxing**

Android uses **SELinux** and **App Sandboxing**:

- Limits what each app can see or access.
- Prevents apps from accessing sensitive system areas even if the file system is there.

So even if you manage to view more of the file system, you may be **blocked from reading it** unless you’re rooted.

---

### Summary

Yes — the reason Android doesn't show a "proper" Linux file system layout is:

1. It **never switches** to a full disk-based root file system.
2. It **mounts essential components** (like `/system`, `/data`) later, from their own partitions.
3. The design is **optimized for mobile, security, and performance** — not general-purpose computing like traditional Linux.
