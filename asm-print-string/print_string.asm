section .data

my_string: db 'hello', 0

section .text

global _start

print_string:
    push rdi
    call string_length
    pop rsi
    mov rdx, rax
    mov rax, 1
    mov rdi, 1
    syscall
  ret

string_length:
    xor rax, rax
.loop:
    cmp byte [rdi + rax], 0
    je .end
    inc rax
    jmp .loop
.end:
    ret

_start:
    mov rdi, my_string
    call print_string

    mov rax, 60
    xor rdi, rdi
    syscall

