section .text

global ft_strlen

; rdi -> const char *s
ft_strlen:
	; stack setup
	push rbp
	mov rbp, rsp

	mov rax, 0				; register size_t result;
.L2:
	inc rax					; result++;
	cmp byte [rdi + rax], 0	; while (*(s + result))
	jne .L2

	; stack dispose
	pop rbp
	ret
