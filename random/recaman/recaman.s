%define offset 4
%define max_size 100
%define format "%d"
%define separator ", "
%define newline "\n"

extern printf

section .text
	global main

main:
	enter 0, 0								; Set up the stack frame
	push rbx								; Save the value of rbx
	lea r9, [rel recamanArray]				; Load the address of recamanArray into r9
	mov dword [r9], 0						; Initialize the first element of the array
	mov rcx, 1								; Start from the second element (index 1)

recaman_loop:
	cmp rcx, max_size						; Check if we've reached the end of the array
	je print_loop							; If yes, jump to the end
	xor rax, rax							; Clear rax
	xor rbx, rbx							; Clear rbx
	mov rax, rcx							; rax = current index
	dec rax									; rax = current index - 1
	mov rbx, [r9 + rax * offset]			; rbx = recamanArray[current index - 1]
	sub rbx, rcx							; rbx = recamanArray[current index - 1] - current index
	cmp rbx, 0								; Check if the result is negative
	js negative_check						; If negative, jump to negative_check
	xor rdx, rdx							; Clear rdx
	xor r8, r8								; Clear r8
	jmp positive_check						; If not negative, jump to positive_check

negative_check:
	mov rbx, [r9 + rax * offset]			; rbx = recamanArray[current index - 1]
	add rbx, rcx							; rbx = recamanArray[current index - 1] + current index

insert_result:
	mov [r9 + rcx * offset], rbx			; Store the result in the current index
	inc rcx									; Move to the next index
	jmp recaman_loop						; Repeat the loop

positive_check:
	cmp rdx, rcx							; Check if loop index is less than current index
	jge insert_result						; If we've checked all previous elements, insert the result
	mov r8, [r9 + rdx * offset]				; Loop to check if rbx is already in the array
	cmp rbx, r8								; Check if the result is already in the array
	je negative_check						; If it is, jump to negative_check
	inc rdx									; Move to the next element
	jmp positive_check						; Repeat the check

print_loop:
	xor rcx, rcx							; Clear rcx for printing

print_loop_start:
	cmp rcx, max_size						; Check if we've printed all elements
	je done									; If yes, jump to done
	mov rsi, [r9 + rcx * offset]			; Load the current element into rsi
	mov rdi, format							; Load the format string for printf
	xor rax, rax							; Clear rax for variadic function call
	call printf wrt ..plt					; Call printf to print the current element
	inc rcx									; Move to the next index
	cmp rcx, max_size						; Check if we've printed all elements
	jne print_seperator						; If not, print a separator
	jmp print_loop_start					; Repeat the loop

print_seperator:
	mov rdi, separator						; Load the separator string for printf
	xor rax, rax							; Clear rax for variadic function call
	call printf wrt ..plt					; Call printf to print the separator
	jmp print_loop_start					; Repeat the loop

done:
	mov rdi, newline						; Load the newline string for printf
	xor rax, rax							; Clear rax for variadic function call
	call printf wrt ..plt					; Call printf to print the newline
	pop rbx									; Restore the value of rbx
	leave									; Clean up the stack frame
	ret										; Return from the function

section .bss
	recamanArray resd 100
