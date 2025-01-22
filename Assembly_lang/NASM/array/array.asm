section .data
    ; Define an array of 5 integers (4 bytes each)
    array dd 10, 20, 30, 40, 50  ; dd = define double word (4 bytes)
    array_size equ ($ - array) / 4  ; Calculate the number of elements in the array

section .text
    global _start

_start:
    ; Example: Access and modify array elements

    ; Load the base address of the array into ESI
    mov esi, array

    ; Access the first element (array[0])
    mov eax, [esi]  ; eax = 10

    ; Access the second element (array[1])
    mov ebx, [esi + 4]  ; ebx = 20

    ; Modify the third element (array[2] = 100)
    mov dword [esi + 8], 100  ; array[2] = 100

    ; Loop through the array and print each element (for demonstration purposes)
    mov ecx, array_size  ; Number of elements in the array
    mov esi, array       ; Base address of the array

print_loop:
    ; Load the current element into EAX
    mov eax, [esi]

    ; Print the value (this is just a placeholder; actual printing requires syscalls)
    ; For example, you can use `printf` in a C wrapper or Linux syscalls.

    ; Move to the next element
    add esi, 4

    ; Decrement the loop counter
    loop print_loop

    ; Exit the program
    mov eax, 1       ; syscall: exit
    xor ebx, ebx     ; exit code 0
    int 0x80         ; invoke syscall