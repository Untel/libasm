global _ft_strcmp

section .text

_ft_strcmp: ;rdi rsi
	mov rax, 0

.loop:
	mov bl, [rsi]
	mov bh, [rdi]
	cmp bl, bh
	jg .sup
	jl .inf
	cmp bl, 0
	je .end
	cmp bh, 0
	je .end
	inc rdi
	inc rsi
	jmp .loop

.sup:
	mov rax, -1
	ret

.inf:
	mov rax, 1
	ret

.end:
	ret