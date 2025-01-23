;this is an simple example which shows that what will happend if we insert an 16 data to an 32 bit register 
;same goes for the 64 bit


section .data

   

    bit_16 dw 5 ; this is an define word which allocates 16 bit value
    ; if we convert 5 to 16 bit it is 0x0005


    bit_32 dd 5 ; this is an define double word which allocates is 32 bit value
    ;if we convert the 5 to 32 bit it is 0x00000005

section .text
    global _start

_start:

    mov eax , [bit_16] ;moving an 16 bit value into an 32 bit register 
    ;in memory it will look like 0x50005 which is not 5 
    ;so our value has been changes 

    mov ebx , [bit_32]  ;moving an 32 bit value into an 32 bit register
    ; in memory it wil look like 0x5 which is the simplified version of 0x00000005 or 0x05000000(depending on the endian)
 

    mov ebx , 5 ;moving an 32 bit value into an 32 bit register 
    ; in memory it will look like 0x5 which is just same as above



    ;lets see how to fix this problem
    ; The same principles apply to 64-bit registers. If you move a 16-bit or 32-bit value into a 64-bit 
    ; register, you should use movzx or movsx to ensure the upper bits are properly set.

   ;-------------------------------------movzx (Move with Zero Extension)------------------------------------
   ;The upper bits of the destination register are filled with zeros.
   ; When you want to treat the source value as an unsigned integer.

   ;    movzx eax, byte [some_8bit_value]
   ;If some_16bit_value is 0xFFFF (65535 in decimal), ebx will become 0x0000FFFF (65535 in 32 bits).


   ;-------------------------------------movsx (Move with Sign Extension)------------------------------------
   ;The upper bits of the destination register are filled with the sign bit of the source value (0 for positive, 1 for negative).
   ; When you want to treat the source value as a signed integer.

   ;    movsx ebx, word [some_16bit_value]
   ;If some_16bit_value is 0xFFFF (which is -1 in signed 16-bit), ebx will become 0xFFFFFFFF (-1 in 32 bits).





;    Use movzx when the source value is unsigned (e.g., an array index, a count, or any value that cannot be negative).

;    Use movsx when the source value is signed (e.g., a temperature, a delta value, or any value that can be negative).







   movzx eax , word [bit_16]  ; The assembler does not know whether [bit_16] is an 8-bit or 16-bit value
   ;so you need to specify it the word mean that this is an 16 bit value
   ;where for 8 bytes we write byte

   ;for an sighn value we use movsx

   ;but when mov an 32 bit value to an 64 bit register it is differnt from the rest
   ;When you move a 32-bit value into a 64-bit register, the upper 32 bits of the 64-bit register are automatically zero-extended by default.
   ;You don't need to use movzx for 32-bit to 64-bit moves because the zero-extension happens implicitly.



;    mov eax, 0xFFFFFFFF
;    mov rbx, eax  

   ;but when dealing with 32 bit sighned values you need to use movsxd instead of movsx 
   ;and also donot need to specify the size of the value it is done implicitly

;    mov eax, 0xFFFFFFFF  ; Load 32-bit value into EAX
;    movsxd rbx, eax      ; Sign-extend EAX into RBX

    mov eax, 1
    xor ebx, ebx
    int 0x80