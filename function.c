/*
** EPITECH PROJECT, 2023
** func
** File description:
** function
*/

#include "dad.h"
#include <stdio.h>

void printf_hex(va_list ap)
{
    int p = va_arg(ap, int);

    base(p);
}

void printf_hex2(va_list ap)
{
    int b = va_arg(ap, int);

    hexx(b);
}

int octal(int b)
{
    if (b >= 0 && b < 8) {
        my_put_nbr(b);
    }
    if (b > 8) {
        octal(b / 8);
        octal(b % 8);
    }
    return b;
}

void printf_oct(va_list ap)
{
    int p = va_arg(ap, int);

    octal(p);
}
