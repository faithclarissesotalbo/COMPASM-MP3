section .text
global _CheckInput

_CheckInput:
    
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    cmp eax, 01
    jl INV
    cmp eax, 05
    jg INV
    jmp END
INV:
    mov eax, 11111111
END:    
    leave
    ret