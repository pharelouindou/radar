/*
** EPITECH PROJECT, 2023
** mini_prinf
** File description:
** printf
*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "dad.h"

void printf_char(va_list ap)
{
    char a = va_arg(ap, int);

    my_putchar(a);
}

void printf_int(va_list ap)
{
    int b = va_arg(ap, int);

    my_put_nbr(b);
}

void change(const char *format, int *i, va_list ap)
{
    switch (format[*i + 1]) {
    case 'd':
    case 'i':
        printf_int(ap);
        *i += 1;
        break;
    case 's':
        printf_str(ap);
        *i += 1;
        break;
    case 'c':
        printf_char(ap);
        *i += 1;
        break;
    case '%':
        my_putchar('%');
        *i += 1;
        break;
    }
    va_end(ap);
}

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            change(format, &i, ap);
            cas_p(format, &i, ap);
            cas(format, &i, ap);
            cas_pls(format, &i, ap);
            cas_pr(format, &i, ap);
        } else
            my_putchar(format[i]);
    }
    va_end(ap);
}
