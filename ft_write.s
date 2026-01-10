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
