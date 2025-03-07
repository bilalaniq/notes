# Compiler and Linker settings
NASM = nasm
LD = ld

# Compiler flags
NASMFLAGS = -f elf32
NASMFLAGSDEBUG = -f elf32 -g -F dwarf

# Linker flags
LDFLAGS = -m elf_i386 -s
LDFLAGSDEBUG = -m elf_i386 -g

# Set the default name of the program here (without extension)
target ?= test

# Default object file name (based on the target name)
OBJECT = $(target).o
OBJECTDEBUG = $(target).o.debug

# Default target: Build the executable from any .asm file
%.o: %.asm
	$(NASM) $(NASMFLAGS) $< -o $@

# Link the regular executable (without .exe extension for Linux)
$(target): $(OBJECT)
	$(LD) $(LDFLAGS) -o $(target) $(OBJECT)

# Link the debug executable (with debug information)
debug: $(OBJECTDEBUG)
	$(LD) $(LDFLAGSDEBUG) -o $(target) $(OBJECTDEBUG)

# Explicit rule for debug object file (using NASMFLAGSDEBUG)
$(OBJECTDEBUG): $(target).asm
	$(NASM) $(NASMFLAGSDEBUG) $< -o $(OBJECTDEBUG)

# The default goal is to build the regular executable
all: $(target)

# Clean up generated files
clean:
	rm -f $(OBJECT) $(target) $(OBJECTDEBUG) $(target)
