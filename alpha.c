/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>

void my_sfcircleshape_set_texture(sfCircleShape* shape,
    sfTexture* texture, sfBool resetRect)
{
    sfCircleShape_setTexture(shape, texture, resetRect);
}

void my_sfrectangleshape_settexture(sfRectangleShape* shape,
    sfTexture* texture, sfBool resetRect)
{
    sfRectangleShape_setTexture(shape, texture, resetRect);
}

void my_sfconvexshape_settexture(sfConvexShape* shape,
    sfTexture* texture, sfBool resetRect)
{
    sfConvexShape_setTexture(shape, texture, resetRect);
}

void my_sfconvexshape_destroy(sfConvexShape* shape)
{
    sfConvexShape_destroy(shape);
}

void my_sfshape_destroy(sfShape* shape)
{
    sfShape_destroy(shape);
}
