/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

int main(int argc, char **argv, char **env)
{
    t_env *envi = NULL;
    char *args[1024];

    for (int i = 0; env[i] != NULL; i++) {
        add_end_list(&envi, env[i]);
    }
    if (argc == 1) {
        while (1) {
            read_command(args, env, envi);
        }
    } else {
        exit(84);
    }
    cleanup(envi);
    return 0;
}
