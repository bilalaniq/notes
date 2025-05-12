# PWN

## What Is "Pwn"?

In cybersecurity, **"pwn"** (a leetspeak form of “own”) means **gaining control over a system or program**, typically by exploiting a vulnerability.

In CTFs or real-world security, **“pwn” refers to binary exploitation** — the art of manipulating compiled programs to:

- Bypass protections
- Redirect execution flow
- Inject and run malicious code (shellcode)
- Gain shells or access restricted functionality

---

## Why Does Binary Exploitation Work?

Most binaries are written in **C/C++**, which:

- Don't have bounds checking by default
- Allow direct memory manipulation (e.g., `strcpy`, pointer arithmetic)
- Let you overwrite **return addresses**, **function pointers**, and **heap structures**

If a program **trusts user input too much**, it becomes vulnerable to things like:

- Buffer overflows
- Format string bugs
- Use-after-free
- Heap corruption

---

## Key Concepts in Pwn

| Concept                               | Description                                                                                  |
| ------------------------------------- | -------------------------------------------------------------------------------------------- |
| **Buffer Overflow**                   | Overwriting memory past the bounds of a buffer (e.g., to reach return address)               |
| **Return-Oriented Programming (ROP)** | Chaining tiny instruction sequences (gadgets) already in the binary to craft arbitrary logic |
| **Shellcode**                         | Raw machine code injected into memory to do something like spawn a shell                     |
| **NX Bit / DEP**                      | Memory protections that mark stack as non-executable                                         |
| **ASLR**                              | Address Space Layout Randomization – makes exploitation harder by randomizing addresses      |
| **Canary / Stack Protector**          | A random value placed before return address to detect overflows                              |

---

## 🧪 Typical Exploitation Flow

1. **Discover vulnerability** (e.g., buffer overflow)
2. **Control execution** (e.g., overwrite return address)
3. **Bypass protections** (like ASLR or NX)
4. **Inject or redirect to payload** (e.g., shellcode or ROP chain)
5. **Gain shell or read flag**

---

## 🛠️ Common Tools

| Tool                   | Use                                      |
| ---------------------- | ---------------------------------------- |
| `gdb` + `pwndbg/gef`   | Debugging binaries and inspecting memory |
| `pwntools`             | Python library for building exploits     |
| `ropper` / `ROPgadget` | Finding ROP gadgets                      |
| `Ghidra` / `IDA`       | Reverse engineering                      |
| `checksec`             | Shows protections enabled on binary      |
| `strace` / `ltrace`    | Trace syscalls and library calls         |

---

## 🧗 Where Pwn Challenges Come From

- **CTFs** (Capture The Flag) competitions
- **Wargames** (e.g., OverTheWire, pwnable.kr)
- **Real-world software vulnerabilities**
- **pwn.college**, which gamifies learning binary exploitation

---

## Final Thoughts

Pwn is one of the **most powerful and fun** areas of offensive security. It mixes:

- Reverse engineering
- Low-level programming
- Memory architecture knowledge
- Creative problem solving

---


now we will learn differnet pwn concepts individually

---

<br>
<br>
<br>


click [here](./Shellcode/Readme.md) to learn about Shellcode

