
### Decimal to Binary

#### Positive Numbers

**Steps to Convert a Positive Decimal Number to Binary:**
1. Divide the decimal number by 2.
2. Record the remainder (it will be either 0 or 1).
3. Repeat the process with the quotient until the quotient is 0.
4. The binary number is the sequence of remainders read from bottom to top.

**Example 1: Convert 13 to Binary**
Let's convert the decimal number 13 to binary.

- Divide 13 by 2:  
  Quotient = 6, Remainder = 1  
  (Record the remainder: 1)

- Divide 6 by 2:  
  Quotient = 3, Remainder = 0  
  (Record the remainder: 0)

- Divide 3 by 2:  
  Quotient = 1, Remainder = 1  
  (Record the remainder: 1)

- Divide 1 by 2:  
  Quotient = 0, Remainder = 1  
  (Record the remainder: 1)

Now, read the remainders from bottom to top:  
13 = `1101` in binary.

There is another way to convert the decimal to binary using **BCD (8421)**, but it has limitations.  
8421 BCD does not represent the full binary form of the number; instead, it represents each decimal digit separately in binary.

Let's use BCD to convert 13 to binary:  
13 → two digits: 1 and 3.  
1 = `0001`  
3 = `0011`  
13 in 8421 BCD = `0001 0011`

We will not use BCD as it converts each separate number into binary.


#### Negative Numbers

There are in total 4 ways to convert/represent negative decimal numbers to binary:

1. Two's Complement (the most commonly used method)
2. Sign and Magnitude
3. One's Complement
4. Excess-K (Bias) Representation (but used for floating-point numbers)


##### Two's Complement

To convert a negative decimal number to binary using **Two's Complement**, follow these steps:
1. Find the binary representation of the positive number.
2. Invert all the bits (bitwise NOT) / one's complement.
3. Add 1 to the result.

**Example: Convert -13 to Binary**

- 13 in binary is `0000 1101` in an 8-bit system.
- Invert all the bits: `1111 0010`.
- Add 1:  
  `1111 0010 + 1 = 1111 0011`, which is `-13` in binary.


##### Sign and Magnitude

In the **Sign and Magnitude** method:
- The binary representation of 13 is `1101`.
- 0 is used for positive numbers and 1 for negative numbers.
- As this is a negative number, we add 1 at the most significant bit, so it becomes `1 1101`, where `1` indicates that the number is negative.


##### One's Complement

**One's Complement** is similar to Two's Complement, but without adding 1 at the end. It only involves the following steps:
1. Convert the positive number to binary.
2. Invert all the bits (flip 0s to 1s and 1s to 0s).
