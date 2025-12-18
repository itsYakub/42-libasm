extern __errno_location

section .text

global ft_read

; ----------------------------------------- ;
; read - read from a file descriptor        ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = int fd                            ;
; > rsi = void *buf                         ;
; > rdx = size_t count                      ;
; ----------------------------------------- ;
; Output:                                   ;
; > rax = number of bytes read from fd.     ;
; ----------------------------------------- ;
ft_read:
    ; read
	mov rax, 1
	syscall
	; errno
	cmp rax, 0
	jl .L2
.L1:
    ret
.L2:
	neg rax
	push rax
	call __errno_location WRT ..plt
	pop rax
	mov rax, -1
    jmp .L1
