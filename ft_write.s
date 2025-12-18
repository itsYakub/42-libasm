section .text

extern __errno_location

global ft_write

; rdi -> int fd
; rsi -> const void *buf
; rdx -> size_t count
ft_write:
	mov rax, 1
	syscall
	; check if error has occured...
	cmp rax, 0
	jl .L2
.L1:
    ret
.L2:
	; process an error and assign errno...
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
    jmp .L1
