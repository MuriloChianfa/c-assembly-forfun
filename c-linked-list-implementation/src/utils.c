/*
 * Utils function implementation
 *
 * utils.c
 *
 * Author:     Murilo Chianfa
 * Build date: 2021-09-02 19:30
 */

#include "utils.h"

#include <stdbool.h>

/*
 * Function: system_exit
 * ----------------
 *   Clear screen and call sys exit function
 *
 *   returns: void
 */
void system_exit()
{
	clear_screen();
    
    puts("Exiting...");
	
    __asm__("movl $60, %eax\n\t"
            "movl $0,  %edi\n\t"
            "syscall");
}

/*
 * Function: is_odd
 * ----------------
 *   Verify if received number is odd
 *
 *   number: a pointer to one number
 *
 *   returns: bool
 */
bool is_odd(int *number)
{
    if ((1 & *number) == 1) {
        return true;
    }

    return false;
}

