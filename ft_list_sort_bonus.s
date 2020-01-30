section .text
	global _ft_list_sort

_ft_list_sort:
	mov rcx, [rdi]		; rcx = 1th elm
	mov r8, rcx			; ref to first elm
	mov r15, rsi		; fn = r15

.loop:
	mov rdi, rcx
	add rcx, 8
	mov rsi, [rcx]
	cmp rsi, 0
	je .exit
	push rdi
	push rsi
	call r15
	pop rsi
	pop rdi
	mov rcx, rsi
	cmp rax, 1
	je .swap
	jmp .loop

.exit:
	ret

.swap:
	mov r13, [rdi]
	mov r12, [rsi]
	mov [rdi], r12
	mov [rsi], r13
	mov rcx, r8
	jmp .loop