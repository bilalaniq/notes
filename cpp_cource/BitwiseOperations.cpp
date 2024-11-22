// ------------------------------BitwiseOperations.cpp----------------------------------
/*
Bitwise operators in C++ are used to manipulate individual bits of integral data types like `int`, `char`, `long`, etc. They 
operate at the binary level, making them useful for low-level programming tasks such as hardware interfacing, cryptography, and 
performance optimization.

Here’s a detailed explanation of the bitwise operators in C++:

---

-------------------------------- Bitwise Left Shift (`<<`)-------------------------------------
- Shifts the bits of a number to the left by a specified number of positions.
- Adds zeros on the right.

for example lets take an no 6 which is 0110 in binary when we apply left shift on 0110 it will become 1100 which will be 12
if you are an keen absorver then you will relize that by doing an left shift we are mutiplying the no by 2 
6 x 2 = 12

**Syntax**: `value << positions`

**Example**:
int main()
{
	int a = 5; // Binary: 0101
	a <<= 1;   //the binary will become 1010          5 x 2 = 10
	std::cout << a;  
}

here i have done left shift by one bit i can do more than one shift 
by doing left shift of more than one bit we are multiplying the no by 2^n where the n is the no of bits you want to shift lets see 
an example 

int main()
{
	int a = 5; // Binary: 0101
	a <<= 2;   //the binary will become 1010          5 x 2^2 = 5 x 4 = 20
	std::cout << a;     
}

bitwise left shift (<<) operator works the same way for both signed and unsigned integers, but there are key differences to be
aware of when dealing with signed integers.
// first you need to learn how to convert negative nos to binary(i donot know either 🧑‍💻😒)

1. Find the binary representation of the positive number
2 .Invert all the bits (bitwise NOT)
3 .Add 1 to the result

for example 
lets take an example 5 first we will represent the no 5 in binary which is 0000 0101
then Invert all the bits which will then become 1111 1010 now we will add 1 in this 
1010 + 1 = 1111 1011 which is -5 in binary now we will do left shift on this
1011 << 1 = 1111 0110  which is -10 in decimal

*/
// if you want to learn about decimal to binary conversion and vice versa click here
#include"../Binary/decimal_to_binary.cpp"
/*

---------------------------------------------Bitwise Right Shift (`>>`)----------------------------------
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






--------------------------------------------------- Bitwise AND (`&`)------------------------------------
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