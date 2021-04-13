section .text
	global _ft_write

_ft_write:
	test	edi, edi	
	js		error		
	test	esi, esi	
	jz		error		
	test	edx, edx	
	js		error		
	push	rdx			
	mov		rdx, 0		
	mov     rax, 0x2000004	
	syscall					
	pop		rdx				
	test	eax, eax		
	jne		error			
    mov     rax, 0x2000004	
    syscall					
	cmp		rax, 14			
	jne		end				
	cmp		rdx, 14			
	jne		error			
	ret

error:
	mov		rax, -1	
	ret				

end:
	ret