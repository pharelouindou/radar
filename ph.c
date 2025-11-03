/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"


controltower* create_control_tower(int x, int y, int radius)
{
    controltower* tower = malloc(sizeof(controltower));
    sfTexture* texture = sfTexture_createFromFile("tower.png", NULL);
    sfFloatRect spriteSize;

    if (!tower)
        return NULL;
    tower->shape = sfCircleShape_create();
    set_shape_properties(tower, radius, x, y);
    tower->x_dest = x;
    tower->y_dest = y;
    tower->sprite = sfSprite_create();
    sfSprite_setScale(tower->sprite, (sfVector2f){0.05, 0.05});
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setOrigin(tower->sprite, (sfVector2f)\
    {spriteSize.width / 2, spriteSize.height / 2});
    sfSprite_setPosition(tower->sprite, (sfVector2f){x, y});
    tower->texture = texture;
    return tower;
}

void destroy2(controltower* tower)
{
    if (tower->texture != NULL)
        sfTexture_destroy(tower->texture);
}

int free_simulation_data(simulationdata* data)
{
    if (data == NULL)
        return 84;
    if (data->aircrafts != NULL) {
        for (int i = 0; data->aircrafts[i] != NULL; i++) {
            sfRectangleShape_destroy(data->aircrafts[i]->shape);
            sfSprite_destroy(data->aircrafts[i]->sprite);
            destroy1(data->aircrafts[i]);
            free(data->aircrafts[i]);
        }
    }
    if (data->towers != NULL) {
        for (int i = 0; data->towers[i] != NULL; i++) {
            sfCircleShape_destroy(data->towers[i]->shape);
            sfSprite_destroy(data->towers[i]->sprite);
            destroy2(data->towers[i]);
            free(data->towers[i]);
        }
    }
    free(data);
}

void handle_aircraft(simulationdata* data, char **words\
    , int *i, int *aircraft_index)
{
    airParams params;

    params.x = my_getnbr(words[*i + 1]);
    params.y = my_getnbr(words[*i + 2]);
    params.x_dest = my_getnbr(words[*i + 3]);
    params.y_dest = my_getnbr(words[*i + 4]);
    params.speed = my_getnbr(words[*i + 5]);
    params.delay = my_getnbr(words[*i + 6]);
    data->aircrafts[(*aircraft_index)] = create_aircraft(params);
    (*aircraft_index)++;
    *i += 6;
}

void handle_tower(simulationdata* data, char **words, int *i, int *tower_index)
{
    int x = my_getnbr(words[*i + 1]);
    int y = my_getnbr(words[*i + 2]);
    int radius = my_getnbr(words[*i + 3]);

    data->towers[(*tower_index)] = create_control_tower(x, y, radius);
    (*tower_index)++;
    *i += 3;
}
