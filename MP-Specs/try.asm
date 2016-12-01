section .data
STRLEN db 00

section .text
global _CheckInput
;null, invalid, no termi, length

_CheckInput:
    push ebp
    mov ebp, esp
    mov eax, [ebp+8]
    lea esi, [eax]
    ; check if null input
    mov dl, [esi]
    cmp dl, 00
    je NULL
    ; check string length
    mov dl, [esi+21]
    cmp dl, 00
    jne TOOLONG
    ; count string length
CHECK:
    cmp byte [esi], 00
    je CONTINUE
    inc byte [STRLEN]
    inc esi
    jmp CHECK
    ; check if invalid
CONTINUE:
    xor ecx, ecx
    mov cl, [STRLEN]
    dec cl
    lea esi, [eax]
TRAVERSE:
    mov dl, [esi]
    cmp dl, 0x41
    je NEXT
    cmp dl, 0x43
    je NEXT
    cmp dl, 0x47
    je NEXT
    cmp dl, 0x54
    je NEXT
    jmp INVALID
NEXT:
    inc esi
    loop TRAVERSE
    ; check if no terminator
    inc esi
    mov dl, [esi]
    cmp dl, 0x2e
    jne NOTERM
    jmp END
NULL:
    mov eax, 0x00000001
    jmp END
TOOLONG:
    mov eax, 0x00000002
    jmp END
INVALID:
    mov eax, 0x00000003
    jmp END
NOTERM:
    mov eax, 0x00000004

END:   
    mov eax, 0xffffffff
    leave
    ret