/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void cd_home(char **env)
{
    int home_index = find_variable_index("HOME", env);

    if (home_index != -1) {
        my_cd(env, env[home_index] + 5);
    } else {
        write(2, "cd: HOME not set\n", 18);
    }
}

void cd_old(char **env, t_env *envi)
{
    int oldpwd_index = find_variable_index("OLDPWD", env);
    char path[1024];
    char **pg;

    delete_list(&envi, "OLDPWD");
    add_old(envi);
    if (oldpwd_index != -1) {
        my_cd(env, env[oldpwd_index] + 7);
    } else {
        write(2, "cd: OLDPWD not set\n", 19);
    }
}

void handle_cd(char **args, char **env, t_env *envi)
{
    char path[1024];
    int home_index;
    int oldpwd_index;

    if (args[1] != NULL) {
        if (my_strcmp(args[1], "~") == 0)
        cd_home(env);
        if (my_strcmp(args[1], "-") == 0) {
            cd_old(env, envi);
        } else {
            my_cd(env, args[1]);
        }
    } else {
        cd_home(env);
    }
}

void handle_exit(char **args)
{
    if (args[1] != NULL) {
        write(2, "exit: Expression Syntax.\n", 26);
    } else {
        exit(0);
    }
}

void handle_setenv(char **args, t_env *envi)
{
    my_setenv(envi, args);
}
