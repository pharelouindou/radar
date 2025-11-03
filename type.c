/*
** EPITECH PROJECT, 2023
** added
** File description:
** add
*/
#include "dad.h"
#include <stdio.h>
#include <math.h>

int hexx(int b)
{
    if (b >= 0 && b <= 9)
        my_put_nbr(b);
    else if (b >= 10 && b < 16)
        my_putchar(b + 87);
    if (b > 16) {
        hexx(b / 16);
        hexx(b % 16);
    }
    return b;
}

void printf_unsigned_int(va_list ap)
{
    unsigned int b = va_arg(ap, unsigned int);

    my_put_nbr_u(b);
}

void expo(int exponent)
{
    if (exponent >= 0) {
        my_putchar('+');
    } else {
        my_putchar('-');
        exponent = -exponent;
    }
    if (exponent < 10) {
        my_put_nbr(0);
    }
    my_put_nbr(exponent);
}

void printf_e(va_list ap)
{
    double f = va_arg(ap, double);
    int exponent = 0;

    while (f > 10) {
        f /= 10;
        exponent++;
    }
    while (f < 1) {
        f *= 10;
        exponent--;
    }
    reduce(f);
    my_put_nbr((int)f);
    my_putchar('e');
    expo(exponent);
}

void reduce(double f)
{
    my_put_nbr((int)f);
        my_putchar('.');
        f = ((f - (int)f) * 1000000);
        for (int i = 100000; i > 1; i /= 10) {
            if (f < i)
                my_put_nbr(0);
        }
        my_put_nbr((int)f);
}
