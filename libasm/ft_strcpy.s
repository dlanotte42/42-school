section .text
	global _ft_strcpy

_ft_strcpy:
		mov		rax, -1	              ;rax = -1
			
loop:	
		inc		rax					  ;rax++
		mov		cl, byte [rsi+rax]	  ;cl = s[i]
		mov		byte [rdi+rax], cl	  ;dst[i] = cl
		cmp		cl, 0				  ;if (cl == 0)
		je		end					  ;	end
		jmp		loop				  ;loop

end:                 
	mov		rax, rdi				  ;rax = rdi
	ret								  ;return rax