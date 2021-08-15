global _start

section .text

_start:
    mov rdi, 1  ; exit status 1
    mov rax, 60 ; syscall exit
    syscall

