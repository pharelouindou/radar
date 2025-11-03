/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void handle_unsetenv(char **args, t_env *envi)
{
    if (args[1] != NULL) {
        my_unsetenv(envi, args);
    } else {
        my_printf("unsetenv: Too few arguments.\n");
    }
}

void handle_env(t_env *envi)
{
    my_env(envi);
}

void verif1(char **args, char **env, t_env *envi)
{
    if (my_strcmp(args[0], "env") == 0) {
        handle_env(envi);
    } else {
        execute(args, env);
    }
}

void verif(char **args, char **env, t_env *envi)
{
    if (my_strcmp(args[0], "setenv") == 0) {
        handle_setenv(args, envi);
    } else if (my_strcmp(args[0], "unsetenv") == 0) {
        handle_unsetenv(args, envi);
    } else {
        verif1(args, env, envi);
    }
}

void handle_builtin(char **args, char **env, t_env *envi)
{
    if (args[0] == NULL) {
        return;
    }
    if (my_strcmp(args[0], "cd") == 0) {
        handle_cd(args, env, envi);
    } else if (my_strcmp(args[0], "exit") == 0) {
        handle_exit(args);
    } else {
        verif(args, env, envi);
    }
}
