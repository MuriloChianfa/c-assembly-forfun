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

void dispatch_option(int *option)
{
    switch (*option)
    {
        case 1: user_insert_product(); break;
        case 2: user_delete_product(); break;
        case 3: show_product_list(); break;
        case 4: puts("4"); break;
        case 5: puts("5"); break;
        case 6: puts("6"); break;
        default: puts("Unrecognized option!"); break;
    }

    printf("\nPress ENTER to continue...");

    setbuf(stdin, NULL);
    fgetc(stdin);
}

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

