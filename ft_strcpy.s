section .text

global ft_strcpy

; rdi -> char *dst
; rsi -> const char *src
ft_strcpy:
	mov rax, 0					; register size_t i = 0
.L2:
	mov rbx, qword [rsi + rax]	; *(src + i)
	mov qword [rdi + rax], rbx	; *(dst + i)

	inc rax						; i++;
	cmp byte [rsi + rax], 0		; while (*(src + i))
	jne .L2

	mov rax, rdi				; return (dst);
