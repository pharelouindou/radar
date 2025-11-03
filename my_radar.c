/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

void game(sfRenderWindow* window, simulationdata* data, sfSprite* radar)
{
    sfClock* clock = sfClock_create();
    sfTime elapsed;

    while (sfRenderWindow_isOpen(window)) {
        elapsed = sfClock_getElapsedTime(clock);
        process_events(window);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, radar, NULL);
        draw_simulation_data(window, data);
        sfRenderWindow_display(window);
        sfClock_restart(clock);
    }
    sfClock_destroy(clock);
}

void cleanup(simulationdata* data, sfRenderWindow* window, sfSprite* radar)
{
    free_simulation_data(data);
    sfRenderWindow_destroy(window);
    sfSprite_destroy(radar);
}

int main(int argc, char **argv)
{
    sfRenderWindow* window;
    simulationdata* data;
    sfSprite* radar;

    if (argc != 2) {
        return 84;
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        description();
        return 0;
    }
    window = create_window();
    data = parse_script_file(argv[1]);
    radar = create_radar();
    if (!window)
        return 1;
    game(window, data, radar);
    cleanup(data, window, radar);
    return 0;
}
