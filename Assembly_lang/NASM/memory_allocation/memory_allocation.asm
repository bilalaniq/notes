

section .data
    
variable1: dd 5 ; here this is an define word directive used to define an 4 bytes and is initilized as 5 
variable2: dd 5



section .text
global _start
_start:



mov eax , 5  ;moving an no to eax register 

mov ebx , 5

add eax , ebx  ;adding the value in eax and edx 5 + 5 = 10 and storing it in eax register


; we can also do this as 
; memory to register

mov eax , [variable1]   ; The [] is used to dereference a memory location same as pointers(*) in c and cpp

mov ebx , [variable2]

add eax , ebx



;memory to memory XXXX(wrong)

; mov [variable1] , [variable2]  ;this will give error as we cannot move an memory to memory we need to 

; add  [variable1] , [variable2]  ;this will also give an error because we can add two memory


;we can only add register 




;--------------------------------???????????????????????--------------------------------------

;this answer the question why registers are important 
; we have learned that we can give istruction to ram to read or write the problem comes when we have to read and
;write to the ram at the same time so while doing this where will the data go the cpu does not have this much 
;intelligence to store the data in some place
;so register are like the temporary place where the data is stored 



;another question why we cannot move two values stored in an address with out involving registers 
;is because when giving instruction to ram  from cpu we need to send two addresse to add them but we have only one 
;address bus which cn only pass one address at a time 
;so thats also answer the question why we canot add or move two address value with out using registers
;without array exception 





mov eax , 1
xor ebx , ebx
int 0x80