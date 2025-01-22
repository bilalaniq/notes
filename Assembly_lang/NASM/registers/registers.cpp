// --------------------------registers----------------------------------

/*
Registers are small, high-speed storage locations within the CPU (Central Processing Unit) of a computer.
They are used to store data temporarily during the execution of a program. Registers are the fastest type of 
memory in a computer system because they are located directly within the CPU and can be accessed
much more quickly than main memory (RAM).

size also depend upon the architechture of the cpu 
the 32 bit machines has 32 bit registers and 64 bit machines has 64 bit registers

backword compatibility is maintained by allowing access to subset of registers so 32 bit code still runs 
on 64 bit machines as because the processor can treat half of the 64 bit register though it was a 32 bit 
register
*/


// ---------------------------------some common registers and there uses --------------------------------
/*
>>eax (Accumulator Register): Used for arithmetic operations, storing function 
return values and passing arguments.Some instructions, like mul (multiply) and div (divide)
implicitly use eax as one of their operands or to store the result.

>>ebx (Base Register): Often used as a pointer to data in memory, particularly 
for accessing arrays or structures.

>>ecx (Count Register): Frequently used as a loop counter in iterative operations or 
for storing temporary data.

>>edx (Data Register): Similar to eax, used for arithmetic and logical operations.

>>esi (Source Index Register): Commonly used for string and memory operations
typically holding the source address.

>>edi (Destination Index Register): Commonly used for string and memory operations
typically holding the destination address.

>>ebp (Base Pointer Register): Often used as a frame pointer for accessing 
function parameters and local variables on the stack.

>>esp (Stack Pointer Register): Points to the top of the stack and is involved in managing 
the stack, especially during function calls and returns.

>>eip (Instruction Pointer Register): Holds the memory address of the next instruction to be executed.

>>Flags Register (EFLAGS): Contains status flags indicating the outcome 
of arithmetic, logical, and comparison operations.

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>some special regiters are
eip (Instruction Pointer Register)
eflags (Flags Register)
cs, ds, es, fs, gs (Segment Registers)
ss (Stack Segment Register)
eflags (Flags Register)
cr0, cr2, cr3, cr4 (Control Registers)
dr0, dr1, dr2, dr3, dr6, dr7 (Debug Registers)
tr (Task Register)
ldtr (Local Descriptor Table Register)

*/