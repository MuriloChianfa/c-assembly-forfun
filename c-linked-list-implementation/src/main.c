/*
 * Exercises to product linked list
 *
 * main.c
 *
 * Author:     Murilo Chianfa
 * Build date: 2021-09-02 19:30
 */

#include "utils.h"
#include "product.h"
#include "product_linked_list.h"
#include "user_methods.h"

#include <stdio.h>
#include <stdint.h>
#include <signal.h>

/*
 * Function: print_main_menu
 * ----------------
 *   Simple print the main menu options
 *
 *   returns: void
 */
void print_main_menu()
{
    puts("+-------------------------+");
    puts("|        MAIN MENU        |");
    puts("|                         |");
    puts("| 1 - Insert product      |");
    puts("| 2 - Delete product      |");
    puts("| 3 - Show all products   |");
    puts("| 4 - Count products      |");
    puts("| 5 - Search by product   |");
    puts("| 6 - Show odd products   |");
    puts("|                         |");
    puts("| 0 - Quit                |");
    puts("|                         |");
    puts("+-------------------------+");
}

/*
 * Function: dispatch_option
 * ----------------
 *   Dispatch the option received to one program function
 *
 *   option: a pointer to int number
 *
 *   returns: void
 */
void dispatch_option(int *option)
{
    switch (*option)
    {
        case 1: user_insert_product(); break;
        case 2: user_delete_product(); break;
        case 3: show_product_list(); break;
        case 4: count_product_list(); break;
        case 5: search_by_product_code(); break;
        case 6: show_odd_products(); break;
        default: puts("Unrecognized option!"); break;
    }

    printf("\nPress ENTER to continue...");

    setbuf(stdin, NULL);
    fgetc(stdin);
}

/*
 * Function: main
 * ----------------
 *   Main function is a entry point to this program
 *
 *   argc: int number containing the size of command line args
 *   argv: string vector containing the command line args
 *
 *   returns: int
 */
int main(int argc, char *argv[])
{
    signal(SIGINT, system_exit);

    int option;

    for (;;)
    {
        clear_screen();

        print_main_menu();

        printf("\nOption: ");
        scanf("%i", &option);
        
        if (0 == option)
        {
            system_exit();
        }
        
        clear_screen();

        dispatch_option(&option);
    }

    return 0;
}

