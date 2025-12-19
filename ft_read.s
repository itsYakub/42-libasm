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
	jc .L1
    ret
.L1:
	mov r15, rax
	call __errno_location WRT ..plt
    mov [rax], r15
	mov rax, -1
    ret
