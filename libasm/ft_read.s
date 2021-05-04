section	.text
global	_ft_read
extern ___error

_ft_read:								
	mov		rax, 0x2000003     ;syscall id 3 read sposto in rax l'id necessario per la syscall
	syscall                    ;viene avviata la syscall
	jc exit                    ;in caso di errore flag carry = 1
	ret                        ;return rax

exit:
	push rax              	   ;pusho rax nello stack 
	call ___error         	   ;chiamo errore return il puntatore di erno 
	pop r10               	   ;prendo dallo stack il valore salvato prima da rax
	mov [rax], r10        	   ;inserisco il return della system call in nella cella puntata da rax
	mov rax, -1			  	   ;rax = -1
	ret                   	   ; return rax