/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** print all
*/
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "dad.h"
#include <stdio.h>

void cas(const char *format, int *i, va_list ap)
{
    void *p = NULL;

    switch (format[*i + 1]) {
    case 'p':
        p = va_arg(ap, void *);
        my_putstr("0x");
        hexx((int unsigned long)p);
        *i += 1;
        break;
    case 'f':
        printf_fl(ap);
        *i += 1;
        break;
    case 'x':
        printf_hex2(ap);
        *i += 1;
        break;
    }
    va_end(ap);
}

void cas_p(const char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
    case 'h':
        if (format[*i + 2] == 'i' || format[*i + 2] == 'd') {
            printf_hi(ap);
            *i += 2;
        }
        break;
    case 'l':
        if (format[*i + 2] == 'i' || format[*i + 2] == 'd') {
            prinf_li(ap);
            *i += 2;
        }
        break;
    case 'X':
        printf_hex(ap);
        break;
    }
    va_end(ap);
}

void cas_pls(const char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
    case 'e':
        printf_e(ap);
        break;
    case 'b':
        printf_bin(ap);
        break;
    case 'u':
        printf_unsigned_int(ap);
        *i += 1;
        break;
    case 'o':
        printf_oct(ap);
        *i += 1;
        break;
    }
    va_end(ap);
}

void reduce2(double f)
{
    my_put_nbr(0);
    my_putchar('.');
    f = (f - (int)f) * 1000000;
    for (int i = 100000; i > 1; i /= 10) {
        if (f < i)
            my_put_nbr(0);
    }
    my_put_nbr((int)f);
}

void printf_fl(va_list ap)
{
    double f = va_arg(ap, double);

    if ((int)f != 0){
        reduce(f);
    } else {
        reduce2(f);
    }
}
