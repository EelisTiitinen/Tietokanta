global print
global input

extern stringLen

section .text

print:
	call stringLen

	mov rdx, rax
	mov rsi, rdi
	mov rdi, 1
	mov rax, 1
	syscall

	ret


input:
	xor rax, rax
	mov rdx, rsi
	mov rsi, rdi
	xor rdi, rdi
	syscall

	mov byte [rsi + rax], 0

	ret
