global _ft_read

section .text

_ft_read:
	mov rax, 0x02000003 ;4th instruct on eax
	syscall
	jb .err
	ret

.err:
	mov rax, -1
	ret