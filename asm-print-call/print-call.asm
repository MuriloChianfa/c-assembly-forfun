section .data

newline_char: db 10

codes: db '0123456789abcdef'

section .text

global _start

print_newline:
    mov rax, 1              ; syscall write
    mov rdi, 1              ; fd stdout
    mov rsi, newline_char   ; local de onde os dados serao obtidos
    mov rdx, 1              ; a quantidade de bytes a ser escrita
    syscall
  ret

print_hex:
    mov rax, rdi
    mov rdi, 1
    mov rdx, 1
    mov rcx, 64             ; ate que ponto estamos deslocando rax

iterate:
    push rax                ; salva o valor inicial de rax
    sub rcx, 4
    sar rax, cl             ; desloca para 60, 56, 52, ... 4, 0
                            ; o registrador cl e a menor parte de rcx
    and rax, 0xf            ; limpa todos os bits, exceto os quatro menos significantes 
    lea rsi, [codes + rax]  ; obtem o codigo de caractere de um digito hexadecimal
    mov rax, 1
    push rcx                ; syscall alterara rax
    syscall                 ; rax = 1 (fd write)
                            ; rdi = 1 (stdout)
                            ; rsi = o enredeco de um caractere
    
    pop rcx

    pop rax
    test rcx, rcx           ; rcx = 0 quando todos os digitos forem mostrados
    jnz iterate
  ret

_start:
    mov rdi, 0x1122334455667788
    call print_hex
    call print_newline

    mov rax, 60
    xor rdi, rdi
    syscall

