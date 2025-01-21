// --------------------------------------------assembly language ---------------------------------
/*
 Assembly language is a low-level programming language that is closely tied to the 
 architecture of a specific computer's hardware.

The extension for an assembly language file can vary depending on the specific assembler being used or personal preference. However, 
some common extensions for assembly language files include:

1. `.asm`: This is a widely used extension for assembly language source files.
2. `.s`: Another common extension, particularly in Unix-like systems.
3. `.asmx`: This extension is sometimes used to indicate extended assembly files.

These are just a few examples, and the choice of extension may vary depending on the conventions of the development environment or 
the preferences of the programmer.


It provides a human-readable representation of machine code instructions, which are the basic operations understood 
by a computer's central processing unit (CPU).*/ 

// this mean that the  cpu of different companies have different types of assemblly language for example 


/*
Intel x86-x64 Assembly : for intel pcs
ARM Assembly: for ARM processeres
MIPS Assembly: used for MIPS
PowerPC Assembly: used in embedded systems.
SPARC Assembly
Motorola 68k Assembly
RISC-V Assembly:
Z80 Assembly: 
*/  
// if you want to learn about differt assemblly lang click here
#include"assembly_synatax.cpp"
// but here we are gona start Intel x86 Assembly language as i have an intel processor


// --------------------------------data flow from RAM to CPU and vice versa-----------------------
/*
Data flow between the CPU and RAM (Random Access Memory) involves several steps and components, primarily governed by the system
architecture. Here’s a simplified overview of how this process works:

### 1. **Data Request**

- **CPU Initiates a Request**: When the CPU needs data (e.g., to perform calculations or execute instructions), it sends a request 
to the memory controller. This request includes the address of the data in RAM.

### 2. **Memory Addressing**

- **Address Bus**: The CPU uses the address bus to communicate the specific address of the data it requires. The address bus is a 
set of wires that carry the address signals from the CPU to the RAM.

### 3. **Memory Controller**

- **Accessing RAM**: The memory controller receives the address from the CPU and translates it into a command to access the corresponding
location in RAM. It then enables the appropriate memory chip and row/column to access the requested data.

### 4. **Data Transfer from RAM to CPU**

- **Data Bus**: Once the memory controller accesses the requested data, it sends that data back to the CPU over the data bus.
The data bus is a set of wires that carry the actual data signals between the CPU and RAM.

### 5. **CPU Processing**

- **Data in CPU**: The CPU receives the data and can now use it for processing. This might involve calculations, logic operations, 
or other tasks depending on the instruction being executed.

### 6. **Writing Data Back to RAM**

- **Output from CPU**: If the CPU needs to write data back to RAM (e.g., storing results of calculations), it prepares the data to be 
sent back to memory.
- **Addressing Again**: The CPU sends the address where the data should be stored and the data itself over the data bus.
- **Memory Controller Handles Write**: The memory controller receives this information and writes the data to the specified address
in RAM.

### 7. **Cache Considerations**

- **CPU Cache**: Modern CPUs often use cache memory (L1, L2, L3 caches) to speed up data access. The cache stores frequently accessed 
data closer to the CPU, reducing the need to access RAM. If the CPU finds the required data in the cache, it can skip the RAM access 
entirely.

### Summary

The flow of data from RAM to the CPU and vice versa involves a combination of address , data buses, the memory controller, and 
potentially the use of CPU cache to optimize access speeds. This process is crucial for the overall performance of a computer system,
as it dictates how efficiently the CPU can access the data it needs to perform tasks.


           +------------------------------------+
           |                CPU                 |
           +------------------------------------+
           |              L1 Cache              |
           +------------------------------------+
           |              L2 Cache              |
           +------------------------------------+
           |              L3 Cache              |
           +------------------------------------+
                            |                                    
                            |
                            v
           +------------------------------------+
           |        Memory Controller           |
           +------------------------------------+
           |   Address Bus                      |----------+                 +----------------------+
           +------------------------------------+          |                 |                      |
           |   Control Bus                      |----------+---------------->|         RAM          |   
           +------------------------------------+          |                 |                      |
           |    Data Bus                        |----------+                 +----------------------+
           +------------------------------------+
                            
          




*/
// if you want to learn about memory learn about memory control click here
#include"memory_control.cpp"
//if you want to learn about cache click here
#include"cache.cpp"

// ----------------------------------registers-------------------------------
#include"registers.cpp"

// -----------------------------stack---------------------------------------
#include"stack.cpp"

// --------------------------------------------flags--------------------------------------------
#include"Flags.cpp"


// ---------------------------------common comands of assemblly language---------------------------
/*
>>>>>>>>>>>>> push: is used to push a value onto the stack
example = push eax
we are pushing the value of the eax on the stack

>>>>>>>>>>>> Pop: is used to remove an item from the stack 
example = pop eax
we are poping the value of eax from the stack

>>>>>>>>>>>> call : used to call a function
example = call function_name (adress_of_function)
it will simply call the function

>>>>>>>>>>>>>>>> mov : it is used to move the digit to a register
example = mov eax,100    
here we are moving 100 into eax register

>>>>>>>>>>>sub : it is used to substraction
example = sub eax,10
here i am substracting the 100 which is store in eax as from the above mov example with 10
it will alter the value of ebx so the value of ebx will become 90

>>>>>>>>>>>>> add : it is used to add two registers
example= add eax,10 
now the value of eax will become 100

>>>>>>>>>>> mul : multiplication
example = 
mov eax, 10   ; Load eax with 10
mov ebx, 2    ; Load ebx with 2
mul ebx       ; this will multiply ebx with eax and result will be stored in eax

-----------Some instructions, like mul (multiply) and div (divide)implicitly 
-----------use eax as one of their operands or to store the result.

>>>>>>>>>>>> div : division
example = 
mov eax, 10   ; Load eax with 10
mov ebx, 2    ; Load ebx with 2
div ebx 
; After execution, eax will contain the quotient (10 ÷ 2 = 5)
; and edx will contain the remainder (10 % 2 = 0)

>>>>>>>>>>>>>>> [pointer]
mov dword ptr [b],2
b acts as a pointer (but are not pointers) because it holds a memory address
[ ]it indicates that you are referencing the memory location where 
 the value of the variable or register is stored.


cmp : used to compare values of two registers
syntax = cmp destination, source
example = cmp eax,10
this will compare the 10 with the value inside the eax
cmp does not store the result of the comparison anywhere; it only updates the flags.


>>>>>>>>>>>>> jmp : stand for jump it is used in conditions
forexample = take a if condition 
if(a == 1)
{
    cout << a <<endl;
}else
{
    cout << b <<endl;
}
now here if a is not equal to 1 then the compiler will jump to else condition
-------------------------------jump conditions----------------------------------------------
when we compare two registers it than set flags according to the given conditions which are then 
used by the jump condition to weather jump or not

>>>>>>je (jump if Equal) : 
example = 
cmp eax, ebx   ; Compare the values in EAX and EBX
je  [adress] ; Jump to adress and execute the adressed code if EAX is equal to EBX

>>>>>>jne (Jump if Not Equal): 
example = 
cmp eax, ebx    ; Compare the values in EAX and EBX
jne  [adresss] ; Jump to given adress if EAX is not equal to EBX

>>>>>> jg (Jump if Greater) : 
example = 
cmp eax, ebx   ; Compare the values in EAX and EBX
jg  [adress] ; Jump to given adress if EAX is greater than EBX

>>>>>>>jl ("jump if less than")
example = 
cmp eax, ebx    ; Compare the values in EAX and EBX
jl  [adress] ; Jump to given adress if EAX is less than EBX

>>>>>>>jle (Jump if Less Than or Equal): 

>>>>>>>jge (Jump if Greater Than or Equal):

>>>>>>>jb (Jump if Below) :

>>>>>>>ja (Jump if Above): 

>>>>>>>jbe (Jump if Below or Equal):

>>>>>>>jae (Jump if Above or Equal):





*/

// -----------------------------------------variables------------------------------
// ptr is a keyword  used to set the size of the memory operand
/*
>>> dword  = it stores 4 byte or 32 bits of data it can be used to store both float and int
>>> word =  it stores 2 byte or 16-bit    (short int ) [float and int] 
>>> byte = it can store 1 byte or 8 bit of size  [char using ASCAII values]
>>> dword = A quadword-sized data, typically 64 bits or 8 bytes.
>>> tbyte = it is used to store float and has a size of 10 bytes or 80 bits
*/