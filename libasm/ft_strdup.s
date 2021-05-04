section .text
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy
	global _ft_strdup
	extern ___error

_ft_strdup:
		push	rdi             ;salvo nello stack il valore di rdi
		call	_ft_strlen		;chiamo ft_strlen(rdi)
		inc		rax				;rax++
		mov		rdi, rax		;rdi = rax
		call	_malloc			;malloc(rdi)
		cmp		rax, 0			;if (return_malloc == NULL)
		je 		error			;	error 
		pop		rsi				;prendo dallo stack il valore del puntatore alla stringa
		mov		rdi, rax		;rdi = return malloc 
		call	_ft_strcpy		;chiamo la strcpy(rdi, rsi)
		ret						;return rax

error:
	pop rsi				  	    ;prendo dallo stack il valore del puntatore alla stringa
	push rax              	    ;pusho rax nello stack 
	call ___error         	    ;chiamo errore return il puntatore di erno 
	pop r10               	    ;prendo dallo stack il valore salvato prima da rax
	mov [rax], r10        	    ;inserisco il return della system call in nella cella puntata da rax
	mov rax, -1			  	    ;rax = -1
	ret                   	    ;return rax