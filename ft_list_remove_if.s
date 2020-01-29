section .text
	global _ft_list_remove_if
	extern _free

_ft_list_remove_if:
	mov r8, [rdi]		; rcx = 1th elm
	mov r15, rdi		; rcx = 1th elm
	mov r14, 0			; rcx = 1th elm
	push rcx
	mov r13, rdx
	mov r12, 1
	mov r9, 0

.loop:
	cmp r8, 0
	je .exit
	push r8
	mov rdi, [r8]
	push rsi
	call r13
	pop rsi
	pop r8
	cmp rax, 0
	je .remove
	mov r14, r8
	jmp .get_next

.get_next:
	inc r9
	add r8, 8
	mov r8, [r8]
	jmp .loop

.exit:
	pop rcx
	ret

.remove:
	cmp r14, 0
	je .set_new_first
	push r8
	push r11
	mov rdi, r8
	call _free
	pop r11
	pop r8
	mov rdi, [r8]
	pop r11
	push r11
	push r8
	call r11
	pop r8
	mov r10, r14
	add r10, 8
	mov r12, r8
	add r12, 8
	mov r12, [r12]
	mov [r10], r12
	mov r8, r12
	jmp .loop

.set_new_first:
	push r8
	push r11
	mov rdi, r8
	call _free
	pop r11
	pop r8
	mov rdi, [r8]
	pop r11
	push r11
	push r8
	call r11
	pop r8
	mov r12, r8
	add r12, 8
	mov r12, [r12]
	mov [r15], r12
	mov r8, r12
	jmp .loop

.is_last:
	cmp r14, 0
	je .return_null
	jmp .exit

.return_null:
	mov rax, 0
	mov [r15], rax
	jmp .exit