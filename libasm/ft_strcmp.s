section .text
	global _ft_strcmp

_ft_strcmp:
		push	r10

loop:	inc		r10					
		mov		r10, -1				
		mov		al, byte [rdi+r10]	
		mov		bl, byte [rsi+r10]	
		cmp		al, 0				
		je		end				
		cmp		bl, 0			
		je		end				
		cmp		al, bl			
    	je		loop			
		jmp		end

end:
	pop		r10
	sub		rax, rbx
	ret