// ------------------------------BitwiseOperations.cpp----------------------------------
/*
Bitwise operators in C++ are used to manipulate individual bits of integral data types like `int`, `char`, `long`, etc. They 
operate at the binary level, making them useful for low-level programming tasks such as hardware interfacing, cryptography, and 
performance optimization.

Here’s a detailed explanation of the bitwise operators in C++:

---

### **1. Bitwise AND (`&`)**
- Performs a bit-by-bit AND operation.
- If both bits are `1`, the result is `1`; otherwise, it is `0`.

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    0   |
|   1   |   0   |    0   |
|   1   |   1   |    1   |

**Example**:
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011
    int result = a & b; // Binary: 0001
    cout << "a & b = " << result << endl; // Output: 1
    return 0;
}
```

---

### **2. Bitwise OR (`|`)**
- Performs a bit-by-bit OR operation.
- If either bit is `1`, the result is `1`.

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    1   |
|   1   |   0   |    1   |
|   1   |   1   |    1   |

**Example**:
```cpp
int result = a | b; // Binary: 0111
// Output: 7
```

---

### **3. Bitwise XOR (`^`)**
- Performs a bit-by-bit exclusive OR operation.
- The result is `1` if the bits are different, otherwise `0`.

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    1   |
|   1   |   0   |    1   |
|   1   |   1   |    0   |

**Example**:
```cpp
int result = a ^ b; // Binary: 0110
// Output: 6
```

---

### **4. Bitwise NOT (`~`)**
- Inverts all the bits of the number.
- Each `0` becomes `1` and each `1` becomes `0`.

**Example**:
```cpp
int a = 5; // Binary: 00000000 00000000 00000000 00000101
int result = ~a; // Binary: 11111111 11111111 11111111 11111010
// Output depends on the size of `int` and is often a negative value in 2's complement.
```

---

### **5. Bitwise Left Shift (`<<`)**
- Shifts the bits of a number to the left by a specified number of positions.
- Adds zeros on the right.

**Syntax**: `value << positions`

**Example**:
```cpp
int a = 5; // Binary: 0101
int result = a << 1; // Binary: 1010
// Output: 10
```

---

### **6. Bitwise Right Shift (`>>`)**
- Shifts the bits of a number to the right by a specified number of positions.
- Behavior differs for signed and unsigned types:
  - **Signed**: Preserves the sign bit (arithmetic shift).
  - **Unsigned**: Fills with zeros (logical shift).

**Syntax**: `value >> positions`

**Example**:
```cpp
int a = 5; // Binary: 0101
int result = a >> 1; // Binary: 0010
// Output: 2
```

---

### **7. Compound Bitwise Assignment Operators**
These combine bitwise operations with assignment:
- `&=`
- `|=`
- `^=`
- `<<=`
- `>>=`

**Example**:
```cpp
int a = 5;
a &= 3; // Same as a = a & 3
// Output: 1
```

---

### **Applications of Bitwise Operators**
1. **Bit Masking**: Toggle, set, or clear specific bits.
2. **Performance Optimization**: Faster than arithmetic operations in many cases.
3. **Encoding/Decoding**: Used in cryptographic algorithms.
4. **Data Compression**: Efficient storage techniques.
5. **Hardware Interfacing**: Setting or reading specific bits in hardware registers.

---

### **Precedence and Associativity**
- **Precedence**: `~` > `<<`, `>>` > `&` > `^` > `|`
- **Associativity**: Left to right, except `~`, which is right to left.

Understanding these operators allows you to work at a lower level of abstraction, enabling efficient manipulation of binary data.




*/