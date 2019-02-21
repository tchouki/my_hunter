/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** background.c
*/

#include "../include/my_hunter.h"

background_t set_background(char *str)
{
    background_t background;
    sfImage *i_background = sfImage_createFromFile(str);
    background.t_background = sfTexture_createFromImage(i_background, NULL);
    background.sp_background = sfSprite_create();
    sfSprite_setTexture(background.sp_background, background.t_background,
        sfTrue);
    return (background);
}