// ---------------------------------flags-------------------------------------
// some common flags
//these flags are set accordig to the jump condition provided
/*
>>>>>>>>>Zero Flag (ZF):it is used for both arithmatic oprations and coparission and logical opratoins(AND ,OR ,XOR)
Set if the result of the operation is zero. Cleared if the result is non-zero.(for add ,sub , mul,div)
the Zero Flag is set if the operands are equal.


>>>>>>>>Sign Flag (SF): Set if the most significant bit (the sign bit) of the result is set (i.e., if the result is negative).
Cleared if the result is positive.

>>>>>>>>Carry Flag (CF): Set if there is a carry-out from the most significant bit during addition or a borrow during subtraction.
Used for unsigned arithmetic.

>>>>>>>Overflow Flag (OF): Set if the signed result is too large (positive overflow) or too small (negative overflow) to be represented in the destination.
Used for signed arithmetic.

>>>>>>>Parity Flag (PF): Set if the least significant byte of the result contains an even number of 1 bits.
Used for error checking.

>>>>>>>Auxiliary Carry Flag (AF): Used for binary-coded decimal (BCD) arithmetic.
Set if there is a carry-out from or borrow into bit 3 to bit 4 during addition or subtraction operations.
For example, if performing a BCD addition results in a carry from bit 3 to bit 4, AF is set.

*/