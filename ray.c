/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

sfRenderWindow* create_window(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode,
    "Air Traffic Simulation", sfResize | sfClose, NULL);

    set_framerate_limit(window, 60);
    return window;
}

sfSprite* create_radar(void)
{
    sfTexture* texture1 = sfTexture_createFromFile("radar.png", NULL);
    sfSprite* radar = sfSprite_create();

    sfSprite_setTexture(radar, texture1, sfTrue);
    return radar;
}

void draw_simulation_data(sfRenderWindow* window, simulationdata* data)
{
    TextParams params = {window, "Warning : aircraft_simulation\
    started", 500, 500, 40};

    for (int i = 0; data->aircrafts[i] != NULL; i++) {
        update_aircraft_position(data->aircrafts[i]);
        sfRenderWindow_drawRectangleShape(window, data->\
        aircrafts[i]->shape, NULL);
        sfRenderWindow_drawSprite(window, data->aircrafts[i]->sprite, NULL);
    }
    for (int i = 0; data->towers[i] != NULL; i++) {
        sfCircleShape_setPosition(data->towers[i]->shape, (sfVector2f)
        {data->towers[i]->x_dest, data->towers[i]->y_dest});
        sfRenderWindow_drawCircleShape(window, data->towers[i]->shape, NULL);
        sfSprite_setPosition(data->towers[i]->sprite, (sfVector2f)
        {data->towers[i]->x_dest, data->towers[i]->y_dest});
        sfRenderWindow_drawSprite(window, data->towers[i]->sprite, NULL);
    }
    draw_text(params);
}

void process_events(sfRenderWindow* window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}
