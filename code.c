/*
** EPITECH PROJECT, 2023
** functio
** File description:
** add
*/
#include "dad.h"

int bin(int nb)
{
    if (nb >= 0 && nb < 2)
        my_put_nbr(nb);
    if (nb > 2) {
        bin(nb / 2);
        bin(nb % 2);
    }
    return nb;
}

void printf_bin(va_list ap)
{
    int b = va_arg(ap, int);

    bin(b);
}

void cas_pr(const char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
    case '#':
        if (format[*i + 2] == 'i' || format[*i + 2] == 'd') {
            printf_int(ap);
            *i += 2;
        }
        if (format[*i + 2] == 'o') {
            my_putchar('0');
            printf_oct(ap);
            *i += 2;
        }
        if (format[*i + 2] == 'x') {
            my_putstr("0x");
            printf_hex2(ap);
            *i += 2;
        }
        break;
    }
    va_end(ap);
}
