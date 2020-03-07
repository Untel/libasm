global _ft_strcpy

section .text

_ft_strcpy: ;rdi rsi
	mov rax, rdi

.loop:
	mov r15b, [rsi]
	mov [rdi], r15b
	cmp r15b, 0
	je .end
	inc rdi
	inc rsi
	jmp .loop

.end:
	ret
