/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"


int draw_text(TextParams params)
{
    sfText* sfmlText = sfText_create();
    sfFont* font = sfFont_createFromFile("Nabla.ttf");

    if (!font) {
        sfRenderWindow_destroy(params.window);
        return 84;
    }
    sfText_setString(sfmlText, params.text);
    sfText_setFont(sfmlText, font);
    sfText_setCharacterSize(sfmlText, params.size);
    sfText_setPosition(sfmlText, (sfVector2f){params.x, params.y});
    sfRenderWindow_drawText(params.window, sfmlText, NULL);
    sfText_destroy(sfmlText);
    sfFont_destroy(font);
}

void update_aircraft_position(air* aircraft)
{
    airParams* params = &(aircraft->params);
    double dx = params->x_dest - params->x;
    double dy = params->y_dest - params->y;
    double distance = sqrt(dx * dx + dy * dy);

    if (distance > params->speed) {
        params->x += dx / distance * params->speed;
        params->y += dy / distance * params->speed;
    } else {
        params->x = params->x_dest;
        params->y = params->y_dest;
    }
    sfRectangleShape_setPosition(aircraft->shape\
    , (sfVector2f){params->x, params->y});
    sfSprite_setPosition(aircraft->sprite, (sfVector2f){params->x, params->y});
}

void set_framerate_limit(sfRenderWindow* window, unsigned int limit)
{
    sfRenderWindow_setFramerateLimit(window, limit);
}

void description(void)
{
    mini_printf("Air traffic simulation panel\n\n");
    mini_printf("USAGE\n");
    mini_printf(" ./my_radar [OPTIONS] path_to_script\n");
    mini_printf("  path_to_script The path to the script file.\n\n");
    mini_printf("OPTIONS\n");
    mini_printf("-h\t\t print the usage and quit.\n\n");
    mini_printf("USER INTERACTIONS\n");
    mini_printf("'L'\t key enable/disable hitboxes and areas.\n");
    mini_printf("'S'\t key enable/disable sprites.\n");
}
