global _ft_strcpy

section .text

_ft_strcpy: ;rdi rsi
	mov rdx, rdi

.loop:
	cmp byte[rsi], 0
	je .end
	mov al, [rsi]
	mov [rdx], al
	inc rdx
	inc rsi
	jmp .loop

.end:
	mov rax, rdi
	ret