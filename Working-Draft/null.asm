section .data

section .text
global _CheckNull, _CheckLength, _CheckValid, _CheckTerminate

;;; Subroutines ;;;

YES:
    mov eax, 00000001
    ret

NO:
    xor eax, eax
    ret
    
FIN:
    mov eax, 00000009
    ret

;;; CheckNull() START ;;;

_CheckNull:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]
    cmp ebx, 0x0000000a
    jne NON
    call YES
    jmp END
NON:
    call NO
    jmp END

;;; CheckNull() END ;;;
;;; CheckLength() START ;;;

_CheckLength:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]    
    cmp ebx, 0x0000002e
    je SHO
    cmp ebx, 0x0000000a
    je SHO
    cmp ebx, 0x00000000
    je SHO
    call YES
    jmp END
SHO:
    call NO
    jmp END

;;; CheckLength() END ;;;
;;; CheckValid() START ;;;

_CheckValid:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]
    cmp ebx, 0x0000002e
    je DON
    cmp ebx, 0x0000000a
    je DON
    cmp ebx, 0x00000041
    je VAL
    cmp ebx, 0x00000043
    je VAL
    cmp ebx, 0x00000047
    je VAL
    cmp ebx, 0x00000054
    je VAL
    call YES
    jmp END
DON:
    call FIN
    jmp END
VAL:
    call NO
    jmp END

;;; CheckValid() END ;;;
;;; CheckTerminate() START ;;;

_CheckTerminate:
    push ebp
    mov ebp, esp
    mov ebx, [ebp+8]
    cmp ebx, 0x0000002e
    je DOT
    call YES
    jmp END
DOT:
    call NO
    jmp END

;;; CheckTerminate() END ;;;

END:
    leave
    ret