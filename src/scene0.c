/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene0.c
*/

#include "../include/my_hunter.h"

scene0_t set_menu(void)
{
    scene0_t scene0;

    scene0.button1 = set_button_play();
    scene0.button2 = set_button_help();
    return (scene0);
}

scene0_t play_menu(scene0_t scene0, sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if ((pos.x > 440 && pos.x < 820) && (pos.y > 250 && pos.y < 340)) {
        sfRenderWindow_drawSprite(window, scene0.button1.sp_cliked, NULL);
        sfRenderWindow_drawSprite(window, scene0.button2.sp_button, NULL);
    }
    else if ((pos.x > 440 && pos.x < 820) && (pos.y > 400 && pos.y < 540)) {
        sfRenderWindow_drawSprite(window, scene0.button1.sp_button, NULL);
        sfRenderWindow_drawSprite(window, scene0.button2.sp_cliked, NULL);
    } else {
        sfRenderWindow_drawSprite(window, scene0.button1.sp_button, NULL);
        sfRenderWindow_drawSprite(window, scene0.button2.sp_button, NULL);
    }
    return (scene0);
}

int swap_scene(scene0_t scene0, sfRenderWindow *window, int s)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 440 && pos.x < 820) &&
        (pos.y > 250 && pos.y < 340))
        s = 1;
    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 440 && pos.x < 820) &&
        (pos.y > 400 && pos.y < 540))
        s = 2;
    return (s);
}