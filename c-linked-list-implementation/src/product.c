
#include "product.h"

#include <malloc.h>
#include <string.h>

product_t* new_product(uint8_t code, char* name, double price, size_t quantity)
{
    product_t* product = malloc(sizeof(product_t));

    product->code = code;
    product->name = name;
    product->price = price;
    product->quantity = quantity;

    return product;
}

void delete_product(product_t* product)
{
    if (NULL != product->name)
    {
        free(product->name);
    }

    free(product);
}

void product_set_name(product_t* product, char* name)
{
    product->name = name;
}

char* product_get_name(product_t* product)
{
    product->name[strcspn(product->name, "(\n|\r\n|\r)$")] = (char) '\x00'; /* Switching EOL by null in name */

    return product->name;
}

