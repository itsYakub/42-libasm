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
	mov rax, 0
.L2:
	mov bl, byte [rdi + rax]
	mov cl, byte [rsi + rax]
	cmp bl, cl
	jne .L1
	inc rax
	cmp byte [rdi + rax], 0
	jne .L2
	cmp byte [rsi + rax], 0
	jne .L2
.L1:
	mov rax, rbx
	sub rax, rcx
	ret
