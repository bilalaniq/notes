// -----------------------------binary to decimal------------------------------
/*
-------------------------------positive no---------------------------
to convert the binary no to deciml follow the following steps
1. Write down the binary number
2. Label each bit with its corresponding power of 2

lets take an example 13 
which is 00000000 00000000 00000000 00001101 in 32 bit system
1   1   0   1                  the rest are 0 so we are skiiping them
2^3 2^2 2^1 2^0

3. Multiply each bit by its corresponding power of 2:

1 × 2^3 = 1 × 8 = 8
1 × 2^2 = 1 × 4 = 4
0 × 2^1 = 0 × 2 = 0
1 × 2^0 = 1 × 1 = 1

4. Add up the results: Now, add all the values:

8 + 4 + 0 + 1 = 13

The binary number 00000000 00000000 00000000 00001101 equals 13 in decimal.

the most significant it is 0 which shows that the no is positive

-------------------------------negative no---------------------------
as we know that the two compliment is the most common way to represnt decimal no both positive and negative in form of binary so 
we will be converting two compliment to decimal
it includes the following steps

1. Check the Most Significant Bit (MSB):

The MSB (the leftmost bit) determines whether the number is positive or negative
If the MSB is 0, the number is positive, and you can directly convert it to decimal.
If the MSB is 1, the number is negative, and you need to apply the two's complement process to get the positive magnitude of the number
and then apply the negative sign.

2.Invert the bits and add 1

lets take an example which takes 11111111 11111111 11111111 11110011 (-13) as an example 
first we will see the MSB which is 1 which mean that the no is negative 
then we will invert all the bits 
which will give us 
00000000 00000000 00000000 00001100

and than we will add 1
00000000 00000000 00000000 00001100
                                 +1
------------------------------------
00000000 00000000 00000000 00001101
 
Multiply each bit by its corresponding power of 2:

1 × 2^3 = 1 × 8 = 8        skiping the 0 
1 × 2^2 = 1 × 4 = 4
0 × 2^1 = 0 × 2 = 0
1 × 2^0 = 1 × 1 = 1

8 + 4 + 0 + 1 = 13

MSB was 1 which will indicate that the no is negative 
so we will replace it by -13



*/