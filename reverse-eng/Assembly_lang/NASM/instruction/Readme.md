1. **Data Movement Instructions**:
   - `MOV` – Move data from source to destination
   - `PUSH` – Push data onto the stack
   - `POP` – Pop data from the stack
   - `XCHG` – Exchange the values of two operands
   - `LEA` – Load effective address
   - `MOVSX` – Move with sign extension
   - `MOVZX` – Move with zero extension

2. **Arithmetic Instructions**:
   - `ADD` – Add two operands
   - `SUB` – Subtract one operand from another
   - `MUL` – Unsigned multiplication
   - `IMUL` – Signed multiplication
   - `DIV` – Unsigned division
   - `IDIV` – Signed division
   - `INC` – Increment operand by 1
   - `DEC` – Decrement operand by 1
   - `NEG` – Negate operand
   - `CMP` – Compare two operands
   - `TEST` – Perform bitwise AND without storing the result

3. **Logical Instructions**:
   - `AND` – Perform bitwise AND
   - `OR` – Perform bitwise OR
   - `XOR` – Perform bitwise XOR
   - `NOT` – Perform bitwise NOT (one's complement)

4. **Control Flow Instructions**:
   - `JMP` – Jump to another instruction (unconditional)
   - `JE/JZ` – Jump if equal or zero (conditional)
   - `JNE/JNZ` – Jump if not equal or not zero
   - `JG/JNLE` – Jump if greater
   - `JL/JNGE` – Jump if less
   - `JGE` – Jump if greater or equal
   - `JLE` – Jump if less or equal
   - `CALL` – Call a procedure (subroutine)
   - `RET` – Return from a procedure
   - `LOOP` – Loop with a count check
   - `NOP` – No operation (used for padding or debugging)

5. **String Instructions**:
   - `MOVS` – Move string data
   - `CMPS` – Compare strings
   - `SCAS` – Scan a string for a byte or word
   - `LODS` – Load a string byte or word into the accumulator
   - `STOS` – Store a byte or word from the accumulator into the string

6. **Stack Instructions**:
   - `PUSH` – Push a value onto the stack
   - `POP` – Pop a value from the stack
   - `ENTER` – Set up a stack frame for a procedure
   - `LEAVE` – Clean up a stack frame

7. **Flag Control Instructions**:
   - `CLC` – Clear the carry flag
   - `STC` – Set the carry flag
   - `CMC` – Complement (toggle) the carry flag
   - `CLI` – Clear the interrupt flag
   - `STI` – Set the interrupt flag
   - `CLD` – Clear the direction flag
   - `STD` – Set the direction flag

8. **Interrupt Instructions**:
   - `INT` – Generate a software interrupt
   - `INTO` – Interrupt on overflow
   - `IRET` – Return from interrupt

9. **Floating Point Instructions** (if using FPU or SIMD):
   - `FLD` – Load a floating point value
   - `FST` – Store a floating point value
   - `FADD` – Add floating point values
   - `FSUB` – Subtract floating point values
   - `FMUL` – Multiply floating point values
   - `FDIV` – Divide floating point values

10. **SIMD (MMX, SSE, AVX) Instructions**:
    - `MOVAPS` – Move aligned packed single-precision floating-point values
    - `MOVD` – Move a doubleword between registers
    - `ADDPS` – Add packed single-precision floating-point values
    - `PSHUF` – Shuffle packed data in registers