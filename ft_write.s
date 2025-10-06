section .text

global ft_write

; rdi -> int fd
; rsi -> const void *buf
; rdx -> size_t count
ft_write:
	; stack setup
	push rbp
	mov rbp, rsp
	
	mov rax, 1
	syscall

	; stack dispose
	pop rbp
	ret
