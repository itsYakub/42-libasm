section .text

global ft_strlen

; rdi -> const char *s
ft_strlen:
	mov rax, 0				; register size_t result;
.L2:
	cmp byte [rdi + rax], 0	; while (*(s + result))
	je .L3
	inc rax					; result++;
	jmp .L2

.L3:
	ret
