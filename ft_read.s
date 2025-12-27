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
	mov rax, 0
	syscall
	; errno
	jc .L1
    ret
.L1:
	neg rax
    mov rdi, rax
	call __errno_location WRT ..plt
    mov [ rax ], rdi
	mov rax, -1
    ret
