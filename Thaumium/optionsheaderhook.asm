.data
    szText      db  'WIRES!!!', 0
.code
OptionsHeaderHook proc
 
	mov rax, [r9]
	lea rdx, szText
	mov rcx, r9
	call qword ptr[rax + 98h]
	mov r10, 7FF697EC1006h
	jmp r10

OptionsHeaderHook endp

end