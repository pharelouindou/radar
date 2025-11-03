/*
** EPITECH PROJECT, 2023
** mon h
** File description:
** my
*/

#ifndef PH
    #define PH

    #include <stdarg.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <math.h>
    #include <time.h>
    #include <SFML/Audio.h>

typedef struct {
    int x;
    int y;
    int x_dest;
    int y_dest;
    int speed;
    int delay;
} airParams;

typedef struct {
    sfRectangleShape* shape;
    sfTexture *texture2;
    sfSprite* sprite;
    airParams params;
} air;

typedef struct controltower {
    sfCircleShape *shape;
    sfTexture *texture;
    sfSprite *sprite;
    int x_dest;
    int y_dest;
} controltower;

typedef struct simulationdata {
    air **aircrafts;
    controltower **towers;
} simulationdata;

void my_putchar(char c);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int cond1(char c);
void process_word(char **words, char *word, int *j, int *k);
char **my_str_to_word_array(char *str);
air* create_aircraft(airParams params);
controltower* create_control_tower(int x, int y, int radius);
int free_simulation_data(simulationdata* data);
void populate_simulation_data(simulationdata* data, char **words);
simulationdata* process_words(char **words);
simulationdata *parse_script_file(const char *filepath);
simulationdata* allocate_memory(int aircraft_count, int tower_count);
void update_aircraft_position(air* aircraft);
void set_framerate_limit(sfRenderWindow* window, unsigned int limit);
void description(void);
void count_objects(char **words, int *aircraft_count, int *tower_count);
void handle_tower(simulationdata* data, char **words,
    int *i, int *tower_index);
sfRenderWindow* create_window(void);
sfSprite* create_radar(void);
typedef struct TextParams {
    sfRenderWindow *window;
    const char *text;
    float x;
    float y;
    unsigned int size;
} TextParams;
void handle_aircraft(simulationdata* data, char **words,
    int *i, int *aircraft_index);
int draw_text(TextParams params);
void process_events(sfRenderWindow* window);
void game(sfRenderWindow* window, simulationdata* data, sfSprite* radar);
void cleanup(simulationdata* data, sfRenderWindow* window, sfSprite* radar);
void set_shape_properties(controltower* tower, int radius, int x, int y);
void draw_simulation_data(sfRenderWindow* window, simulationdata* data);
int my_put_nbr(int nb);

int my_putstr(char const *str);

void printf_str(va_list ap);

int mini_printf(const char *format, ...);

void change(const char *format, int i, va_list ap);

void printf_int(va_list ap);

void printf_char(va_list ap);
int fs_open_file(char const *filepath);
typedef struct {
    simulationdata* data;
    char **words;
    int i;
} Params;
void destroy1(air* ac);
#endif
