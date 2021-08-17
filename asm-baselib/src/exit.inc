%ifndef _ASM_EXIT_INC_LIB_
%define _ASM_EXIT_INC_LIB_

    %define EXIT_OK       0      ; Exit with success
    %define EXIT_ER       1      ; Exit with error

    %define set_exit_status mov rdi,

    extern exit

%endif
