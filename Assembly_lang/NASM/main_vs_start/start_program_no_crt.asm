section .text       ; Declare the text (code) section
    global _start   ; Declare _start as the entry point for the program

_start:
    mov eax, 1      ; Syscall number for exit (sys_exit)
    xor ebx, ebx      ; Exit status value (5)
    int 0x80        ; Trigger the interrupt for the system call
