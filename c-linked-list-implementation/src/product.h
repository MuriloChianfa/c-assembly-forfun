#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_PRODUCT_NAME_LEN 50

#include <stddef.h>
#include <stdint.h>

struct product {
    uint8_t code;
    char* name;
    double price;
    size_t quantity;
    struct product* next;
} __attribute__((__packed__));

typedef struct product product_t;

product_t* new_product(uint8_t code, char* name, double price, size_t quantity);
void delete_product(product_t* product);

void product_set_name(product_t* product, char* name);
char* product_get_name(product_t* product);

#endif
