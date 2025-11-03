/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;

    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return nbr;
}

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

int my_strlen(char const *str)
{
    int y = 0;

    for (int i = 0; str[i] != '\0'; i++)
        y++;
    return y;
}

int cond1(char c)
{
    if ((c >= '0' && c <= '9') || c == 'A' || c == 'T')
        return 1;
    return 84;
}
