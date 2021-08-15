global print_uint32

print_uint32:
    mov     eax, edi    ; function arg

    mov     ecx, 0xa    ; base 10
    push    rcx         ; newline = 0xa = base
    mov     rsi, rsp
    sub     rsp, 16     ; not needed on 64-bit Linux, the red-zone is big enough.  Change the LEA below if you remove this.

  .toascii_digit:
    xor     edx, edx    
    div     ecx         ; edx = remainder = low digit = 0..9
    
    add     edx, '0'
    dec     rsi
    mov     [rsi], dl

    test    eax,eax
    jnz  .toascii_digit

    mov     eax, 1
    mov     edi, 1      ; fd stdout
    lea     edx, [rsp+16 + 1]    ; yes, it's safe to truncate pointers before subtracting to find length.
    sub     edx, esi    ; length = end-start, including the \n
    syscall             ; write(1, string,  digits + 1)

    add     rsp, 24     ; undo the push and the buffer reservation
  ret

