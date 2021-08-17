section .text

global strlen

strlen:             ; argumento deve ser obtido de rdi
  .loop:
    cmp byte [rdi + r13], 0 ; verifica se o simbolo atual e o finalizador nulo
                            ; definitivamente precisamos do modificador 'bytes', pois
                            ; a parte a esquerda e a direita de cmp devem ter
                            ; o mesmo tamanho. o operando a direita e imediato
                            ; e nao contem nenhuma informacao sobre o seu tamanho,
                            ; desse modo, nao sabemos quantos bytes devem ser
                            ; obtidos da memoria e comparados com zero
    je .end         ; jump se o finalizador nulo for encontrado
    inc r13         ; caso contratio vai para a proxima iteracao e incrementa rax

    jmp .loop

  .end:
    mov rax, r13
  ret               ; quando 'ret' for alcancado, rax deve conter o valor de retorno

