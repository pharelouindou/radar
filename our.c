/*
** EPITECH PROJECT, 2023
** .c
** File description:
** function
*/

#include "dad.h"
#include <stdio.h>

int base(int b)
{
    if (b >= 0 && b <= 9)
        my_put_nbr(b);
    else if (b >= 10 && b < 16)
        my_putchar(b + 55);
    if (b > 16) {
        base(b / 16);
        base(b % 16);
    }
    return b;
}

void prinf_li(va_list ap)
{
    long int c = (long int)va_arg(ap, long int);

    my_put_nbr(c);
}

void printf_hi(va_list ap)
{
    short int e = (short int)va_arg(ap, int);

    my_put_nbr(e);
}

int my_put_nbr_u(unsigned int nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + '0');
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}
