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
	jc .L1
    ; ft_strcpy
	mov rdi, rax
	pop rsi
	call ft_strcpy
    ret
.L1:
	mov r15, rax
	call __errno_location WRT ..plt
    mov [rax], r15
	mov rax, -1
    ret
