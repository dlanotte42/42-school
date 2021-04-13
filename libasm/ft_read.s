section .text
	global _ft_read

_ft_read:
	test	edi, edi	
	js		error		
	test	esi, esi	
	jz		error		
	test	edx, edx	
	js		error		
	push	rdx			
	mov		rdx, 0		
	mov     rax, 0x2000003	
	syscall					
	pop		rdx				
	test	eax, eax		
	jne		error			
    mov     rax, 0x2000003	
    syscall					
	ret

error:
	mov		rax, -1	
	ret				