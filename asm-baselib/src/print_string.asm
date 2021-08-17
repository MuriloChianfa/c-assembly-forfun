;print_string.asm

bits 64

[list -]
	%include "strlen.inc"
[list +]

section .text

global print_string

print_string:
    push rdi

    call strlen

    pop rsi

    mov rdx, rax
    mov rax, 1
    mov rdi, 1
    syscall
  ret
