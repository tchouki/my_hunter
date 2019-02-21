/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene0.c
*/

#include "../include/my_hunter.h"

scene2_t set_help(void)
{
    scene2_t scene2;

    scene2.button = set_button_back();
    return (scene2);
}

scene2_t play_help(scene2_t scene2, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if ((pos.x > 575 && pos.x < 640) && (pos.y > 600 && pos.y < 670)) {
        sfRenderWindow_drawSprite(window, scene2.button.sp_cliked, NULL);
    } else {
        sfRenderWindow_drawSprite(window, scene2.button.sp_button, NULL);
    }
    return (scene2);
}

int back_menu(scene2_t scene2, sfRenderWindow *window, int s)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 575 && pos.x < 640) &&
        (pos.y > 600 && pos.y < 670))
        s = 0;
    return (s);
}