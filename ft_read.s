section .text

global ft_read

; rdi -> int fd
; rsi -> void *buf
; rdx -> size_t count
ft_read:
	mov rax, 0
	syscall
