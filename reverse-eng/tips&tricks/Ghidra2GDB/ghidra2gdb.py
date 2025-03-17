def ghidra_to_gdb(ghidra_base, gdb_base, ghidra_addr):
    """Convert a Ghidra address to a GDB runtime address."""
    offset = ghidra_addr - ghidra_base
    gdb_addr = gdb_base + offset
    return hex(gdb_addr)

# Get user input at runtime
ghidra_base = 0x00100000  
gdb_base = int(input("Enter GDB base address (hex): "), 16)
ghidra_addr = int(input("Enter Ghidra target address (hex): "), 16)

# Compute the actual address in GDB
gdb_real_addr = ghidra_to_gdb(ghidra_base, gdb_base, ghidra_addr)
print(f"GDB runtime address: {gdb_real_addr}")
