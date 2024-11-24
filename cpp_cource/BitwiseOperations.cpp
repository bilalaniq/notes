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
	a <<= 2;   //the binary will become 10100          5 x 2^2 = 5 x 4 = 20
	std::cout << a; 
}

bitwise left shift (<<) operator works the same way for both signed and unsigned integers, but there are key differences to be
aware of when dealing with signed integers.
// first you need to learn how to convert negative nos to binary

1. Find the binary representation of the positive number
2. Invert all the bits (bitwise NOT) / one's compliment
3. Add 1 to the result

for example 
lets take an example 5 first we will represent the no 5 in binary which is 0000 0101
then Invert all the bits which will then become 1111 1010 now we will add 1 in this 
1010 + 1 = 1111 1011 which is -5 in binary now we will do left shift on this
1011 << 1 = 1111 0110  which is -10 in decimal

now we will perform left shift on 1 1110 1100 which will give us -100




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
    a >>= 1;      // Right shift by 1    1111 1111 1111 1100    which is -4 
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

you can use this in if codisions 
>>>>>>>>>>>>>Checking if a bit is set (Bit Testing)

You can check if a specific bit in an integer is set (i.e., if it's 1). To do this, you use the bitwise AND operator with a bitmask
where only the bit you are checking is set to 1.

int number = 0b11011010; // Binary representation
int bit_position = 3;    // Position to check (from right, 0-based index)

if (number & (1 << bit_position)) {
    std::cout << "Bit is set." << std::endl;     //this will be printed
} else {
    std::cout << "Bit is not set." << std::endl;
}

if you replace the binary by 0b11010010  the bit is not set will be printed


>>>>>>>>>>>>Clearing a Specific Bit
You can use the bitwise AND operator to clear (set to 0) a specific bit in a number. To do this, you AND the number with a mask 
that has 0 in the target bit position and 1 elsewhere.

int number = 0b11011010;  // Binary representation
int bit_position = 3;     // Bit to clear

number = number & ~(1 << bit_position);  // Clear the 3rd bit

std::cout << std::bitset<8>(number) << std::endl; // Output: 11010010


>>>>>>>>>>>Checking if a Number is Even or Odd
int number = 5;

if (number & 1) {
    std::cout << "Odd" << std::endl;
} else {
    std::cout << "Even" << std::endl;
}

An even number in binary has the least significant bit (rightmost bit) set to 0.
An odd number in binary has the least significant bit set to 1.
for example for 5 

0000 0000 01001
0000 0000 00001
---------------
000000000000001      this is an odd no 


>>>>>>>>>>>>>Efficient Power of Two Check
If you want to check whether a number is a power of two, you can use a bitwise AND operation. A number that is a power of two has 
exactly one 1 bit in its binary representation, so when you subtract 1 from it, the result will have all 1 bits in the positions 
of the original 1 bit and lower.

int number = 16; // Power of 2

if (number > 0 && (number & (number - 1)) == 0) {
    std::cout << "Power of two" << std::endl;
} else {
    std::cout << "Not a power of two" << std::endl;
}



these are some of the few examples which can be used to understand and operator in detail



------------------------------------------------Bitwise OR (`|`)----------------------------------------

- Performs a bit-by-bit OR operation.
- If either bit is `1`, the result is `1`.
it works same as the logical or but logical or works with bools where the the or works on bits

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    1   |
|   1   |   0   |    1   |
|   1   |   1   |    1   |


it can be used in many ways some are as following by looking at them you will be able to easly understan bitwise or

>>>>>>>>>>Setting Specific Bits
Bitwise OR is often used to set specific bits to 1 without affecting other bits.

int main() {
    int x = 5;  // binary: 0101
    int mask = 8;  // binary: 1000 (set 4th bit to 1)
    
    x = x | mask; // Set the 4th bit of x to 1
    //or could used x = x | 1 << 3;

    std::cout << "Result: " << x << std::endl;  // Output: 13 (binary: 1101)
    return 0;
}

>>>>>>>>>>>Combining Flags
Bitwise OR is useful for combining multiple flags (or binary options) that are represented by different bits. Each flag can be 
represented as a power of two, and you can combine them using the OR operator.


const int FLAG_A = 1;     // 0001
const int FLAG_B = 2;     // 0010
const int FLAG_C = 4;     // 0100
const int FLAG_D = 8;     // 1000

int main() {
    int combinedFlags = FLAG_A | FLAG_B;  // Combine FLAG_A and FLAG_B

    std::cout << "Combined Flags: " << combinedFlags << std::endl;  // Output: 3 (0011)
    return 0;
}


>>>>>>>>>>Clearing or Modifying Specific Bits:
You can use Bitwise OR to preserve certain bits and set others to 1. This can be useful in low-level programming when you need 
to ensure that some bits remain unchanged while others are set.


int main() {
    int x = 10;  // binary: 1010
    x = x | 4;    // binary OR with 0100

    std::cout << "Result: " << x << std::endl;  // Output: 14 (binary: 1110)
    return 0;
}

>>>>>>>>>>Permission or State Flags
Bitwise OR is useful for systems that represent permissions or state flags in a compact binary form. For example, in many 
operating systems, file permissions are represented by a series of bits, where each bit represents a different permission 
(read, write, execute). You can use OR to combine permissions.

const int READ = 1;   // 0001
const int WRITE = 2;  // 0010
const int EXECUTE = 4; // 0100

int main() {
    int permissions = READ | WRITE;  // User can read and write
    std::cout << "Permissions: " << permissions << std::endl;  // Output: 3 (0011)

    permissions = permissions | EXECUTE;
    std::cout << "Permissions: " << permissions << std::endl;  // Output: 7 (0111)
    return 0;
}


>>>>>>>>>>>>>Setting Control or Mode Flags:
In embedded systems or hardware control, you may often deal with registers or control flags, where each bit represents a different 
mode or setting. You can use Bitwise OR to set specific modes without affecting others.

const int MODE_A = 1; // 0001
const int MODE_B = 2; // 0010

int main() {
    int controlFlags = 0; // Start with no modes set
    controlFlags = controlFlags | MODE_A | MODE_B; // Enable both modes

    std::cout << "Control Flags: " << controlFlags << std::endl;  // Output: 3 (0011)
    return 0;
}





-------------------------------------------Bitwise XOR (`^`)------------------------------
- Performs a bit-by-bit exclusive OR operation.
- The result is `1` if the bits are different, otherwise `0`.

**Truth Table**:
| Bit 1 | Bit 2 | Result |
|-------|-------|--------|
|   0   |   0   |    0   |
|   0   |   1   |    1   |
|   1   |   0   |    1   |
|   1   |   1   |    0   |


int main() {
    int a = 5;  // Binary: 0101
    int b = 3;  // Binary: 0011
    int result = a ^ b;  // XOR operation
    std::cout << "Result of " << a << " ^ " << b << " = " << result << std::endl;  // Output: 6
    return 0;
}


it has also many use cases for example 

>>>>>>>>>>>>>>>>>>>>>>Swapping Two Variables (without a temporary variable)

One of the classic use cases for the Bitwise XOR operator is to swap the values of two variables without using a temporary variable. 
This is a well-known technique in low-level programming and algorithms.

int main() {
    int a = 5;
    int b = 3;
    
    // Swapping using Bitwise XOR
    a = a ^ b;  // a now becomes 6 (binary: 0101 ^ 0011 = 0110)
    b = a ^ b;  // b now becomes 5 (binary: 0110 ^ 0011 = 0101)
    a = a ^ b;  // a now becomes 3 (binary: 0110 ^ 0101 = 0011)
    
    std::cout << "a: " << a << ", b: " << b << std::endl;  // Output: a: 3, b: 5
    return 0;
}

this also work work for negative nos but it has its limitasions and canot work with floating nos


>>>>>>>>>>>>>>>>>>Finding the Single Non-Duplicated Element:
Bitwise XOR is often used in problems where we need to find the single element that does not have a duplicate in an array.
So, XORing all the elements together will cancel out the duplicates, and only the unique number will remain.

#include <iostream>
#include <vector>

int findSingleNumber(const std::vector<int>& nums) {
    int result = 0;
    for (int num : nums) {
        result ^= num;  // XOR all elements
    }
    return result;
}

int main() {
    std::vector<int> nums = {4, 1, 2, 1, 2};
    int singleNumber = findSingleNumber(nums);
    std::cout << "The single number is: " << singleNumber << std::endl;  // Output: 4
    return 0;
}

but this only work if we have only one single no in the array
but we can over come this problem 


>>>>>>>>>>>>>Detecting Odd or Even Numbers:
#include <iostream>

bool isOdd(int num) {
    return num ^ 1;  // XOR with 1 flips the least significant bit
}

int main() {
    int number = 7;  // Binary: 0111 (odd)
    if (isOdd(number)) {
        std::cout << number << " is odd." << std::endl;  // Output: 7 is odd.
    } else {
        std::cout << number << " is even." << std::endl;
    }

    return 0;
}



>>>>>>>>>>>>>>>Toggling a Specific Bit
int toggleBit(int num, int pos) {
    return num ^ (1 << pos);  // XOR with a mask that has only the target bit set
}

int main() {
    int num = 5;  // Binary: 0101
    int pos = 1;  // Targeting the 2nd bit
    
    // Toggling the 2nd bit
    num = toggleBit(num, pos);  // 0101 ^ 0010 = 0111
    
    std::cout << "Number after toggling the 2nd bit: " << num << std::endl;  // Output: 7 (binary: 0111)
    return 0;
}


>>>>>>>>>>>>>>>>Parity Checking (Even or Odd Parity)

You can use XOR to check if a number has even or odd parity. For example, if you need to check if the number of 1 bits in a number 
is even or odd, you can repeatedly XOR the bits of the number.

bool checkParity(int num) {
    bool parity = false;
    while (num) {
        parity = !parity;   // Flip the parity each time a 1 bit is encountered
        num = num & (num - 1);  // Remove the rightmost 1 bit from num
    }
    return parity;
}

int main() {
    int number = 7;  // Binary: 0111 (odd number of 1s)
    if (checkParity(number)) {
        std::cout << "Odd parity" << std::endl;
    } else {
        std::cout << "Even parity" << std::endl;
    }

    return 0;
}



>>>>>>>>>>>>>>>>>>Cryptographic Applications
XOR is often used in cryptography and encryption algorithms. For example, it can be used in simple XOR-based ciphers to encrypt 
and decrypt messages. XOR is used because of its reversibility: applying the XOR operation twice with the same key will return the
original value.

#include <iostream>
#include <string>

std::string xorCipher(const std::string& input, char key) {
    std::string result = input;
    for (size_t i = 0; i < result.length(); i++) {
        result[i] = result[i] ^ key;  // XOR each character with the key
    }
    return result;
}

int main() {
    std::string text = "Hello";
    char key = 'K';  // Key for XOR cipher

    // Encrypting
    std::string encrypted = xorCipher(text, key);
    std::cout << "Encrypted: " << encrypted << std::endl;

    // Decrypting (XOR again with the same key)
    std::string decrypted = xorCipher(encrypted, key);
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}









---------------------------------Bitwise NOT (`~`)-----------------------------
- Inverts all the bits of the number.
- Each `0` becomes `1` and each `1` becomes `0`.

**Example**:
```cpp
int a = 5; // Binary: 00000000 00000000 00000000 00000101
int result = ~a; // Binary: 11111111 11111111 11111111 11111010
// Output depends on the size of `int` and is often a negative value in 2's complement.






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