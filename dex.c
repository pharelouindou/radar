/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

int my_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

int find_variable_index(char *variable, char **env)
{
    char *key;

    for (int i = 0; env[i] != NULL; i++) {
        key = strtok(env[i], "=");
        if (key != NULL && my_strcmp(variable, key) == 0) {
            return i;
        }
    }
    return -1;
}

void my_cd(char **env, const char *path)
{
    if (chdir(path) == -1) {
        perror("cd");
    }
}

void free_word_array(char **words)
{
    if (words == NULL)
        return;
    for (int i = 0; words[i] != NULL; i++) {
        free(words[i]);
    }
    free(words);
}

int my_getnbr(const char *str)
{
    int i = 0;
    int p = 1;

    if (*str == 0)
        return 0;
    while (1) {
    i++;
    if (str[i] == 0)
        return (str[0] - '0') * p + my_getnbr(str + 1);
    p *= 10;
    }
}
