/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** arrow.c
*/

#include "../include/my_hunter.h"

arrow_t set_arrow(character_t player1)
{
    arrow_t arrow;
    sfImage *i_a = sfImage_createFromFile("character/arrow.png");
    arrow.t_a = sfTexture_createFromImage(i_a, NULL);
    arrow.sp_a = sfSprite_create();
    arrow.v_a.x = 0;
    arrow.v_a.y = 620;
    arrow.scale.x = 0.01;
    arrow.scale.y = 0.01;
    player1.clock = sfClock_create();
    arrow.pressed = 0;
    arrow.touched = 0;
    arrow.touched_boss = 0;
    sfSprite_setTexture(arrow.sp_a, arrow.t_a, sfTrue);
    sfSprite_setPosition(arrow.sp_a, arrow.v_a);
    sfSprite_setScale(arrow.sp_a, arrow.scale);
    return (arrow);
}

arrow_t move_arrow(arrow_t arrow, sfRenderWindow *window, character_t player1)
{
    if (arrow.pressed == 1) {
        arrow.v_a.x -= 15;
        if (arrow.v_a.x >= player1.v_c.x - 100)
            arrow.v_a.y -= 4;
        else
            arrow.v_a.y += 4;
        sfSprite_setPosition(arrow.sp_a, arrow.v_a);
        sfRenderWindow_drawSprite(window, arrow.sp_a, NULL);
    }
    else if (arrow.pressed == 2) {
        arrow.v_a.x += 15;
        if (arrow.v_a.x <= player1.v_c.x + 200)
            arrow.v_a.y -= 4;
        else
            arrow.v_a.y += 4;
        sfSprite_setPosition(arrow.sp_a, arrow.v_a);
        sfRenderWindow_drawSprite(window, arrow.sp_a, NULL);
    }
    return (arrow);
}

scene1_t shoot(scene1_t scene1, sfRenderWindow *window)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        scene1.character.animation.left == 160) {
        if (scene1.character.looking == LEFT)
            scene1.arrow.pressed = 1;
        if (scene1.character.looking == RIGHT)
            scene1.arrow.pressed = 2;
        scene1.arrow.v_a.x = scene1.character.v_c.x + 40;
        scene1.arrow.v_a.y = 620;
        sfSprite_setPosition(scene1.arrow.sp_a, scene1.arrow.v_a);
        sfRenderWindow_drawSprite(window, scene1.arrow.sp_a, NULL);
    }
    scene1.arrow = move_arrow(scene1.arrow, window, scene1.character);
    scene1 = shoot_enemy(scene1, window);
    scene1 = shoot_boss(scene1, window);
    scene1 = shoot_enemy2(scene1, window);
    return (scene1);
}