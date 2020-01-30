section .text
	global _ft_list_size
	extern _malloc

_ft_list_size:			; rdi = lst; rsi = data
	mov rax, 0

.loop:
	cmp rdi, 0
	je .exit
	add rdi, 8
	add rax, 1
	mov rdi, [rdi]
	jmp .loop

.exit:
	ret