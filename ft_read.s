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
	xor rax, rax
	syscall
	; errno
    test rax, rax
	js .L1
    ret
.L1:
	neg rax
    mov rdi, rax
    push rdi
	call __errno_location WRT ..plt
    pop rdi
    mov [ rax ], rdi
	mov rax, -1
    ret
