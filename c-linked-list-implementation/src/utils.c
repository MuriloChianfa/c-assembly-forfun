
#include "utils.h"

#include <stdbool.h>

void system_exit()
{
	clear_screen();
    
    puts("Exiting...");
	
    __asm__("movl $60, %eax\n\t"
            "movl $0,  %edi\n\t"
            "syscall");
}

bool is_odd(int *number)
{
    if ((1 & *number) == 1) {
        return true;
    }

    return false;
}

