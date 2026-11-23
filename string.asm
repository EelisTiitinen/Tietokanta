
global stringlen

section .text

stringlen:
	mov rcx, 0

strlenloop:
	cmp byte [rdi + rcx], 0
	je endstrlen

	inc rcx
	jmp strlenloop

endstrlen:
	mov rax, rcx
	ret
