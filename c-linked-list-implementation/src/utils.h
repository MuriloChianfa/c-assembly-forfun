/*
 * Utils functions header definitions
 *
 * utils.h
 *
 * Author:     Murilo Chianfa
 * Build date: 2021-09-02 19:30
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

#if defined(__MINGW32__) || defined(_MSC_VER)
    #define clear_screen() system("cls")
#else
    #include <stdio_ext.h>
    #include <stdlib.h>
    #define clear_screen() system("clear")
#endif

void system_exit();
bool is_odd(int *number);

#endif
