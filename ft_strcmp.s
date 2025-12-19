section .text

global ft_strcmp

; ----------------------------------------- ;
; strcmp - compare two strings              ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = const char *s1                    ;
; > rsi = const char *s2                    ;
; ----------------------------------------- ;
; Output:                                   ;
; > rax = difference between s1 and s2      ;
; ----------------------------------------- ;
ft_strcmp:
    xor rax, rax
.L1:
    mov al, byte [ rdi ]
    cmp al, byte [ rsi ]
    jne .L2
    cmp al, 0
    je .L3
    inc rdi
    inc rsi
    jmp .L1
.L2:
    movzx rcx, byte [ rsi ]
    sub rax, rcx
.L3:
    ret
