section .text
global _start

_start:
    ; Load value 5 into eax
    mov eax, 5

    ; Load value 10 into ebx
    mov ebx, 10

    ; Add ebx to eax (eax = eax + ebx)
    add eax, ebx

    ; Exit the program with return code 0
    mov eax, 1           ; Syscall number for sys_exit
    xor ebx, ebx         ; Exit code 0
    int 0x80             ; Invoke syscall to exit the program
