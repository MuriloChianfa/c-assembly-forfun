/*
 * Product functions implementation
 *
 * product.c
 *
 * Author:     Murilo Chianfa
 * Build date: 2021-09-02 19:30
 */

#include "product.h"

#include <malloc.h>
#include <string.h>

/*
 * Function: new_product
 * ----------------
 *   Alloc and return one new product
 *
 *   code: the code of new product
 *   name: a pointer to string for product name
 *   price: the price of new product
 *   quantity: the quantity in stock to this new product
 *
 *   returns: product_t*
 */
product_t* new_product(uint8_t code, char* name, double price, size_t quantity)
{
    product_t* product = malloc(sizeof(product_t));

    product->code = code;
    product->name = name;
    product->price = price;
    product->quantity = quantity;

    return product;
}

/*
 * Function: delete_product
 * ----------------
 *   Delete one existing product
 *
 *   product: a pointer to target product 
 *
 *   returns: void
 */
void delete_product(product_t* product)
{
    if (NULL != product->name)
    {
        free(product->name);
    }

    free(product);
}

/*
 * Function: product_set_name
 * ----------------
 *   Set name to received product
 *
 *   product: a pointer to target product
 *   name: a pointer to string name
 *
 *   returns: void
 */
void product_set_name(product_t* product, char* name)
{
    product->name = name;
}

/*
 * Function: product_get_name
 * ----------------
 *   Get the name of target product
 *
 *   product: a pointer to target product
 *
 *   returns: char*
 */
char* product_get_name(product_t* product)
{
    product->name[strcspn(product->name, "(\n|\r\n|\r)$")] = (char) '\x00'; /* Switching EOL by null in name */

    return product->name;
}

