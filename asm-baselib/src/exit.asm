;exit.asm

bits 64

section .text

global exit

exit:
    mov rax, 60
    syscall

