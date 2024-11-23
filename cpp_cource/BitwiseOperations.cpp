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
// first you need to learn how to convert negative nos to binary

1. Find the binary representation of the positive number
2 .Invert all the bits (bitwise NOT) / one's compliment
3 .Add 1 to the result

for example 
lets take an example 5 first we will represent the no 5 in binary which is 0000 0101
then Invert all the bits which will then become 1111 1010 now we will add 1 in this 
1010 + 1 = 1111 1011 which is -5 in binary now we will do left shift on this
1011 << 1 = 1111 0110  which is -10 in decimal



also note that left shift works same for both sighned and unsighned nos

*/
// if you want to learn about decimal to binary conversion and vice versa click here
#include"../Binary/decimal_to_binary.cpp"
/*

---------------------------------------------Bitwise Right Shift (`>>`)----------------------------------
- Shifts the bits of a number to the right by a specified number of positions.
- Behavior differs for signed and unsigned types:
  - **Signed**: Preserves the sign bit (arithmetic shift).
  - **Unsigned**: Fills with zeros (logical shift).


for Unsigned integer

int main()
{
	unsigned int a = 8; // Binary: 0000 0000 0000 1000    in 16 bit
	a >>= 1;   //the binary will become 0000 0000 0000 0100          whcih is 4 in decimal
	std::cout << a;
}

for signed integer
#include <iostream>

int main() {
    int a = -8;  // Binary: 1111 1111 1111 1000 in 16-bit signed integer
    a >>= 1;      // Right shift by 1  1111 1111 1111 1100    which is -4 
    std::cout << a;  // Output the result
}


---------------------------------should you use left and right shift in your code---------------------
If you want to optimize code that involves dividing or multiplying by 2, shifting is often the best approach, as it's much faster 
than using the / or * operators.
but is this correct not because the modren compliers are desighned for efficiency when the encounter an multiplicasion and division by 2
the compilers replace the code like a / 2 or a * 2 by doing left and right shift
so it is wise to use / and * as they are more readable










--------------------------------------------------- Bitwise AND (`&`)------------------------------------
- Performs a bit-by-bit AND operation.
note that it is different from && which is an logical And where this is an single and 
the logical and is used to perform operasion on bool where the single and performs operations on bits
- If both bits are `1`, the result is `1`; otherwise, it is `0`.

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    0   |
|   1   |   0   |    0   |
|   1   |   1   |    1   |



int main() {
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011
    int result = a & b; // Binary: 0001
    cout << "a & b = " << result << endl; // Output: 1
    return 0;
}

now you may be asking that where can this be used in cpp 
it has many use cases some are as followed

>>>>>>>>>masking
Masking is a technique used to isolate specific bits in a number. 
You use the bitwise AND operator with a mask (a number that has certain bits set to 1, which you want to preserve, while 
others are set to 0) to isolate bits of interest.

for example if you want the last 4 bits then we use masking technique 
0000 0000 1110 1001
0000 0000 0000 1111     we will chose such no/binary which has set to 1 bit at which you want to preserve while the rest are set to 0
--------------------     afterapplying and operasion
0000 0000 0000 1001 

by using this tecnique we can preserve the selected bits


lets see this in action in cpp
int number = 0b11011010; // Binary representation of the number
int mask = 0b11110000;   // Mask with bits we want to preserve
int result = number & mask; // The result will preserve only the bits in the mask (high nibble)

std::cout << std::bitset<8>(result) << std::endl; // Output: 11010000

if you want to learn aboot std::bitset click here
*/
#include"std_bitset.cpp"
/*




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