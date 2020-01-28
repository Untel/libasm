section .text
	global _ft_list_push_front
	extern _malloc

_ft_list_push_front:			; rdi = lst; rsi = data
	push rsi
	push rdi
	mov rdi, 16					; 2 * ptr_size (8)
	call _malloc
	pop rdi						; rdi = le ptr de ptr
	mov rcx, [rdi]				; rcx = l'ancien premier elm
	pop rsi
	mov [rax], rsi
	mov [rdi], rax
	add rax, 8
	mov [rax], rcx
	ret
