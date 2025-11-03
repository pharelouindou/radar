/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "dad.h"

void dex(char **args, char **env, char *exec_path)
{
    if (execve(exec_path, args, env) == -1) {
        my_printf("Error: Failed to execute command %s.\n", args[0]);
        exit(EXIT_FAILURE);
    }
}

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}

void process_word(char **words, char *word, int *j, int *k)
{
    if (*j != 0) {
    word[*j] = '\0';
    words[*k] = my_strcpy(malloc(my_strlen(word) + 1), word);
    (*k)++;
    *j = 0;
    }
}

char **my_str_to_word_array(char *str, char delimiter)
{
    int i;
    int j = 0;
    int k = 0;
    char **words = NULL;
    char *word = NULL;

    words = malloc((my_strlen(str) + 1) * sizeof(char *));
    word = malloc((my_strlen(str) + 1) * sizeof(char));
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != delimiter) {
            word[j] = str[i];
            j++;
        } else {
            process_word(words, word, &j, &k);
        }
    }
    process_word(words, word, &j, &k);
    words[k] = NULL;
    return words;
}
