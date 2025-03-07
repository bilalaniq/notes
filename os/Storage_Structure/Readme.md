# Storage Structure

The CPU can load instructions only from memory, so any programs must
first be loaded into memory to run. General-purpose computers run most
of their programs from rewritable memory, called main memory (also called
random-access memory, or RAM). Main memory commonly is implemented in
a semiconductor technology called [dynamic random-access memory (DRAM)](./DRAM.md)


Computers use other forms of memory as well. For example, the first program to run on computer power-on is a bootstrap program, which then loads the operating system. Since RAM is volatile—loses its content when power
is turned off or otherwise lost. we cannot trust it to hold the bootstrap program. Instead, for this and some other purposes, the computer uses [electrically erasable programmable read-only memory (EEPROM)]() and other forms of
firmwar —storage that is infrequently written to and is nonvolatile.