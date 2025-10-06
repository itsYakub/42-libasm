section .text

global ft_read

; rdi -> int fd
; rsi -> void *buf
; rdx -> size_t count
ft_read:
	; stack setup
	push rbp
	mov rbp, rsp
	
	mov rax, 0
	syscall

	; stack dispose
	pop rbp
	ret
