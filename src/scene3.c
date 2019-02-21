/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** scene3.c
*/

#include "../include/my_hunter.h"

scene3_t set_gameover(void)
{
    scene3_t scene3;

    scene3.button = set_button_back();
    scene3.death_counter = set_death_counter();
    scene3.pos_death.x = 595;
    scene3.pos_death.y = 440;
    return (scene3);
}

scene3_t play_gameover(scene3_t scene3, sfRenderWindow *window, scene1_t scene1)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    scene3.death_counter.nbr_death = scene1.death_counter.nbr_death;
    scene3.death_counter.string = my_put_nbr(scene3.death_counter.nbr_death);
    sfText_setCharacterSize(scene3.death_counter.text, 50);
    sfText_setPosition(scene3.death_counter.text, scene3.pos_death);
    sfText_setString(scene3.death_counter.text, scene3.death_counter.string);
    sfRenderWindow_drawText(window, scene3.death_counter.text, NULL);
    if ((pos.x > 575 && pos.x < 640) && (pos.y > 600 && pos.y < 670)) {
        sfRenderWindow_drawSprite(window, scene3.button.sp_cliked, NULL);

    } else {
        sfRenderWindow_drawSprite(window, scene3.button.sp_button, NULL);
    }
    return (scene3);
}

int back_menu_gameover(scene3_t scene3, sfRenderWindow *window, int s)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    if (sfMouse_isButtonPressed(sfMouseLeft) && (pos.x > 575 && pos.x < 640) &&
        (pos.y > 600 && pos.y < 670))
        s = 0;
    return (s);
}