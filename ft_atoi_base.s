section .text
	global _ft_atoi_base
	extern _ft_strlen

_ft_atoi_base:			; rdi = STR; rsi = BASE
	push rdi	
	mov rdi, rsi 		; rdi = BASE
	call _ft_strlen	
	mov rdx, rax 		; rdx = BASE SIZE
	pop r15		 		; rcx = STR
	mov r10, 0
	mov r11, 0
	mov r12, 0
	mov r13, 0
	mov r14, 0
	dec r15

.ignore_white_space:
	inc r15
	cmp byte[r15], ' '
	je .ignore_white_space
	cmp byte[r15], 9
	je .ignore_white_space
	cmp byte[r15], 10
	je .ignore_white_space
	cmp byte[r15], 11
	je .ignore_white_space
	cmp byte[r15], 12
	je .ignore_white_space
	cmp byte[r15], 13
	je .ignore_white_space
	dec r15

.signs:
	inc r15
	cmp byte[r15], '+'
	je .signs
	cmp byte[r15], '-'
	je .inc_sign

.find_index_loop:
	mov rax, 0			; RESET RAX && RBX to use al & bl
	mov rbx, 0
	mov bl, byte[rdi] 	; bl = BASE SEARCHING INDEX
	mov al, byte[r15] 	; al = ACTUAL NUMBER IN STR
	cmp al, 0			; If str is at end, exit
	je .exit
	cmp bl, 0
	je .error
	cmp al, bl
	je .atoi_loop
	inc rdi
	jmp .find_index_loop

.atoi_loop:
	mov rdi, rsi 		; rdi = BASE
	sub rbx, '0'
	imul r10, rdx		; counter * base_size
	add r10, rbx		; counter + index
	inc r15
	mov rdi, rsi
	jmp .find_index_loop

.inc_sign:
	cmp r14, 0
	je .set_positive
	mov r14, 0
	jmp .signs

.set_positive:
	mov r14, 1
	jmp .signs

.return_negative:
	imul rax, -1
	ret

.exit:
	mov rax, r10
	cmp r14, 1
	je .return_negative
	ret

.error:
	jmp .exit