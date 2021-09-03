
#include "product_linked_list.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

product_t* main_product = NULL;

bool product_has_next(product_t* product)
{
    if (NULL == product->next)
    {
        return false;
    }

    return true;
}

void product_insert(product_t* product)
{
   	if (NULL == main_product)
    {
        main_product = product;
        puts("\nYour product has been added with success!");
        return;
    } 

    product->next = main_product;

    main_product = product;
    
    puts("\nYour product has been added with success!");
}

void product_append(product_t* product)
{
    if (NULL == main_product)
    {
        main_product = product;
        puts("\nYour product has been added with success!");
        return;
    } 

    product_t* iterator = main_product;

    for (;;)
    {
        if (!product_has_next(iterator))
        {
            break;
        }

        iterator = iterator->next;
    }
    
    iterator->next = product;

    puts("\nYour product has been added with success!");
}

void product_add(product_t* product, uint8_t *product_code)
{
    if (NULL == main_product)
    {
        main_product = product;
        puts("\nYour product has been added with success!");
        return;
    } 

    product_t* iterator = main_product;

    for (;;)
    {
        if (*product_code == iterator->code)
        {
            product->next = iterator->next;
            iterator->next = product;
            
            puts("\nYour product has been added with success!");
            return;
        }
        
        if (!product_has_next(iterator))
        {
            break;
        }

        iterator = iterator->next;
    }

    puts("\nProduct code not found!");
}

void product_delete()
{
    product_t* new_main = main_product->next;

    delete_product(main_product);

    main_product = new_main;

    puts("\nYour product has deleted with success!");
}

void product_pop()
{
    if (!product_has_next(main_product))
    {
        product_delete();
        return;
    }

    product_t* iterator = main_product;

    for (;;)
    {
        if (!product_has_next(iterator->next))
        {
            delete_product(iterator->next);
            iterator->next = NULL;
            puts("\nYour product has deleted with success!");
            return;
        }

        iterator = iterator->next;
    }
}

void product_remove(uint8_t *product_code)
{
    if (NULL == main_product)
    {
        puts("The product list is empty!");
        return;
    }
    
    if (*product_code == main_product->code)
    {
        delete_product(main_product);
        puts("\nYour product has deleted with success!");
        return;
    }

    product_t* iterator = main_product;

    for (;;)
    {
        if (!product_has_next(iterator))
        {
            break;
        }
        
        if (*product_code == iterator->next->code)
        {
            product_t* product_to_remove = iterator->next;

            iterator->next = iterator->next->next;

            delete_product(product_to_remove);

            puts("\nYour product has deleted with success!");
            return;
        }

        iterator = iterator->next;
    }
}

void show_product_list()
{
    if (NULL == main_product)
    {
        puts("The product list is empty!");
        return;
    }

    product_t* iterator = main_product;

    puts(" ***************************** PRODUCT LIST ********************************* \n");
    puts("Format: [<product_code>] <product_name>, $<product_price>, <product_in_stock>\n");

    for (;;)
    {
        printf("[%i] %s, $%.2lf, %zu\n",
            iterator->code,
            product_get_name(iterator),
            iterator->price,
            iterator->quantity);

        if (!product_has_next(iterator))
        {
            break;
        }
        
        iterator = iterator->next;
    }
}

