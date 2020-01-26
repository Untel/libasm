section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strcpy
	extern _ft_strlen

_ft_strdup:
	push rdi
	call _ft_strlen
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je .err
	pop rsi
	mov rdi, rax
	call _ft_strcpy
	ret

.err:
	mov rax, 0
	ret