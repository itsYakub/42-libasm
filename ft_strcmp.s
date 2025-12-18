section .text

global ft_strcmp

; rdi -> const char *s1
; rsi -> const char *s2
ft_strcmp:
	; variables setup
	mov rax, 0					; register size_t i;

.L2:
	mov bl, byte [rdi + rax]	; *(s1 + i)
	mov cl, byte [rsi + rax]	; *(s2 + i)
	cmp bl, cl
	jne .L3

	inc rax						; i++;
	
	cmp byte [rdi + rax], 0		; while (*(s1 + result))
	jne .L2
	
	cmp byte [rsi + rax], 0		; while (*(s2 + result))
	jne .L2

.L3:
	mov rax, rbx				; *(s1 + i)
	sub rax, rcx				; *(s2 + i)
	ret
