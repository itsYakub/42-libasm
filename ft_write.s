section .text

global ft_write

; rdi -> int fd
; rsi -> const void *buf
; rdx -> size_t count
ft_write:
	mov rax, 1
	syscall
