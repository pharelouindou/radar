/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

void process_word(char **words, char *word, int *j, int *k)
{
    if (*j != 0) {
        word[*j] = '\0';
        words[*k] = my_strcpy(malloc(my_strlen(word) + 1), word);
        (*k)++;
        *j = 0;
    }
}

char **my_str_to_word_array(char *str)
{
    int i;
    int j = 0;
    int k = 0;
    char **words = NULL;
    char *word = NULL;

    words = malloc((my_strlen(str) + 1) * sizeof(char *));
    word = malloc((my_strlen(str) + 1) * sizeof(char));
    for (i = 0; str[i] != '\0'; i++) {
        if (cond1(str[i]) == 1) {
            word[j] = str[i];
            j++;
        } else {
            process_word(words, word, &j, &k);
        }
    }
    words[k] = NULL;
    return words;
}

air* create_aircraft(airParams params)
{
    air* aircraft = malloc(sizeof(air));
    sfTexture* texture2 = sfTexture_createFromFile("plane.png", NULL);

    if (!aircraft)
        return NULL;
    aircraft->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(aircraft->shape, (sfVector2f){20, 20});
    sfRectangleShape_setPosition(aircraft->shape, (sfVector2f)\
    {params.x, params.y});
    sfRectangleShape_setOutlineThickness(aircraft->shape, 1);
    sfRectangleShape_setOutlineColor(aircraft->shape, sfWhite);
    sfRectangleShape_setFillColor(aircraft->shape, sfTransparent);
    aircraft->params = params;
    aircraft->sprite = sfSprite_create();
    sfSprite_setScale(aircraft->sprite, (sfVector2f){0.075, 0.07});
    sfSprite_setTexture(aircraft->sprite, texture2, sfTrue);
    aircraft->texture2 = texture2;
    return aircraft;
}

void set_shape_properties(controltower* tower, int radius, int x, int y)
{
    sfCircleShape_setRadius(tower->shape, radius);
    sfCircleShape_setOutlineThickness(tower->shape, 1);
    sfCircleShape_setOutlineColor(tower->shape, sfWhite);
    sfCircleShape_setFillColor(tower->shape, sfTransparent);
    sfCircleShape_setOrigin(tower->shape, (sfVector2f){radius, radius});
    sfCircleShape_setPosition(tower->shape, (sfVector2f){x, y});
}
