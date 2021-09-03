
#include "user_methods.h"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <malloc.h>

void user_insert_product()
{
    uint8_t code;
    char* product_name = (char*) malloc(MAX_PRODUCT_NAME_LEN * sizeof(char));
    double price;
    size_t quantity;

    printf("Type the code of new product: ");
    scanf("%hhu", &code);

    printf("Type the name of new product: ");
    setbuf(stdin, NULL);
    fgets(product_name, MAX_PRODUCT_NAME_LEN, stdin);
    
    printf("Type the price of new product: ");
    scanf("%lf", &price);

    printf("Type the quantity in stock: ");
    scanf("%zu", &quantity);

    product_t* product = new_product(code, product_name, price, quantity);

    puts("\nWhere you want to store this product ?\n");
    puts("1 - First of the list");
    puts("2 - Last of the list");
    puts("3 - After one product code");
    printf("\nOption: ");

    int option;

    scanf("%i", &option);

    switch(option)
    {
        case 1: product_insert(product); break;
        case 2: product_append(product); break;
        case 3:
            printf("\nType the code of required product: ");
            scanf("%hhu", &code);
            product_add(product, &code);
            break;

        default: puts("Invalid option!"); delete_product(product); break;
    }
}

void user_delete_product()
{
    uint8_t code;

    puts("\nWhats product you want to delete ?\n");
    puts("1 - First of the list");
    puts("2 - Last of the list");
    puts("3 - Delete by product code");
    printf("\nOption: ");

    int option;

    scanf("%i", &option);

    switch(option)
    {
        case 1: product_delete(); break;
        case 2: product_pop(); break;
        case 3:
            printf("\nType the code of product: ");
            scanf("%hhu", &code);
            product_remove(&code);
            break;

        default: puts("Invalid option!"); break;
    }

}

