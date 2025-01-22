section .data
    ; Define an array of 5 integers (4 bytes each)
    array dd 10, 20, 30, 40, 50  ; dd = define double word (4 bytes)

; or i could also do it by using labels it doesthe same work 
    ; array: dd 10, 20, 30, 40, 50

    ; With :: array: is a label followed by the data definition.
    ; Without :: array is still a label, but the colon is omitted for convenience.

;in short both are labels

    array_size equ ($ - array) / 4

; $ symbol represents the current address of the instruction pointer (essentially the address of the current
; instruction).

section .text
    global _start

_start:

    ; Load the base address of the array into ESI
    mov esi, array

    ; esi: This is a register in the x86 architecture. Specifically, ESI stands for Extended Source Index. 
    ; It's commonly used to hold addresses for string or array operations and is often used as a pointer to an
    ; array or a location in memory.

    ; Access the first element (array[0])
    mov eax, [esi]  ; eax = 10

    ; Access the second element (array[1])
    mov ebx, [esi + 4]  ; ebx = 20

    ; Modify the third element (array[2] = 100)
    mov dword [esi + 8], 100  ; array[2] = 100


    ; Exit the program
    mov eax, 1       ; syscall: exit
    xor ebx, ebx     ; exit code 0
    int 0x80         ; invoke syscall