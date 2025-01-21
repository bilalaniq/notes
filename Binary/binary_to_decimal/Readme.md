# Binary to Decimal Conversion

---
## Positive Numbers

To convert the binary number to decimal, follow these steps:

1. Write down the binary number.
2. Label each bit with its corresponding power of 2.

Let's take an example, `13`, which is represented as `00000000 00000000 00000000 00001101` in a 32-bit system.


```
1   1   0   1
2^3 2^2 2^1 2^0
```

1. Multiply each bit by its corresponding power of 2:

```
1 × 2^3 = 1 × 8 = 8
1 × 2^2 = 1 × 4 = 4
0 × 2^1 = 0 × 2 = 0
1 × 2^0 = 1 × 1 = 1
```

4. Add up the results: Now, add all the values:

```
8 + 4 + 0 + 1 = 13
```

The binary number `00000000 00000000 00000000 00001101` equals `13` in decimal.

The most significant bit (MSB) is `0`, which shows that the number is positive.

---

## Negative Numbers

As we know, the two's complement is the most common way to represent decimal numbers, both positive and negative, in binary form. Let's convert a negative number using two's complement.

### Steps to Convert Negative Numbers:

1. Check the Most Significant Bit (MSB):

   The MSB (the leftmost bit) determines whether the number is positive or negative.
   - If the MSB is `0`, the number is positive, and you can directly convert it to decimal.
   - If the MSB is `1`, the number is negative, and you need to apply the two's complement process to get the positive magnitude of the number, and then apply the negative sign.

2. Invert the bits and add 1.

Let's take an example: `11111111 11111111 11111111 11110011` (-13). First, check the MSB. Since the MSB is `1`, the number is negative. Then, invert all the bits:

```
00000000 00000000 00000000 00001100
```

Now, add `1`:

```
00000000 00000000 00000000 00001100
                                 +1
------------------------------------
00000000 00000000 00000000 00001101
```

Multiply each bit by its corresponding power of 2:

```
1 × 2^3 = 1 × 8 = 8
1 × 2^2 = 1 × 4 = 4
0 × 2^1 = 0 × 2 = 0
1 × 2^0 = 1 × 1 = 1
```

Now, add the values:

```
8 + 4 + 0 + 1 = 13
```

Since the MSB was `1`, indicating a negative number, we replace the result with `-13`.

```
The binary number 11111111 11111111 11111111 11110011 equals -13 in decimal.
```
```