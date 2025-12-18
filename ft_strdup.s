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
	cmp rax, 0
	jl .L2
    ; ft_strcpy
	pop rsi
	mov rdi, rax
	call ft_strcpy
.L1:	
    ret
.L2:
    pop rdi
	neg rax
	push rax
	call __errno_location WRT ..plt
	pop rax
	mov rax, -1
    jmp .L1
