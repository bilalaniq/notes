### One's Complement vs Two's Complement

#### Why Two's Complement is Preferred Over One's Complement

One's complement has the problem of having two representations for zero: `00000000` and `11111111` both represent zero (positive zero and negative zero). This is problematic because there are two different ways to represent zero, which can confuse computers or cause errors during calculations.

On the other hand, Two's Complement has only one representation for zero: `00000000`, which represents both positive and negative zero. This makes sense because zero is neither positive nor negative, so it should be represented as a single value.

This is the main reason Two's Complement is preferred over One's Complement.

#### The Role of Adding 1

Inverting the bits gives you the One's Complement, which is a "negative" version of the number, but it’s not correct for binary arithmetic. Adding 1 to the inverted bits creates the Two's Complement, which is the proper representation of a negative number in binary. This allows binary arithmetic operations like addition and subtraction to work correctly without needing extra adjustments.

Without adding 1, you would encounter an overflow or "wrap-around" problem. Overflow or wrap-around happens when the result of an operation exceeds the range that can be represented with the given number of bits. This usually occurs when you try to represent numbers that are too large (positive or negative) for the available bit width.

#### Inverting Bits Alone (One's Complement)

When you take the One's Complement of a number (which means flipping all the bits), you get a value that is "close" to the negative counterpart, but it’s not exactly correct for binary arithmetic.

Let’s say we’re working with an 8-bit system, and we want to represent -5 starting from +5:

- +5 in binary (8-bit):  
  `00000101`

- Inverting the bits (One's Complement):  
  Flip all bits: `11111010`

This result (`11111010`) is close to the negative version of 5, but it’s not the correct negative value. If we were to add `11111010` (One's Complement of +5) to `00000101` (+5), the result wouldn’t be the expected value of 0, because the negative number isn’t quite correct yet.

This is where the wrap-around or overflow issue comes into play. When you invert the bits, you're not correctly "wrapping" the number into the negative range properly. This can cause problems in calculations, like adding numbers together.

The "+1" step after inverting the bits fixes this problem and ensures that negative numbers are represented correctly in Two's Complement.

#### Example with -5

We already have the One's Complement of +5, which is `11111010`.  
Now, let’s add 1 to it:

- Add 1 to the One's Complement result:  
  `11111010 + 1 = 11111011`

Now, `11111011` is the correct Two's Complement representation of -5.

When you add this with +5, the result will be 0:

```
  00000101
+ 11111011
-------------
  00000000
```

This shows why Two's Complement is preferred over One's Complement.

#### In Summary

One's Complement has two flaws:
1. It cannot represent 0 correctly. This creates unnecessary complexity in both hardware implementation and binary arithmetic.
2. Complexity in binary arithmetic, as the negative counterpart isn't represented correctly, causing potential overflow or wrap-around problems.
