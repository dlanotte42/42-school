section .data

section .text
	global _ft_strlen

_ft_strlen:
		mov		rax, -1					;rax = -1
		
loop:	
		inc		rax					    ;i++;
		mov		cl, byte[rdi+rax]	    ;cl = s[i]
		cmp		cl, 0				    ;if (cl != 0)
    	jne		loop					;	loop
		ret								;return rax 