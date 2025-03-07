

# Data Movement in Assembly: 16-bit, 32-bit, and 64-bit Registers

This document explains the behavior of moving data between registers of different sizes (16-bit, 32-bit, and 64-bit) in x86 and x86-64 assembly. It also covers the use of `movzx`, `movsx`, and `movsxd` instructions for proper zero-extension and sign-extension.

---

## Table of Contents
1. [Introduction](#introduction)
2. [16-bit to 32-bit Movement](#16-bit-to-32-bit-movement)
3. [32-bit to 32-bit Movement](#32-bit-to-32-bit-movement)
4. [16-bit to 64-bit Movement](#16-bit-to-64-bit-movement)
5. [32-bit to 64-bit Movement](#32-bit-to-64-bit-movement)
6. [Key Instructions](#key-instructions)
   - [`movzx`](#movzx)
   - [`movsx`](#movsx)
   - [`movsxd`](#movsxd)
7. [Code Example](#code-example)
8. [Conclusion](#conclusion)

---

## Introduction

In assembly programming, moving data between registers of different sizes requires careful handling to ensure the correct value is preserved. This is especially important when dealing with **16-bit**, **32-bit**, and **64-bit** registers. The x86 and x86-64 architectures provide specific instructions like `movzx`, `movsx`, and `movsxd` to handle zero-extension and sign-extension.

---

## 16-bit to 32-bit Movement

When moving a **16-bit value** into a **32-bit register**, the upper 16 bits of the 32-bit register must be properly set. There are two ways to handle this:

1. **Zero-Extension**:
   - Use `movzx` to fill the upper bits with zeros.
   - This is used for **unsigned values**.

   ```asm
   movzx eax, word [bit_16]  ; Zero-extend 16-bit value to 32 bits
   ```

   Example:
   - If `bit_16` is `0x0005`, `eax` will become `0x00000005`.

2. **Sign-Extension**:
   - Use `movsx` to fill the upper bits with the sign bit (0 for positive, 1 for negative).
   - This is used for **signed values**.

   ```asm
   movsx eax, word [bit_16]  ; Sign-extend 16-bit value to 32 bits
   ```

   Example:
   - If `bit_16` is `0xFFFF` (-1 in signed 16-bit), `eax` will become `0xFFFFFFFF` (-1 in 32-bit).

---

## 32-bit to 32-bit Movement

Moving a **32-bit value** into a **32-bit register** is straightforward. The value is copied as-is.

```asm
mov ebx, [bit_32]  ; Move 32-bit value into EBX
```

Example:
- If `bit_32` is `0x00000005`, `ebx` will contain `0x00000005`.

---

## 16-bit to 64-bit Movement

When moving a **16-bit value** into a **64-bit register**, you must explicitly specify whether to zero-extend or sign-extend the value.

1. **Zero-Extension**:
   - Use `movzx` to fill the upper 48 bits with zeros.

   ```asm
   movzx rax, word [bit_16]  ; Zero-extend 16-bit value to 64 bits
   ```

   Example:
   - If `bit_16` is `0x0005`, `rax` will become `0x0000000000000005`.

2. **Sign-Extension**:
   - Use `movsx` to fill the upper 48 bits with the sign bit.

   ```asm
   movsx rax, word [bit_16]  ; Sign-extend 16-bit value to 64 bits
   ```

   Example:
   - If `bit_16` is `0xFFFF` (-1 in signed 16-bit), `rax` will become `0xFFFFFFFFFFFFFFFF` (-1 in 64-bit).

---

## 32-bit to 64-bit Movement

Moving a **32-bit value** into a **64-bit register** has special behavior in x86-64:

1. **Default Zero-Extension**:
   - The upper 32 bits of the 64-bit register are automatically filled with zeros.
   - No need to use `movzx`.

   ```asm
   mov eax, [bit_32]  ; Load 32-bit value into EAX
   mov rbx, eax       ; Zero-extend EAX into RBX
   ```

   Example:
   - If `bit_32` is `0xFFFFFFFF`, `rbx` will become `0x00000000FFFFFFFF`.

2. **Sign-Extension**:
   - Use `movsxd` to fill the upper 32 bits with the sign bit.

   ```asm
   movsxd rbx, [bit_32]  ; Sign-extend 32-bit value into RBX
   ```

   Example:
   - If `bit_32` is `0xFFFFFFFF` (-1 in signed 32-bit), `rbx` will become `0xFFFFFFFFFFFFFFFF` (-1 in 64-bit).

---

## Key Instructions

### `movzx`
- **Purpose**: Zero-extend a smaller value into a larger register.
- **Use Case**: For **unsigned values**.
- **Syntax**:
  ```asm
  movzx dest, src
  ```
- **Example**:
  ```asm
  movzx eax, word [bit_16]  ; Zero-extend 16-bit to 32-bit
  movzx rax, byte [bit_8]   ; Zero-extend 8-bit to 64-bit
  ```

### `movsx`
- **Purpose**: Sign-extend a smaller value into a larger register.
- **Use Case**: For **signed values**.
- **Syntax**:
  ```asm
  movsx dest, src
  ```
- **Example**:
  ```asm
  movsx eax, word [bit_16]  ; Sign-extend 16-bit to 32-bit
  movsx rax, byte [bit_8]   ; Sign-extend 8-bit to 64-bit
  ```

### `movsxd`
- **Purpose**: Sign-extend a 32-bit value into a 64-bit register.
- **Use Case**: For **signed 32-bit values**.
- **Syntax**:
  ```asm
  movsxd dest, src
  ```
- **Example**:
  ```asm
  movsxd rbx, [bit_32]  ; Sign-extend 32-bit to 64-bit
  ```

---

## Code Example

```asm
section .data
    bit_16 dw 5      ; 16-bit value (0x0005)
    bit_32 dd 5      ; 32-bit value (0x00000005)

section .text
    global _start

_start:
    ; Zero-extend 16-bit to 32-bit
    movzx eax, word [bit_16]  ; EAX = 0x00000005

    ; Sign-extend 16-bit to 64-bit
    movsx rbx, word [bit_16]  ; RBX = 0x0000000000000005

    ; Zero-extend 32-bit to 64-bit (implicit)
    mov ecx, [bit_32]         ; ECX = 0x00000005
    mov rdx, ecx              ; RDX = 0x0000000000000005

    ; Sign-extend 32-bit to 64-bit
    movsxd rsi, [bit_32]      ; RSI = 0x0000000000000005

    ; Exit program
    mov eax, 60               ; syscall: exit
    xor edi, edi              ; status: 0
    syscall
```

---
