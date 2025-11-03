/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void handle_args(char **args, char **env, t_env *envi)
{
    if (args[0] == NULL) {
        return;
    }
    if (my_strcmp(args[0], "exit") == 0) {
        if (args[1] != NULL) {
            my_printf("exit: Expression Syntax.\n");
        } else {
            my_printf("exit\n");
            exit(0);
        }
    } else {
        handle_builtin(args, env, envi);
    }
}

void read_command(char **args, char **env, t_env *envi)
{
    char *cmd = NULL;
    int i = 0;
    size_t cmd_size = 0;
    size_t len;

    my_printf("$Pharel Ouindou> ");
    if (getline(&cmd, &cmd_size, stdin) == -1) {
        exit(0);
    }
    len = my_strlen(cmd);
    if (len > 0 && cmd[len - 1] == '\n') {
        cmd[len - 1] = '\0';
    }
    args[i] = strtok(cmd, " \t");
    while (args[i] != NULL) {
        i++;
        args[i] = strtok(NULL, " \t");
    }
    handle_args(args, env, envi);
    free(cmd);
}

void cleanup(t_env *envi)
{
    t_env *temp;

    while (envi != NULL) {
        temp = envi;
        envi = envi->nxt;
        free(temp->elem);
        free(temp);
    }
}
