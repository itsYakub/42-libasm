extern __errno_location
extern malloc
extern ft_strlen
extern ft_strcpy

section .text

global ft_strdup

; ----------------------------------------- ;
; strdup - duplicate a string               ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = const char *s                     ;
; ----------------------------------------- ;
; Output:                                   ;
; > rax = pointer to the duplicated string  ;
; ----------------------------------------- ;
ft_strdup:
	push rdi
    ; ft_strlen
	call ft_strlen 
    ; malloc
	inc rax
	mov rdi, rax
	call malloc WRT ..plt
    ; errno
    test rax, rax
	js .L1
    ; ft_strcpy
	mov rdi, rax
	pop rsi
	call ft_strcpy
    ret
.L1:
	neg rax
    mov rdi, rax
    push rdi
	call __errno_location WRT ..plt
    pop rdi
    mov [ rax ], rdi
	mov rax, -1
    ret
