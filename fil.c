/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void ver(t_env *env, char **exe)
{
    char *cpy;
    int i = 0;

    while (exe[i])
        i += 1;
    if (i == 3) {
        if (check_error(exe) == true)
            return;
        delete_list(&env, exe[1]);
        cpy = malloc(sizeof(char) * (my_strlen(exe[1]) +\
        1 + my_strlen(exe[2])));
        cpy = my_strcat(my_strcat(my_strcat(cpy, exe[1]), "="), exe[2]);
        add_end_list(&env, cpy);
    } else {
        my_putstr("Trop d'arguments\n");
    }
}

void set_two(t_env *env, char **exe)
{
    if (check_error(exe) == true)
            return;
        add_end_list(&env, my_strcat(my_strcat(exe[1], "="), ""));
}

void my_setenv(t_env *env, char **exe)
{
    int i = 0;

    while (exe[i])
        i += 1;
    if (i == 1)
        my_env(env);
    else if (i == 2)
        set_two(env, exe);
    else
        ver(env, exe);
}

void my_unsetenv(t_env *env, char **exe)
{
    int i = 0;

    while (exe[i])
        i += 1;
    if (i != 2)
        my_putstr("Nombre d'arguments incorrect\n");
    else
        delete_list(&env, exe[1]);
}

void check_sign(int status)
{
    if (WIFEXITED(status)) {
        if (WTERMSIG(status) == 11)
            my_printf("Error: Segmentation fault\n");
        if (WTERMSIG(status) == 8)
            my_printf("Error: Floating exception\n");
    }
}
