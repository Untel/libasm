global _ft_strlen

section .text
_ft_strlen:
	mov rax, rdi

.loop:
	cmp byte[rax], 0
	je .end
	inc rax
	jmp .loop

.end:
	sub rax, rdi
	ret