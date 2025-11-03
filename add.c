/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include "mom.h"

sfImage *my_sfimage_createfromfile(char *filename)
{
    sfImage* image = sfImage_createFromFile(filename);

    return image;
}

void my_sftexture_destroy(sfTexture* texture)
{
    sfTexture_destroy(texture);
}

void my_sfimage_destroy(sfImage* image)
{
    sfImage_destroy(image);
}

void my_sfshape_set_texture(sfShape* shape,
    sfTexture* texture, sfBool resetRect)
{
    sfShape_setTexture(shape, texture, resetRect);
}

void destroy1(air* ac)
{
    if (ac->texture2 != NULL)
        sfTexture_destroy(ac->texture2);
}
