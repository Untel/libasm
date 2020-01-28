section .text
	global _ft_list_push_front
	extern _malloc

_ft_list_push_front:			; rdi = lst; rsi = data
	push rdi
	push rsi					; WTF ? Oblige sinon malloc change rsi
	mov rdi, 16					; 2 * ptr_size (8)
	call _malloc
	cmp rax, 0
	je .exit
	pop rsi
	pop rdi						; rdi = le ptr de ptr
	mov rcx, [rdi]				; rcx = l'ancien premier elm
	mov [rax], rsi				; On store data dans rax
	mov [rdi], rax				; On set remplace le premier elm de l ancienne liste par le nouveau malloc
	add rax, 8					; On avance de 8 pour passer sur next
	mov [rax], rcx				; set le next

.exit:
	ret