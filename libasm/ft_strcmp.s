section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, 0           		;i = 0
	mov rax, 0           		;pulisco rax
	mov rbx, 0 					;pulisco rbx

while: 
	mov r10b, byte[rdi+rcx]     ;r10b = s1[i]
	mov r11b, byte[rsi+rcx]		;r11b = s2[i]
	cmp r10b, r11b              ;if (r10b != r11b)
	jne  exit                   ;	exit
	cmp r10b, 0					;if (r10b == '\0')
	je	exit					;	exit
	inc rcx						;i++;
	jmp while					;do while

exit:
	mov al, r10b				;al = r10b
	mov bl, r11b				;bl = r10b
	sub rax, rbx				;al - bl
	ret							;return rax