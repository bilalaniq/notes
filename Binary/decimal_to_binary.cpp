// -----------------------------decimal to binary-------------------------------
/*
-------------------------------positive no---------------------------
Steps to Convert a Positive Decimal Number to Binary:
1. Divide the decimal number by 2.
2. Record the remainder (it will be either 0 or 1).
3. Repeat the process with the quotient until the quotient is 0.
4. The binary number is the sequence of remainders read from bottom to top.

for example:
Example 1: Convert 13 to Binary
Let's convert the decimal number 13 to binary.

Divide 13 by 2:
Quotient = 6, Remainder = 1
(Record the remainder: 1)

Divide 6 by 2:
Quotient = 3, Remainder = 0
(Record the remainder: 0)

Divide 3 by 2:
Quotient = 1, Remainder = 1
(Record the remainder: 1)

Divide 1 by 2:
Quotient = 0, Remainder = 1
(Record the remainder: 1)

Now, read the remainders from bottom to top:
13 = 1101 in binary.


ther is another way to convet the decimal to binary and that method is using BCD (8421)
but it has its limitasions 
8421 BCD does not represent the full binary form of the number; instead, it represents each decimal digit separately in binary.

lets use BCD to convert 13 to binary
13 → two digits: 1 and 3.
1 = 0001 
3 = 0011 
13 in 8421 BCD = 0001 0011

we will not be using BCD as it converts each seprate no into binary




-------------------------------negative no---------------------------
there are in total 4 ways to convert/represent negative decimal no to binary

1.Two's Complement (the most commonly used method)
2.Sign and Magnitude
3.One's Complement
4.Excess-K (Bias) Representation (but used for floating nos)


--------------------------------Two's Complement----------------------------

to convert negative decimal no to binary we it should go through the following steps (Two's Complement)
1. Find the binary representation of the positive number
2 .Invert all the bits (bitwise NOT)  / one's compliment
3 .Add 1 to the result

lets take -13 as an example 
13 to binary is 0000 1101 in 8 bit system 
now invert all the bits 1111 0010 and then add 1 
1111 0010 + 1 = 1111 0011 which is -13 in binary 



---------------------------------Sign and Magnitude---------------------------
-13 in binary is 1101 

this is called Sign and Magnitude method
0 for positive numbers
1 for negative numbers

as this is an negative no so we will add 1 at the most significant bit so it will become 
 1 1101
where 1 shows that the no is negative


---------------------------------One's Complement---------------------------


there is also another way to convert decimal to binary and that is One's Complement it is same as that of two's compliment but 
with out adding one in the end 
it only involves the following steps
Convert the positive number to binary.
Invert all the bits (flip 0s to 1s and 1s to 0s).

*/
// if you want o learn abbout the difference between one and to compliment click here 
#include"one_vs_two_compliment.cpp"
/*




---------------------------------floating nos-------------------------------

floating-point numbers are usually represented in specialized formats like IEEE 754 
to represent floating no in binary we use

------------------------------------------Excess-K (Bias) Representation----------------------------------

Excess-K is a way of encoding exponents by adding a constant value (called the bias K) to the actual exponent. This allows 
the exponent to be stored as an unsigned integer.

it involves the following steps
1. Convert the Absolute Value to Binary

2. Normalize the Number
Normalization is a process used to adjust the representation of a number in a floating-point format.
The goal of normalization is to express the number in a form where the most significant (left-most) digit is always 1. 
This allows for the most efficient use of the available bits in the mantissa (fractional part).

3. Apply the Bias to the Exponent
4. Find the Mantissa
5. Determine the Sign Bit
6. Combine All Parts


-------------------------positive floating no-------------------
lets take 13.75 as an example 

1. Convert the Number to Binary

>>>>Integer part
13 = 1101
>>>>Fractional part 
0.75 × 2 = 1.5 → take the 1 (first bit)
0.5 × 2 = 1.0 → take the 1 (second bit)
so 0.75 in binary is 0.11 

2. Normalize the Binary Number
The goal is to express it in scientific notation such that the binary point is after the first 1.
1.10111 x 2^3

3. Apply the Bias to the Exponent
For IEEE 754 single-precision (32-bit), the exponent is stored using an 8-bit exponent with a bias of 127.



-------------------------negative floating no-------------------


*/

// now we will learn how to convert binary to decimal click here
#include"binary_to_decimal.cpp"