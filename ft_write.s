section .text

extern __errno_location

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
	; check if error has occured...
	cmp rax, 0
	jl .L1
.L0:
	; stack dispose
	pop rbp
	ret
.L1:
	; process an error and assign errno...
	neg rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov rax, -1
	jmp .L0
