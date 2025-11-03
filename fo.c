/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

simulationdata* process_words(char **words)
{
    int aircraft_count = 0;
    int tower_count = 0;
    simulationdata* data;

    count_objects(words, &aircraft_count, &tower_count);
    if (data == NULL) {
        return NULL;
    }
    data = allocate_memory(aircraft_count, tower_count);
    populate_simulation_data(data, words);
    return data;
}

char *read_file(int fd, struct stat *s)
{
    char *buffer = malloc(sizeof(char) * (s->st_size + 1));

    if (read(fd, buffer, s->st_size) == -1) {
        free(buffer);
        close(fd);
        return NULL;
    }
    buffer[s->st_size] = '\0';
    return buffer;
}

void free_words(char **words)
{
    for (int i = 0; words[i] != NULL; i++)
        free(words[i]);
}

simulationdata *parse_script_file(const char *filepath)
{
    int fd;
    struct stat s;
    char *buffer;
    char **words;
    simulationdata* data;

    if (stat(filepath, &s) == -1)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    buffer = read_file(fd, &s);
    if (!buffer)
        return NULL;
    words = my_str_to_word_array(buffer);
    data = process_words(words);
    free(buffer);
    free_words(words);
    close(fd);
    return data;
}
