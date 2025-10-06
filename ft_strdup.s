section .text

extern malloc
extern ft_strlen
extern ft_strcpy

global ft_strdup

; rdi -> const char *s
ft_strdup:
	; stack setup
	push rbp
	mov rbp, rsp

	; preserve 's'
	mov rbx, rdi

	call ft_strlen 
	inc rax

	mov rdi, rax
	call malloc

	mov rdi, rax
	mov rsi, rbx
	call ft_strcpy

	; stack dispose
	pop rbp
	ret
