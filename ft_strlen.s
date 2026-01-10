section .text

global ft_strlen

; ----------------------------------------- ;
; strlen - calculate the length of a string ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = const char *s                     ;
; ----------------------------------------- ;
; Output:                                   ;
; > rax = size of the string                ;
; ----------------------------------------- ;
ft_strlen:
	xor rax, rax
.L2:
	cmp byte [rdi + rax], 0
	je .L3
	inc rax
	jmp .L2
.L3:
	ret
