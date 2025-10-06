section .text

global ft_strcpy

; rdi -> char *dst
; rsi -> const char *src
ft_strcpy:
	; stack setup
	push rbp
	mov rbp, rsp

	mov rax, 0
.L2:
	mov rbx, qword [rsi + rax]
	mov qword [rdi + rax], rbx

	inc rax
	cmp byte [rsi + rax], 0
	jne .L2

	; return the 'dest' pointer
	mov rax, rdi

	; stack dispose
	pop rbp
	ret
