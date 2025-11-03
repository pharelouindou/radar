/*
** EPITECH PROJECT, 2023
** mon c
** File description:
** my
*/

#include "mom.h"
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int r = 0;

    while (str[r] != '\0') {
        my_putchar(str[r]);
        r++;
    }
    return 0;
}

int my_put_nbr(int nb)
{
    if (nb >= 0 && nb < 10) {
        my_putchar(nb + '0');
    } else if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * -1);
    } else {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    return 0;
}

void printf_str(va_list ap)
{
    char *b = va_arg(ap, char *);

    my_putstr(b);
}
