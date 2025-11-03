/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "mom.h"

void cond_air(Params* params, int *aircraft_index, int *tower_index)
{
    if (params->words[params->i][0] == 'A') {
        handle_aircraft(params->data, params->words,
        &(params->i), aircraft_index);
    } else if (params->words[params->i][0] == 'T') {
        handle_tower(params->data, params->words, &(params->i), tower_index);
    }
}

void populate_simulation_data(simulationdata* data, char **words)
{
    int aircraft_index = 0;
    int tower_index = 0;
    Params params = {data, words, 0};

    for (params.i = 0; words[params.i] != NULL; params.i++) {
        cond_air(&params, &aircraft_index, &tower_index);
    }
    data->aircrafts[aircraft_index] = NULL;
    data->towers[tower_index] = NULL;
}

void count_objects(char **words, int *aircraft_count, int *tower_count)
{
    for (int i = 0; words[i] != NULL; i++) {
        switch (words[i][0]) {
            case 'A':
                (*aircraft_count)++;
                break;
            case 'T':
                (*tower_count)++;
                break;
        }
    }
}

simulationdata* allocate_memory(int aircraft_count, int tower_count)
{
    simulationdata* data = malloc(sizeof(simulationdata));

    if (data == NULL) {
        return NULL;
    }
    data->aircrafts = malloc(sizeof(air*) * (aircraft_count + 1));
    data->towers = malloc(sizeof(controltower*) * (tower_count + 1));
    if (data->aircrafts == NULL || data->towers == NULL) {
        free_simulation_data(data);
        return NULL;
    }
    return data;
}
