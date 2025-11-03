/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

int my_strcmp(char *str, char *scr)
{
    int i = 0;

    while (str[i] != '\0' && scr[i] != '\0') {
        if (str[i] != scr[i])
            return (str[i] - scr[i]);
        i++;
    }
    return (str[i] - scr[i]);
}

char *my_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strdup(char *src)
{
    char *dest = malloc(my_strlen(src) + 1);

    if (dest != NULL)
        my_strcpy(dest, src);
    return dest;
}

char *my_strcat(char *dest, char *src)
{
    char *p_dest = dest;
    const char *p_src = src;

    while (*p_dest != '\0') {
        p_dest++;
    }
    while (*p_src != '\0') {
        *p_dest = *p_src;
        p_dest++;
        p_src++;
    }
    *p_dest = '\0';
    return dest;
}

int my_strncmp(char *str1, char *str2, int n)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0' && i < n) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    if (i == n) {
        return 0;
    }
    return str1[i] - str2[i];
}
