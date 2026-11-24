global stringLen
global stringComp
global assignString

section .text

stringLen:
	mov rax, 0

str_len_loop:
	cmp byte [rdi + rax], 0
	je end_str_len

	inc rax
	jmp str_len_loop

end_str_len:
	ret


stringComp:
	mov rcx, 0

str_comp_loop:
	mov al, [rsi + rcx]
	cmp [rdi + rcx], al
	jne return_one

	cmp byte [rdi + rcx], 0
	je return_null

	inc rcx
	jmp str_comp_loop

return_one:
	mov rax, 1
	ret

return_null:
	mov rax, 0
	ret


assignString:
	mov rcx, 0

assign_loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al

	cmp al, 0
	je return_null

	inc rcx

	jmp assign_loop
