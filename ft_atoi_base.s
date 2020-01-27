section .text
	global _ft_atoi_base
	extern _ft_strlen

_ft_atoi_base:		; rdi = STR; rsi = BASE
	push rdi
	mov rdi, rsi 	; rdi = BASE
	call _ft_strlen
	mov rdx, rax 	; rdx = BASE SIZE
	pop rcx		 	; rcx = STR
	mov r10, 0	 	; r10 = i = 0
	mov r11, 0		; r11 = counter = 0
	mov r12, 0	 	; r12 = ibase = 0

.find_index_loop:
	mov al, rdi[r12]
	cmp al, 0
	je .error
	cmp rdi[r12], rcx[r10]
	je .atoi_loop
	inc r12
	jmp .find_index_loop

.atoi_loop:
	je .exit
	inc rcx
	jmp .atoi_loop

.error:
	mov rax, -1
	ret