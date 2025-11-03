#!/bin/bash

# Liste des mots à vérifier
mots=("sfRenderWindow_create"
"sfRenderWindow_destroy"
"sfRenderWindow_isOpen"
"sfRenderWindow_pollEvent"
"sfRenderWindow_clear"
"sfRenderWindow_drawSprite"
"sfRenderWindow_drawShape".
"sfRenderWindow_drawRectangleShape"
"sfRenderWindow_drawCircleShape"
"sfRenderWindow_drawConvexShape".
"sfRenderWindow_display"
"sfRenderWindow_close"
"sfSprite_create"
"sfShape_create".
"sfRectangleShape_create"
"sfCircleShape_create"
"sfConvexShape_create".
"sfSprite_destroy"
"sfShape_destroy".
"sfRectangleShape_destroy"
"sfCircleShape_destroy"
"sfConvexShape_destroy".
"sfSprite_setTexture"
"sfShape_setTexture".
"sfCircleShape_setTexture".
"sfRectangleShape_setTexture".
"sfConvexShape_setTexture".
"sfTexture_create"
"sfTexture_createFromFile"
"sfImage_createFromFile".
"sfTexture_destroy".
"sfImage_destroy".
"sfClock_create"
"sfClock_destroy"
"sfClock_getElapsedTime"
"sfClock_restart")

# Répertoire à analyser
repertoire="/home/ayeyemiouindou/B-MUL-100-COT-1-1-myradar-pharel.ouindou"

# Parcourir chaque mot
for mot in "${mots[@]}"; do
    # Rechercher le mot dans le répertoire
    if grep -q -r "$mot" "$repertoire"; then
        echo "$mot est utilisé"
    else
        echo "$mot n'est pas utilisé"
    fi
done
