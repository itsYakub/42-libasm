section .text

global ft_strcpy

; ----------------------------------------- ;
; strcpy - copy or catenate a string        ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = char *dst                         ;
; > rsi = const char *src                   l
; ----------------------------------------- ;
; Output:                                   ;
; > rax = pointer to dst                    ;
; ----------------------------------------- ;
ft_strcpy:
	mov rax, 0
.L2:
	mov bl, [rsi + rax]
	mov [rdi + rax], bl
	inc rax
	cmp bl, 0
	jne .L2
	mov rax, rdi
    ret
