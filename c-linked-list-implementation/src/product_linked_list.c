/*
 * Product linked list implementatino
 *
 * product_linked_list.c
 *
 * Author:     Murilo Chianfa
 * Build date: 2021-09-02 19:30
 */

#include "product_linked_list.h"
#include "utils.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

product_t* main_product = NULL;

/*
 * Function: product_has_next
 * ----------------
 *   Verify if received product, has next reference
 *
 *   product: a pointer to target product
 *
 *   returns: bool
 */
bool product_has_next(product_t* product)
{
    if (NULL == product->next)
    {
        return false;
    }

    return true;
}

/*
 * Function: product_insert
 * ----------------
 *   Insert the received product as a first of the list
 *
 *   product: a pointer to target product
 *
 *   returns: void
 */
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

/*
 * Function: product_append
 * ----------------
 *   Append the received product as a last of the list
 *
 *   product: a pointer to target product
 *
 *   returns: void
 */
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

/*
 * Function: product_add
 * ----------------
 *   Put the received product after product with received code
 *
 *   product: a pointer to target product
 *   code: a pointer to target product code
 *
 *   returns: void
 */
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

/*
 * Function: product_delete
 * ----------------
 *   Delete the fist product in linked list
 *
 *   returns: void
 */
void product_delete()
{
    product_t* new_main = main_product->next;

    delete_product(main_product);

    main_product = new_main;

    puts("\nYour product has deleted with success!");
}

/*
 * Function: product_pop
 * ----------------
 *   Delete the last product in linked list
 *
 *   returns: void
 */
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

/*
 * Function: product_remove
 * ----------------
 *   Delete the product with the received code
 *
 *   product_code: a pointer to product code
 *
 *   returns: void
 */
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

/*
 * Function: show_product_list
 * ----------------
 *   Simple product list print
 *
 *   returns: void
 */
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

/*
 * Function: count_product_list
 * ----------------
 *   Simple count the product list and show there
 *
 *   returns: void
 */
void count_product_list()
{
    if (NULL == main_product)
    {
        puts("The product list is empty!");
        return;
    }

    product_t* iterator = main_product;
    size_t size = 0;

    for (;;)
    {
        size++;
        
        if (!product_has_next(iterator))
        {
            break;
        }

        iterator = iterator->next;
    }

    printf("The size product list is: %li\n", size);
}

/*
 * Function: search_by_product
 * ----------------
 *   Search by product with the received product code
 *
 *   product_code: a pointer to int product code
 *
 *   returns: void
 */
void search_by_product(uint8_t *product_code)
{
    if (NULL == main_product)
    {
        puts("\nThe product list is empty!");
        return;
    }

    product_t* iterator = main_product;

    for (;;)
    {
        if (*product_code == iterator->code)
        {
            puts("\nProduct found!\nThe product with this code is: \n");

            printf("[%i] %s, $%.2lf, %zu\n",
                iterator->code,
                product_get_name(iterator),
                iterator->price,
                iterator->quantity);
            
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

/*
 * Function: show_odd_products
 * ----------------
 *   Show only products with odd code
 *
 *   returns: void
 */
void show_odd_products()
{
    if (NULL == main_product)
    {
        puts("The product list is empty!");
        return;
    }

    product_t* iterator = main_product;

    puts(" **************************** PRODUCT ODD LIST ******************************* \n");
    puts("Format: [<product_code>] <product_name>, $<product_price>, <product_in_stock>\n");
    puts("Showing only odd products!\n");

    for (;;)
    {
        if (!product_has_next(iterator))
        {
            if (!is_odd((int*) &iterator->code))
            {
                break;
            }

            printf("[%i] %s, $%.2lf, %zu\n",
                iterator->code,
                product_get_name(iterator),
                iterator->price,
                iterator->quantity);
            
            break;
        }

        if (!is_odd((int*) &iterator->code))
        {
            iterator = iterator->next;
            continue;
        }

        printf("[%i] %s, $%.2lf, %zu\n",
            iterator->code,
            product_get_name(iterator),
            iterator->price,
            iterator->quantity);
                
        iterator = iterator->next;
    }
}

