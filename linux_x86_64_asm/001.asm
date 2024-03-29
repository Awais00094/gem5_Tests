section .data
	text db "hello world",10

section .text
	global _start

_start: 
	mov rax, 1
	mov rdi, 1
	mov rsi, text
	mov rdx, 14
	syscall

	mov rax, 60
	moe rdi,0
	syscall
