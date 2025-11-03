/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void search(t_env *tmp, t_env *prev, t_env **env, int i)
{
    if (i == 0) {
        *env = tmp->nxt;
    } else {
        prev->nxt = tmp->nxt;
    }
}

int delete_list(t_env **env, char *name)
{
    t_env *tmp;
    t_env *prev;
    int i = 0;

    prev = *env;
    tmp = prev;
    while (tmp != NULL) {
        if (my_strncmp(tmp->elem, name, my_strlen(name)) == 0
        && tmp->elem[strlen(name)] == '=') {
            search(tmp, prev, env, i);
            return (0);
        }
        prev = tmp;
        tmp = tmp->nxt;
        i += 1;
    }
    return (1);
}

void add_end_list(t_env **env, char *str)
{
    t_env *tmp;
    t_env *new;

    new = malloc(sizeof(t_env));
    if (new == NULL)
        write(2, "erreur malloc", 14);
    new->elem = my_strdup(str);
    new->nxt = NULL;
    if (*env == NULL)
        *env = new;
    else {
        tmp = *env;
        while (tmp->nxt != NULL)
            tmp = tmp->nxt;
        tmp->nxt = new;
    }
}

void my_env(t_env *env)
{
    t_env *temp = env;

    while (temp != NULL) {
        my_printf("%s\n", temp->elem);
        temp = temp->nxt;
    }
}

bool check_error(char **arg)
{
    int i = 1;
    char *str = "setenv: Variable name must contain alphanumeric";
    char *fr = " characters.\n";

    if (!(arg[1][0] >= 'A' && arg[1][0] <= 'Z') &&
        !(arg[1][0] >= 'a' && arg[1][0] <= 'z')) {
        write(2, "setenv: Variable name must begin with a letter.\n", 49);
        return true;
    }
    while (arg[1][i] != '\0') {
        if (!((arg[1][i] >= 'A' && arg[1][i] <= 'Z') ||
            (arg[1][i] >= 'a' && arg[1][i] <= 'z')
            || (arg[1][i] >= '0' && arg[1][i] <= '9') || arg[1][i] == '_')) {
            write(2, str, my_strlen(str));
            write(2, fr, my_strlen(fr));
            return true;
        }
        i++;
    }
    return false;
}
