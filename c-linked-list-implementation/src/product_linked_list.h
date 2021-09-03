#ifndef PRODUCT_LINKED_LIST_H
#define PRODUCT_LINKED_LIST_H

#include "product.h"

#include <stdint.h>
#include <stdbool.h>


bool product_has_next(product_t* product);

void product_insert(product_t* product);
void product_append(product_t* product);
void product_add(product_t* product, uint8_t *product_code);

void product_delete();
void product_pop();
void product_remove(uint8_t *product_code);

void show_product_list();

#endif
