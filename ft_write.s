extern __errno_location

section .text

global ft_write

; ----------------------------------------- ;
; write - write to a file descriptor        ;
; ----------------------------------------- ;
; Input:                                    ;
; > rdi = int fd                            ;
; > rsi = const void *buf                   ;
; > rdx = size_t count                      ;
; ----------------------------------------- ;
; Output:                                   ;
; > rax = number of bytes written to fd.    ;
; ----------------------------------------- ;
ft_write:
    ; write
	mov rax, 1
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
