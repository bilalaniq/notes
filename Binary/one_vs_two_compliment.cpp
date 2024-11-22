// ------------------------------one vs two compliment---------------------------
/*
------------why two's compliment is preffered over one's compliment-------------------------

One's complement also has the problem of having two representations for zero. 00000000 and 11111111 both represent zero 
(positive zero and negative zero).
This is a problem because there are two different ways to represent zero, and this can confuse computers or cause errors 
when doing calculations.

where on the other hand the two's copmliment has only one representasion of zero 00000000 represents zero (both positive and negative zero).
a it make sence as zero is nor positive nor negative 

so this is the reason the is two's Complement is prefered over One's Complement

you may be asking what is the role of adding one in the one's complement 
The Role of Adding 1:
Inverting the bits gives you the one's complement, which is a sort of "negative" version of the number, but it's not quite right yet 
because it doesn't reflect the correct negative value for binary arithmetic.
Adding 1 to the inverted bits creates the two's complement, which is the proper representation of a negative number in binary.
The binary representation of negative numbers works with binary addition and subtraction without extra adjustments.


if you donot add 1 you will come across an overflow or "wrap-around" problem 
overflow or wrap-around happens when the result of an operation exceeds the range that can be represented with the given number of bits.
This usually occurs when you try to represent numbers that are too large (positive or negative) for the available space (bit width).

Inverting Bits Alone (One's Complement):
When you take the one's complement of a number (which means flipping all the bits), you get a value that is "close" to the negative 
counterpart, but not exactly correct for binary arithmetic.


Let’s say we’re working with an 8-bit system, and we want to represent -5 starting from +5:

+5 in binary (8-bit):
00000101

Inverting the bits (one's complement):

Flip all bits: 11111010

This result (11111010) is close to the negative version of 5, but it's not the correct negative value. If we were to add 11111010 
(one's complement of +5) to 00000101 (+5), the result wouldn't be the expected value of 0, because the negative number isn't quite 
correct yet.

This is where the wrap-around or overflow issue comes into play. When you invert the bits, you’re not correctly "wrapping" the number
into the negative range properly. This could cause problems in calculations, like adding numbers together.


The "+1" step after inverting the bits fixes this problem and ensures that negative numbers are represented correctly in two's complement.

Continuing with the Example of -5:
We already have the one's complement of +5, which is 11111010.
Now, let’s add 1 to it:

Add 1 to the one’s complement result (11111010):
11111010 + 1 = 11111011

Now, 11111011 is the correct two's complement representation of -5.

now if i add this with +5 we will get 0 answer
  00000101
+ 11111011
-------------
  00000000

so this shows that why two's compliment is prefered over one's compliment

in summary one's compliment has two flaws 
1. it canot represent 0 which make it very complex to intigrate on hard ware 
2. it canot do binary arithmatics


*/