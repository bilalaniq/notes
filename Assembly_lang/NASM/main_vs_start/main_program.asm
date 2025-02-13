section .text
    global main      ; Declare the main entry point

main:
    mov eax, 1        ; Exit system call number (sys_exit)
    xor ebx, ebx        ; Status value (return code 5)
    int 0x80          ; Trigger interrupt to invoke the system call