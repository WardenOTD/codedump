%define offset 4
%define max_size 100

extern printf

section .text
	global main

main:
	enter 0, 0								; set up the stack frame
	push rbx								; save the value of rbx
	push r12								; save the value of r12
	push r13								; save the value of r13
	sub rsp, 8								; reallign the stack to 16 bytes
	lea r12, [rel recamanArray]				; load the address of recamanArray into r12
	mov dword [r12], 0						; initialize the first element of the array
	xor r13, r13							; clear r13 for use as a loop index
	mov r13, 1								; start from the second element (index 1)

recaman_loop:
	cmp r13, max_size						; check if we've reached the end of the array
	je print_loop							; if yes, jump to the end
	xor rax, rax							; clear rax
	xor rbx, rbx							; clear rbx
	mov rax, r13							; rax = current index
	dec rax									; rax = current index - 1
	mov ebx, dword [r12 + rax * offset]		; rbx = recamanArray[current index - 1]
	sub ebx, r13d							; rbx = recamanArray[current index - 1] - current index
	cmp ebx, 0								; check if the result is negative
	jle negative_check						; if negative, jump to negative_check
	xor edx, edx							; clear rdx
	xor r8, r8								; clear r8
	jmp positive_check						; if not negative, jump to positive_check

negative_check:
	mov ebx, dword [r12 + rax * offset]		; rbx = recamanArray[current index - 1]
	add ebx, r13d							; rbx = recamanArray[current index - 1] + current index

insert_result:
	mov dword [r12 + r13 * offset], ebx		; store the result in the current index
	inc r13									; move to the next index
	jmp recaman_loop						; repeat the loop

positive_check:
	cmp rdx, r13							; check if loop index is less than current index
	jge insert_result						; if we've checked all previous elements, insert the result
	mov r8d, dword [r12 + rdx * offset]		; loop to check if rbx is already in the array
	cmp ebx, r8d							; check if the result is already in the array
	je negative_check						; if it is, jump to negative_check
	inc rdx									; move to the next element
	jmp positive_check						; repeat the check

print_loop:
	xor r13, r13							; clear r13 for printing

print_loop_start:
	cmp r13, max_size						; check if we've printed all elements
	je done									; if yes, jump to done
	lea rsi, [rel blue]						; load the blue color string for printf
	mov edx, [r12 + r13 * offset]			; load the current element into edx
	lea rcx, [rel reset]					; load the reset color string for printf
	lea rdi, [rel format]					; load the format string for printf
	xor eax, eax							; clear rax for variadic function call
	call printf wrt ..plt					; call printf to print the current element
	inc r13									; move to the next index
	cmp r13, max_size						; check if we've printed all elements
	jne print_seperator						; if not, print a separator
	jmp print_loop_start					; repeat the loop

print_seperator:
	lea rdi, [rel separator]				; load the separator string for printf
	xor eax, eax							; clear rax for variadic function call
	call printf wrt ..plt					; call printf to print the separator
	jmp print_loop_start					; repeat the loop

done:
	lea rdi, [rel newline]					; load the newline string for printf
	xor eax, eax							; clear rax for variadic function call
	call printf wrt ..plt					; call printf to print the newline
	add rsp, 8								; restore the stack pointer
	pop r13									; restore the value of r13
	pop r12									; restore the value of r12
	pop rbx									; restore the value of rbx
	leave									; clean up the stack frame
	xor rax, rax							; set return value to 0
	ret										; return from the function

section .bss
	recamanArray resd max_size

section .rodata
	format db "%s%d%s", 0
	separator db ", ", 0
	newline db 10, 0
	blue db 27, "[0;34m", 0
	reset db 27, "[0m", 0
