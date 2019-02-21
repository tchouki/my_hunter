/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene.c
*/

#include "../include/my_hunter.h"

scene4_t set_pause_menu(void)
{
    scene4_t scene4;

    scene4.button_menu = set_button_back();
    scene4.button_back = set_button_play();
    return (scene4);
}

scene4_t play_pause(scene4_t scene4, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if ((pos.x > 440 && pos.x < 820) && (pos.y > 250 && pos.y < 340)) {
        sfRenderWindow_drawSprite(window, scene4.button_back.sp_cliked, NULL);
        sfRenderWindow_drawSprite(window, scene4.button_menu.sp_button, NULL);
    }
    else if ((pos.x > 575 && pos.x < 640) && (pos.y > 600 && pos.y < 670)) {
        sfRenderWindow_drawSprite(window, scene4.button_menu.sp_cliked, NULL);
        sfRenderWindow_drawSprite(window, scene4.button_back.sp_button, NULL);
    } else {
        sfRenderWindow_drawSprite(window, scene4.button_menu.sp_button, NULL);
        sfRenderWindow_drawSprite(window, scene4.button_back.sp_button, NULL);
    }
    return (scene4);
}

int back_pause_menu(scene4_t scene4, sfRenderWindow *window, int s)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 575 && pos.x < 640) &&
        (pos.y > 600 && pos.y < 670))
        s = 0;
    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 440 && pos.x < 820) &&
        (pos.y > 250 && pos.y < 340))
        s = 1;
    return (s);
}